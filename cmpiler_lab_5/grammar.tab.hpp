/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 26 "grammar.ypp" /* yacc.c:1909  */

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

#line 138 "grammar.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_HPP_INCLUDED  */
