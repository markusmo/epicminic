#include <stdlib.h>

#if !defined(AST)
#define AST
#include "../AST.h"
#endif

typedef struct Block {
	int nr;
	struct DECLARATION *declarations;	
	struct STMT *statements;
	struct STMT *lastStatement;
} Block;

Block createBlock();
void addStatementToBlock(Block* block, struct STMT* stmt);
