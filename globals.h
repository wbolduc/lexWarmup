/****************************************************/
/* File: globals.h                                  */
/* Global types and vars for the TINY language      */
/****************************************************/

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

extern FILE* source; /* source code text file */
extern FILE* listing; /* listing output text file */
extern int lineno; /* source line number for listing */

typedef enum
   { /* book-keeping tokens */
     ENDFILE,
     /* reserved keywords */
     WORD, NUMBER, 

     /* special word types */
     APOSTROPHIZED, HYPHENATED,

     /* punctuation */
     PUNCTUATION,

     /* tags */
     OPEN_TAG, CLOSE_TAG,
     
     /* other */
     ERROR
   } TokenType;

#endif
