#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#include "printer.h"

/*
Main file
by Stefan Dunst, Michael Faisst, Markus Mohanty
*/


extern FILE *yyin;

int main(int argc, char *argv[])
{
	/*
	check if arguments are valid, exit if not
	*/
	if(argc < 2)
	{
		printf("Please enter: epic_parser *in_filename* \n");
		return 0;
	}
	/*
	check if file exists
	*/
	if( access( argv[1], F_OK ) != -1 ) {
		/*
		open filestreams
		*/
   		yyin = fopen(argv[1],"r");

		FILE* astFile = fopen("./output/tree.txt", "w");
		FILE* tableFile = fopen("./output/table.txt", "w");
		FILE* cfaFile = fopen("./output/CFA.out", "w");
		FILE* lifenessFile = fopen("./output/Liveness.out", "w");
		
		/*
		check if file to parse is opened
		*/
		if(yyin)
		{
			printf("'%s' successfully opened\n",argv[1]);
		}
		/*
		when parsing is done, print success and output files
		*/
		if(!yyparse())
		{
			printf("'%s' successfully parsed. Tree in 'tree.txt', symboltable in 'table.txt'\n",argv[1]);
			
			//set_timer();		
			generateOutput(astFile, tableFile);
			set_timer();			
			generateCFG(cfaFile); //, lifenessFile);
			double time = get_timer();
			printf("EPIC TOTAL TIME: %f\n", time);
		}
		/*
		when error occured, print
		*/
		else
		{
			printf("Error while parsing. See error message\n");
		}
		/*
		close filestreams
		*/
		fclose(astFile);
		fclose(tableFile);
		fclose(cfaFile);
		fclose(lifenessFile);
		fclose(yyin);
	}
	/*
	when file not exists, print error
	*/
	else
	{
    		printf("File: '%s' does not exist, please check.\n",argv[1]);
	}
	
	return 0;
}
