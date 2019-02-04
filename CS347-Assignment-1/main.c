#include "code_gen.h"
#include <stdio.h>
#include <stdlib.h>

void create_files();

int main ()
{
	create_files();
	statements ();
	fprintf(stderr, "%s\n", "Created Lexemes, Intermediate and assembly documents.");
}

void create_files(){
	FILE *fp;

	fp = fopen("Lexemes.txt", "w");
	if(fp == NULL){
		fprintf(stderr, "%s\n", "ERROR IN OPENING 'Lexemes.txt'");
		exit(1);		// unsuccessful exit
	}
	fclose(fp);

	fp = fopen("Intermediate.txt", "w");
	if(fp == NULL){
		fprintf(stderr, "%s\n", "ERROR IN OPENING 'Intermediate.txt'");
		exit(1);		// unsuccessful exit
	}
	fclose(fp);

	fp = fopen("Assembly.asm", "w");
	if(fp == NULL){
		fprintf(stderr, "%s\n", "ERROR IN OPENING 'Assembly.asm'");
		exit(1);		// unsuccessful exit
	}
	fclose(fp);
}
