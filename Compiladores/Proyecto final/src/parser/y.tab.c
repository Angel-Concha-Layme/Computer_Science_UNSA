/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <vector>
#include "tree/common.h"
#include "symbol.h"
#include "scope.h"
#include "tree/node.h"
#include "tree/programnode.h"
#include "tree/vardeclarationnode.h"
#include "tree/vectordeclarationnode.h"
#include "tree/headernode.h"
#include "tree/functiondefinitionnode.h"
#include "tree/assignmentnode.h"
#include "tree/inputnode.h"
#include "tree/outputnode.h"
#include "tree/returnnode.h"
#include "tree/functioncallnode.h"
#include "tree/ifnode.h"
#include "tree/whilenode.h"
#include "tree/blocknode.h"
#include "tree/expression/expressionnode.h"
#include "tree/expression/identifiernode.h"
#include "tree/expression/literalnode.h"
#include "tree/expression/operationnode.h"

int yylex();
void yyerror(const char *message);

typedef std::vector<Node*> ParameterList;
typedef std::vector<Node*> VariableList;
typedef std::vector<Node*> ExpressionList;
typedef std::vector<Node*> CommandList;
typedef std::vector<int> DimensionList;


#line 102 "y.tab.c" /* yacc.c:339  */

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 37 "parser.y" /* yacc.c:355  */

class FunctionDefinitionNode;

#line 133 "y.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_PR_ENTERO = 258,
    TK_PR_FLOTANTE = 259,
    TK_PR_BOOLEANO = 260,
    TK_PR_CARACTER = 261,
    TK_PR_CADENA = 262,
    TK_PR_SE = 263,
    TK_PR_ENTONCES = 264,
    TK_PR_SENAO = 265,
    TK_PR_ENQUANTO = 266,
    TK_PR_REALIZA = 267,
    TK_PR_ENTRADA = 268,
    TK_PR_SALIDA = 269,
    TK_PR_RETORNA = 270,
    TK_OC_LE = 271,
    TK_OC_GE = 272,
    TK_OC_EQ = 273,
    TK_OC_NE = 274,
    TK_OC_AND = 275,
    TK_OC_OR = 276,
    TK_LIT_ENTERO = 277,
    TK_LIT_FLOTANTE = 278,
    TK_LIT_FALSO = 279,
    TK_LIT_VERDADERO = 280,
    TK_LIT_CARACTER = 281,
    TK_LIT_CADENA = 282,
    TK_IDENTIFICADOR = 283,
    TOKEN_ERROR = 284
  };
#endif
/* Tokens.  */
#define TK_PR_ENTERO 258
#define TK_PR_FLOTANTE 259
#define TK_PR_BOOLEANO 260
#define TK_PR_CARACTER 261
#define TK_PR_CADENA 262
#define TK_PR_SE 263
#define TK_PR_ENTONCES 264
#define TK_PR_SENAO 265
#define TK_PR_ENQUANTO 266
#define TK_PR_REALIZA 267
#define TK_PR_ENTRADA 268
#define TK_PR_SALIDA 269
#define TK_PR_RETORNA 270
#define TK_OC_LE 271
#define TK_OC_GE 272
#define TK_OC_EQ 273
#define TK_OC_NE 274
#define TK_OC_AND 275
#define TK_OC_OR 276
#define TK_LIT_ENTERO 277
#define TK_LIT_FLOTANTE 278
#define TK_LIT_FALSO 279
#define TK_LIT_VERDADERO 280
#define TK_LIT_CARACTER 281
#define TK_LIT_CADENA 282
#define TK_IDENTIFICADOR 283
#define TOKEN_ERROR 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 41 "parser.y" /* yacc.c:355  */

  Node* node;
  FunctionDefinitionNode* funcNode;
  std::vector<Node*>* nodes;
  Common::DataType dataType;
  Symbol* symbol;
  int integer;
  std::vector<int>* integers;

#line 213 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 230 "y.tab.c" /* yacc.c:358  */

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   321

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

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
      42,    43,    34,    32,    44,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    36,
      30,    45,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   128,   131,   132,   133,   134,   137,   138,
     141,   142,   145,   148,   151,   152,   155,   158,   159,   160,
     161,   162,   165,   166,   169,   173,   173,   176,   177,   180,
     181,   184,   191,   192,   193,   194,   195,   196,   197,   198,
     201,   201,   204,   205,   206,   209,   210,   213,   214,   217,
     220,   223,   226,   227,   230,   231,   234,   235,   236,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PR_ENTERO", "TK_PR_FLOTANTE",
  "TK_PR_BOOLEANO", "TK_PR_CARACTER", "TK_PR_CADENA", "TK_PR_SE",
  "TK_PR_ENTONCES", "TK_PR_SENAO", "TK_PR_ENQUANTO", "TK_PR_REALIZA",
  "TK_PR_ENTRADA", "TK_PR_SALIDA", "TK_PR_RETORNA", "TK_OC_LE", "TK_OC_GE",
  "TK_OC_EQ", "TK_OC_NE", "TK_OC_AND", "TK_OC_OR", "TK_LIT_ENTERO",
  "TK_LIT_FLOTANTE", "TK_LIT_FALSO", "TK_LIT_VERDADERO", "TK_LIT_CARACTER",
  "TK_LIT_CADENA", "TK_IDENTIFICADOR", "TOKEN_ERROR", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "';'", "':'", "'['", "']'", "'{'", "'}'", "'('",
  "')'", "','", "'='", "$accept", "s", "@1", "programa", "decl_global",
  "decl_local", "decl_var", "decl_vector", "decl_vector_dimension",
  "decl_vector_dimension_tamanio", "tipo_var", "def_funcion",
  "llamada_funcion", "encabezado", "@2", "lista_parametros",
  "lista_parametros_no_vacia", "parametro", "comando", "bloco_comando",
  "@3", "seq_comando", "asignacion", "vector_dimensiones", "entrada",
  "salida", "retorna", "lista_expresiones", "lista_expresiones_no_vacia",
  "control_flujo", "expresion", YY_NULLPTR
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
      60,    62,    43,    45,    42,    47,    59,    58,    91,    93,
     123,   125,    40,    41,    44,    61
};
# endif

#define YYPACT_NINF -114

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-114)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -114,    14,   -13,  -114,   -19,   -13,  -114,   -16,   -10,  -114,
     -23,   101,  -114,  -114,  -114,  -114,     0,  -114,   -21,    17,
    -114,  -114,  -114,  -114,  -114,    10,   101,    -5,  -114,    23,
    -114,    25,  -114,    37,  -114,    34,    50,    65,   268,   268,
      12,  -114,  -114,    59,    64,    73,  -114,  -114,  -114,  -114,
    -114,  -114,    70,  -114,  -114,    74,    86,    25,   268,   268,
      85,  -114,  -114,  -114,  -114,  -114,  -114,    18,   268,   268,
     268,  -114,   -20,   286,   225,   268,   268,   268,    13,  -114,
    -114,  -114,  -114,  -114,  -114,    87,    79,    82,  -114,    84,
     117,   137,  -114,    89,   -22,   -22,   157,  -114,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,  -114,   177,    96,    97,   232,   268,   268,    88,   101,
    -114,    86,  -114,   121,   104,  -114,   286,    54,    54,    54,
      54,    11,    11,    54,    54,   -22,   -22,  -114,  -114,  -114,
    -114,  -114,   201,   253,  -114,  -114,  -114,   104,  -114,  -114,
    -114,   130,   104,  -114
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     6,     0,     0,     7,
       0,     0,     4,     5,     8,     9,     0,    44,     0,     0,
      17,    18,    19,    20,    21,    12,     0,     0,    44,     0,
      11,     0,    25,    13,    12,     0,     0,     0,     0,     0,
       0,    40,    23,     0,     0,    42,    32,    34,    35,    36,
      37,    33,     0,    10,    16,     0,    28,     0,     0,     0,
       0,    61,    62,    63,    64,    65,    66,    59,     0,     0,
       0,    82,     0,    55,     0,     0,    53,     0,     0,    44,
      38,    39,    43,    22,    15,     0,     0,    27,    30,     0,
       0,     0,    49,    60,    73,    74,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,    52,     0,     0,     0,     0,     0,
      26,     0,    14,     0,     0,    75,    54,    76,    77,    78,
      79,    80,    81,    71,    72,    67,    68,    69,    70,    48,
      24,    45,     0,     0,    41,    31,    29,     0,    58,    47,
      46,    56,     0,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,  -114,   126,  -114,    72,  -114,  -114,   102,
     -25,   138,   -27,  -114,  -114,  -114,  -114,    21,  -113,  -114,
    -114,   -24,  -114,    78,  -114,  -114,  -114,  -114,    90,  -114,
     -37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     5,     6,    18,    43,     8,    33,    55,
      25,     9,    71,    10,    56,    86,    87,    88,    45,    46,
      79,    27,    47,    78,    48,    49,    50,   113,    72,    51,
      73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    34,    74,    35,    52,    16,    36,    16,    37,    38,
      39,   148,   109,   110,     3,     4,    97,    17,    11,    28,
      14,    90,    91,    40,    98,    44,    15,    99,   100,   101,
     102,    94,    95,    96,   151,    41,    42,    26,   112,   153,
     115,   105,   106,   107,   108,   109,   110,    54,    31,    26,
      75,   116,    32,    30,    76,   118,    75,    77,   117,    53,
      76,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     7,    57,    58,     7,    35,   142,
     143,    36,    19,    37,    38,    39,   107,   108,   109,   110,
      29,    44,    59,    60,   145,    80,    35,    44,    40,    36,
      81,    37,    38,    39,    20,    21,    22,    23,    24,    82,
      41,    83,    35,    84,    85,    36,    40,    37,    38,    39,
      44,    92,   120,   122,   119,    44,   121,   116,    41,   144,
     147,    12,    40,    99,   100,   101,   102,   103,   104,   140,
     152,    98,   146,    13,    41,    93,     0,   105,   106,   107,
     108,   109,   110,    99,   100,   101,   102,   103,   104,    89,
     123,     0,     0,     0,     0,     0,   114,   105,   106,   107,
     108,   109,   110,    99,   100,   101,   102,   103,   104,     0,
     124,     0,     0,     0,     0,     0,     0,   105,   106,   107,
     108,   109,   110,    99,   100,   101,   102,   103,   104,     0,
     125,     0,     0,     0,     0,     0,     0,   105,   106,   107,
     108,   109,   110,     0,     0,     0,   139,    99,   100,   101,
     102,   103,   104,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   110,     0,     0,     0,
     149,    99,   100,   101,   102,   103,   104,     0,    99,   100,
     101,   102,   103,   104,     0,   105,   106,   107,   108,   109,
     110,   111,   105,   106,   107,   108,   109,   110,   141,    99,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,   105,   106,   107,   108,   109,   110,   150,
      61,    62,    63,    64,    65,    66,    67,     0,     0,     0,
      68,    69,    99,   100,   101,   102,   103,   104,     0,     0,
      70,     0,     0,     0,     0,     0,   105,   106,   107,   108,
     109,   110
};

static const yytype_int16 yycheck[] =
{
      27,    26,    39,     8,    28,    28,    11,    28,    13,    14,
      15,   124,    34,    35,     0,    28,    36,    40,    37,    40,
      36,    58,    59,    28,    44,    52,    36,    16,    17,    18,
      19,    68,    69,    70,   147,    40,    41,    37,    75,   152,
      77,    30,    31,    32,    33,    34,    35,    22,    38,    37,
      38,    38,    42,    36,    42,    79,    38,    45,    45,    36,
      42,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,     2,    38,    42,     5,     8,   116,
     117,    11,    10,    13,    14,    15,    32,    33,    34,    35,
      18,   118,    42,    28,   119,    36,     8,   124,    28,    11,
      36,    13,    14,    15,     3,     4,     5,     6,     7,    36,
      40,    41,     8,    39,    28,    11,    28,    13,    14,    15,
     147,    36,    43,    39,    37,   152,    44,    38,    40,    41,
       9,     5,    28,    16,    17,    18,    19,    20,    21,    43,
      10,    44,   121,     5,    40,    67,    -1,    30,    31,    32,
      33,    34,    35,    16,    17,    18,    19,    20,    21,    57,
      43,    -1,    -1,    -1,    -1,    -1,    76,    30,    31,    32,
      33,    34,    35,    16,    17,    18,    19,    20,    21,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    16,    17,    18,    19,    20,    21,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    16,    17,    18,    19,    20,    21,    -1,    16,    17,
      18,    19,    20,    21,    -1,    30,    31,    32,    33,    34,
      35,    36,    30,    31,    32,    33,    34,    35,    36,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      32,    33,    16,    17,    18,    19,    20,    21,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    48,     0,    28,    49,    50,    52,    53,    57,
      59,    37,    50,    57,    36,    36,    28,    40,    51,    52,
       3,     4,     5,     6,     7,    56,    37,    67,    40,    52,
      36,    38,    42,    54,    56,     8,    11,    13,    14,    15,
      28,    40,    41,    52,    58,    64,    65,    68,    70,    71,
      72,    75,    67,    36,    22,    55,    60,    38,    42,    42,
      28,    22,    23,    24,    25,    26,    27,    28,    32,    33,
      42,    58,    74,    76,    76,    38,    42,    45,    69,    66,
      36,    36,    36,    41,    39,    28,    61,    62,    63,    55,
      76,    76,    36,    69,    76,    76,    76,    36,    44,    16,
      17,    18,    19,    20,    21,    30,    31,    32,    33,    34,
      35,    36,    76,    73,    74,    76,    38,    45,    67,    37,
      43,    44,    39,    43,    43,    43,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    39,
      43,    36,    76,    76,    41,    56,    63,     9,    64,    39,
      36,    64,    10,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    48,    47,    49,    49,    49,    49,    50,    50,
      51,    51,    52,    53,    54,    54,    55,    56,    56,    56,
      56,    56,    57,    57,    58,    60,    59,    61,    61,    62,
      62,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      66,    65,    67,    67,    67,    68,    68,    69,    69,    70,
      71,    72,    73,    73,    74,    74,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     1,     1,     2,     2,
       3,     2,     3,     4,     4,     3,     1,     1,     1,     1,
       1,     1,     5,     4,     4,     0,     7,     1,     0,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     2,     2,
       0,     4,     2,     3,     0,     4,     5,     4,     3,     3,
       3,     3,     1,     0,     3,     1,     6,     8,     5,     1,
       2,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     1
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ProgramNode(); }
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); /*$$->print(0);*/ (yyval.node)->generateILOCCode(NULL); (yyval.node)->printILOC(yyout); /*$$->printSourceCode("");*/ /*$$->printILOC();*/ }
#line 1461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].node)->addChild((yyvsp[0].node)); }
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].node)->addChild((yyvsp[0].funcNode)); }
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].node)->addChild((yyvsp[0].node)); }
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].node)->addChild((yyvsp[0].funcNode)); }
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.nodes)->push_back((yyvsp[-1].node)); }
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.nodes) = new VariableList(); (yyval.nodes)->push_back((yyvsp[-1].node)); }
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new VarDeclarationNode((yyvsp[-2].symbol)->getText(), (yyvsp[0].dataType)); }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new VectorDeclarationNode((yyvsp[-3].symbol)->getText(), (yyvsp[-1].dataType), (yyvsp[0].integers)); }
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.integers)->push_back((yyvsp[-1].integer)); }
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.integers) = new DimensionList(); (yyval.integers)->push_back((yyvsp[-1].integer)); }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.integer) = atoi((yyvsp[0].symbol)->getText().c_str()); }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.dataType) = Common::INT; }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.dataType) = Common::FLOAT; }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.dataType) = Common::BOOL; }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.dataType) = Common::CHAR; }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.dataType) = Common::STRING; }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.funcNode) = new FunctionDefinitionNode(); (yyval.funcNode)->setHeader((yyvsp[-4].node)); (yyval.funcNode)->setLocals((yyvsp[-3].nodes)); Node* b = new BlockNode(false); b->addChildren((yyvsp[-1].nodes)); (yyval.funcNode)->setBlock(b); b->generateILOCCode(NULL); (yyval.funcNode)->generateILOCCode(NULL); delete (yyvsp[-3].nodes); }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.funcNode) = new FunctionDefinitionNode(); (yyval.funcNode)->setHeader((yyvsp[-3].node)); Node* b = new BlockNode(false); b->addChildren((yyvsp[-1].nodes)); (yyval.funcNode)->setBlock(b); b->generateILOCCode(NULL); (yyval.funcNode)->generateILOCCode(NULL); }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionCallNode((yyvsp[-3].symbol), (yyvsp[-1].nodes)); }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new HeaderNode((yyvsp[-3].symbol)->getText(), (yyvsp[-1].dataType)); }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); (yyval.node)->addChildren((yyvsp[-1].nodes)); Scope::setParams((yyvsp[-6].symbol)->getText(), (yyvsp[-1].nodes)) }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.nodes) = (yyvsp[0].nodes); }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.nodes) = new ParameterList(); }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].nodes)->push_back((yyvsp[0].node)); }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval.nodes) = new ParameterList(); (yyval.nodes)->push_back((yyvsp[0].node)); }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new VarDeclarationNode((yyvsp[-2].symbol)->getText(), (yyvsp[0].dataType)); }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 196 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 198 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BlockNode(); }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node);  (yyval.node)->addChildren((yyvsp[-1].nodes)); (yyval.node)->generateILOCCode(NULL); Scope::popScope(); }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].nodes)->push_back((yyvsp[0].node)); }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].nodes)->push_back((yyvsp[-1].node)); }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.nodes) = new CommandList(); }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentNode((yyvsp[-3].symbol)->getText(), (yyvsp[-1].node)); }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignmentNode((yyvsp[-4].symbol)->getText(), (yyvsp[-3].nodes), (yyvsp[-1].node)); }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-3].nodes)->push_back((yyvsp[-1].node)); }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.nodes) = new ExpressionList(); (yyval.nodes)->push_back((yyvsp[-1].node)); }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new InputNode((yyvsp[-1].symbol)->getText()); }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OutputNode((yyvsp[-1].nodes)); }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ReturnNode((yyvsp[-1].node)); }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.nodes) = (yyvsp[0].nodes); }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval.nodes) = new ExpressionList(); }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].nodes)->push_back((yyvsp[0].node)); }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.nodes) = new ExpressionList(); (yyval.nodes)->push_back((yyvsp[0].node)); }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new IfNode((yyvsp[-3].node), (yyvsp[0].node)); }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 235 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new IfNode((yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new WhileNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new IdentifierNode((yyvsp[0].symbol)); }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 240 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new IdentifierNode((yyvsp[-1].symbol), (yyvsp[0].nodes)); }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 241 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LiteralNode((yyvsp[0].symbol)->getText(), Common::INT); }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 242 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LiteralNode((yyvsp[0].symbol)->getText(), Common::FLOAT); }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 243 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LiteralNode((yyvsp[0].symbol)->getText(), Common::BOOL); }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LiteralNode((yyvsp[0].symbol)->getText(), Common::BOOL); }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 245 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LiteralNode((yyvsp[0].symbol)->getText(), Common::CHAR); }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 246 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LiteralNode((yyvsp[0].symbol)->getText(), Common::STRING); }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 247 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OperationNode(Common::OP_SUM, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OperationNode(Common::OP_SUB, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OperationNode(Common::OP_MULT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 250 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OperationNode(Common::OP_DIV, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 251 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OperationNode(Common::OP_LESS, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 252 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OperationNode(Common::OP_GREATER, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 253 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 254 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OperationNode(Common::OP_SUB, (yyvsp[0].node), NULL); }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 255 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OperationNode(Common::OP_PAREN, (yyvsp[-1].node), NULL); }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 256 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OperationNode(Common::OP_LE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 257 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OperationNode(Common::OP_GE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 258 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OperationNode(Common::OP_EQUAL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 259 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OperationNode(Common::OP_NEQUAL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OperationNode(Common::OP_AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new OperationNode(Common::OP_OR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 262 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1939 "y.tab.c" /* yacc.c:1646  */
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 267 "parser.y" /* yacc.c:1906  */

