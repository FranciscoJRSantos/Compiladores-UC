%{
    #include <stdio.h>
    #include <stdlib.h> 
    #include <string.h>
    #include "ast.h"
    int flag = 0,print_tree = 0;

    node root;

%}

%union 
{
int ival;
char * cval;
struct no * node;

}

%token CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI 
%token <cval> ID CHRLIT REALLIT RESERVED INTLIT

%type <node> Program PrimaryExpr ParameterList ParameterDeclaration FunctionsAndDeclarations FunctionDeclaration FunctionDefinition FunctionBody FunctionDeclarator Statement AndExpr InclusiveOrExpr ExclusiveOrExpr Declaration Declarator DeclarationList AssignExpr LogicalOrExpr LogicalAndExpr AdditiveExpr MultiplicativeExpr Jump_Stm Iter_Stm Compound_Stm TypeSpec Expr_Stm Expr DeclarationsAndStatements RelationalExpr EqualExpr Select_Stm

%start Program 

%%
Program
        : FunctionsAndDeclarations                      { root = create_node(root_node,"","Program"); }
        ;

PrimaryExpr
        : ID                                            { $$ = create_node(identifier_node,$1,"Id"); }
        | INTLIT                                        { $$ = create_node(terminal_node,$1,"IntLit"); }
        | CHRLIT                                        { $$ = create_node(terminal_node,$1,"ChrLit"); }
        | REALLIT                                       { $$ = create_node(terminal_node,$1,"RealLit"); } 
        | LPAR Expr RPAR                                { $$ = $2; }
        | LPAR error RPAR                               { $$ = NULL; flag=1; }
        ; 

ParameterList
        : ParameterDeclaration                          { $$ = $1; }
        | ParameterList COMMA ParameterDeclaration
        ;
        
ParameterDeclaration
        : TypeSpec                                      { $$ = $1; } 
        | TypeSpec ID                                   { $$ = $1;  }
        ;

FunctionsAndDeclarations
        : FunctionDefinition                            { $$ = $1; } 
        | FunctionDeclaration                           { $$ = $1; } 
        | Declaration                                   { $$ = $1; } 
        | FunctionsAndDeclarations FunctionDefinition   { $$ = $1; } 
        | FunctionsAndDeclarations FunctionDeclaration  { $$ = $1; } 
        | FunctionsAndDeclarations Declaration          { $$ = $1; } 
        ; 

FunctionDefinition
        : TypeSpec FunctionDeclarator FunctionBody
        ;

FunctionBody
        : LBRACE RBRACE                                 { $$ = create_node(functiondec_node,"","FunctionBody"); }
        | LBRACE DeclarationsAndStatements RBRACE       { $$ = create_node(functiondec_node,"","FunctionBody"); add_son($$,$2); }
        ;

DeclarationsAndStatements
        : Statement DeclarationsAndStatements 
        | Declaration DeclarationsAndStatements 
        | Statement                                     { $$ = $1; }
        | Declaration                                   { $$ = $1; }
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
        | TypeSpec error SEMI
        ;

DeclarationList
        : COMMA Declarator
        | DeclarationList COMMA Declarator
        ;

TypeSpec
        : CHAR                                          { $$ = create_node(terminal_node,"","Char"); }
        | INT                                           { $$ = create_node(terminal_node,"","Int"); }      
        | VOID                                          { $$ = create_node(terminal_node,"","Void"); }
        | SHORT                                         { $$ = create_node(terminal_node,"","Short"); }
        | DOUBLE                                        { $$ = create_node(terminal_node,"","Double"); }
        ;

Declarator
        : ID                                            { $$ = create_node(identifier_node,"","Id");; }
        | ID ASSIGN AssignExpr                          { $$ = create_node(identifier_node,"","Id"); add_son($$,$3); }
        ;

Statement
        : Compound_Stm                                  { $$ = $1; }
        | Expr_Stm                                      { $$ = $1; }
        | Select_Stm                                    { $$ = $1; }
        | Iter_Stm                                      { $$ = $1; }
        | Jump_Stm                                      { $$ = $1; }
        ;

Compound_Stm
        : LBRACE RBRACE                                 
        | LBRACE Statement RBRACE                       
        | LBRACE error RBRACE
        ;

Expr_Stm
        : SEMI
        | Expr SEMI
        | error SEMI
        ;

Select_Stm
        : IF LPAR Expr RPAR Statement                   { $$ = create_node(stm_node,"","While"); add_son($$,$3); if ($5 != NULL) { add_brother($3,$5); } } 
        | IF LPAR Expr RPAR Statement ELSE Statement
        ;

Iter_Stm
        : WHILE LPAR Expr RPAR Statement                { $$ = create_node(stm_node,"","While"); add_son($$,$3); if ($5 != NULL) { add_brother($3,$5); } }
        ;

Jump_Stm
        : RETURN SEMI                                   { $$ = create_node(stm_node,"","Return"); }
        | RETURN Expr SEMI                              { $$ = create_node(stm_node,"","Return"); /* Add son node*/}
        ; 

MultiplicativeExpr
        : PrimaryExpr                                   { $$ = $1; }
        | MultiplicativeExpr MUL PrimaryExpr            { $$ = create_node(operator_node,"","Mul"); add_son($$,$1); add_brother($1,$3); }
        | MultiplicativeExpr DIV PrimaryExpr            { $$ = create_node(operator_node,"","Div"); add_son($$,$1); add_brother($1,$3); } 
        | MultiplicativeExpr MOD PrimaryExpr            { $$ = create_node(operator_node,"","Mod"); add_son($$,$1); add_brother($1,$3); } 
        ;

AdditiveExpr
        : MultiplicativeExpr                            { $$ = $1; }
        | AdditiveExpr PLUS MultiplicativeExpr          { $$ = create_node(operator_node,"","Plus"); add_son($$,$1); add_brother($1,$3); }
        | AdditiveExpr MINUS MultiplicativeExpr         { $$ = create_node(operator_node,"","Minus"); add_son($$,$1); add_brother($1,$3); }
        ;

RelationalExpr
        : AdditiveExpr                                  { $$ = $1; }
        | RelationalExpr LT AdditiveExpr                { $$ = create_node(operator_node,"","Lt"); add_son($$,$1); add_brother($1,$3); }
        | RelationalExpr GT AdditiveExpr                { $$ = create_node(operator_node,"","Gt"); add_son($$,$1); add_brother($1,$3); }
        | RelationalExpr LE AdditiveExpr                { $$ = create_node(operator_node,"","Le"); add_son($$,$1); add_brother($1,$3); }
        | RelationalExpr GE AdditiveExpr                { $$ = create_node(operator_node,"","Ge"); add_son($$,$1); add_brother($1,$3); }
        ;

EqualExpr
        : RelationalExpr                                { $$ = $1; }
        | EqualExpr EQ RelationalExpr                   { $$ = create_node(operator_node,"","Eq"); add_son($$,$1); add_brother($1,$3); }
        | EqualExpr NE RelationalExpr                   { $$ = create_node(operator_node,"","Ne"); add_son($$,$1); add_brother($1,$3); }
        ;

AndExpr
        : EqualExpr                                     { $$ = $1; }
        | AndExpr BITWISEAND EqualExpr                  { $$ = create_node(operator_node,"","BitWiseAnd"); add_son($$,$1); add_brother($1,$3); }
        ;

ExclusiveOrExpr
        : AndExpr                                       { $$ = $1; }
        | ExclusiveOrExpr BITWISEXOR AndExpr            { $$ = create_node(operator_node,"","BitWiseXor"); add_son($$,$1); add_brother($1,$3); }
        ;

InclusiveOrExpr 
        : ExclusiveOrExpr                               { $$ = $1; }
        | InclusiveOrExpr BITWISEOR ExclusiveOrExpr     { $$ = create_node(operator_node,"","BitWiseOr"); add_son($$,$1); add_brother($1,$3); }

LogicalAndExpr
        : InclusiveOrExpr                               { $$ = $1; }
        | LogicalAndExpr AND InclusiveOrExpr            { $$ = create_node(operator_node,"","And"); add_son($$,$1); add_brother($1,$3); }
        ;

LogicalOrExpr
        : LogicalAndExpr                                { $$ = $1; }
        | LogicalOrExpr OR LogicalAndExpr               { $$ = create_node(operator_node,"","Or"); add_son($$,$1); add_brother($1,$3); }
        ;

AssignExpr
        : LogicalOrExpr                                 { $$ = $1; }
        | PrimaryExpr ASSIGN AssignExpr                 /*{ $$ = create_node(operator_node,"","Store");  } Rever esta shit estranha */
        ;

Expr    
        : AssignExpr                                    { $$ = $1; }
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
        if(strcmp(argv[1],"-t") == 0)
        {
            flag = 2;
            // print_tree = 1; 
            yyparse();
            yylex_destroy(); 
        }
    }
    return 0;
}
