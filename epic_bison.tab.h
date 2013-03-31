/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     INTNUM = 259,
     FLOAT = 260,
     FLOATNUM = 261,
     FOR = 262,
     WHILE = 263,
     DO = 264,
     IF = 265,
     ELSE = 266,
     RETURN = 267,
     ID = 268,
     DIV = 269,
     MULT = 270,
     PLUS = 271,
     MINUS = 272,
     LT = 273,
     NE = 274,
     EQ = 275,
     GT = 276,
     LE = 277,
     GE = 278,
     ASSIGN = 279,
     LPARENT = 280,
     RPARENT = 281,
     LFANCYBRACKET = 282,
     RFANCYBRACKET = 283,
     LBRACKET = 284,
     RBRACKET = 285,
     SEMICOLON = 286,
     COLON = 287
   };
#endif
/* Tokens.  */
#define INT 258
#define INTNUM 259
#define FLOAT 260
#define FLOATNUM 261
#define FOR 262
#define WHILE 263
#define DO 264
#define IF 265
#define ELSE 266
#define RETURN 267
#define ID 268
#define DIV 269
#define MULT 270
#define PLUS 271
#define MINUS 272
#define LT 273
#define NE 274
#define EQ 275
#define GT 276
#define LE 277
#define GE 278
#define ASSIGN 279
#define LPARENT 280
#define RPARENT 281
#define LFANCYBRACKET 282
#define RFANCYBRACKET 283
#define LBRACKET 284
#define RBRACKET 285
#define SEMICOLON 286
#define COLON 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 6 "epic_bison.y"
{
	int *ivalue;
    float *fvalue;
}
/* Line 1529 of yacc.c.  */
#line 118 "epic_bison.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

