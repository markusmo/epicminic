

typedef enum {
	eVar, ePar
} Role; 

typedef struct TableEntry{
	int count;
	Typee type;
	char* name;
	int array;
	Role role;
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
} SymbolTable;

SymbolTable* initTable();
void newType(SymbolTable* table, Typee type);
void goToParent(SymbolTable* table);
void addEntry(SymbolTable* table, char* name, int array, Role role);
void goToChild(SymbolTable* table, char* name);
