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
#include "y.tab.h"

int column = 1;
int line = 1;
int curr_column = 1;
int curr_line = 1;
int flag = 0;
int error = -1;

void print_text(char * text);
void print_content(char * text, char * content);
void yyerror(const char * s);
%}

%X CHAR MLINECOMMENT

%%
"/*"                                            { BEGIN MLINECOMMENT; curr_line = line; curr_column = column; column+=yyleng; }
<MLINECOMMENT>"*/"                              { BEGIN 0; column+=yyleng; }
<MLINECOMMENT><<EOF>>                           { BEGIN 0; printf("Line %d, col %d: unterminated comment\n",curr_line,curr_column); column+=yyleng; }
<MLINECOMMENT>{LINETERMINATOR}                  { line++; column=1; }
<MLINECOMMENT>.                                 { column+=yyleng; }

"//".*                                          { column+=yyleng; }

"char"                                          { column+=yyleng; print_text("CHAR"); if(flag == 2) return CHAR; }
"else"                                          { column+=yyleng; print_text("ELSE"); if(flag == 2) return ELSE; }
"while"                                         { column+=yyleng; print_text("WHILE"); if (flag == 2) return WHILE; }
"if"                                            { column+=yyleng; print_text("IF"); if (flag == 2) return IF; }
"int"                                           { column+=yyleng; print_text("INT"); if (flag == 2) return INT; }
"short"                                         { column+=yyleng; print_text("SHORT"); if (flag == 2) return SHORT; }
"double"                                        { column+=yyleng; print_text("DOUBLE"); if (flag == 2) return DOUBLE; }
"return"                                        { column+=yyleng; print_text("RETURN"); if (flag == 2) return RETURN; }
"void"                                          { column+=yyleng; print_text("VOID"); if (flag == 2) return VOID; }
"&"                                             { column+=yyleng; print_text("BITWISEAND"); if (flag == 2) return BITWISEAND; }
"|"                                             { column+=yyleng; print_text("BITWISEOR");  if (flag == 2) return BITWISEOR; }
"^"                                             { column+=yyleng; print_text("BITWISEXOR"); if (flag == 2) return BITWISEXOR; }
"&&"                                            { column+=yyleng; print_text("AND"); if (flag == 2) return AND;}
"="                                             { column+=yyleng; print_text("ASSIGN"); if (flag == 2) return ASSIGN; }
"*"                                             { column+=yyleng; print_text("MUL"); if (flag == 2) return MUL; }
","                                             { column+=yyleng; print_text("COMMA"); if (flag == 2) return COMMA; }
"/"                                             { column+=yyleng; print_text("DIV"); if (flag == 2) return DIV; }
"=="                                            { column+=yyleng; print_text("EQ"); if (flag == 2) return EQ; }
">="                                            { column+=yyleng; print_text("GE"); if (flag == 2) return GE; }
">"                                             { column+=yyleng; print_text("GT"); if (flag == 2) return GT; }
"{"                                             { column+=yyleng; print_text("LBRACE"); if (flag == 2) return LBRACE; }
"<="                                            { column+=yyleng; print_text("LE"); if (flag == 2) return LE; }
"("                                             { column+=yyleng; print_text("LPAR"); if (flag == 2) return LPAR; }
"<"                                             { column+=yyleng; print_text("LT"); if (flag == 2) return LT; }
"-"                                             { column+=yyleng; print_text("MINUS"); if (flag == 2) return MINUS; }
"%"                                             { column+=yyleng; print_text("MOD"); if (flag == 2) return MOD; }
"!="                                            { column+=yyleng; print_text("NE"); if (flag == 2) return NE; }
"!"                                             { column+=yyleng; print_text("NOT"); if (flag == 2) return NOT; }
"||"                                            { column+=yyleng; print_text("OR"); if (flag == 2) return OR; }
"+"                                             { column+=yyleng; print_text("PLUS"); if (flag == 2) return PLUS; }
"}"                                             { column+=yyleng; print_text("RBRACE"); if (flag == 2) return RBRACE; }
")"                                             { column+=yyleng; print_text("RPAR"); if (flag == 2) return RPAR; }
";"                                             { column+=yyleng; print_text("SEMI"); if (flag == 2) return SEMI; }
{RESERVED}                                      { column+=yyleng; print_content("RESERVED", yytext); if (flag == 2) return RESERVED; }

{TAB}                                           { column+=yyleng; }
{SPACE}                                         { column+=yyleng; }
{LINETERMINATOR}                                { column=1; line++; }

{ID}                                            { column+=yyleng; print_content("ID",yytext); if (flag == 2) { yyval.string = (char *) strdup(yytext) } return ID; }
{INTLIT}                                        { column+=yyleng; print_content("INTLIT",yytext); if (flag == 2) { yyval.string = (char *) strdup(yytext) }return INTLIT; }
{REALLIT}                                       { column+=yyleng; print_content("REALLIT",yytext); if (flag == 2) { yyval.string = (char *) strdup(yytext) } return REALLIT; }

{SINGLESPLIT}                                   { yymore(); BEGIN CHAR; curr_column = column; curr_line = line; error = -1; }
<CHAR>{CHARLIT}                                 { yymore(); error++; }
<CHAR>\\(.?)                                    { yymore(); error=1;}
<CHAR>{LINETERMINATOR}                          { BEGIN 0; printf("Line %d, col %d: unterminated char constant\n",curr_line,curr_column); line++; column=1; }
<CHAR>{SINGLESPLIT}                             { BEGIN 0; if(error == 0) { print_content("CHRLIT",yytext); } else { printf("Line %d, col %d: invalid char constant (%s)\n",curr_line,curr_column,yytext);} column+=yyleng; if (flag == 2) {yyval.string = (char*)strdup(yytext)} return CHRLIT; }
<CHAR><<EOF>>                                   { BEGIN 0; printf("Line %d, col %d: unterminated char constant\n",curr_line,curr_column); line++; column=1; }

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


int yywrap(void)
{
  return 1;
}

void yyerror(const char * s){
  printf("Line %d, col %d: %s: %s\n",line,(int)(coluna-yyleng), s, yytext);
}
