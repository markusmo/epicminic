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
Block* addBlock(CFG* cfg, Block* block);
void addConnection(CFG* cfg, int start, int end);
void doubleArray(CFG* cfg);
int isLeaf(CFG* cfg, Block* block);
void optimize(CFG* cfg);
void optimizeRec(CFG* cfg, int node, char* optimized);
void printGraph(CFG* cfg, FILE* cfgStream);
