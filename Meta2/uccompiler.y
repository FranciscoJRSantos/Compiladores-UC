%{
    #include <stdio.h>
    #include <stdlib.h> 
	#include <stdarg.h>
    #include "ast.h"
    int flag = 0;

%}

%union 
{
int ival;
char * cval;

}

%token CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND 
%token ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI 
%token <cval> ID CHRLIT REALLIT RESERVED
%token <ival> INTLIT

%right ASSIGN
%left COMMA

%%

Program: INT ID LBRACE ProgramRead RBRACE;

ProgramRead: FunctionsAndDeclarations
           | SEMI 
           | FunctionsAndDeclarations ProgramRead
           | SEMI ProgramRead
           ;

FunctionsAndDeclarations: FunctionDefinition 
                        | FunctionDeclaration
                        | Declaration
                        | FunctionDefinition FunctionsAndDeclarations
                        | FunctionDeclaration FunctionsAndDeclarations
                        | Declaration FunctionsAndDeclarations
                        ;


FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody;

FunctionBody: LBRACE RBRACE
            | LBRACE DeclarationsAndStatements RBRACE
            ;

DeclarationsAndStatements: Statement DeclarationsAndStatements 
                         | Declaration DeclarationsAndStatements 
                         | Statement 
                         | Declaration
                         ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI;

FunctionDeclarator: ID LPAR ParameterList RPAR;

ParameterList: ParameterDeclaration PL2;

PL2: COMMA ParameterDeclaration
   | COMMA ParameterDeclaration PL2
   ;

ParameterDeclaration: TypeSpec
                    | TypeSpec ID
                    ;

Declaration: TypeSpec Declarator D2 SEMI;

D2: COMMA Declarator
  | COMMA Declarator D2
  ;

TypeSpec:   CHAR 
        |   INT 
        |   VOID 
        |   SHORT 
        |   DOUBLE
        ;

Declarator: ID 
          | ID ASSIGN Expr
          ;

Statement: SEMI 
         | Expr SEMI 
         | LBRACE Statement2 RBRACE 
         | IF LPAR Expr RPAR Statement 
         | IF LPAR Expr RPAR Statement ELSE Statement 
         | WHILE LPAR Expr RPAR Statement 
         | RETURN SEMI
         | RETURN Expr SEMI
         ;

Statement2: Statement
   | Statement Statement2
   ;

Expr: Expr Assign_Expr Expr 
    | Expr Comparative_Expr Expr 
    | Expr Multiplicative_Expr Expr 
    | Expr Addictive_Expr Expr 
    | Expr Relational_Expr Expr
    | Expr Equality_Expr Expr
    | EPMN Expr 
    | ID LPAR RPAR
    | ID LPAR ECE RPAR
    | ELIT 
    ;

Assign_Expr: ASSIGN 
           | COMMA 
           ;

Multiplicative_Expr: MUL 
                   | DIV 
                   | MOD
                   ;

Addictive_Expr: PLUS 
              | MINUS
              ;

Comparative_Expr: OR 
                | AND 
                | BITWISEAND 
                | BITWISEOR 
                | BITWISEXOR 
                ;

Relational_Expr: LE 
               | GE 
               | LT 
               | GT 
               ;

Equality_Expr: EQ
             | NE 
             ;

EPMN: PLUS 
    | MINUS 
    | NOT
    ;

ECE: COMMA Expr
   | COMMA Expr ECE 
   ;

ELIT: ID 
    | INTLIT 
    | CHRLIT 
    | REALLIT 
    | LPAR Expr RPAR
    ;

%%
int main(int argc, char * argv[])
{
    if (argc > 1)
    {
        if(strcmp(argv[1],"-l") == 0)
        {
            flag = 1;
            yylex();
        }
        if(strcmp(argv[1],"-t" == 0)) 
        {
            flag = 2;
            print_tree = 1; 
            yyparse();
            yylex_destroy(); 
        }
    }
    return 0;
}
