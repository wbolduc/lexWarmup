/****************************************************/
/* File: util.c                                     */
/* Utility function implementation                  */
/* for the TINY language                            */
/****************************************************/

#include "globals.h"
#include "util.h"

/* prints a token and its lexeme to the listing file
 */
void printToken( int token, const char* tokenString )
{ switch (token) {
    case ENDFILE: 
      break;
    case ERROR:
      fprintf(listing, "ERROR(%s)\n", tokenString);
      break;
    default: /* should never happen */
      fprintf(listing, "Unknown(%s)\n", tokenString);
  }
}
