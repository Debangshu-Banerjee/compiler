#include "lex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* yytext = ""; /* Lexeme (not '\0' terminated) */
int yyleng   = 0;  /* Lexeme length.               */
int yylineno = 0;  /* Input line number            */
FILE *lexFile;
static int Lookahead = -1; /* Lookahead token  */


int lex(void) {

    static char input_buffer[1024];
    char *current;

    current = yytext + yyleng; /* Skip current
																 lexeme        */

    while(1) {      /* Get the next one         */
        while(!*current ) {
            /* Get new lines, skipping any leading
            * white space on the line,
            * until a nonblank line is found.
            */

            current = input_buffer;
            if(!gets(input_buffer)) {
                *current = '\0' ;

                return EOI;
            }
            ++yylineno;
            while(isspace(*current))
                ++current;
        }
        for(; *current; ++current) {
            /* Get the next token */
            yytext = current;
            yyleng = 1;
            switch( *current )
            {
            case ';':
                return SEMI;
            case '+':
                return PLUS;
            case '-':
                return MINUS;
            case '*':
                return TIMES;
            case '/':
                return DIV;
            case '(':
                return LP;
            case ')':
                return RP;
            case ':':
                return COL;
            case '=':
                return EQUAL;
            case '<':
                return LT;
            case '>':
                return GT;
            case '\n':
            case '\t':
            case ' ' :
                break;
            default:
                if(!isalnum(*current))
                    fprintf(stderr, "Not an alphanumeric entity <%c>\n", *current);
                else
                {
                    while(isalnum(*current)) current++;
                    yyleng = current - yytext;
                    char temp[yyleng+1];
                    memcpy( temp, yytext, yyleng );
                    temp[yyleng] = '\0';
                    if(strcmp(temp, "if") == 0) return IF;
                    else if(strcmp(temp, "then") == 0) return THEN;
                    else if(strcmp(temp, "while") == 0) return WHILE;
                    else if(strcmp(temp, "do") == 0) return DO;
                    else if(strcmp(temp, "begin") == 0) return BEGIN;
                    else if(strcmp(temp, "end") == 0) return END;
                    return NUM_OR_ID;
                }
                break;
            }
        }
    }
}



int match(int token) {
    /* Return true if "token" matches the
    	current lookahead symbol.                */

    if(Lookahead == -1) Lookahead = lex();

    if( (token != ID) && (token == Lookahead))
    {
        lexFile = fopen("Lexemes.txt", "a");
        if (lexFile != NULL) {
            switch(token)
            {
            case(0):
                fprintf(lexFile,"<END OF INPUT> ");
                break;
            case(1):
                fprintf(lexFile,"<SEMI> ");
                break;
            case(2):
                fprintf(lexFile,"<PLUS> ");
                break;
            case(3):
                fprintf(lexFile,"<TIMES> ");
                break;
            case(4):
                fprintf(lexFile,"<LP> ");
                break;
            case(5):
                fprintf(lexFile,"<RP> ");
                break;
            case(6):
                fprintf(lexFile,"<NUM_OR_ID> ");
                break;
            case(7):
                fprintf(lexFile,"<MINUS> ");
                break;
            case(8):
                fprintf(lexFile,"<DIV> ");
                break;
            case(9):
                fprintf(lexFile,"<LT> ");
                break;
            case(10):
                fprintf(lexFile,"<GT> ");
                break;
            case(11):
                fprintf(lexFile,"<EQUAL> ");
                break;
            case(12):
                fprintf(lexFile,"<WHILE> ");
                break;
            case(13):
                fprintf(lexFile,"<DO> ");
                break;
            case(14):
                fprintf(lexFile,"<BEGIN> ");
                break;
            case(15):
                fprintf(lexFile,"<END> ");
                break;
            case(16):
                fprintf(lexFile,"<ID> ");
                break;
            case(17):
                fprintf(lexFile,"<COL> ");
                break;
            case(18):
                fprintf(lexFile,"<IF> ");
                break;
            case(19):
                fprintf(lexFile,"<THEN> ");
                break;
            }
            fclose(lexFile);
        }
        return 1;
    }

    else if(token == ID && Lookahead == NUM_OR_ID)  //because lookahead can be NUM or ID
    {
        int i;
        char *current = yytext;
        for(i=0; i<yyleng; i++) current++;
        while(isspace(*current)) current++;
        if((*current)==':' && (isalpha(*yytext) != 0))   //match for ID since it is followed by :=
        {
            lexFile = fopen("Lexemes.txt", "a");
            if (lexFile != NULL) {
                fprintf(lexFile,"<ID> ");
                fclose(lexFile);
            }
            return 1;
        }
        return 0;
    }
    else return 0;
}

void advance(void) {
    /* Advance the lookahead to the next
    	 input symbol.                               */

    Lookahead = lex();
}
