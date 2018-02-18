#!/bin/sh
flex $1
clang-3.8 -o $2 -Wall -Wno-unused-function lex.yy.c
zip uccompiler.zip uccompiler.l
