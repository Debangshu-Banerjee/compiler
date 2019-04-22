.SILENT: create
.SILENT: run
.SILENT: output
create:
	bison -d -v grammar.ypp
	flex lexer.l
	g++ -std=c++11 lex.yy.c structure_function.cpp grammar.tab.cpp -o main
run :
	./main
