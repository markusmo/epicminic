#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

void initCFG(CFG* cfg)
{
	int i;
	cfg->currentSize = START_SIZE;
	cfg->currentEntries = 0;
	cfg->blocks = (Block*) calloc(START_SIZE, sizeof(Block));
	cfg->matrix = (int**) calloc(cfg->currentSize, sizeof(Block));

	for (i = 0; i < cfg->currentSize; i++)
	{
		cfg->matrix[i] = (int*) calloc(cfg->currentSize, sizeof(Block));
	}
}

void addBlock(CFG* cfg, Block* block)
{
	if (cfg->currentEntries >= cfg->currentSize - 1)
	{
		doubleArray(cfg);
	}

	cfg->blocks[cfg->currentEntries++] = *block;
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

int isLeaf(CFG* cfg, Block* block)
{
	int i;
	for (i = 0; i < cfg->currentEntries; i++)
	{
		if (cfg->matrix[block->nr][i] != 0)
			return 0;
	}

	return 1;
}

void printGraph(CFG* cfg)
{
	int i;
	for (i = 0; i < cfg->currentSize; i++)
	{
		printf("B%d\n{\n", i);
		printDeclaration(cfg->blocks[i].declarations);
		printStatement(cfg->blocks[i].statements);
		printf("}\n");

		//TODO all somehow in one loop??
		printf("Predecessor: ");
		int j;
		for (j = 0; j < cfg->currentSize; j++)
		{
			if (cfg->matrix[j][cfg->blocks[i].nr] == 1)
			{
				printf("B%d, ", j);
			}
		}
		printf("\nSuccessor: ");
		for (j = 0; j < cfg->currentSize; j++)
		{
			if (cfg->matrix[cfg->blocks[i].nr][j] == 1)
			{
				printf("B%d, ", j);
			}
		}
		printf("\n\n");
	}
}
