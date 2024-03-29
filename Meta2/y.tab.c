/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "uccompiler.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h> 
    #include <string.h>
    #include "ast.h"
    int flag = 0,tree_flag = 1;

    node root = NULL;
    node aux = NULL;


#line 78 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    INTLIT = 295,
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
#define IFS 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 14 "uccompiler.y" /* yacc.c:355  */

char * cval;
struct no * node;

#line 205 "y.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 234 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    29,    29,    34,    35,    36,    37,    38,    39,    43,
      47,    48,    52,    53,    54,    55,    59,    63,    67,    71,
      72,    76,    77,    81,    93,    97,    98,   102,   103,   107,
     108,   109,   110,   111,   115,   116,   119,   120,   121,   122,
     123,   127,   128,   129,   133,   134,   138,   142,   143,   147,
     155,   167,   177,   181,   182,   183,   184,   185,   186,   190,
     191,   195,   196,   197,   198,   203,   204,   205,   206,   210,
     211,   212,   213,   217,   218,   219,   223,   224,   225,   226,
     227,   231,   232,   233,   237,   238,   242,   243,   247,   248,
     252,   253,   257,   258,   262,   263,   267,   268,   271
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "ELSE", "WHILE", "IF", "INT",
  "SHORT", "DOUBLE", "RETURN", "VOID", "BITWISEAND", "BITWISEOR",
  "BITWISEXOR", "AND", "ASSIGN", "MUL", "COMMA", "DIV", "EQ", "GE", "GT",
  "LBRACE", "LE", "LPAR", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS",
  "RBRACE", "RPAR", "SEMI", "ID", "CHRLIT", "REALLIT", "RESERVED",
  "INTLIT", "IFS", "$accept", "Program", "FunctionsAndDeclarations",
  "FunctionDefinition", "FunctionBody", "DeclarationsAndStatements",
  "FunctionDeclaration", "FunctionDeclarator", "ParameterList",
  "ParameterDeclaration_", "ParameterDeclaration", "Declaration",
  "Declarator_", "Declarator", "TypeSpec", "StatementError", "Statement",
  "Compound_Stm", "BlockItemStm", "Expr_Stm", "OptionalExpr", "Select_Stm",
  "Iter_Stm", "Jump_Stm", "PrimaryExpr", "ArgExpr", "FunctionCallExpr",
  "UnaryExpr", "MultiplicativeExpr", "AdditiveExpr", "RelationalExpr",
  "EqualExpr", "AndExpr", "ExclusiveOrExpr", "InclusiveOrExpr",
  "LogicalAndExpr", "LogicalOrExpr", "AssignExpr", "Expr", "empty", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -35

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-35)))

#define YYTABLE_NINF -99

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,   -34,   -35,   -35,   -35,   -35,   -35,     9,   -35,    89,
     276,   288,    -5,   -35,   -35,   -35,   -35,   -35,    49,    35,
     -35,   235,   112,    12,   -35,   -35,   -10,   -35,   221,   235,
     235,   235,    44,   -35,   -35,   -35,   -35,   -35,   -35,   119,
      78,   164,    73,    52,    66,    75,    92,    47,   -35,    70,
     -35,    82,    97,   100,   235,   139,   -35,   102,    76,   101,
     123,   -35,   -35,   104,   -35,   -35,   -35,   -35,   125,   -35,
     101,   -35,   117,    -4,   -35,   -35,   -35,   207,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   -35,   134,   -35,   -35,   235,
     235,   122,   -28,   -35,   177,   -35,   121,   -35,   -35,   149,
     -35,   -35,   235,   -35,   -35,   -35,   133,   -35,    28,   -35,
     -35,   -35,   -35,   119,   119,    78,    78,    78,    78,   164,
     164,    73,    52,    66,    75,   -35,    92,   112,    37,    39,
     -35,   -35,   -35,   135,   -35,   -35,   -35,   -35,   235,   -35,
     -35,   193,   193,   -35,   -35,   169,   193,   -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -35,   -35,    57,   -35,   -35,   -31,   -35,   -35,   -35,   -35,
      31,   -17,   -35,   110,   -20,    40,    -7,   -35,    77,   -35,
     130,   -35,   -35,   -35,   -35,   -35,   -35,   -19,    13,   217,
      54,   106,    99,   114,   105,   107,   -35,   -21,   -24,     4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    25,    57,    10,    19,    49,    96,
      50,    11,    26,    20,    12,   104,   105,    61,   106,    62,
      63,    64,    65,    66,    36,   118,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    67,    68,    69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    13,    51,    59,    73,   141,    58,   142,    70,    14,
      74,    75,    76,     1,   112,     2,    60,    52,    53,     3,
       4,     5,    54,     6,    27,    71,     1,   108,     2,   110,
     115,    18,     3,     4,     5,    55,     6,    28,    59,    29,
      59,    58,    30,    58,    31,    56,   148,   -98,    32,    33,
      34,    60,    35,    60,    97,   112,   119,   112,    23,   120,
     121,   122,   149,    93,    89,    21,    15,    16,    17,    77,
      24,   151,   135,   152,    22,   138,   139,     1,    94,     2,
      90,    52,    53,     3,     4,     5,    54,     6,    91,    -3,
       1,   146,     2,    87,   123,   124,     3,     4,     5,    55,
       6,    28,    88,    29,    95,    81,    30,    92,    31,   -15,
      82,   -98,    32,    33,    34,     2,    35,    51,    98,     3,
       4,     5,    99,     6,     1,   100,     2,   153,    52,    53,
       3,     4,     5,    54,     6,   107,    78,   109,    79,   111,
     102,   129,   130,   112,    52,    53,    55,    80,    28,    54,
      29,   114,   137,    30,   145,    31,   -14,   140,   -98,    32,
      33,    34,    55,    35,    28,    21,    29,   147,   150,    30,
     142,    31,   103,   156,   -98,    32,    33,    34,   143,    35,
     113,   144,    52,    53,   101,    83,    84,    54,    85,   132,
      86,   154,   155,     0,   143,   131,   157,   134,    52,    53,
      55,   136,    28,    54,    29,   133,     0,    30,   116,    31,
     -45,     0,   -98,    32,    33,    34,    55,    35,    28,     0,
      29,     0,    72,    30,     0,    31,     0,     0,   -98,    32,
      33,    34,    28,    35,    29,     0,     0,    30,     0,    31,
       0,   117,     0,    32,    33,    34,    28,    35,    29,     0,
       0,    30,     0,    31,     0,     0,     0,    32,    33,    34,
      28,    35,    29,     0,     0,    30,     0,    31,     0,     0,
       0,    32,    33,    34,     0,    35,    -4,     1,     0,     2,
       0,     0,     0,     3,     4,     5,     0,     6,    -5,     1,
       0,     2,     0,     0,     0,     3,     4,     5,     0,     6,
     125,   126,   127,   128
};

static const yytype_int16 yycheck[] =
{
      21,    35,    22,    23,    28,    33,    23,    35,    18,     0,
      29,    30,    31,     1,    18,     3,    23,     5,     6,     7,
       8,     9,    10,    11,    20,    35,     1,    58,     3,    60,
      34,    36,     7,     8,     9,    23,    11,    25,    58,    27,
      60,    58,    30,    60,    32,    33,    18,    35,    36,    37,
      38,    58,    40,    60,    50,    18,    77,    18,    23,    78,
      79,    80,    34,    16,    12,    16,     9,    10,    11,    25,
      35,    34,    93,    34,    25,    99,   100,     1,    31,     3,
      14,     5,     6,     7,     8,     9,    10,    11,    13,     0,
       1,   112,     3,    20,    81,    82,     7,     8,     9,    23,
      11,    25,    29,    27,    34,    27,    30,    15,    32,    33,
      32,    35,    36,    37,    38,     3,    40,   137,    36,     7,
       8,     9,    25,    11,     1,    25,     3,   148,     5,     6,
       7,     8,     9,    10,    11,    33,    17,    36,    19,    35,
       1,    87,    88,    18,     5,     6,    23,    28,    25,    10,
      27,    34,    18,    30,    33,    32,    33,    35,    35,    36,
      37,    38,    23,    40,    25,    16,    27,    34,   137,    30,
      35,    32,    33,     4,    35,    36,    37,    38,     1,    40,
      70,   104,     5,     6,    54,    21,    22,    10,    24,    90,
      26,   151,   152,    -1,     1,    89,   156,    92,     5,     6,
      23,    94,    25,    10,    27,    91,    -1,    30,     1,    32,
      33,    -1,    35,    36,    37,    38,    23,    40,    25,    -1,
      27,    -1,     1,    30,    -1,    32,    -1,    -1,    35,    36,
      37,    38,    25,    40,    27,    -1,    -1,    30,    -1,    32,
      -1,    34,    -1,    36,    37,    38,    25,    40,    27,    -1,
      -1,    30,    -1,    32,    -1,    -1,    -1,    36,    37,    38,
      25,    40,    27,    -1,    -1,    30,    -1,    32,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,     0,     1,    -1,     3,
      -1,    -1,    -1,     7,     8,     9,    -1,    11,     0,     1,
      -1,     3,    -1,    -1,    -1,     7,     8,     9,    -1,    11,
      83,    84,    85,    86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     7,     8,     9,    11,    43,    44,    45,
      48,    53,    56,    35,     0,    44,    44,    44,    36,    49,
      55,    16,    25,    23,    35,    46,    54,    81,    25,    27,
      30,    32,    36,    37,    38,    40,    66,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    50,
      52,    56,     5,     6,    10,    23,    33,    47,    53,    56,
      58,    59,    61,    62,    63,    64,    65,    79,    80,    81,
      18,    35,     1,    80,    69,    69,    69,    25,    17,    19,
      28,    27,    32,    21,    22,    24,    26,    20,    29,    12,
      14,    13,    15,    16,    31,    34,    51,    81,    36,    25,
      25,    62,     1,    33,    57,    58,    60,    33,    47,    36,
      47,    35,    18,    55,    34,    34,     1,    34,    67,    79,
      69,    69,    69,    70,    70,    71,    71,    71,    71,    72,
      72,    73,    74,    75,    76,    79,    77,    18,    80,    80,
      35,    33,    35,     1,    60,    33,    79,    34,    18,    34,
      52,    34,    34,    79,    57,    57,     4,    57
};

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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
     '$$ = $1'.

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
#line 29 "uccompiler.y" /* yacc.c:1646  */
    { root = create_node("Program", NULL, 1, (yyvsp[0].node)); }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 34 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 35 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 36 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 37 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = add_brother((yyvsp[-1].node),(yyvsp[0].node)); }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 38 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = add_brother((yyvsp[-1].node),(yyvsp[0].node)); }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 39 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = add_brother((yyvsp[-1].node),(yyvsp[0].node)); }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 43 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("FuncDefinition",NULL,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 47 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("FuncBody",NULL,0); }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 48 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("FuncBody",NULL,1,(yyvsp[-1].node)); }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 52 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = add_brother((yyvsp[-1].node),(yyvsp[0].node)); }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 53 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = add_brother((yyvsp[-1].node),(yyvsp[0].node)); }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 54 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 55 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 59 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("FuncDeclaration",NULL,2,(yyvsp[-2].node),(yyvsp[-1].node)); }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 63 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = add_brother(create_node("Id",(yyvsp[-3].cval),0),(yyvsp[-1].node)); free((yyvsp[-3].cval)); }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 67 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("ParamList",NULL,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 71 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = add_brother((yyvsp[-2].node),(yyvsp[0].node)); }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 72 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 76 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("ParamDeclaration",NULL,1,(yyvsp[0].node)); }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 77 "uccompiler.y" /* yacc.c:1646  */
    { aux = create_node("Id",(yyvsp[0].cval),0); (yyval.node) = create_node("ParamDeclaration",NULL,2,(yyvsp[-1].node),aux); free((yyvsp[0].cval)); }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 81 "uccompiler.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].node) = add_brother((yyvsp[-2].node),(yyvsp[-1].node)); 
            aux = (yyvsp[-2].node); 
            while(aux != NULL) { 
                aux->son = add_brother(create_node((yyvsp[-3].node)->label,NULL,0),aux->son); 
                aux = aux->brother; 
            }
            (yyval.node) = (yyvsp[-2].node);
            free((yyvsp[-3].node)->label); 
            free((yyvsp[-3].node)->cval); 
            free((yyvsp[-3].node)); 
        }
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 93 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; tree_flag = 0; }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 97 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = add_brother((yyvsp[-2].node),(yyvsp[0].node)); }
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 98 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 102 "uccompiler.y" /* yacc.c:1646  */
    { aux = create_node("Id",(yyvsp[-2].cval),0); if((yyvsp[0].node) != NULL) (yyval.node) = create_node("Declaration",NULL,2,aux,(yyvsp[0].node)); free((yyvsp[-2].cval)); }
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 103 "uccompiler.y" /* yacc.c:1646  */
    { aux = create_node("Id",(yyvsp[0].cval),0); (yyval.node) = create_node("Declaration",NULL,1,aux); free((yyvsp[0].cval)); }
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 107 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Char", NULL, 0); }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 108 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Int", NULL, 0); }
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 109 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Void", NULL, 0); }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 110 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Short", NULL, 0); }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 111 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Double", NULL, 0); }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 115 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; tree_flag = 0; }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 116 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 119 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 120 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 121 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 122 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 123 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 127 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 128 "uccompiler.y" /* yacc.c:1646  */
    { if((yyvsp[-1].node) != NULL && (yyvsp[-1].node)->brother != NULL) { (yyval.node) = create_node("StatList", NULL, 1, (yyvsp[-1].node)); } else (yyval.node) = (yyvsp[-1].node); }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 129 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; tree_flag = 0; }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 133 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = add_brother((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 134 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 138 "uccompiler.y" /* yacc.c:1646  */
    { if (strcmp((yyvsp[-1].node)->label, "Null") == 0) { (yyval.node) = NULL; free((yyvsp[-1].node)); } else (yyval.node) = (yyvsp[-1].node); }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 142 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Null", NULL, 0); }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 143 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 147 "uccompiler.y" /* yacc.c:1646  */
    { 
            if((yyvsp[-2].node) == NULL) 
                (yyvsp[-2].node) = create_node("Null", NULL, 0); 
            if((yyvsp[0].node) == NULL) 
                (yyvsp[0].node) = create_node("Null", NULL, 0); 
            aux = create_node("Null", NULL, 0);
            (yyval.node) = create_node("If", NULL, 3, (yyvsp[-2].node), (yyvsp[0].node), aux);
        }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 155 "uccompiler.y" /* yacc.c:1646  */
    { 
            if ((yyvsp[-4].node) == NULL)
                (yyvsp[-4].node) = create_node("Null", NULL, 0); 
            if((yyvsp[-2].node) == NULL) 
                (yyvsp[-2].node) = create_node("Null", NULL, 0); 
            if((yyvsp[0].node) == NULL) 
                (yyvsp[0].node) = create_node("Null", NULL, 0); 
            (yyval.node) = create_node("If", NULL, 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
        }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 167 "uccompiler.y" /* yacc.c:1646  */
    { 
            if ((yyvsp[-2].node) == NULL)
                (yyvsp[-2].node) = create_node("Null", NULL, 0);
            if ((yyvsp[0].node) == NULL) 
                (yyvsp[0].node) = create_node("Null", NULL, 0); 
            (yyval.node) = create_node("While", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); 
        }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 177 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Return", NULL, 1, (yyvsp[-1].node)); }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 181 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Id",(yyvsp[0].cval),0); free((yyvsp[0].cval)); }
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 182 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("IntLit",(yyvsp[0].cval),0); free((yyvsp[0].cval)); }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 183 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("ChrLit",(yyvsp[0].cval),0); free((yyvsp[0].cval)); }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 184 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("RealLit",(yyvsp[0].cval),0); free((yyvsp[0].cval)); }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 185 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 186 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Null", NULL, 0); }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 190 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 191 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = add_brother((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 195 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 196 "uccompiler.y" /* yacc.c:1646  */
    { aux = create_node("Id", (yyvsp[-3].cval), 0); (yyval.node) = create_node("Call", NULL, 2, aux, (yyvsp[-1].node)); free((yyvsp[-3].cval)); }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 197 "uccompiler.y" /* yacc.c:1646  */
    { aux = create_node("Id", (yyvsp[-2].cval), 0); (yyval.node) = create_node("Call", NULL, 1, aux); free((yyvsp[-2].cval));}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 198 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Null", NULL, 0); free((yyvsp[-3].cval)); }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 203 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 204 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Plus",NULL,1,(yyvsp[0].node)); }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 205 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Minus",NULL,1,(yyvsp[0].node)); }
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 206 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Not",NULL,1,(yyvsp[0].node)); }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 210 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 211 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Mul", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 212 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Div", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 213 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Mod", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 217 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 218 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Add", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 219 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Sub", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 223 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 224 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Lt", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 225 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Gt", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 226 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Le", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 227 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Ge", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 231 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 232 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Eq", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 233 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Ne", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 237 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 238 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("BitWiseAnd", NULL,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 242 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 243 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("BitWiseXor",NULL,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 247 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 248 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("BitWiseOr",NULL,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 252 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 253 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("And",NULL,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 257 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 258 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Or",NULL,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 262 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 263 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Store",NULL,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 267 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 268 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("Comma",NULL,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 271 "uccompiler.y" /* yacc.c:1646  */
    {}
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2165 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 273 "uccompiler.y" /* yacc.c:1906  */

