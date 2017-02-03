/****************************************************/
/* File: main.c                                     */
/* Main program for the SGML scanner                */
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

	int currentlyRelevant = 1;

	STRINGSTACK * stack;

	stack = initStringStack(40);


	while( (ttype=getToken())!= ENDFILE )
	{
		switch (ttype)
		{
			case OPEN_TAG:
				pushStringStack(stack, strdup(tokenString));

				if (currentlyRelevant)
				{
					currentlyRelevant = isRelevantTag(tokenString);
				}

				break;
			case CLOSE_TAG:
				if (!strcmp(peekStack(stack), tokenString)) //end tag matches start tag
				{
					free(popStack(stack));
					
					if (!currentlyRelevant)
					{
						currentlyRelevant = isRelevantTag(peekStack(stack));
						continue;
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
	}
	
	freeStringStack(stack);
	return 0;
}

