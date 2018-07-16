/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CHAR = 258,
    ELSE = 259,
    WHILE = 260,
    IF = 261,
    INT = 262,
    SHORT = 263,
    DOUBLE = 264,
    RETURN = 265,
    BITWISEAND = 266,
    BITWISEOR = 267,
    BITWISEXOR = 268,
    AND = 269,
    ASSIGN = 270,
    MUL = 271,
    COMMA = 272,
    DIV = 273,
    EQ = 274,
    GE = 275,
    GT = 276,
    LBRACE = 277,
    LE = 278,
    LPAR = 279,
    LT = 280,
    MINUS = 281,
    MOD = 282,
    NE = 283,
    NOT = 284,
    OR = 285,
    PLUS = 286,
    RBRACE = 287,
    RPAR = 288,
    SEMI = 289,
    ID = 290,
    CHRLIT = 291,
    REALLIT = 292,
    RESERVED = 293,
    INTLIT = 294,
    VOID = 295,
    IFS = 296
  };
#endif
/* Tokens.  */
#define CHAR 258
#define ELSE 259
#define WHILE 260
#define IF 261
#define INT 262
#define SHORT 263
#define DOUBLE 264
#define RETURN 265
#define BITWISEAND 266
#define BITWISEOR 267
#define BITWISEXOR 268
#define AND 269
#define ASSIGN 270
#define MUL 271
#define COMMA 272
#define DIV 273
#define EQ 274
#define GE 275
#define GT 276
#define LBRACE 277
#define LE 278
#define LPAR 279
#define LT 280
#define MINUS 281
#define MOD 282
#define NE 283
#define NOT 284
#define OR 285
#define PLUS 286
#define RBRACE 287
#define RPAR 288
#define SEMI 289
#define ID 290
#define CHRLIT 291
#define REALLIT 292
#define RESERVED 293
#define INTLIT 294
#define VOID 295
#define IFS 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 17 "uccompiler.y" /* yacc.c:1909  */

  struct token * tok;
  struct no * node;

#line 141 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
