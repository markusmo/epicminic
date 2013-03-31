%{
	#include <stdio.h>
	#include <stdlib.h>
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
	%right '-' '+' MINUS PLUS DIV MULT
	%right RPARENT ELSE
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
	
	declaration: type identList SEMICOLON;
	
	identList: ID
		| ID COLON identList
		;
		
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
		| SEMICOLON
		;
	
	assignStmt: assign;
	
	assign: ID ASSIGN expr 
		| ID LBRACKET expr RBRACKET ASSIGN expr
		;
	
	callStmt: call;
	
	call: ID LPARENT argList RPARENT;
	
	retStmt: RETURN expr SEMICOLON
	
	whileStmt: WHILE LPARENT expr RPARENT statement
		| DO expr WHILE LPARENT expr RPARENT SEMICOLON
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
