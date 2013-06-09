#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"


void initList(List* list) {
	list->nodeCounter = 0;
	clearList(list);
}

void addItemToList(List* list, void* data, char* funcName) {
	
	Listnode* ln = (Listnode*) malloc(sizeof(Listnode));
	ln->data = data;
	ln->next = NULL;
	ln->prev = NULL;
	ln->funcName = funcName;
	ln->nr = list->nodeCounter++;

	if(list->startNode == NULL) {
		list->startNode = ln;
	} else {
		list->lastNode->next = ln;
		ln->prev = list->lastNode;
	}

	list->lastNode = ln;
}

void clearList(List* list) {
	list->startNode = NULL;
	list->lastNode = NULL;
}

void deleteNode(List* list, Listnode* node) {
	if(node->prev != NULL && node->next != NULL) {
		node->prev->next = node->next;
	} else if(node->prev != NULL && node->next == NULL) {
		list->lastNode = node->prev;
		node->prev->next = NULL;
	} else if(node->prev == NULL && node->next != NULL) {
		list->startNode->next->prev = NULL;
		list->startNode = node->next;
	} else {
		clearList(list);	
	}
}

int isDataInList(List* list, void* data) {
	Listnode* temp = list->startNode;

	while(temp != NULL) {
		if(temp->data == data) {
			return 1;
		}
		temp = temp->next;	
	}	

	return 0;
}

void printList(List* list) {
	Listnode* temp = list->startNode;

	while(temp != NULL) {
		Block* t1 = (Block*) temp->data;
		printf("B%d, ", t1->nr);		
		temp = temp->next;			
	}

	printf("\n");
}
