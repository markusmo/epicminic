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
	%token DIV MULT PLUS MINUS LT NE EQ GT LE GE ASIGN
	
	%right '=' ASIGN
	%left '<' '>' LE GE EQ NE LT GT
	%right '-' '+' MINUS PLUS
%%