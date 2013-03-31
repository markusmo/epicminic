#include <stdio.h>
#include "lex.yy.c"
#include <ctype.h>

int main(int argc, char *arg[])
{
	yyin = fopen("todesprogramm.emc","r");
	
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
