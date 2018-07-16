#include "symboltable.h"
#include "y.tab.h"

typedef struct no* node;
typedef struct no {
    char * cval;
    char * label;
    int depth;
    node son;
    node brother;
    symbol_type type;
  
    int line;
    int column;
    int is_literal;

    int registry;
} no;

typedef struct token {
  char * cval;
  int line, column;
} token;

int yylex(void);
int yylex_destroy();
void yyerror(const char * s);

node create_node (char* label, char* cval, int n_sons, ...);
token * create_token (char * cval, int line, int column);
node add_brother(node b1, node b2);
void print_tree(node n, int depth);
