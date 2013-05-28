#if !defined(AST)
#define AST
#include "AST.h"
#endif

void generateOutput(FILE *astStreamPar, FILE *tableStream);

void printFunction(struct FUNCTION *func);
void printParameter(struct PARAMETER *par);
void printCompound(struct COMPOUNDSTMT *comp);
void printStatement(struct STMT *stmt, int isAlreadyDeeper);
void printExpr(struct EXPR *expr);
void printInt(int i);
void printFloat(float f);
void printUnop(struct UNOP *un);
void printBinop(struct BINOP *bin);
void printIDs(struct IDs *ids);
void printArgument(struct ARGLIST *arg);
void printAssign(struct ASSIGN *assign);
void printCall(struct CALL *call);
void printWhile(struct WHILEs *whil);
void printDoWhile(struct DOWHILEs *dowhile);
void printFor(struct FORs *fr);
void printIf(struct IFs *iff);
void printDeclaration(struct DECLARATION* decl);
void printIdentifier(struct IDENTIFIER* identifier);

char* getTypeString(Typee type);
char* getUnopString(Unop unop);
char* getBinopString(Binop binop);
