#if !defined(BLOCK)
#define BLOCK
#include "block.h"
#endif

static blockCounter = 0;

Block createBlock()
{
	Block b;
	b.statements = NULL;
	b.declarations = NULL;
	b.lastStatement = NULL;
	b.nr = blockCounter++;
	return b;
}

void addStatementToBlock(Block* block, struct STMT* stmt) {
	
	if(block->statements == NULL) {
		block->statements = stmt;		
	} else {
		block->lastStatement->prev = stmt;
	}

	block->lastStatement = stmt;
}
