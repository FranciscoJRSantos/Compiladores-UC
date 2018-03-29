#!/bin/sh
flex uccompiler.l
clang-3.8 -o uccompiler -Wall -Wno-unused-function lex.yy.c
zip uccompiler.zip uccompiler.l
