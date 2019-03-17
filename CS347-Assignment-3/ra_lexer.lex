%option noyywrap
%{
	#include <stdio.h>
  #include "ra_parser.tab.h"
%}

ID              [a-zA-Z]([_a-zA-Z0-9])*
WHITE_SPACE     [ \t]
ENDLN           "\n"
LB_ROUND				"("
RB_ROUND        ")"
LESS_THAN        "<"
GRE_THAN        ">"
GRE_THAN_EQ		">="
LESS_THAN_EQ	"<="
AMP							"&"
COMMA						","
PLUS						"+"
MINUS						"-"
TIMES						"*"
DIV							"/"
EQUAL						"="
DIGITS 						([0-9]+)
FLOAT             ([0-9]*\.?[0-9]+|[0-9]+)
NUM                ({DIGITS}|{FLOAT})
DOT             "."
AND             "AND"
OR              "OR"
NOT             "NOT"
CHAR					\'([^\']|\\.)?\'
STRING1       \"([^\"]|\\.)*\"
STRING2       \'([^\']|\\.)*\'
STRING         ({CHAR}|{STRING1}|{STRING2})
SELECT          "SELECT"
PROJECT         "PROJECT"
CARTESIAN_PRODUCT    "CARTESIAN_PRODUCT"
EQUI_JOIN            "EQUI_JOIN"

%%
{SELECT}            {return SELECT;}
{PROJECT}           {return PROJECT;}
{CARTESIAN_PRODUCT}     {return CARTESIAN_PRODUCT;}
{EQUI_JOIN}            {return EQUI_JOIN;}
{NUM}                 {return NUM;}
{LESS_THAN_EQ}		  {return LESS_THAN_EQ;}
{LESS_THAN}						{return  LESS_THAN;}
{GRE_THAN_EQ}						{return GRE_THAN_EQ;}
{GRE_THAN}						{return GRE_THAN;}
{LB_ROUND}						{return LB_ROUND;}
{RB_ROUND}						{return RB_ROUND;}
{AMP}							{return AMP;}
{PLUS}							{return PLUS;}
{MINUS}							{return MINUS;}
{TIMES}							{return TIMES;}
{DIV}							{return DIV;}
{COMMA}							{return COMMA;}
{EQUAL}							{return EQUAL;}
{DOT}               {return DOT;}
{AND}               {return AND;}
{ENDLN}				{return ENDLN;}
{OR}                {return OR;}
{ID}                {return ID ;}
{STRING}            {return STRING;}
{WHITE_SPACE}				{ECHO;}
.                   {return ERROR;}

%%
