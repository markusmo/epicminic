#if !defined(AST)
#define AST
#include "../AST.h"
#endif

void generateLiveliness(FILE *astStreamPar);

void liveFunction(struct FUNCTION *func);
void liveParameter(struct PARAMETER *par);
Block* liveCompound(struct COMPOUNDSTMT *comp, int functionComp, Block* currBlockP);
Block* liveStatement(struct STMT *stmt, int isAlreadyDeeper, Block* currBlock);
void liveExpr(struct EXPR *expr);
void liveInt(int i);
void liveFloat(float f);
void liveUnop(struct UNOP *un);
void liveBinop(struct BINOP *bin);
void liveIDs(struct IDs *ids);
void liveArgument(struct ARGLIST *arg);
void liveAssign(struct ASSIGN *assign);
void liveCall(struct CALL *call);
Block* liveWhile(struct WHILEs *whil, Block* currBlock, struct STMT *currStmt);
Block* liveDoWhile(struct DOWHILEs *dowhile, Block* currBlock, struct STMT *currStmt);
Block* liveFor(struct FORs *fr, Block* currBlock, struct STMT *currStmt);
Block* liveIf(struct IFs *iff, Block* currentBlock);
void liveDeclaration(struct DECLARATION* decl);
void liveIdentifier(struct IDENTIFIER* identifier);
void liveInt(int i);
void liveFloat(float f);
