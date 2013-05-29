#define START_SIZE 64
#if !defined(BLOCK)
#define BLOCK
#include "block.h"
#endif

typedef struct CFG {
	Block* blocks;
	int** matrix;
	int currentSize;
	int currentEntries;
} CFG;

void initCFG(CFG* cfg);
void addBlock(CFG* cfg, Block* block);
void addConnection(CFG* cfg, int start, int end);
void doubleArray(CFG* cfg);
void printGraph(CFG* cfg);
