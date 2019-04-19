%option noyywrap
%{
#include <bits/stdc++.h>
#include "parser.tab.h"
using namespace std;
%}


%s NORMAL
%x COMM

DIGIT                               [0-9]
ALPHA                              [a-zA-Z_]
BEG_COMMENT                        ("/*")
END_COMMENT                        ("*/")
SINGLE_COMMENT                     ("//"[^\n]*)
LIBRARY                            (\#include[ \n\t]*\<.+\>)|((\#include[ \t\n]*\".+\"))

%%

[ \t]+                   { /* ignore all spaces */  }


 /* -------------------- Comments ----------------------------- */
{BEG_COMMENT}          { BEGIN(COMM); }
<COMM>{END_COMMENT}    { BEGIN(NORMAL); }
<COMM><<EOF>>          {}
<COMM>.                { /* ignore everything else that doesn't match */ }
{SINGLE_COMMENT}       { /* skip to end of line for // comment */ }



 /* -------------------- Tokens ------------------------------- */
char                            { yylval.type = CHAR; return(CHAR); }
else                            { return(ELSE); }
break                           { return(BREAK);}
continue                        { return(CONTINUE); }
float                           { yylval.type = FLOAT; return(FLOAT); }
for                             { return(FOR); }
if                              { return(IF); }
int                             { yylval.type = INT; return(INT); }
return                          { return(RETURN); }
void                            { yylval.type = VOID; return(VOID); }
while                           { return(WHILE); }
do                              { return(DO); }
bool                            { yylval.type = BOOL; return(BOOL); }
{LIBRARY}                       { return LIBRARY;}
"->"                            { return(PTR_OP); }
"&"                             { return(AMP); }
"~"                             { return(TILDE); }
"+"                             { return(PLUS); }
"-"                             { return(MINUS); }
"*"                             { return(STAR); }
"/"                             { return(DIVIDE); }
"%"                             { return(MODULUS); }
"++"                            { return(INC_OP); }
"--"                            { return(DEC_OP); }
"&&"                            { return(AND_OP); }
"||"                            { return(OR_OP); }
"<"                             { return(LT); }
">"                             { return(GT); }
"<="                            { return(LE_OP); }
">="                            { return(GE_OP); }
"=="                            { return(EQ_OP); }
"!="                            { return(NE_OP); }
"!"                             { return(NOT); }
"="                             { return(ASSIGN); }
":"                             { return(COLON); }
"("                             { return(OPEN_BRACKET); }
")"                             { return(CLOSED_BRACKET); }
"{"                             { return(OPEN_CURLY); }
"}"                             { return(CLOSED_CURLY); }
ALPHA?\"(\\.|[^\\"])*\"         { yylval.string_value = strdup(yytext); return(STRING_LITERAL); }
ALPHA?\'(\\.|[^\\'])*\'         { yylval.string_value = strdup(yytext); return(STRING_LITERAL); }
"]"                             { return(CLOSED_SQUARE); }
"["                             { return(OPEN_SQUARE); }
[0-9]*"."[0-9]+                 { yylval.real_value = atof(yytext); return(REAL); } 
[0-9]+                          { yylval.integer_value = atoi(yytext); return(NUM);}
true                            { yylval.boolean_value = true; return(BOOLEAN);}
false                           { yylval.boolean_value = false; return(BOOLEAN);}
{ALPHA}({ALPHA}|{DIGIT})*       {   
                                  yylval.name = strdup(yytext);
                                  return(ID); 
                                }
";"                             { return(SEMI);}
","                             { return(COMMA); }
"."                             { return(DOT); }
"^"                             { return(XOR); }
"|"                             { return(PIPE); }
"?"                             { return(QUES); }
.                               { cerr<< "TOKEN CANNOT BE MATCHED :\t"<< yytext <<"\t"<<endl;return(ERROR);}
                                  
%%

