%{
  #include <stdio.h>
  #include <stdlib.h>
%}

digit [0-9]
letter [a-zA-Z]
letter2 [a-zA-Z_]

%%
int	return INT;
float	return FLOAT;
while return WHILE;
do	return DO;
if	return IF;
else	return ELSE;
for	return FOR;
return	return RETURN;
{digit}+	{ yylval =  atoi(yyltext); return INTNUM; }
{digit}+.{digit}+	{ yylval = atoi(yyltext); return FLOATNUM; }
{letter}{letter2}*	{ yylval = yyltext; return ID; }
"*"	return MULT;
"/"	return DIV;
"+"	return PLUS;
"-"	return MINUS;
"<"	return LT;
"<="	return LE;
">"	return GT;
">="	return GE;
"=="	return EQ;
"!="	return NE;
"="     return ASSIGN;
"("	return LPARENT;
")"	return RPARENT;
"{"	return LFANCYBRACKET;
"}"	return RFANCYBRACKET;
"["	return LBRACKET;
"]"	return RBRACKET;
";" return SEMICOLON;
"," return COLON;
%%

main() {
	yylex();
}
