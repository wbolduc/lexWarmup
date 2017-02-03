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

	char *stackTop; 
	int currentlyRelevant = 1;
	int nextIsRelevant = 0;

	STRINGSTACK * stack;

	stack = initStringStack(40);


	while( (ttype=getToken())!= ENDFILE )
	{
		switch (ttype)
		{
			case OPEN_TAG:
				pushStringStack(stack, strdup(tokenString));
				//check if you are to print anything at all and if you must, check if this tag is relevant
				if (currentlyRelevant)
				{
					currentlyRelevant = isRelevantTag(tokenString);
				}
				break;
			case CLOSE_TAG:
				stackTop = peekStack(stack);
				if (!strcmp(stackTop, tokenString)) //end tag matches start tag
				{
					free(popStack(stack));
					if (!currentlyRelevant)
					{
						nextIsRelevant = isRelevantTag(peekStack(stack));
					}
				}
				else
				{
					printf("MISMATCH TAG\n");

				}
				
				break;
			default:
				break;
		}

		if (currentlyRelevant)
		{
			printToken(ttype, tokenString);
		}
		else if (nextIsRelevant)
		{
			currentlyRelevant = 1;
		}
	}
	
	freeStringStack(stack);
	return 0;
}

