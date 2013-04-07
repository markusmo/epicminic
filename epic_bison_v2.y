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
	
	%right ASSIGN INTNUM
	%left LE GE EQ NE LT GT
	%right MINUS PLUS DIV MULT
	%right RPARENT ELSE LBRACKET
	%right COLON
	%left LPARENT SEMICOLON UNOP RBRACKET

%%
	start: program;
	
	program: decList funcList;
	
	decList: declaration
		| decList declaration
		;
		
	declaration: identList SEMICOLON;
	
	identList: identifier
		| identifier COLON identList
		;
	
	identifier: type ID
		| type ID LBRACKET RBRACKET
		;
	
	type: INT
		| FLOAT
		;
	
	funcList: function
		| funcList function
		;
	
	function: type ID LPARENT paramList RPARENT compoundStmt;
	
	paramList: param params;
		
	params: COLON params
		| /*empty*/
		;
	
	param: type ID;
	
	compoundStmt: LFANCYBRACKET decList stmtList RFANCYBRACKET;
	
	stmtList: stmt stmtList
		| /* emtpy */
	
	stmt: assignStmt
		| callStmt
		| retStmt
		| whileStmt
		| forStmt
		| ifStmt
		| compoundStmt
		| SEMICOLON
		;
	
	ifStmt: IF LPARENT expr RPARENT stmt
		| IF LPARENT expr RPARENT stmt ELSE stmt
		;
	
	forStmt: FOR LPARENT assign SEMICOLON expr SEMICOLON expr RPARENT stmt;
	
	whileStmt: WHILE LPARENT expr RPARENT stmt
		| DO stmt WHILE LPARENT expr RPARENT SEMICOLON
		;
	
	retStmt: RETURN expr;
	
	callStmt: call;
	
	call: ID LBRACKET argList RBRACKET;
	
	argList: arg args
		| /* empty */
		;
	
	arg: expr;
	
	args: COLON argList
		| /* empty */
	
	assignStmt: assign;
	
	assign: ID ASSIGN expr
		| ID LBRACKET INTNUM RBRACKET ASSIGN array
		;
	
	array: ID LBRACKET INTNUM RBRACKET;
	
	expr: UNOP expr
		| INTNUM
		| FLOATNUM
		| ID
		| LPARENT expr RPARENT
		| callStmt
		| expr exprs
		;
		
	exprs: PLUS expr
		| MINUS expr
		| DIV expr
		| MULT expr
		| LT expr
		| NE expr
		| EQ expr
		| GT expr
		| LE expr
		| GE expr
		;
		
%%
