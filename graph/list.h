#if !defined(GRAPH)
#define GRAPH
#include "graph.h"
#endif

typedef struct ListNode {
	int nr;
	struct ListNode* next;
	struct ListNode* prev;
	struct CFG* graph;
} Listnode;

void addGraphToList(CFG* graph);
void clearList();
void deleteNode(Listnode* node);

