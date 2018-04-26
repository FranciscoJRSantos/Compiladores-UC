#include "symboltable.h"

typedef struct no* node;
typedef struct no {
    char * cval;
    char * label;
    int depth;
    node son;
    node brother;
    symbol_type type;

    int column;
    int line;
} no;

int yylex(void);
int yylex_destroy();
void yyerror(const char * s);
node create_node (char* label, char* cval, int n_sons, ...);
node add_brother(node b1, node b2);
void print_tree(node n, int depth);
