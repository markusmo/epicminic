#if !defined(AST)
#define AST
#include "AST.h"
#endif
typedef struct TableEntry{
	int count;
	Typee type;
	char* name;
	int array;
	int isParam;
	struct TableEntry* next;
} TableEntry;

typedef struct TableHeadline{
	char* name;
	struct TableEntry* firstEntry;
	struct TableHeadline* next;
	struct TableHeadline* child;
	struct TableHeadline* parent;
} TableHeadline;

typedef struct SymbolTable {
	struct TableHeadline* global;
	struct TableHeadline* current;
	Typee currType; 
	int isParam;
} SymbolTable;

SymbolTable* initTable();

void destroy(SymbolTable* table);
void printTable(SymbolTable* table, FILE* stream);
void printHeadline(TableHeadline* head, FILE* stream);
void printEntry(TableEntry* entry, FILE* stream);

void setParam(SymbolTable* table, int param);
void newType(SymbolTable* table, Typee type);
void goToParent(SymbolTable* table);
void addEntry(SymbolTable* table, char* name, int array);
void goToChild(SymbolTable* table, char* name);
