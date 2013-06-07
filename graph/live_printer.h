#if !defined(AST)
#define AST
#include "AST.h"
#endif

void printLiveFunction(struct FUNCTION *func);
void printLiveParameter(struct PARAMETER *par);
void printLiveCompound(struct COMPOUNDSTMT *comp);
void printLiveStatement(struct STMT *stmt);
void printLiveExpr(struct EXPR *expr);
void printLiveInt(int i);
void printLiveFloat(float f);
void printLiveUnop(struct UNOP *un);
void printLiveBinop(struct BINOP *bin);
void printLiveIDs(struct IDs *ids);
void printLiveArgument(struct ARGLIST *arg);
void printLiveAssign(struct ASSIGN *assign);
void printLiveCall(struct CALL *call);
void printLiveWhile(struct WHILEs *whil);
void printLiveDoWhile(struct DOWHILEs *dowhile);
void printLiveFor(struct FORs *fr);
void printLiveIf(struct IFs *iff);
void printLiveDeclaration(struct DECLARATION* decl);
void printLiveIdentifier(struct IDENTIFIER* identifier);
void printLiveInt(int i);
void printLiveFloat(float f);
