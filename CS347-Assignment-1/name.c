#include <stdio.h>
#include <stdlib.h>
#include "name.h"
#include "lex.h"


char  *Names[] = { "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7" };
char  **Namep  = Names;

int exp_count = 0;
int ifThen_count = 0;
int loop_count = 0;

char  *newname()
{
    if( Namep >= &Names[ sizeof(Names)/sizeof(*Names) ] )
    {
        fprintf( stderr, "%d: Expression too complex\n", yylineno );
        exit( 1 );
    }

    return( *Namep++ );
}

freename(s)
char    *s;
{
    if( Namep > Names )
    *--Namep = s;
    else
    fprintf(stderr, "%d: (Internal error) Name stack underflow\n",
                                yylineno );
}


int get_comp(){
  return exp_count++;
}

int get_ifThen(){
  return ifThen_count++;
}
int get_loop(){
  return loop_count++;
}
