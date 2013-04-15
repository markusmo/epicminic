#include "symbolTable.h"

SymbolTable* initTable()
{
	SymbolTable* table = (SymbolTable*) malloc(sizeof(SymbolTable));
	table->global = (TableHeadline*) malloc(sizeof(TableHeadline));
	table->global->name = "GLOBAL";
	table->global->firstEntry = NULL;
	table->global->next = NULL;

	table->current = table->global;

	return table;
}

void newType(SymbolTable* table, Typee type)
{
	table->currType = type;
}

void goToParent(SymbolTable* table)
{
	table->current = table->current->parent;
}

void addEntry(SymbolTable* table, char* name, int array, Role role)
{
	int count = 1;
	if (table->current->firstEntry == NULL)
	{
		table->current->firstEntry = (TableEntry*) malloc(sizeof(TableEntry));
		table->current->firstEntry->next = NULL;
	}
	else
	{
		TableEntry* currEntry = table->current->firstEntry;
		
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
		currEntry->next->role = role;
		currEntry->next->next = NULL;
	}
}

void goToChild(SymbolTable* table, char* name)
{
	TableHeadline* currPrev = table->current;

	while (currPrev->next != NULL)
		currPrev = currPrev->next;

	currPrev->next = (TableHeadline*) malloc(sizeof(TableHeadline));
	currPrev->next->parent = table->current;
	char* newName = malloc(strlen(table->current->name) + strlen(name) + 4);
	sprintf(newName, "%s - %s", table->current->name, name);
	currPrev->next->name = newName;
	currPrev->next->firstEntry = NULL;
	currPrev->next->next = NULL;
	currPrev->next->child = NULL;

	table->current = currPrev->next;

}
