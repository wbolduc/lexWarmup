/****************************************************/
/* File: util.c                                     */
/* Utility function implementation                  */
/* for the SGML scanner                             */
/****************************************************/

#include "globals.h"
#include "util.h"

const int TAGCOUNT = 7;
const char * const relevantTags[] = {"TEXT", "DATE", "DOC", "DOCNO", "HEADLINE", "LENGTH", "P"};

/* prints a token and its lexeme to the listing file */
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
    	fprintf(listing, "OPEN-%s\n", tokenString);
    	break;
    case CLOSE_TAG:
    	fprintf(listing, "CLOSE-%s\n", tokenString);
    	break;
    case ERROR:
		fprintf(listing, "ERROR(%s)\n", tokenString);
		break;
    default: /* should never happen */
		fprintf(listing, "Unknown(%s)\n", tokenString);
	}
}

/* checks to see if a tag will contain relevant info */
int isRelevantTag(char *str)
{
	int i;

	for(i = 0; i < TAGCOUNT; i++)
	{
		if (!strcmp(str,relevantTags[i]))
		{
			return 1;
		}
	}
	return 0;
}

/* converts lowercase chars in a string to upper */
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

/* gets the number of digits in a number */
int digitCount(int x)
{
	int i = 1;
	while (x >= i * 10)
	{
		i++;
	}
	return i;
}