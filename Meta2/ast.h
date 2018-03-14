#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum { root_node, variable_node, functiondec_node, stm_node, operator_node, terminal_node, identifier_node } type_node;
typedef struct no* node;
typedef struct no {
    char * cval;
    char * stype;
    int depth;
    type_node type;
    node father;
    node son;
    node brother;
} no;

int yylex(void);
int yylex_destroy();
void yyerror(const char * s);
node create_node (type_node type, char* cval, char* stype);
void add_son(node father, node son);
void add_brother(node b1, node b2);
