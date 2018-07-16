#ifndef CODE_GEN_H
#define CODE_GEN_H

#include "semantics.h"

void generate_program(node current_node);
void generate_code(node current_node);
void generate_global_code(node current_node);

#endif
