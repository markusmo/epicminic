/*
   _____ _        __                    _         _ _       __                   _                      _ _
  / ____| |      / _|                  | |       | (_)     / _|                 | |                    | | |
 | (___ | |_ ___| |_ __ _ _ __       __| |_   _  | |_  ___| |_ ___ _ __ ___  ___| |__    _ __   ___  __| | |
  \___ \| __/ _ \  _/ _` | '_ \     / _` | | | | | | |/ _ \  _/ _ \ '__/ __|/ __| '_ \  | '_ \ / _ \/ _` | |
  ____) | ||  __/ || (_| | | | |_  | (_| | |_| | | | |  __/ ||  __/ |  \__ \ (__| | | | | | | |  __/ (_| |_|
 |_____/ \__\___|_| \__,_|_| |_( )  \__,_|\__,_| |_|_|\___|_| \___|_|  |___/\___|_| |_| |_| |_|\___|\__,_(_)
                               |/                                                                          
                                                                                                            
*/

%code top{
 #include <stdio.h>
 #include <stdlib.h>

 extern struct PROGRAM root;
}
%code requires{
 #include "AST.h"
}
%union {
 int ivalue;
 float fvalue;
 Typee typee;
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
 struct IDENTIFIER *idenf;
}

 %type <typee> type
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
 %type <idenf> identifier identList

 %token <type> INT
 %token <ivalue> INTNUM
 %token <type> FLOAT
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

 %start program

%%

 /* ########### PROGRAM ########### */

 program: decList funcList  	{ 	
					root = (PROGRAM *) malloc(sizeof(PROGRAM));
					struct PROGRAM p; 
					p.DeclList = $1; 
					p.FuncList = $2; 
					root = p; 
				}
  | decList   			{ 	
					root = (PROGRAM *) malloc(sizeof(PROGRAM));
					struct PROGRAM p; 
					p.FuncList = NULL; 
					p.DeclList = $1; 
					root = p; 
				}
  | funcList  			{ 	
					root = (PROGRAM *) malloc(sizeof(PROGRAM));
					struct PROGRAM p; 
					p.FuncList = $1; 
					p.DeclList = NULL; 
					root = p; 
				}
  | /* empty */  		{ 	
					root = (PROGRAM *) malloc(sizeof(PROGRAM));
					root.FuncList = NULL; 
					root.DeclList = NULL; 
				}
  ;


 /* ########### FUNCLIST ########### */
 
 funcList: function   		{ 
					$$ = $1; 
				}
  | funcList function  		{ 
					$2->prev = $1; 
					$$ = $2; 
				}
  ;


 /* ########### DECLIST ########### */
 
 decList: declaration  		{ 
					$$ = $1; 
				}
  | decList declaration  	{ 
					$$ = (DECLARATION *) malloc(sizeof(DECLARATION));
					struct DECLARATION* d; 
					d = $2; d->prev = $1; 
					$$ = d; 
				}
  ;
 

 /* ########### DECLARATION ########### */

 declaration: type identList SEMICOLON 	{ 
						$$ = (DECLARATION *) malloc(sizeof(DECLARATION));
						struct DECLARATION d; 
						d.t = $1; 
						d.ilist = $2; 
						d.prev = NULL; 
						$$ = &d; 
					};
 

 /* ########### IDENTLIST ########### */

 identList: identifier   { $$ = $1; }
  | identList COLON identifier { $1->prev = $3; }
  ;
 

 /* ########### IDENTIFIER ########### */

  identifier: ID    			{ 
						$$ = (IDENTIFIER *) malloc(sizeof(IDENTIFIER));
						struct IDENTIFIER i; 
						i.ID = $1; 
						$$ = &i; 
					}
  | ID LBRACKET INTNUM RBRACKET 	{ 
						struct IDENTIFIER i; 
						i.ID = $1; 
						i.intnum = $3; 
						$$ = &i; 
					}
  ;


 /* ########### FUNCTION ########### */

 function: type ID LPARENT paramList RPARENT compoundStatement 		{ 
										$$ = (FUNCTION *) malloc(sizeof(FUNCTION));
										struct FUNCTION f; 
										f.t = $1; 
										f.ID = $2; 
										f.ParamList = $4; 
										f.CStmt = $6; 
										f.prev = NULL; 
										$$ = &f; 
									}
  | type ID LPARENT RPARENT compoundStatement   			{ 
										$$ = (FUNCTION *) malloc(sizeof(FUNCTION));
										struct FUNCTION f; 
										f.t = $1; 
										f.ID = $2; 
										f.CStmt = $5; 
										f.prev = NULL; 
										$$ = &f; 
									}
  ;
 

 /* ########### PARAMLIST ########### */

 paramList: type identifier  	{ 
					$$ = (PARAMETER *) malloc(sizeof(PARAMETER));
					struct PARAMETER p; 
					p.t = $1; 
					p.id = $2; 
					$$ = &p; 
				}
  | paramList type identifier 	{ 
					$$ = (PARAMETER *) malloc(sizeof(PARAMETER));
					struct PARAMETER p; 
					p.t = $2; 
					p.id = $3; 
					$1->prev = &p; 
					$$ = &p; 
				}
  ;


 /* ########### TYPE ########### */

 type: INT   { $$ = eInt; }
  | FLOAT  { $$ = eFloat; }
  ;


 /* ########### COMPOUNDSTATEMENT ########### */ 

 compoundStatement: LFANCYBRACKET stmtList RFANCYBRACKET   	{ 
									$$ = (COMPOUNDSTMT *) malloc(sizeof(COMPOUNDSTMT));
									struct COMPOUNDSTMT c; 
									c.StmtList = $2; 
									$$ = &c; 
								}
  |   LFANCYBRACKET decList stmtList RFANCYBRACKET  		{ 
									$$ = (COMPOUNDSTMT *) malloc(sizeof(COMPOUNDSTMT));
									struct COMPOUNDSTMT c; 
									c.DeclList = $2; 
									c.StmtList = $3; 
									$$ = &c; 
								}
  ;	
 

 /* ########### STMTLIST ########### */

 stmtList: statement  { $$ = $1; }
  | stmtList statement   { $1->prev = $2; }
  //| /* empty */  { }  ----> TODO shift / reduce
  ;

 
 /* ########### STATEMENT ########### */

 statement: assignStmt  	{ 
					$$ = (STMT *) malloc(sizeof(STMT));
					struct STMT s; 
					s.e_stmt = eAssign; 
					s.stmt.assign_s = $1; 
					$$ = &s; 
				}
  | callStmt 			{ 
					$$ = (STMT *) malloc(sizeof(STMT));
					struct STMT s; 
					s.e_stmt = eCall; 
					s.stmt.call_s = $1; 
					$$ = &s; 
				}
  | retStmt  			{ 
					$$ = (STMT *) malloc(sizeof(STMT));
					struct STMT s; 
					s.e_stmt = eRet; 
					s.stmt.return_s = $1; 
					$$ = &s; 
				}
  | whileStmt  			{ 
					$$ = (STMT *) malloc(sizeof(STMT));
					struct STMT s; 
					s.e_stmt = eWhile; 
					s.stmt.while_s = $1; 
					$$ = &s; 
				}
  | forStmt  			{ 
					$$ = (STMT *) malloc(sizeof(STMT));
					struct STMT s; 
					s.e_stmt = eFor; 
					s.stmt.for_s = $1; 
					$$ = &s; 
				}
  | ifStmt  			{ 
					$$ = (STMT *) malloc(sizeof(STMT));
					struct STMT s; 
					s.e_stmt = eIf; 
					s.stmt.if_s = $1; 
					$$ = &s; 
				}
  | compoundStatement 		{ 
					$$ = (STMT *) malloc(sizeof(STMT));
					struct STMT s; 
					s.e_stmt = eCompound; 
					s.stmt.compound_s = $1; 
					$$ = &s; 
				}
  | SEMICOLON  			{ 
					$$ = (STMT *) malloc(sizeof(STMT));
					struct STMT s; 
					s.e_stmt = eSemi; 
					$$ = &s; 
				}
  ;


 /* ########### ASSIGNSTMT ########### */ 

 assignStmt: ID ASSIGN expr SEMICOLON    		{ 
								$$ = (ASSIGN *) malloc(sizeof(ASSIGN));
								struct ASSIGN a; 
								a.ID = $1; 
								a.expr = $3; 
								$$ = &a; 
							}
  | ID LBRACKET expr RBRACKET ASSIGN expr SEMICOLON 	{ 
								$$ = (ASSIGN *) malloc(sizeof(ASSIGN));
								struct ASSIGN a; 
								a.ID = $1; 
								a.index = $3; 
								a.expr = $6; 
								$$ = &a; 
							}
  ;
 

 /* ########### CALLSTMT ########### */

 callStmt: ID LPARENT argList RPARENT SEMICOLON { 
							$$ = (CALL *) malloc(sizeof(CALL));
							struct CALL c; 
							c.ID = $1; 
							c.arg = $3; 
							$$ = &c; 
						}
  | ID LPARENT RPARENT SEMICOLON    		{
							$$ = (CALL *) malloc(sizeof(CALL)); 
							struct CALL c; 
							c.ID = $1; 
							$$ = &c; 
						}
  ;
 

 /* ########### RETSTMT ########### */

 retStmt: RETURN expr SEMICOLON    	{ 
						$$ = (EXPR *) malloc(sizeof(EXPR));
						struct EXPR e; 
						e.e_expr = eExpr; 
						e.expression.bracket = $2; 
						$$ = &e; 
					}
  | RETURN SEMICOLON    		{ 
						$$ = (EXPR *) malloc(sizeof(EXPR));
						struct EXPR e; 
						e.e_expr = eExpr; 
						$$ = &e; 
					}
  ;
 

 /* ########### WHILESTMT ########### */

 whileStmt: WHILE LPARENT expr RPARENT statement    	{ 
								$$ = (WHILEs *) malloc(sizeof(
								struct WHILEs w; 
								w.condition = $3; 
								w.stmt = $5; 
								$$ = &w; 
							}
  | DO statement WHILE LPARENT expr RPARENT SEMICOLON  	{ 
								struct WHILEs w; 
								w.condition = $5; 
								w.stmt = $2; 
								$$ = &w; 
							}
  ;

 
 /* ########### FORSTMT ########### */
 forStmt: FOR LPARENT assignStmt SEMICOLON expr SEMICOLON assignStmt RPARENT statement 	{ 
												$$ = (FORs *) malloc(sizeof(FORs));
												struct FORs f; 
												f.init = $3; 
												f.condition = $5; 
												f.next = $7; 
												f.stmt = $9; 
												$$ = &f; 
											} ;
 

 /* ########### IFSTMT ########### */
 ifStmt: IF LPARENT expr RPARENT statement    		{ 
								$$ = (IFs *) malloc(sizeof(IFs));
								struct IFs i; 
								i.condition = $3; 
								i.if_s = $5; 
								$$ = &i; 
							}
  | IF LPARENT expr RPARENT statement ELSE statement 	{ 
								$$ = (IFs *) malloc(sizeof(IFs));
								struct IFs i; 
								i.condition = $3; 
								i.if_s = $5; 
								i.else_s = $7; 
								$$ = &i; 
							}
  ;
 

 /* ########### EXPR ########### */

expr: expr PLUS expr      	{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct BINOP b; 
					struct EXPR e; 
					e.expresision.binop_expr = (BINOP *) malloc(sizeof(BINOP));
					b.bi = ePlus; 
					b.expr1 = $1; 
					b.expr2 = $3; 
					e.e_expr = eBinop; 
					e.expression.binop_expr = &b; 
					$$ = &e; 
				}
  | expr MINUS expr     	{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct BINOP b; 
					struct EXPR e; 
					e.expresision.binop_expr = (BINOP *) malloc(sizeof(BINOP));
					b.bi = eMinus; 
					b.expr1 = $1; 
					b.expr2 = $3; 
					e.e_expr = eBinop; 
					e.expression.binop_expr = &b; 
					$$ = &e; 
				}
  | expr MULT expr     		{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct BINOP b; 
					struct EXPR e; 
					e.expresision.binop_expr = (BINOP *) malloc(sizeof(BINOP));
					b.bi = eMult; 
					b.expr1 = $1; 
					b.expr2 = $3; 
					e.e_expr = eBinop; 
					e.expression.binop_expr = &b; 
					$$ = &e; 
				}
  | expr DIV expr     		{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct BINOP b; 
					struct EXPR e; 
					e.expresision.binop_expr = (BINOP *) malloc(sizeof(BINOP));
					b.bi = eDiv; 
					b.expr1 = $1; 
					b.expr2 = $3; 
					e.e_expr = eBinop; 
					e.expression.binop_expr = &b; 
					$$ = &e; 
				}
  | expr LT expr     	 	{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct BINOP b; 
					struct EXPR e; 
					e.expresision.binop_expr = (BINOP *) malloc(sizeof(BINOP));
					b.bi = eLT; 
					b.expr1 = $1; 
					b.expr2 = $3; 
					e.e_expr = eBinop; 
					e.expression.binop_expr = &b; 
					$$ = &e; 
				}
  | expr LE expr      		{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct BINOP b; 
					struct EXPR e;
					e.expresision.binop_expr = (BINOP *) malloc(sizeof(BINOP)); 
					b.bi = eLTE; 
					b.expr1 = $1; 
					b.expr2 = $3; 
					e.e_expr = eBinop; 
					e.expression.binop_expr = &b; 
					$$ = &e; 
				}
  | expr GT expr      		{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct BINOP b; 
					struct EXPR e; 
					e.expresision.binop_expr = (BINOP *) malloc(sizeof(BINOP)); 
					b.bi = eGT; 
					b.expr1 = $1; 
					b.expr2 = $3; 
					e.e_expr = eBinop; 
					e.expression.binop_expr = &b; 
					$$ = &e; 
				}
  | expr GE expr      		{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct BINOP b; 
					struct EXPR e;
					e.expresision.binop_expr = (BINOP *) malloc(sizeof(BINOP)); 
					b.bi = eGTE; 
					b.expr1 = $1; 
					b.expr2 = $3; 
					e.e_expr = eBinop; 
					e.expression.binop_expr = &b; 
					$$ = &e; 
				}
  | expr EQ expr     		{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct BINOP b; 
					struct EXPR e; 
					e.expresision.binop_expr = (BINOP *) malloc(sizeof(BINOP));
					b.bi = eEQ; 
					b.expr1 = $1; 
					b.expr2 = $3; 
					e.e_expr = eBinop; 
					e.expression.binop_expr = &b; 
					$$ = &e; 
				}
  | expr NE expr     		{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct BINOP b; 
					struct EXPR e; 
					e.expresision.binop_expr = (BINOP *) malloc(sizeof(BINOP));
					b.bi = eNEQ; 
					b.expr1 = $1;
					b.expr2 = $3; 
					e.e_expr = eBinop; 
					e.expression.binop_expr = &b; 
					$$ = &e; 
				}
  | MINUS expr     		{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct UNOP u; 
					struct EXPR e; 
					e.expression.unop_expr = (UNOP *) malloc(sizeof(UNOP));
					u.u = eNegative; 
					e.e_expr = eUnop; 
					e.expression.unop_expr = &u; 
					$$ = &e; 
				}
  | INTNUM      		{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct EXPR e; 
					e.e_expr = eIntnum; 
					e.expression.intnum = $1; 
					$$ = &e; 
				}
  | FLOATNUM      		{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct EXPR e; 
					e.e_expr = eFloatnum; 
					e.expression.floatnum = $1; 
					$$ = &e; 
				}
  | ID       			{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct EXPR e; 
					struct IDs i; 
					e.expression.ID_expr = (IDs *) malloc(sizeof(IDs));
					i.ID = $1; 
					e.e_expr = eId; 
					e.expression.ID_expr = &i; 
					$$ = &e; 
				}
  | ID LBRACKET expr RBRACKET   { 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct EXPR e; 
					struct IDs i;
					e.expression.ID_expr = (IDs *) malloc(sizeof(IDs)); 
					i.ID = $1; 
					i.expr = $3; 
					e.e_expr = eId; 
					e.expression.ID_expr = &i; 
					$$ = &e; 
				}
  | LPARENT expr RPARENT    	{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct EXPR e; 
					e.e_expr = eExpr; 
					e.expression.bracket = $2; 
					$$ = &e; 
				}
  | callStmt     		{ 
					$$ = (EXPR *) malloc(sizeof(EXPR));
					struct EXPR e; 
					e.e_expr = eCallExpr; 
					e.expression.call_expr = $1; 
					$$ = &e; 
				}
  ;
 

 /* ########### ARGLIST ########### */

 argList: expr    		{ 
					$$ = (ARGLIST *) malloc(sizeof(ARGLIST));
					struct ARGLIST a; 
					a.expr = $1; 
					$$ = &a; 
				}
  | expr COLON argList  	{ 
					$$ = (ARGLIST *) malloc(sizeof(ARGLIST));
					struct ARGLIST a; 
					a.expr = $1; 
					a.prev = $3; 
					$$ = &a; 
				}
  ;

%%
