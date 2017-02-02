/****************************************************/
/* File: stringStack.h                              */
/* Stack for strings                                */
/****************************************************/

#ifndef _STRINGSTACK_H_
#define _STRINGSTACK_H_

typedef struct STRINGSTACK
{
	int maxHeight;
	int currHeight;
	char **stack;
}STRINGSTACK;


/* initializes the string stack*/
STRINGSTACK* initStringStack(int heightSuggestion);

/* adds a string to the stack */
void pushStringStack(STRINGSTACK * stack, char * string);

/* returns the top item without removing it */
char *peekStack(STRINGSTACK * stack);

/* returns the top item */
char *popStack(STRINGSTACK * stack);

/* gets the current height */
int getStackHeight(STRINGSTACK * stack);

/* free string stack */
void freeStringStack(STRINGSTACK * stack);

#endif
