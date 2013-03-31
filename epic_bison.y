%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "AST.h"
		
	int yyerror(yyscan_t scanner, SExpression **expression, const char *msg);

%}

%union{
	int *ivalue;
    float *fvalue;
}

	%token INT
	%token <ivalue> INTNUM
	%token FLOAT
	%token <fvalue> FLOATNUM
	%token FOR WHILE DO
	%token IF ELSE
	%token RETURN
	%token ID
	%token DIV MULT PLUS MINUS LT NE EQ GT LE GE ASSIGN
	%token LPARENT RPARENT LFANCYBRACKET RFANCYBRACKET LBRACKET RBRACKET
	%token SEMICOLON COLON
	
	%right '=' ASSIGN
	%left '<' '>' LE GE EQ NE LT GT
	%right '-' '+' MINUS PLUS
%%
	start: program
	
	program: decList funcList
		| decList 
		| funcList
		;
	
	funcList: function
		| function funcList
		;
	
	decList: declaration
		| declaration decList
		;
	
	declaration: type identList;
	
	identList: identifier
		| identifier identList
		;
	
	identifier: ID;
	
	function: type ID LPARENT paramList RPARENT compoundStatement;
	
	paramList: type ID;
	
	type: INT 
		| FLOAT;
	
	compoundStatement: LFANCYBRACKET decList stmtList RFANCYBRACKET;
	
	stmtList: statement
		| statement stmtList
		;
	
	statement: assignStmt
		| callStmt
		| retStmt
		| whileStmt
		| forStmt
		| ifStmt
		| compoundStatement
		;
	
	assignStmt: assign;
	
	assign: ID ASSIGN expr 
		| ID LBRACKET expr RBRACKET ASSIGN expr
		;
	
	callStmt: call;
	
	call: ID LPARENT argList RPARENT;
	
	retStmt: RETURN expr
	
	whileStmt: WHILE LPARENT expr RPARENT statement
		| DO expr WHILE LPARENT expr RPARENT
		;
	
	forStmt: FOR LPARENT assign SEMICOLON expr SEMICOLON assign RPARENT statement ;
	
	ifStmt: IF LPARENT expr RPARENT statement 
		| IF LPARENT expr RPARENT statement ELSE statement
		;
	
	expr: expr PLUS expr
		| expr MINUS expr
		| expr MULT expr
		| expr DIV expr
		| expr LT expr
		| expr LE expr
		| expr GT expr
		| expr GE expr
		| expr EQ expr
		| expr NE expr
		| INTNUM
		| FLOATNUM
		| ID
		| ID LBRACKET expr RBRACKET 
		| LPARENT expr RPARENT
		;
	
	argList: expr
		| expr COLON argList
		;

%%
/*
#include "lex.yy.c"
#inlude <ctype.h>

int main(int argc, char *arg[])
{
	yyin = fopen("program.emc","r");
	
	if(!yyparse())
	{
		printf("\nDone");
	}
	else
	{
		printf("\nFail");
	}
	fclose(yyin);
	
	return 0;
}
*/
