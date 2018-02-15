O                   [1-7]?
CHARACTERS          [a-zA-Z]
UPPERCASE           [a-z]
LOWERCASE           [A-Z]
NUMBERS             [0-9]
ESCNUMBERS          [1-7]
NEWLINE             "\n"
CARRIAGERETURN      "\r"
TAB                 "\t"
SPACE               " "
SINGLESPLIT         \'
ESCAPE              \\r|\\n|\\f|\"|\\t|\\{O}{3}
LINETERMINATOR      \\n|"\r\n"
CHARLIT             {CHARACTERS}|{ESCAPE}|\_
INVALID             ({CHARACTERS}|{ESCAPE}|{SPACE}|\/)+
INTLIT              {NUMBERS}+ 
EXPOENTE            ("e"|"E")(("+"|"-"))?
ID                  "_"?{CHARACTERS}({CHARACTERS}|{NUMBERS})*
REALLIT             ({INTLIT}"."{INTLIT})|({INTLIT}"."{INTLIT}{EXPOENTE}{INTLIT})|({INTLIT}{EXPOENTE}{INTLIT})
RESERVED            "auto"|"break"|"case"|"const"|"continue"|"default"|"do"|"enum"|"extern"|"for"|"goto"|"inline"|"long"|"register"|"register"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatile"|"_Bool"|"_Imaginary"|"++"|"--"

%{
#include <stdio.h>
#include <string.h>

int column = 1;
int curr_column = 1;
int line = 1;
int curr_line = 1;
int flag = 0;

void count(void);
void comment();
void ignore_line();
void print_text(char * text);
void print_content(char * text, char * content);
%}

%X CHARACTERLIT LINECOMMENT 

%%

"/*"                                            { comment(); }
"//"[^\n]*                                      { /* skip line */}

"char"                                          { count(); print_text("CHAR"); }
"else"                                          { count(); print_text("ELSE"); }
"while"                                         { count(); print_text("WHILE"); }
"if"                                            { count(); print_text("IF"); }
"int"                                           { count(); print_text("INT"); }
"short"                                         { count(); print_text("SHORT"); }
"double"                                        { count(); print_text("DOUBLE"); }
"return"                                        { count(); print_text("RETURN"); }
"void"                                          { count(); print_text("VOID"); }
"&"                                             { count(); print_text("BITWISEAND"); }
"|"                                             { count(); print_text("BITWISEOR");  }
"^"                                             { count(); print_text("BITWISEXOR");  }
"&&"                                            { count(); print_text("AND"); }
"="                                             { count(); print_text("ASSIGN"); }
"*"                                             { count(); print_text("MUL"); }
","                                             { count(); print_text("COMMA"); }
"/"                                             { count(); print_text("DIV"); }
"=="                                            { count(); print_text("EQ"); }
">="                                            { count(); print_text("GE"); }
">"                                             { count(); print_text("GT");  }
"{"                                             { count(); print_text("LBRACE"); }
"<="                                            { count(); print_text("LE"); }
"("                                             { count(); print_text("LPAR"); }
"<"                                             { count(); print_text("LT"); }
"-"                                             { count(); print_text("MINUS"); }
"%"                                             { count(); print_text("MOD");  }
"!="                                            { count(); print_text("NE"); }
"!"                                             { count(); print_text("NOT"); }
"||"                                            { count(); print_text("OR"); }
"+"                                             { count(); print_text("PLUS");  }
"}"                                             { count(); print_text("RBRACE"); }
")"                                             { count(); print_text("RPAIR");  }
";"                                             { count(); print_text("SEMI"); }

{TAB}                                           { count(); }
{SPACE}                                         { count(); }
{NEWLINE}                                       { count(); }
{LINETERMINATOR}                                { count(); }
{RESERVED}                                      { count(); print_content("RESERVED", yytext); }
{INTLIT}                                        { count(); print_content("INTLIT",yytext); }
{REALLIT}                                       { count(); print_content("REALLIT",yytext); }
{SINGLESPLIT}{CHARLIT}{SINGLESPLIT}             { count(); print_content("CHARLIT",yytext); }
{ID}                                            { count(); print_content("ID",yytext); }

{SINGLESPLIT}                                   { yymore(); BEGIN CHARACTERLIT; curr_column = column; curr_line = line; count(); }
<CHARACTERLIT>{INVALID}+                        { count(); yymore(); }
<CHARACTERLIT>{LINETERMINATOR}                  { BEGIN 0; printf("Line: %d, col %d: unterminated char constant\n",line,column); count(); }
<CHARACTERLIT>{SINGLESPLIT}                     { BEGIN 0; printf("Line: %d, col %d: invalid char constant (%s)\n",line,column,yytext); count(); }
<CHARACTERLIT><<EOF>>                           { BEGIN 0; printf("Line %d, col %d: unterminated char constant\n",curr_line,curr_column); count(); }
.                                               { printf("Line %d, col %d: illegal character (%s)\n",line,column,yytext); count();}
%%

void count(void)
{
  int i;

  for (i = 0; yytext[i] != '\0'; i++)
    if (yytext[i] == '\n'){
      column = 1;
      line++;
    }
    else if (yytext[i] == '\t')
      column += 8 - (column % 8);
    else
      column++;

}

void print_text(char* text)
{
  if (flag == 1)
    printf("%s\n",text);
}

void print_content(char* text, char* content)
{
  if (flag == 1)
    printf("%s(%s)\n",text,content);
}

void comment()
{
  char current, prev = 0;

  while ((current = input()) != 0)
  {
      if(current == '/' && prev == '*')
          return;
      prev = current;
  }
  printf("Line %d, col %d: unterminated comment\n",line,column);
}

int main(int argc, char * argv[])
{
  if (argc > 1)
  {
    if(strcmp(argv[1],"-l") == 0){
      flag = 1;
    }
  }
  yylex();
  return 0;
}

int yywrap(void)
{
  return 1;
}
