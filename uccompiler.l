O                   [0-7]{1,3}
CHARACTERS          [a-zA-Z]
UPPERCASE           [a-z]
LOWERCASE           [A-Z]
NUMBERS             [0-9]
TAB                 "\t"
SPACE               " "
SINGLESPLIT         \'
LINETERMINATOR      "\n"|"\r\n"|"\r"
ESCAPE              \\n|\\\"|\\t|\\{O}|\\\\|\\\'|\"
CHARLIT             [^\r\n\']|{ESCAPE}
INTLIT              {NUMBERS}+ 
ID                  ("_"|{CHARACTERS})+({CHARACTERS}|{NUMBERS}|"_")*
EXPOENTE            ("e"|"E")(("+"|"-"))?
RL1                 ({INTLIT}?"."{INTLIT})
RL2                 ({INTLIT}"."{INTLIT}?)
REALLIT             ({RL1}|{RL2})({EXPOENTE}{INTLIT})|({INTLIT}{EXPOENTE}{INTLIT})|({RL1}|{RL2})
RESERVED            "auto"|"break"|"case"|"const"|"continue"|"default"|"do"|"enum"|"extern"|"float"|"for"|"goto"|"inline"|"long"|"register"|"restrict"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatile"|"_Bool"|"_Imaginary"|"_Complex"|"++"|"--"|"["|"]"

%{
#include <stdio.h>

int column = 1;
int line = 1;
int curr_column = 1;
int curr_line = 1;
int flag = 0;
int error = -1;

void print_text(char * text);
void print_content(char * text, char * content);
%}

%X CHAR MLINECOMMENT

%%
"/*"                                            { BEGIN MLINECOMMENT; curr_line = line; curr_column = column; column+=yyleng; }
<MLINECOMMENT>"*/"                              { BEGIN 0; column+=yyleng; }
<MLINECOMMENT><<EOF>>                           { BEGIN 0; printf("Line %d, col %d: unterminated comment\n",curr_line,curr_column); column+=yyleng; }
<MLINECOMMENT>{LINETERMINATOR}                  { line++; column=1; }
<MLINECOMMENT>.                                 { column+=yyleng; }

"//".*                                          { column+=yyleng; }

"char"                                          { column+=yyleng; print_text("CHAR"); }
"else"                                          { column+=yyleng; print_text("ELSE"); }
"while"                                         { column+=yyleng; print_text("WHILE"); }
"if"                                            { column+=yyleng; print_text("IF"); }
"int"                                           { column+=yyleng; print_text("INT"); }
"short"                                         { column+=yyleng; print_text("SHORT"); }
"double"                                        { column+=yyleng; print_text("DOUBLE"); }
"return"                                        { column+=yyleng; print_text("RETURN"); }
"void"                                          { column+=yyleng; print_text("VOID"); }
"&"                                             { column+=yyleng; print_text("BITWISEAND"); }
"|"                                             { column+=yyleng; print_text("BITWISEOR");  }
"^"                                             { column+=yyleng; print_text("BITWISEXOR");  }
"&&"                                            { column+=yyleng; print_text("AND"); }
"="                                             { column+=yyleng; print_text("ASSIGN"); }
"*"                                             { column+=yyleng; print_text("MUL"); }
","                                             { column+=yyleng; print_text("COMMA"); }
"/"                                             { column+=yyleng; print_text("DIV"); }
"=="                                            { column+=yyleng; print_text("EQ"); }
">="                                            { column+=yyleng; print_text("GE"); }
">"                                             { column+=yyleng; print_text("GT");  }
"{"                                             { column+=yyleng; print_text("LBRACE"); }
"<="                                            { column+=yyleng; print_text("LE"); }
"("                                             { column+=yyleng; print_text("LPAR"); }
"<"                                             { column+=yyleng; print_text("LT"); }
"-"                                             { column+=yyleng; print_text("MINUS"); }
"%"                                             { column+=yyleng; print_text("MOD");  }
"!="                                            { column+=yyleng; print_text("NE"); }
"!"                                             { column+=yyleng; print_text("NOT"); }
"||"                                            { column+=yyleng; print_text("OR"); }
"+"                                             { column+=yyleng; print_text("PLUS");  }
"}"                                             { column+=yyleng; print_text("RBRACE"); }
")"                                             { column+=yyleng; print_text("RPAR");  }
";"                                             { column+=yyleng; print_text("SEMI"); }
{RESERVED}                                      { column+=yyleng; print_content("RESERVED", yytext); }

{TAB}                                           { column+=yyleng; }
{SPACE}                                         { column+=yyleng; }
{LINETERMINATOR}                                { column=1; line++; }

{ID}                                            { column+=yyleng; print_content("ID",yytext); }
{INTLIT}                                        { column+=yyleng; print_content("INTLIT",yytext); }

{SINGLESPLIT}                                   { yymore(); BEGIN CHAR; curr_column = column; curr_line = line; error = -1; }
<CHAR>{CHARLIT}                                 { yymore(); column+=yyleng; error++; }
<CHAR>\\(.?)                                    { yymore(); error++;  }
<CHAR>{LINETERMINATOR}                          { BEGIN 0; printf("Line %d, col %d: unterminated char constant\n",curr_line,curr_column); line++; column=1; }
<CHAR>{SINGLESPLIT}                             { BEGIN 0; if(error == 0) { print_content("CHRLIT",yytext); } else { printf("Line %d, col %d: invalid char constant (%s)\n",curr_line,curr_column,yytext);} column+=yyleng; }
<CHAR><<EOF>>                                   { BEGIN 0; printf("Line %d, col %d: unterminated char constant\n",curr_line,curr_column); line++; column=1; }

{REALLIT}                                       { column+=yyleng; print_content("REALLIT",yytext); }
.                                               { printf("Line %d, col %d: illegal character (%s)\n",line,column,yytext); column+=yyleng; }

%%

/* 
   Francisco José Rodrigues dos Santos 2015238068
   João Afonso Póvoa Marques 2015227041
*/

void print_text(char* text)
{
  if (flag == 1){
    printf("%s\n",text);
  }
}

void print_content(char* text, char* content)
{
  if (flag == 1){
    printf("%s(%s)\n",text,content);
  }
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

