#define EOI			0	/*	End of input	*/
#define SEMI		1	/*	; 				*/
#define PLUS		2	/*	+ 				*/
#define TIMES		3	/*	* 				*/
#define LP			4	/*	(				*/
#define RP			5	/*	)				*/
#define NUM_OR_ID	6	/*	Decimal Number or Identifier */
#define MINUS		7	/*	- 				*/
#define DIV			8	/*	/ 				*/
#define LT			9	/*	< 				*/
#define GT			10	/*	> 				*/
#define EQUAL		11	/*	= 				*/
#define WHILE 		12
#define DO 			13
#define BEGIN 		14
#define END			15
#define ID 			16
#define COL 		17
#define IF			18
#define THEN 		19


/* in lex.c	*/
extern char *yytext;
extern int yyleng;
extern int yylineno;

int lex(void);
int match(int);
void advance(void);
