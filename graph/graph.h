#define START_SIZE 64
#include "block.h"

typedef struct CFG {
	struct Block* blocks;
	int** matrix;
	int currentSize;
	int currentEntries;
} CFG;

void initCFG(CFG* cfg);
void addBlock(CFG* cfg, Block* block);
void addConnection(CFG* cfg, int start, int end);
void doubleArray(CFG* cfg);
void printGraph(CFG* cfg);
