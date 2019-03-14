%{
#include <stdio.h>

void yyerror(char *s){
	fprintf (stderr, "%s\n", s);
}

%}

%union{ char Char;}

%token <Char> WHITE_SPACE SEMI LESS_THAN GRE LB_ROUND RB_ROUND AMP COMMA PLUS MINUS TIMES DIV EQUAL DOT AND OR STRING SELECT PROJECT CARTESIAN_PRODUCT EQUI_JOIN ID

%start PROG

%%

/*grammar to be added */

int main(){
	yyparse();
	return 0;
}
