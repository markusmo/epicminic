#include <stdio.h>
#include <ctype.h>

int main(int argc, char *arg[])
{
	FILE *yyin = fopen("todesprogramm.emc",'r');
	
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
