%code top{
	#include <stdio.h>
	#include <stdlib.h>
}

%code requires{
	#include "AST.h"
}

%union {
	int ivalue;
    	float fvalue;
	char *string;
	struct PROGRAM *prog;
	struct DECLARATION *decl;
	struct FUNCTION *func;
	struct PARAMETER *param;
	struct COMPOUNDSTMT *cmpstmt;
	struct STMT *stmt;
	struct ASSIGN *assignstmt;
	struct CALL *callstmt;
	struct ARGLIST *arglist;
	struct WHILEs *whilestmt;
	struct FORs *forstmt;
	struct IFs *ifstmt;
	struct EXPR *exp;
	struct BINOP *binop;
	struct IDs *id;
}

	%type <string> type
	%type <arglist> argList
	%type <ifstmt> ifStmt
	%type <stmt> statement stmtList
	%type <forstmt> forStmt
	%type <assignstmt> assignStmt
	%type <callstmt> callStmt
	%type <whilestmt> whileStmt
	%type <func> funcList function
	%type <cmpstmt> compoundStatement
	%type <decl> decList declaration
	%type <param> paramList
	%type <exp> retStmt expr
	%type <prog> program
	%type <id> identifier

	%token <string> INT
	%token <ivalue> INTNUM
	%token <string> FLOAT
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
	program: decList funcList 	{ struct PROGRAM p; p.DeclList = $1; p.FuncList = $2; $$ = &p }
		| decList 		{ struct PROGRAM p; p.DeclList = $1; $$ = &p }
		| funcList		{ struct PROGRAM p; p.FuncList = $1; $$ = &p }
		| /* empty */		{ struct PROGRAM p; $$ = &p }
		;
	
	funcList: function 		{ $$ = $1; }
		| function funcList	{ $2->prev = $1; }
		;
	
	decList: declaration		{ $$ = $1; }
		| decList declaration 	{ $2->prev = $1; }
		;
	
	declaration: type identList SEMICOLON {  };
	
	identList: identifier
		| identifier COLON identList
		;
	
	identifier: ID				{ struct IDs i; i.ID = $1; $$ = &i; }
		| ID LBRACKET expr RBRACKET	{ struct IDs i; i.ID = $1; i.expr = $3; $$ = &i; }
		;

	function: type ID LPARENT paramList RPARENT compoundStatement	{ struct FUNCTION f; f.t = $1; f.ID = $2; f.ParamList = $4; f.CStmt = $6; $$ = &f; };
	
	paramList: type identifier		{ }
		| paramList type identifier	{ }
		;

	type: INT 
		| FLOAT
		;
	
	compoundStatement: LFANCYBRACKET decList stmtList RFANCYBRACKET { struct COMPOUNDSTMT c; c.DeclList = $2; c.StmtList = $3; $$ = &c };
	
	stmtList: statement		{ $$ = $1; }
		| stmtList statement 	{ $2->prev = $1; }
		| /* empty */		{ }
		;
	
	statement: assignStmt		{ struct STMT s; s.e_stmt = eAssign; s.stmt.assign_s = $1; $$ = &s}
		| callStmt		{ struct STMT s; s.e_stmt = eCall; s.stmt.call_s = $1; $$ = &s}
		| retStmt		{ struct STMT s; s.e_stmt = eRet; s.stmt.return_s = $1; $$ = &s }
		| whileStmt		{ struct STMT s; s.e_stmt = eWhile; s.stmt.while_s = $1; $$ = &s }
		| forStmt		{ struct STMT s; s.e_stmt = eFor; s.stmt.for_s = $1; $$ = &s }
		| ifStmt		{ struct STMT s; s.e_stmt = eIf; s.stmt.if_s = $1; $$ = &s }
		| compoundStatement	{ struct STMT s; s.e_stmt = eCompound; s.stmt.compound_s = $1; $$ = &s }
		| SEMICOLON		{ struct STMT s; s.e_stmt = eSemi; $$ = &s }
		;
	
	assignStmt: ID ASSIGN expr SEMICOLON				{ struct ASSIGN a; a.ID = $1; a.expr = $3; $$ = &a }
		| ID LBRACKET expr RBRACKET ASSIGN expr SEMICOLON	{ struct ASSIGN a; a.ID = $1; a.index = $3; a.expr = $6; $$ = &a }
		;
	
	callStmt: ID LPARENT argList RPARENT SEMICOLON	{ struct CALL c; c.ID = $1; c.arg = $3; $$ = &c };
	
	retStmt: RETURN expr SEMICOLON		{ struct EXPR e; e.e_expr = eExpr; e.expression.bracket = $2; $$ = &e };		
	
	whileStmt: WHILE LPARENT expr RPARENT statement			{ struct WHILEs w; w.condition = $3; w.stmt = $5; $$ = &w }
		| DO statement WHILE LPARENT expr RPARENT SEMICOLON		{ struct WHILEs w; w.condition = $5; w.stmt = $2; $$ = &w }
		;
	
	forStmt: FOR LPARENT assignStmt SEMICOLON expr SEMICOLON assignStmt RPARENT statement { struct FORs f; f.init = $3; f.condition = $5; f.next = $7; f.stmt = $9; $$ = &f } ;
	
	ifStmt: IF LPARENT expr RPARENT statement 			{ struct IFs i; i.condition = $3; i.if_s = $5; $$ = &i; }
		| IF LPARENT expr RPARENT statement ELSE statement	{ struct IFs i; i.condition = $3; i.if_s = $5; i.else_s = $7; $$ = &i; }
		;
	
	expr: expr PLUS expr 			{ struct BINOP b; struct EXPR e; b.bi = ePlus; b.expr1 = $1; b.expr2 = $3; e.e_expr = eBinop; e.expression.binop_expr = &b; $$ = &e }
		| expr MINUS expr 		{ struct BINOP b; struct EXPR e; b.bi = eMinus; b.expr1 = $1; b.expr2 = $3; e.e_expr = eBinop; e.expression.binop_expr = &b; $$ = &e }
		| expr MULT expr 		{ struct BINOP b; struct EXPR e; b.bi = eMult; b.expr1 = $1; b.expr2 = $3; e.e_expr = eBinop; e.expression.binop_expr = &b; $$ = &e }
		| expr DIV expr 		{ struct BINOP b; struct EXPR e; b.bi = eDiv; b.expr1 = $1; b.expr2 = $3; e.e_expr = eBinop; e.expression.binop_expr = &b; $$ = &e }
		| expr LT expr 			{ struct BINOP b; struct EXPR e; b.bi = eLT; b.expr1 = $1; b.expr2 = $3; e.e_expr = eBinop; e.expression.binop_expr = &b; $$ = &e }
		| expr LE expr 			{ struct BINOP b; struct EXPR e; b.bi = eLTE; b.expr1 = $1; b.expr2 = $3; e.e_expr = eBinop; e.expression.binop_expr = &b; $$ = &e }
		| expr GT expr 			{ struct BINOP b; struct EXPR e; b.bi = eGT; b.expr1 = $1; b.expr2 = $3; e.e_expr = eBinop; e.expression.binop_expr = &b; $$ = &e }
		| expr GE expr 			{ struct BINOP b; struct EXPR e; b.bi = eGTE; b.expr1 = $1; b.expr2 = $3; e.e_expr = eBinop; e.expression.binop_expr = &b; $$ = &e }
		| expr EQ expr			{ struct BINOP b; struct EXPR e; b.bi = eEQ; b.expr1 = $1; b.expr2 = $3; e.e_expr = eBinop; e.expression.binop_expr = &b; $$ = &e }
		| expr NE expr			{ struct BINOP b; struct EXPR e; b.bi = eNEQ; b.expr1 = $1; b.expr2 = $3; e.e_expr = eBinop; e.expression.binop_expr = &b; $$ = &e }
		| INTNUM 			{ struct EXPR e; e.e_expr = eIntnum; e.expression.intnum = $1; $$ = &e }
		| FLOATNUM 			{ struct EXPR e; e.e_expr = eFloatnum; e.expression.floatnum = $1; $$ = &e }
		| ID 				{ struct EXPR e; struct IDs i; i.ID = $1; e.e_expr = eId; e.expression.ID_expr = &i; $$ = &e }
		| ID LBRACKET expr RBRACKET 	{ struct EXPR e; struct IDs i; i.ID = $1; i.expr = $3; e.e_expr = eId; e.expression.ID_expr = &i; $$ = &e }
		| LPARENT expr RPARENT		{ struct EXPR e; e.e_expr = eExpr; e.expression.bracket = $2; $$ = &e }
		;
	
	argList: expr				{ struct ARGLIST a; a.expr = $1; $$ = &a }
		| expr COLON argList		{ struct ARGLIST a; a.expr = $1; a.prev = $3; $$ = &a }
		;

%%
