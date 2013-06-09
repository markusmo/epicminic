#if !defined(AST)
#define AST
#include "../AST.h"
#endif

void generateLiveliness(FILE *astStreamPar);

void postOrderTraversal(CFG* graph, Block block);
void postOrderTraversalRec(CFG* graph, Block block, char* traversed);
void liveFunction(struct FUNCTION *func);
void liveParameter(struct PARAMETER *par);
void liveExpr(struct EXPR *expr);
void liveInt(int i);
void liveFloat(float f);
void liveUnop(struct UNOP *un);
void liveBinop(struct BINOP *bin);
void liveIDs(struct IDs *ids);
void liveArgument(struct ARGLIST *arg);
void liveAssign(struct ASSIGN *assign);
void liveCall(struct CALL *call);
void liveDeclaration(struct DECLARATION* decl);
void liveIdentifier(struct IDENTIFIER* identifier);
void liveInt(int i);
void liveFloat(float f);
