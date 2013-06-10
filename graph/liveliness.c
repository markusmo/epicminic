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
#include "../hashset/hashset.h"

extern List* graphList;

hashset_t* prev_in_set;
hashset_t* in_set;
hashset_t* use_set;
hashset_t* def_set;
hashset_t* out_set;

List* closeList;
int currentBlockNr;

void generateLiveliness(FILE *astStreamPar)
{
	Listnode* temp = graphList->startNode;
	closeList = (List*) malloc(sizeof(List));

	while(temp != NULL) {

		initList(closeList);

		CFG* currGraph = (CFG*) temp->data;
		fprintf(astStreamPar, "%s\n\n", temp->funcName);

		prev_in_set = (hashset_t*) calloc(currGraph->currentEntries, sizeof(hashset_t));
		in_set = (hashset_t*) calloc(currGraph->currentEntries, sizeof(hashset_t));
		use_set = (hashset_t*) calloc(currGraph->currentEntries, sizeof(hashset_t));
		def_set = (hashset_t*) calloc(currGraph->currentEntries, sizeof(hashset_t));
		out_set = (hashset_t*) calloc(currGraph->currentEntries, sizeof(hashset_t));
		
		int i;
		for (i = 0; i < currGraph->currentEntries; i++)
		{
			prev_in_set[i] = hashset_create();
			in_set[i] = hashset_create();
			use_set[i] = hashset_create();
			def_set[i] = hashset_create();
			out_set[i] = hashset_create();
		}

		// initialize

		for(i = 0; i < currGraph->currentEntries; i++) {
			if(currGraph->blocks[i].statements == NULL && currGraph->blocks[i].declarations == NULL) {
				continue;
			}

			currentBlockNr = currGraph->blocks[i].nr;

			struct DECLARATION* decl = currGraph->blocks[i].declarations;
			
			while(decl != NULL) {
				liveDeclaration(decl);
				decl = decl->prev;			
			}

			struct STMT* stmt = currGraph->blocks[i].statements;			
			
			int countStmts = 0;
			while(stmt != NULL && countStmts < currGraph->blocks[i].countStmts) {
				liveStatement(stmt);
				stmt = stmt->prev;
				countStmts++;			
			}			

			//set in_set of block i to use_set if block i
			hashset_union(in_set[i], use_set[i]);

			//copy in_set to prev_in_set for graph traversal
			//hashset_union(prev_in_set[i], in_set[i]);
		}

		//while any change to a in_set of any block happened loop
		//initial change is true
		int changes = 1;
		while(changes > 0)
		{
			postOrderTraversal(currGraph,currGraph->blocks[0]);
			changes = 0;
			for(i = 0; i < currGraph->currentEntries; i++)
			{
				if(hashset_equals(in_set[i], prev_in_set[i]) == 0)
				{
					changes++;
					//reset previous in set
					hashset_destroy(prev_in_set[i]);
				 	prev_in_set[i] = hashset_create();
					//copy current in set to previous one
					hashset_union(prev_in_set[i], in_set[i]);
				}
			}
		}
		
		//print in_set and out_set
		//####################
		fprintf(astStreamPar, "\tBegin (IN)\t\tEnd(OUT)\n");
		for(i = 0; i < currGraph->currentEntries; i++)
		{
			fprintf(astStreamPar, "B%d", currGraph->blocks[i].nr);
			hashset_print(in_set[i], astStreamPar);
			fprintf(astStreamPar, "\t\t");
			hashset_print(out_set[i], astStreamPar);
			fprintf(astStreamPar, "\n");
		}

		temp = temp->next;
		
		//free!
		for (i = 0; i < currGraph->currentEntries; i++)
		{
			hashset_destroy(prev_in_set[i]);
			hashset_destroy(in_set[i]);
			hashset_destroy(use_set[i]);
			hashset_destroy(def_set[i]);
			hashset_destroy(out_set[i]);
		}
		free(prev_in_set);
		free(in_set);
		free(use_set);
		free(def_set);
		free(out_set);
	}
}

void postOrderTraversal(CFG* graph, Block block) 
{
	char* traversed = (char*) calloc(graph->currentEntries, sizeof(char));
	postOrderTraversalRec(graph, block, traversed);
	free(traversed);
}

void postOrderTraversalRec(CFG* graph, Block block, char* traversed) 
{
	int blockNr = block.nr;
	traversed[blockNr] = 1;
	int j;

	for (j = 0; j < graph->currentEntries; j++)
	{
		if (graph->matrix[blockNr][j] == 1 && !traversed[j])
		{
			postOrderTraversalRec(graph, graph->blocks[j], traversed);
			//out_set of block is all in_sets of the blocks parent
			int num;
			for(num = j; num < graph->currentEntries; num ++)
			{
				hashset_union(out_set[blockNr],in_set[num]);
			}
			//new in_set = use_set UNION (out_set without def_set)
			hashset_t out_min_def = hashset_substraction(out_set[blockNr], def_set[blockNr]);
			hashset_t new_in = hashset_addition(use_set[blockNr],out_min_def);
			hashset_destroy(in_set[blockNr]);
			in_set[blockNr] = new_in;
		}
	}
}

void liveCompound(struct COMPOUNDSTMT *comp) {
	
	struct DECLARATION *currDecl = comp->DeclList;

	while (currDecl != NULL)
	{
		liveDeclaration(currDecl);
		currDecl = currDecl->prev;
	}

	struct STMT *currStmt = comp->StmtList;	

	while (currStmt != NULL)
	{
		liveStatement(currStmt);
		currStmt = currStmt->prev;
	}
}

void liveStatement(struct STMT *stmt) {
	
	if(stmt == NULL)
		return;
	/* statement needs to be switched, because multiple possibilities are available */
	switch (stmt->e_stmt)
	{
		case eAssign:
			liveAssign(stmt->stmt.assign_s);
			break;
		case eCall:
			liveCall(stmt->stmt.call_s);
			break;
		case eRet:
			liveExpr(stmt->stmt.return_s, 1);
			break;
		case eWhile:
			liveExpr(stmt->stmt.while_s->condition, 1);
			break;
		case eDoWhile:
			liveExpr(stmt->stmt.dowhile_s->condition, 1);
			break;
		case eFor:
			liveAssign(stmt->stmt.for_s->init);
			liveExpr(stmt->stmt.for_s->condition, 1);
			liveAssign(stmt->stmt.for_s->next);
			break;
		case eIf:
			liveExpr(stmt->stmt.if_s->condition, 1);
			break;
		case eCompound:
			liveCompound(stmt->stmt.compound_s);
			break;
	}
}

void liveExpr(struct EXPR *expr, int use) {
	
	switch(expr->e_expr)
	{
		case eUnop:
			liveExpr(expr->expression.unop_expr->expr, use);
			break;
		case eBinop:
			liveExpr(expr->expression.binop_expr->expr1, use);
			liveExpr(expr->expression.binop_expr->expr2, use);
			break;
		case eCallExpr:
			liveCall(expr->expression.call_expr);
			break;
		case eId:
			liveIDs(expr->expression.ID_expr, use);
			break;
		case eExpr:
			liveExpr(expr->expression.bracket, use);
			break;
	}
}

void liveIDs(struct IDs *ids, int use) {

	if(use) {
		hashset_add(use_set[currentBlockNr], ids->ID);	
	} else {
		hashset_add(def_set[currentBlockNr], ids->ID);	
	}
	
	if (ids->expr != NULL)
	{
		liveExpr(ids->expr, use);
	}
}

void liveAssign(struct ASSIGN *assign) {

	hashset_add(def_set[currentBlockNr], assign->ID);

	if (assign->index != NULL)
	{
		liveExpr(assign->index, 0);
	}

	liveExpr(assign->expr, 1);
}

void liveCall(struct CALL *call) {

	struct ARGLIST *currArg = call->arg;

	while (currArg != NULL)
	{
		liveExpr(currArg->expr, 1);
		currArg = currArg->prev;
	}
}

void liveDeclaration(struct DECLARATION* decl) {
	
	struct IDENTIFIER *currIdent = decl->ilist;

	while (currIdent != NULL)
	{
		printf("%d -> %p -> %s\n", currentBlockNr, def_set[currentBlockNr], currIdent->ID);
		hashset_add(def_set[currentBlockNr], currIdent->ID);
		currIdent = currIdent->prev;
	}
}
