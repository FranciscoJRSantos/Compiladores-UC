#include "ast.h"

node create_node (type_node type, char* cval, char* stype) {
    node new = malloc(sizeof(no));

    new->stype = (char*) malloc (strlen(stype)*sizeof(char));
    new->cval = (char*) malloc (strlen(cval)*sizeof(char));
    strcpy(new->stype,stype);
    strcpy(new->cval,cval); 

    new->father = NULL;
    new->son = NULL;
    new->brother = NULL;

    return new;
}

void add_son(node father, node son) {
    
    if (son == NULL) {
        return;
    }
    father->son = son;
    father->depth++;
    son->father = father;
}

void add_brother(node b1, node b2) {
    if ( (b1 == NULL) || (b2 == NULL) ) {
        return;
    }

    node aux;
    aux = b1;

    while(aux->brother != NULL) {
        aux = aux->brother;
    }
    aux->brother=b2;
    
    if ( b1->father == NULL ) { 
        b2->father = b1->father;
        b2->father->depth++;
    }
}
