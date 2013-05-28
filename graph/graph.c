#include "graph.h"

void initCFG(CFG* cfg)
{
	cfg->currentSize = START_SIZE;
	cfg->currentEntries = 0;
	cfg->blocks = (Block*) calloc(START_SIZE, sizeof(Block));
	cfg->matrix = (int**) calloc(cfg->currentSize, sizeof(Block));

	for (i = 0; i < cfg->currentSize; i++)
	{
		cfg->matrix[i] = (int*) calloc(cfg->currentSize, sizeof(Block));
	}

	return &cfg;
}

void addBlock(CFG* cfg, Block* block)
{
	if (cfg->currentEntries >= cfg->currentSize - 1)
	{
		doubleArray(cfg);
	}

	cfg->blocks[cfg.currentEntries++] = block;
}


void addConnection(CFG* cfg, int start, int end)
{
	cfg->matrix[start][end] = 1;
}

void doubleArray(CFG* cfg)
{
	int newSize = cfg->currentSize * 2;
	Block* newBlocks = (Block*) calloc(newSize, sizeof(Block));
	int** newMatrix = (int**) calloc(newSize, sizeof(Block));
	int i;
	int oldRealSize = cfg->currentSize * sizeof(Block);

	memcpy(newBlocks, cfg->blocks, oldRealSize);

	for (i = 0; i < newSize; i++)
	{
		newMatrix[i] = (int*) calloc(newSize, sizeof(Block));
		
		if (i < cfg->currentSize)
		{
			memcpy(newMatrix[i], cfg->matrix[i], oldRealSize);
			free(cfg->matrix[i]);
		}
	}

	free(cfg->matrix);
	free(cfg->blocks);

	cfg->matrix = newMatrix;
	cfg->currentSize = newSize;
	cfg->blocks = newBlocks;
}
