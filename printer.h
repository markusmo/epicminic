#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "AST.h"

void asdf(FILE *stream);
void printSymbolTable(FILE *stream);

void printFunction(struct FUNCTION *func);
void printParameter(struct PARAMETER *par);
void printCompound(struct COMPOUNDSTMT *comp);
void printStatement(struct STMT *stmt);
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
void printFor(struct FORs *fr);
void printIf(struct IFs *iff);
void printDeclaration(struct DECLARATION* decl);
void printIdentifier(struct IDENTIFIER* identifier);
