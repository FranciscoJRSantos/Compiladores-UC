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
#define YYLSP_NEEDED 1



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




/* Copy the first part of user declarations.  */
#line 2 "uccompiler.y"

    #include <stdio.h>
    #include <stdlib.h> 
    #include <string.h>
    #include "ast.h"
    extern int flag,tree_flag;

    node root = NULL;
    node aux = NULL;

    extern int column, line;



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
#line 17 "uccompiler.y"
{
  struct token * tok;
  struct no * node;
}
/* Line 193 of yacc.c.  */
#line 197 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 222 "y.tab.c"

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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   358

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    14,    17,    20,
      24,    27,    31,    34,    37,    39,    41,    45,    50,    53,
      57,    59,    61,    64,    69,    72,    76,    78,    82,    84,
      86,    88,    90,    92,    94,    97,    99,   101,   103,   105,
     107,   109,   112,   116,   120,   123,   125,   128,   130,   132,
     138,   146,   152,   156,   158,   160,   162,   164,   168,   172,
     174,   178,   180,   185,   189,   194,   196,   199,   202,   205,
     207,   211,   215,   219,   221,   225,   229,   231,   235,   239,
     243,   247,   249,   253,   257,   259,   263,   265,   269,   271,
     275,   277,   281,   283,   287,   289,   293,   295,   299
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,    -1,    45,    -1,    48,    -1,    53,
      -1,    45,    44,    -1,    48,    44,    -1,    53,    44,    -1,
      56,    49,    46,    -1,    22,    32,    -1,    22,    47,    32,
      -1,    58,    47,    -1,    53,    47,    -1,    58,    -1,    53,
      -1,    56,    49,    34,    -1,    35,    24,    50,    33,    -1,
      52,    51,    -1,    51,    17,    52,    -1,    81,    -1,    56,
      -1,    56,    35,    -1,    56,    55,    54,    34,    -1,     1,
      34,    -1,    54,    17,    55,    -1,    81,    -1,    35,    15,
      79,    -1,    35,    -1,     3,    -1,     7,    -1,    40,    -1,
       8,    -1,     9,    -1,     1,    34,    -1,    58,    -1,    59,
      -1,    61,    -1,    63,    -1,    64,    -1,    65,    -1,    22,
      32,    -1,    22,    60,    32,    -1,    22,     1,    32,    -1,
      57,    60,    -1,    57,    -1,    62,    34,    -1,    81,    -1,
      80,    -1,     6,    24,    80,    33,    57,    -1,     6,    24,
      80,    33,    57,     4,    57,    -1,     5,    24,    80,    33,
      57,    -1,    10,    62,    34,    -1,    35,    -1,    39,    -1,
      36,    -1,    37,    -1,    24,    80,    33,    -1,    24,     1,
      33,    -1,    79,    -1,    67,    17,    79,    -1,    66,    -1,
      35,    24,    67,    33,    -1,    35,    24,    33,    -1,    35,
      24,     1,    33,    -1,    68,    -1,    31,    69,    -1,    26,
      69,    -1,    29,    69,    -1,    69,    -1,    70,    16,    69,
      -1,    70,    18,    69,    -1,    70,    27,    69,    -1,    70,
      -1,    71,    31,    70,    -1,    71,    26,    70,    -1,    71,
      -1,    72,    25,    71,    -1,    72,    21,    71,    -1,    72,
      23,    71,    -1,    72,    20,    71,    -1,    72,    -1,    73,
      19,    72,    -1,    73,    28,    72,    -1,    73,    -1,    74,
      11,    73,    -1,    74,    -1,    75,    13,    74,    -1,    75,
      -1,    76,    12,    75,    -1,    76,    -1,    77,    14,    76,
      -1,    77,    -1,    78,    30,    77,    -1,    78,    -1,    78,
      15,    79,    -1,    79,    -1,    80,    17,    79,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    31,    31,    36,    37,    38,    39,    40,    41,    45,
      49,    50,    54,    55,    56,    57,    61,    65,    75,    79,
      80,    84,    85,    98,   110,   114,   115,   119,   131,   144,
     145,   146,   147,   148,   152,   153,   156,   157,   158,   159,
     160,   164,   165,   166,   170,   171,   175,   179,   180,   184,
     192,   204,   214,   228,   229,   230,   231,   232,   233,   237,
     238,   242,   243,   253,   263,   268,   269,   270,   271,   275,
     276,   277,   278,   282,   283,   284,   288,   289,   290,   291,
     292,   296,   297,   298,   302,   303,   307,   308,   312,   313,
     317,   318,   322,   323,   327,   328,   332,   333,   336
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "ELSE", "WHILE", "IF", "INT",
  "SHORT", "DOUBLE", "RETURN", "BITWISEAND", "BITWISEOR", "BITWISEXOR",
  "AND", "ASSIGN", "MUL", "COMMA", "DIV", "EQ", "GE", "GT", "LBRACE", "LE",
  "LPAR", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS", "RBRACE",
  "RPAR", "SEMI", "ID", "CHRLIT", "REALLIT", "RESERVED", "INTLIT", "VOID",
  "IFS", "$accept", "Program", "FunctionsAndDeclarations",
  "FunctionDefinition", "FunctionBody", "DeclarationsAndStatements",
  "FunctionDeclaration", "FunctionDeclarator", "ParameterList",
  "ParameterDeclaration_", "ParameterDeclaration", "Declaration",
  "Declarator_", "Declarator", "TypeSpec", "StatementError", "Statement",
  "Compound_Stm", "BlockItemStm", "Expr_Stm", "OptionalExpr", "Select_Stm",
  "Iter_Stm", "Jump_Stm", "PrimaryExpr", "ArgExpr", "FunctionCallExpr",
  "UnaryExpr", "MultiplicativeExpr", "AdditiveExpr", "RelationalExpr",
  "EqualExpr", "AndExpr", "ExclusiveOrExpr", "InclusiveOrExpr",
  "LogicalAndExpr", "LogicalOrExpr", "AssignExpr", "Expr", "empty", 0
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
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    44,    44,    44,    45,
      46,    46,    47,    47,    47,    47,    48,    49,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    56,    56,    56,    57,    57,    58,    58,    58,    58,
      58,    59,    59,    59,    60,    60,    61,    62,    62,    63,
      63,    64,    65,    66,    66,    66,    66,    66,    66,    67,
      67,    68,    68,    68,    68,    69,    69,    69,    69,    70,
      70,    70,    70,    71,    71,    71,    72,    72,    72,    72,
      72,    73,    73,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    80,    81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     3,
       2,     3,     2,     2,     1,     1,     3,     4,     2,     3,
       1,     1,     2,     4,     2,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     2,     1,     2,     1,     1,     5,
       7,     5,     3,     1,     1,     1,     1,     3,     3,     1,
       3,     1,     4,     3,     4,     1,     2,     2,     2,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    29,    30,    32,    33,    31,     0,     2,     0,
       0,     0,     0,    24,     1,     6,     7,     8,    28,     0,
      98,     0,     0,     0,    16,     9,     0,    26,     0,     0,
       0,     0,    53,    55,    56,    54,    61,    65,    69,    73,
      76,    81,    84,    86,    88,    90,    92,    94,    27,     0,
      98,    21,     0,     0,    98,     0,    10,     0,     0,     0,
       0,    36,    37,     0,    38,    39,    40,    96,    48,    47,
       0,    23,     0,     0,    67,    68,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,    20,    22,     0,
       0,     0,     0,    41,     0,    35,     0,    11,    13,    28,
      12,    46,     0,    25,    58,    57,     0,    63,     0,    59,
      70,    71,    72,    75,    74,    80,    78,    79,    77,    82,
      83,    85,    87,    89,    91,    95,    93,     0,     0,     0,
      52,    43,    34,     0,    44,    42,    97,    64,     0,    62,
      19,     0,     0,    60,    51,    49,     0,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    25,    57,    10,    19,    49,    96,
      50,    11,    26,    20,    12,   104,   105,    61,   106,    62,
      63,    64,    65,    66,    36,   118,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    67,    68,    69
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -34
static const yytype_int16 yypact[] =
{
      40,   -33,   -34,   -34,   -34,   -34,   -34,    19,   -34,     6,
      17,    27,   -27,   -34,   -34,   -34,   -34,   -34,    50,    10,
     -34,   319,    55,    76,   -34,   -34,    16,   -34,   305,   319,
     319,   319,    -1,   -34,   -34,   -34,   -34,   -34,   -34,    74,
      11,    98,    59,    60,    56,    77,    79,    58,   -34,    70,
     -34,    71,    80,    85,   319,   200,   -34,    82,   123,    90,
     163,   -34,   -34,    86,   -34,   -34,   -34,   -34,   105,   -34,
      90,   -34,   111,   -12,   -34,   -34,   -34,   288,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   -34,   129,   -34,   -34,   319,
     319,   114,    62,   -34,   237,   -34,   121,   -34,   -34,   141,
     -34,   -34,   319,   -34,   -34,   -34,   128,   -34,    12,   -34,
     -34,   -34,   -34,    74,    74,    11,    11,    11,    11,    98,
      98,    59,    60,    56,    77,   -34,    79,    55,    22,    37,
     -34,   -34,   -34,   131,   -34,   -34,   -34,   -34,   319,   -34,
     -34,   274,   274,   -34,   -34,   172,   274,   -34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,   127,   -34,   -34,    39,   -34,   -34,   -34,   -34,
      30,    -7,   -34,   107,   -20,   -17,     8,   -34,    75,   -34,
     124,   -34,   -34,   -34,   -34,   -34,   -34,   -19,    69,    57,
      87,    91,    92,    93,    89,    94,   -34,   -21,   -24,     2
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -99
static const yytype_int16 yytable[] =
{
      48,    13,    51,    59,    73,   112,    -3,     1,    18,     2,
      74,    75,    76,     3,     4,     5,    58,    -4,     1,    14,
       2,   115,    27,    77,     3,     4,     5,    -5,     1,   148,
       2,    60,    23,    70,     3,     4,     5,    81,    59,   112,
      59,     1,    82,     2,    24,   149,     6,     3,     4,     5,
      71,    58,    97,    58,   112,   151,   119,     6,     2,   120,
     121,   122,     3,     4,     5,    21,    60,     6,    60,    90,
     152,    89,   135,    93,    22,   138,   139,     1,    87,     2,
       6,    52,    53,     3,     4,     5,    54,    88,    94,    91,
      78,   146,    79,    92,   141,     6,   142,   108,    55,   110,
      28,    80,    29,    95,    99,    30,    98,    31,    56,   100,
     -98,    32,    33,    34,   107,    35,     6,    51,    83,    84,
     111,    85,   112,    86,     1,   109,     2,   153,    52,    53,
       3,     4,     5,    54,   154,   155,    15,    16,    17,   157,
     125,   126,   127,   128,   114,    55,   137,    28,   140,    29,
     123,   124,    30,   145,    31,   -15,    21,   -98,    32,    33,
      34,   147,    35,     6,     1,   142,     2,   150,    52,    53,
       3,     4,     5,    54,   129,   130,   156,   113,   101,   144,
     131,   134,   132,     0,   133,    55,     0,    28,   136,    29,
       0,     0,    30,     0,    31,   -14,     0,   -98,    32,    33,
      34,   102,    35,     6,     0,    52,    53,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    28,     0,    29,     0,     0,    30,
       0,    31,   103,     0,   -98,    32,    33,    34,   143,    35,
       0,     0,    52,    53,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,    28,     0,    29,     0,     0,    30,     0,    31,   -45,
       0,   -98,    32,    33,    34,   143,    35,     0,     0,    52,
      53,     0,     0,     0,    54,     0,     0,     0,     0,   116,
       0,     0,     0,     0,     0,     0,    55,     0,    28,     0,
      29,     0,     0,    30,     0,    31,    72,     0,   -98,    32,
      33,    34,    28,    35,    29,     0,     0,    30,     0,    31,
       0,   117,     0,    32,    33,    34,     0,    35,     0,    28,
       0,    29,     0,     0,    30,     0,    31,     0,     0,     0,
      32,    33,    34,    28,    35,    29,     0,     0,    30,     0,
      31,     0,     0,     0,    32,    33,    34,     0,    35
};

static const yytype_int16 yycheck[] =
{
      21,    34,    22,    23,    28,    17,     0,     1,    35,     3,
      29,    30,    31,     7,     8,     9,    23,     0,     1,     0,
       3,    33,    20,    24,     7,     8,     9,     0,     1,    17,
       3,    23,    22,    17,     7,     8,     9,    26,    58,    17,
      60,     1,    31,     3,    34,    33,    40,     7,     8,     9,
      34,    58,    50,    60,    17,    33,    77,    40,     3,    78,
      79,    80,     7,     8,     9,    15,    58,    40,    60,    13,
      33,    11,    93,    15,    24,    99,   100,     1,    19,     3,
      40,     5,     6,     7,     8,     9,    10,    28,    30,    12,
      16,   112,    18,    14,    32,    40,    34,    58,    22,    60,
      24,    27,    26,    33,    24,    29,    35,    31,    32,    24,
      34,    35,    36,    37,    32,    39,    40,   137,    20,    21,
      34,    23,    17,    25,     1,    35,     3,   148,     5,     6,
       7,     8,     9,    10,   151,   152,     9,    10,    11,   156,
      83,    84,    85,    86,    33,    22,    17,    24,    34,    26,
      81,    82,    29,    32,    31,    32,    15,    34,    35,    36,
      37,    33,    39,    40,     1,    34,     3,   137,     5,     6,
       7,     8,     9,    10,    87,    88,     4,    70,    54,   104,
      89,    92,    90,    -1,    91,    22,    -1,    24,    94,    26,
      -1,    -1,    29,    -1,    31,    32,    -1,    34,    35,    36,
      37,     1,    39,    40,    -1,     5,     6,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    24,    -1,    26,    -1,    -1,    29,
      -1,    31,    32,    -1,    34,    35,    36,    37,     1,    39,
      -1,    -1,     5,     6,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    32,
      -1,    34,    35,    36,    37,     1,    39,    -1,    -1,     5,
       6,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    24,    -1,
      26,    -1,    -1,    29,    -1,    31,     1,    -1,    34,    35,
      36,    37,    24,    39,    26,    -1,    -1,    29,    -1,    31,
      -1,    33,    -1,    35,    36,    37,    -1,    39,    -1,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      35,    36,    37,    24,    39,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    35,    36,    37,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     7,     8,     9,    40,    43,    44,    45,
      48,    53,    56,    34,     0,    44,    44,    44,    35,    49,
      55,    15,    24,    22,    34,    46,    54,    81,    24,    26,
      29,    31,    35,    36,    37,    39,    66,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    50,
      52,    56,     5,     6,    10,    22,    32,    47,    53,    56,
      58,    59,    61,    62,    63,    64,    65,    79,    80,    81,
      17,    34,     1,    80,    69,    69,    69,    24,    16,    18,
      27,    26,    31,    20,    21,    23,    25,    19,    28,    11,
      13,    12,    14,    15,    30,    33,    51,    81,    35,    24,
      24,    62,     1,    32,    57,    58,    60,    32,    47,    35,
      47,    34,    17,    55,    33,    33,     1,    33,    67,    79,
      69,    69,    69,    70,    70,    71,    71,    71,    71,    72,
      72,    73,    74,    75,    76,    79,    77,    17,    80,    80,
      34,    32,    34,     1,    60,    32,    79,    33,    17,    33,
      52,    33,    33,    79,    57,    57,     4,    57
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



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

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

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
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 31 "uccompiler.y"
    { root = create_node("Program", NULL, 1, (yyvsp[(1) - (1)].node)); }
    break;

  case 3:
#line 36 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 4:
#line 37 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 5:
#line 38 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 6:
#line 39 "uccompiler.y"
    { (yyval.node) = add_brother((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); }
    break;

  case 7:
#line 40 "uccompiler.y"
    { (yyval.node) = add_brother((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); }
    break;

  case 8:
#line 41 "uccompiler.y"
    { (yyval.node) = add_brother((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); }
    break;

  case 9:
#line 45 "uccompiler.y"
    { (yyval.node) = create_node("FuncDefinition",NULL,3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 10:
#line 49 "uccompiler.y"
    { (yyval.node) = create_node("FuncBody",NULL,0); }
    break;

  case 11:
#line 50 "uccompiler.y"
    { (yyval.node) = create_node("FuncBody",NULL,1,(yyvsp[(2) - (3)].node)); }
    break;

  case 12:
#line 54 "uccompiler.y"
    { (yyval.node) = add_brother((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); }
    break;

  case 13:
#line 55 "uccompiler.y"
    { (yyval.node) = add_brother((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); }
    break;

  case 14:
#line 56 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 15:
#line 57 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 16:
#line 61 "uccompiler.y"
    { (yyval.node) = create_node("FuncDeclaration",NULL,2,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node)); }
    break;

  case 17:
#line 65 "uccompiler.y"
    { 
          (yyval.node) = add_brother(create_node("Id",(yyvsp[(1) - (4)].tok)->cval,0),(yyvsp[(3) - (4)].node)); 
          (yyval.node)->line = (yyvsp[(1) - (4)].tok)->line; 
          (yyval.node)->column = (yyvsp[(1) - (4)].tok)->column; 
          (yyval.node)->is_literal = 1;
          free((yyvsp[(1) - (4)].tok)); 
        }
    break;

  case 18:
#line 75 "uccompiler.y"
    { (yyval.node) = create_node("ParamList",NULL,2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); }
    break;

  case 19:
#line 79 "uccompiler.y"
    { (yyval.node) = add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 20:
#line 80 "uccompiler.y"
    { (yyval.node) = NULL; }
    break;

  case 21:
#line 84 "uccompiler.y"
    { (yyval.node) = create_node("ParamDeclaration",NULL,1,(yyvsp[(1) - (1)].node)); }
    break;

  case 22:
#line 85 "uccompiler.y"
    { 
          aux = create_node("Id",(yyvsp[(2) - (2)].tok)->cval,0); 
          aux->line = (yyvsp[(2) - (2)].tok)->line;
          aux->column = (yyvsp[(2) - (2)].tok)->column;
          aux->is_literal = 1;
          (yyval.node) = create_node("ParamDeclaration",NULL,2,(yyvsp[(1) - (2)].node),aux); 
          (yyval.node)->line = (yyvsp[(2) - (2)].tok)->line; 
          (yyval.node)->column = (yyvsp[(2) - (2)].tok)->column; 
          free((yyvsp[(2) - (2)].tok)); 
        }
    break;

  case 23:
#line 98 "uccompiler.y"
    {
            (yyvsp[(2) - (4)].node) = add_brother((yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node)); 
            aux = (yyvsp[(2) - (4)].node); 
            while(aux != NULL) { 
                aux->son = add_brother(create_node((yyvsp[(1) - (4)].node)->label,NULL,0),aux->son); 
                aux = aux->brother; 
            }
            (yyval.node) = (yyvsp[(2) - (4)].node);
            free((yyvsp[(1) - (4)].node)->label); 
            free((yyvsp[(1) - (4)].node)->cval); 
            free((yyvsp[(1) - (4)].node)); 
        }
    break;

  case 24:
#line 110 "uccompiler.y"
    { (yyval.node) = NULL; tree_flag = 0; }
    break;

  case 25:
#line 114 "uccompiler.y"
    { (yyval.node) = add_brother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 26:
#line 115 "uccompiler.y"
    { (yyval.node) = NULL; }
    break;

  case 27:
#line 119 "uccompiler.y"
    { 
          aux = create_node("Id",(yyvsp[(1) - (3)].tok)->cval,0); 
          aux->line = (yyvsp[(1) - (3)].tok)->line;
          aux->column = (yyvsp[(1) - (3)].tok)->column;
          aux->is_literal = 1;
          if((yyvsp[(3) - (3)].node) != NULL) {  
            (yyval.node) = create_node("Declaration",NULL,2,aux,(yyvsp[(3) - (3)].node)); 
            (yyval.node)->line = aux->line;
            (yyval.node)->column = aux->column;
          } 
          free((yyvsp[(1) - (3)].tok)); 
        }
    break;

  case 28:
#line 131 "uccompiler.y"
    { 
          aux = create_node("Id",(yyvsp[(1) - (1)].tok)->cval,0); 
          aux->line = (yyvsp[(1) - (1)].tok)->line;
          aux->column = (yyvsp[(1) - (1)].tok)->column;
          aux->is_literal = 1;
          (yyval.node) = create_node("Declaration",NULL,1,aux); 
          (yyval.node)->line = aux->line;
          (yyval.node)->column = aux->column;
          free((yyvsp[(1) - (1)].tok)); 
        }
    break;

  case 29:
#line 144 "uccompiler.y"
    { (yyval.node) = create_node("Char", NULL, 0); (yyval.node)->line = (yyvsp[(1) - (1)].tok)->line; (yyval.node)->column = (yyvsp[(1) - (1)].tok)->column; }
    break;

  case 30:
#line 145 "uccompiler.y"
    { (yyval.node) = create_node("Int", NULL, 0); (yyval.node)->line = (yyvsp[(1) - (1)].tok)->line; (yyval.node)->column = (yyvsp[(1) - (1)].tok)->column; }
    break;

  case 31:
#line 146 "uccompiler.y"
    { (yyval.node) = create_node("Void", NULL, 0); (yyval.node)->line = (yyvsp[(1) - (1)].tok)->line; (yyval.node)->column = (yyvsp[(1) - (1)].tok)->column; }
    break;

  case 32:
#line 147 "uccompiler.y"
    { (yyval.node) = create_node("Short", NULL, 0); (yyval.node)->line = (yyvsp[(1) - (1)].tok)->line; (yyval.node)->column = (yyvsp[(1) - (1)].tok)->column; }
    break;

  case 33:
#line 148 "uccompiler.y"
    { (yyval.node) = create_node("Double", NULL, 0); (yyval.node)->line = (yyvsp[(1) - (1)].tok)->line; (yyval.node)->column = (yyvsp[(1) - (1)].tok)->column; }
    break;

  case 34:
#line 152 "uccompiler.y"
    { (yyval.node) = NULL; tree_flag = 0; }
    break;

  case 35:
#line 153 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 36:
#line 156 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 37:
#line 157 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 38:
#line 158 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 39:
#line 159 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 40:
#line 160 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 41:
#line 164 "uccompiler.y"
    { (yyval.node) = NULL; }
    break;

  case 42:
#line 165 "uccompiler.y"
    { if((yyvsp[(2) - (3)].node) != NULL && (yyvsp[(2) - (3)].node)->brother != NULL) { (yyval.node) = create_node("StatList", NULL, 1, (yyvsp[(2) - (3)].node)); } else (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 43:
#line 166 "uccompiler.y"
    { (yyval.node) = NULL; tree_flag = 0; }
    break;

  case 44:
#line 170 "uccompiler.y"
    { (yyval.node) = add_brother((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 45:
#line 171 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 46:
#line 175 "uccompiler.y"
    { if (strcmp((yyvsp[(1) - (2)].node)->label, "Null") == 0) { (yyval.node) = NULL; free((yyvsp[(1) - (2)].node)); } else (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 47:
#line 179 "uccompiler.y"
    { (yyval.node) = create_node("Null", NULL, 0); }
    break;

  case 48:
#line 180 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 49:
#line 184 "uccompiler.y"
    { 
            if((yyvsp[(3) - (5)].node) == NULL) 
                (yyvsp[(3) - (5)].node) = create_node("Null", NULL, 0); 
            if((yyvsp[(5) - (5)].node) == NULL) 
                (yyvsp[(5) - (5)].node) = create_node("Null", NULL, 0); 
            aux = create_node("Null", NULL, 0);
            (yyval.node) = create_node("If", NULL, 3, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), aux);
        }
    break;

  case 50:
#line 192 "uccompiler.y"
    { 
            if ((yyvsp[(3) - (7)].node) == NULL)
                (yyvsp[(3) - (7)].node) = create_node("Null", NULL, 0); 
            if((yyvsp[(5) - (7)].node) == NULL) 
                (yyvsp[(5) - (7)].node) = create_node("Null", NULL, 0); 
            if((yyvsp[(7) - (7)].node) == NULL) 
                (yyvsp[(7) - (7)].node) = create_node("Null", NULL, 0); 
            (yyval.node) = create_node("If", NULL, 3, (yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));
        }
    break;

  case 51:
#line 204 "uccompiler.y"
    { 
            if ((yyvsp[(3) - (5)].node) == NULL)
                (yyvsp[(3) - (5)].node) = create_node("Null", NULL, 0);
            if ((yyvsp[(5) - (5)].node) == NULL) 
                (yyvsp[(5) - (5)].node) = create_node("Null", NULL, 0); 
            (yyval.node) = create_node("While", NULL, 2, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)); 
        }
    break;

  case 52:
#line 214 "uccompiler.y"
    { 
          (yyval.node) = create_node("Return", NULL, 1, (yyvsp[(2) - (3)].node)); 
          if (strcmp((yyvsp[(2) - (3)].node)->label,"Null") != 0) { 
            (yyval.node)->line = (yyvsp[(2) - (3)].node)->line; 
            (yyval.node)->column = (yyvsp[(2) - (3)].node)->column; 
          } 
          else { 
            (yyval.node)->line = (yyvsp[(1) - (3)].tok)->line;
            (yyval.node)->column = (yyvsp[(1) - (3)].tok)->column;
          }
        }
    break;

  case 53:
#line 228 "uccompiler.y"
    { (yyval.node) = create_node("Id",(yyvsp[(1) - (1)].tok)->cval,0); (yyval.node)->line = (yyvsp[(1) - (1)].tok)->line; (yyval.node)->column = (yyvsp[(1) - (1)].tok)->column; (yyval.node)->is_literal = 1; free((yyvsp[(1) - (1)].tok)); }
    break;

  case 54:
#line 229 "uccompiler.y"
    { (yyval.node) = create_node("IntLit",(yyvsp[(1) - (1)].tok)->cval,0); (yyval.node)->line = (yyvsp[(1) - (1)].tok)->line; (yyval.node)->column = (yyvsp[(1) - (1)].tok)->column; (yyval.node)->is_literal = 1; free((yyvsp[(1) - (1)].tok)); }
    break;

  case 55:
#line 230 "uccompiler.y"
    { (yyval.node) = create_node("ChrLit",(yyvsp[(1) - (1)].tok)->cval,0); (yyval.node)->line = (yyvsp[(1) - (1)].tok)->line; (yyval.node)->column = (yyvsp[(1) - (1)].tok)->column; (yyval.node)->is_literal = 1; free((yyvsp[(1) - (1)].tok)); }
    break;

  case 56:
#line 231 "uccompiler.y"
    { (yyval.node) = create_node("RealLit",(yyvsp[(1) - (1)].tok)->cval,0); (yyval.node)->line = (yyvsp[(1) - (1)].tok)->line; (yyval.node)->column = (yyvsp[(1) - (1)].tok)->column; (yyval.node)->is_literal = 1; free((yyvsp[(1) - (1)].tok)); }
    break;

  case 57:
#line 232 "uccompiler.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 58:
#line 233 "uccompiler.y"
    { (yyval.node) = create_node("Null", NULL, 0); }
    break;

  case 59:
#line 237 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 60:
#line 238 "uccompiler.y"
    { (yyval.node) = add_brother((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 61:
#line 242 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 62:
#line 243 "uccompiler.y"
    { 
          aux = create_node("Id", (yyvsp[(1) - (4)].tok)->cval, 0); 
          aux->line = (yyvsp[(1) - (4)].tok)->line;
          aux->column = (yyvsp[(1) - (4)].tok)->column;
          aux->is_literal = 1;
          (yyval.node) = create_node("Call", NULL, 2, aux, (yyvsp[(3) - (4)].node)); 
          (yyval.node)->line = (yyvsp[(1) - (4)].tok)->line;
          (yyval.node)->column = (yyvsp[(1) - (4)].tok)->column;
          free((yyvsp[(1) - (4)].tok)); 
        }
    break;

  case 63:
#line 253 "uccompiler.y"
    { 
          aux = create_node("Id", (yyvsp[(1) - (3)].tok)->cval, 0); 
          aux->line = (yyvsp[(1) - (3)].tok)->line;
          aux->column = (yyvsp[(1) - (3)].tok)->column;
          aux->is_literal = 1;
          (yyval.node) = create_node("Call", NULL, 1, aux); 
          (yyval.node)->line = (yyvsp[(1) - (3)].tok)->line;
          (yyval.node)->column = (yyvsp[(1) - (3)].tok)->column;
          free((yyvsp[(1) - (3)].tok));
        }
    break;

  case 64:
#line 263 "uccompiler.y"
    { (yyval.node) = create_node("Null", NULL, 0); free((yyvsp[(1) - (4)].tok)); }
    break;

  case 65:
#line 268 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 66:
#line 269 "uccompiler.y"
    { (yyval.node) = create_node("Plus",(yyvsp[(1) - (2)].tok)->cval,1,(yyvsp[(2) - (2)].node)); (yyval.node)->line = (yyvsp[(1) - (2)].tok)->line; (yyval.node)->column = (yyvsp[(1) - (2)].tok)->column; }
    break;

  case 67:
#line 270 "uccompiler.y"
    { (yyval.node) = create_node("Minus",(yyvsp[(1) - (2)].tok)->cval,1,(yyvsp[(2) - (2)].node)); (yyval.node)->line = (yyvsp[(1) - (2)].tok)->line; (yyval.node)->column = (yyvsp[(1) - (2)].tok)->column; }
    break;

  case 68:
#line 271 "uccompiler.y"
    { (yyval.node) = create_node("Not",(yyvsp[(1) - (2)].tok)->cval,1,(yyvsp[(2) - (2)].node)); (yyval.node)->line = (yyvsp[(1) - (2)].tok)->line; (yyval.node)->column = (yyvsp[(1) - (2)].tok)->column; }
    break;

  case 69:
#line 275 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 70:
#line 276 "uccompiler.y"
    { (yyval.node) = create_node("Mul", (yyvsp[(2) - (3)].tok)->cval, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 71:
#line 277 "uccompiler.y"
    { (yyval.node) = create_node("Div", (yyvsp[(2) - (3)].tok)->cval, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 72:
#line 278 "uccompiler.y"
    { (yyval.node) = create_node("Mod", (yyvsp[(2) - (3)].tok)->cval, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 73:
#line 282 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 74:
#line 283 "uccompiler.y"
    { (yyval.node) = create_node("Add", (yyvsp[(2) - (3)].tok)->cval, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column;  }
    break;

  case 75:
#line 284 "uccompiler.y"
    { (yyval.node) = create_node("Sub", (yyvsp[(2) - (3)].tok)->cval, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column;  }
    break;

  case 76:
#line 288 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 77:
#line 289 "uccompiler.y"
    { (yyval.node) = create_node("Lt", (yyvsp[(2) - (3)].tok)->cval, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 78:
#line 290 "uccompiler.y"
    { (yyval.node) = create_node("Gt", (yyvsp[(2) - (3)].tok)->cval, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 79:
#line 291 "uccompiler.y"
    { (yyval.node) = create_node("Le", (yyvsp[(2) - (3)].tok)->cval, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 80:
#line 292 "uccompiler.y"
    { (yyval.node) = create_node("Ge", (yyvsp[(2) - (3)].tok)->cval, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 81:
#line 296 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 82:
#line 297 "uccompiler.y"
    { (yyval.node) = create_node("Eq", (yyvsp[(2) - (3)].tok)->cval, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 83:
#line 298 "uccompiler.y"
    { (yyval.node) = create_node("Ne", (yyvsp[(2) - (3)].tok)->cval, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 84:
#line 302 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 85:
#line 303 "uccompiler.y"
    { (yyval.node) = create_node("BitWiseAnd", (yyvsp[(2) - (3)].tok)->cval,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 86:
#line 307 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 87:
#line 308 "uccompiler.y"
    { (yyval.node) = create_node("BitWiseXor",(yyvsp[(2) - (3)].tok)->cval,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 88:
#line 312 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 89:
#line 313 "uccompiler.y"
    { (yyval.node) = create_node("BitWiseOr",(yyvsp[(2) - (3)].tok)->cval,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 90:
#line 317 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 91:
#line 318 "uccompiler.y"
    { (yyval.node) = create_node("And",(yyvsp[(2) - (3)].tok)->cval,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 92:
#line 322 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 93:
#line 323 "uccompiler.y"
    { (yyval.node) = create_node("Or",(yyvsp[(2) - (3)].tok)->cval,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 94:
#line 327 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 95:
#line 328 "uccompiler.y"
    { (yyval.node) = create_node("Store",(yyvsp[(2) - (3)].tok)->cval,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 96:
#line 332 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 97:
#line 333 "uccompiler.y"
    { (yyval.node) = create_node("Comma",(yyvsp[(2) - (3)].tok)->cval,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); (yyval.node)->line = (yyvsp[(2) - (3)].tok)->line; (yyval.node)->column = (yyvsp[(2) - (3)].tok)->column; }
    break;

  case 98:
#line 336 "uccompiler.y"
    {}
    break;


/* Line 1267 of yacc.c.  */
#line 2212 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


#line 338 "uccompiler.y"


