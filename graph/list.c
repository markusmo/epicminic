#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

Listnode *startNode;
Listnode *lastNode;
int listCounter = 0;

void addBlockToList(Block* block, int deepness) {
	
	Listnode* ln = malloc(sizeof(Listnode));
	ln->block = block;
	ln->deepness = deepness;
	ln->next = NULL;
	ln->prev = NULL;
	ln->nr = listCounter++;

	if(startNode == NULL) {
		startNode = ln;
	} else {
		lastNode->next = ln;
		ln->prev = lastNode;
	}

	lastNode = ln;
}

void clearList() {
	startNode = NULL;
	lastNode = NULL;
}

void deleteNode(Listnode* node) {
	if(node->prev != NULL && node->next != NULL) {
		node->prev->next = node->next;
	} else if(node->prev != NULL && node->next == NULL) {
		lastNode = node->prev;
		node->prev->next = NULL;
	} else if(node->prev == NULL && node->next != NULL) {
		startNode->next->prev = NULL;
		startNode = node->next;
	} else {
		clearList();	
	}
}
