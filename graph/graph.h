#define START_SIZE 64

typedef struct CFG {
	Block* blocks;
	int** matrix;
	int currentSize;
	int currentEntries;
} CFG;

void createCFG(CFG* cfg);
void addBlock(CFG* cfg, Block* block);
void addConnection(CFG* cfg, int start, int end);
void doubleArray(CFG* cfg);
