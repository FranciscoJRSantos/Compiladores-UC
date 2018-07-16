
%{
    #include <stdio.h>
    #include <stdlib.h> 
    #include <string.h>
    #include "ast.h"
    extern int flag,tree_flag;

    node root = NULL;
    node aux = NULL;

    extern int column, line;

%}

%union 
{
  struct token * tok;
  struct no * node;
}

%token <tok> CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN  BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI ID CHRLIT REALLIT RESERVED INTLIT VOID

%type <node> Program PrimaryExpr ParameterList ParameterDeclaration FunctionsAndDeclarations FunctionDeclaration FunctionDefinition FunctionBody FunctionDeclarator Statement AndExpr InclusiveOrExpr ExclusiveOrExpr Declaration Declarator Declarator_ AssignExpr LogicalOrExpr LogicalAndExpr AdditiveExpr MultiplicativeExpr Jump_Stm Iter_Stm Compound_Stm TypeSpec Expr_Stm Expr DeclarationsAndStatements RelationalExpr EqualExpr Select_Stm ArgExpr FunctionCallExpr UnaryExpr BlockItemStm ParameterDeclaration_ StatementError OptionalExpr

%nonassoc IFS
%nonassoc ELSE
%%

Program
        : FunctionsAndDeclarations                              { root = create_node("Program", NULL, 1, $1); }
        ;


FunctionsAndDeclarations
        : FunctionDefinition                                    { $$ = $1; }
        | FunctionDeclaration                                   { $$ = $1; } 
        | Declaration                                           { $$ = $1; } 
        | FunctionDefinition FunctionsAndDeclarations           { $$ = add_brother($1,$2); } 
        | FunctionDeclaration FunctionsAndDeclarations          { $$ = add_brother($1,$2); } 
        | Declaration FunctionsAndDeclarations                  { $$ = add_brother($1,$2); } 
        ; 

FunctionDefinition
        : TypeSpec FunctionDeclarator FunctionBody              { $$ = create_node("FuncDefinition",NULL,3,$1,$2,$3); }
        ;

FunctionBody
        : LBRACE RBRACE                                         { $$ = create_node("FuncBody",NULL,0); }
        | LBRACE DeclarationsAndStatements RBRACE               { $$ = create_node("FuncBody",NULL,1,$2); }
        ;

DeclarationsAndStatements
        : Statement DeclarationsAndStatements                   { $$ = add_brother($1,$2); } 
        | Declaration DeclarationsAndStatements                 { $$ = add_brother($1,$2); } 
        | Statement                                             { $$ = $1; } 
        | Declaration                                           { $$ = $1; } 
        ;

FunctionDeclaration
        : TypeSpec FunctionDeclarator SEMI                      { $$ = create_node("FuncDeclaration",NULL,2,$1,$2); }
        ;

FunctionDeclarator
        : ID LPAR ParameterList RPAR                            { 
          $$ = add_brother(create_node("Id",$1->cval,0),$3); 
          $$->line = $1->line; 
          $$->column = $1->column; 
          $$->is_literal = 1;
          free($1); 
        }
        ; 

ParameterList
        : ParameterDeclaration ParameterDeclaration_            { $$ = create_node("ParamList",NULL,2,$1,$2); }
        ;

ParameterDeclaration_
        : ParameterDeclaration_ COMMA ParameterDeclaration      { $$ = add_brother($1,$3); }
        | empty                                                 { $$ = NULL; }
        ;
        
ParameterDeclaration
        : TypeSpec                                              { $$ = create_node("ParamDeclaration",NULL,1,$1); }
        | TypeSpec ID                                           { 
          aux = create_node("Id",$2->cval,0); 
          aux->line = $2->line;
          aux->column = $2->column;
          aux->is_literal = 1;
          $$ = create_node("ParamDeclaration",NULL,2,$1,aux); 
          $$->line = $2->line; 
          $$->column = $2->column; 
          free($2); 
        } 
        ;

Declaration
        : TypeSpec Declarator Declarator_ SEMI                  {
            $2 = add_brother($2,$3); 
            aux = $2; 
            while(aux != NULL) { 
                aux->son = add_brother(create_node($1->label,NULL,0),aux->son); 
                aux = aux->brother; 
            }
            $$ = $2;
            free($1->label); 
            free($1->cval); 
            free($1); 
        }
        | error SEMI                                            { $$ = NULL; tree_flag = 0; }
        ;

Declarator_
        : Declarator_ COMMA Declarator                          { $$ = add_brother($1,$3); }
        | empty                                                 { $$ = NULL; }
        ;

Declarator
        : ID ASSIGN AssignExpr                                  { 
          aux = create_node("Id",$1->cval,0); 
          aux->line = $1->line;
          aux->column = $1->column;
          aux->is_literal = 1;
          if($3 != NULL) {  
            $$ = create_node("Declaration",NULL,2,aux,$3); 
            $$->line = aux->line;
            $$->column = aux->column;
          } 
          free($1); 
        }
        | ID                                                    { 
          aux = create_node("Id",$1->cval,0); 
          aux->line = $1->line;
          aux->column = $1->column;
          aux->is_literal = 1;
          $$ = create_node("Declaration",NULL,1,aux); 
          $$->line = aux->line;
          $$->column = aux->column;
          free($1); 
        } 
        ;

TypeSpec
        : CHAR                                                  { $$ = create_node("Char", NULL, 0); $$->line = $1->line; $$->column = $1->column; } 
        | INT                                                   { $$ = create_node("Int", NULL, 0); $$->line = $1->line; $$->column = $1->column; } 
        | VOID                                                  { $$ = create_node("Void", NULL, 0); $$->line = $1->line; $$->column = $1->column; } 
        | SHORT                                                 { $$ = create_node("Short", NULL, 0); $$->line = $1->line; $$->column = $1->column; } 
        | DOUBLE                                                { $$ = create_node("Double", NULL, 0); $$->line = $1->line; $$->column = $1->column; } 
        ;

StatementError
        : error SEMI                                            { $$ = NULL; tree_flag = 0; }
        | Statement                                             { $$ = $1; }

Statement
        : Compound_Stm                                          { $$ = $1; } 
        | Expr_Stm                                              { $$ = $1; } 
        | Select_Stm                                            { $$ = $1; } 
        | Iter_Stm                                              { $$ = $1; } 
        | Jump_Stm                                              { $$ = $1; } 
        ;

Compound_Stm
        : LBRACE RBRACE                                         { $$ = NULL; } 
        | LBRACE BlockItemStm RBRACE                            { if($2 != NULL && $2->brother != NULL) { $$ = create_node("StatList", NULL, 1, $2); } else $$ = $2; } 
        | LBRACE error RBRACE                                   { $$ = NULL; tree_flag = 0; } 
        ;

BlockItemStm
        : StatementError BlockItemStm                           { $$ = add_brother($1, $2); }
        | StatementError                                        { $$ = $1; }
        ;

Expr_Stm
        : OptionalExpr SEMI                                     { if (strcmp($1->label, "Null") == 0) { $$ = NULL; free($1); } else $$ = $1; } 
        ;

OptionalExpr
        : empty                                                 { $$ = create_node("Null", NULL, 0); }
        | Expr                                                  { $$ = $1; }
        ;

Select_Stm
        : IF LPAR Expr RPAR StatementError %prec IFS            { 
            if($3 == NULL) 
                $3 = create_node("Null", NULL, 0); 
            if($5 == NULL) 
                $5 = create_node("Null", NULL, 0); 
            aux = create_node("Null", NULL, 0);
            $$ = create_node("If", NULL, 3, $3, $5, aux);
        } 
        | IF LPAR Expr RPAR StatementError ELSE StatementError  { 
            if ($3 == NULL)
                $3 = create_node("Null", NULL, 0); 
            if($5 == NULL) 
                $5 = create_node("Null", NULL, 0); 
            if($7 == NULL) 
                $7 = create_node("Null", NULL, 0); 
            $$ = create_node("If", NULL, 3, $3, $5, $7);
        } 
        ;

Iter_Stm
        : WHILE LPAR Expr RPAR StatementError                   { 
            if ($3 == NULL)
                $3 = create_node("Null", NULL, 0);
            if ($5 == NULL) 
                $5 = create_node("Null", NULL, 0); 
            $$ = create_node("While", NULL, 2, $3, $5); 
        }
        ;

Jump_Stm
        : RETURN OptionalExpr SEMI                               { 
          $$ = create_node("Return", NULL, 1, $2); 
          if (strcmp($2->label,"Null") != 0) { 
            $$->line = $2->line; 
            $$->column = $2->column; 
          } 
          else { 
            $$->line = $1->line;
            $$->column = $1->column;
          }
        } 
        ; 

PrimaryExpr
        : ID                                                    { $$ = create_node("Id",$1->cval,0); $$->line = $1->line; $$->column = $1->column; $$->is_literal = 1; free($1); } 
        | INTLIT                                                { $$ = create_node("IntLit",$1->cval,0); $$->line = $1->line; $$->column = $1->column; $$->is_literal = 1; free($1); } 
        | CHRLIT                                                { $$ = create_node("ChrLit",$1->cval,0); $$->line = $1->line; $$->column = $1->column; $$->is_literal = 1; free($1); } 
        | REALLIT                                               { $$ = create_node("RealLit",$1->cval,0); $$->line = $1->line; $$->column = $1->column; $$->is_literal = 1; free($1); } 
        | LPAR Expr RPAR                                        { $$ = $2; }
        | LPAR error RPAR                                       { $$ = create_node("Null", NULL, 0); }
        ; 

ArgExpr
        : AssignExpr                                            { $$ = $1; }
        | ArgExpr COMMA AssignExpr                              { $$ = add_brother($1, $3); }
        ;

FunctionCallExpr
        : PrimaryExpr                                           { $$ = $1; }
        | ID LPAR ArgExpr RPAR                                  { 
          aux = create_node("Id", $1->cval, 0); 
          aux->line = $1->line;
          aux->column = $1->column;
          aux->is_literal = 1;
          $$ = create_node("Call", NULL, 2, aux, $3); 
          $$->line = $1->line;
          $$->column = $1->column;
          free($1); 
        } 
        | ID LPAR RPAR                                          { 
          aux = create_node("Id", $1->cval, 0); 
          aux->line = $1->line;
          aux->column = $1->column;
          aux->is_literal = 1;
          $$ = create_node("Call", NULL, 1, aux); 
          $$->line = $1->line;
          $$->column = $1->column;
          free($1);
        }
        | ID LPAR error RPAR                                    { $$ = create_node("Null", NULL, 0); free($1); }
        ;
        

UnaryExpr
        : FunctionCallExpr                                      { $$ = $1; } 
        | PLUS UnaryExpr                                        { $$ = create_node("Plus",$1->cval,1,$2); $$->line = $1->line; $$->column = $1->column; } 
        | MINUS UnaryExpr                                       { $$ = create_node("Minus",$1->cval,1,$2); $$->line = $1->line; $$->column = $1->column; } 
        | NOT UnaryExpr                                         { $$ = create_node("Not",$1->cval,1,$2); $$->line = $1->line; $$->column = $1->column; } 
        ;

MultiplicativeExpr
        : UnaryExpr                                             { $$ = $1; } 
        | MultiplicativeExpr MUL UnaryExpr                      { $$ = create_node("Mul", $2->cval, 2, $1, $3); $$->line = $2->line; $$->column = $2->column; } 
        | MultiplicativeExpr DIV UnaryExpr                      { $$ = create_node("Div", $2->cval, 2, $1, $3); $$->line = $2->line; $$->column = $2->column; } 
        | MultiplicativeExpr MOD UnaryExpr                      { $$ = create_node("Mod", $2->cval, 2, $1, $3); $$->line = $2->line; $$->column = $2->column; } 
        ;

AdditiveExpr
        : MultiplicativeExpr                                    { $$ = $1; } 
        | AdditiveExpr PLUS MultiplicativeExpr                  { $$ = create_node("Add", $2->cval, 2, $1, $3); $$->line = $2->line; $$->column = $2->column;  } 
        | AdditiveExpr MINUS MultiplicativeExpr                 { $$ = create_node("Sub", $2->cval, 2, $1, $3); $$->line = $2->line; $$->column = $2->column;  } 
        ;

RelationalExpr
        : AdditiveExpr                                          { $$ = $1; } 
        | RelationalExpr LT AdditiveExpr                        { $$ = create_node("Lt", $2->cval, 2, $1, $3); $$->line = $2->line; $$->column = $2->column; } 
        | RelationalExpr GT AdditiveExpr                        { $$ = create_node("Gt", $2->cval, 2, $1, $3); $$->line = $2->line; $$->column = $2->column; } 
        | RelationalExpr LE AdditiveExpr                        { $$ = create_node("Le", $2->cval, 2, $1, $3); $$->line = $2->line; $$->column = $2->column; } 
        | RelationalExpr GE AdditiveExpr                        { $$ = create_node("Ge", $2->cval, 2, $1, $3); $$->line = $2->line; $$->column = $2->column; } 
        ;

EqualExpr
        : RelationalExpr                                        { $$ = $1; } 
        | EqualExpr EQ RelationalExpr                           { $$ = create_node("Eq", $2->cval, 2, $1, $3); $$->line = $2->line; $$->column = $2->column; } 
        | EqualExpr NE RelationalExpr                           { $$ = create_node("Ne", $2->cval, 2, $1, $3); $$->line = $2->line; $$->column = $2->column; } 
        ;

AndExpr
        : EqualExpr                                             { $$ = $1; } 
        | AndExpr BITWISEAND EqualExpr                          { $$ = create_node("BitWiseAnd", $2->cval,2,$1,$3); $$->line = $2->line; $$->column = $2->column; } 
        ;

ExclusiveOrExpr
        : AndExpr                                               { $$ = $1; } 
        | ExclusiveOrExpr BITWISEXOR AndExpr                    { $$ = create_node("BitWiseXor",$2->cval,2,$1,$3); $$->line = $2->line; $$->column = $2->column; } 
        ;

InclusiveOrExpr 
        : ExclusiveOrExpr                                       { $$ = $1; } 
        | InclusiveOrExpr BITWISEOR ExclusiveOrExpr             { $$ = create_node("BitWiseOr",$2->cval,2,$1,$3); $$->line = $2->line; $$->column = $2->column; } 
        ;

LogicalAndExpr
        : InclusiveOrExpr                                       { $$ = $1; } 
        | LogicalAndExpr AND InclusiveOrExpr                    { $$ = create_node("And",$2->cval,2,$1,$3); $$->line = $2->line; $$->column = $2->column; } 
        ;

LogicalOrExpr
        : LogicalAndExpr                                        { $$ = $1; } 
        | LogicalOrExpr OR LogicalAndExpr                       { $$ = create_node("Or",$2->cval,2,$1,$3); $$->line = $2->line; $$->column = $2->column; } 
        ;

AssignExpr
        : LogicalOrExpr                                         { $$ = $1; } 
        | LogicalOrExpr ASSIGN AssignExpr                       { $$ = create_node("Store",$2->cval,2,$1,$3); $$->line = $2->line; $$->column = $2->column; } 
        ;

Expr    
        : AssignExpr                                            { $$ = $1; } 
        | Expr COMMA AssignExpr                                 { $$ = create_node("Comma",$2->cval,2,$1,$3); $$->line = $2->line; $$->column = $2->column; } 
        ;

empty: {};

%%
