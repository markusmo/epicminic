#include "printer.h"

extern struct PROGRAM root;

void asdf(FILE *stream)
{
	if (root.DeclList != NULL)
	{
		struct DECLARATION *currentDecl = root.DeclList;
		do
		{
			fwrite("Declaration\n", sizeof(char), 12,stream);
		} while (currentDecl->prev != NULL);

		struct FUNCTION *currentFunc = root.FuncList;
		do
		{
			fwrite("Function\n", sizeof(char), 9, stream);
		} while (currentFunc->prev != NULL);
	}
}

void printSymbolTable(FILE *stream)
{

}
