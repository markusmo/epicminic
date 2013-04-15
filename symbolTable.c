#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbolTable.h"

/*
	Creates a new symbol table
*/
SymbolTable* initTable()
{
	/* allocate the space for the table and set all pointers to NULL */
	SymbolTable* table = (SymbolTable*) malloc(sizeof(SymbolTable));
	table->global = (TableHeadline*) malloc(sizeof(TableHeadline));
	table->global->name = "GLOBAL";
	table->global->firstEntry = NULL;
	table->global->next = NULL;

	table->current = table->global;

	return table;
}

void destroy(SymbolTable* table)
{
	free(table);
}

/*
	recursive helper function for printing
*/
void printEntry(TableEntry* entry, FILE* stream)
{
	if (entry->array > 0)
		fprintf(stream, "%d\t\t%s\t\t%s\t\t%d\t\t%s\n", entry->count, entry->type == 0 ? "int" : "float", 
			entry->name, entry->array, entry->isParam ? "param" : "var");
	else
		fprintf(stream, "%d\t\t%s\t\t%s\t\t \t\t%s\n", entry->count, entry->type == 0 ? "int" : "float", 
			entry->name, entry->isParam ? "param" : "var");

	if (entry->next != NULL)
		printEntry(entry->next, stream);
}

/*
	recursive helper function for printing
*/
void printHeadline(TableHeadline* head, FILE* stream)
{
	if (head->firstEntry != NULL)
	{
		fprintf(stream, "Function name: %s\n", head->name);
		fprintf(stream, "count\t\tType\t\tName\t\tArray\t\tRole\n");
		
		printEntry(head->firstEntry, stream);

		fprintf(stream, "\n");
	}

	if (head->child != NULL)
		printHeadline(head->child, stream);

	if (head->next != NULL)
		printHeadline(head->next, stream);
}

/*
	prints the table t a given output stream
*/
void printTable(SymbolTable* table, FILE* stream)
{
	if (table != NULL && table->global != NULL)
	{
		printHeadline(table->global, stream);
	}
}

/*
	changes the type of new added variables
*/
void newType(SymbolTable* table, Typee type)
{
	table->currType = type;
}

/*
	Leaves the current level and goes one up
*/
void goToParent(SymbolTable* table)
{
	table->current = table->current->parent;
}

/*
	indicates wheter new variables are stored as parameters or variables
*/
void setParam(SymbolTable* table, int isParam)
{
	table->isParam = isParam;
}

/*
	adds an entry to the current head of the list
	if array is set to 0, the variable is an scalar
*/
void addEntry(SymbolTable* table, char* name, int array)
{
	int count = 1;
	
	/* first entry needs to be treated seperatly, because its predecessor is not an entry */
	if (table->current->firstEntry == NULL)
	{
		table->current->firstEntry = (TableEntry*) malloc(sizeof(TableEntry));
		table->current->firstEntry->name = name;
		table->current->firstEntry->count = count;
		table->current->firstEntry->type = table->currType;
		table->current->firstEntry->array = array;
		table->current->firstEntry->isParam = table->isParam;
		table->current->firstEntry->next = NULL;
	}
	else
	{
		TableEntry* currEntry = table->current->firstEntry;
		count++; /* one is already skipped */

		while (currEntry->next != NULL)
		{
			currEntry = currEntry->next;
			count++;
		}

		currEntry->next = (TableEntry*) malloc(sizeof(TableEntry));
		currEntry->next->name = name;
		currEntry->next->count = count;
		currEntry->next->type = table->currType;
		currEntry->next->array = array;
		currEntry->next->isParam = table->isParam;
		currEntry->next->next = NULL;
	}
}

/*
	enters a deeper level in the parsing structure
	the entered name will be appended to the name of the current node
*/
void goToChild(SymbolTable* table, char* name)
{
	TableHeadline* currPrev = table->current;

	while (currPrev->next != NULL)
		currPrev = currPrev->next;

	currPrev->next = (TableHeadline*) malloc(sizeof(TableHeadline));
	currPrev->next->parent = table->current;
	/* reserve space for concated string */
	char* newName = malloc(strlen(table->current->name) + strlen(name) + 4);
	sprintf(newName, "%s - %s", table->current->name, name);

	currPrev->next->name = newName;
	currPrev->next->firstEntry = NULL;
	currPrev->next->next = NULL;
	currPrev->next->child = NULL;

	table->current = currPrev->next;

}
