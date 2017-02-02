/****************************************************/
/* File: tiny.l                                     */
/* Flex specification for TINY                       */
/****************************************************/

%{
#include "globals.h"
#include "util.h"
#include "scan.h"

char tokenString[MAXTOKENLEN+1];

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

int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}

TokenType getToken(void)
{
  TokenType token;

  //skip whitespace
  while(WHITESPACE == (token = yylex())){}

  if (token == OPEN_TAG)
  {
	strncpy(tokenString, &(yytext[1]), MAXTOKENLEN);
	tokenString[strlen(yytext)-2] = '\0';
  	normalizeUpper(tokenString);
  }
  else if (token == CLOSE_TAG)
  {
  	strncpy(tokenString, &(yytext[2]), MAXTOKENLEN);
  	tokenString[strlen(yytext)-3] = '\0';
  	normalizeUpper(tokenString);
  }
  else
  {
  	strncpy(tokenString, yytext, MAXTOKENLEN);
  }

  return token;
}
