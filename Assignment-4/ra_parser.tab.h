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

#ifndef YY_YY_RA_PARSER_TAB_H_INCLUDED
# define YY_YY_RA_PARSER_TAB_H_INCLUDED
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
    ERROR = 258,
    NUM = 259,
    WHITE_SPACE = 260,
    SEMI = 261,
    LESS_THAN = 262,
    GRE_THAN = 263,
    LB_ROUND = 264,
    RB_ROUND = 265,
    AMP = 266,
    COMMA = 267,
    PLUS = 268,
    MINUS = 269,
    TIMES = 270,
    DIV = 271,
    EQUAL = 272,
    DOT = 273,
    AND = 274,
    OR = 275,
    NOT = 276,
    STRING = 277,
    SELECT = 278,
    PROJECT = 279,
    CARTESIAN_PRODUCT = 280,
    EQUI_JOIN = 281,
    ID = 282,
    ENDLN = 283,
    GRE_THAN_EQ = 284,
    LESS_THAN_EQ = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "ra_parser.y" /* yacc.c:1909  */
 char Char;

#line 88 "ra_parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_RA_PARSER_TAB_H_INCLUDED  */
