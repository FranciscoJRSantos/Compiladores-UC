NUMBERS             [0-9]
CHARACTERS          [a-zA-Z]
NEWLINE             "\n"
CARRIAGERETURN      "\r"
TAB                 "\t"
SPACE               " "
INITCOMMENT         "/*"
SINGLECOMMENT       "//"

%{
#include <stdio.h>
#include "y.tab.h"

void count(void);
%}

%%

"char"              { count(); print_text("CHAR"); return(CHAR); }
"else"              { count(); print_text("ELSE"); return(ELSE); }
"while"             { count(); print_text("WHILE");return(WHILE); }
"if"                { count(); print_text("IF"); return(IF); }
"int"               { count(); print_text("INT"); return(INT); }
"short"             { count(); print_text("SHORT"); return(SHORT); }
"double"            { count(); print_text("DOUBLE"); return(DOUBLE); }
"return"            { count(); print_text("RETURN"); return(RETURN); }
"void"              { count(); print_text("VOID"); return(VOID); }
"&"                 { count(); print_text("BITWISEAND"); return(BITWISEAND); }
"|"                 { count(); print_text("BITWISEOR"); return(BITWISEOR); }
"^"                 { count(); print_text("BITWISEXOR"); return(BITWISEXOR); }
"&&"                { count(); print_text("AND"); return(AND); }
"="                 { count(); print_text("ASSIGN"); return(ASSIGN); }
"*"                 { count(); print_text("MUL"); return(MUL); }
","                 { count(); print_text("COMMA"); return(COMMA); }
"/"                 { count(); print_text("DIV"); return(DIV); }
"=="                { count(); print_text("EQ"); return(EQ); }
">="                { count(); print_text("GE"); return(GE); }
">"                 { count(); print_text("GT"); return(GT); }
"{"                 { count(); print_text("LBRACE"); return(LBRACE); }
"<="                { count(); print_text("LE"); return(LE); }
"("                 { count(); print_text("LPAR"); return(LPAR); }
"<"                 { count(); print_text("LT"); return(LT); }
"-"                 { count(); print_text("MINUS"); return(MINUS); }
"%"                 { count(); print_text("MOD"); return(MOD); }
"!="                { count(); print_text("NE"); return(NE); }
"!"                 { count(); print_text("NOT"); return(NOT); }
"||"                { count(); print_text("OR"); return(OR); }
"+"                 { count(); print_text("PLUS"); return(PLUS); }
"}"                 { count(); print_text("RBRACE"); return(RBRACE); }
")"                 { count(); print_text("RPAIR"); return(RPAIR); }
";"                 { count(); print_text("SEMI"); return(SEMI); }

%%

int yywrap(void)
{
  return 1;
}

int column = 0;
int line = 1;

void count(void)
{
  int i;

  for (i = 0; yytext[i] != '\0'; i++)
    if (yytext[i] == '\n'){
      column = 0;
      line++;
    }
    else if (yytext[i] == '\t')
      column += 4 - (column % 4);
    else
      column++;

  ECHO;
}
