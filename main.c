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
	while( (ttype=getToken())!= ENDFILE ){}
		//printToken( ttype, tokenString );
	return 0;
}

