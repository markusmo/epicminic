#include <stdio.h>
#include <ctype.h>

extern FILE *yyin;
extern FILE *yyout;

int main(int argc, char *argv[])
{
	yyin = fopen("todesprogramm.emc","r");
	yyout = fopen("todesoutput", "w");
	if(yyin)
	{
		printf("opening success");
	}
	
	if(!yyparse())
	{
		printf("\nDone\n");
	}
	else
	{
		printf("\nFail\n");
	}
	fclose(yyout);
	fclose(yyin);
	
	return 0;
}

void yyerror(char * str)
{
    fprintf(stderr, "Error: %s\n", str);
}
