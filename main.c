#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	FILE *yyin = fopen("todesprogramm.emc","r");
	if(yyin)
	{
		printf("opening success");
	}
	
	if(!yyparse())
	{
		printf("\nDone");
	}
	else
	{
		printf("\nFail");
	}
	fclose(yyin);
	
	return 0;
}

void yyerror(char * str)
{
    fprintf(stderr, "Error: %s\n", str);
}
