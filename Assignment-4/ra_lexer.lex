%option noyywrap
%{
	#include <stdio.h>
	#include<string.h>
  #include "ra_parser.tab.h"
   extern char* given_input;
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
{SELECT}            {strcat(given_input,yytext);return SELECT;}
{PROJECT}           {strcat(given_input,yytext);return PROJECT;}
{CARTESIAN_PRODUCT}     {strcat(given_input,yytext);return CARTESIAN_PRODUCT;}
{EQUI_JOIN}            {strcat(given_input,yytext);return EQUI_JOIN;}
{NUM}                 {strcat(given_input,yytext);return NUM;}
{LESS_THAN_EQ}		  {strcat(given_input,yytext);return LESS_THAN_EQ;}
{LESS_THAN}						{strcat(given_input,yytext);return  LESS_THAN;}
{GRE_THAN_EQ}						{strcat(given_input,yytext);return GRE_THAN_EQ;}
{GRE_THAN}						{strcat(given_input,yytext);return GRE_THAN;}
{LB_ROUND}						{strcat(given_input,yytext);return LB_ROUND;}
{RB_ROUND}						{strcat(given_input,yytext);return RB_ROUND;}
{AMP}							{strcat(given_input,yytext);return AMP;}
{PLUS}							{strcat(given_input,yytext);return PLUS;}
{MINUS}							{strcat(given_input,yytext);return MINUS;}
{TIMES}							{strcat(given_input,yytext);return TIMES;}
{DIV}							{strcat(given_input,yytext);return DIV;}
{COMMA}							{strcat(given_input,yytext);return COMMA;}
{NOT}							{strcat(given_input,"!");return NOT;}
{EQUAL}							{strcat(given_input,"==");return EQUAL;}
{DOT}               {strcat(given_input,"_");return DOT;}
{AND}               {strcat(given_input,"&&");return AND;}
{ENDLN}				{strcat(given_input,yytext);return ENDLN;}
{OR}                {strcat(given_input,"||");return OR;}
{ID}                {strcat(given_input,yytext);return ID ;}
{STRING}            {
char* tempo = malloc(250 * sizeof(char));
strcpy(tempo,yytext);
	if(tempo[0] == '\''){
		tempo[0] = '\"';
		tempo[strlen(tempo)-1]= '\"';
	}
	printf("**************** %s *******************",tempo);
	strcat(given_input,tempo);return STRING;
}
{WHITE_SPACE}				{ECHO;}
.                   {strcat(given_input,yytext);return ERROR;}

%%
