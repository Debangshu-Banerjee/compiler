create:
	flex ra_lexer.lex
	bison -d ra_parser.y
	gcc -Wall ra_parser.tab.c ra_parser.tab.h -ly lex.yy.c -lfl -o ra_analyser
run :
	./ra_analyser
		
