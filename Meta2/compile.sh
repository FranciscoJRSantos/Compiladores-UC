#!/bin/sh
clear
flex uccompiler.l
yacc -d uccompiler.y
clang-3.8 -g -Wall -Wno-unused-function *.c
#zip uccompiler.zip uccompiler.l uccompiler.y
#valgrind --leak-check=yes ./a.out < teste.uc -t
