
typedef enum
{eInt = 0,eFloat} Typee;
typedef enum
{eNegative} Unop;
typedef enum
{eAssign,eCall,eRet,eWhile,eDoWhile,eFor,eIf,eCompound,eSemi} Stmt;
typedef enum
{eUnop,eBinop,eCallExpr,eIntnum,eFloatnum,eId,eExpr} Expre;
typedef enum
{ePlus,eMinus,eMult,eDiv,eLT,eGT,eLTE,eGTE,eEQ,eNEQ} Binop;

struct PROGRAM
{
	struct DECLARATION *DeclList;
	struct FUNCTION * FuncList;
};

struct PROGRAM *root;

struct DECLARATION
{
	Typee t;
	struct IDENTIFIER *ilist;
	struct DECLARATION *prev;
};


struct IDENTIFIER
{
	char *ID;
	int intnum; //zero ,if scalar
	struct IDENTIFIER *prev;

};
struct FUNCTION  // *prev  type id (parameter) {} 
{
	Typee t;
	char *ID;
	struct PARAMETER *ParamList;
	struct COMPOUNDSTMT *CStmt;
	struct FUNCTION *prev;
};

struct PARAMETER
{
	Typee t;
	struct IDENTIFIER *id;
	struct PARAMETER *prev;
};
struct COMPOUNDSTMT // {}
{
	struct DECLARATION *DeclList;
	struct STMT *StmtList;
};

struct STMT 
{	
	Stmt e_stmt;
	union {
		struct ASSIGN *assign_s; // id=expr;
		struct CALL *call_s; //id(arg) 
		struct EXPR *return_s; //return expr
		struct WHILEs *while_s; //while()stmt
		struct DOWHILEs *dowhile_s;//do stmt
		struct FORs *for_s; //for()stmt
		struct IFs *if_s;  //if()stmt
		struct COMPOUNDSTMT *compound_s; // {}
	} stmt; 
	struct STMT *prev;
};


///// id[index]=expr;
struct ASSIGN
{
	char *ID;
	struct EXPR *index; //Null, if LHS is scalar variable
	struct EXPR *expr;  // RHS
};
//// id(arglist?);
struct CALL
{
	char *ID;
	struct ARGLIST *arg;
};
//// (expr,expr*)
struct ARGLIST
{
	struct EXPR *expr;
	struct ARGLIST *prev;

};
///// while(condition)stmt;
struct WHILEs 
{
	struct EXPR *condition;
	struct STMT *stmt;

};
////do stmt; while(condition);
struct DOWHILEs 
{
	struct EXPR *condition;
	struct STMT *stmt;

};
/// for(init;condition;next)stmt;
struct FORs
{
	struct ASSIGN *init;
	struct EXPR *condition;
	struct ASSIGN *next;
	struct STMT *stmt; 

};

//// if(condition)if_s else else_s
struct IFs
{
	struct EXPR *condition;
	struct STMT *if_s;
	struct STMT *else_s; //NUll, if 'else' not exist
};
struct EXPR
{
	Expre e_expr;   // EXPR type (enumeration type)
	union
	{
		int intnum; //int
		float floatnum; // float
		struct UNOP *unop_expr; //-expr
		struct BINOP *binop_expr; // expr A expr
		struct CALL *call_expr; //call
		struct EXPR *bracket; //(expr)
		struct IDs *ID_expr; //id[expr]
	} expression;
};
struct UNOP
{
	Unop u;
	struct EXPR *expr;
};
///  expr1+ expr2
struct BINOP
{
	Binop bi;
	struct EXPR *expr1;
	struct EXPR *expr2;
};
/// id[expr]
struct IDs
{
	char *ID;
	struct EXPR *expr; //NULL , if scalar variable
};
