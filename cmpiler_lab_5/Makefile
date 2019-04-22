.SILENT: create
.SILENT: run
.SILENT: output
create:
	flex lexer.l
	bison -d -v grammar.ypp
	g++ -std=c++11 lex.yy.c structure_function.cpp grammar.tab.cpp -o main
run :
	./main
