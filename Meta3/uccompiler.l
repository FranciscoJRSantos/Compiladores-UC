
%{
#include "y.tab.h"
#include "semantics.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int column = 1;
int line = 1;
int curr_column = 1;
int curr_line = 1;
int flag;
int error = -1;
int tree_flag;

void print_text(char * text);
void print_content(char * text, char * content);
void yyerror(const char * s);
node root;
%}

%X CHARSTATE MLINECOMMENT

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

%%
"/*"                                            { BEGIN MLINECOMMENT; curr_line = line; curr_column = column; column+=yyleng; }
<MLINECOMMENT>"*/"                              { BEGIN 0; column+=yyleng; }
<MLINECOMMENT><<EOF>>                           { BEGIN 0; printf("Line %d, col %d: unterminated comment\n",curr_line,curr_column); column+=yyleng; return 0; }
<MLINECOMMENT>{LINETERMINATOR}                  { line++; column=1; }
<MLINECOMMENT>.                                 { column+=yyleng; }

"//".*                                          { column+=yyleng; }

"else"                                          { column+=yyleng; print_text("ELSE"); if(flag == 2) return ELSE; }
"while"                                         { column+=yyleng; print_text("WHILE"); if (flag == 2) { yylval.tok = create_token(NULL,line,column-yyleng);  return WHILE; } }
"if"                                            { column+=yyleng; print_text("IF"); if (flag == 2) { yylval.tok = create_token(NULL,line,column-yyleng); return IF; } }

"int"                                           { column+=yyleng; print_text("INT"); if (flag == 2) { yylval.tok = create_token(NULL,line,column-yyleng);  return INT; } }
"char"                                          { column+=yyleng; print_text("CHAR"); if(flag == 2) { yylval.tok = create_token(NULL,line,column-yyleng);  return CHAR; } }
"short"                                         { column+=yyleng; print_text("SHORT"); if (flag == 2) { yylval.tok = create_token(NULL,line,column-yyleng); return SHORT; } }
"double"                                        { column+=yyleng; print_text("DOUBLE"); if (flag == 2) { yylval.tok = create_token(NULL,line,column-yyleng);  return DOUBLE; } }
"void"                                          { column+=yyleng; print_text("VOID"); if (flag == 2) { yylval.tok = create_token(NULL,line,column-yyleng); return VOID; } }
"return"                                        { column+=yyleng; print_text("RETURN"); if (flag == 2) { yylval.tok = create_token(NULL,line,column-yyleng); return RETURN; } }

"&"                                             { column+=yyleng; print_text("BITWISEAND"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng); return BITWISEAND; }  }
"|"                                             { column+=yyleng; print_text("BITWISEOR");  if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng); return BITWISEOR; } }
"^"                                             { column+=yyleng; print_text("BITWISEXOR"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng); return BITWISEXOR; }  }
"&&"                                            { column+=yyleng; print_text("AND"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng); return AND; } }
"="                                             { column+=yyleng; print_text("ASSIGN"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng); return ASSIGN; } }
"*"                                             { column+=yyleng; print_text("MUL"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng); return MUL; } }
","                                             { column+=yyleng; print_text("COMMA"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng); return COMMA; } }
"/"                                             { column+=yyleng; print_text("DIV"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng);  return DIV; } }
"=="                                            { column+=yyleng; print_text("EQ"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng); return EQ; } }
">="                                            { column+=yyleng; print_text("GE"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng); return GE; } }
">"                                             { column+=yyleng; print_text("GT"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng); return GT; } }

"{"                                             { column+=yyleng; print_text("LBRACE"); if (flag == 2) return LBRACE; }
"<="                                            { column+=yyleng; print_text("LE"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng);  return LE; } }
"("                                             { column+=yyleng; print_text("LPAR"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng); return LPAR; } }
"<"                                             { column+=yyleng; print_text("LT"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng); return LT; } }
"-"                                             { column+=yyleng; print_text("MINUS"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng);  return MINUS; } }
"%"                                             { column+=yyleng; print_text("MOD"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng);  return MOD; } }
"!="                                            { column+=yyleng; print_text("NE"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng);  return NE; } }
"!"                                             { column+=yyleng; print_text("NOT"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng); return NOT; } }
"||"                                            { column+=yyleng; print_text("OR"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng); return OR; } }
"+"                                             { column+=yyleng; print_text("PLUS"); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng);  return PLUS; } }
"}"                                             { column+=yyleng; print_text("RBRACE"); if (flag == 2) return RBRACE; }
")"                                             { column+=yyleng; print_text("RPAR"); if (flag == 2) {  return RPAR; } }
";"                                             { column+=yyleng; print_text("SEMI"); if (flag == 2) {  return SEMI; } }
{RESERVED}                                      { column+=yyleng; print_content("RESERVED", yytext); if (flag == 2) { yylval.tok = create_token(NULL,line,column-yyleng); return RESERVED; } }

{TAB}                                           { column+=yyleng; }
{SPACE}                                         { column+=yyleng; }
{LINETERMINATOR}                                { column=1; line++; }

{ID}                                            { column+=yyleng; print_content("ID",yytext); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng); return ID; } }
{INTLIT}                                        { column+=yyleng; print_content("INTLIT",yytext); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng);  return INTLIT; } }
{REALLIT}                                       { column+=yyleng; print_content("REALLIT",yytext); if (flag == 2) { yylval.tok = create_token(yytext,line,column-yyleng);  return REALLIT; } }

{SINGLESPLIT}                                   { yymore(); BEGIN CHARSTATE; curr_column = column; curr_line = line; error = -1; }
<CHARSTATE>{CHARLIT}                            { yymore(); error++; }
<CHARSTATE>\\(.?)                               { yymore(); error=1;}
<CHARSTATE>{LINETERMINATOR}                     { BEGIN 0; printf("Line %d, col %d: unterminated char constant\n",curr_line,curr_column); line++; column=1; }
<CHARSTATE>{SINGLESPLIT}                        { BEGIN 0; if(error == 0) { print_content("CHRLIT",yytext); } else { printf("Line %d, col %d: invalid char constant (%s)\n",curr_line,curr_column,yytext);} column+=yyleng; if (flag == 2) { yylval.tok = create_token(yytext, line, column-yyleng);  return CHRLIT; } }
<CHARSTATE><<EOF>>                              { BEGIN 0; printf("Line %d, col %d: unterminated char constant\n",curr_line,curr_column); column+=yyleng; return 0; }

<<EOF>>                                         { column+=yyleng; return 0; }
.                                               { printf("Line %d, col %d: illegal character (%s)\n",line,column,yytext); column+=yyleng; }

%%

/* 
   Francisco José Rodrigues dos Santos 2015238068
   João Afonso Póvoa Marques 2015227041
*/

void print_text(char* text) {
  if (flag == 1){
    printf("%s\n",text);
  }
}

void print_content(char* text, char* content) {
  if (flag == 1){
    printf("%s(%s)\n",text,content);
  }
}


int yywrap(void) {
  return 1;
}

void yyerror(const char * s) {
  printf("Line %d, col %d: %s: %s\n",line,(int)(column-yyleng), s, yytext);
}

int main(int argc, char * argv[])
{
    if (argc > 1) {
        /* Meta 1 */
        if(strcmp(argv[1],"-l") == 0) {
            flag = 1;
            yylex();
        }
        /* Meta 2 */
        if(strcmp(argv[1],"-t") == 0 || strcmp(argv[1],"-2") == 0) {
          if(strcmp(argv[1],"-t") == 0) {
            tree_flag = 1; 
          }

          flag = 2;
          yyparse();
          if (tree_flag == 1 && root != NULL) {
            print_tree(root,0);
          }
        }
        if(strcmp(argv[1],"-s") == 0) {
          flag = 2;
          tree_flag = 1;
          yyparse();

          symbols_table = create_table("Global");
          symbols_table->print_flag = 1;
          current_table = symbols_table;

          create_predefined_functions(symbols_table);
          read_tree(root);
          print_tables();
          if (tree_flag == 1 && root != NULL) {
            print_tree(root,0);
          }
        }
    }
    else {
        flag = 2;
        yyparse();

        symbols_table = create_table("Global");
        symbols_table->print_flag = 1;
        current_table = symbols_table;

        create_predefined_functions(symbols_table);
        read_tree(root);
    }
    yylex_destroy();
    return 0;
}
