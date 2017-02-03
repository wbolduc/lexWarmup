/****************************************************/
/* File: util.h                                     */
/* Utility functions for the SGML scanner           */
/****************************************************/

#ifndef _UTIL_H_
#define _UTIL_H_

/* prints a token and its value to the listing file */
void printToken( int, const char* );

/* checks to see if a tag will contain relevant info */
int isRelevantTag(char *str);

/* converts lowercase chars in a string to upper */
void normalizeUpper(char* str);

#endif
