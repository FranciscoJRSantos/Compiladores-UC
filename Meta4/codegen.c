#include "codegen.h"

char * current_function = NULL;
char * curr_function_type = NULL;
int temp_count = 1;
int conv_count = 1;

void create_global_declarations(node current_node) {
  
  symbol sym = symbols_table->first;


  while(sym != NULL) {
    if (sym->type->parameters == NULL) {
      if (strcmp(sym->type->type,"double") == 0) {
        printf("@global.var.%s = common global double 0.000000e+00, align 8\n", sym->name);
      }
      if (strcmp(sym->type->type,"int") == 0) {
        printf("@global.var.%s = common global i32 0, align 4\n", sym->name);
      }
      if (strcmp(sym->type->type,"short") == 0) {
        printf("@global.var.%s = common global i16 0, align 2\n", sym->name);

      }
      if (strcmp(sym->type->type,"char") == 0) {
        printf("@global.var.%s = common global i8 0, align 1\n", sym->name);
      }
    }
    sym = sym->next;
  }

}

void generate_program(node current_node) {


  printf("declare i32 @putchar(i8)\n");
  printf("declare i32 @getchar()\n");

  printf("define i32 @main(i32 %%argc, i8** %%argv) {\n");
  printf("\tcall void @function.declaration.v.main.s.(i32 %%argc, i8** %%argv)\n");
  printf("\tret i32 0\n");
  printf("}\n\n");

}

void generate_function_definition(node current_node) {
  node type = current_node->son;
  node name = type->brother;
  node params = name->brother->son;
  node body = name->brother->brother;

  current_function = strdup(name->cval);
  curr_function_type = strdup(type->label);
  
  char * aux_params= (char *) malloc(1024 * sizeof(char));

  int param_count = 0;
  while(params != NULL) {
    char * aux = (char *) malloc(1024 * sizeof(char));
    aux[0] = '\0';
    if (strcmp(params->son->label,"Double") == 0) {
      sprintf(aux, "double %%%s", params->son->brother->cval);
    }
    else if (strcmp(params->son->label,"Int") == 0) {
      sprintf(aux, "i32 %%%s", params->son->brother->cval); 
    }
    else if (strcmp(params->son->label,"Short") == 0) {
      sprintf(aux, "i16 %%%s", params->son->brother->cval); 
    }
    else if (strcmp(params->son->label,"Char") == 0) {
      sprintf(aux, "i8 %%%s", params->son->brother->cval); 
    }
    
    int i = 0;
    while(aux[i] != '\0') {
      aux_params[param_count] = aux[i];
      param_count++;
      i++;
    }
    
    free(aux);
    aux = NULL;

    if (params->brother != NULL) {
      aux_params[param_count] = ',';
      param_count++;
    }

    params = params->brother;
  }

  if (strcmp(type->label,"Void") == 0) {
    printf("define void @%s(%s) {\n",name->cval, aux_params);   
  }
  else if (strcmp(type->label,"Double") == 0) { 
    printf("define double @%s(%s) {\n",name->cval, aux_params);   
  }
  else if (strcmp(type->label,"Int") == 0) { 
    printf("define i32 @%s(%s) {\n",name->cval, aux_params);   
  }
  else if (strcmp(type->label,"Short") == 0) {
    printf("define i16 @%s(%s) {\n",name->cval, aux_params);   
  }
  else if (strcmp(type->label,"Char") == 0) {
    printf("define i8 @%s(%s) {\n",name->cval, aux_params);   
  }
  
  free(aux_params);
  generate_global_code(body);
}

void generate_declaration(node current_node) {
  if (strcmp(current_node->son->label, "Double") == 0) {
    printf("\t%%%s = alloca double, align 8\n", current_node->son->brother->cval);
  }
  else if (strcmp(current_node->son->label, "Int") == 0) {
    printf("\t%%%s = alloca i32, align 4\n", current_node->son->brother->cval); 
  }
  else if (strcmp(current_node->son->label, "Short") == 0) {
    printf("\t%%%s = alloca i16, align 2\n", current_node->son->brother->cval); 
  }
  else if (strcmp(current_node->son->label, "Char") == 0) {
    printf("\t%%%s = alloca i8, align 1\n", current_node->son->brother->cval); 
  }
  return;
}

void generate_global_code(node current_node) {
  
  if (current_node == NULL) {
    generate_program(current_node);
    return;
  }
  if(((strcmp(current_node->label,"Program") == 0))) {
    create_global_declarations(current_node);
    generate_program(current_node);
    node aux = current_node->son;
    while(aux != NULL) {
      generate_global_code(aux);
      aux = aux->brother;
    }
  }
  else if((strcmp(current_node->label,"FuncDefinition") == 0)) {
    generate_function_definition(current_node);
  }
  else if((strcmp(current_node->label,"FuncDeclaration") == 0)) {
    node aux = current_node->son;
    while(current_node != NULL) {
      generate_code(aux);
      aux = aux->brother;
    }
  }
  else if((strcmp(current_node->label,"FuncBody") == 0)) {
    node aux = current_node->son;
    while(aux != NULL) {
      generate_code(aux);
      aux = aux->brother;
    }

    if (curr_function_type != NULL && strcmp(curr_function_type,"Void") == 0) {
      printf("\tret void\n");
    }
    else if(curr_function_type != NULL) {
      if(strcmp(curr_function_type,"Double") == 0) {
        printf("\tret double 0.000000e+00\n");
      }
      else if(strcmp(curr_function_type,"Int") == 0) {
        printf("\tret i32 0\n");

      }
      else if(strcmp(curr_function_type,"Short") == 0) {
        printf("\tret i16 0\n");
      }
      else if(strcmp(curr_function_type,"Char") == 0) {
        printf("\tret i8 0\n"); 
      }
    }
    printf("}\n\n");
  } 
}

void generate_store(node current_node) {
  node aux = current_node->son;
  if (strcmp(aux->type->type,"double") == 0) {
    if (strcmp(aux->brother->type->type, "int") == 0) {
      printf("\t%%convertion.%d = sitofp i32 %%%d to double\n", conv_count, temp_count-1);
      if (is_global(aux->cval,current_function) != NULL) {
        printf("\tstore double %%convertion.%d, double* %%%s, align 8\n", conv_count, aux->cval); 
      }
      else {
        printf("\tstore double %%convertion.%d, double* @global.var.%s, align 8\n", conv_count, aux->cval); 
      }
      conv_count++;
    }
    else {
      if(is_global(aux->cval,current_function) != NULL){
        printf("\tstore double %%%d, double* %%%s, align 8\n", conv_count-1, aux->cval);                  
      }
      else{
        printf("\tstore double %%%d, double* @global.var.%s, align 8\n", conv_count-1, aux->cval);                                     
      }
    }
  }
  else if (strcmp(aux->type->type,"int") == 0) {
    if (is_global(aux->cval,current_function) != NULL) {
      printf("\tstore i32 %%%d, i32* %%%s, align 4\n", temp_count-1, aux->cval);
    }
    else {
      printf("\tstore i32 %%%d, i32* @global.var.%s, align 4\n", temp_count-1, aux->cval);
    }
  }
  else if (strcmp(aux->type->type,"char") == 0) {
    if (strcmp(aux->brother->type->type, "int") == 0) {
      printf("\t%%convertion.%d = sitofp i32 %%%d to i8\n", conv_count, temp_count-1);
      if (is_global(aux->cval,current_function) != NULL) {
        printf("\tstore i8 %%convertion.%d, i8* %%%s, align 1\n", conv_count, aux->cval); 
      }
      else {
        printf("\tstore i8 %%convertion.%d, i8* @global.var.%s, align 1\n", conv_count, aux->cval); 
      }
      conv_count++;

    }

  }
}

void generate_code(node current_node) {
  
  if (current_node == NULL) {
    return;
  }
  else if((strcmp(current_node->label,"Declaration") == 0)) {
    generate_declaration(current_node);
  }
  else if((strcmp(current_node->label,"Eq") == 0) || (strcmp(current_node->label,"Ne") == 0) || (strcmp(current_node->label,"Lt") == 0) || (strcmp(current_node->label,"Gt") == 0) 
          || (strcmp(current_node->label,"Le") == 0) || (strcmp(current_node->label,"Ge") == 0) || (strcmp(current_node->label,"And") == 0) || (strcmp(current_node->label,"Or") == 0)
          || (strcmp(current_node->label,"Sub") == 0) || (strcmp(current_node->label,"Add") == 0) || (strcmp(current_node->label,"Mul") == 0) || (strcmp(current_node->label,"Div") == 0) || (strcmp(current_node->label,"Mod") == 0)
          || (strcmp(current_node->label,"BitWiseOr") == 0) || (strcmp(current_node->label,"BitWiseAnd") == 0) || (strcmp(current_node->label,"BitWiseXor") == 0)) {

  }
  else if((strcmp(current_node->label,"IntLit") == 0)) { 
    printf("\t%%%d = add i32 0, %s\n", temp_count, current_node->cval);
    temp_count++;
  }
  else if((strcmp(current_node->label,"ChrLit") == 0)) {  
    printf("\t%%%d = add i32 0, %s\n", temp_count, current_node->cval);
    temp_count++;
  }
  else if((strcmp(current_node->label,"RealLit") == 0)) {
    printf("\t%%%d = fadd double 0.000000e+00, %.16E\n", temp_count, atof(current_node->cval));
    temp_count++;
  }
  else if((strcmp(current_node->label,"Id") == 0)) {  
    /* generate_id(current_node); */
  }
  else if((strcmp(current_node->label,"Call") == 0)) {
  }
  else if((strcmp(current_node->label,"Store") == 0)) {
    generate_store(current_node);
  }
  else if((strcmp(current_node->label,"Comma") == 0)) {
    node aux = current_node->son;
    while (aux != NULL) {
      generate_code(aux->son);
      aux = aux->brother;
    }
  }
  else if((strcmp(current_node->label,"Minus") == 0) || (strcmp(current_node->label,"Plus") == 0) || (strcmp(current_node->label,"Not") == 0)) {
  }
  else if((strcmp(current_node->label,"If") == 0) || strcmp(current_node->label,"While") == 0) {
  }
  else if((strcmp(current_node->label,"Return") == 0)) {
  }
}
