#if !defined(AST)
#define AST
#include "AST.h"
#endif

void printCFGFunction(struct FUNCTION *func);
void printCFGParameter(struct PARAMETER *par);
void printCFGCompound(struct COMPOUNDSTMT *comp);
void printCFGStatement(struct STMT *stmt);
void printCFGExpr(struct EXPR *expr);
void printCFGInt(int i);
void printCFGFloat(float f);
void printCFGUnop(struct UNOP *un);
void printCFGBinop(struct BINOP *bin);
void printCFGIDs(struct IDs *ids);
void printCFGArgument(struct ARGLIST *arg);
void printCFGAssign(struct ASSIGN *assign);
void printCFGCall(struct CALL *call);
void printCFGWhile(struct WHILEs *whil);
void printCFGDoWhile(struct DOWHILEs *dowhile);
void printCFGFor(struct FORs *fr);
void printCFGIf(struct IFs *iff);
void printCFGDeclaration(struct DECLARATION* decl);
void printCFGIdentifier(struct IDENTIFIER* identifier);
void printCFGInt(int i);
void printCFGFloat(float f);

char* getTypeString(Typee type);
char* getUnopString(Unop unop);
char* getBinopString(Binop binop);
