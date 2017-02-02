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
		printToken( ttype, tokenString );

		/*
		switch (ttype)
		{
			case OPEN_TAG:
				//pushes the current tag to stack without the <>
				normalizeUpper(tokenString);
				pushStringStack(strndup(&(tokenString[1]), strlen(tokenString) - 3));
				break;
			case CLOSE_TAG:
				strncmp(peekStack(stack),&(tokenString[2], strlen(tokenString) - 4);
				break;
			default:

				break;
		}
		*/
	}
	
	freeStringStack(stack);
	return 0;
}

