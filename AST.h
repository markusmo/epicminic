
typedef enum
{eINT,eFLOAT} Typee;

typedef enum
{eassign,ecall,eret,ewhile,efor,eif,ecompound,esemi} Stmt;

typedef enum
{eunop,ebinop,eecall,eintnum,efloatnum,eid,eid2,eexpr} Expre;
typedef enum
{eplus,eminus,emod,epmod,elt,egt,elte,egte,eeq,eneq} Binop;



struct PROGRAM
{
	struct DECLARATION *DeclList;
	struct FUNCTION * FuncList;
};

struct DECLARATION
{
	Typee t; 
	struct IDENTIFIER *ilist;
	struct DECLARATION *prev;	
};

struct IDENTIFIER
{
	char *ID;
	int intnum;
	struct IDENTIFIER *prev;
};

struct FUNCTION
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
struct COMPOUNDSTMT
{
	struct DECLARATION *DeclList;
	struct STMT *StmtList;
};

struct STMT ////////////////////
{	
	Stmt s;
	void *inner;
	struct STMT *prev;
};

struct ASSIGN
{
	char *ID;
	struct EXPR *expr1;
	struct EXPR *expr2;
};
struct CALL
{
	char *ID;
	struct ARGLIST *arg;
};
struct ARGLIST
{
	struct EXPR *expr;
	struct ARGLIST *prev;

};

struct WHILEs ///////////////////
{
	struct EXPR *condition;
	struct STMT *stmt;


};
struct FORs
{
	struct ASSIGN *init;
	struct EXPR *condition;
	struct ASSIGN *calc;
	struct STMT *stmt; ////////////////

};

struct IFs /////////////////////////
{
	struct EXPR *condition;
	struct STMT *stmt;
	struct STMT *stmt2;
};
struct EXPR
{
	Expre aa;
	int intnum;
	float floatnum;
	void *inner;
};
struct BINOP
{
	struct EXPR *expr1;
	Binop bi; 
	struct EXPR *expr2;
};
struct IDs
{
	char *ID;
	struct EXPR *expr;
};
