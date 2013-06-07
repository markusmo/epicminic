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

Block* addBlock(CFG* cfg, Block* block)
{
	if (cfg->currentEntries >= cfg->currentSize - 1)
	{
		doubleArray(cfg);
	}

	cfg->blocks[cfg->currentEntries++] = *block;
	return &cfg->blocks[cfg->currentEntries-1];
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

void printGraph(CFG* cfg, FILE* cfgStream)
{

	int a,b;
	setStream(cfgStream);

	for (a = 0; a < 5; a++)
	{
		for (b = 0; b < 5; b++)
		{
			fprintf(cfgStream, "%d\t", cfg->matrix[a][b]);
		}
		fprintf(cfgStream, "\n");
	}
	
	fprintf(cfgStream, "\n\n\n");

	int i;
	for (i = 0; i < cfg->currentSize; i++)
	{
		//if(cfg->blocks[i].declarations != NULL || cfg->blocks[i].statements != NULL) {
			fprintf(cfgStream, "B%d\n{\n", i);
			if(cfg->blocks[i].declarations != NULL) 
			{ 	
				struct DECLARATION* temp = cfg->blocks[i].declarations;
				while(temp != NULL) {
					fprintf(cfgStream, "\t");
					printCFGDeclaration(temp);
					temp = temp->prev; 
				}			
			}
			if(cfg->blocks[i].statements != NULL) 
			{ 	
				struct STMT* temp = cfg->blocks[i].statements;
				int count = 0;
				while(temp != NULL && count < cfg->blocks[i].countStmts) {
					fprintf(cfgStream, "\t");
					printCFGStatement(temp);
					temp = temp->prev; 
					count++;
				}	
			}
			fprintf(cfgStream, "}\n");

			//TODO all somehow in one loop??
			fprintf(cfgStream, "Predecessor: ");
			int j;
			for (j = 0; j < cfg->currentSize; j++)
			{
				if (cfg->matrix[j][cfg->blocks[i].nr] == 1)
				{
					fprintf(cfgStream, "B%d, ", j);
				}
			}

			fprintf(cfgStream, "\nSuccessor: ");
			for (j = 0; j < cfg->currentSize; j++)
			{
				if (cfg->matrix[cfg->blocks[i].nr][j] == 1)
				{
					fprintf(cfgStream, "B%d, ", j);
				}
			}
			fprintf(cfgStream, "\n\n");
		}
	//}
}
