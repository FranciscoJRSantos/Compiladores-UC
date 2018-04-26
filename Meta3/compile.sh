#!/bin/sh
clear
##### Meta 1 #####
#flex uccompiler.l
#clang-3.8 -o uccompiler -Wall -Wno-unused-function *.c

##### Meta 2 #####
# lex uccompiler.l
# yacc -d -v --locations uccompiler.y 
# clang-3.8 -o uccompiler -Wall -Wno-unused-function *.c
# zip uccompiler.zip uccompiler.l uccompiler.y ast.h y.tab.h ast.c y.tab.h y.tab.c
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./uccompiler < first.uc -t
# rm -rf uccompiler.dSYM

#### Meta 3 #####
lex uccompiler.l
yacc -d -v --locations uccompiler.y 
clang-3.8 -o uccompiler -Wall -Wno-unused-function *.c
zip uccompiler.zip uccompiler.l uccompiler.y y.tab.h y.tab.c ast.h y.tab.h ast.c symboltable.c symboltable.h semantics.c semantics.h functions.c functions.h
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./uccompiler < errors.uc -s
rm -rf uccompiler.dSYM
