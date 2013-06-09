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

hashset_t in_set;
hashset_t use_set;
hashset_t kill_set;
hashset_t out_set;

List* closeList;

void generateLiveliness(FILE *astStreamPar)
{
	Listnode* temp = graphList->startNode;
	closeList = (List*) malloc(sizeof(List));

	while(temp != NULL) {

		initList(closeList);

		CFG* currGraph = (CFG*) temp->data;
		fprintf(astStreamPar, "%s\n\n", temp->funcName);

		in_set = (hashset_t) calloc(currGraph->currentEntries, sizeof(struct hashset_st));
		use_set = (hashset_t) calloc(currGraph->currentEntries, sizeof(struct hashset_st));
		kill_set = (hashset_t) calloc(currGraph->currentEntries, sizeof(struct hashset_st));
		out_set = (hashset_t) calloc(currGraph->currentEntries, sizeof(struct hashset_st));

		postOrderTraversal(currGraph, currGraph->blocks[0]);			

		temp = temp->next;	
	}
}

void postOrderTraversal(CFG* graph, Block block) {
	addItemToList(closeList, &block, "");
	printList(closeList);	
	
	printf("Actual node: B%d\n", block.nr);
	int j;
	for (j = 0; j < graph->currentEntries; j++)
	{
		if (graph->matrix[block.nr][j] == 1 && !isDataInList(closeList, &block))
		{
			postOrderTraversal(graph, graph->blocks[j]);
		}
	}
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
