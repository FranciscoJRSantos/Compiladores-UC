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

Primary_Expr
        : ID
        | INTLIT 
        | CHRLIT 
        | REALLIT 
        | LPAR Expr RPAR
        ; 

Secondary_Expr
        : ID LPAR 
        ;

Program
        : INT ID LBRACE ProgramRead RBRACE
        ;

ProgramRead
        : FunctionsAndDeclarations
        | SEMI 
        | FunctionsAndDeclarations ProgramRead
        | SEMI ProgramRead
        ;

FunctionsAndDeclarations
        : FunctionDefinition 
        | FunctionDeclaration
        | Declaration
        | FunctionDefinition FunctionsAndDeclarations
        | FunctionDeclaration FunctionsAndDeclarations
        | Declaration FunctionsAndDeclarations
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

ParameterList
        : ParameterDeclaration PL2
        ;

PL2
        : COMMA ParameterDeclaration
        | COMMA ParameterDeclaration PL2
        ;

ParameterDeclaration
        : TypeSpec
        | TypeSpec ID
        ;

Declaration
        : TypeSpec Declarator D2 SEMI
        ;

D2
        : COMMA Declarator
        | COMMA Declarator D2
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
        | ID ASSIGN Expr
        ;

Statement
        : SEMI 
        | Expr SEMI 
        | LBRACE Statement2 RBRACE 
        | IF LPAR Expr RPAR Statement 
        | IF LPAR Expr RPAR Statement ELSE Statement 
        | WHILE LPAR Expr RPAR Statement 
        | RETURN SEMI
        | RETURN Expr SEMI
        ;

Statement2
        : Statement
        | Statement Statement2
        ;

Multiplicative_Expr
        : Primary_Expr
        | Multiplicative_Expr MUL Primary_Expr
        | Multiplicative_Expr DIV Primary_Expr
        | Multiplicative_Expr MOD Primary_Expr
        ;

Additive_Expr
        : Multiplicative_Expr
        | Additive_Expr PLUS Multiplicative_Expr
        | Additive_Expr MINUS Multiplicative_Expr
        ;

Equal_Expr
        : Relational_Expr
        | Relational_Expr LT Additive_Expr
        | Relational_Expr GT Additive_Expr
        | Relational_Expr LE Additive_Expr
        | Relational_Expr GE Additive_Expr
        ;

And_Expr
        : Equal_Expr
        | And_Expr BITWISEAND Equal_Expr
        ;

Exclusive_or_Expr
        : And_Expr 
        | Exclusive_or_Expr BITWISEXOR And_Expr
        ;

Inclusive_or_Expr 
        : Exclusive_or_Expr 
        | Inclusive_or_Expr OR Exclusive_or_Expr

Logical_and_Expr
        : Inclusive_or_Expr
        | Logical_and_Expr AND Inclusive_or_Expr
        ;

Logical_or_Expr
        : Logical_and_Expr 
        | Logical_or_Expr OR Logical_and_Expr
        ;

Conditional_Expression
        : Logical_or_Expr
        ;

Assign_Expr
        : Conditional_Expression
        | TypeRead ASSIGN Assign_Expr
        ;

Expr    
        : Assign_Expr
        | Expr COMMA Assign_Expr
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
