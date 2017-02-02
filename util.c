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
    case WORD:
    	fprintf(listing, "WORD(%s)\n", tokenString);
    	break;
    case NUMBER:
    	fprintf(listing, "NUMBER(%s)\n", tokenString);
    	break;
    case APOSTROPHIZED:
    	fprintf(listing, "APOSTROPHIZED(%s)\n", tokenString);
    	break;
    case HYPHENATED:
    	fprintf(listing, "HYPHENATED(%s)\n", tokenString);
    	break;
    case PUNCTUATION:
    	fprintf(listing, "PUNCTUATION(%s)\n", tokenString);
    	break;
	case OPEN_TAG:
    	fprintf(listing, "OPEN_TAG(%s)\n", tokenString);
    	break;
    case CLOSE_TAG:
    	fprintf(listing, "CLOSE_TAG(%s)\n", tokenString);
    	break;
    case ERROR:
		fprintf(listing, "ERROR(%s)\n", tokenString);
		break;
    default: /* should never happen */
		fprintf(listing, "Unknown(%s)\n", tokenString);
	}
}

void normalizeUpper(char* str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		if(str[i] >= 97 && str[i] <= 122)
		{
			str[i] -= 32;
		}
	}
}

/* returns a pointer to a copy of the open token without the < > */
char *dupStripOpenTag(const char* tokenString)
{
	char* toRet;
	toRet = strndup(&(tokenString[1]), strlen(tokenString) - 3);
	normalizeUpper(toRet);
	return toRet;
}

/* returns a pointer to a copy of the close token without the < > */
char *dupStripCloseTag(const char* tokenString)
{
	return strndup(&(tokenString[2]), strlen(tokenString) - 4);
}