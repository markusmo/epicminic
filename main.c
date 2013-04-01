#include <stdio.h>
#include <ctype.h>

extern FILE *yyin;
extern FILE *yyout;

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("Please enter: epic_parser *in_filename* *out_filename*\n");
		return 0;
	}
	yyin = fopen(argv[1],"r");
	yyout = fopen(argv[2], "w");
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
