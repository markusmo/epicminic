%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "epic_bison.tab.h"
  extern YYSTYPE yylval;
%}

digit [0-9]
number [0-9]+
floating [0-9]+\.[0-9]+
letter [a-zA-Z]
letter2 [a-zA-Z_]
id [a-zA-Z][a-zA-Z_0-9]*

%%
"int"	{return(INT); }
"float"	{return(FLOAT); }
"while" {return(WHILE); }
"do"	{return(DO); }
"if"	{return(IF); }
"else"	{return(ELSE); }
"for"	{return(FOR); }
"return"	{ return(RETURN); }
{number}	{ yylval.ivalue = atoi(yytext); return(INTNUM); }
{floating}	{ yylval.fvalue = atoi(yytext); return(FLOATNUM); }
{id}	{yylval.string = strdup(yytext); return(ID); }
"*"	{return(MULT); }
"/"	{return(DIV); }
"+"	{return(PLUS); }
"-"	{return(MINUS); }
"<"	{return(LT); }
"<="	{return(LE); }
">"	{return(GT); }
">="	{return(GE); }
"=="	{return(EQ); }
"!="	{return(NE); }
"="     {return(ASSIGN); }
"("	{return(LPARENT); }
")"	{return(RPARENT); }
"{"	{return(LFANCYBRACKET); }
"}"	{return(RFANCYBRACKET); }
"["	{return(LBRACKET); }
"]"	{return(RBRACKET); }
";"	{return(SEMICOLON); }
","	{return(COLON); }
[ \t\n\r] {/* skip whitespace*/ }
%%
