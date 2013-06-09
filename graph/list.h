#if !defined(GRAPH)
#define GRAPH
#include "graph.h"
#endif

typedef struct List {
	struct ListNode* startNode;
	struct ListNode* lastNode;
	int nodeCounter;
} List;

typedef struct ListNode {
	int nr;
	struct ListNode* next;
	struct ListNode* prev;
	void* data;
	char* funcName;
} Listnode;

void initList(List* list);
void addItemToList(List* list, void* data, char* funcName);
void clearList(List* list);
void deleteNode(List* list, Listnode* node);
int isDataInList(List* list, void* data);
void printList(List* list);
