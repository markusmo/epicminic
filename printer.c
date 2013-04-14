#include "printer.h"
#include <string.h>

extern struct PROGRAM *root;

void asdf(FILE *stream)
{
	if (root->DeclList != NULL)
	{
		struct DECLARATION *currentDecl = root->DeclList;

		while (currentDecl != NULL)
		{
			printf("Dec for enum val %x \n", (int)(currentDecl->t));
			fwrite("Declaration\n", sizeof(char), 12,stream);
			currentDecl = currentDecl->prev;
		} 

		struct FUNCTION *currentFunc = root->FuncList;

		while (currentFunc != NULL)
		{
			printf("Func for enum val %s \n", currentFunc->ID);
			fwrite("Function\n", sizeof(char), 9, stream);
			currentFunc = currentFunc->prev;
		} 
	}
}

void printFunction(FUNCTION* func)
{
	printf("IDENTIFIER, Type: %d, ID: %s \n", (int)func->t, func->ID);
	struct PARAMETER *currPar = func->ParamList;

	while (currPar != NULL)
	{
		printParameter(currPar);
		currPar = currPar->prev;
	} 

	printCompound(func->CStmt);
}

void printCompound(COMPOUNDSTMT *comp)
{
	printf("COMPOUND \n");
	struct DECLARATION *currDecl = comp->DeclList;

	while (currDecl != NULL)
	{
		printDeclaration(currDecl);
		currDecl = currDecl->prev;
	}

	struct STMT *currStmt = comp->StmtList;

	while (currDecl != NULL)
	{
		printStatement(currStmt);
		currStmt = currStmt->prev;
	}
}

void printStatement(STMT *stmt)
{

}

void printDeclaration(DECLARATION* decl)
{
	printf("DECLARATION, type: %d \n", (int)decl->t);
	struct IDENTIFIER *currIdent = decl->ilist;

	while (currIdent != NULL)
	{
		printIdentifier(currIdent);
		currIdent = currIdent->prev;
	} 
}

void printIdentifier(IDENTIFIER* identifier)
{
	printf("IDENTIFIER, ID: %d, num: %d \n", (int)identifier->ID, identifier->intnum);
}

void printSymbolTable(FILE *stream)
{

}
