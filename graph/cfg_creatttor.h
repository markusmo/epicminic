#if !defined(AST)
#define AST
#include "../AST.h"
#endif

void generateCFG(FILE *astStreamPar);

void gotoFunction(struct FUNCTION *func);
void gotoParameter(struct PARAMETER *par);
void gotoCompound(struct COMPOUNDSTMT *comp, int functionComp, Block* currBlockP);
Block* gotoStatement(struct STMT *stmt, int isAlreadyDeeper, Block* currBlock);
void gotoExpr(struct EXPR *expr);
void gotoInt(int i);
void gotoFloat(float f);
void gotoUnop(struct UNOP *un);
void gotoBinop(struct BINOP *bin);
void gotoIDs(struct IDs *ids);
void gotoArgument(struct ARGLIST *arg);
void gotoAssign(struct ASSIGN *assign);
void gotoCall(struct CALL *call);
void gotoWhile(struct WHILEs *whil, Block* currBlock);
void gotoDoWhile(struct DOWHILEs *dowhile, Block* currBlock);
void gotoFor(struct FORs *fr, Block* currBlock);
Block* gotoIf(struct IFs *iff, Block* currentBlock);
void gotoDeclaration(struct DECLARATION* decl);
void gotoIdentifier(struct IDENTIFIER* identifier);
void gotoInt(int i);
void gotoFloat(float f);

char* getTypeString(Typee type);
char* getUnopString(Unop unop);
char* getBinopString(Binop binop);
