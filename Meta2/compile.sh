#!/bin/sh
clear
##### Meta 1 #####
#flex uccompiler.l
#clang-3.8 -o uccompiler -Wall -Wno-unused-function lex.yy.c
##### Meta 2 #####
lex uccompiler.l && yacc -d -v --locations uccompiler.y && clang -o uccompiler -Wall -Wno-unused-function *.c
zip uccompiler.zip uccompiler.l uccompiler.y *.c ast.h y.tab.h
#valgrind --leak-check=full --show-leak-kinds=all ./uccompiler < first.uc -t 
