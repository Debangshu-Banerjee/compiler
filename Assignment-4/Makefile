.SILENT: create
.SILENT: run
.SILENT: output
create:
	flex ra_lexer.lex
	bison -d ra_parser.y
	gcc -Wall ra_parser.tab.c ra_parser.tab.h -ly lex.yy.c -lfl 2>flex_bi.err -o ra_analyser
run :
	./ra_analyser
output:
	  if g++ -std=c++11 output_file.cpp 2>temp.err; then echo "compilation success.\nRunning ./a.out to get ouput\n" ; ./a.out; else echo "Error::There is type mismatch in condition.\nCheck wheather attribute types are compatible with operator."; fi
	  
