#include "printer.h"

extern struct PROGRAM root;

void asdf(FILE *stream)
{
	if (root.DeclList != NULL)
	{
		struct DECLARATION *currentDecl = root.DeclList;
int num = 0;
		while (currentDecl != NULL && num++ < 10)
		{
			printf("Dec for enum val %x \n", (int)(currentDecl->t));
			fwrite("Declaration\n", sizeof(char), 12,stream);
			currentDecl = currentDecl->prev;
		} 

		struct FUNCTION *currentFunc = root.FuncList;
num = 0;
		while (currentFunc != NULL && num++ < 10)
		{
			printf("Func for enum val %s \n", currentFunc->ID);
			fwrite("Function\n", sizeof(char), 9, stream);
			currentFunc = currentFunc->prev;
		} 
	}
}

void printSymbolTable(FILE *stream)
{

}
