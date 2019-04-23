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
#line 1 "grammar.ypp" /* yacc.c:339  */



#include <bits/stdc++.h>
#include "structure_def.h"

using namespace std;

extern int yylex();
extern int yylineno;
void yyerror(string s){
	 cerr<< s <<"at line no "<< yylineno<< endl;
}
int global_temp = 0;
code_output intermediate_output;
sym_tab symbol_table;
int level = 0;
int active_function_index = 0;  // -1 for any type error


#line 87 "grammar.tab.cpp" /* yacc.c:339  */

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
   by #include "grammar.tab.hpp".  */
#ifndef YY_YY_GRAMMAR_TAB_HPP_INCLUDED
# define YY_YY_GRAMMAR_TAB_HPP_INCLUDED
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
    ELSE = 258,
    FOR = 259,
    IF = 260,
    RETURN = 261,
    WHILE = 262,
    PTR_OP = 263,
    INC_OP = 264,
    DEC_OP = 265,
    AND_OP = 266,
    OR_OP = 267,
    LT = 268,
    GT = 269,
    LE_OP = 270,
    GE_OP = 271,
    EQ_OP = 272,
    NE_OP = 273,
    DO = 274,
    BREAK = 275,
    LIBRARY = 276,
    CONTINUE = 277,
    ERROR = 278,
    NOT = 279,
    AMP = 280,
    TILDE = 281,
    STAR = 282,
    ASSIGN = 283,
    OPEN_BRACKET = 284,
    CLOSE_BRACKET = 285,
    OPEN_CURLY = 286,
    CLOSE_CURLY = 287,
    OPEN_SQUARE = 288,
    CLOSE_SQUARE = 289,
    SEMI = 290,
    COMMA = 291,
    DOT = 292,
    PLUS = 293,
    MINUS = 294,
    DIVIDE = 295,
    MODULUS = 296,
    PIPE = 297,
    XOR = 298,
    QUES = 299,
    COLON = 300,
    ID = 301,
    BOOL = 302,
    CHAR = 303,
    INT = 304,
    FLOAT = 305,
    VOID = 306,
    NUM = 307,
    REAL = 308,
    UMINUS = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "grammar.ypp" /* yacc.c:355  */

  char *name;          // name of a variable or function
  int integer_value;   // value of an integer
  float real_value;    // value of a real number
  int type;            // check the define -1 for int -2 float and so on
  N_* N_s;
  M_ * M_s;
  ifexp_ * ifexp_s;
  loopexp_ * loopexp_s;
  varlist_ * varlist_s;
  id_arr_ * id_arr_s;
  id_arr_declare_ * id_arr_declare_s;
  type_ * type_s;
  elist_ * elist_s;
  conditional_expression_ * conditional_expression_s;
  parameter_list_ * parameter_list_s;
  assignment_statement_ * assignment_statement_s;
  statement_list_ * statement_list_s;
  result_ * result_s;
  new_num_list_ * new_num_list_s;
  unit_declaration_ * unit_declaration_s;

#line 205 "grammar.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 222 "grammar.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    88,    90,    93,    95,    97,   115,   116,
     117,   120,   121,   123,   124,   125,   126,   127,   128,   129,
     130,   132,   133,   137,   139,   140,   142,   144,   146,   148,
     150,   167,   184,   191,   195,   201,   224,   248,   271,   293,
     315,   338,   354,   371,   378,   394,   411,   419,   425,   430,
     446,   462,   479,   499,   504,   509,   520,   529,   545,   563,
     564,   565,   568,   577,   585,   605,   639,   677,   683,   691,
     696,   701,   715,   728,   742,   758,   763
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ELSE", "FOR", "IF", "RETURN", "WHILE",
  "PTR_OP", "INC_OP", "DEC_OP", "AND_OP", "OR_OP", "LT", "GT", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "DO", "BREAK", "LIBRARY", "CONTINUE", "ERROR",
  "NOT", "AMP", "TILDE", "STAR", "ASSIGN", "OPEN_BRACKET", "CLOSE_BRACKET",
  "OPEN_CURLY", "CLOSE_CURLY", "OPEN_SQUARE", "CLOSE_SQUARE", "SEMI",
  "COMMA", "DOT", "PLUS", "MINUS", "DIVIDE", "MODULUS", "PIPE", "XOR",
  "QUES", "COLON", "ID", "BOOL", "CHAR", "INT", "FLOAT", "VOID", "NUM",
  "REAL", "\"IFX\"", "UMINUS", "$accept", "program",
  "function_declaration", "first_curly", "last_curly", "function_head",
  "res_id", "type", "statement_list", "statement", "selection_statement",
  "ifexp", "iteration_statement", "whileexp", "forexp", "M", "N",
  "conditional_expression", "expression", "rel_expression",
  "normal_expression", "term", "factor", "unary_expression",
  "primary_expression", "elist", "assignment_statement",
  "variable_declaration", "id_arr", "id_arr_declare", "new_num_list",
  "parameter_list", "param_decl", "unit_declaration", "varlist", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF -53

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-53)))

#define YYTABLE_NINF -8

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -53,     7,    14,   -53,    13,     5,    12,    21,   -53,    61,
      61,    61,    61,   -53,    61,    -8,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,    15,    19,     8,   -53,   -53,    13,   -53,
      13,    61,    46,   -53,   -53,   111,     9,   -53,   -53,   -53,
       3,    16,    33,    61,    61,   -53,     0,   -53,    40,   -53,
     -53,   -53,    17,   -53,    61,    45,    48,   -53,    38,   -20,
     -53,    57,    81,   -53,    67,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,   -53,   -53,    61,
      63,    71,   -53,    61,   -53,    68,    61,   -53,   -53,    48,
      58,    73,    70,   -53,    59,    76,    66,   -53,    13,   -53,
     -53,    37,    37,    37,    37,    37,    37,     9,     9,   -53,
     -53,    46,   -53,   -53,    80,   -53,    82,   -53,    84,   -53,
      38,    85,    69,    87,   -53,   -53,   -53,    61,   -53,   -53,
      88,   -53,   -53,   103,    13,   104,   -53,   -53,   -53,   -53
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      12,     0,    28,     1,    61,     0,     0,     0,    28,     0,
       0,     0,     0,     4,     0,    63,     8,     9,    10,    53,
      54,    20,    12,     0,     0,     0,    11,    16,    61,    17,
      61,    61,    60,    32,    33,    34,    43,    46,    47,    48,
       0,     0,    55,    61,    61,    14,     0,    55,     0,    52,
      51,    50,     0,    49,     0,    64,    28,    12,    70,    65,
      76,    62,    22,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    13,     0,
       0,     0,    15,    61,    56,     0,     0,     5,    19,    28,
       0,     0,    69,    72,     0,    66,     0,    29,    61,    30,
      31,    36,    35,    38,    37,    39,    40,    41,    42,    44,
      45,    59,    28,    23,     0,    58,     0,     3,    73,     6,
       0,     0,     0,    65,    75,    28,    25,    61,    26,    57,
       0,    71,    68,     0,    61,     0,    74,    67,    21,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -53,    92,    49,   -53,   -53,   -52,   -14,   -26,
     -53,   -53,   -53,   -53,   -53,    -7,   -53,    -2,   -33,   -53,
      64,    18,    20,    72,   -53,   -53,   -28,   -53,    -4,    44,
     -53,   -53,   -53,    22,   -53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    21,    22,    88,    23,    24,    25,     2,    26,
      27,    28,    29,    30,    31,     4,   125,    32,    33,    34,
      35,    36,    37,    38,    39,    55,    40,    41,    47,    60,
      95,    91,    92,    93,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    48,    62,    64,    63,    46,    90,     3,    56,    -7,
      52,    65,    66,    94,    -2,    80,    81,     5,     6,     7,
       8,    85,     9,    10,    42,    54,    42,    42,    65,    66,
       9,    10,    99,   100,    43,    82,    75,    11,    77,    42,
      42,    44,    12,    89,    13,    11,    13,    84,    58,    76,
      12,    78,    14,   116,    59,   114,    45,    65,    66,    15,
      14,    79,    16,    17,    18,    19,    20,    15,    90,    83,
       9,    10,   126,    19,    20,    73,    74,   111,    86,    42,
      87,    49,    50,    51,    97,    11,    53,    16,    17,    18,
      12,   107,   108,    96,    42,   109,   110,    98,   112,   135,
      14,   113,   115,   119,   118,   127,   120,    15,   138,   122,
     128,   121,   123,    19,    20,    57,   129,   130,   134,   132,
      94,   133,   136,    42,    67,    68,    69,    70,    71,    72,
      42,   101,   102,   103,   104,   105,   106,   137,   117,   139,
     124,     0,   131,     0,     0,     0,     0,     0,     0,    73,
      74
};

static const yytype_int16 yycheck[] =
{
       4,     8,    28,    31,    30,     7,    58,     0,    22,    29,
      12,    11,    12,    33,     0,    43,    44,     4,     5,     6,
       7,    54,     9,    10,    28,    33,    30,    31,    11,    12,
       9,    10,    65,    66,    29,    35,    27,    24,    35,    43,
      44,    29,    29,    57,    31,    24,    31,    30,    29,    40,
      29,    35,    39,    86,    46,    83,    35,    11,    12,    46,
      39,    28,    49,    50,    51,    52,    53,    46,   120,    29,
       9,    10,    98,    52,    53,    38,    39,    79,    33,    83,
      32,     9,    10,    11,     3,    24,    14,    49,    50,    51,
      29,    73,    74,    36,    98,    75,    76,    30,    35,   127,
      39,    30,    34,    30,    46,   112,    36,    46,   134,    33,
      30,    52,    46,    52,    53,    23,    34,    33,   125,    34,
      33,    52,    34,   127,    13,    14,    15,    16,    17,    18,
     134,    67,    68,    69,    70,    71,    72,    34,    89,    35,
      96,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    64,     0,    71,     4,     5,     6,     7,     9,
      10,    24,    29,    31,    39,    46,    49,    50,    51,    52,
      53,    58,    59,    61,    62,    63,    65,    66,    67,    68,
      69,    70,    73,    74,    75,    76,    77,    78,    79,    80,
      82,    83,    84,    29,    29,    35,    73,    84,    71,    79,
      79,    79,    73,    79,    33,    81,    64,    59,    29,    46,
      85,    90,    65,    65,    82,    11,    12,    13,    14,    15,
      16,    17,    18,    38,    39,    27,    40,    35,    35,    28,
      82,    82,    35,    29,    30,    74,    33,    32,    60,    64,
      63,    87,    88,    89,    33,    86,    36,     3,    30,    74,
      74,    76,    76,    76,    76,    76,    76,    77,    77,    78,
      78,    73,    35,    30,    82,    34,    74,    60,    46,    30,
      36,    52,    33,    46,    85,    72,    65,    71,    30,    34,
      33,    89,    34,    52,    71,    82,    34,    34,    65,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    59,    60,    61,    62,    63,    63,
      63,    64,    64,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    66,    67,    68,    68,    69,    70,    71,    72,
      73,    73,    73,    74,    74,    75,    75,    75,    75,    75,
      75,    76,    76,    76,    77,    77,    77,    78,    79,    79,
      79,    79,    79,    80,    80,    80,    80,    81,    81,    82,
      82,    82,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    88,    88,    89,    89,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     1,     1,     4,     2,     1,     1,
       1,     3,     0,     2,     2,     3,     1,     1,     2,     3,
       1,     6,     2,     4,     2,     4,     5,     7,     0,     0,
       3,     3,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     3,     4,     3,     3,
       1,     0,     2,     1,     2,     1,     2,     4,     3,     1,
       0,     3,     1,     2,     4,     3,     1
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
        case 4:
#line 90 "grammar.ypp" /* yacc.c:1646  */
    { level++;}
#line 1408 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 97 "grammar.ypp" /* yacc.c:1646  */
    {
	cout<< "find a function \n";
    string s((yyvsp[0].name));
    if(symbol_table.search_func(s) != -1){
      (yyval.result_s) = new result_(ERROR_TYPE);
      yyerror("this function is declared previously\n");
      active_function_index = -1;
    }
    else{
        (yyval.result_s) = new result_((yyvsp[-1].type_s)->type);
        active_function_index = symbol_table.add_function(s,(yyvsp[-1].type_s)->type);
        level = 1;
        string new_s = "func_" + s + ":";
        intermediate_output.gen(new_s);
    }
}
#line 1429 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 115 "grammar.ypp" /* yacc.c:1646  */
    {(yyval.type_s) = new type_(INT_TYPE);}
#line 1435 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 116 "grammar.ypp" /* yacc.c:1646  */
    {(yyval.type_s) = new type_(FLOAT_TYPE);}
#line 1441 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 117 "grammar.ypp" /* yacc.c:1646  */
    {(yyval.type_s) = new type_(VOID_TYPE);}
#line 1447 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 151 "grammar.ypp" /* yacc.c:1646  */
    {

 	int temp_type = get_compatible_type_bool_only((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
 	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
 	std::ostringstream out;
 	if(temp_type != ERROR_TYPE){
	 	out << " && " << (yyvsp[-2].conditional_expression_s)->temporary_name <<"     "<<(yyvsp[0].conditional_expression_s)->temporary_name << (yyval.conditional_expression_s)->temporary_name;
	 	string s = out.str();
	 	intermediate_output.gen(s);
 	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type != ERROR_TYPE && (yyvsp[0].conditional_expression_s)->type != ERROR_TYPE){
				yyerror("Expected boolean data types for both operand");
		}
	}
}
#line 1468 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 168 "grammar.ypp" /* yacc.c:1646  */
    {
 	int temp_type = get_compatible_type_bool_only((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
 	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
 	std::ostringstream out;
 	if(temp_type != ERROR_TYPE){
	 	out << " || " << (yyvsp[-2].conditional_expression_s)->temporary_name <<"     "<<(yyvsp[0].conditional_expression_s)->temporary_name << (yyval.conditional_expression_s)->temporary_name;
	 	string s = out.str();
	 	intermediate_output.gen(s);
 	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type != ERROR_TYPE && (yyvsp[0].conditional_expression_s)->type != ERROR_TYPE){
				yyerror("Expected boolean data types for both operand");
		}
	}
}
#line 1488 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 185 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->temporary_name);
}
#line 1496 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 192 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->temporary_name);
}
#line 1504 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 196 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->temporary_name);
}
#line 1512 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 202 "grammar.ypp" /* yacc.c:1646  */
    {
	int temp_type = get_compatible_type_rel_op((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		out << " > " << (yyvsp[-2].conditional_expression_s)->temporary_name <<"     "<<(yyvsp[0].conditional_expression_s)->temporary_name << (yyval.conditional_expression_s)->temporary_name;
		string s = out.str();
		intermediate_output.gen(s);
	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type != ERROR_TYPE &&  (yyvsp[0].conditional_expression_s)->type != ERROR_TYPE){
			if((yyvsp[-2].conditional_expression_s)->type == BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type != BOOL_TYPE){
				yyerror("Incompatible data types with relational operator");
			}
			if((yyvsp[-2].conditional_expression_s)->type != BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type == BOOL_TYPE){
				yyerror("Incompatible data types with relational operator");
			}
		}
	}

}
#line 1538 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 226 "grammar.ypp" /* yacc.c:1646  */
    {
	int temp_type = get_compatible_type_rel_op((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		out << " < " << (yyvsp[-2].conditional_expression_s)->temporary_name <<"     "<<(yyvsp[0].conditional_expression_s)->temporary_name << (yyval.conditional_expression_s)->temporary_name;
		string s = out.str();
		intermediate_output.gen(s);
	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type != ERROR_TYPE &&  (yyvsp[0].conditional_expression_s)->type != ERROR_TYPE){
			if((yyvsp[-2].conditional_expression_s)->type == BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type != BOOL_TYPE){
				yyerror("Incompatible data types with relational operator");
			}
			if((yyvsp[-2].conditional_expression_s)->type != BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type == BOOL_TYPE){
				yyerror("Incompatible data types with relational operator");
			}
		}
	}

}
#line 1564 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 249 "grammar.ypp" /* yacc.c:1646  */
    {
	int temp_type = get_compatible_type_rel_op((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		out << " >= " << (yyvsp[-2].conditional_expression_s)->temporary_name <<"     "<<(yyvsp[0].conditional_expression_s)->temporary_name << (yyval.conditional_expression_s)->temporary_name;
		string s = out.str();
		intermediate_output.gen(s);
	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type != ERROR_TYPE &&  (yyvsp[0].conditional_expression_s)->type != ERROR_TYPE){
			if((yyvsp[-2].conditional_expression_s)->type == BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type != BOOL_TYPE){
				yyerror("Incompatible data types with relational operator");
			}
			if((yyvsp[-2].conditional_expression_s)->type != BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type == BOOL_TYPE){
				yyerror("Incompatible data types with relational operator");
			}
		}
	}

}
#line 1590 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 272 "grammar.ypp" /* yacc.c:1646  */
    {
	int temp_type = get_compatible_type_rel_op((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		out << " <= " << (yyvsp[-2].conditional_expression_s)->temporary_name <<"     "<<(yyvsp[0].conditional_expression_s)->temporary_name << (yyval.conditional_expression_s)->temporary_name;
		string s = out.str();
		intermediate_output.gen(s);
	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type != ERROR_TYPE &&  (yyvsp[0].conditional_expression_s)->type != ERROR_TYPE){
			if((yyvsp[-2].conditional_expression_s)->type == BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type != BOOL_TYPE){
				yyerror("Incompatible data types with relational operator");
			}
			if((yyvsp[-2].conditional_expression_s)->type != BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type == BOOL_TYPE){
				yyerror("Incompatible data types with relational operator");
			}
		}
	}

}
#line 1616 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 294 "grammar.ypp" /* yacc.c:1646  */
    {
	int temp_type = get_compatible_type_rel_op((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		out << " == " << (yyvsp[-2].conditional_expression_s)->temporary_name <<"     "<<(yyvsp[0].conditional_expression_s)->temporary_name << (yyval.conditional_expression_s)->temporary_name;
		string s = out.str();
		intermediate_output.gen(s);
	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type != ERROR_TYPE &&  (yyvsp[0].conditional_expression_s)->type != ERROR_TYPE){
			if((yyvsp[-2].conditional_expression_s)->type == BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type != BOOL_TYPE){
				yyerror("Incompatible data types with relational operator");
			}
			if((yyvsp[-2].conditional_expression_s)->type != BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type == BOOL_TYPE){
				yyerror("Incompatible data types with relational operator");
			}
		}
	}

}
#line 1642 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 316 "grammar.ypp" /* yacc.c:1646  */
    {
	int temp_type = get_compatible_type_rel_op((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		out << " != " << (yyvsp[-2].conditional_expression_s)->temporary_name <<"     "<<(yyvsp[0].conditional_expression_s)->temporary_name << (yyval.conditional_expression_s)->temporary_name;
		string s = out.str();
		intermediate_output.gen(s);
	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type != ERROR_TYPE &&  (yyvsp[0].conditional_expression_s)->type != ERROR_TYPE){
			if((yyvsp[-2].conditional_expression_s)->type == BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type != BOOL_TYPE){
				yyerror("Incompatible data types with relational operator");
			}
			if((yyvsp[-2].conditional_expression_s)->type != BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type == BOOL_TYPE){
				yyerror("Incompatible data types with relational operator");
			}
		}
	}
}
#line 1667 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 339 "grammar.ypp" /* yacc.c:1646  */
    {
	int temp_type = get_compatible_type_non_bool((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		out << " + " << (yyvsp[-2].conditional_expression_s)->temporary_name <<"     "<<(yyvsp[0].conditional_expression_s)->temporary_name << (yyval.conditional_expression_s)->temporary_name;
		string s = out.str();
		intermediate_output.gen(s);
	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type == BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type == BOOL_TYPE){
			yyerror("Trying to add with a boolean data type");
		}
	}
}
#line 1687 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 355 "grammar.ypp" /* yacc.c:1646  */
    {
	int temp_type = get_compatible_type_non_bool((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		out << " - " << (yyvsp[-2].conditional_expression_s)->temporary_name <<"     "<<(yyvsp[0].conditional_expression_s)->temporary_name << (yyval.conditional_expression_s)->temporary_name;
		string s = out.str();
		intermediate_output.gen(s);
	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type == BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type == BOOL_TYPE){
			yyerror("Trying to subtract with a boolean data type");
		}
	}
}
#line 1707 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 372 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->temporary_name);
}
#line 1715 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 379 "grammar.ypp" /* yacc.c:1646  */
    {
	int temp_type = get_compatible_type_non_bool((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		out << " * " << (yyvsp[-2].conditional_expression_s)->temporary_name <<"     "<<(yyvsp[0].conditional_expression_s)->temporary_name << (yyval.conditional_expression_s)->temporary_name;
		string s = out.str();
		intermediate_output.gen(s);
	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type == BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type == BOOL_TYPE){
			yyerror("Trying to multiply with a boolean data type");
		}
	}
}
#line 1735 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 395 "grammar.ypp" /* yacc.c:1646  */
    {
	int temp_type = get_compatible_type_non_bool((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		out << " / " << (yyvsp[-2].conditional_expression_s)->temporary_name <<"     "<<(yyvsp[0].conditional_expression_s)->temporary_name << (yyval.conditional_expression_s)->temporary_name;
		string s = out.str();
		intermediate_output.gen(s);
	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type == BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type == BOOL_TYPE){
		 	yyerror("Trying to divide with a boolean data type");
		}
	}
}
#line 1755 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 412 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->temporary_name);

}
#line 1764 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 420 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->temporary_name);
}
#line 1772 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 426 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->temporary_name);

}
#line 1781 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 431 "grammar.ypp" /* yacc.c:1646  */
    {
	if((yyvsp[0].conditional_expression_s)->type != BOOL_TYPE){
		(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type);
		std::ostringstream out;
		if((yyvsp[0].conditional_expression_s)->type != ERROR_TYPE ){
			out << " UMINUS " << (yyvsp[0].conditional_expression_s)->temporary_name << " --- " << (yyval.conditional_expression_s)->temporary_name;
			string s = out.str();
			intermediate_output.gen(s);
		}
	}
	else{
		yyerror("Trying to negate a boolean data type");
		(yyval.conditional_expression_s) = new conditional_expression_(ERROR_TYPE);
	}
}
#line 1801 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 447 "grammar.ypp" /* yacc.c:1646  */
    {
	std::ostringstream out;
	if((yyvsp[0].conditional_expression_s)->type == FLOAT_TYPE ){
		(yyval.conditional_expression_s) = new conditional_expression_(ERROR_TYPE);
		yyerror("can not use not operator on a float data type");
	}
	else{
				(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type);
		}
	if((yyvsp[0].conditional_expression_s)->type != ERROR_TYPE && (yyvsp[0].conditional_expression_s)->type != FLOAT_TYPE ){
				out << " NOT " << (yyvsp[0].conditional_expression_s)->temporary_name << " --- " << (yyval.conditional_expression_s)->temporary_name;
				string s = out.str();
				intermediate_output.gen(s);
		}
}
#line 1821 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 463 "grammar.ypp" /* yacc.c:1646  */
    {
	if((yyvsp[0].conditional_expression_s)->type != BOOL_TYPE){
		(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type);
		std::ostringstream out;
		if((yyvsp[0].conditional_expression_s)->type != ERROR_TYPE){
			out << " - " << (yyvsp[0].conditional_expression_s)->temporary_name << " 1 " << (yyval.conditional_expression_s)->temporary_name;
			string s = out.str();
			intermediate_output.gen(s);
		}
	}
	else{
		yyerror("Trying to decrement a boolean data type");
		(yyval.conditional_expression_s) = new conditional_expression_(ERROR_TYPE);
	}

}
#line 1842 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 480 "grammar.ypp" /* yacc.c:1646  */
    {
	if((yyvsp[0].conditional_expression_s)->type != BOOL_TYPE){
		(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type);
		std::ostringstream out;
		if((yyvsp[0].conditional_expression_s)->type != ERROR_TYPE){
			out << " + " << (yyvsp[0].conditional_expression_s)->temporary_name << " 1 " << (yyval.conditional_expression_s)->temporary_name;
			string s = out.str();
			intermediate_output.gen(s);
		}
	}
	else{
		yyerror("Trying to increment a boolean data type");
		(yyval.conditional_expression_s) = new conditional_expression_(ERROR_TYPE);
	}

}
#line 1863 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 500 "grammar.ypp" /* yacc.c:1646  */
    {
(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].integer_value)->type,(yyvsp[0].integer_value)->temporary_name);
}
#line 1871 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 505 "grammar.ypp" /* yacc.c:1646  */
    {
(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].real_value)->type,(yyvsp[0].real_value)->temporary_name);
}
#line 1879 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 510 "grammar.ypp" /* yacc.c:1646  */
    {
	if((yyvsp[0].id_arr_s)->var == NULL){
			yyerror("The used variable is not declared");
			(yyval.conditional_expression_s) = new conditional_expression_(ERROR_TYPE);
	}
	else{
			(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].id_arr_s)->type,(yyvsp[0].id_arr_s)->temporary_name);
	}

}
#line 1894 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 521 "grammar.ypp" /* yacc.c:1646  */
    {
  (yyval.conditional_expression_s) = new conditional_expression_((yyvsp[-1].conditional_expression_s)->type,(yyvsp[-1].conditional_expression_s)->temporary_name);
}
#line 1902 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 530 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.elist_s) = new elist_();
	(yyval.elist_s)->name_list.insert((yyval.elist_s)->name_list.end(),(yyvsp[-3].elist_s)->name_list.begin(),(yyvsp[-3].elist_s)->name_list.end());
	if((yyvsp[-1].conditional_expression_s)->type != INT_TYPE){
		(yyval.elist_s)->type = ERROR_TYPE;
		if((yyvsp[-1].conditional_expression_s)->type != ERROR_TYPE){
			yyerror("Expected an integer data type for array index");
		}
		(yyval.elist_s)->name_list.push_back("ERR");
	}
	else{
		(yyval.elist_s)->type = INT_TYPE;
		(yyval.elist_s)->name_list.push_back((yyvsp[-1].conditional_expression_s)->temporary_name);
	}
}
#line 1922 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 546 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.elist_s) = new elist_();
	if((yyvsp[-1].conditional_expression_s)->type != INT_TYPE){
		(yyval.elist_s)->type = ERROR_TYPE;
		if((yyvsp[-1].conditional_expression_s)->type != ERROR_TYPE){
			yyerror("Expected an integer data type for array index");
		}
		(yyval.elist_s)->name_list.push_back("ERR");
	}
	else{
		(yyval.elist_s)->type = INT_TYPE;
		(yyval.elist_s)->name_list.push_back((yyvsp[-1].conditional_expression_s)->temporary_name);
	}
}
#line 1941 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 569 "grammar.ypp" /* yacc.c:1646  */
    {
	if(active_function_index != -1 ){
		symbol_table.patch_variable(active_function_index,(yyvsp[0].varlist_s)->list_of_indexes,(yyvsp[-1].type_s)->type);
 	}
}
#line 1951 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 578 "grammar.ypp" /* yacc.c:1646  */
    {
	if(active_function_index != -1){
		string s((yyvsp[0].name));
		variable * var =symbol_table.search_variable_global(active_function_index,s,level);
		(yyval.id_arr_s) = new id_arr_(var);
	}
}
#line 1963 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 586 "grammar.ypp" /* yacc.c:1646  */
    {
	if(active_function_index != -1){
		string s((yyvsp[-1].name));
		variable * var =symbol_table.search_variable_global(active_function_index,s,level);
		if(var != NULL){
			if(var->type != ARRAY){
				yyerror("Expected array type variable");
				var = NULL;
			}
		}

		if(var != NULL){

		}		
	}
}
#line 1984 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 605 "grammar.ypp" /* yacc.c:1646  */
    {
  if(active_function_index != -1){
      string s((yyvsp[0].name));
      variable * v_temp = symbol_table.search_variable_current(active_function_index,s,level);
      vector<int> v;
      v.clear();
      if(v_temp == NULL){
          int index = symbol_table.add_variable(active_function_index,s,SIMPLE,v,level);
          (yyval.id_arr_declare_s) = new id_arr_declare_(index);
      }
      else{
          if(v_temp->level_of_declaration != level){
              if(level != 2){
                  int index = symbol_table.add_variable(active_function_index,s,SIMPLE,v,level);
                  (yyval.id_arr_declare_s) = new id_arr_declare_(index);
              }
              else{
                  if(symbol_table.search_parameter(active_function_index,s) == false){
                    int index = symbol_table.add_variable(active_function_index,s,SIMPLE,v,level);
                    (yyval.id_arr_declare_s) = new id_arr_declare_(index);
                  }
                  else{
                      yyerror("This variable is defined in this scope previously");
                      (yyval.id_arr_declare_s) = new id_arr_declare_(-1);
                  }
              }
          }
          else{
              yyerror("This variable is defined in this scope previously");
              (yyval.id_arr_declare_s) = new id_arr_declare_(-1);
          }
      }
  }
}
#line 2023 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 639 "grammar.ypp" /* yacc.c:1646  */
    {
if(active_function_index != -1){
      string s((yyvsp[-1].name));
      variable * v_temp = symbol_table.search_variable_current(active_function_index,s,level);
      vector<int> v;
      v.clear();
      v = (yyvsp[0].new_num_list_s)-> num_list;
      if(v_temp == NULL){
          int index = symbol_table.add_variable(active_function_index,s,ARRAY,v,level);
          (yyval.id_arr_declare_s) = new id_arr_declare_(index);
      }
      else{
          if(v_temp->level_of_declaration != level){
              if(level != 2){
                  int index = symbol_table.add_variable(active_function_index,s,ARRAY,v,level);
                  (yyval.id_arr_declare_s) = new id_arr_declare_(index);
              }
              else{
                  if(symbol_table.search_parameter(active_function_index,s) == false){
                    int index = symbol_table.add_variable(active_function_index,s,ARRAY,v,level);
                    (yyval.id_arr_declare_s) = new id_arr_declare_(index);
                  }
                  else{
                      yyerror("This variable is defined in this scope previously");
                      (yyval.id_arr_declare_s) = new id_arr_declare_(-1);
                  }
              }
          }
          else{
              yyerror("This variable is defined in this scope previously");
              (yyval.id_arr_declare_s) = new id_arr_declare_(-1);
          }
      }
  }
}
#line 2063 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 677 "grammar.ypp" /* yacc.c:1646  */
    {
			cout<<"Trying to reduce new num list\n";
      (yyval.new_num_list_s)  = new new_num_list_();
      (yyval.new_num_list_s)->num_list.insert((yyval.new_num_list_s)->num_list.end(),(yyvsp[-3].new_num_list_s)->num_list.begin(),(yyvsp[-3].new_num_list_s)->num_list.end());
      (yyval.new_num_list_s)->num_list.push_back((yyvsp[-1].integer_value));
}
#line 2074 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 684 "grammar.ypp" /* yacc.c:1646  */
    {
		cout<<"Trying to reduce new num list\n";
    (yyval.new_num_list_s)  = new new_num_list_();
    (yyval.new_num_list_s)->num_list.push_back((yyvsp[-1].integer_value));
}
#line 2084 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 692 "grammar.ypp" /* yacc.c:1646  */
    { (yyval.parameter_list_s) = new parameter_list_((yyvsp[0].parameter_list_s)->no_of_parameter);
								symbol_table.patch_function_parameter_no(active_function_index,(yyval.parameter_list_s)->no_of_parameter);
							}
#line 2092 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 696 "grammar.ypp" /* yacc.c:1646  */
    { (yyval.parameter_list_s) = new parameter_list_(0);
							 symbol_table.patch_function_parameter_no(active_function_index,(yyval.parameter_list_s)->no_of_parameter);
							}
#line 2100 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 703 "grammar.ypp" /* yacc.c:1646  */
    {
if(active_function_index != -1){
	 if((yyvsp[0].unit_declaration_s)->type != ERROR_TYPE){
	 (yyval.parameter_list_s) = new parameter_list_((yyvsp[-2].parameter_list_s)->no_of_parameter + 1);;
	 }
	 else{
	  	(yyval.parameter_list_s) = new parameter_list_((yyvsp[-2].parameter_list_s)->no_of_parameter);
	 }
}
}
#line 2115 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 716 "grammar.ypp" /* yacc.c:1646  */
    {
if(active_function_index != -1){
	 if((yyvsp[0].unit_declaration_s)->type != ERROR_TYPE){
	 (yyval.parameter_list_s) = new parameter_list_(1);
	 }
	 else{
	  	(yyval.parameter_list_s) = new parameter_list_(0);
	 }
}
}
#line 2130 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 729 "grammar.ypp" /* yacc.c:1646  */
    {
	if(active_function_index != -1){
		string s((yyvsp[0].name));
		if(symbol_table.search_parameter(active_function_index,s) == false ){
			int index = symbol_table.add_parameter(active_function_index,s,SIMPLE,(yyvsp[-1].type_s)->type);
			(yyval.unit_declaration_s) = new unit_declaration_ ((yyvsp[-1].type_s)->type);
		}
		else{
			yyerror("This parameter has been passed early");
			(yyval.unit_declaration_s) = new unit_declaration_ (ERROR_TYPE);
			}
	}
}
#line 2148 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 743 "grammar.ypp" /* yacc.c:1646  */
    {
if(active_function_index != -1){
	string s((yyvsp[-2].name));
	if(symbol_table.search_parameter(active_function_index,s) == false ){
		int index = symbol_table.add_parameter(active_function_index,s,ARRAY,(yyvsp[-3].type_s)->type);
		(yyval.unit_declaration_s) = new unit_declaration_ ((yyvsp[-3].type_s)->type);
	}
	else{
			yyerror("This parameter has been passed early");
			(yyval.unit_declaration_s) = new unit_declaration_ (ERROR_TYPE);
	}
}
}
#line 2166 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 758 "grammar.ypp" /* yacc.c:1646  */
    {
	  (yyval.varlist_s) = new varlist_();
		(yyval.varlist_s)->list_of_indexes.insert((yyval.varlist_s)->list_of_indexes.end(),(yyvsp[-2].varlist_s)->list_of_indexes.begin(),(yyvsp[-2].varlist_s)->list_of_indexes.end());
		(yyval.varlist_s)->list_of_indexes.push_back((yyvsp[0].id_arr_declare_s)->index_in_sym_tab);
}
#line 2176 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 763 "grammar.ypp" /* yacc.c:1646  */
    {
          (yyval.varlist_s) = new varlist_();
		  (yyval.varlist_s)->list_of_indexes.push_back((yyvsp[0].id_arr_declare_s)->index_in_sym_tab);
        }
#line 2185 "grammar.tab.cpp" /* yacc.c:1646  */
    break;


#line 2189 "grammar.tab.cpp" /* yacc.c:1646  */
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
#line 770 "grammar.ypp" /* yacc.c:1906  */

#include <stdio.h>

int main(){

	yyparse();
  symbol_table.display();
	intermediate_output.print();
}
