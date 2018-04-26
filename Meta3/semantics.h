#include "functions.h"

void create_predefined_functions(table aux_table);
symbol_type read_parameter_list(node aux_node, int flag);
void read_function_decl(node aux_node);
void read_declaration(node aux_node);
void read_tree(node current_node);
void read_function_def(node aux_node);
