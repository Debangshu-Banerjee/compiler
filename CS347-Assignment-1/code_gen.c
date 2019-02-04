#include <stdio.h>
#include "lex.h"
#include "code_gen.h"
#include "name.h"
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <ctype.h>   //isalnum()

extern char *newname( void       );
extern void freename( char *name );

FILE *assFile, *interFile, *lexFile;
char REG[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

void statements()
{
    /*  statements -> statements statement | epsilon  */
    assFile = fopen("Assembly.asm", "w");
    interFile = fopen("Intermediate.txt", "w");

    fprintf(assFile, "%s\n", "ORG 0000h");

    while( !match(EOI) )
    {
      statement();
    }
    fprintf(assFile, "%s\n", "END");
    fclose(assFile);
    fclose(interFile);
}

void statement(){
/*  statement -> ID:=cond_expression;
            | if cond_expression then statement
            | while expression1 do statement
            |begin stmt_list end
  */

  char *tempvar;

  if(match(ID)){
    char variable[500];
    int i = 0;
    for(;i<yyleng;i++){
      variable[i] = *(yytext + i);
    }
    variable[i] = '\0';
    advance();
    if(!check_lookahead(COL, 0)){
      fprintf(stderr, "%d: missing colon\n", yylineno);
      goto lookahead_ABSURD;
    }
    else{
      advance();
      if(!check_lookahead(EQUAL, 0)){
        fprintf(stderr, "%d: missing equal\n", yylineno);
        goto lookahead_ABSURD;
      }
      else{
        advance();
        tempvar = cond_expression();
        fprintf(interFile, "%s <- %s\n", variable, tempvar);

        if(strcmp(tempvar, "t0") == 0){
          fprintf(assFile, "STA _%s\n", variable);
        }
        else{
          fprintf(assFile, "PUSH A \n MOV A %c \n STA _%s \n POP A \n", REG[tempvar[1] - '0'],variable);
        }
      }
    }
  }
  else if(match(IF)){
    advance();
    fprintf(interFile, "if (\n");
    tempvar = cond_expression();
    if(!check_lookahead(THEN, 0)){
      freename(tempvar);
      fprintf(stderr, "%d: missing THEN\n", yylineno);
      goto lookahead_ABSURD;
    }
    else{
      fprintf(interFile, "%s)\n", tempvar);
      int ifThen = get_ifThen();
      fprintf(assFile, "CMP %c 0\n JZ IFTHEN%d\n", REG[tempvar[1] - '0'], ifThen);
      fprintf(interFile, "%s\n", "then {");
      advance();
      freename(tempvar);
      statement();
      fprintf(interFile, "%s\n", "}");
      fprintf(assFile, "IFTHEN%d:\n", ifThen);
      return;
    }
  }
  else if(match(WHILE)){
    advance();
    int loop1 = get_loop();
    fprintf(assFile, "LOOP%d:\n",loop1);
    fprintf(interFile, "while ( ");
    tempvar = cond_expression();
    if(!check_lookahead(DO, 0)){
      freename(tempvar);
      fprintf(stderr, "%d: missing do\n", yylineno);
      goto lookahead_ABSURD;
    }
    else{
      
      fprintf(interFile, "%s )\n", tempvar);
      int loop = get_loop();
      fprintf(assFile, "CMP %c 0 \n JZ LOOP%d\n", REG[tempvar[1] - '0'], loop);
      fprintf(interFile, "%s\n", "do {");
      advance();
      freename(tempvar);
      statement();
      fprintf(interFile, "%s\n", "}");
      fprintf(assFile, "JMP LOOP%d \n LOOP%d: \n", loop1, loop);
      return;
    }
  }
  else if(match(BEGIN)){
    fprintf(interFile, "%s\n", "BEGIN{");
    advance();
    int c = stmt_list();
    if(c==0){
      fprintf(stderr, "%d: missing END\n", yylineno);
      goto lookahead_ABSURD;
    }
  
      fprintf(interFile, "} %s\n", "END");
      advance();

    return;
  }
  else{
    fprintf(stderr, "Warning : the evaluated expression is not assigned to any variable at line no %d \n",yylineno );
    tempvar = cond_expression();
  }


  if(tempvar!=NULL){
    freename(tempvar);
  }
  else{
    exit(1);
  }

lookahead_ABSURD:
  if(match(SEMI)){
    advance();
  }
  else{
    fprintf(stderr, "%d: Syntax error\n", yylineno);
  }
}

int stmt_list(){
  while(1){
	if(match(END))
		return 1;
	if(match(EOI))
		break;
     statement();
  }
  fprintf(stderr, "%d: end of file reached without end \n", yylineno);
  return 0;
}

char *cond_expression(){
  char *tempvar3;
  char *tempvar = expression();
  if(match(GT)){
    freename(tempvar);
    tempvar3 = newname();
    tempvar = newname();
    fprintf(interFile, "%s <- %s\n", tempvar, tempvar3);
    fprintf(assFile, "MOV %c %c \n", REG[tempvar[1] - '0'], REG[tempvar3[1] - '0']);
    advance();
    char *tempvar2 = expression();
    fprintf(interFile, "%s <- %s > %s\n", tempvar3, tempvar, tempvar2);
    int comp = get_comp();
    fprintf(assFile, "CMP %c %c\n", REG[tempvar[1] - '0'], REG[tempvar2[1] - '0']);
    fprintf(assFile, "MVI %c 1 \n JNZ COMPARE%d \n MVI %c 0 \n COMPARE%d:\n", REG[tempvar3[1] - '0'], comp, REG[tempvar3[1] - '0'], comp);
    freename(tempvar2);
    freename(tempvar);
    return tempvar3;
  }
  else if(match(LT)){
    freename(tempvar);
    tempvar3 = newname();
    tempvar = newname();

    fprintf(interFile, "%s <- %s\n", tempvar, tempvar3);
    fprintf(assFile, "MOV %c %c\n", REG[tempvar[1] - '0'], REG[tempvar3[1] - '0']);
    advance();
    char *tempvar2 = expression();
    fprintf(interFile, "%s <- %s < %s\n", tempvar3, tempvar, tempvar2);
    int comp = get_comp();
    fprintf(assFile, "CMP %c %c\n", REG[tempvar[1] - '0'], REG[tempvar2[1] - '0']);
    fprintf(assFile, "MVI %c 1 \n JC COMPARE%d \n MVI %c 0 \n COMPARE%d: \n", REG[tempvar3[1] - '0'], comp, REG[tempvar3[1] - '0'], comp);
    freename(tempvar);
    freename(tempvar2);
    return tempvar3;
  }
  else if(match(EQUAL)){
    freename(tempvar);
    tempvar3 = newname();
    tempvar = newname();
    fprintf(interFile, "%s <- %s\n", tempvar, tempvar3);
    fprintf(assFile, "MOV %c %c\n", REG[tempvar[1] - '0'], REG[tempvar3[1] - '0']);
    advance();
    char *tempvar2 = expression();
    fprintf(interFile, "%s <- %s == %s\n", tempvar3, tempvar, tempvar2);
    int comp = get_comp();
    fprintf(assFile, "CMP %c %c\n", REG[tempvar[1] - '0'], REG[tempvar2[1] - '0']);
    fprintf(assFile, "MVI %c 1 \n JZ COMPARE%d \n MVI %c 0 \n COMPARE%d: \n", REG[tempvar3[1] - '0'], comp, REG[tempvar3[1] - '0'], comp);
    freename(tempvar);
    freename(tempvar2);
    return tempvar3;
  }
  return tempvar;
}

char *expression()
{
  /*
		expression  -> term expression'
		expression' ->    PLUS term expression'
						| MINUS term expression'
						| epsilon
	*/

    char  *tempvar, *tempvar2;

    tempvar = term();
    while(1)
    {	
    	int x= match( PLUS );
    	int y =match(MINUS);
    	if(x == 0 && y==0) break;
        int Plus_check = 0;
        if(x){
          Plus_check = 1;
        }
        advance();
        tempvar2 = term();
        if(Plus_check){
          fprintf(interFile, "%s += %s\n",tempvar, tempvar2);
          if(strcmp(tempvar, "t0") == 0){
            fprintf(assFile, "ADD %c\n", REG[tempvar2[1] - '0']);
          }
          else{
            fprintf(assFile, "PUSH A \n MOV A %c \n ADD %c \n MOV %c, A \n POP A \n", REG[tempvar[1] - '0'], REG[tempvar2[1] - '0'], REG[tempvar[1] - '0']);
          }
      }
      else{
        fprintf(interFile, "%s -= %s\n",tempvar, tempvar2);
        if(strcmp(tempvar, "t0") == 0){
          fprintf(assFile, "SUB %c\n", REG[tempvar2[1] - '0']);
        }
        else{
          fprintf(assFile, "PUSH A \n MOV A %c \n SUB %c \n MOV %c, A \n POP A \n", REG[tempvar[1] - '0'], REG[tempvar2[1] - '0'], REG[tempvar[1] - '0']);
        }
      }
        freename( tempvar2 );
    }
    return tempvar;
}

char *term()
{

  /*
    term 	->  factor term'
    term' 	->  TIMES factor term'
          | DIV factor term'
          | epsilon
  */
    char  *tempvar, *tempvar2 ;

    tempvar = factor();
    while(1)
    {
        int x =  match( TIMES );
        int y = match(DIV);
        if(x==0 && y==0) break;
        int Times_check = 0;
        if(x){
          Times_check = 1;
        }
        advance();
        tempvar2 = factor();
        if(Times_check){
          fprintf(interFile, "%s *= %s\n", tempvar, tempvar2);
          if(strcmp(tempvar, "t0") == 0){
            fprintf(assFile, "MUL %c\n", REG[tempvar2[1] - '0']);
          }
          else{
            fprintf(assFile, "PUSH A \n MOV A %c \n MUL %c \n MOV %c, A \n POP A \n", REG[tempvar[1] - '0'], REG[tempvar2[1] - '0'], REG[tempvar[1] - '0']);
          }
        }
        else{
          fprintf(interFile, "%s /= %s \n", tempvar, tempvar2);
          if(strcmp(tempvar, "t0") == 0){
            fprintf(assFile, "DIV %c \n", REG[tempvar2[1] - '0']);
          }
          else{
            fprintf(assFile, "PUSH A \n MOV A %c \n DIV %c \n MOV %c, A \n POP A \n", REG[tempvar[1] - '0'], REG[tempvar2[1] - '0'], REG[tempvar[1] - '0']);
          }
        }
        freename( tempvar2 );
    }
    return tempvar;
}

char    *factor()
{

  /*
		factor ->   NUM_OR_ID
				  | LP expression RP
	*/
    char *tempvar = NULL;

    if( match(NUM_OR_ID) )
    {
	/* Print the assignment instruction. The %0.*s conversion is a form of
	 * %X.Ys, where X is the field width and Y is the maximum number of
	 * characters that will be printed (even if the string is longer). I'm
	 * using the %0.*s to print the string because it's not \0 terminated.
	 * The field has a default width of 0, but it will grow the size needed
	 * to print the string. The ".*" tells printf() to take the maximum-
	 * number-of-characters count from the next argument (yyleng).
	 */

        fprintf(interFile, "%s = %.*s\n", tempvar = newname(), yyleng, yytext );
        int cond_digit = 1;
        int i = 0;
        for(;i<yyleng;i++){
          if(!isdigit(*(yytext + i))){
            cond_digit = 0;
            break;
          }
        }
        if(cond_digit){
          fprintf(assFile, "MVI %c %.*s\n", REG[tempvar[1] - '0'], yyleng, yytext);
        }
        else{
          if(strcmp(tempvar, "t0") == 0){
            fprintf(assFile, "LDA _%.*s\n", yyleng, yytext);
          }
          else{
            fprintf(assFile, "PUSH A \n LDA _%.*s \n MOV %c A \n POP A \n", yyleng, yytext, REG[tempvar[1] - '0']);
          }
        }
        advance();
    }
    else if( match(LP) )
    {
        advance();
        tempvar = expression();
        if( match(RP) )
            advance();
        else
            fprintf(stderr, "%d: Mismatched parenthesis\n", yylineno );
    }
    else
	fprintf( stderr, "%d: Number or identifier expected\n", yylineno );

    return tempvar;
}

#include <stdarg.h>
#define MAX_ARG 50

// checking if any of the arguments matches or not to the next token. If matches return 1, else 0
int check_lookahead(int first_arg, ...){
  va_list args; // variable argument list
  int temp;
  int lookaheads[MAX_ARG];
  int *poi = lookaheads;
  int *i;
  int err_details = 0;
  int ret_val = 0;
  int prev_line = -1;

  va_start(args, first_arg);

  if(!first_arg){
    if(match(EOI)){
      ret_val = 1;
    }
  }
  else{
      *poi++ = first_arg;
      while((temp = va_arg(args, int)) && poi < &lookaheads[MAX_ARG]){
        *poi++ = temp;
      }

      while(!match(SEMI)){
        if(match(EOI)) break;
        for(i = lookaheads; i<poi;++i){
          if(match(*i)){
            ret_val = 1;
            goto exit;
          }
        }
        if(!err_details && prev_line != yylineno){
          prev_line = yylineno;
          fprintf(stdout, "Syntax error on line number %d \n", yylineno);
        }
        advance();
      }
  }

exit:
  va_end(args);
  return ret_val;

}
