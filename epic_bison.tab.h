
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 8 "epic_bison.y"

 #include "AST.h"



/* Line 1676 of yacc.c  */
#line 46 "epic_bison.tab.h"

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



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 12 "epic_bison.y"

 int ivalue;
 float fvalue;
 Typee typee;
 char *string;
 struct PROGRAM *prog;
 struct DECLARATION *decl;
 struct FUNCTION *func;
 struct PARAMETER *param;
 struct COMPOUNDSTMT *cmpstmt;
 struct STMT *stmt;
 struct ASSIGN *assignstmt;
 struct CALL *callstmt;
 struct ARGLIST *arglist;
 struct WHILEs *whilestmt;
 struct DOWHILEs *dostmt;
 struct FORs *forstmt;
 struct IFs *ifstmt;
 struct EXPR *exp;
 struct BINOP *binop;
 struct IDs *id;
 struct IDENTIFIER *idenf;



/* Line 1676 of yacc.c  */
#line 121 "epic_bison.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


