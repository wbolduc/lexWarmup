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

int lineno = 1;

main( int argc, char * argv[] )
{ 
	TokenType ttype;
	source = stdin;
	listing = stdout;

	char* str;
	int i;

	int currentlyRelevant = 1;

	STRINGSTACK * stack;
	STRINGSTACK * errors;

	stack = initStringStack(40);
	errors = initStringStack(20);


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
				str = peekStack(stack);
				if (str && !strcmp(str, tokenString)) //end tag matches start tag
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
					//mismatched tags, store for later
					str = malloc(sizeof(char) * (strlen(tokenString) + 27 + digitCount(lineno)));
					sprintf(str,"mismatched tags line %d\t- </", lineno);
					strcat(str, tokenString);
					strcat(str, ">");
					pushStringStack(errors, str);
					continue;
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
	

	//NOTE: used a stack to store errors. In order to not read backwards, I'm exploiting that fact that I made the stack structure. I should change it to an actual list
	for (i = 0; i < errors->currHeight; i++)
	{
		str = errors->stack[i];
		fprintf(listing, "%s\n", str);
	}

	freeStringStack(stack);
	freeStringStack(errors);
	return 0;
}

