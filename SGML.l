/****************************************************/
/* File: tiny.l                                     */
/* Flex specification for SGML                      */
/****************************************************/

%{
#include "globals.h"
#include "util.h"
#include "scan.h"

char tokenString[MAXTOKENLEN+1];

%}
letter         [a-zA-z]
digit          [0-9]
diglet         [0-9a-zA-Z]
word           {diglet}*{letter}+{diglet}*
number         [+-]?{digit}*\.?{digit}+
apostrphized   {diglet}+('{diglet}*)+
hyphenated     {diglet}+(-{diglet}*)+
open_tag       <[^\/][^>]*>
close_tag      <\/[^>]*>
newline        \n
whitespace     [ \t]+
punctuation    [^{letter}{digit} \t\n]


%%
{word}          {return WORD;}
{number}        {return NUMBER;}
{apostrphized}  {return APOSTROPHIZED;}
{hyphenated}    {return HYPHENATED;}
{close_tag}     {return CLOSE_TAG;}
{open_tag}      {return OPEN_TAG;}
{punctuation}   {return PUNCTUATION;}
{newline}       {lineno++;}
{whitespace}    {return WHITESPACE;}
.               {return ERROR;}
%%

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
