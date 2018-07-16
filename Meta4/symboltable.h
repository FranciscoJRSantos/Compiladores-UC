#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

// Estrutura para o tipo de simbolo.
typedef struct type_{
  char* type;
  struct type_* parameters;
}*symbol_type;

// Estrutura para o simbolo em si.
typedef struct symbol_{
  struct symbol_ *next;
  char* name;
  symbol_type type;
  int param_flag;
}*symbol;

// Estrutura para a tabela
typedef struct table_{
  struct table_ *next;
  symbol first;
  char* name;
  int function;
  int print_flag;
}*table;

table symbols_table;
table current_table;

table create_table(char* name);
table search_table(char* name);
void add_symbol(table tab, char* name, symbol_type symbol_type, int flag);
symbol search_symbol(table tab, char* name);
symbol_type new_type(char* name, symbol_type param);
