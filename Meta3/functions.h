#include "ast.h"

void print_symbol_type(symbol_type type);
void print_symbol(symbol symbol_aux);
void print_table(table aux_table);
void print_tables();

int compare_types(symbol_type type_1, symbol_type type_2);

// Define error prints
int report_param_errors(node aux_node);
void print_void_error(int line, int column);
void print_lvalue_error(int line, int column);
int param_has_error(node aux_node, node to_compare);
void error_operator_type(node aux_node, symbol_type t);
void print_unknown_symbol(char *symbol, int line, int column);
int call_type_convertion(symbol_type expected, symbol_type given);
int implicit_type_convertion(symbol_type expected, symbol_type given);
void print_operand_error(node aux_node, symbol_type t1, symbol_type t2);
void print_symbol_error (char * symbol, int line, int column, int flag);
void print_conflicting_types(symbol_type t1, symbol_type t2, int line, int column);
void print_arguments_error(char *function,int n_arguments,int n_parameters,int line,int col);
