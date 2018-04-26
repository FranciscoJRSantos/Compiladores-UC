#include "symboltable.h"

// Cria uma tabela com o nome passado por parametro ou retorna uma caso ja exista com esse nome
table create_table(char* name) {

  table aux_table;
  // Caso já exista uma tabela com esse nome
  if(symbols_table != NULL) {
    for(aux_table = symbols_table; aux_table->next != NULL; aux_table = aux_table->next) {
      if(strcmp(aux_table->next->name,name) == 0) {
        return aux_table->next;
      }
    }
  }
  // Caso contrário aloca-se memoria e inicializa-se a nova tabela
  table new_table = (table) malloc(sizeof(struct table_));
  new_table->next = NULL;
  new_table->name = strdup(name);
  new_table->function = 0;
  new_table->print_flag = 0;
  new_table->first = NULL;
  if (symbols_table != NULL) {
    aux_table->next = new_table;
  }
  return new_table;
}

// Procura uma tabela com o nome passado por parametro
table search_table(char* name) {

    for(table aux_table = symbols_table; aux_table->next != NULL; aux_table = aux_table->next) {
      if (strcmp(aux_table->name,name) == 0) {
       return aux_table;
      }
    }
    return NULL;
}

// Adiciona um simbolo a uma tabela passada por parametro
void add_symbol(table tab, char* name, symbol_type symbol_type, int flag) {
  
  symbol new_symbol = (symbol) malloc(sizeof(struct symbol_));
  new_symbol->name = strdup(name);
  new_symbol->type = symbol_type;
  new_symbol->next = NULL;
  new_symbol->param_flag = flag;

  symbol last_symbol = tab->first;
  if (last_symbol != NULL) {
    while(last_symbol->next != NULL) {
      last_symbol = last_symbol->next;
    }
    last_symbol->next = new_symbol;
  }
  else {
    tab->first = new_symbol;
  }
}

// Procura um simbolo numa tabela passada por parametro
symbol search_symbol(table tab, char* name) {
  for(symbol aux = tab->first; aux != NULL; aux = aux->next) {
    if(strcmp(aux->name,name) == 0) {
      return aux;
    }
  }
  return NULL;
}

// Cria um tipo a um symbol type 
symbol_type new_type(char* name, symbol_type param) {
  symbol_type result = (symbol_type) malloc (sizeof(struct type_));

  char *name_type = strdup(name);
  for (char *aux = name_type; *aux; ++aux) 
    *aux = tolower(*aux);
  
  result->type = name_type;
  result->parameters = param;

  return result;
}
