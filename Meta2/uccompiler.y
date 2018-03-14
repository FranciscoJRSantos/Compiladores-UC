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

%start Program 

%%
Program
        : FunctionsAndDeclarations
        ;

PrimaryExpr
        : ID
        | INTLIT 
        | CHRLIT 
        | REALLIT 
        | LPAR Expr RPAR
        ; 

ParameterList
        : ParameterDeclaration
        | ParameterList COMMA ParameterDeclaration
        ;
        
ParameterDeclaration
        : TypeSpec
        | TypeSpec ID
        ;

FunctionsAndDeclarations
        : FunctionDefinition 
        | FunctionDeclaration
        | Declaration
        | FunctionsAndDeclarations FunctionDefinition 
        | FunctionsAndDeclarations FunctionDeclaration 
        | FunctionsAndDeclarations Declaration 
        ; 

FunctionDefinition
        : TypeSpec FunctionDeclarator FunctionBody
        ;

FunctionBody
        : LBRACE RBRACE
        | LBRACE DeclarationsAndStatements RBRACE
        ;

DeclarationsAndStatements
        : Statement DeclarationsAndStatements 
        | Declaration DeclarationsAndStatements 
        | Statement 
        | Declaration
        ;

FunctionDeclaration
        : TypeSpec FunctionDeclarator SEMI
        ;

FunctionDeclarator
        : ID LPAR ParameterList RPAR
        ; 

Declaration
        : TypeSpec Declarator SEMI
        | TypeSpec Declarator DeclarationList SEMI
        ;

DeclarationList
        : COMMA Declarator
        | DeclarationList COMMA Declarator
        ;

TypeSpec
        :   CHAR 
        |   INT 
        |   VOID 
        |   SHORT 
        |   DOUBLE
        ;

Declarator
        : ID 
        | ID ASSIGN AssignExpr
        ;

Statement
        : Compound_Stm
        | Expr_Stm
        | Select_Stm
        | Iter_Stm
        | Jump_Stm
        ;

Compound_Stm
        : LBRACE RBRACE
        | LBRACE Statement RBRACE
        ;

Expr_Stm
        : SEMI
        | Expr SEMI
        ;

Select_Stm
        : IF LPAR Expr RPAR Statement
        | IF LPAR Expr RPAR Statement ELSE Statement
        ;

Iter_Stm
        : WHILE LPAR Expr RPAR Statement
        ;

Jump_Stm
        : RETURN SEMI
        | RETURN Expr SEMI
        ; 

MultiplicativeExpr
        : PrimaryExpr
        | MultiplicativeExpr MUL PrimaryExpr
        | MultiplicativeExpr DIV PrimaryExpr
        | MultiplicativeExpr MOD PrimaryExpr
        ;

AdditiveExpr
        : MultiplicativeExpr
        | AdditiveExpr PLUS MultiplicativeExpr
        | AdditiveExpr MINUS MultiplicativeExpr
        ;

RelationalExpr
        : AdditiveExpr 
        | RelationalExpr LT AdditiveExpr
        | RelationalExpr GT AdditiveExpr
        | RelationalExpr LE AdditiveExpr
        | RelationalExpr GE AdditiveExpr
        ;

EqualExpr
        : RelationalExpr
        | EqualExpr EQ RelationalExpr
        | EqualExpr NE RelationalExpr
        ;

AndExpr
        : EqualExpr
        | AndExpr BITWISEAND EqualExpr
        ;

ExclusiveOrExpr
        : AndExpr 
        | ExclusiveOrExpr BITWISEXOR AndExpr
        ;

InclusiveOrExpr 
        : ExclusiveOrExpr 
        | InclusiveOrExpr BITWISEOR ExclusiveOrExpr

LocagicalAndExpr
        : InclusiveOrExpr
        | LocagicalAndExpr AND InclusiveOrExpr
        ;

LogicalOrExpr
        : LocagicalAndExpr 
        | LogicalOrExpr OR LocagicalAndExpr
        ;

ConditionalExpr
        : LogicalOrExpr
        ;

AssignExpr
        : ConditionalExpr
        | PrimaryExpr ASSIGN AssignExpr
        | PrimaryExpr NOT ASSIGN AssignExpr
        ;

Expr    
        : AssignExpr
        | Expr COMMA AssignExpr
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
