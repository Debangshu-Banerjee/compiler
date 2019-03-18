%{
#include <stdio.h>

void yyerror(char *s){
	fprintf (stderr, "%s\n", s);
}

%}

%union{ char Char;}

%token <Char> ERROR NUM WHITE_SPACE SEMI LESS_THAN GRE_THAN LB_ROUND RB_ROUND AMP COMMA PLUS MINUS TIMES DIV EQUAL DOT AND OR NOT STRING SELECT PROJECT CARTESIAN_PRODUCT EQUI_JOIN ID ENDLN GRE_THAN_EQ LESS_THAN_EQ

%start INITIAL

%%
INITIAL:          QUERY ENDLN          { printf("INITIAL -> QUERY \n"); printf("\n the string is valid\n"); return 0;}
                  ;

QUERY:             SELECTION           {printf("QUERY -> SELECTION\n");}
                  | PROJECTION          {printf("QUERY -> PROJECTION\n");}
                  | PRODUCT_CART         {printf("QUERY -> PRODUCT_CART\n");}
                  | JOINING             {printf("QUERY -> JOINING\n");}
                  ;

SELECTION:      SELECT LESS_THAN CONDITION GRE_THAN LB_ROUND ID RB_ROUND     {printf("SELECTION -> SELECT <condition> (Table_Name)\n");}
                ;

PROJECTION:     PROJECT LESS_THAN ATTRIBUTE_LIST GRE_THAN LB_ROUND ID RB_ROUND {printf("PROJECTION -> PROJECT <attribute_list> (Table_Name)\n");}
                ;

PRODUCT_CART:   LESS_THAN ID GRE_THAN CARTESIAN_PRODUCT LESS_THAN ID GRE_THAN  {printf("PRODUCT_CART -> < Table_Name_1 > CARTESIAN_PRODUCT < Table_Name_2 >\n");}
                ;

JOINING:   LESS_THAN ID GRE_THAN EQUI_JOIN LESS_THAN CONDITION GRE_THAN LESS_THAN ID GRE_THAN {printf("JOINING -> < Table_Name_1 > EQUI_JOIN <condition> < Table_Name_2 >\n");}
            ;

CONDITION:    CONDITION_SMALL CONDITION_PRIME      {printf("CONDITION -> CONDITION_SMALL CONDITION_PRIME\n");}
            | NOT CONDITION_SMALL CONDITION_PRIME  {printf("CONDITION -> NOT CONDITION_SMALL CONDITION_PRIME\n");}
            ;

CONDITION_SMALL:   COMPARISON_COND               {printf("CONDITION_SMALL -> COMPARISON_COND \n");}
                  | LB_ROUND CONDITION RB_ROUND   {printf("CONDITION_SMALL -> LB_ROUND CONDITION RB_ROUND \n");}
                  ;

CONDITION_PRIME:   AND CONDITION_SMALL CONDITION_PRIME  {printf("CONDITION_PRIME -> AND CONDITION_SMALL CONDITION_PRIME\n");}
                  | OR CONDITION_SMALL CONDITION_PRIME  {printf("CONDITION_PRIME -> OR CONDITION_SMALL CONDITION_PRIME\n");}
                  | AND NOT CONDITION_SMALL CONDITION_PRIME  {printf("CONDITION_PRIME -> AND NOT CONDITION_SMALL CONDITION_PRIME\n");}
                  | OR NOT CONDITION_SMALL CONDITION_PRIME  {printf("CONDITION_PRIME -> OR NOT CONDITION_SMALL CONDITION_PRIME\n");}
                  | /* empty */                             {printf("CONDITION_PRIME -> epsilon\n");}
                  ;

COMPARISON_COND:   EXPR EQUAL EXPR    {printf("COMPARISON_COND -> EXPR EQUAL EXPR\n");}
                  | EXPR GRE_THAN EQUAL EXPR    {printf("COMPARISON_COND -> EXPR GRE_THAN EQUAL EXPR\n");}
                  | EXPR LESS_THAN EQUAL EXPR    {printf("COMPARISON_COND -> EXPR LESS_THAN EQUAL EXPR\n");}
                  | EXPR GRE_THAN EXPR    {printf("COMPARISON_COND -> EXPR GRE_THAN EXPR\n");}
                  | EXPR LESS_THAN EXPR    {printf("COMPARISON_COND -> EXPR LESS_THAN EXPR\n");}
                  | EXPR GRE_THAN_EQ EXPR  {printf("COMPARISON_COND -> EXPR GRE_THAN_EQUAL EXPR\n");}
                  | EXPR LESS_THAN_EQ EXPR  {printf("COMPARISON_COND -> EXPR LESS_THAN_EQUAL EXPR\n");}
                  ;

EXPR:    TERM EXPR_PRIME  {printf("EXPR -> TERM EXPR_PRIME\n");}
          ;

EXPR_PRIME:    PLUS TERM EXPR_PRIME    {printf("EXPR_PRIME -> PLUS TERM EXPR_PRIME\n");}
              | MINUS TERM EXPR_PRIME  {printf("EXPR_PRIME -> MINUS TERM EXPR_PRIME\n");}
              |  /* empty */           {printf("EXPR_PRIME -> epsilon\n");}
              ;

TERM:      FACTOR TERM_PRIME    {printf("TERM -> FACTOR TERM_PRIME\n");}
            ;

TERM_PRIME:    TIMES FACTOR TERM_PRIME     {printf("TERM_PRIME -> TIMES FACTOR TERM_PRIME\n");}
              | DIV FACTOR TERM_PRIME      {printf("TERM_PRIME -> DIV FACTOR TERM_PRIME\n");}
              | /* empty */                  {printf("TERM_PRIME -> epsilon\n");}
              ;

FACTOR:      ID            {printf("FACTOR -> ID\n");}
            | NUM          {printf("FACTOR -> NUM\n");}
            | STRING       {printf("FACTOR -> STRING\n");}
            | ID DOT ID    {printf("FACTOR -> ID DOT ID\n");}
            ;

ATTRIBUTE_LIST:     ID ATTRIBUTE_LIST_PRIME    {printf("ATTRIBUTE_LIST -> ID ATTRIBUTE_LIST_PRIME\n");}
                    ;

ATTRIBUTE_LIST_PRIME:   COMMA ID ATTRIBUTE_LIST_PRIME    {printf("ATTRIBUTE_LIST_PRIME -> COMMA ID ATTRIBUTE_LIST_PRIME\n");}
                       | /* empty */                     {printf("ATTRIBUTE_LIST_PRIME -> epsilon\n");}
                       ;

%%

int main(){
	yyparse();
	return 0;
}
