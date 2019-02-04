CC=gcc
CCFLAGS=-Wall -g

all: main.o lex.o code_gen.o name.o Makefile
	$(CC) main.o lex.o code_gen.o name.o -o main $(CCFLAGS)

main.o: main.c code_gen.o
	$(CC) -c main.c -o main.o $(CCFLAGS)

code_gen.o : code_gen.c name.o
	$(CC) -c code_gen.c -o code_gen.o $(CCFLAGS)

name.o: name.c lex.o
	$(CC) -c name.c -o name.o $(CCFLAGS)

lex.o : lex.c
	$(CC) -c lex.c -o lex.o $(CCFLAGS)

clean:
	rm -f *.asm *.txt *.o main
