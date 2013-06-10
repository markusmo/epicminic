#if !defined(AST)
#define AST
#include "../AST.h"
#endif

void generateCFG(FILE *astStreamPar);

void gotoFunction(struct FUNCTION *func, CFG* cfg);
void gotoParameter(struct PARAMETER *par, CFG* cfg);
Block* gotoCompound(struct COMPOUNDSTMT *comp, int functionComp, Block* currBlockP, CFG* cfg);
Block* gotoStatement(struct STMT *stmt, int isAlreadyDeeper, Block* currBlock, CFG* cfg);
void gotoExpr(struct EXPR *expr, CFG* cfg);
void gotoInt(int i);
void gotoFloat(float f);
void gotoUnop(struct UNOP *un, CFG* cfg);
void gotoBinop(struct BINOP *bin, CFG* cfg);
void gotoIDs(struct IDs *ids, CFG* cfg);
void gotoArgument(struct ARGLIST *arg, CFG* cfg);
void gotoAssign(struct ASSIGN *assign, CFG* cfg);
void gotoCall(struct CALL *call, CFG* cfg);
Block* gotoWhile(struct WHILEs *whil, Block* currBlock, struct STMT *currStmt, CFG* cfg);
Block* gotoDoWhile(struct DOWHILEs *dowhile, Block* currBlock, struct STMT *currStmt, CFG* cfg);
Block* gotoFor(struct FORs *fr, Block* currBlock, struct STMT *currStmt, CFG* cfg);
Block* gotoIf(struct IFs *iff, Block* currentBlock, CFG* cfg);
void gotoDeclaration(struct DECLARATION* decl, CFG* cfg);
void gotoIdentifier(struct IDENTIFIER* identifier, CFG* cfg);
