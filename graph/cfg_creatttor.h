#if !defined(AST)
#define AST
#include "AST.h"
#endif

void generateCFG(FILE *astStreamPar);

void gotoFunction(struct FUNCTION *func);
void gotoParameter(struct PARAMETER *par);
void gotoCompound(struct COMPOUNDSTMT *comp);
void gotoStatement(struct STMT *stmt, int isAlreadyDeeper);
void gotoExpr(struct EXPR *expr);
void gotoInt(int i);
void gotoFloat(float f);
void gotoUnop(struct UNOP *un);
void gotoBinop(struct BINOP *bin);
void gotoIDs(struct IDs *ids);
void gotoArgument(struct ARGLIST *arg);
void gotoAssign(struct ASSIGN *assign);
void gotoCall(struct CALL *call);
void gotoWhile(struct WHILEs *whil);
void gotoDoWhile(struct DOWHILEs *dowhile);
void gotoFor(struct FORs *fr);
void gotoIf(struct IFs *iff);
void gotoDeclaration(struct DECLARATION* decl);
void gotoIdentifier(struct IDENTIFIER* identifier);

char* getTypeString(Typee type);
char* getUnopString(Unop unop);
char* getBinopString(Binop binop);
