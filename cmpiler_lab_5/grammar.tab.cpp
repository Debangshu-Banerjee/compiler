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

int global_temp = 0;
code_output intermediate_output;
loop_tag_genarator loop_tag;
conditional_tag_genator condition_tag;
func_end_tag_genarator func_end_tag;
sym_tab symbol_table;
int level = 0;
int active_function_index = 0;  // -1 for any type error
int call_function_index = -1;
bool main_flag = false;
bool total_error = false;
user_define_data total_user_variable;
void yyerror(string s){
	total_error = true;
	 cerr<< s <<" at line no "<< yylineno<< endl;
}

#line 95 "grammar.tab.cpp" /* yacc.c:339  */

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
    SWITCH = 301,
    CASE = 302,
    DEFAULT = 303,
    ID = 304,
    BOOL = 305,
    CHAR = 306,
    INT = 307,
    FLOAT = 308,
    VOID = 309,
    NUM = 310,
    REAL = 311,
    UMINUS = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "grammar.ypp" /* yacc.c:355  */

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
	elist_func_call_ * elist_func_call_s;
	case_name_ * case_name_s;
	case_list_ * case_list_s;
	unary_expression_ * unary_expression_s;

#line 220 "grammar.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 237 "grammar.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

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
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   105,   124,   127,   134,   137,   159,   160,
     161,   164,   179,   187,   195,   203,   212,   220,   228,   236,
     243,   250,   258,   267,   281,   299,   313,   327,   346,   360,
     380,   390,   403,   410,   424,   432,   447,   460,   487,   504,
     524,   530,   537,   543,   573,   604,   611,   615,   621,   658,
     696,   733,   769,   805,   842,   874,   905,   912,   942,   973,
     981,   987,   992,  1016,  1042,  1072,  1105,  1113,  1120,  1147,
    1152,  1161,  1177,  1194,  1215,  1222,  1229,  1237,  1245,  1321,
    1326,  1333,  1342,  1371,  1432,  1467,  1505,  1511,  1518,  1523,
    1528,  1542,  1555,  1569,  1585,  1591
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
  "QUES", "COLON", "SWITCH", "CASE", "DEFAULT", "ID", "BOOL", "CHAR",
  "INT", "FLOAT", "VOID", "NUM", "REAL", "\"IFS\"", "\"IFX\"", "UMINUS",
  "$accept", "program", "function_declaration", "first_curly",
  "last_curly", "function_head", "res_id", "type", "statement_list",
  "statement", "selection_statement", "switch_statement", "case_list",
  "case_list_minor", "default_statement", "default_name", "case_statement",
  "case_name", "ifexp", "iteration_statement", "whileexp", "forexp",
  "N_new", "M", "N", "conditional_expression", "expression",
  "rel_expression", "normal_expression", "term", "factor",
  "unary_expression", "primary_expression", "elist", "func_call",
  "elist_super", "elist_func_call", "assignment_statement",
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF -60

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-60)))

#define YYTABLE_NINF -8

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -60,    18,    25,   -60,    54,   -19,    12,   105,   -60,   102,
     102,    22,    27,   102,   102,   -60,   102,    36,   -20,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,    37,    46,    35,   -60,
     -60,   -60,    54,   -60,    54,   -60,    26,   -60,   -60,   160,
       6,   -60,   -60,   -60,   -60,    52,    56,    53,   102,   102,
     -60,     5,   -60,    63,   -60,   -60,   -60,   -60,   -60,    23,
     -60,   102,   102,   102,    64,    66,   -60,     2,     3,   -60,
      60,    96,   -60,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   -60,   -60,   102,    69,
      83,   -60,   102,   -60,     9,   -60,    86,    81,    84,   102,
     -60,   -60,    66,    71,    92,    87,   -60,    70,    91,    78,
     -60,   -60,   -60,   -60,    33,    33,    33,    33,    33,    33,
       6,     6,   -60,   -60,    26,   -60,   -60,    98,    99,   -60,
     102,   -60,   104,   -60,   100,   -60,     2,   108,    88,   113,
     -60,   -60,   -60,   102,   -60,   103,   -60,   -60,   115,   -60,
     -60,   118,    54,   117,   120,   -60,   121,    32,   -60,   102,
     -60,   -60,   -60,    54,   -60,   -60,   111,   -60,    54,   -60,
       4,   -60,   -60,   -60,   -60,   -60,    54,   -60
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      12,     0,    41,     1,    80,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     4,     0,     0,    82,     8,
       9,    10,    66,    67,    23,    12,     0,     0,     0,    11,
      18,    22,    80,    19,    80,    41,    79,    45,    46,    47,
      56,    59,    60,    61,    70,     0,     0,    68,    80,    80,
      16,     0,    68,     0,    65,    64,    14,    15,    63,     0,
      62,     0,    75,     0,    83,    41,    12,    89,    84,    95,
      81,    25,    36,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    13,     0,     0,
       0,    17,    80,    69,     0,    77,     0,    74,     0,     0,
       5,    21,    41,     0,     0,    88,    91,     0,    85,     0,
      42,    41,    43,    44,    49,    48,    51,    50,    52,    53,
      54,    55,    57,    58,    78,    41,    35,     0,     0,    73,
       0,    72,     0,     3,    92,     6,     0,     0,     0,    84,
      94,    41,    41,    80,    38,     0,    76,    71,     0,    90,
      87,     0,    80,     0,     0,    34,     0,    28,    30,     0,
      93,    86,    24,    80,    39,    26,     0,    27,    80,    29,
       0,    37,    32,    31,    40,    41,    80,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -60,   -60,   -60,   136,    61,   -60,   -60,   -59,   -14,   -31,
     -60,   -60,   -60,   -60,   -60,   -60,     8,   -60,   -60,   -60,
     -60,   -60,   -60,    -6,   -60,    -2,   -48,   -60,   -57,     7,
      10,    57,   -60,   -60,   -60,   -60,   -60,   -42,   -60,    -4,
      58,   -60,   -60,   -60,    30,   -60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,    25,   101,    26,    27,    28,     2,    29,
      30,    31,   156,   157,   167,   168,   158,   159,    32,    33,
      34,    35,   175,     4,   141,    36,    37,    38,    39,    40,
      41,    42,    43,    64,    44,    96,    97,    45,    46,    52,
      69,   108,   104,   105,   106,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    71,    53,    72,    94,    51,    89,    90,   103,    62,
      48,    65,    59,    63,    95,    98,    74,    75,     3,   114,
     115,   116,   117,   118,   119,    -2,   112,   113,    47,    73,
      47,   111,    -7,    84,    74,    75,   107,    74,    75,   128,
      91,    49,    82,    83,    47,    47,    85,    82,    83,   174,
     127,   132,   102,    93,    19,    20,    21,    56,     5,     6,
       7,     8,    57,     9,    10,    61,    54,    55,    15,    47,
      58,    82,    83,    60,    11,    67,    12,   103,    13,   155,
     166,    88,   146,    14,    68,    15,   124,    86,    47,   120,
     121,    87,    92,    16,   122,   123,   109,    99,   100,   110,
      17,   154,   170,    18,   125,   142,    19,    20,    21,    22,
      23,     9,    10,   126,     9,    10,   129,   130,   131,   143,
     134,   162,   135,   136,   138,   137,    13,   139,   144,    13,
     145,    14,   171,   148,    14,   152,   153,   173,   147,    47,
      50,    16,   150,   151,    16,   177,   107,   163,    47,   160,
     155,    18,   161,   165,    18,   164,   172,    22,    23,    47,
      22,    23,    66,   133,    47,   169,   149,   140,     0,   176,
       0,     0,    47,    76,    77,    78,    79,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,    83
};

static const yytype_int16 yycheck[] =
{
       4,    32,     8,    34,    61,     7,    48,    49,    67,    29,
      29,    25,    14,    33,    62,    63,    11,    12,     0,    76,
      77,    78,    79,    80,    81,     0,    74,    75,    32,    35,
      34,    73,    29,    27,    11,    12,    33,    11,    12,    30,
      35,    29,    38,    39,    48,    49,    40,    38,    39,    45,
      92,    99,    66,    30,    52,    53,    54,    35,     4,     5,
       6,     7,    35,     9,    10,    29,     9,    10,    31,    73,
      13,    38,    39,    16,    20,    29,    22,   136,    24,    47,
      48,    28,   130,    29,    49,    31,    88,    35,    92,    82,
      83,    35,    29,    39,    84,    85,    36,    33,    32,     3,
      46,   143,   159,    49,    35,   111,    52,    53,    54,    55,
      56,     9,    10,    30,     9,    10,    30,    36,    34,   125,
      49,   152,    30,    36,    33,    55,    24,    49,    30,    24,
      31,    29,   163,    33,    29,   141,   142,   168,    34,   143,
      35,    39,    34,    55,    39,   176,    33,    30,   152,    34,
      47,    49,    34,    32,    49,    35,    45,    55,    56,   163,
      55,    56,    26,   102,   168,   157,   136,   109,    -1,   175,
      -1,    -1,   176,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    68,     0,    83,     4,     5,     6,     7,     9,
      10,    20,    22,    24,    29,    31,    39,    46,    49,    52,
      53,    54,    55,    56,    62,    63,    65,    66,    67,    69,
      70,    71,    78,    79,    80,    81,    85,    86,    87,    88,
      89,    90,    91,    92,    94,    97,    98,    99,    29,    29,
      35,    85,    99,    83,    91,    91,    35,    35,    91,    85,
      91,    29,    29,    33,    93,    68,    63,    29,    49,   100,
     105,    69,    69,    83,    11,    12,    13,    14,    15,    16,
      17,    18,    38,    39,    27,    40,    35,    35,    28,    97,
      97,    35,    29,    30,    88,    86,    95,    96,    86,    33,
      32,    64,    68,    67,   102,   103,   104,    33,   101,    36,
       3,    97,    86,    86,    88,    88,    88,    88,    88,    88,
      89,    89,    90,    90,    85,    35,    30,    97,    30,    30,
      36,    34,    86,    64,    49,    30,    36,    55,    33,    49,
     100,    84,    83,    83,    30,    31,    86,    34,    33,   104,
      34,    55,    83,    83,    97,    47,    72,    73,    76,    77,
      34,    34,    69,    30,    35,    32,    48,    74,    75,    76,
      88,    69,    45,    69,    45,    82,    83,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    63,    64,    65,    66,    67,    67,
      67,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    70,    71,    72,    72,    73,
      73,    74,    75,    76,    77,    78,    79,    79,    80,    81,
      82,    83,    84,    85,    85,    85,    86,    86,    87,    87,
      87,    87,    87,    87,    88,    88,    88,    89,    89,    89,
      90,    91,    91,    91,    91,    91,    92,    92,    92,    92,
      92,    93,    93,    94,    95,    95,    96,    96,    97,    97,
      97,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   105,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     1,     1,     4,     2,     1,     1,
       1,     3,     0,     2,     2,     2,     2,     3,     1,     1,
       2,     3,     1,     1,     6,     2,     7,     2,     1,     2,
       1,     2,     2,     6,     1,     4,     2,     7,     5,     7,
       0,     0,     0,     3,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     1,     3,
       1,     4,     3,     4,     1,     0,     3,     1,     3,     1,
       0,     2,     1,     2,     1,     2,     4,     3,     1,     0,
       3,     1,     2,     4,     3,     1
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
        case 3:
#line 106 "grammar.ypp" /* yacc.c:1646  */
    {
	string tag = func_end_tag.get_func_end_tag();
	intermediate_output.gen(tag);
	if(!((yyvsp[-1].statement_list_s)->continue_list.empty())){
		yyerror("unpatched continue statement left in the function\nAborting");
		exit(1);
	}
	if(!((yyvsp[-1].statement_list_s)->break_list.empty())){
		yyerror("unpatched break statement left in the function\nAborting");
		exit(1);
	}
	//intermediate_output.patch_tag_no_put(tag,$3->break_list,intermediate_output.get_next()-1);
	intermediate_output.patch_tag_no_put(tag,(yyvsp[-1].statement_list_s)->next,intermediate_output.get_next()-1);
	intermediate_output.gen_special("func","end","---","---");
	active_function_index = 0;
}
#line 1469 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 124 "grammar.ypp" /* yacc.c:1646  */
    { level++;}
#line 1475 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 128 "grammar.ypp" /* yacc.c:1646  */
    {
symbol_table.clear_var_list(active_function_index,level);
level--;
}
#line 1484 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 137 "grammar.ypp" /* yacc.c:1646  */
    {
    string s((yyvsp[0].name));
		if(s == "main"){
		 main_flag = true;
		}
    if(symbol_table.search_func(s) != -1){
      (yyval.result_s) = new result_(ERROR_TYPE);
      yyerror("this function is declared previously.Aborting at ");
			exit(0);
      active_function_index = -1;
    }
    else{
        (yyval.result_s) = new result_((yyvsp[-1].type_s)->type);
        active_function_index = symbol_table.add_function(s,(yyvsp[-1].type_s)->type);
        level = 1;
        string new_s = "func_" + s + ":";
        intermediate_output.gen(new_s);
				intermediate_output.gen_special("func","begin",s,"---");
    }
}
#line 1509 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 159 "grammar.ypp" /* yacc.c:1646  */
    {(yyval.type_s) = new type_(INT_TYPE);}
#line 1515 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 160 "grammar.ypp" /* yacc.c:1646  */
    {(yyval.type_s) = new type_(FLOAT_TYPE);}
#line 1521 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 161 "grammar.ypp" /* yacc.c:1646  */
    {(yyval.type_s) = new type_(VOID_TYPE);}
#line 1527 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 165 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.statement_list_s) = new statement_list_((yyvsp[-2].statement_list_s)->can_appear_in_global);
	if(!((yyvsp[-2].statement_list_s)->next.empty())){
		string tag = condition_tag.get_conditional_tag();
		intermediate_output.patch_tag(tag,(yyvsp[-2].statement_list_s)->next,(yyvsp[-1].M_s)->position);
	}
	(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[0].statement_list_s)->next.begin(),(yyvsp[0].statement_list_s)->next.end());
	(yyval.statement_list_s)->break_list.insert((yyval.statement_list_s)->break_list.end(),(yyvsp[-2].statement_list_s)->break_list.begin(),(yyvsp[-2].statement_list_s)->break_list.end());
	(yyval.statement_list_s)->break_list.insert((yyval.statement_list_s)->break_list.end(),(yyvsp[0].statement_list_s)->break_list.begin(),(yyvsp[0].statement_list_s)->break_list.end());
	(yyval.statement_list_s)->continue_list.insert((yyval.statement_list_s)->continue_list.end(),(yyvsp[-2].statement_list_s)->continue_list.begin(),(yyvsp[-2].statement_list_s)->continue_list.end());
	(yyval.statement_list_s)->continue_list.insert((yyval.statement_list_s)->continue_list.end(),(yyvsp[0].statement_list_s)->continue_list.begin(),(yyvsp[0].statement_list_s)->continue_list.end());

}
#line 1545 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 179 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.statement_list_s) = new statement_list_(0);
	(yyval.statement_list_s)->next.clear();
	(yyval.statement_list_s)->break_list.clear();
	(yyval.statement_list_s)->continue_list.clear();
}
#line 1556 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 188 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.statement_list_s) = new statement_list_(0);
	(yyval.statement_list_s)->next.clear();
	(yyval.statement_list_s)->break_list.clear();
	(yyval.statement_list_s)->continue_list.clear();
}
#line 1567 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 196 "grammar.ypp" /* yacc.c:1646  */
    {
(yyval.statement_list_s) = new statement_list_(1);
(yyval.statement_list_s)->next.clear();
(yyval.statement_list_s)->break_list.push_back(intermediate_output.get_next());
intermediate_output.gen_special("goto","---","---","---");
(yyval.statement_list_s)->continue_list.clear();
}
#line 1579 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 204 "grammar.ypp" /* yacc.c:1646  */
    {
(yyval.statement_list_s) = new statement_list_(1);
(yyval.statement_list_s)->next.clear();
(yyval.statement_list_s)->continue_list.push_back(intermediate_output.get_next());
intermediate_output.gen_special("goto","---","---","---");
(yyval.statement_list_s)->break_list.clear();

}
#line 1592 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 213 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.statement_list_s) = new statement_list_(1);
	(yyval.statement_list_s)->next.clear();
	(yyval.statement_list_s)->break_list.clear();
	(yyval.statement_list_s)->continue_list.clear();
	intermediate_output.gen_special("return","---","---","---");
}
#line 1604 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 221 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.statement_list_s) = new statement_list_(1);
	(yyval.statement_list_s)->next.clear();
	(yyval.statement_list_s)->break_list.clear();
	(yyval.statement_list_s)->continue_list.clear();
	intermediate_output.gen_special("return",(yyvsp[-1].conditional_expression_s)->temporary_name,"---","---");
}
#line 1616 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 229 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.statement_list_s) = new statement_list_(1);
	(yyval.statement_list_s)->error = false;
	(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[0].statement_list_s)->next.begin(),(yyvsp[0].statement_list_s)->next.end());
	(yyval.statement_list_s)->break_list.insert((yyval.statement_list_s)->break_list.end(),(yyvsp[0].statement_list_s)->break_list.begin(),(yyvsp[0].statement_list_s)->break_list.end());
	(yyval.statement_list_s)->continue_list.insert((yyval.statement_list_s)->continue_list.end(),(yyvsp[0].statement_list_s)->continue_list.begin(),(yyvsp[0].statement_list_s)->continue_list.end());
	}
#line 1628 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 237 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.statement_list_s) = new statement_list_(1);
	(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[0].statement_list_s)->next.begin(),(yyvsp[0].statement_list_s)->next.end());
	(yyval.statement_list_s)->break_list.clear();
	(yyval.statement_list_s)->continue_list.clear();
}
#line 1639 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 244 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.statement_list_s) = new statement_list_(0);
	(yyval.statement_list_s)->next.clear();
	(yyval.statement_list_s)->break_list.clear();
	(yyval.statement_list_s)->continue_list.clear();
}
#line 1650 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 251 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.statement_list_s) = new statement_list_(0);
	(yyval.statement_list_s)->error = false;
	(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[-1].statement_list_s)->next.begin(),(yyvsp[-1].statement_list_s)->next.end());
	(yyval.statement_list_s)->break_list.insert((yyval.statement_list_s)->break_list.end(),(yyvsp[-1].statement_list_s)->break_list.begin(),(yyvsp[-1].statement_list_s)->break_list.end());
	(yyval.statement_list_s)->continue_list.insert((yyval.statement_list_s)->continue_list.end(),(yyvsp[-1].statement_list_s)->continue_list.begin(),(yyvsp[-1].statement_list_s)->continue_list.end());
}
#line 1662 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 259 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.statement_list_s) = new statement_list_(1);
	(yyval.statement_list_s)->error = false;
	(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[0].statement_list_s)->next.begin(),(yyvsp[0].statement_list_s)->next.end());
	(yyval.statement_list_s)->break_list.insert((yyval.statement_list_s)->break_list.end(),(yyvsp[0].statement_list_s)->break_list.begin(),(yyvsp[0].statement_list_s)->break_list.end());
	(yyval.statement_list_s)->continue_list.insert((yyval.statement_list_s)->continue_list.end(),(yyvsp[0].statement_list_s)->continue_list.begin(),(yyvsp[0].statement_list_s)->continue_list.end());
}
#line 1674 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 269 "grammar.ypp" /* yacc.c:1646  */
    {
	if(active_function_index != 0){
			yyerror("can not define function within a function\nAborting");
			exit(1);
	}
	(yyval.statement_list_s) = new statement_list_(2);
	(yyval.statement_list_s)->next.clear();
	(yyval.statement_list_s)->break_list.clear();
	(yyval.statement_list_s)->continue_list.clear();
}
#line 1689 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 282 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.statement_list_s)= new statement_list_(1);
	if(active_function_index <= 0){
			yyerror("can not define selection statement globally\nAborting");
			exit(1);
	}

	string tag = condition_tag.get_conditional_tag();
	intermediate_output.patch_tag(tag,(yyvsp[-5].ifexp_s)->false_list,(yyvsp[-1].M_s)->position);
	(yyval.statement_list_s)->break_list.insert((yyval.statement_list_s)->break_list.end(),(yyvsp[-4].statement_list_s)->break_list.begin(),(yyvsp[-4].statement_list_s)->break_list.end());
	(yyval.statement_list_s)->continue_list.insert((yyval.statement_list_s)->continue_list.end(),(yyvsp[-4].statement_list_s)->continue_list.begin(),(yyvsp[-4].statement_list_s)->continue_list.end());
	(yyval.statement_list_s)->break_list.insert((yyval.statement_list_s)->break_list.end(),(yyvsp[0].statement_list_s)->break_list.begin(),(yyvsp[0].statement_list_s)->break_list.end());
	(yyval.statement_list_s)->continue_list.insert((yyval.statement_list_s)->continue_list.end(),(yyvsp[0].statement_list_s)->continue_list.begin(),(yyvsp[0].statement_list_s)->continue_list.end());
	(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[-4].statement_list_s)->next.begin(),(yyvsp[-4].statement_list_s)->next.end());
	(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[0].statement_list_s)->next.begin(),(yyvsp[0].statement_list_s)->next.end());
	(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[-2].N_s)->next.begin(),(yyvsp[-2].N_s)->next.end());
}
#line 1711 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 300 "grammar.ypp" /* yacc.c:1646  */
    {
		(yyval.statement_list_s)= new statement_list_(1);
		if(active_function_index <= 0){
				yyerror("can not define selection statement globally\nAborting");
				exit(1);
		}
		(yyval.statement_list_s)->break_list.insert((yyval.statement_list_s)->break_list.end(),(yyvsp[0].statement_list_s)->break_list.begin(),(yyvsp[0].statement_list_s)->break_list.end());
		(yyval.statement_list_s)->continue_list.insert((yyval.statement_list_s)->continue_list.end(),(yyvsp[0].statement_list_s)->continue_list.begin(),(yyvsp[0].statement_list_s)->continue_list.end());
		(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[-1].ifexp_s)->false_list.begin(),(yyvsp[-1].ifexp_s)->false_list.end());
		(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[0].statement_list_s)->next.begin(),(yyvsp[0].statement_list_s)->next.end());
}
#line 1727 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 314 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.statement_list_s) = new statement_list_(1);
	(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[-1].case_list_s)->break_list.begin(),(yyvsp[-1].case_list_s)->break_list.end());
	(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[-1].case_list_s)->next.begin(),(yyvsp[-1].case_list_s)->next.end());
	(yyval.statement_list_s)->break_list.clear();
	(yyval.statement_list_s)->continue_list.insert((yyval.statement_list_s)->continue_list.end(),(yyvsp[-1].case_list_s)->continue_list.begin(),(yyvsp[-1].case_list_s)->continue_list.end());
	if(active_function_index <= 0){
			yyerror("can not define  selection statement globally\nAborting");
			exit(1);
	}
 	intermediate_output.patch_switch_con((yyvsp[-4].conditional_expression_s)->temporary_name,(yyvsp[-1].case_list_s)->false_list);
}
#line 1744 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 328 "grammar.ypp" /* yacc.c:1646  */
    {
	string patch_address_1 = condition_tag.get_conditional_tag();

	//cout<<patch_address_1 << "   "<<patch_address_2 <<endl;
	intermediate_output.patch_tag(patch_address_1,(yyvsp[-1].case_list_s)->next,(yyvsp[0].case_list_s)->second_address); // same 1st address
	vector<int> temp_index;
	if(!((yyvsp[-1].case_list_s)->false_list.empty())) temp_index.push_back((yyvsp[-1].case_list_s)->false_list.back());
	intermediate_output.patch_tag(patch_address_1,temp_index,(yyvsp[0].case_list_s)->first_address);

	(yyval.case_list_s) = new case_list_((yyvsp[0].case_list_s)->first_address,(yyvsp[0].case_list_s)->second_address);
	(yyval.case_list_s)->false_list.insert((yyval.case_list_s)->false_list.end(),(yyvsp[-1].case_list_s)->false_list.begin(),(yyvsp[-1].case_list_s)->false_list.end());
	(yyval.case_list_s)->false_list.insert((yyval.case_list_s)->false_list.end(),(yyvsp[0].case_list_s)->false_list.begin(),(yyvsp[0].case_list_s)->false_list.end());
	(yyval.case_list_s)->next.insert((yyval.case_list_s)->next.end(),(yyvsp[0].case_list_s)->next.begin(),(yyvsp[0].case_list_s)->next.end());
	(yyval.case_list_s)->break_list.insert((yyval.case_list_s)->break_list.end(),(yyvsp[-1].case_list_s)->break_list.begin(),(yyvsp[-1].case_list_s)->break_list.end());
	(yyval.case_list_s)->break_list.insert((yyval.case_list_s)->break_list.end(),(yyvsp[0].case_list_s)->break_list.begin(),(yyvsp[0].case_list_s)->break_list.end());
	(yyval.case_list_s)->continue_list.insert((yyval.case_list_s)->continue_list.end(),(yyvsp[-1].case_list_s)->continue_list.begin(),(yyvsp[-1].case_list_s)->continue_list.end());
	(yyval.case_list_s)->continue_list.insert((yyval.case_list_s)->continue_list.end(),(yyvsp[0].case_list_s)->continue_list.begin(),(yyvsp[0].case_list_s)->continue_list.end());
}
#line 1767 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 347 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.case_list_s) = new case_list_((yyvsp[0].case_list_s)->first_address,(yyvsp[0].case_list_s)->second_address);
	(yyval.case_list_s)->false_list.insert((yyval.case_list_s)->false_list.end(),(yyvsp[0].case_list_s)->false_list.begin(),(yyvsp[0].case_list_s)->false_list.end());
	(yyval.case_list_s)->break_list.insert((yyval.case_list_s)->break_list.end(),(yyvsp[0].case_list_s)->break_list.begin(),(yyvsp[0].case_list_s)->break_list.end());
	(yyval.case_list_s)->continue_list.insert((yyval.case_list_s)->continue_list.end(),(yyvsp[0].case_list_s)->continue_list.begin(),(yyvsp[0].case_list_s)->continue_list.end());
	(yyval.case_list_s)->next.insert((yyval.case_list_s)->next.end(),(yyvsp[0].case_list_s)->next.begin(),(yyvsp[0].case_list_s)->next.end());
	// special case to handle last false list
	if(!((yyval.case_list_s)->false_list.empty())){
		(yyval.case_list_s)->next.push_back((yyval.case_list_s)->false_list.back());
	}
}
#line 1783 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 361 "grammar.ypp" /* yacc.c:1646  */
    {
	string patch_address_1 = condition_tag.get_conditional_tag();
	string patch_address_2 = condition_tag.get_conditional_tag();
  intermediate_output.patch_tag(patch_address_2,(yyvsp[-1].case_list_s)->next,(yyvsp[0].case_list_s)->second_address);
	vector<int> temp_index;
	if(!((yyvsp[-1].case_list_s)->false_list.empty())) temp_index.push_back((yyvsp[-1].case_list_s)->false_list.back());
	intermediate_output.patch_tag(patch_address_1,temp_index,(yyvsp[0].case_list_s)->first_address);


	(yyval.case_list_s) = new case_list_((yyvsp[0].case_list_s)->first_address,(yyvsp[0].case_list_s)->second_address);
	(yyval.case_list_s)->false_list.insert((yyval.case_list_s)->false_list.end(),(yyvsp[-1].case_list_s)->false_list.begin(),(yyvsp[-1].case_list_s)->false_list.end());
	(yyval.case_list_s)->false_list.insert((yyval.case_list_s)->false_list.end(),(yyvsp[0].case_list_s)->false_list.begin(),(yyvsp[0].case_list_s)->false_list.end());
	(yyval.case_list_s)->next.insert((yyval.case_list_s)->next.end(),(yyvsp[0].case_list_s)->next.begin(),(yyvsp[0].case_list_s)->next.end());
	(yyval.case_list_s)->break_list.insert((yyval.case_list_s)->break_list.end(),(yyvsp[-1].case_list_s)->break_list.begin(),(yyvsp[-1].case_list_s)->break_list.end());
	(yyval.case_list_s)->break_list.insert((yyval.case_list_s)->break_list.end(),(yyvsp[0].case_list_s)->break_list.begin(),(yyvsp[0].case_list_s)->break_list.end());
	(yyval.case_list_s)->continue_list.insert((yyval.case_list_s)->continue_list.end(),(yyvsp[-1].case_list_s)->continue_list.begin(),(yyvsp[-1].case_list_s)->continue_list.end());
	(yyval.case_list_s)->continue_list.insert((yyval.case_list_s)->continue_list.end(),(yyvsp[0].case_list_s)->continue_list.begin(),(yyvsp[0].case_list_s)->continue_list.end());
}
#line 1806 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 381 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.case_list_s) = new case_list_ ((yyvsp[0].case_list_s)->first_address,(yyvsp[0].case_list_s)->second_address);
	(yyval.case_list_s)->false_list.insert((yyval.case_list_s)->false_list.end(),(yyvsp[0].case_list_s)->false_list.begin(),(yyvsp[0].case_list_s)->false_list.end());
	(yyval.case_list_s)->next.insert((yyval.case_list_s)->next.end(),(yyvsp[0].case_list_s)->next.begin(),(yyvsp[0].case_list_s)->next.end());
	(yyval.case_list_s)->break_list.insert((yyval.case_list_s)->break_list.end(),(yyvsp[0].case_list_s)->break_list.begin(),(yyvsp[0].case_list_s)->break_list.end());
	(yyval.case_list_s)->continue_list.insert((yyval.case_list_s)->continue_list.end(),(yyvsp[0].case_list_s)->continue_list.begin(),(yyvsp[0].case_list_s)->continue_list.end());
}
#line 1818 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 391 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.case_list_s) = new case_list_((yyvsp[-1].case_name_s)->first_address,(yyvsp[-1].case_name_s)->first_address);
	(yyval.case_list_s)->false_list.clear();
	int normal_jump = intermediate_output.get_next();
	intermediate_output.gen_special("goto","---","---","---");
	(yyval.case_list_s)->next.insert((yyval.case_list_s)->next.end(),(yyvsp[0].statement_list_s)->next.begin(),(yyvsp[0].statement_list_s)->next.end());
	(yyval.case_list_s)->next.push_back(normal_jump);
	(yyval.case_list_s)->break_list.insert((yyval.case_list_s)->break_list.end(),(yyvsp[0].statement_list_s)->break_list.begin(),(yyvsp[0].statement_list_s)->break_list.end());
	(yyval.case_list_s)->false_list.clear();
	(yyval.case_list_s)->continue_list.insert((yyval.case_list_s)->continue_list.end(),(yyvsp[0].statement_list_s)->continue_list.begin(),(yyvsp[0].statement_list_s)->continue_list.end());
}
#line 1834 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 404 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.case_name_s) = new case_name_(intermediate_output.get_next());
	intermediate_output.gen("");
}
#line 1843 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 411 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.case_list_s) = new case_list_((yyvsp[-5].case_name_s)->first_address,(yyvsp[-1].M_s)->position);
	(yyval.case_list_s)->false_list.push_back((yyvsp[-2].M_s)->position);
	intermediate_output.back_patch_special("!=",(yyvsp[-4].conditional_expression_s)->temporary_name,"---","---",(yyvsp[-2].M_s)->position);

	int normal_jump = intermediate_output.get_next();
	intermediate_output.gen_special("goto","---","---","---");
	(yyval.case_list_s)->next.insert((yyval.case_list_s)->next.end(),(yyvsp[0].statement_list_s)->next.begin(),(yyvsp[0].statement_list_s)->next.end());
	(yyval.case_list_s)->next.push_back(normal_jump);
	(yyval.case_list_s)->break_list.insert((yyval.case_list_s)->break_list.end(),(yyvsp[0].statement_list_s)->break_list.begin(),(yyvsp[0].statement_list_s)->break_list.end());
	(yyval.case_list_s)->continue_list.insert((yyval.case_list_s)->continue_list.end(),(yyvsp[0].statement_list_s)->continue_list.begin(),(yyvsp[0].statement_list_s)->continue_list.end());
}
#line 1860 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 425 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.case_name_s) = new case_name_(intermediate_output.get_next());
	intermediate_output.gen("");
}
#line 1869 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 433 "grammar.ypp" /* yacc.c:1646  */
    {
	if((yyvsp[-1].assignment_statement_s)->type!= ERROR_TYPE){
		(yyval.ifexp_s) = new ifexp_(intermediate_output.get_next());
		intermediate_output.gen_special("==",(yyvsp[-1].assignment_statement_s)->temporary_var_name,"0","---");
	}
	else{
		(yyval.ifexp_s) = new ifexp_(-1);
		yyerror("unknown expression in used with if\nAborting");
		exit(1);
	}
}
#line 1885 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 448 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.statement_list_s) = new statement_list_(1);
	string tag = loop_tag.get_loop_tag();
	intermediate_output.patch_tag(tag,(yyvsp[0].statement_list_s)->next,(yyvsp[-1].loopexp_s)->jump_back_address);
	intermediate_output.patch_tag_no_put(tag,(yyvsp[0].statement_list_s)->continue_list,(yyvsp[-1].loopexp_s)->jump_back_address);
	intermediate_output.gen_special("goto","---","---",tag);
	(yyval.statement_list_s)->break_list.clear();
	(yyval.statement_list_s)->continue_list.clear();
	(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[-1].loopexp_s)->false_list.begin(),(yyvsp[-1].loopexp_s)->false_list.end());
	(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[0].statement_list_s)->break_list.begin(),(yyvsp[0].statement_list_s)->break_list.end());

}
#line 1902 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 461 "grammar.ypp" /* yacc.c:1646  */
    {
	if((yyvsp[-4].assignment_statement_s)->type == ERROR_TYPE){
		yyerror("unknown expression is used with while\nAborting");
		exit(1);
	}
	(yyval.statement_list_s) = new statement_list_(1);
	string tag = loop_tag.get_loop_tag();
	intermediate_output.patch_tag(tag,(yyvsp[0].statement_list_s)->next,(yyvsp[-5].M_s)->position);
	intermediate_output.patch_tag_no_put(tag,(yyvsp[0].statement_list_s)->continue_list,(yyvsp[-5].M_s)->position);
	intermediate_output.gen_special("goto","---","---",tag);
	(yyval.statement_list_s)->break_list.clear();
	(yyval.statement_list_s)->continue_list.clear();
	string tag1 = loop_tag.get_loop_tag();
	intermediate_output.put_tag((yyvsp[-6].loopexp_s)->jump_back_address,tag1);
	intermediate_output.gen_at_pos("goto --- --- "+tag1,(yyvsp[-3].M_s)->position);
 	string tag2 = loop_tag.get_loop_tag();
	vector<int> temp;
	if(!((yyvsp[-6].loopexp_s)->false_list.empty())){
		temp.push_back(*((yyvsp[-6].loopexp_s)->false_list.begin()) + 1);
		intermediate_output.patch_tag(tag2,temp,(yyvsp[-2].M_s)->position);
	}
	(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[-6].loopexp_s)->false_list.begin(),(yyvsp[-6].loopexp_s)->false_list.end());
	(yyval.statement_list_s)->next.insert((yyval.statement_list_s)->next.end(),(yyvsp[0].statement_list_s)->break_list.begin(),(yyvsp[0].statement_list_s)->break_list.end());
}
#line 1931 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 488 "grammar.ypp" /* yacc.c:1646  */
    {
	if(active_function_index <= 0){
		yyerror("can not define loops globally\nAborting");
		exit(1);
	}
	if((yyvsp[-1].assignment_statement_s)->type != ERROR_TYPE){
		(yyval.loopexp_s) = new loopexp_(intermediate_output.get_next(),(yyvsp[-3].M_s)->position);
		intermediate_output.gen_special("==",(yyvsp[-1].assignment_statement_s)->temporary_var_name,"0","---");
	}
	else{
		yyerror("unknown expression is used with while\nAborting");
		exit(1);
	}
}
#line 1950 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 505 "grammar.ypp" /* yacc.c:1646  */
    {
	if(active_function_index <= 0){
		yyerror("can not define loops globally\nAborting");
		exit(1);
	}
	if((yyvsp[-4].assignment_statement_s)->type != ERROR_TYPE && (yyvsp[-1].assignment_statement_s)->type != ERROR_TYPE){
		(yyval.loopexp_s) = new loopexp_ (intermediate_output.get_next(),(yyvsp[-2].M_s)->position);
		intermediate_output.gen_special("==",(yyvsp[-1].assignment_statement_s)->temporary_var_name,"0","---");
		intermediate_output.gen_special("goto","---","---","---");
	}
	else{
		yyerror("unknown expression is used with for\nAborting");
		exit(1);
	}
}
#line 1970 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 524 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.M_s) = new M_(intermediate_output.get_next());
	intermediate_output.gen("");
}
#line 1979 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 530 "grammar.ypp" /* yacc.c:1646  */
    {
 (yyval.M_s) = new M_(intermediate_output.get_next());
 intermediate_output.gen("");
}
#line 1988 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 537 "grammar.ypp" /* yacc.c:1646  */
    {
(yyval.N_s) = new N_ (intermediate_output.get_next());
intermediate_output.gen_special("goto","---","---","---");
}
#line 1997 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 544 "grammar.ypp" /* yacc.c:1646  */
    {
if((yyvsp[-2].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to use and operator with a void data type");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[-2].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[-2].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to use and operator with a pointer");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to use and operator with a void data type");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to use and operator with a pointer");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
 	int temp_type = get_compatible_type_bool_only((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
 	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
 	std::ostringstream out;
 	if(temp_type != ERROR_TYPE){
		intermediate_output.gen_special("&&",(yyvsp[-2].conditional_expression_s)->temporary_name,(yyvsp[0].conditional_expression_s)->temporary_name,(yyval.conditional_expression_s)->temporary_name);
 	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type != ERROR_TYPE && (yyvsp[0].conditional_expression_s)->type != ERROR_TYPE){
				yyerror("Expected boolean data types for both operand");
		}
	}
}
#line 2031 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 574 "grammar.ypp" /* yacc.c:1646  */
    {
if((yyvsp[-2].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to use or operator with a void data type");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[-2].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[-2].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to use or operator with a pointer");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to use or operator with a void data type");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to use or operator with a pointer");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
 	int temp_type = get_compatible_type_bool_only((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
 	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
 	std::ostringstream out;
 	if(temp_type != ERROR_TYPE){
	 	intermediate_output.gen_special("&&",(yyvsp[-2].conditional_expression_s)->temporary_name,(yyvsp[0].conditional_expression_s)->temporary_name,(yyval.conditional_expression_s)->temporary_name);
 	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type != ERROR_TYPE && (yyvsp[0].conditional_expression_s)->type != ERROR_TYPE){
				yyerror("Expected boolean data types for both operand");
		}
	}
}
#line 2065 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 605 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->temporary_name);
}
#line 2073 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 612 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->temporary_name);
}
#line 2081 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 616 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->temporary_name);
}
#line 2089 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 622 "grammar.ypp" /* yacc.c:1646  */
    {
if((yyvsp[-2].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to compare a void data type");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[-2].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[-2].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to compare a pointer");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to compare a void data type");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to compare a pointer");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
	int temp_type = get_compatible_type_rel_op((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		intermediate_output.gen_relational_op(">",(yyvsp[-2].conditional_expression_s)->temporary_name,(yyvsp[0].conditional_expression_s)->temporary_name,(yyval.conditional_expression_s)->temporary_name);
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
#line 2129 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 660 "grammar.ypp" /* yacc.c:1646  */
    {
if((yyvsp[-2].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to compare a void data type");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[-2].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[-2].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to compare a pointer");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to compare a void data type");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to compare a pointer");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
	int temp_type = get_compatible_type_rel_op((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
	intermediate_output.gen_relational_op("<",(yyvsp[-2].conditional_expression_s)->temporary_name,(yyvsp[0].conditional_expression_s)->temporary_name,(yyval.conditional_expression_s)->temporary_name);
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
#line 2169 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 697 "grammar.ypp" /* yacc.c:1646  */
    {
if((yyvsp[-2].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to compare a void data type");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[-2].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[-2].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to compare a pointer");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to compare a void data type");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to compare a pointer");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
	int temp_type = get_compatible_type_rel_op((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		intermediate_output.gen_relational_op(">=",(yyvsp[-2].conditional_expression_s)->temporary_name,(yyvsp[0].conditional_expression_s)->temporary_name,(yyval.conditional_expression_s)->temporary_name);
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
#line 2209 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 734 "grammar.ypp" /* yacc.c:1646  */
    {
if((yyvsp[-2].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to compare a void data type");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[-2].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[-2].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to compare a pointer");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to compare a void data type");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to compare a pointer");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
	int temp_type = get_compatible_type_rel_op((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		intermediate_output.gen_relational_op("<=",(yyvsp[-2].conditional_expression_s)->temporary_name,(yyvsp[0].conditional_expression_s)->temporary_name,(yyval.conditional_expression_s)->temporary_name);
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
#line 2249 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 770 "grammar.ypp" /* yacc.c:1646  */
    {
if((yyvsp[-2].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to compare a void data type");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[-2].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[-2].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to compare a pointer");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to compare a void data type");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to compare a pointer");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
	int temp_type = get_compatible_type_rel_op((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
	intermediate_output.gen_relational_op("==",(yyvsp[-2].conditional_expression_s)->temporary_name,(yyvsp[0].conditional_expression_s)->temporary_name,(yyval.conditional_expression_s)->temporary_name);
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
#line 2289 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 806 "grammar.ypp" /* yacc.c:1646  */
    {
if((yyvsp[-2].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to compare a void data type");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[-2].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[-2].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to compare a pointer");
	(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == VOID_TYPE){
	yyerror("Trying to compare a void data type");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
if((yyvsp[0].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].conditional_expression_s)->type == INT_ADDRESS_TYPE){
	yyerror("Trying to compare a pointer");
	(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
}
	int temp_type = get_compatible_type_rel_op((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		intermediate_output.gen_relational_op("!=",(yyvsp[-2].conditional_expression_s)->temporary_name,(yyvsp[0].conditional_expression_s)->temporary_name,(yyval.conditional_expression_s)->temporary_name);
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
#line 2328 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 843 "grammar.ypp" /* yacc.c:1646  */
    {
	if((yyvsp[-2].conditional_expression_s)->type == VOID_TYPE){
		yyerror("Trying to add a void data type");
		(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[-2].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[-2].conditional_expression_s)->type == INT_ADDRESS_TYPE){
		yyerror("Trying to add a pointer");
		(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[0].conditional_expression_s)->type == VOID_TYPE){
		yyerror("Trying to add a void data type");
		(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[0].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].conditional_expression_s)->type == INT_ADDRESS_TYPE){
		yyerror("Trying to add a pointer");
		(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
	}

	int temp_type = get_compatible_type_non_bool((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		intermediate_output.gen_special("+",(yyvsp[-2].conditional_expression_s)->temporary_name,(yyvsp[0].conditional_expression_s)->temporary_name,(yyval.conditional_expression_s)->temporary_name);

	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type == BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type == BOOL_TYPE){
			yyerror("Trying to add with a boolean data type");
		}
	}
}
#line 2364 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 875 "grammar.ypp" /* yacc.c:1646  */
    {
	if((yyvsp[-2].conditional_expression_s)->type == VOID_TYPE){
		yyerror("Trying to subtract a void data type");
		(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[-2].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[-2].conditional_expression_s)->type == INT_ADDRESS_TYPE){
		yyerror("Trying to subtract a pointer");
		(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[0].conditional_expression_s)->type == VOID_TYPE){
		yyerror("Trying to subtract a void data type");
		(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[0].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].conditional_expression_s)->type == INT_ADDRESS_TYPE){
		yyerror("Trying to subtract a pointer");
		(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
	}
	int temp_type = get_compatible_type_non_bool((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		intermediate_output.gen_special("-",(yyvsp[-2].conditional_expression_s)->temporary_name,(yyvsp[0].conditional_expression_s)->temporary_name,(yyval.conditional_expression_s)->temporary_name);
	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type == BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type == BOOL_TYPE){
			yyerror("Trying to subtract with a boolean data type");
		}
	}
}
#line 2398 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 906 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->temporary_name);
}
#line 2406 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 913 "grammar.ypp" /* yacc.c:1646  */
    {
	if((yyvsp[-2].conditional_expression_s)->type == VOID_TYPE){
		yyerror("Trying to multiply a void data type");
		(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[-2].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[-2].conditional_expression_s)->type == INT_ADDRESS_TYPE){
		yyerror("Trying to multiply a pointer");
		(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[0].conditional_expression_s)->type == VOID_TYPE){
		yyerror("Trying to multiply a void data type");
		(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[0].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].conditional_expression_s)->type == INT_ADDRESS_TYPE){
		yyerror("Trying to multiply a pointer");
		(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
	}
	int temp_type = get_compatible_type_non_bool((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		intermediate_output.gen_special("*",(yyvsp[-2].conditional_expression_s)->temporary_name,(yyvsp[0].conditional_expression_s)->temporary_name,(yyval.conditional_expression_s)->temporary_name);
	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type == BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type == BOOL_TYPE){
			yyerror("Trying to multiply with a boolean data type");
		}
	}
}
#line 2440 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 943 "grammar.ypp" /* yacc.c:1646  */
    {
	if((yyvsp[-2].conditional_expression_s)->type == VOID_TYPE){
		yyerror("Trying to divide a void data type");
		(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[-2].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[-2].conditional_expression_s)->type == INT_ADDRESS_TYPE){
		yyerror("Trying to divide a pointer");
		(yyvsp[-2].conditional_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[0].conditional_expression_s)->type == VOID_TYPE){
		yyerror("Trying to divide a void data type");
		(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[0].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].conditional_expression_s)->type == INT_ADDRESS_TYPE){
		yyerror("Trying to divide a pointer");
		(yyvsp[0].conditional_expression_s)->type = ERROR_TYPE;
	}
	int temp_type = get_compatible_type_non_bool((yyvsp[-2].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->type);
	(yyval.conditional_expression_s) = new conditional_expression_(temp_type);
	std::ostringstream out;
	if(temp_type != ERROR_TYPE){
		intermediate_output.gen_special("/",(yyvsp[-2].conditional_expression_s)->temporary_name,(yyvsp[0].conditional_expression_s)->temporary_name,(yyval.conditional_expression_s)->temporary_name);
	}
	else{
		if((yyvsp[-2].conditional_expression_s)->type == BOOL_TYPE &&  (yyvsp[0].conditional_expression_s)->type == BOOL_TYPE){
		 	yyerror("Trying to divide with a boolean data type");
		}
	}
}
#line 2474 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 974 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->temporary_name);

}
#line 2483 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 982 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.conditional_expression_s) = new conditional_expression_((yyvsp[0].unary_expression_s)->type,(yyvsp[0].unary_expression_s)->temporary_name);
}
#line 2491 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 988 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.unary_expression_s) = new unary_expression_((yyvsp[0].unary_expression_s)->type,(yyvsp[0].unary_expression_s)->temporary_name);
	(yyval.unary_expression_s)->var = (yyvsp[0].unary_expression_s)->var;
}
#line 2500 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 993 "grammar.ypp" /* yacc.c:1646  */
    {
	if((yyvsp[0].unary_expression_s)->type == VOID_TYPE){
		yyerror("Trying to negate a void data type");
		(yyvsp[0].unary_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[0].unary_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].unary_expression_s)->type == INT_ADDRESS_TYPE){
	 	yyerror("Trying to negate a pointer");
	 	(yyvsp[0].unary_expression_s)->type = ERROR_TYPE;
 	}
	if((yyvsp[0].unary_expression_s)->type != BOOL_TYPE){
		(yyval.unary_expression_s) = new unary_expression_((yyvsp[0].unary_expression_s)->type);
		(yyval.unary_expression_s)->var = (yyvsp[0].unary_expression_s)->var;
		std::ostringstream out;
		if((yyvsp[0].unary_expression_s)->type != ERROR_TYPE ){
			intermediate_output.gen_special("UMINUS",(yyvsp[0].unary_expression_s)->temporary_name,"---",(yyval.unary_expression_s)->temporary_name);
		}
	}
	else{
		yyerror("Trying to negate a boolean data type");
		(yyval.unary_expression_s) = new unary_expression_(ERROR_TYPE);
		(yyval.unary_expression_s)->var = NULL;
	}
}
#line 2528 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 1017 "grammar.ypp" /* yacc.c:1646  */
    {
	std::ostringstream out;
	if((yyvsp[0].unary_expression_s)->type == VOID_TYPE){
		yyerror("can not use not operator on void data type");
		(yyvsp[0].unary_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[0].unary_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].unary_expression_s)->type == INT_ADDRESS_TYPE){
		yyerror("can not use not operator on pointers");
		(yyvsp[0].unary_expression_s)->type = ERROR_TYPE;
	}

	if((yyvsp[0].unary_expression_s)->type == FLOAT_TYPE  || (yyvsp[0].unary_expression_s)->type == INT_TYPE ){
		(yyval.unary_expression_s) = new unary_expression_(ERROR_TYPE);
		yyerror("can not use not operator on a float or int data type");
		(yyval.unary_expression_s)->var = NULL;
	}
	else{
				(yyval.unary_expression_s) = new unary_expression_((yyvsp[0].unary_expression_s)->type);
				(yyval.unary_expression_s)->var = (yyvsp[0].unary_expression_s)->var;
		}
	if((yyvsp[0].unary_expression_s)->type != ERROR_TYPE && (yyvsp[0].unary_expression_s)->type != FLOAT_TYPE && (yyvsp[0].unary_expression_s)->type != INT_TYPE ){
			intermediate_output.gen_special("NOT",(yyvsp[0].unary_expression_s)->temporary_name,"---",(yyval.unary_expression_s)->temporary_name);

	}
}
#line 2558 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 1043 "grammar.ypp" /* yacc.c:1646  */
    {
	if((yyvsp[0].unary_expression_s)->type == VOID_TYPE){
		yyerror("Trying to decrement a void data type");
		(yyvsp[0].unary_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[0].unary_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].unary_expression_s)->type == INT_ADDRESS_TYPE){
		yyerror("decrementing pointers not allowed");
		(yyvsp[0].unary_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[0].unary_expression_s)->type != BOOL_TYPE && (yyvsp[0].unary_expression_s)->type != FLOAT_TYPE){
		(yyval.unary_expression_s) = new unary_expression_((yyvsp[0].unary_expression_s)->type);
		(yyval.unary_expression_s)->var = (yyvsp[0].unary_expression_s)->var;
		std::ostringstream out;
		if((yyvsp[0].unary_expression_s)->type != ERROR_TYPE){
			intermediate_output.gen_special("-",(yyvsp[0].unary_expression_s)->temporary_name,"1",(yyval.unary_expression_s)->temporary_name);
			intermediate_output.gen_special("=",(yyval.unary_expression_s)->temporary_name,"---",(yyvsp[0].unary_expression_s)->temporary_name);
			(yyval.unary_expression_s)->temporary_name = (yyvsp[0].unary_expression_s)->temporary_name;
			if((yyvsp[0].unary_expression_s)->var != NULL){
				intermediate_output.gen_special("=",(yyvsp[0].unary_expression_s)->temporary_name,"---",(yyvsp[0].unary_expression_s)->var->name+"_"+to_string((yyvsp[0].unary_expression_s)->var->offset));
			}
		}
	}
	else{
		yyerror("Trying to decrement a boolean or float data type");
		(yyval.unary_expression_s) = new unary_expression_(ERROR_TYPE);
		(yyval.unary_expression_s)->var = NULL;
	}

}
#line 2592 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 1073 "grammar.ypp" /* yacc.c:1646  */
    {
	if((yyvsp[0].unary_expression_s)->type == VOID_TYPE){
		yyerror("Trying to increment a void data type");
		(yyvsp[0].unary_expression_s)->type = ERROR_TYPE;
	}
	if((yyvsp[0].unary_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].unary_expression_s)->type == INT_ADDRESS_TYPE){
		yyerror("incrementing pointers not allowed");
		(yyvsp[0].unary_expression_s)->type = ERROR_TYPE;
	}

	if((yyvsp[0].unary_expression_s)->type != BOOL_TYPE && (yyvsp[0].unary_expression_s)->type != FLOAT_TYPE){
		(yyval.unary_expression_s) = new unary_expression_((yyvsp[0].unary_expression_s)->type);
		(yyval.unary_expression_s)->var = (yyvsp[0].unary_expression_s)->var;
		std::ostringstream out;
		if((yyvsp[0].unary_expression_s)->type != ERROR_TYPE){
			intermediate_output.gen_special("+",(yyvsp[0].unary_expression_s)->temporary_name,"1",(yyval.unary_expression_s)->temporary_name);
			intermediate_output.gen_special("=",(yyval.unary_expression_s)->temporary_name,"---",(yyvsp[0].unary_expression_s)->temporary_name);
			(yyval.unary_expression_s)->temporary_name = (yyvsp[0].unary_expression_s)->temporary_name;
			if((yyvsp[0].unary_expression_s)->var != NULL ){
				intermediate_output.gen_special("=",(yyvsp[0].unary_expression_s)->temporary_name,"---",(yyvsp[0].unary_expression_s)->var->name+"_"+to_string((yyvsp[0].unary_expression_s)->var->offset));
			}
		}
	}
	else{
		yyerror("Trying to increment a boolean or float data type");
		(yyval.unary_expression_s) = new unary_expression_(ERROR_TYPE);
		(yyval.unary_expression_s)->var = NULL;
	}
}
#line 2626 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 1106 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.unary_expression_s) = new unary_expression_(INT_TYPE);
	intermediate_output.gen_special("=",to_string((yyvsp[0].integer_value)),"---",(yyval.unary_expression_s)->temporary_name);
	(yyval.unary_expression_s)->var = NULL;
}
#line 2636 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 1114 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.unary_expression_s) = new unary_expression_(FLOAT_TYPE);
	intermediate_output.gen_special("=",to_string((yyvsp[0].real_value)),"---",(yyval.unary_expression_s)->temporary_name);
	(yyval.unary_expression_s)->var = NULL;
}
#line 2646 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 1121 "grammar.ypp" /* yacc.c:1646  */
    {
/* don't put error msg here*/
if((yyvsp[0].id_arr_s)->var == NULL){
		//yyerror("The used variable is not declared");
		(yyval.unary_expression_s) = new unary_expression_(ERROR_TYPE);
		(yyval.unary_expression_s)->var = NULL;
}
else{
		(yyval.unary_expression_s) = new unary_expression_((yyvsp[0].id_arr_s)->var->eletype);
		std::ostringstream out;
		if((yyvsp[0].id_arr_s)->var->type == SIMPLE){
			out << "= " << (yyvsp[0].id_arr_s)->var->name <<"_"<< (yyvsp[0].id_arr_s)->var->offset << " --- " << (yyval.unary_expression_s)->temporary_name;
			(yyval.unary_expression_s)->var = (yyvsp[0].id_arr_s)->var;
		}
		else{
			string temp_address = "T" + to_string(global_temp);
			global_temp ++;
			intermediate_output.gen_special("addr",(yyvsp[0].id_arr_s)->var->name+"_"+to_string((yyvsp[0].id_arr_s)->var->offset),"---",temp_address);
			out << "= " <<temp_address<< "["<<(yyvsp[0].id_arr_s)->offset_temp<<"] " << (yyval.unary_expression_s)->temporary_name;
			(yyval.unary_expression_s)->var = (yyvsp[0].id_arr_s)->var;
		}
		string s = out.str();
		intermediate_output.gen(s);
}

}
#line 2677 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 1148 "grammar.ypp" /* yacc.c:1646  */
    {
  (yyval.unary_expression_s) = new unary_expression_((yyvsp[-1].conditional_expression_s)->type,(yyvsp[-1].conditional_expression_s)->temporary_name);
	(yyval.unary_expression_s)->var = NULL;
}
#line 2686 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 1153 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.unary_expression_s) = new unary_expression_ ((yyvsp[0].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->temporary_name);
	(yyval.unary_expression_s)->var = NULL;
}
#line 2695 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 1162 "grammar.ypp" /* yacc.c:1646  */
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
#line 2715 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 1178 "grammar.ypp" /* yacc.c:1646  */
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
#line 2734 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 1195 "grammar.ypp" /* yacc.c:1646  */
    {
 string s((yyvsp[-3].name));
 call_function_index = symbol_table.search_func(s);
 if(call_function_index != -1){
 		int temp_type = symbol_table.check_param_compatible(call_function_index,(yyvsp[-1].elist_func_call_s)->type_list); // this function prints error msgs
		if(temp_type != ERROR_TYPE){
			string result_func = symbol_table.genarate_function_call(call_function_index,(yyvsp[-1].elist_func_call_s));
			(yyval.conditional_expression_s) = new conditional_expression_(temp_type,result_func);
		}
		else{
			(yyval.conditional_expression_s) = new conditional_expression_(ERROR_TYPE,"ERR");
		}
 }
 else{
 		yyerror("function "+s+ " is not declared");
		(yyval.conditional_expression_s) = new conditional_expression_(ERROR_TYPE,"ERR");
 }
}
#line 2757 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 1216 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.elist_func_call_s) = new elist_func_call_();
	(yyval.elist_func_call_s)->type_list = (yyvsp[0].elist_func_call_s)->type_list;
	(yyval.elist_func_call_s)->name_list = (yyvsp[0].elist_func_call_s)->name_list;
}
#line 2767 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 1222 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.elist_func_call_s) = new elist_func_call_();
	(yyval.elist_func_call_s)->type_list.clear();
	(yyval.elist_func_call_s)->name_list.clear();
}
#line 2777 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 1230 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.elist_func_call_s) = new elist_func_call_();
	(yyval.elist_func_call_s)->type_list.insert((yyval.elist_func_call_s)->type_list.end(),(yyvsp[-2].elist_func_call_s)->type_list.begin(),(yyvsp[-2].elist_func_call_s)->type_list.end());
	(yyval.elist_func_call_s)->name_list.insert((yyval.elist_func_call_s)->name_list.end(),(yyvsp[-2].elist_func_call_s)->name_list.begin(),(yyvsp[-2].elist_func_call_s)->name_list.end());
	(yyval.elist_func_call_s)->type_list.push_back((yyvsp[0].conditional_expression_s)->type);
	(yyval.elist_func_call_s)->name_list.push_back((yyvsp[0].conditional_expression_s)->temporary_name);
}
#line 2789 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1238 "grammar.ypp" /* yacc.c:1646  */
    {
	(yyval.elist_func_call_s) = new elist_func_call_();
	(yyval.elist_func_call_s)->type_list.push_back((yyvsp[0].conditional_expression_s)->type);
	(yyval.elist_func_call_s)->name_list.push_back((yyvsp[0].conditional_expression_s)->temporary_name);
}
#line 2799 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1246 "grammar.ypp" /* yacc.c:1646  */
    { /* don't put error msg here */
	if((yyvsp[-2].id_arr_s)->var != NULL){
			if((yyvsp[-2].id_arr_s)->var->eletype == FLOAT_ADDRESS_TYPE || (yyvsp[-2].id_arr_s)->var->eletype == INT_ADDRESS_TYPE){
				yyerror("we don't support assigning pointers");
				(yyvsp[-2].id_arr_s)->var->eletype = ERROR_TYPE;
			}
			if((yyvsp[0].conditional_expression_s)->type == FLOAT_ADDRESS_TYPE || (yyvsp[0].conditional_expression_s)->type == INT_ADDRESS_TYPE){
				yyerror("we don't support assigning pointers");
				(yyvsp[-2].id_arr_s)->var->eletype = ERROR_TYPE;
			}
			if((yyvsp[-2].id_arr_s)->var->eletype == VOID_TYPE || (yyvsp[0].conditional_expression_s)->type == VOID_TYPE){
				yyerror("Trying to assign a void type");
				(yyvsp[-2].id_arr_s)->var->eletype = ERROR_TYPE;
			}
			int temp_type = get_compatible_type_non_bool((yyvsp[-2].id_arr_s)->var->eletype,(yyvsp[0].conditional_expression_s)->type);
			if(temp_type == ERROR_TYPE){
				if((yyvsp[-2].id_arr_s)->var->type != ERROR_TYPE && (yyvsp[0].conditional_expression_s)->type != ERROR_TYPE){
						yyerror("Incompatible data types are used for assignment");
				}
				(yyval.assignment_statement_s) = new assignment_statement_(ERROR_TYPE,"ERR");
			}
			else{
				if((yyvsp[-2].id_arr_s)->var->type == SIMPLE){
					if((yyvsp[-2].id_arr_s)->var->eletype == (yyvsp[0].conditional_expression_s)->type){
						intermediate_output.gen_special("=",(yyvsp[0].conditional_expression_s)->temporary_name,"---",(yyvsp[-2].id_arr_s)->var->name+"_"+to_string((yyvsp[-2].id_arr_s)->var->offset));
					}
					else{
					 	string temp;
						if((yyvsp[-2].id_arr_s)->var->eletype == FLOAT_TYPE && (yyvsp[0].conditional_expression_s)->type == INT_TYPE){
						 	temp = "F" + to_string(global_temp);
							global_temp++;
						}
						if((yyvsp[-2].id_arr_s)->var->eletype == INT_TYPE && (yyvsp[0].conditional_expression_s)->type == FLOAT_TYPE){
						 	temp = "T" + to_string(global_temp);
							global_temp++;
						}
						intermediate_output.gen_special("=",(yyvsp[0].conditional_expression_s)->temporary_name,"---",temp);
						intermediate_output.gen_special("=",temp,"---",(yyvsp[-2].id_arr_s)->var->name+"_"+to_string((yyvsp[-2].id_arr_s)->var->offset));
					}
					//intermediate_output.gen_special("=",$3->temporary_name,"---",$1->var->name+"_"+to_string($1->var->offset));
				}
				else{
					std::ostringstream out;
					string temp_address = "T" + to_string(global_temp);
					global_temp ++;
					if((yyvsp[-2].id_arr_s)->var->eletype == (yyvsp[0].conditional_expression_s)->type){
						intermediate_output.gen_special("addr",(yyvsp[-2].id_arr_s)->var->name+"_"+to_string((yyvsp[-2].id_arr_s)->var->offset),"---",temp_address);
						out << "= " << (yyvsp[0].conditional_expression_s)->temporary_name <<" " << temp_address<< "["<<(yyvsp[-2].id_arr_s)->offset_temp<<"] " ;
						string s_1 = out.str();
						intermediate_output.gen(s_1);
					}
					else{
						string temp;
						if((yyvsp[-2].id_arr_s)->var->eletype == FLOAT_TYPE && (yyvsp[0].conditional_expression_s)->type == INT_TYPE){
							temp = "F" + to_string(global_temp);
							global_temp++;
						}
						if((yyvsp[-2].id_arr_s)->var->eletype == INT_TYPE && (yyvsp[0].conditional_expression_s)->type == FLOAT_TYPE){
							temp = "T" + to_string(global_temp);
							global_temp++;
						}
						intermediate_output.gen_special("=",(yyvsp[0].conditional_expression_s)->temporary_name,"---",temp);
						intermediate_output.gen_special("addr",(yyvsp[-2].id_arr_s)->var->name+"_"+to_string((yyvsp[-2].id_arr_s)->var->offset),"---",temp_address);
						out << "= " << temp <<" " << temp_address<< "["<<(yyvsp[-2].id_arr_s)->offset_temp<<"] " ;
						string s_1 = out.str();
						intermediate_output.gen(s_1);
					}
			 }
				(yyval.assignment_statement_s) = new assignment_statement_(temp_type,"ERR");
			}
	}
	else{
			(yyval.assignment_statement_s) = new assignment_statement_(ERROR_TYPE,"ERR");
	}
}
#line 2879 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 1322 "grammar.ypp" /* yacc.c:1646  */
    {
		(yyval.assignment_statement_s) = new assignment_statement_((yyvsp[0].conditional_expression_s)->type,(yyvsp[0].conditional_expression_s)->temporary_name);
}
#line 2887 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1326 "grammar.ypp" /* yacc.c:1646  */
    {
// needs attention
	(yyval.assignment_statement_s) = new assignment_statement_(VOID_TYPE,"ERR");
}
#line 2896 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1334 "grammar.ypp" /* yacc.c:1646  */
    {
	if(active_function_index != -1 ){
		symbol_table.patch_variable(active_function_index,(yyvsp[0].varlist_s)->list_of_indexes,(yyvsp[-1].type_s)->type);
 	}
}
#line 2906 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1343 "grammar.ypp" /* yacc.c:1646  */
    {
	if(active_function_index != -1){
		string s((yyvsp[0].name));
		variable * var =symbol_table.search_variable_global(active_function_index,s,level);
		if(var == NULL){
			std::ostringstream out1;
			out1<<"varible with name "<<s<< " should be declared before use";
			string s_1 = out1.str();
			yyerror(s_1);
		}
		else{
			if(var-> type != SIMPLE){
				if(var->eletype == FLOAT_TYPE){
					var->eletype = FLOAT_ADDRESS_TYPE;
					var->type = SIMPLE;
				}
				if(var->eletype == INT_TYPE){
					var->eletype = INT_ADDRESS_TYPE;
					var->type = SIMPLE;
				}
				if(var->eletype != INT_TYPE && var->eletype != FLOAT_TYPE){
					var = NULL;
				}
			}
		}
		(yyval.id_arr_s) = new id_arr_(var,"NONE");
	}
}
#line 2939 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1372 "grammar.ypp" /* yacc.c:1646  */
    {
	if(active_function_index != -1){
		string s((yyvsp[-1].name));
		string offset_temp = "NONE";
		variable * var =symbol_table.search_variable_global(active_function_index,s,level);
		if(var == NULL){
			std::ostringstream out1;
			out1<<"varible with name "<<s<< " should be declared before use";
			string s_1 = out1.str();
			yyerror(s_1);
		}

		if(var != NULL){
			if(var->type != ARRAY){
				yyerror("variable "+ s + "is not array ");
				var = NULL;
			}
		}
		/* var != NULL signifies it is an array type */
		if(var != NULL){
			if((yyvsp[0].elist_s)->type == ERROR_TYPE || ((yyvsp[0].elist_s)->name_list.size() == 0) || ((yyvsp[0].elist_s)->name_list.size() != var->dimlist.size() ) ){
				var = NULL;
				std::ostringstream out1;
				out1<<"for variable "<<s<<" either array index is not integer " <<" or does not fit its declaration";
				string s_1 = out1.str();
				yyerror(s_1);
			}
			else{
					string temp_index = "T" + to_string(global_temp);
					global_temp ++;
					intermediate_output.gen_special("=",(yyvsp[0].elist_s)->name_list[0],"---",temp_index);
					string prev_index = temp_index;
					for(int i=1;i<(yyvsp[0].elist_s)->name_list.size();i++){
						string temp_index_new_1 = "T" + to_string(global_temp);
						global_temp ++;
						string temp_index_new_2 = "T" + to_string(global_temp);
						global_temp ++;
						intermediate_output.gen_special("*",prev_index,to_string(var->dimlist[i]),temp_index_new_1);
						intermediate_output.gen_special("+",temp_index_new_1,(yyvsp[0].elist_s)->name_list[i],temp_index_new_2);
						prev_index = temp_index_new_2;
					}
					string final_index = "T" + to_string(global_temp);
					global_temp++;
					string temp_final_result = "T" + to_string(global_temp);
					global_temp ++;
					if(var->eletype == FLOAT_TYPE){
						intermediate_output.gen_special("*",prev_index,to_string(FLOAT_TYPE_SIZE),final_index);
					}
					else {
						intermediate_output.gen_special("*",prev_index,to_string(INT_TYPE_SIZE),final_index);
					}
						offset_temp = final_index;
			}
		}
			(yyval.id_arr_s) = new id_arr_(var,offset_temp);
	}
}
#line 3001 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1433 "grammar.ypp" /* yacc.c:1646  */
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
#line 3040 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1467 "grammar.ypp" /* yacc.c:1646  */
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
#line 3080 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1506 "grammar.ypp" /* yacc.c:1646  */
    {
      (yyval.new_num_list_s)  = new new_num_list_();
      (yyval.new_num_list_s)->num_list.insert((yyval.new_num_list_s)->num_list.end(),(yyvsp[-3].new_num_list_s)->num_list.begin(),(yyvsp[-3].new_num_list_s)->num_list.end());
      (yyval.new_num_list_s)->num_list.push_back((yyvsp[-1].integer_value));
}
#line 3090 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1512 "grammar.ypp" /* yacc.c:1646  */
    {
    (yyval.new_num_list_s)  = new new_num_list_();
    (yyval.new_num_list_s)->num_list.push_back((yyvsp[-1].integer_value));
}
#line 3099 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1519 "grammar.ypp" /* yacc.c:1646  */
    { (yyval.parameter_list_s) = new parameter_list_((yyvsp[0].parameter_list_s)->no_of_parameter);
								symbol_table.patch_function_parameter_no(active_function_index,(yyval.parameter_list_s)->no_of_parameter);
							}
#line 3107 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1523 "grammar.ypp" /* yacc.c:1646  */
    { (yyval.parameter_list_s) = new parameter_list_(0);
							 symbol_table.patch_function_parameter_no(active_function_index,(yyval.parameter_list_s)->no_of_parameter);
							}
#line 3115 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1530 "grammar.ypp" /* yacc.c:1646  */
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
#line 3130 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1543 "grammar.ypp" /* yacc.c:1646  */
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
#line 3145 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1556 "grammar.ypp" /* yacc.c:1646  */
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
#line 3163 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1570 "grammar.ypp" /* yacc.c:1646  */
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
#line 3181 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1586 "grammar.ypp" /* yacc.c:1646  */
    {
	  (yyval.varlist_s) = new varlist_();
		(yyval.varlist_s)->list_of_indexes.insert((yyval.varlist_s)->list_of_indexes.end(),(yyvsp[-2].varlist_s)->list_of_indexes.begin(),(yyvsp[-2].varlist_s)->list_of_indexes.end());
		(yyval.varlist_s)->list_of_indexes.push_back((yyvsp[0].id_arr_declare_s)->index_in_sym_tab);
}
#line 3191 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1592 "grammar.ypp" /* yacc.c:1646  */
    {
    (yyval.varlist_s) = new varlist_();
		(yyval.varlist_s)->list_of_indexes.push_back((yyvsp[0].id_arr_declare_s)->index_in_sym_tab);
}
#line 3200 "grammar.tab.cpp" /* yacc.c:1646  */
    break;


#line 3204 "grammar.tab.cpp" /* yacc.c:1646  */
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
#line 1599 "grammar.ypp" /* yacc.c:1906  */

#include <stdio.h>

int main(){

	yyparse();
	if(main_flag == false){
		cout<< "ERROR :: no main function found\n";
		exit(1);
	}
	if(total_error == false){
		intermediate_output.print();
		total_user_variable.print();
	}
}
