#if !defined(AST)
#define AST
#include "../AST.h"
#endif

void generateLiveliness(FILE *astStreamPar);

void postOrderTraversal(CFG* graph, Block block);
void postOrderTraversalRec(CFG* graph, Block block, char* traversed);
void liveCompound(struct COMPOUNDSTMT *comp);
void liveStatement(struct STMT *stmt);
void liveExpr(struct EXPR *expr, int use);
void liveIDs(struct IDs *ids, int use);
void liveAssign(struct ASSIGN *assign);
void liveCall(struct CALL *call);
void liveDeclaration(struct DECLARATION* decl);
void liveIdentifier(struct IDENTIFIER* identifier);
