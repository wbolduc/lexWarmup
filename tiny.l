/****************************************************/
/* File: tiny.l                                     */
/* Flex specification for TINY                       */
/****************************************************/

%{
#include "globals.h"
#include "stringStack.h"
#include "util.h"
#include "scan.h"

%}
letter         [a-zA-z]
digit          [0-9]
word           [{digit}{letter}]*{letter}+[{digit}{letter}]*
number         [+-]?{digit}*\.?{digit}+
apostrphized   {word}+('{word}+)+
hyphenated     {word}+(-{word}+)+
open_tag       <[^\\][^>]*>
close_tag      <\\[^>]*>
whitespace     [ \t\n]+
punctuation    [^{letter}{digit} \t\n]


%%
{word}          {return WORD;}
{number}        {return NUMBER;}
{apostrphized}  {return APOSTROPHIZED;}
{hyphenated}    {return HYPHENATED;}
{close_tag}     {return CLOSE_TAG;}
{open_tag}      {return OPEN_TAG;}
{punctuation}   {return PUNCTUATION;}
{whitespace}    {return WHITESPACE;}
.               {return ERROR;}
%%

TokenType getToken(void)
{
  TokenType token;
  token = yylex();
  
  //stack stuff

  if (token != WHITESPACE)
    printf("_-_%s_-_ token: %d\n",yytext, token);

  //strcpy(tokenString, yytext, MAXTOKENLEN);
  return token;
}
