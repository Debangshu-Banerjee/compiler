create:
	flex ra_lexer.lex
	bison -d ra_parser.y
	gcc -Wall ra_parser.tab.c ra_parser.tab.h -ly lex.yy.c -lfl -o ra_analyser
run :
	./ra_analyser
output:
	g++ -std=c++11 ouput_file.cpp 2> temp.err -o output
	./output
	rm -f output	
