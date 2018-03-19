#include "ast.h"

node create_node (char* label, char* cval, int n_sons, ...) {
    va_list args;
    va_start(args,n_sons);
    
    // Create new node
    node new_node = NULL;
    new_node = (node) malloc (sizeof(struct no));
    new_node->label = strdup(label);
    new_node->son = NULL;
    new_node->brother = NULL;
    if (cval == NULL) new_node->cval = cval;
    else new_node->cval = strdup(cval);

    
    node aux_son = NULL;
    for (int i=0; i < n_sons; i++) {
        node son = va_arg(args, node);

        // Dont count null children 
        if (son == NULL) continue;
        
        // Add son
        if(new_node->son == NULL) {
            new_node->son = son;
            aux_son = son;
        }
        else {
            add_brother(aux_son,son);
            aux_son = son;
        }
    }
    
    va_end(args);
    return new_node;
}

node add_brother(node b1, node b2) {
    if(b1 == NULL) return b2;
    if(b2 == NULL) return b1;

    node aux = b1;
    while(aux->brother != NULL) {
        aux = aux->brother;
    }

    aux->brother = b2;

    return b1;
}

void print_tree(node n, int depth) {
    for (int i = 0; i < depth; i++) 
        printf("..");
            
    if(n->cval != NULL)
        printf("%s(%s)",n->label,n->cval);
    else 
        printf("%s",n->label);
    printf("\n");
    
    if(n && n->son != NULL)
        print_tree(n->son,depth+1);
    
    if (n && n->brother != NULL)
        print_tree(n->brother,depth);
    
    if (n->cval != NULL)
        free(n->cval);
    if (n->label != NULL)
        free(n->label);
    if (n != NULL)
        free(n); 
}
