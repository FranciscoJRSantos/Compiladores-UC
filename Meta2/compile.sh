#!/bin/sh
flex uccompiler.l
yacc -d uccompiler.y
clang-3.8 -o uccompiler -Wall -Wno-unused-function y.tab.h lex.yy.c
#zip uccompiler.zip uccompiler.l uccompiler.y
