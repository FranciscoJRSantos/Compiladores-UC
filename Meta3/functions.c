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
  free(symbol_aux->name);
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
