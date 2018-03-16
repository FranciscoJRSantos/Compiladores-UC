#!/bin/sh
clear
##### Meta 1 #####
#flex uccompiler.l
#clang-3.8 -o uccompiler -Wall -Wno-unused-function lex.yy.c
##### Meta 2 #####
flex uccompiler.l
yacc -d uccompiler.y
cc -o uccompiler -g -Wall -Wno-unused-function *.c
#zip uccompiler.zip uccompiler.l uccompiler.y
valgrind --leak-check=full --show-leak-kinds=all ./uccompiler < first.uc -t 
