#include "block.h"

static blockCounter = 0;

Block createBlock()
{
	Block b;
	b.nr = blockCounter++;
	return b;
}

void addStatementToBlock(Block* block, STMT* stmt) {
	if(block->statements == NULL) {
		block->statements = stmt;		
	} else {
		block->lastStatment->prev = stmt;	
	}

	block->lastStatement = stmt;
}
