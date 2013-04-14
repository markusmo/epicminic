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
 #include <string.h>

 extern struct PROGRAM *root;
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
 %type <assignstmt> assignStmt assign
 %type <callstmt> callStmt call
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
					root = (struct PROGRAM *) malloc(sizeof(struct PROGRAM));
					root->DeclList = $1; 
					root->FuncList = $2; 
				}
  | decList   			{ 	
					root = (struct PROGRAM *) malloc(sizeof(struct PROGRAM));
					root->FuncList = NULL;
					root->DeclList = $1;
				}
  | funcList  			{ 	
					root = (struct PROGRAM *) malloc(sizeof(struct PROGRAM));
					root->FuncList = $1; 
					root->DeclList = NULL; 
				}
  | /* empty */  		{ 	
					root = (struct PROGRAM *) malloc(sizeof(struct PROGRAM));
					root->FuncList = NULL;
					root->DeclList = NULL;
				}
  ;


 /* ########### FUNCLIST ########### */
 
 funcList: function   		{
					printf("funclist 1\n");
					$$ = $1; 
				}
  | funcList function  		{
					printf("funclist 2\n");
					$1->prev = $2; 
					$$ = $1; 
				}
  ;


 /* ########### DECLIST ########### */
 
 decList: declaration  		{ 
					$$ = $1; 
				}
  | decList declaration  	{ 
					$1->prev = $2;
					$$ = $1;
				}
  ;
 

 /* ########### DECLARATION ########### */

 declaration: type identList SEMICOLON 	{
						$$ = (struct DECLARATION *) malloc(sizeof(struct DECLARATION));
						$$->t = $1; 
						$$->ilist = $2; 
						$$->prev = NULL; 
					};
 

 /* ########### IDENTLIST ########### */

 identList: identifier   { $$ = $1; }
  | identList COLON identifier { $1->prev = $3; }
  ;
 

 /* ########### IDENTIFIER ########### */

  identifier: ID    			{
						
						$$ = (struct IDENTIFIER *) malloc(sizeof(struct IDENTIFIER));
						$$->ID = $1;
					}
  | ID LBRACKET INTNUM RBRACKET 	{ 
						$$ = (struct IDENTIFIER *) malloc(sizeof(struct IDENTIFIER));
						$$->ID = $1; 
						$$->intnum = $3; 
					}
  ;


 /* ########### FUNCTION ########### */

 function: type ID LPARENT paramList RPARENT compoundStatement 		{ 
										printf("%s\n", $2);
										$$ = (struct FUNCTION *) malloc(sizeof(struct FUNCTION)); 
										$$->t = $1; 
										$$->ID = $2;
										$$->ParamList = $4; 
										$$->CStmt = $6; 
										$$->prev = NULL; 
									}
  | type ID LPARENT RPARENT compoundStatement   			{
										printf("function 1\n");
										$$ = (struct FUNCTION *) malloc(sizeof(struct FUNCTION));
										$$->t = $1; 
										$$->ID = $2;
										$$->CStmt = $5; 
										$$->prev = NULL;  
									}
  ;
 

 /* ########### PARAMLIST ########### */

 paramList: type identifier  	{ 
					$$ = (struct PARAMETER *) malloc(sizeof(struct PARAMETER));
					$$->t = $1; 
					$$->id = $2; 
				}
  | paramList COLON type identifier 	{ 
					$$ = (struct PARAMETER *) malloc(sizeof(struct PARAMETER)); 
					$$->t = $3; 
					$$->id = $4; 
					$$->prev = $1; 
				}
  ;


 /* ########### TYPE ########### */

 type: INT   { $$ = eInt; }
  | FLOAT  { $$ = eFloat; }
  ;


 /* ########### COMPOUNDSTATEMENT ########### */ 

 compoundStatement: LFANCYBRACKET stmtList RFANCYBRACKET   	{
									$$ = (struct COMPOUNDSTMT *) malloc(sizeof(struct COMPOUNDSTMT));
									$$->StmtList = $2;  
								}
  |   LFANCYBRACKET decList stmtList RFANCYBRACKET  		{ 
									$$ = (struct COMPOUNDSTMT *) malloc(sizeof(struct COMPOUNDSTMT));
									$$->DeclList = $2; 
									$$->StmtList = $3; 
								}
  ;	
 

 /* ########### STMTLIST ########### */

 stmtList: statement  { $$ = $1; }
  | stmtList statement   { $2->prev = $1; $$ = $2; }
  //| /* empty */  { }  ----> TODO shift / reduce
  ;

 
 /* ########### STATEMENT ########### */

 statement: assignStmt  	{ 
					$$ = (struct STMT *) malloc(sizeof(struct STMT));
					$$->e_stmt = eAssign; 
					$$->stmt.assign_s = $1; 
				}
  | callStmt 			{ 
					$$ = (struct STMT *) malloc(sizeof(struct STMT)); 
					$$->e_stmt = eCall; 
					$$->stmt.call_s = $1; 
				}
  | retStmt  			{ 
					$$ = (struct STMT *) malloc(sizeof(struct STMT));
					$$->e_stmt = eRet; 
					$$->stmt.return_s = $1; 
				}
  | whileStmt  			{ 
					$$ = (struct STMT *) malloc(sizeof(struct STMT));
					$$->e_stmt = eWhile; 
					$$->stmt.while_s = $1; 
				}
  | forStmt  			{ 
					$$ = (struct STMT *) malloc(sizeof(struct STMT));
					$$->e_stmt = eFor; 
					$$->stmt.for_s = $1;
				}
  | ifStmt  			{ 
					$$ = (struct STMT *) malloc(sizeof(struct STMT));
					$$->e_stmt = eIf; 
					$$->stmt.if_s = $1; 
				}
  | compoundStatement 		{ 
					$$ = (struct STMT *) malloc(sizeof(struct STMT));
					$$->e_stmt = eCompound; 
					$$->stmt.compound_s = $1; 
				}
  | SEMICOLON  			{ 
					$$ = (struct STMT *) malloc(sizeof(struct STMT));
					$$->e_stmt = eSemi; 

				}
  ;


 /* ########### ASSIGNSTMT ########### */ 

 assignStmt: assign SEMICOLON;

 assign: ID ASSIGN expr					{ 
								$$ = (struct ASSIGN *) malloc(sizeof(struct ASSIGN));
								$$->ID = $1; 
								$$->expr = $3; 
							}
	| ID LBRACKET expr RBRACKET ASSIGN expr 	{ 
								$$ = (struct ASSIGN *) malloc(sizeof(struct ASSIGN));
								$$->ID = $1; 
								$$->index = $3; 
								$$->expr = $6; 
							}
   ;

 /* ########### CALLSTMT ########### */

 callStmt: call SEMICOLON;

 call: ID LPARENT argList RPARENT		{ 
							$$ = (struct CALL *) malloc(sizeof(struct CALL));
							$$->ID = $1; 
							$$->arg = $3; 
						}
   | ID LPARENT RPARENT				{
							$$ = (struct CALL *) malloc(sizeof(struct CALL)); 
							$$->ID = $1; 
						}
   ;
 

 /* ########### RETSTMT ########### */

 retStmt: RETURN expr SEMICOLON    	{ 
						$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
						$$->e_expr = eExpr; 
						$$->expression.bracket = $2; 
					}
  | RETURN SEMICOLON    		{ 
						$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
						$$->e_expr = eExpr; 
					}
  ;
 

 /* ########### WHILESTMT ########### */

 whileStmt: WHILE LPARENT expr RPARENT statement    	{ 
								$$ = (struct WHILEs *) malloc(sizeof(struct WHILEs));
								$$->condition = $3; 
								$$->stmt = $5; 
							}
  | DO statement WHILE LPARENT expr RPARENT SEMICOLON  	{ 
								$$ = (struct WHILEs *) malloc(sizeof(struct WHILEs));
								$$->condition = $5; 
								$$->stmt = $2; 
							}
  ;

 
 /* ########### FORSTMT ########### */
 forStmt: FOR LPARENT assign SEMICOLON expr SEMICOLON assign RPARENT statement 	{ 
												$$ = (struct FORs *) malloc(sizeof(struct FORs));
												$$->init = $3; 
												$$->condition = $5; 
												$$->next = $7; 
												$$->stmt = $9; 
											} ;
 

 /* ########### IFSTMT ########### */
 ifStmt: IF LPARENT expr RPARENT statement    		{ 
								$$ = (struct IFs *) malloc(sizeof(struct IFs));
								$$->condition = $3; 
								$$->if_s = $5; 
							}
  | IF LPARENT expr RPARENT statement ELSE statement 	{ 
								$$ = (struct IFs *) malloc(sizeof(struct IFs));
								$$->condition = $3; 
								$$->if_s = $5; 
								$$->else_s = $7; 
							}
  ;
 

 /* ########### EXPR ########### */

expr: expr PLUS expr      	{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					$$->e_expr = eBinop; 
					$$->expression.binop_expr->bi = ePlus; 
					$$->expression.binop_expr->expr1 = $1;
					$$->expression.binop_expr->expr2 = $3;
				}
  | expr MINUS expr     	{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					$$->e_expr = eBinop; 
					$$->expression.binop_expr->bi = eMinus; 
					$$->expression.binop_expr->expr1 = $1;
					$$->expression.binop_expr->expr2 = $3;
				}
  | expr MULT expr     		{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					$$->e_expr = eBinop; 
					$$->expression.binop_expr->bi = eMult; 
					$$->expression.binop_expr->expr1 = $1;
					$$->expression.binop_expr->expr2 = $3;
				}
  | expr DIV expr     		{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					$$->e_expr = eBinop; 
					$$->expression.binop_expr->bi = eDiv; 
					$$->expression.binop_expr->expr1 = $1;
					$$->expression.binop_expr->expr2 = $3;
				}
  | expr LT expr     	 	{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					$$->e_expr = eBinop; 
					$$->expression.binop_expr->bi = eLT; 
					$$->expression.binop_expr->expr1 = $1;
					$$->expression.binop_expr->expr2 = $3;
				}
  | expr LE expr      		{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					$$->e_expr = eBinop; 
					$$->expression.binop_expr->bi = eLTE; 
					$$->expression.binop_expr->expr1 = $1;
					$$->expression.binop_expr->expr2 = $3;
				}
  | expr GT expr      		{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					$$->e_expr = eBinop; 
					$$->expression.binop_expr->bi = eGT; 
					$$->expression.binop_expr->expr1 = $1;
					$$->expression.binop_expr->expr2 = $3;
				}
  | expr GE expr      		{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					$$->e_expr = eBinop; 
					$$->expression.binop_expr->bi = eGTE; 
					$$->expression.binop_expr->expr1 = $1;
					$$->expression.binop_expr->expr2 = $3;
				}
  | expr EQ expr     		{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					$$->e_expr = eBinop; 
					$$->expression.binop_expr->bi = eEQ; 
					$$->expression.binop_expr->expr1 = $1;
					$$->expression.binop_expr->expr2 = $3;
				}
  | expr NE expr     		{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					$$->e_expr = eBinop; 
					$$->expression.binop_expr->bi = eNEQ; 
					$$->expression.binop_expr->expr1 = $1;
					$$->expression.binop_expr->expr2 = $3;
				}
  | MINUS expr     		{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->expression.unop_expr = (struct UNOP *) malloc(sizeof(struct UNOP));
					$$->e_expr = eUnop; 
					$$->expression.unop_expr->u = eNegative; 
					$$->expression.unop_expr->expr = $2;
				}
  | INTNUM      		{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->e_expr = eIntnum; 
					$$->expression.intnum = $1;  
				}
  | FLOATNUM      		{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->e_expr = eFloatnum; 
					$$->expression.floatnum = $1; 
				}
  | ID       			{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->expression.ID_expr = (struct IDs *) malloc(sizeof(struct IDs));
					$$->e_expr = eId; 
					$$->expression.ID_expr->ID = $1; 
				}
  | ID LBRACKET expr RBRACKET   { 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->expression.ID_expr = (struct IDs *) malloc(sizeof(struct IDs)); 
					$$->e_expr = eId; 
					$$->expression.ID_expr->ID = $1; 
					$$->expression.ID_expr->expr = $3; 
				}
  | LPARENT expr RPARENT    	{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR)); 
					$$->e_expr = eExpr; 
					$$->expression.bracket = $2; 
				}
  | call     		{ 
					$$ = (struct EXPR *) malloc(sizeof(struct EXPR));
					$$->e_expr = eCallExpr; 
					$$->expression.call_expr = $1; 
				}
  ;
 

 /* ########### ARGLIST ########### */

 argList: expr    		{ 
					$$ = (struct ARGLIST *) malloc(sizeof(struct ARGLIST));
					$$->expr = $1; 
				}
  | expr COLON argList  	{ 
					$$ = (struct ARGLIST *) malloc(sizeof(struct ARGLIST));
					$$->expr = $1; 
					$3->prev = $$; 
				}
  ;

%%
