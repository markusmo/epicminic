#if !defined(BLOCK)
#define BLOCK
#include "block.h"
#endif

typedef struct ListNode {
	int nr;
	int deepness;
	struct ListNode* next;
	struct ListNode* prev;
	struct Block* block;
} Listnode;

void addBlockToList(Block* block, int deepness);
void clearList();
void deleteNode(Listnode* node);

