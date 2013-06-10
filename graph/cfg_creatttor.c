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

FILE* cfgStream;

int firstBlock = 0;
List* graphList;


/*
	Generates the AST text representation and the symbol table
	For both files seperate streams are needed - their opening/closing should be handled from the outside
*/
void generateCFG(FILE *cfgStreamPar)
{	
	cfgStream = cfgStreamPar;
	graphList = (List*) malloc(sizeof(List));
	initList(graphList);	

	struct FUNCTION *currentFunc = root->FuncList;

	while (currentFunc != NULL)
	{
		fprintf(cfgStream, "%s\n\n", currentFunc->ID);
		
		CFG* cfg = (CFG*) malloc(sizeof(CFG));
		initCFG(cfg);
		
		gotoFunction(currentFunc, cfg);

		optimize(cfg);
		printGraph(cfg, cfgStream);
		addItemToList(graphList, cfg, currentFunc->ID);
		currentFunc = currentFunc->prev;
	}
}

void printToConsole(CFG* graph)
{
	int i, j;
	for (i = 0; i < graph->currentEntries; i++)
	{
		for (j = 0; j < graph->currentEntries; j++)
		{
			printf("%d\t", graph->matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void gotoDeclaration(struct DECLARATION* decl, CFG* cfg)
{
	struct IDENTIFIER *currIdent = decl->ilist;

	while (currIdent != NULL)
	{
		gotoIdentifier(currIdent, cfg);
		currIdent = currIdent->prev;
	}
}

void gotoFunction(struct FUNCTION *func, CFG* cfg)
{
	struct PARAMETER *currPar = func->ParamList;

	while (currPar != NULL)
	{
		gotoParameter(currPar, cfg);
		currPar = currPar->prev;
	}

	gotoCompound(func->CStmt, 1, NULL, cfg);

}

void gotoParameter(struct PARAMETER *par, CFG* cfg)
{
	gotoIdentifier(par->id, cfg);	
}

Block* gotoCompound(struct COMPOUNDSTMT *comp, int functionComp, Block* currBlockP, CFG* cfg)
{	
	struct DECLARATION *currDecl = comp->DeclList;

	if(functionComp) {
		Block currBlock = createBlock();
		currBlockP = addBlock(cfg, &currBlock);
	}

	currBlockP->declarations = currDecl;

	while (currDecl != NULL)
	{
		gotoDeclaration(currDecl, cfg);
		currDecl = currDecl->prev;
	}

	struct STMT *currStmt = comp->StmtList;	

	while (currStmt != NULL)
	{
		currBlockP = gotoStatement(currStmt, 0, currBlockP, cfg);
		currStmt = currStmt->prev;
	}

	return currBlockP;
}

Block* gotoStatement(struct STMT *stmt, int isAlreadyDeeper, Block* currBlock, CFG* cfg)
{
	Block* returnBlock = currBlock;

	/* statement needs to be switched, because multiple possibilities are available */
	switch (stmt->e_stmt)
	{
		case eAssign:
			addStatementToBlock(currBlock, stmt);
			gotoAssign(stmt->stmt.assign_s, cfg);
			break;
		case eCall:
			addStatementToBlock(currBlock, stmt);
			gotoCall(stmt->stmt.call_s, cfg);
			break;
		case eRet:
			addStatementToBlock(currBlock, stmt);
			gotoExpr(stmt->stmt.return_s, cfg);
			Block temp = createBlock();
			returnBlock = addBlock(cfg, &temp);
			break;
		case eWhile:
			returnBlock = gotoWhile(stmt->stmt.while_s, currBlock, stmt, cfg);
			break;
		case eDoWhile:
			returnBlock = gotoDoWhile(stmt->stmt.dowhile_s, currBlock, stmt, cfg);
			break;
		case eFor:
			returnBlock = gotoFor(stmt->stmt.for_s, currBlock, stmt, cfg);
			break;
		case eIf:
			// add Expr of the if to the current block....no idea how to do
			addStatementToBlock(currBlock, stmt);
			returnBlock = gotoIf(stmt->stmt.if_s, currBlock, cfg);
			break;
		case eCompound:
			returnBlock = gotoCompound(stmt->stmt.compound_s, 0, currBlock, cfg);
			break;
		case eSemi:
			break;
	}

	return returnBlock;
}

void gotoExpr(struct EXPR *expr, CFG* cfg)
{
	/* expressions need to be switched, because multiple possibilities are available */
	switch(expr->e_expr)
	{
		case eUnop:
			gotoUnop(expr->expression.unop_expr, cfg);
			break;
		case eBinop:
			gotoBinop(expr->expression.binop_expr, cfg);
			break;
		case eCallExpr:
			gotoCall(expr->expression.call_expr, cfg);
			break;
		case eIntnum:
			gotoInt(expr->expression.intnum);
			break;
		case eFloatnum:
			gotoFloat(expr->expression.floatnum);
			break;
		case eId:
			gotoIDs(expr->expression.ID_expr, cfg);
			break;
		case eExpr:
			gotoExpr(expr->expression.bracket, cfg);
			break;
	}
}

void gotoUnop(struct UNOP *un, CFG* cfg)
{
	gotoExpr(un->expr, cfg);
}

void gotoBinop(struct BINOP *bin, CFG* cfg)
{
	gotoExpr(bin->expr1, cfg);
	gotoExpr(bin->expr2, cfg);
}

void gotoIDs(struct IDs *ids, CFG* cfg)
{
	if (ids->expr != NULL)
	{
		gotoExpr(ids->expr, cfg);
	}
}

void gotoArgument(struct ARGLIST *arg, CFG* cfg)
{
	gotoExpr(arg->expr, cfg);
}

void gotoAssign(struct ASSIGN *assign, CFG* cfg)
{
	if (assign->index != NULL)
	{
		gotoExpr(assign->index, cfg);
	}

	gotoExpr(assign->expr, cfg);
}

void gotoCall(struct CALL *call, CFG* cfg)
{
	struct ARGLIST *currArg = call->arg;

	while (currArg != NULL)
	{
		gotoArgument(currArg, cfg);
		currArg = currArg->prev;
	}
}

Block* gotoWhile(struct WHILEs *whil, Block* currBlock, struct STMT *currStmt, CFG* cfg)
{
	gotoExpr(whil->condition, cfg);

	Block condition = createBlock();
	Block* conditionP = addBlock(cfg, &condition);
	addStatementToBlock(conditionP, currStmt);

	Block body = createBlock();
	Block* bodyP = addBlock(cfg, &body);

	addConnection(cfg, currBlock->nr, conditionP->nr);
	addConnection(cfg, conditionP->nr, bodyP->nr);

	Block* lastBlock = gotoStatement(whil->stmt, 1, bodyP, cfg);
	addConnection(cfg, lastBlock->nr, conditionP->nr);

	Block newBlock = createBlock();

	//addConnection(cfg, lastBlock->nr, newBlock.nr);
	addConnection(cfg, conditionP->nr, newBlock.nr);

	return addBlock(cfg, &newBlock);
}

Block* gotoDoWhile(struct DOWHILEs *dowhile, Block* currBlock, struct STMT *currStmt, CFG* cfg)
{
	gotoStatement(dowhile->stmt, 1, currBlock, cfg);

	Block body = createBlock();
	Block* bodyP = addBlock(cfg, &body);

	addConnection(cfg, currBlock->nr, bodyP->nr);

	Block* lastBlock = gotoStatement(dowhile->stmt, 1, bodyP, cfg);

	Block condition = createBlock();
	Block* conditionP = addBlock(cfg, &condition);
	addStatementToBlock(conditionP, currStmt);
	//addConnection(cfg, bodyP->nr, conditionP->nr);
	addConnection(cfg, lastBlock->nr, conditionP->nr);

	gotoExpr(dowhile->condition, cfg);

	Block newBlock = createBlock();

	addConnection(cfg, conditionP->nr, bodyP->nr);
	addConnection(cfg, conditionP->nr, newBlock.nr);

	return addBlock(cfg, &newBlock);
}

Block* gotoFor(struct FORs *fr, Block* currBlock, struct STMT *currStmt, CFG* cfg)
{
	gotoAssign(fr->init, cfg);
	gotoExpr(fr->condition, cfg);
	gotoAssign(fr->next, cfg);

	Block condition = createBlock();
	Block* conditionP = addBlock(cfg, &condition);
	addStatementToBlock(conditionP, currStmt);

	Block body = createBlock();
	Block* bodyP = addBlock(cfg, &body);

	addConnection(cfg, currBlock->nr, conditionP->nr);
	addConnection(cfg, conditionP->nr, bodyP->nr);

	Block* lastBlock = gotoStatement(fr->stmt, 1, bodyP, cfg);
	addConnection(cfg, lastBlock->nr, conditionP->nr);

	Block newBlock = createBlock();

	//addConnection(cfg, lastBlock->nr, newBlock.nr);
	addConnection(cfg, conditionP->nr, newBlock.nr);

	return addBlock(cfg, &newBlock);
}

Block* gotoIf(struct IFs *iff, Block* currentBlock, CFG* cfg)
{

	int elseNr = -1;
	Block* nextBlock2;

	gotoExpr(iff->condition, cfg);
	Block ifBlock = createBlock();
	
	Block* ifBlockP = addBlock(cfg, &ifBlock);
	addConnection(cfg, currentBlock->nr, ifBlockP->nr);
	
	Block* nextBlock = gotoStatement(iff->if_s, 1, ifBlockP, cfg);

	if (iff->else_s != NULL)
	{
		Block elseBlock = createBlock();
		elseNr = elseBlock.nr;
		Block* elseBlockP = addBlock(cfg, &elseBlock);
		addConnection(cfg, currentBlock->nr, elseBlockP->nr);

		nextBlock2 = gotoStatement(iff->else_s, 1, elseBlockP, cfg);

	}

	Block newBlock = createBlock();
	
	addConnection(cfg, nextBlock->nr, newBlock.nr);

	if (elseNr >= 0)
	{
		addConnection(cfg, nextBlock2->nr, newBlock.nr);
	}
	else
	{
		addConnection(cfg, currentBlock->nr, newBlock.nr);
	}

	return addBlock(cfg, &newBlock);
}

void gotoIdentifier(struct IDENTIFIER* identifier, CFG* cfg)
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

