#include "semantics.h"

/* Creating predefined functions putchar and getchar */
void create_predefined_functions(table aux_table) {
  symbol_type putchar_type = new_type ("int", new_type("int",NULL));
  symbol_type getchar_type = new_type ("int", new_type("void",NULL));

  add_symbol(aux_table,"putchar", putchar_type,0);
  create_table("putchar");
  add_symbol(aux_table,"getchar", getchar_type,0);
  create_table("getchar");
}

/* Handling function parameters */
symbol_type read_parameter_list(node aux_node, int flag) {

  // Parameter List
  node param_list = aux_node->son;
  symbol_type list_type = NULL;
  symbol_type current_type = NULL;
  while(param_list != NULL) {

    node var = param_list->son;
    char* lbl = strdup(var->label);
    var = var->brother;

    // Create symbol type for function declaration in global table
    symbol_type type_n = new_type(lbl,NULL); 
    if (flag == 0 && var != NULL) {
      // Add function symbol to global table
      add_symbol(current_table,var->cval,new_type(lbl,NULL),1); 
    }
    if (list_type == NULL) {
      list_type = type_n;
      current_type = list_type;
    }
    else {
      current_type->parameters = type_n;
      current_type = current_type->parameters;
    }
    param_list = param_list->brother;
  }
  return list_type;
}

/* Handling of function definition */
void read_function_def(node aux_node) {
  node definition = aux_node->son;
  char* type = strdup(definition->label);
  definition = definition->brother;

  current_table = search_table(definition->cval);
  if (current_table == NULL) {
    current_table = create_table(definition->cval);
    current_table->function = 1;
  }
  current_table->print_flag = 1;
  symbol_type type_new = new_type(type,NULL);
  add_symbol(current_table,"return",type_new,0);
  symbol_type list_type = read_parameter_list(definition->brother,0);
  if (search_symbol(symbols_table,definition->cval) == NULL) {
    add_symbol(symbols_table, definition->cval,new_type(type,list_type), 0);
  }
  read_tree(definition->brother->brother);
}

/* Handling of function declaration */
void read_function_decl(node aux_node) {
  node declaration = aux_node->son;
  char* type = strdup(declaration->label);
  declaration = declaration->brother;

  current_table = search_table(declaration->cval);
  if (current_table == NULL) {
    current_table = create_table(declaration->cval);
    current_table->function = 1;
    symbol_type list_type = read_parameter_list(declaration->brother,1);
    if (search_symbol(symbols_table,declaration->cval) == NULL) {
      add_symbol(symbols_table,declaration->cval,new_type(type,list_type),0);
    }
    current_table = symbols_table;
  }
}

/* Handling standard declaration */
void read_declaration(node aux_node) {
  node child = aux_node->son;
  char* type = strdup(child->label);
  child = child->brother;

  if (child->brother != NULL) { 
    read_tree(child->brother);
  }

  if (search_symbol(current_table,child->cval) == NULL) {
    add_symbol(current_table,child->cval,new_type(type,NULL),0);
  }
}

void annotate_expressions(node aux_node) {
  symbol_type type1 = aux_node->son->type;
  symbol_type type2 = aux_node->son->brother->type;

  // Types are null
  if (type1->type == NULL && type2->type == NULL) {
    aux_node->type = new_type("undef",NULL);
  }
  // Type One is not null 
  else if (type1->type != NULL && type2->type == NULL) {
    aux_node->type = new_type(type1->type,NULL);
  } 
  // Type Two is not null
  else if (type1->type == NULL && type2->type != NULL) {
    aux_node->type = new_type(type2->type,NULL);
  } 
  // Types are the same
  else if (strcmp(type1->type,type2->type) == 0) {
    aux_node->type = new_type(type1->type,NULL);
  }
  // One of the types is double
  else if((strcmp(type1->type,"double") == 0) || (strcmp(type2->type,"double") == 0)) {
    aux_node->type = new_type("double",NULL);
  }
  // One of the types is int 
  else if((strcmp(type1->type,"int") == 0) || (strcmp(type2->type,"int") == 0)) {
    aux_node->type = new_type("int",NULL);
  }
  // One of the types is short 
  else if((strcmp(type1->type,"short") == 0) || (strcmp(type2->type,"short") == 0)) {
    aux_node->type = new_type("short",NULL);
  }
  // One of the types is char
  else if((strcmp(type1->type,"char") == 0) || (strcmp(type2->type,"char") == 0)) {
    aux_node->type = new_type("char",NULL);
  }
}

/* Handling tree */
void read_tree(node current_node) {
  
  if(current_node == NULL){
    return;
  }
  else if(((strcmp(current_node->label,"Program") == 0) || (strcmp(current_node->label, "FuncBody") == 0))) {
    read_tree(current_node->son);
    return;
  }
  else if((strcmp(current_node->label,"FuncDefinition") == 0)) {
    read_function_def(current_node);
    current_table = symbols_table;
  }
  else if((strcmp(current_node->label,"FuncDeclaration") == 0)) {
    read_function_decl(current_node);;
  }
  else if((strcmp(current_node->label,"Declaration") == 0)) {
    read_declaration(current_node);
  }
  else if((strcmp(current_node->label,"Sub") == 0)) {
    read_tree(current_node->son);
    annotate_expressions(current_node);
  }
  else if((strcmp(current_node->label,"Add") == 0)) {
    read_tree(current_node->son);
    annotate_expressions(current_node);
  }
  else if((strcmp(current_node->label,"Mul") == 0) || (strcmp(current_node->label,"Div") == 0) ) {
    read_tree(current_node->son);
    annotate_expressions(current_node);
  }
  else if ((strcmp(current_node->label,"Mod") == 0)) {
    read_tree(current_node->son);
    current_node->type = new_type("int",NULL);
  }
  else if((strcmp(current_node->label,"Eq") == 0) || (strcmp(current_node->label,"Ne") == 0) || (strcmp(current_node->label,"Lt") == 0) || (strcmp(current_node->label,"Gt") == 0) || (strcmp(current_node->label,"Le") == 0) || (strcmp(current_node->label,"Ge") == 0)) {
    read_tree(current_node->son);
    current_node->type = new_type("int",NULL);
  }
  else if((strcmp(current_node->label,"BitWiseOr") == 0) || (strcmp(current_node->label,"BitWiseAnd") == 0) || (strcmp(current_node->label,"BitWiseXor") == 0)) {
    read_tree(current_node->son);
    annotate_expressions(current_node);
  }
  else if((strcmp(current_node->label,"IntLit") == 0)) {
    current_node->type = new_type("int",NULL);
  }
  else if((strcmp(current_node->label,"ChrLit") == 0)) {
    current_node->type = new_type("int",NULL);
  }
  else if((strcmp(current_node->label,"RealLit") == 0)) {
    current_node->type = new_type("double",NULL); 
  }
  else if((strcmp(current_node->label,"Id") == 0)) {  
    symbol symbol_aux = search_symbol(current_table,current_node->cval);
    if (symbol_aux != NULL) {
      current_node->type = symbol_aux->type;
    }
    else {
      symbol_aux = search_symbol(symbols_table, current_node->cval);
      if (symbol_aux != NULL) {
        current_node->type = symbol_aux->type;
      }
      else {
        current_node->type = new_type("undef",NULL);
      }
    }
  }
  else if((strcmp(current_node->label,"Call") == 0)) {
    read_tree(current_node->son);
    current_node->type = new_type(current_node->son->type->type,NULL);
  }
  else if((strcmp(current_node->label,"Store") == 0)) {
    read_tree(current_node->son);
    current_node->type = new_type(current_node->son->type->type,NULL);
  }
  else if((strcmp(current_node->label,"Comma") == 0)) {
    read_tree(current_node->son);
    current_node->type = new_type(current_node->son->brother->type->type,NULL);
  }
  else if((strcmp(current_node->label,"Minus") == 0) || (strcmp(current_node->label,"Plus") == 0)) {
    read_tree(current_node->son);
    current_node->type = new_type(current_node->son->type->type,NULL);
  }
  else if((strcmp(current_node->label,"Not") == 0)) {
    read_tree(current_node->son);
    current_node->type = new_type("int",NULL);
  }
  else if((strcmp(current_node->label,"And") == 0) || (strcmp(current_node->label,"Or") == 0)) {
    read_tree(current_node->son);
    current_node->type = new_type("int",NULL);
  }
  else{
    if (current_node->son != NULL) {
      read_tree(current_node->son);
    }
  }
  if (current_node->brother != NULL) {
    read_tree(current_node->brother);
  }
}
