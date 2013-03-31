%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "AST.h"

	extern FILE *emc;

%}

%union{
	int *ivalue;
    float *fvalue;
    
}

	%token INT FLOAT
	%token FOR WHILE DO
	%token IF ELSE
	%token RETURN
	%token ID
	%token UNOP BINOP
	
	%right '='
	%left AND OR
	%left '<' '>' LE GE EQ NE LT GT
%%