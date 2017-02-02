/****************************************************/
/* File: tiny.l                                     */
/* Flex specification for TINY                       */
/****************************************************/

%{
#include "globals.h"
#include "util.h"
#include "scan.h"

int tagStackHeight = 0;

%}

%%
"\w+\"                  {return WORD;}
"[+-]?\d*\.?\d+"       {return NUMBER;}
"\w+('\w+)+"           {return APOSTROPHIZED;}
"\w+(-\w+)+"           {return HYPHENATED;}
"[^\\][^>]*>"          {return OPEN_TAG;}
"<\\[^>]*>"            {return CLOSE_TAG;}
" \t\n"                {/* skip whitespace */}
.                      {return ERROR;}
%%

TokenType getToken(void)
{
  TokenType token;
  token = yylex();
  
  //stack stuff

  printf("%s token: %d\n",yytext, token);

  //strcpy(tokenString, yytext, MAXTOKENLEN);
  return token;
}
