%{
	#include <stdio.h>
	#include <stdlib.h>
%}

%union{
	int ivalue;
    	float fvalue;
	ARGLIST *arglist
	IFs *ifstmt
	STMT *stmt
	FORs *forstmt
	ASSIGN *assignstmt
	CALL *callstmt
	WHILEs *whilestmt
}

	%type <ivalue> expr
	%type <arglist> argList
	%type <ifstmt> ifStmt
	%type <stmt> statement
	%type <forstmt> forStmt
	%type <assignstmt> assignStmt
	%type <callstmt> callStmt
	%type <whilestmt> whileStmt

	%token INT
	%token <ivalue> INTNUM
	%token FLOAT
	%token <fvalue> FLOATNUM
	%token FOR WHILE DO
	%token IF ELSE
	%token RETURN
	%token <string> ID
	%token DIV MULT PLUS MINUS LT NE EQ GT LE GE ASSIGN
	%token LPARENT RPARENT LFANCYBRACKET RFANCYBRACKET LBRACKET RBRACKET
	%token SEMICOLON COLON
	
	%right ASSIGN
	%left LE GE EQ NE LT GT
	%right MINUS PLUS DIV MULT
	%right RPARENT ELSE
	%right COLON
	%left LPARENT SEMICOLON

%%
	program: decList funcList	
		| decList 		
		| funcList		
		| /* empty */		
		;
	
	funcList: function 		{ $$ = $1; }
		| function funcList	{ $2->prev = $1; }
		;
	
	decList: declaration		{ $$ = $1; }
		| decList declaration 	{ $2->prev = $1; }
		;
	
	declaration: type identList SEMICOLON;
	
	identList: ID
		| ID COLON identList
		;
		
	function: type ID LPARENT paramList RPARENT compoundStatement	{ struct FUNCTION f; f.t = $1; f.ID = $2; f.ParamList = $4; f.CompoundStatement = $6; $$ = f; };
	
	paramList: param
		| param paramList
		;
	
	param: type ID;
	
	type: INT 
		| FLOAT
		;
	
	compoundStatement: LFANCYBRACKET decList stmtList RFANCYBRACKET { struct COMPOUNDSTMT c; c.DeclList = $2; c.StmtList = $3; $$ = c };
	
	stmtList: statement		{ $$ = $1; }
		| statement stmtList	{ $2->prev = $1; }
		;
	
	statement: assignStmt		{ struct STMT s; s.e_stmt = Stmt.eAssign; s.stmt = $1; $$ = s}
		| callStmt		{ struct STMT s; s.e_stmt = Stmt.eCall; s.stmt = $1; $$ = s}
		| retStmt		{ struct STMT s; s.e_stmt = Stmt.eRet; s.stmt = $1; $$ = s }
		| whileStmt		{ struct STMT s; s.e_stmt = Stmt.eWhile; s.stmt = $1; $$ = s }
		| forStmt		{ struct STMT s; s.e_stmt = Stmt.eFor; s.stmt = $1; $$ = s }
		| ifStmt		{ struct STMT s; s.e_stmt = Stmt.eIf; s.stmt = $1; $$ = s }
		| compoundStatement	{ struct STMT s; s.e_stmt = Stmt.eCompound; s.stmt = $1; $$ = s }
		| SEMICOLON		{ struct STMT s; s.e_stmt = Stmt.eSemi; $$ = s }
		;
	
	assignStmt: ID ASSIGN expr 					{ struct ASSIGN a; a.id = $1; a.expr = $3; $$ = a }
		| ID LBRACKET expr RBRACKET ASSIGN expr		{ struct ASSIGN a; a.id = $1; a.index = $3; a.expr = $6; $$ = a }
		;
	
	callStmt: ID LPARENT argList RPARENT	{ struct CALL c; c.id = $1; c.arg = $3; $$ = c };
	
	retStmt: RETURN expr SEMICOLON		{ struct EXPR e; e.e_expr = Expre.eExpr; e.expression = $2 };		
	
	whileStmt: WHILE LPARENT expr RPARENT statement			{ struct WHILEs w; w.condition = $3; w.stmt = $5; $$ = w }
		| DO expr WHILE LPARENT expr RPARENT SEMICOLON		{ struct WHILEs w; w.condition = $2; w.stmt = $5; $$ = w }
		;
	
	forStmt: FOR LPARENT assign SEMICOLON expr SEMICOLON assign RPARENT statement { struct FORs f; f.init = $3; f.condition = $5; f.next = $7; f.stmt = $9; $$ = f } ;
	
	ifStmt: IF LPARENT expr RPARENT statement 			{ struct IFS i; i.condition = $3; i.if_s = $5; $$ = i; }
		| IF LPARENT expr RPARENT statement ELSE statement	{ struct IFS i; i.condition = $3; i.if_s = $5; i.else_s = $7; $$ = i; }
		;
	
	expr: expr PLUS expr 			{ struct BINOP b; b.bi = Binop.ePlus; e.expr1 = $1; e.expr2 = $3; $$ = e }
		| expr MINUS expr 		{ struct BINOP b; b.bi = Binop.eMinus; e.expr1 = $1; e.expr2 = $3; $$ = e }
		| expr MULT expr 		{ struct BINOP b; b.bi = Binop.eMult; e.expr1 = $1; e.expr2 = $3; $$ = e }
		| expr DIV expr 		{ struct BINOP b; b.bi = Binop.eDiv; e.expr1 = $1; e.expr2 = $3; $$ = e }
		| expr LT expr 			{ struct BINOP b; b.bi = Binop.eLT; e.expr1 = $1; e.expr2 = $3; $$ = e }
		| expr LE expr 			{ struct BINOP b; b.bi = Binop.eLTE; e.expr1 = $1; e.expr2 = $3; $$ = e }
		| expr GT expr 			{ struct BINOP b; b.bi = Binop.eGT; e.expr1 = $1; e.expr2 = $3; $$ = e }
		| expr GE expr 			{ struct BINOP b; b.bi = Binop.eGTE; e.expr1 = $1; e.expr2 = $3; $$ = e }
		| expr EQ expr			{ struct BINOP b; b.bi = Binop.eEQ; e.expr1 = $1; e.expr2 = $3; $$ = e }
		| expr NE expr			{ struct BINOP b; b.bi = Binop.eNEQ; e.expr1 = $1; e.expr2 = $3; $$ = e }
		| INTNUM 			{ struct EXPR e; e.e_expr = Expre.eIntnum; e.expression = $1; $$ = e }
		| FLOATNUM 			{ struct EXPR e; e.e_expr = Expre.eFloatnum; e.expression = $1; $$ = e }
		| ID 				{ struct EXPR e; e.e_expr = Expre.eId; e.expression = $1; $$ = e }
		| ID LBRACKET expr RBRACKET 	{ struct IDs i; i.ID = $1; i.expr = $3; $$ = e }
		| LPARENT expr RPARENT		{ struct EXPR e; e.e_expr = Expre.eExpr; e.expression = $2; $$ = e }
		;
	
	argList: expr				{ struct ARGLIST a; a.expr = $1; $$ = a }
		| expr COLON argList		{ struct ARGLIST a; a.expr = $1; a.prev = $3; $$ = a }
		;

%%
