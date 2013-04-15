#include <stdio.h>
#include <ctype.h>

#include "printer.h"

extern FILE *yyin;

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Please enter: epic_parser *in_filename* \n");
		return 0;
	}
	yyin = fopen(argv[1],"r");

	FILE* astFile = fopen("tree.txt", "w");
	FILE* tableFile = fopen("table.txt", "w");

	if(yyin)
	{
		printf("opening success");
	}
	
	if(!yyparse())
	{
		printf("\nDone\n");
		generateOutput(astFile, tableFile);
	}
	else
	{
		printf("\nFail\n");
	}

	fclose(astFile);
	fclose(tableFile);
	fclose(yyin);
	
	return 0;
}
