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
  int error = 0;
  
  if (flag != 2)
    report_param_errors(aux_node);
  while(param_list != NULL) {

    node var = param_list->son;
    char* lbl = strdup(var->label);
    var = var->brother;
    symbol_type type_n = new_type(lbl,NULL); 
    error = 0;


    if (flag != 2 && strcmp(lbl,"Void") == 0 && (list_type != NULL || param_list->brother != NULL || var != NULL)) {
      print_void_error(param_list->son->line,param_list->son->column);
      return NULL;
    }
    
    if (var != NULL) {
      error = param_has_error(aux_node, var);
    }
    
    // Create symbol type for function declaration in current table
    if (error == 0 && flag == 0 && var != NULL) {
      // Add function symbol to current table
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
  int error = 0;
  node definition = aux_node->son;
  char* type = strdup(definition->label);
  definition = definition->brother;
  symbol_type list_type = read_parameter_list(definition->brother,2);

  if (list_type == NULL) {
    return;
  }

  current_table = search_table(definition->cval);
  if (current_table == NULL) {
    current_table = create_table(definition->cval);
    current_table->function = 1;
  }
  else if (current_table->print_flag == 1) {
    print_symbol_error(definition->cval, definition->line, definition->column, 2);
    error = 1;
  }
  else {
    symbol_type test_def = new_type(type,list_type);
    symbol alr_def = search_symbol(symbols_table,definition->cval);

    if (compare_types(alr_def->type, test_def) == 0) {
      print_conflicting_types(test_def,alr_def->type,definition->line,definition->column);
      error = 1;
    }
  }
  if (error == 0) {
    current_table->print_flag = 1;
    symbol_type new = new_type(type,NULL);
    add_symbol(current_table,"return",new,0);
    list_type = read_parameter_list(definition->brother,0);
  }
  
  symbol sym1 = search_symbol(symbols_table,definition->cval);
  symbol_type new = new_type(type,list_type);
  if (sym1 == NULL && error == 0 && list_type != NULL) {
    add_symbol(symbols_table, definition->cval, new, 0);
  }
  else if (list_type != NULL){
    if(!compare_types(sym1->type, new) && error == 0) {
      print_conflicting_types(new,sym1->type,definition->line,definition->column);
      error = 1;
      if (current_table->print_flag == 1) {
        current_table->print_flag = 0;
      }
    }
  }
  else {
    current_table->print_flag = 0;
    error = 1;
  }
  if (error == 0)
    read_tree(definition->brother->brother);
}

/* Handling of function declaration */
void read_function_decl(node aux_node) {
  node declaration = aux_node->son;
  char* type = strdup(declaration->label);
  declaration = declaration->brother;

  current_table = search_table(declaration->cval);
  symbol_type list_type = read_parameter_list(declaration->brother,1);
  symbol_type new = new_type(type,list_type);
  if (current_table == NULL && list_type != NULL) {
    current_table = create_table(declaration->cval);
    current_table->function = 1;

    symbol sym1 = search_symbol(symbols_table,declaration->cval);
    if (sym1 == NULL) {
      list_type = read_parameter_list(declaration->brother,2);
      add_symbol(symbols_table,declaration->cval,new,0);
      current_table = symbols_table;
    }
    else {
      if(!compare_types(sym1->type, new)) {
        print_conflicting_types(new,sym1->type,declaration->line,declaration->column);
        current_table = symbols_table;
      }
    }
  }
  else if (current_table != NULL && list_type != NULL){
    symbol sym1 = search_symbol(symbols_table,declaration->cval);
      if(!compare_types(sym1->type, new)) {
        print_conflicting_types(new,sym1->type,declaration->line,declaration->column);
        current_table = symbols_table;
      }
  }
}

/* Handling standard declaration */
void read_declaration(node aux_node) {
  node child = aux_node->son;
  char* type = strdup(child->label);
  child = child->brother;
  int error = 0;
  symbol_type new = new_type(type,NULL);
  symbol sym1 = NULL;


  if (strcmp(type,"Void") == 0) {
    print_void_error(child->line, child->column);
    error = 1;
  }
  if (error == 0) {
    sym1 = search_symbol(current_table,child->cval);
  }
  if (sym1 == NULL && error == 0) {
    add_symbol(current_table,child->cval,new,0);
  }
  else if (sym1 != NULL){
    if(compare_types(sym1->type, new) && error == 0) {
      if (current_table != symbols_table) {
        print_symbol_error(child->cval, child->line, child->column, 2);
      }
    }
    else if (error == 0) {
        print_symbol_error(child->cval, child->line, child->column, 2);
    }
  }

  if (child->brother != NULL) { 
    read_tree(child->brother);
    if (implicit_type_convertion(new, child->brother->type) == 0) {
        print_conflicting_types(child->brother->type, new,child->line,child->column);
    }
  }

}

void annotate_expressions(node aux_node) {
  symbol_type type1 = aux_node->son->type;
  symbol_type type2 = aux_node->son->brother->type;

  // Types are null
  if (type1->type == NULL && type2->type == NULL) {
    aux_node->type = new_type("undef", NULL);
    print_operand_error(aux_node, type1, type2);
  }
  // Type One is not null 
  else if (type1->type != NULL && type2->type == NULL) {
    aux_node->type = new_type("undef", NULL);
    print_operand_error(aux_node, type1, type2);
  } 
  // Type Two is not null
  else if (type1->type == NULL && type2->type != NULL) {
    aux_node->type = new_type("undef", NULL);
    print_operand_error(aux_node, type1, type2);
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

int parse_call (node aux_node) {
  
  char * function_name = strdup(aux_node->son->cval);
  int is_function = (search_symbol(symbols_table, function_name) != NULL) != (search_symbol(current_table, function_name) != NULL);
  if (!is_function) {
    print_symbol_error(function_name, aux_node->son->line, aux_node->son->column,1);
    aux_node->type = aux_node->son->type;
    return 0;
  }
  int error = 0;
  aux_node->type = new_type(aux_node->son->type->type,NULL);
  int params_given = 0;
  int params_expected = 0;
  if (strcmp(aux_node->son->type->type,"undef") != 0) {
    if (aux_node->son->type->parameters != NULL) {
      node params = aux_node->son->brother;
      symbol_type expt = aux_node->son->type->parameters;
      while (params != NULL || expt != NULL) {
        if (params != NULL)
          params_given++;
        if (expt != NULL) 
          params_expected++;

        if (params != NULL && expt != NULL) {
          /* printf("%s | %s\n", params->type->type, expt->type); */
          if (strcmp(params->type->type, "undef") == 0 || strcmp(expt->type,"undef") == 0) {
            print_conflicting_types(params->type, new_type(expt->type, NULL), params->line, params->column);
            error = 1;
          }
          else if (((strcmp(params->type->type, "void") == 0)) && (strcmp(expt->type,"void") != 0)) {
            print_conflicting_types(params->type, new_type(expt->type, NULL), params->line, params->column);
            error = 1;
          }
          else if (!call_type_convertion(expt, params->type)) {
            print_conflicting_types(params->type, new_type(expt->type, NULL), params->line, params->column);
            error = 1;
          }
        }
        if (expt != NULL) 
          expt = expt->parameters;
        if (params != NULL)
          params = params->brother;
      }
      if (params_expected == 1 && strcmp(aux_node->son->type->parameters->type,"void") == 0 && params_given == 0) {
        return 1;
      }
      else if (params_expected == 1 && strcmp(aux_node->son->type->parameters->type,"void") == 0 && params_given != 0) {
        print_arguments_error(aux_node->son->cval, params_given,0, aux_node->son->line, aux_node->son->column);
        return 0;
      }
      if (params_given != params_expected) {
        print_arguments_error(aux_node->son->cval, params_given ,params_expected, aux_node->son->line, aux_node->son->column);
        return 0;
      }
    }
  }
  return 1;
}

int parse_math_expressions(node aux_node) {
  
  symbol_type type1 = aux_node->son->type;
  symbol_type type2 = aux_node->son->brother->type;
  int is_function1 = type1->parameters != NULL;
  int is_function2 = type2->parameters != NULL;
  if (is_function1 || is_function2){
    aux_node->type = new_type("undef", NULL);
    print_operand_error(aux_node, type1, type2);
    return 0;
  }
  else if (strcmp(aux_node->label,"Mod") == 0) {
    if (strcmp(type1->type, "undef") == 0 || strcmp(type2->type, "undef") == 0) {
      print_operand_error(aux_node, type1, type2);
      return 0;
    }
    if (strcmp(type1->type, "void") == 0 || strcmp(type2->type, "void") == 0) {
      print_operand_error(aux_node, type1, type2);
      return 0;
    }
    if (strcmp(type1->type, "double") == 0 || (strcmp(type2->type,"double") == 0)) {
      print_operand_error(aux_node, type1, type2);
      return 0;
    }
  }  
  else if (strcmp(type1->type,"undef") == 0 || strcmp(type2->type,"undef") == 0) {
    aux_node->type = new_type("undef", NULL);
    print_operand_error(aux_node, type1, type2);
    return 0;
  } 
  else if (strcmp(type1->type,"void") == 0 || strcmp(type2->type,"void") == 0) {
    aux_node->type = new_type("undef", NULL);
    print_operand_error(aux_node, type1, type2);
    return 0;
  }
  return 1;
}

int parse_comparison_expressions(node aux_node) {

  symbol_type type1 = aux_node->son->type;
  symbol_type type2 = aux_node->son->brother->type;
  int is_function1 = type1->parameters != NULL;
  int is_function2 = type2->parameters != NULL;
  if (is_function1 || is_function2){
    aux_node->type = new_type("int", NULL);
    print_operand_error(aux_node, type1, type2);
    return 0;
  }
  else if (strcmp(type1->type,"undef") == 0 || strcmp(type2->type,"undef") == 0) {
    aux_node->type = new_type("int", NULL);
    print_operand_error(aux_node, type1, type2);
    return 0;
  } else if (strcmp(type1->type,"void") == 0 || strcmp(type2->type,"void") == 0) {
    aux_node->type = new_type("int", NULL);
    print_operand_error(aux_node, type1, type2);
    return 0;
  }
  return 1;
}

int parse_unary_expression(node aux_node) {

  symbol_type type1 = aux_node->son->type;
  int is_function1 = type1->parameters != NULL;
 
  if (is_function1) {
    aux_node->type = new_type("undef", NULL);
    error_operator_type(aux_node,type1);
    return 0;
  }
  else if (strcmp(aux_node->label,"Not") == 0){
    if (strcmp(type1->type,"undef") == 0) {
      aux_node->type = new_type("int", NULL);
      error_operator_type(aux_node,type1);
      return 0;
    }
    if ((strcmp(type1->type,"double") == 0)) {
      aux_node->type = new_type("int", NULL);
      error_operator_type(aux_node,type1);
      return 0;
    }
    else if ((strcmp(type1->type,"void") == 0)) {
      aux_node->type = new_type("int", NULL);
      error_operator_type(aux_node,type1);
      return 0;
    }
  }
  else if (strcmp(type1->type,"undef") == 0) {
    aux_node->type = new_type("undef", NULL);
    error_operator_type(aux_node,type1);
    return 0;
  }
  else if (strcmp(type1->type,"void") == 0) {
    aux_node->type = new_type("undef", NULL);
    error_operator_type(aux_node,type1);
    return 0;
  }
  return 1;
}

int parse_bitwise_error (node aux_node) {

  symbol_type type1 = aux_node->son->type;
  symbol_type type2 = aux_node->son->brother->type;
  int is_function1 = type1->parameters != NULL;
  int is_function2 = type2->parameters != NULL;
  if (is_function1 || is_function2){
    aux_node->type = new_type("int", NULL);
    print_operand_error(aux_node, type1, type2);
    return 0;
  }
  else if (strcmp(type1->type,"undef") == 0 || strcmp(type2->type,"undef") == 0) {
    aux_node->type = new_type("int", NULL);
    print_operand_error(aux_node, type1, type2);
    return 0;
  }
  else if ((strcmp(type1->type,"double") == 0) || (strcmp(type2->type,"double") == 0)) {
    aux_node->type = new_type("int", NULL);
    print_operand_error(aux_node, type1, type2);
    return 0;
  } 
  else if (strcmp(type1->type,"void") == 0 || strcmp(type2->type,"void") == 0) {
    aux_node->type = new_type("int", NULL);
    print_operand_error(aux_node, type1, type2);
    return 0;
  }
  return 1;
}

void parse_and_or_errors(node aux_node) {

  symbol_type type1 = aux_node->son->type;
  symbol_type type2 = aux_node->son->brother->type;
  int is_function1 = type1->parameters != NULL;
  int is_function2 = type2->parameters != NULL;
  if (is_function1 || is_function2){
    aux_node->type = new_type("int", NULL);
    print_operand_error(aux_node, type1, type2);
  }
  else if (strcmp(type1->type,"undef") == 0 || strcmp(type2->type,"undef") == 0) {
    aux_node->type = new_type("int", NULL);
    print_operand_error(aux_node, type1, type2);
  }
  else if ((strcmp(type1->type,"double") == 0) || (strcmp(type2->type,"double") == 0)) {
    aux_node->type = new_type("int", NULL);
    print_operand_error(aux_node, type1, type2);
  } 
  else if (strcmp(type1->type,"void") == 0 || strcmp(type2->type,"void") == 0) {
    aux_node->type = new_type("int", NULL);
    print_operand_error(aux_node, type1, type2);
  }
}

int parse_comma_errors(node aux_node) {

  symbol_type type1 = aux_node->son->type;
  symbol_type type2 = aux_node->son->brother->type;
  int is_function1 = type1->parameters != NULL;
  int is_function2 = type2->parameters != NULL;
  if (is_function1 || is_function2){
    aux_node->type = new_type("undef", NULL);
    print_operand_error(aux_node, type1, type2);
    return 0;
  }
  else if (strcmp(type1->type,"undef") == 0 || strcmp(type2->type,"undef") == 0) {
    aux_node->type = new_type("undef", NULL);
    print_operand_error(aux_node, type1, type2);
    return 0;
  }
  return 1;
}

void parse_return(node aux_node) {
  symbol_type type1 = NULL;
  int is_function1 = 0;
  if (strcmp(current_table->first->type->type,"void") == 0) {
    if (aux_node->son->type != NULL) {
      type1 = aux_node->son->type;
      is_function1 = type1->parameters != NULL;
      if (is_function1) {
        print_conflicting_types(aux_node->son->type,current_table->first->type, aux_node->line, aux_node->column);
        return;
      }
      else if (strcmp(type1->type,"void") != 0) {
        print_conflicting_types(aux_node->son->type,current_table->first->type, aux_node->line, aux_node->column);
        return;
      }
    }
    else if (strcmp(aux_node->son->label,"Null") != 0) {
      print_conflicting_types(aux_node->son->type,current_table->first->type, aux_node->line, aux_node->column);
      return;
    }
  }
  else {
    if (strcmp(aux_node->son->label,"Null") == 0) {
      print_conflicting_types(new_type("void", NULL),current_table->first->type, aux_node->line, aux_node->column);
      return;
    }
    type1 = aux_node->son->type;
    is_function1 = type1->parameters != NULL;
    if (is_function1) {
      print_conflicting_types(aux_node->son->type,current_table->first->type, aux_node->line, aux_node->column);
      return;
    }
    else {
      if (!implicit_type_convertion(current_table->first->type, type1)) {
        print_conflicting_types(aux_node->son->type,current_table->first->type, aux_node->line, aux_node->column);
        return;
      }
    }
  }
}

void parse_if_while_errors(node aux_node) {
  symbol_type type1 = aux_node->son->type;
  int is_function1 = type1->parameters != NULL;

  if (is_function1) {
    print_conflicting_types(aux_node->son->type,new_type("int", NULL), aux_node->son->line, aux_node->son->column);
  }
  else if (strcmp(type1->type,"undef") == 0) {
    print_conflicting_types(aux_node->son->type,new_type("int", NULL), aux_node->son->line, aux_node->son->column);
  }
  else if (strcmp(type1->type,"void") == 0) {
    print_conflicting_types(aux_node->son->type,new_type("int", NULL), aux_node->son->line, aux_node->son->column);
  }
  else if (strcmp(type1->type,"double") == 0) {
    print_conflicting_types(aux_node->son->type,new_type("int", NULL), aux_node->son->line, aux_node->son->column);
  }
}

void parse_store (node aux_node) {

  symbol_type type1 = aux_node->son->type;
  int is_function1 = type1->parameters != NULL;

  if (is_function1) {
    print_operand_error(aux_node, aux_node->son->type, aux_node->son->brother->type);
    aux_node->type = new_type("undef",NULL);
    return;
  }

  if (strcmp(aux_node->son->label,"Id") == 0) {
    if (strcmp(aux_node->son->type->type,"undef") == 0 || strcmp(aux_node->son->brother->type->type, "undef") == 0){
      print_operand_error(aux_node, aux_node->son->type, aux_node->son->brother->type);
      aux_node->type = new_type(aux_node->son->type->type,NULL);
    }
    else if (strcmp(aux_node->son->type->type,"void") == 0 || strcmp(aux_node->son->brother->type->type, "void") == 0){
      print_operand_error(aux_node, aux_node->son->type, aux_node->son->brother->type);
      aux_node->type = new_type(aux_node->son->type->type,NULL);
    }
    else if (strcmp(aux_node->son->type->type,"double") == 0 != strcmp(aux_node->son->brother->type->type, "double") == 0){
      print_operand_error(aux_node, aux_node->son->type, aux_node->son->brother->type);
      aux_node->type = new_type(aux_node->son->type->type,NULL);
    }
    else {
      aux_node->type = new_type(aux_node->son->type->type,NULL);
    }
  }
  else {
    print_lvalue_error(aux_node->son->line, aux_node->son->column);
    aux_node->type = new_type(aux_node->son->type->type,NULL);
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
    if (parse_math_expressions(current_node))
      annotate_expressions(current_node);
  }
  else if((strcmp(current_node->label,"Add") == 0)) {
    read_tree(current_node->son);
    if (parse_math_expressions(current_node))
      annotate_expressions(current_node);
  }
  else if((strcmp(current_node->label,"Mul") == 0) || (strcmp(current_node->label,"Div") == 0) ) {
    read_tree(current_node->son);
    if (parse_math_expressions(current_node))
      annotate_expressions(current_node);
  }
  else if ((strcmp(current_node->label,"Mod") == 0)) {
    read_tree(current_node->son);
    parse_math_expressions(current_node);
    current_node->type = new_type("int",NULL);
  }
  else if((strcmp(current_node->label,"Eq") == 0) || (strcmp(current_node->label,"Ne") == 0) || (strcmp(current_node->label,"Lt") == 0) || (strcmp(current_node->label,"Gt") == 0) || (strcmp(current_node->label,"Le") == 0) || (strcmp(current_node->label,"Ge") == 0)) {
    read_tree(current_node->son);
    if (parse_comparison_expressions(current_node))
      current_node->type = new_type("int",NULL);
  }
  else if((strcmp(current_node->label,"BitWiseOr") == 0) || (strcmp(current_node->label,"BitWiseAnd") == 0) || (strcmp(current_node->label,"BitWiseXor") == 0)) {
    read_tree(current_node->son);
    parse_bitwise_error(current_node);
    current_node->type = new_type("int",NULL);
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
        print_unknown_symbol(current_node->cval, current_node->line, current_node->column);
        current_node->type = new_type("undef",NULL);
      }
    }
  }
  else if((strcmp(current_node->label,"Call") == 0)) {
    read_tree(current_node->son);
    if(parse_call(current_node))
      current_node->type = new_type(current_node->son->type->type,NULL);
  }
  else if((strcmp(current_node->label,"Store") == 0)) {
    read_tree(current_node->son);
    parse_store(current_node);
  }
  else if((strcmp(current_node->label,"Comma") == 0)) {
    read_tree(current_node->son);
    if (parse_comma_errors(current_node))
      current_node->type = new_type(current_node->son->brother->type->type,NULL);
  }
  else if((strcmp(current_node->label,"Minus") == 0) || (strcmp(current_node->label,"Plus") == 0)) {
    read_tree(current_node->son);
    if(parse_unary_expression(current_node))
      current_node->type = new_type(current_node->son->type->type,NULL);
  }
  else if((strcmp(current_node->label,"Not") == 0)) {
    read_tree(current_node->son);
    parse_unary_expression(current_node);
    current_node->type = new_type("int",NULL);
  }
  else if((strcmp(current_node->label,"And") == 0) || (strcmp(current_node->label,"Or") == 0)) {
    read_tree(current_node->son);
    parse_and_or_errors(current_node);
    current_node->type = new_type("int",NULL);
  }
  else if((strcmp(current_node->label,"If") == 0) || strcmp(current_node->label,"While") == 0) {
    read_tree(current_node->son);
    parse_if_while_errors(current_node);
  }
  else if((strcmp(current_node->label,"Return") == 0)) {
    read_tree(current_node->son);
    parse_return(current_node);
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
