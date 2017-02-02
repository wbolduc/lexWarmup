/****************************************************/
/* File: main.c                                     */
/* Main program for the TINY scanner                */
/****************************************************/

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "stringStack.h"

/* allocate global variables */
FILE * source;
FILE * listing;
FILE * code;

main( int argc, char * argv[] )
{ 
	TokenType ttype;
	source = stdin;
	listing = stdout; 

	STRINGSTACK * stack;

	stack = initStringStack(40);


	while( (ttype=getToken())!= ENDFILE )
	{
		switch (ttype)
		{
			case OPEN_TAG:
				pushStringStack(stack, strdup(tokenString));
				printToken(ttype, tokenString);
				break;
			case CLOSE_TAG:
				if (!strcmp(peekStack(stack), tokenString)) //end tag matches start tag
				{
					free(popStack(stack));
				}
				else
				{
					printf("ERROR NON MATCHING TAG ");

				}
				printToken(ttype, tokenString);
				break;
			default:

				break;
		}
	}
	
	freeStringStack(stack);
	return 0;
}

