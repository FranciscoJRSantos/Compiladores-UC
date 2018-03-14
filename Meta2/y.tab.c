/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CHAR = 258,
     ELSE = 259,
     WHILE = 260,
     IF = 261,
     INT = 262,
     SHORT = 263,
     DOUBLE = 264,
     RETURN = 265,
     VOID = 266,
     BITWISEAND = 267,
     BITWISEOR = 268,
     BITWISEXOR = 269,
     AND = 270,
     ASSIGN = 271,
     MUL = 272,
     COMMA = 273,
     DIV = 274,
     EQ = 275,
     GE = 276,
     GT = 277,
     LBRACE = 278,
     LE = 279,
     LPAR = 280,
     LT = 281,
     MINUS = 282,
     MOD = 283,
     NE = 284,
     NOT = 285,
     OR = 286,
     PLUS = 287,
     RBRACE = 288,
     RPAR = 289,
     SEMI = 290,
     ID = 291,
     CHRLIT = 292,
     REALLIT = 293,
     RESERVED = 294,
     INTLIT = 295
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
#define VOID 266
#define BITWISEAND 267
#define BITWISEOR 268
#define BITWISEXOR 269
#define AND 270
#define ASSIGN 271
#define MUL 272
#define COMMA 273
#define DIV 274
#define EQ 275
#define GE 276
#define GT 277
#define LBRACE 278
#define LE 279
#define LPAR 280
#define LT 281
#define MINUS 282
#define MOD 283
#define NE 284
#define NOT 285
#define OR 286
#define PLUS 287
#define RBRACE 288
#define RPAR 289
#define SEMI 290
#define ID 291
#define CHRLIT 292
#define REALLIT 293
#define RESERVED 294
#define INTLIT 295




/* Copy the first part of user declarations.  */
#line 1 "uccompiler.y"

    #include <stdio.h>
    #include <stdlib.h> 
    #include <string.h>
    #include "ast.h"
    int flag = 0,print_tree = 0;

    node root;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "uccompiler.y"
{
int ival;
char * cval;
struct no * node;

}
/* Line 193 of yacc.c.  */
#line 194 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 207 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNRULES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    17,    21,
      23,    27,    29,    32,    34,    36,    38,    41,    44,    47,
      51,    54,    58,    61,    64,    66,    68,    72,    77,    81,
      86,    90,    93,    97,    99,   101,   103,   105,   107,   109,
     113,   115,   117,   119,   121,   123,   126,   130,   134,   136,
     139,   142,   148,   156,   162,   165,   169,   171,   175,   179,
     183,   185,   189,   193,   195,   199,   203,   207,   211,   213,
     217,   221,   223,   227,   229,   233,   235,   239,   241,   245,
     247,   251,   253,   257,   259
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    46,    -1,    36,    -1,    40,    -1,    37,
      -1,    38,    -1,    25,    72,    34,    -1,    25,     1,    34,
      -1,    45,    -1,    44,    18,    45,    -1,    54,    -1,    54,
      36,    -1,    47,    -1,    50,    -1,    52,    -1,    46,    47,
      -1,    46,    50,    -1,    46,    52,    -1,    54,    51,    48,
      -1,    23,    33,    -1,    23,    49,    33,    -1,    56,    49,
      -1,    52,    49,    -1,    56,    -1,    52,    -1,    54,    51,
      35,    -1,    36,    25,    44,    34,    -1,    54,    55,    35,
      -1,    54,    55,    53,    35,    -1,    54,     1,    35,    -1,
      18,    55,    -1,    53,    18,    55,    -1,     3,    -1,     7,
      -1,    11,    -1,     8,    -1,     9,    -1,    36,    -1,    36,
      16,    71,    -1,    57,    -1,    58,    -1,    59,    -1,    60,
      -1,    61,    -1,    23,    33,    -1,    23,    56,    33,    -1,
      23,     1,    33,    -1,    35,    -1,    72,    35,    -1,     1,
      35,    -1,     6,    25,    72,    34,    56,    -1,     6,    25,
      72,    34,    56,     4,    56,    -1,     5,    25,    72,    34,
      56,    -1,    10,    35,    -1,    10,    72,    35,    -1,    43,
      -1,    62,    17,    43,    -1,    62,    19,    43,    -1,    62,
      28,    43,    -1,    62,    -1,    63,    32,    62,    -1,    63,
      27,    62,    -1,    63,    -1,    64,    26,    63,    -1,    64,
      22,    63,    -1,    64,    24,    63,    -1,    64,    21,    63,
      -1,    64,    -1,    65,    20,    64,    -1,    65,    29,    64,
      -1,    65,    -1,    66,    12,    65,    -1,    66,    -1,    67,
      14,    66,    -1,    67,    -1,    68,    13,    67,    -1,    68,
      -1,    69,    15,    68,    -1,    69,    -1,    70,    31,    69,
      -1,    70,    -1,    43,    16,    71,    -1,    71,    -1,    72,
      18,    71,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    29,    29,    33,    34,    35,    36,    37,    38,    42,
      43,    47,    48,    52,    53,    54,    55,    56,    57,    61,
      65,    66,    70,    71,    72,    73,    77,    81,    85,    86,
      87,    91,    92,    96,    97,    98,    99,   100,   104,   105,
     109,   110,   111,   112,   113,   117,   118,   119,   123,   124,
     125,   129,   130,   134,   138,   139,   143,   144,   145,   146,
     150,   151,   152,   156,   157,   158,   159,   160,   164,   165,
     166,   170,   171,   175,   176,   180,   181,   184,   185,   189,
     190,   194,   195,   199,   200
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "ELSE", "WHILE", "IF", "INT",
  "SHORT", "DOUBLE", "RETURN", "VOID", "BITWISEAND", "BITWISEOR",
  "BITWISEXOR", "AND", "ASSIGN", "MUL", "COMMA", "DIV", "EQ", "GE", "GT",
  "LBRACE", "LE", "LPAR", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS",
  "RBRACE", "RPAR", "SEMI", "ID", "CHRLIT", "REALLIT", "RESERVED",
  "INTLIT", "$accept", "Program", "PrimaryExpr", "ParameterList",
  "ParameterDeclaration", "FunctionsAndDeclarations", "FunctionDefinition",
  "FunctionBody", "DeclarationsAndStatements", "FunctionDeclaration",
  "FunctionDeclarator", "Declaration", "DeclarationList", "TypeSpec",
  "Declarator", "Statement", "Compound_Stm", "Expr_Stm", "Select_Stm",
  "Iter_Stm", "Jump_Stm", "MultiplicativeExpr", "AdditiveExpr",
  "RelationalExpr", "EqualExpr", "AndExpr", "ExclusiveOrExpr",
  "InclusiveOrExpr", "LogicalAndExpr", "LogicalOrExpr", "AssignExpr",
  "Expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    43,    43,    43,    44,
      44,    45,    45,    46,    46,    46,    46,    46,    46,    47,
      48,    48,    49,    49,    49,    49,    50,    51,    52,    52,
      52,    53,    53,    54,    54,    54,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    57,    57,    57,    58,    58,
      58,    59,    59,    60,    61,    61,    62,    62,    62,    62,
      63,    63,    63,    64,    64,    64,    64,    64,    65,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     1,     2,     1,     1,     1,     2,     2,     2,     3,
       2,     3,     2,     2,     1,     1,     3,     4,     3,     4,
       3,     2,     3,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     2,     3,     3,     1,     2,
       2,     5,     7,     5,     2,     3,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    33,    34,    36,    37,    35,     0,     2,    13,    14,
      15,     0,     1,    16,    17,    18,     0,    38,     0,     0,
      30,     0,     0,     0,    26,    19,     0,    28,     0,     0,
       3,     5,     6,     4,    56,    60,    63,    68,    71,    73,
      75,    77,    79,    81,    39,     0,     9,    11,     0,     0,
       0,     0,     0,    20,    48,     0,     0,     0,     0,    40,
      41,    42,    43,    44,    83,     0,    38,    31,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    12,    50,     0,     0,    54,     0,     0,    45,     0,
      21,    23,    22,     0,    49,    32,     8,     7,    82,    57,
      58,    59,    56,    62,    61,    67,    65,    66,    64,    69,
      70,    72,    74,    76,    78,    80,    10,     0,     0,    55,
      47,    46,    84,     0,     0,    53,    51,     0,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,    34,    45,    46,     7,     8,    25,    55,     9,
      18,    56,    28,    57,    19,    58,    59,    60,    61,    62,
      63,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      64,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -52
static const yytype_int16 yypact[] =
{
     172,   -52,   -52,   -52,   -52,   -52,    20,   172,   -52,   -52,
     -52,     8,   -52,   -52,   -52,   -52,   -11,    82,    65,    21,
     -52,    94,   172,     5,   -52,   -52,    11,   -52,    30,   116,
     -52,   -52,   -52,   -52,    34,   121,    -9,   169,   108,    42,
      43,    72,    77,    90,   -52,   -13,   -52,    87,    78,   111,
     114,   149,    89,   -52,   -52,   122,    26,    16,    68,   -52,
     -52,   -52,   -52,   -52,   -52,    37,   127,   -52,    11,   -52,
     117,    62,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,   172,
     -52,   -52,   -52,    94,    94,   -52,    52,    25,   -52,   124,
     -52,   -52,   -52,    94,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   121,   121,    -9,    -9,    -9,    -9,   169,
     169,   108,    42,    43,    72,    77,   -52,    63,    84,   -52,
     -52,   -52,   -52,   110,   110,   -52,   178,   110,   -52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,    85,   -52,    99,   -52,   185,   -52,    86,   187,
     -52,    19,   -52,     0,   -22,   -51,   -52,   -52,   -52,   -52,
     -52,    33,   118,    95,    92,   115,   119,   120,   113,   -52,
     -19,   -26
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -26
static const yytype_int16 yytable[] =
{
      11,    99,    44,    71,    67,    89,    48,    11,     1,    16,
      49,    50,     2,     3,     4,    51,     5,    16,    76,    10,
      12,    90,    47,    77,    20,    96,    15,    48,    52,     1,
      29,    49,    50,     2,     3,     4,    51,     5,    53,    26,
      54,    30,    31,    32,    17,    33,   105,    66,    68,    52,
      72,    29,    66,   108,    84,   103,    27,    85,   130,   -25,
      92,    54,    30,    31,    32,    69,    33,   127,   128,    48,
     103,     1,   104,    49,    50,     2,     3,     4,    51,     5,
     103,   103,   135,   136,   132,    86,   138,   129,    23,    47,
      97,    52,    87,    29,    49,    50,   107,   133,    21,    51,
      24,   -24,   103,    54,    30,    31,    32,    22,    33,   113,
     114,    48,    52,    92,    29,    49,    50,    70,   134,    29,
      51,    88,    98,    91,    54,    30,    31,    32,    82,    33,
      30,    31,    32,    52,    33,    29,    93,    83,    73,    94,
      74,    29,   101,    21,   102,    54,    30,    31,    32,    75,
      33,   106,    30,    31,    32,   100,    33,   131,   109,   110,
     111,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,    29,     1,   121,   119,   120,     2,
       3,     4,   137,     5,    95,    30,    31,    32,   126,    33,
      78,    79,    13,    80,    14,    81,   115,   116,   117,   118,
     122,   125,     0,     0,     0,   123,     0,   124
};

static const yytype_int16 yycheck[] =
{
       0,    52,    21,    29,    26,    18,     1,     7,     3,     1,
       5,     6,     7,     8,     9,    10,    11,     1,    27,     0,
       0,    34,    22,    32,    35,    51,     7,     1,    23,     3,
      25,     5,     6,     7,     8,     9,    10,    11,    33,    18,
      35,    36,    37,    38,    36,    40,    68,    36,    18,    23,
      16,    25,    36,    72,    12,    18,    35,    14,    33,    33,
      35,    35,    36,    37,    38,    35,    40,    93,    94,     1,
      18,     3,    35,     5,     6,     7,     8,     9,    10,    11,
      18,    18,   133,   134,   103,    13,   137,    35,    23,    89,
       1,    23,    15,    25,     5,     6,    34,    34,    16,    10,
      35,    33,    18,    35,    36,    37,    38,    25,    40,    76,
      77,     1,    23,    35,    25,     5,     6,     1,    34,    25,
      10,    31,    33,    36,    35,    36,    37,    38,    20,    40,
      36,    37,    38,    23,    40,    25,    25,    29,    17,    25,
      19,    25,    56,    16,    58,    35,    36,    37,    38,    28,
      40,    34,    36,    37,    38,    33,    40,    33,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    25,     3,    84,    82,    83,     7,
       8,     9,     4,    11,    35,    36,    37,    38,    89,    40,
      21,    22,     7,    24,     7,    26,    78,    79,    80,    81,
      85,    88,    -1,    -1,    -1,    86,    -1,    87
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,     8,     9,    11,    42,    46,    47,    50,
      52,    54,     0,    47,    50,    52,     1,    36,    51,    55,
      35,    16,    25,    23,    35,    48,    18,    35,    53,    25,
      36,    37,    38,    40,    43,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    44,    45,    54,     1,     5,
       6,    10,    23,    33,    35,    49,    52,    54,    56,    57,
      58,    59,    60,    61,    71,    72,    36,    55,    18,    35,
       1,    72,    16,    17,    19,    28,    27,    32,    21,    22,
      24,    26,    20,    29,    12,    14,    13,    15,    31,    18,
      34,    36,    35,    25,    25,    35,    72,     1,    33,    56,
      33,    49,    49,    18,    35,    55,    34,    34,    71,    43,
      43,    43,    43,    62,    62,    63,    63,    63,    63,    64,
      64,    65,    66,    67,    68,    69,    45,    72,    72,    35,
      33,    33,    71,    34,    34,    56,    56,     4,    56
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 29 "uccompiler.y"
    { root = create_node(root_node,"","Program"); }
    break;

  case 3:
#line 33 "uccompiler.y"
    { (yyval.node) = create_node(identifier_node,(yyvsp[(1) - (1)].cval),"Id"); }
    break;

  case 4:
#line 34 "uccompiler.y"
    { (yyval.node) = create_node(terminal_node,(yyvsp[(1) - (1)].cval),"IntLit"); }
    break;

  case 5:
#line 35 "uccompiler.y"
    { (yyval.node) = create_node(terminal_node,(yyvsp[(1) - (1)].cval),"ChrLit"); }
    break;

  case 6:
#line 36 "uccompiler.y"
    { (yyval.node) = create_node(terminal_node,(yyvsp[(1) - (1)].cval),"RealLit"); }
    break;

  case 7:
#line 37 "uccompiler.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 8:
#line 38 "uccompiler.y"
    { (yyval.node) = NULL; flag=1; }
    break;

  case 9:
#line 42 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 11:
#line 47 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 12:
#line 48 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node);  }
    break;

  case 13:
#line 52 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 14:
#line 53 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 15:
#line 54 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 16:
#line 55 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 17:
#line 56 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 18:
#line 57 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 20:
#line 65 "uccompiler.y"
    { (yyval.node) = create_node(functiondec_node,"","FunctionBody"); }
    break;

  case 21:
#line 66 "uccompiler.y"
    { (yyval.node) = create_node(functiondec_node,"","FunctionBody"); add_son((yyval.node),(yyvsp[(2) - (3)].node)); }
    break;

  case 24:
#line 72 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 25:
#line 73 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 33:
#line 96 "uccompiler.y"
    { (yyval.node) = create_node(terminal_node,"","Char"); }
    break;

  case 34:
#line 97 "uccompiler.y"
    { (yyval.node) = create_node(terminal_node,"","Int"); }
    break;

  case 35:
#line 98 "uccompiler.y"
    { (yyval.node) = create_node(terminal_node,"","Void"); }
    break;

  case 36:
#line 99 "uccompiler.y"
    { (yyval.node) = create_node(terminal_node,"","Short"); }
    break;

  case 37:
#line 100 "uccompiler.y"
    { (yyval.node) = create_node(terminal_node,"","Double"); }
    break;

  case 38:
#line 104 "uccompiler.y"
    { (yyval.node) = create_node(identifier_node,"","Id");; }
    break;

  case 39:
#line 105 "uccompiler.y"
    { (yyval.node) = create_node(identifier_node,"","Id"); add_son((yyval.node),(yyvsp[(3) - (3)].node)); }
    break;

  case 40:
#line 109 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 41:
#line 110 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 42:
#line 111 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 43:
#line 112 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 44:
#line 113 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 51:
#line 129 "uccompiler.y"
    { (yyval.node) = create_node(stm_node,"","While"); add_son((yyval.node),(yyvsp[(3) - (5)].node)); if ((yyvsp[(5) - (5)].node) != NULL) { add_brother((yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node)); } }
    break;

  case 53:
#line 134 "uccompiler.y"
    { (yyval.node) = create_node(stm_node,"","While"); add_son((yyval.node),(yyvsp[(3) - (5)].node)); if ((yyvsp[(5) - (5)].node) != NULL) { add_brother((yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node)); } }
    break;

  case 54:
#line 138 "uccompiler.y"
    { (yyval.node) = create_node(stm_node,"","Return"); }
    break;

  case 55:
#line 139 "uccompiler.y"
    { (yyval.node) = create_node(stm_node,"","Return"); /* Add son node*/}
    break;

  case 56:
#line 143 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 57:
#line 144 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","Mul"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 58:
#line 145 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","Div"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 59:
#line 146 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","Mod"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 60:
#line 150 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 61:
#line 151 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","Plus"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 62:
#line 152 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","Minus"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 63:
#line 156 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 64:
#line 157 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","Lt"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 65:
#line 158 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","Gt"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 66:
#line 159 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","Le"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 67:
#line 160 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","Ge"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 68:
#line 164 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 69:
#line 165 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","Eq"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 70:
#line 166 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","Ne"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 71:
#line 170 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 72:
#line 171 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","BitWiseAnd"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 73:
#line 175 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 74:
#line 176 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","BitWiseXor"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 75:
#line 180 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 76:
#line 181 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","BitWiseOr"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 77:
#line 184 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 78:
#line 185 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","And"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 79:
#line 189 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 80:
#line 190 "uccompiler.y"
    { (yyval.node) = create_node(operator_node,"","Or"); add_son((yyval.node),(yyvsp[(1) - (3)].node)); add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 81:
#line 194 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 83:
#line 199 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;


/* Line 1267 of yacc.c.  */
#line 1864 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 203 "uccompiler.y"


int main(int argc, char * argv[])
{
    if (argc > 1)
    {
        if(strcmp(argv[1],"-l") == 0)
        {
            flag = 1;
            yylex();
        }
        if(strcmp(argv[1],"-t") == 0)
        {
            flag = 2;
            // print_tree = 1; 
            yyparse();
            yylex_destroy(); 
        }
    }
    return 0;
}

