#include <stdio.h>
#include <ctype.h>
#include <string.h>
#if !defined(BLOCK)
#define BLOCK
#include "block.h"
#endif
#if !defined(GRAPH)
#define GRAPH
#include "graph.h"
#endif
#if !defined(LIST)
#define LIST
#include "list.h"
#endif
#include "liveliness.h"

void generateLiveliness(FILE *astStreamPar)
{
}

void liveFunction(struct FUNCTION *func)
{
}
void liveParameter(struct PARAMETER *par)
{
}
void liveExpr(struct EXPR *expr)
{
}
void liveInt(int i)
{
}
void liveFloat(float f)
{
}
void liveUnop(struct UNOP *un)
{
}
void liveBinop(struct BINOP *bin)
{
}
void liveIDs(struct IDs *ids)
{
}
void liveArgument(struct ARGLIST *arg)
{
}
void liveAssign(struct ASSIGN *assign)
{
}
void liveCall(struct CALL *call)
{
}
void liveDeclaration(struct DECLARATION* decl)
{
}
void liveIdentifier(struct IDENTIFIER* identifier)
{
}
void liveInt(int i)
{
}
void liveFloat(float f)
{
}
