#include "functions.h"

void print_symbol_type(symbol_type type) {
  printf("%s",type->type);
  symbol_type params = type->parameters;
  if (params != NULL) {
    printf("(");
    printf("%s",params->type);
    params = params->parameters;
    while (params != NULL) {
      printf(",");
      printf("%s",params->type);
      params = params->parameters;
    }
    printf(")");
  }
}

void print_symbol(symbol symbol_aux) {
  printf("%s\t", symbol_aux->name);
  print_symbol_type(symbol_aux->type);
  printf("%s\n",(symbol_aux->param_flag == 1) ? "\tparam" : "");
}

void print_table(table aux_table) {
  
  if(aux_table->print_flag == 1) {
    if(strcmp(aux_table->name,"Global") == 0) 
      printf("===== %s Symbol Table =====\n", aux_table->name);
    else 
      printf("===== Function %s Symbol Table =====\n", aux_table->name);
    
    symbol symbol_aux = aux_table->first;
    while(symbol_aux!= NULL) {
      print_symbol(symbol_aux);
      symbol_aux = symbol_aux->next;
    }
    printf("\n");
  }
}

void print_tables() {
  table aux_table = symbols_table;
  while(aux_table != NULL) {
    print_table(aux_table);
    aux_table = aux_table->next;
  }
}

int compare_types(symbol_type type_1, symbol_type type_2) {
  symbol_type sym1 = type_1, sym2 = type_2;
  if(sym1 == NULL && sym2 == NULL){
    return 1;
  }
  else if(sym1 == NULL || sym2 == NULL){
    return 0;
  }
  while (sym1 != NULL || sym2 != NULL) {
    if(sym1 == NULL && sym2 == NULL){
      return 1;
    }
    else if(sym1 == NULL || sym2 == NULL){
      return 0;
    }
    if(strcmp(sym1->type, sym2->type)!=0){
      return 0;
    }
    sym1 = sym1->parameters;
    sym2 = sym2->parameters;
  }
  return 1;
}

int implicit_type_convertion(symbol_type expected, symbol_type given) {

  char types [5][100] = { "double", "int", "short", "char", "void" };
  int t1 = 0, t2 = 0;

  for (int i = 0; i < 6; i++) {
    if (strcmp(expected->type, types[i]) == 0) {
      t1 = i;
    }
    if (strcmp(given->type, types[i]) == 0) {
      t2 = i;
    }
  }

  if (t1 == 3 && (t2 == 1 || t2 == 2)){
    return 1;
  }
  else if (t2 == 4 || t1 == 4) {
    return 0;
  }
  else if (t1 == 2 && t2 == 1) {
    return 1;
  }
  else if (t1 > t2) {
    return 0;
  }
  return 1;
  
}

int call_type_convertion(symbol_type expected, symbol_type given) {

  char types [5][100] = { "double", "int", "short", "char" };
  int t1 = 0, t2 = 0;

  for (int i = 0; i < 5; i++) {
    if (strcmp(expected->type, types[i]) == 0) {
      t1 = i;
    }
    if (strcmp(given->type, types[i]) == 0) {
      t2 = i;
    }
  }

  if (t1 == 3 && (t2 == 1 || t2 == 2)){
    return 1;
  }
  else if (t1 == 2 && t2 == 1) {
    return 1;
  }
  else if (t1 > t2) {
    return 0;
  }
  return 1;
  
}


int report_param_errors(node aux_node) {

  node param_list = aux_node->son;
  int error = 0;

  while(param_list != NULL) {

    node var = param_list->son;
    var = var->brother;
    if (var != NULL) {
      for (node runner = aux_node->son; runner->son->brother != var; runner = runner->brother) {
        if (runner->son->brother != NULL) {
          if (strcmp(runner->son->brother->cval, var->cval) == 0) {
            print_symbol_error(var->cval, var->line, var->column, 2);
            error = 1;
            break;
          }
        }
      }

    }
    param_list = param_list->brother;
  }
  return error;
}

int param_has_error(node aux_node, node to_compare){
  int error = 0;
  if (to_compare != NULL) {
    for (node runner = aux_node->son; runner->son->brother != to_compare; runner = runner->brother) {
      if (runner->son->brother != NULL) {
        if (strcmp(runner->son->brother->cval, to_compare->cval) == 0) {
          return error = 1;
        }
      }
    }
  }
  return error;
}

// ============================= Error prints ===============================
void print_arguments_error(char *function,int n_arguments,int n_parameters,int line,int column){
  printf("Line %d, col %d: Wrong number of arguments to function %s (got %d, required %d)\n",line, column, function,n_arguments,n_parameters);
}

void print_void_error(int line, int column) {
  printf("Line %d, col %d: Invalid use of void type in declaration\n", line, column);
}

void print_unknown_symbol(char *symbol, int line, int column) {
  printf("Line %d, col %d: Unknown symbol %s\n",line, column, symbol);
}

void print_lvalue_error(int line, int column) {
  printf("Line %d, col %d: Lvalue required\n", line, column);
}

void error_operator_type(node aux_node, symbol_type t){
  printf("Line %d, col %d: Operator %s cannot be applied to type ", aux_node->line, aux_node->column, aux_node->cval);
  print_symbol_type(t);
  printf("\n");
}

void print_operand_error(node aux_node, symbol_type t1, symbol_type t2) {
  printf("Line %d, col %d: Operator %s cannot be applied to types ", aux_node->line, aux_node->column, aux_node->cval);
  print_symbol_type(t1);
  printf(", ");
  print_symbol_type(t2);
  printf("\n");
}

void print_conflicting_types(symbol_type t1, symbol_type t2, int line, int column) {
  printf("Line %d, col %d: Conflicting types (got ", line, column);
  print_symbol_type(t1);
  printf(", expected ");
  print_symbol_type(t2);
  printf(")\n");
}

void print_symbol_error (char * symbol, int line, int column, int flag) {
  
  switch (flag) {
    case (1):
      printf("Line %d, col %d: Symbol %s is not a function\n",line, column, symbol);
      break;
    case (2):
      printf("Line %d, col %d: Symbol %s already defined\n",line, column, symbol);
      break;
  }
}

// ============================= LLVM ===============================
//

char * is_global(char * name, char * function_name) {
  table t = search_table(function_name);

  for (symbol sym = t->first; sym != NULL; sym = sym->next) {
    if (strcmp(sym->name, name) == 0) {
      return name;
    }
  }
  return NULL;
}

