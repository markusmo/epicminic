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
#include "cfg_creatttor.h"

extern struct PROGRAM *root;
extern Listnode *startNode;
extern Listnode *lastNode;

FILE* cfgStream;
CFG *cfg;

int if_deepness = 0;

int firstBlock = 0;


/*
	Generates the AST text representation and the symbol table
	For both files seperate streams are needed - their opening/closing should be handled from the outside
*/
void generateCFG(FILE *cfgStreamPar)
{	
	cfgStream = cfgStreamPar;
	cfg = (CFG*) malloc(sizeof(CFG));
	initCFG(cfg);
	
	struct FUNCTION *currentFunc = root->FuncList;

	while (currentFunc != NULL)
	{
		fprintf(cfgStream, "%s\n\n", currentFunc->ID);
		gotoFunction(currentFunc);
		currentFunc = currentFunc->prev;
	}

	printGraph(cfg, cfgStream);
}

void gotoDeclaration(struct DECLARATION* decl)
{
	struct IDENTIFIER *currIdent = decl->ilist;

	while (currIdent != NULL)
	{
		gotoIdentifier(currIdent);
		currIdent = currIdent->prev;
	}
}

void gotoFunction(struct FUNCTION *func)
{
	struct PARAMETER *currPar = func->ParamList;

	while (currPar != NULL)
	{
		gotoParameter(currPar);
		currPar = currPar->prev;
	}

	gotoCompound(func->CStmt, 1, NULL);

}

void gotoParameter(struct PARAMETER *par)
{
	gotoIdentifier(par->id);	
}

void gotoCompound(struct COMPOUNDSTMT *comp, int functionComp, Block* currBlockP)
{	
	struct DECLARATION *currDecl = comp->DeclList;

	if(functionComp) {
		Block currBlock = createBlock();
		currBlockP = addBlock(cfg, &currBlock);
	}

	currBlockP->declarations = currDecl;

	while (currDecl != NULL)
	{
		gotoDeclaration(currDecl);
		currDecl = currDecl->prev;
	}

	struct STMT *currStmt = comp->StmtList;	

	while (currStmt != NULL)
	{
		currBlockP = gotoStatement(currStmt, 0, currBlockP);
		currStmt = currStmt->prev;
	}
}

Block* gotoStatement(struct STMT *stmt, int isAlreadyDeeper, Block* currBlock)
{
	Block* returnBlock = currBlock;

	/* statement needs to be switched, because multiple possibilities are available */
	switch (stmt->e_stmt)
	{
		case eAssign:
			addStatementToBlock(currBlock, stmt);
			gotoAssign(stmt->stmt.assign_s);
			break;
		case eCall:
			addStatementToBlock(currBlock, stmt);
			gotoCall(stmt->stmt.call_s);
			break;
		case eRet:
			addStatementToBlock(currBlock, stmt);
			gotoExpr(stmt->stmt.return_s);
			break;
		case eWhile:
			gotoWhile(stmt->stmt.while_s, currBlock);
			break;
		case eDoWhile:
			gotoDoWhile(stmt->stmt.dowhile_s, currBlock);
			break;
		case eFor:
			gotoFor(stmt->stmt.for_s, currBlock);
			break;
		case eIf:
			// add Expr of the if to the current block....no idea how to do
			if_deepness++;
			addStatementToBlock(currBlock, stmt);
			returnBlock = gotoIf(stmt->stmt.if_s, currBlock);

			if_deepness--;
			break;
		case eCompound:
			gotoCompound(stmt->stmt.compound_s, 0, currBlock);
			break;
		case eSemi:
			break;
	}

	return returnBlock;
}

void gotoExpr(struct EXPR *expr)
{
	/* expressions need to be switched, because multiple possibilities are available */
	switch(expr->e_expr)
	{
		case eUnop:
			gotoUnop(expr->expression.unop_expr);
			break;
		case eBinop:
			gotoBinop(expr->expression.binop_expr);
			break;
		case eCallExpr:
			gotoCall(expr->expression.call_expr);
			break;
		case eIntnum:
			gotoInt(expr->expression.intnum);
			break;
		case eFloatnum:
			gotoFloat(expr->expression.floatnum);
			break;
		case eId:
			gotoIDs(expr->expression.ID_expr);
			break;
		case eExpr:
			gotoExpr(expr->expression.bracket);
			break;
	}
}

void gotoUnop(struct UNOP *un)
{
	gotoExpr(un->expr);
}

void gotoBinop(struct BINOP *bin)
{
	gotoExpr(bin->expr1);
	gotoExpr(bin->expr2);
}

void gotoIDs(struct IDs *ids)
{
	if (ids->expr != NULL)
	{
		gotoExpr(ids->expr);
	}
}

void gotoArgument(struct ARGLIST *arg)
{
	gotoExpr(arg->expr);
}

void gotoAssign(struct ASSIGN *assign)
{
	if (assign->index != NULL)
	{
		gotoExpr(assign->index);
	}

	gotoExpr(assign->expr);
}

void gotoCall(struct CALL *call)
{
	struct ARGLIST *currArg = call->arg;

	while (currArg != NULL)
	{
		gotoArgument(currArg);
		currArg = currArg->prev;
	}
}

void gotoWhile(struct WHILEs *whil, Block* currBlock)
{
	gotoExpr(whil->condition);
	gotoStatement(whil->stmt, 1, currBlock);
}

void gotoDoWhile(struct DOWHILEs *dowhile, Block* currBlock)
{	
	gotoStatement(dowhile->stmt, 1, currBlock);
	gotoExpr(dowhile->condition);
}

void gotoFor(struct FORs *fr, Block* currBlock)
{
	gotoAssign(fr->init);
	gotoExpr(fr->condition);
	gotoAssign(fr->next);
	gotoStatement(fr->stmt, 1, currBlock);
}

Block* gotoIf(struct IFs *iff, Block* currentBlock)
{
	int elseNr = -1;

	gotoExpr(iff->condition);
	Block ifBlock = createBlock();
	
	Block* ifBlockP = addBlock(cfg, &ifBlock);
	addConnection(cfg, currentBlock->nr, ifBlockP->nr);
	
	addBlockToList(ifBlockP, if_deepness);
	gotoStatement(iff->if_s, 1, ifBlockP);

	if (iff->else_s != NULL)
	{
		Block elseBlock = createBlock();
		elseNr = elseBlock.nr;
		Block* elseBlockP = addBlock(cfg, &elseBlock);
		addConnection(cfg, currentBlock->nr, elseBlockP->nr);

		addBlockToList(elseBlockP, if_deepness);
		gotoStatement(iff->else_s, 1, elseBlockP);

	} else {
		addBlockToList(currentBlock, if_deepness);
	}

	Block newBlock = createBlock();
	addConnection(cfg, ifBlock.nr, newBlock.nr);

	if (elseNr >= 0)
	{
		addConnection(cfg, elseNr, newBlock.nr);
	}

	return addBlock(cfg, &newBlock);
}

void gotoIdentifier(struct IDENTIFIER* identifier)
{	
	if (identifier->intnum == 0) {
		//printf("Identifier id: %s\n", identifier->ID);
	}
	else {
		//fprintf(cfgStream, "%s[%d]", identifier->ID, identifier->intnum);
	}
}

void gotoInt(int i)
{
	//fprintf(cfgStream, "%d", i);
}

void gotoFloat(float f)
{
	//fprintf(cfgStream, "%f", f);
}

