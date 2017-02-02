/****************************************************/
/* File: stringStack.c                              */
/* Stack for strings                                */
/****************************************************/

#include "stringStack.h"
#include <stdlib.h>


//TODO: check mallocs and reallocs

/* initializes the string stack*/
STRINGSTACK* initStringStack(int heightSuggestion)
{
	int maxHeight = 10;
	STRINGSTACK *stack;

	if (heightSuggestion > 10)
	{
		maxHeight = heightSuggestion;
	}

	stack = malloc(sizeof(STRINGSTACK));

	stack->maxHeight = maxHeight;
	stack->currHeight = 0;
	stack->stack = malloc(sizeof(char*) * maxHeight);

	return stack;
}

/* adds a string to the stack */
void pushStringStack(STRINGSTACK * stack, char * string)
{
	if (stack->currHeight == stack->maxHeight)
	{
		stack->maxHeight += stack->maxHeight / 2;
		stack->stack = realloc(stack->stack, sizeof(char*) * stack->maxHeight); 
	}

	stack->stack[stack->currHeight++] = string;
}

/* returns the top item without removing it */
char *peekStack(STRINGSTACK * stack)
{
	if (stack->currHeight != 0)
	{
		return stack->stack[stack->currHeight - 1];
	}
	return NULL;
}

/* returns the top item */
char *popStack(STRINGSTACK * stack)
{
	if (stack->currHeight != 0)
	{
		return stack->stack[--stack->currHeight];
	}
	return NULL;	
}

/* gets the current height */
int getStackHeight(STRINGSTACK * stack)
{
	return stack->currHeight;
}

/* free string stack */
void freeStringStack(STRINGSTACK * stack)
{
	int i;

	for (i = 0; i < stack->currHeight; i++)
	{
		free(stack->stack[i]);
	}
	free(stack);
}