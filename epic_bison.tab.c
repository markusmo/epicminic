
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* "%code top" blocks.  */

/* Line 171 of yacc.c  */
#line 1 "epic_bison.y"

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 extern struct PROGRAM *root;



/* Line 171 of yacc.c  */
#line 81 "epic_bison.tab.c"


/* Copy the first part of user declarations.  */


/* Line 189 of yacc.c  */
#line 88 "epic_bison.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 8 "epic_bison.y"

 #include "AST.h"



/* Line 209 of yacc.c  */
#line 118 "epic_bison.tab.c"

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

/* Line 214 of yacc.c  */
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



/* Line 214 of yacc.c  */
#line 193 "epic_bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 205 "epic_bison.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   290

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNRULES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    11,    13,    16,    18,
      21,    25,    27,    31,    33,    38,    45,    51,    54,    59,
      61,    63,    67,    72,    74,    75,    77,    80,    82,    84,
      86,    88,    90,    92,    94,    96,    98,   101,   105,   112,
     115,   120,   124,   128,   131,   137,   145,   155,   161,   169,
     173,   177,   181,   185,   189,   193,   197,   201,   205,   209,
     212,   214,   216,   218,   223,   227,   229,   231
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    36,    35,    -1,    36,    -1,    35,    -1,
      -1,    40,    -1,    40,    35,    -1,    37,    -1,    36,    37,
      -1,    42,    38,    31,    -1,    39,    -1,    39,    32,    38,
      -1,    13,    -1,    13,    29,     4,    30,    -1,    42,    13,
      25,    41,    26,    43,    -1,    42,    13,    25,    26,    43,
      -1,    42,    39,    -1,    42,    39,    32,    41,    -1,     3,
      -1,     5,    -1,    27,    44,    28,    -1,    27,    36,    44,
      28,    -1,    45,    -1,    -1,    46,    -1,    46,    45,    -1,
      47,    -1,    49,    -1,    51,    -1,    52,    -1,    53,    -1,
      54,    -1,    55,    -1,    43,    -1,    31,    -1,    48,    31,
      -1,    13,    24,    56,    -1,    13,    29,    56,    30,    24,
      56,    -1,    50,    31,    -1,    13,    25,    57,    26,    -1,
      13,    25,    26,    -1,    12,    56,    31,    -1,    12,    31,
      -1,     8,    25,    56,    26,    46,    -1,     9,    46,     8,
      25,    56,    26,    31,    -1,     7,    25,    48,    31,    56,
      31,    48,    26,    46,    -1,    10,    25,    56,    26,    46,
      -1,    10,    25,    56,    26,    46,    11,    46,    -1,    56,
      16,    56,    -1,    56,    17,    56,    -1,    56,    15,    56,
      -1,    56,    14,    56,    -1,    56,    18,    56,    -1,    56,
      22,    56,    -1,    56,    21,    56,    -1,    56,    23,    56,
      -1,    56,    20,    56,    -1,    56,    19,    56,    -1,    17,
      56,    -1,     4,    -1,     6,    -1,    13,    -1,    13,    29,
      56,    30,    -1,    25,    56,    26,    -1,    50,    -1,    56,
      -1,    56,    32,    57,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    79,    79,    84,    89,    94,   104,   107,   116,   119,
     132,   142,   145,   154,   160,   170,   178,   191,   197,   208,
     209,   215,   220,   231,   234,   238,   242,   252,   258,   264,
     270,   276,   282,   288,   294,   300,   310,   312,   318,   328,
     330,   335,   345,   350,   360,   367,   375,   385,   391,   402,
     410,   418,   426,   434,   442,   450,   458,   466,   474,   482,
     489,   494,   499,   505,   512,   517,   527,   532
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "INTNUM", "FLOAT", "FLOATNUM",
  "FOR", "WHILE", "DO", "IF", "ELSE", "RETURN", "ID", "DIV", "MULT",
  "PLUS", "MINUS", "LT", "NE", "EQ", "GT", "LE", "GE", "ASSIGN", "LPARENT",
  "RPARENT", "LFANCYBRACKET", "RFANCYBRACKET", "LBRACKET", "RBRACKET",
  "SEMICOLON", "COLON", "$accept", "program", "funcList", "decList",
  "declaration", "identList", "identifier", "function", "paramList",
  "type", "compoundStatement", "stmtList", "stmtListL", "statement",
  "assignStmt", "assign", "callStmt", "call", "retStmt", "whileStmt",
  "doWhileStmt", "forStmt", "ifStmt", "expr", "argList", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    34,    34,    34,    35,    35,    36,    36,
      37,    38,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    43,    43,    44,    44,    45,    45,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    47,    48,    48,    49,
      50,    50,    51,    51,    52,    53,    54,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    57,    57
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     0,     1,     2,     1,     2,
       3,     1,     3,     1,     4,     6,     5,     2,     4,     1,
       1,     3,     4,     1,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     6,     2,
       4,     3,     3,     2,     5,     7,     9,     5,     7,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     1,     1,     4,     3,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    19,    20,     0,     4,     3,     8,     6,     0,     1,
       2,     9,     7,     0,    13,     0,    11,     0,     0,     0,
      10,     0,     0,     0,     0,     0,    13,    12,    24,    16,
       0,    17,    14,     0,     0,     0,     0,     0,     0,    35,
      24,     0,    34,     0,    23,    25,    27,     0,    28,     0,
      29,    30,    31,    32,    33,    15,     0,     0,     0,     0,
       0,    60,    61,    62,     0,     0,    43,    65,     0,     0,
       0,     0,     0,    21,    26,    36,    39,    18,     0,     0,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,    37,    41,    66,
       0,     0,    22,     0,     0,     0,     0,     0,    64,    52,
      51,    49,    50,    53,    58,    57,    55,    54,    56,     0,
      40,     0,     0,    44,     0,    47,    63,    67,     0,     0,
       0,     0,    38,     0,    45,    48,     0,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    15,    16,     7,    23,     8,
      42,    43,    44,    45,    46,    47,    48,    67,    50,    51,
      52,    53,    54,    99,   100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -56
static const yytype_int16 yypact[] =
{
      62,   -56,   -56,    13,   -56,    62,   -56,    62,     8,   -56,
     -56,   -56,   -56,    12,    -7,     3,     6,    18,     5,    31,
     -56,    35,    26,    40,    35,    39,    46,   -56,    37,   -56,
      26,    49,   -56,    59,    63,   102,    66,    73,    -9,   -56,
      37,    35,   -56,    64,   -56,   102,   -56,    56,   -56,    68,
     -56,   -56,   -56,   -56,   -56,   -56,    62,    81,    76,    87,
      76,   -56,   -56,    -2,    76,    76,   -56,   -56,   145,    76,
     113,    76,    72,   -56,   -56,   -56,   -56,   -56,   -20,    74,
     215,    82,   228,    76,   267,   241,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,   -56,   267,   -56,   126,
      80,   181,   -56,    76,   102,    76,   102,   198,   -56,   134,
     134,   151,   267,    10,   -56,   -56,    10,    10,    10,    76,
     -56,    89,   163,   -56,   254,   105,   -56,   -56,    76,    81,
      90,   102,   267,    92,   -56,   -56,   102,   -56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,    78,    94,     1,    99,   100,   -56,    67,    -4,
     -11,    85,    83,   -34,   -56,   -55,   -56,   -28,   -56,   -56,
     -56,   -56,   -56,   -32,    15
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      49,    59,    79,    13,    69,    68,    11,    49,     1,    71,
       2,    29,    49,     9,    24,    69,    70,    49,    18,    55,
      71,    14,    19,    70,    41,    17,    80,    83,    82,    91,
      92,    22,    84,    85,    20,    25,    41,    97,    21,   101,
       1,    11,     2,    18,    33,    34,    35,    36,    26,    37,
      38,   107,    24,    28,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    28,     1,    30,     2,    39,    32,
     123,   122,   125,   124,   133,    19,    49,    61,    49,    62,
      61,    56,    62,    10,    57,    12,    63,    75,    58,    63,
      64,    60,    73,    64,    78,    81,   132,   135,    65,    76,
     102,    65,   137,    49,    66,   103,   120,   105,    49,    33,
      34,    35,    36,   128,    37,    38,   131,    61,   136,    62,
      27,   134,    40,    77,    31,    72,    63,     0,    74,    28,
      64,     0,     0,    39,   127,     0,     0,     0,    65,    98,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      88,     0,    90,    91,    92,    93,    94,    95,   119,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    90,
      91,    92,    93,    94,    95,     0,    96,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,   129,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,   121,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,   126,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,   104,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,     0,   106,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,   108,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
     130,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95
};

static const yytype_int16 yycheck[] =
{
      28,    35,    57,     7,    24,    37,     5,    35,     3,    29,
       5,    22,    40,     0,    18,    24,    25,    45,    25,    30,
      29,    13,    29,    25,    28,    13,    58,    29,    60,    19,
      20,    26,    64,    65,    31,     4,    40,    69,    32,    71,
       3,    40,     5,    25,     7,     8,     9,    10,    13,    12,
      13,    83,    56,    27,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    27,     3,    26,     5,    31,    30,
     104,   103,   106,   105,   129,    29,   104,     4,   106,     6,
       4,    32,     6,     5,    25,     7,    13,    31,    25,    13,
      17,    25,    28,    17,    13,     8,   128,   131,    25,    31,
      28,    25,   136,   131,    31,    31,    26,    25,   136,     7,
       8,     9,    10,    24,    12,    13,    11,     4,    26,     6,
      21,    31,    28,    56,    24,    40,    13,    -1,    45,    27,
      17,    -1,    -1,    31,   119,    -1,    -1,    -1,    25,    26,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      16,    -1,    18,    19,    20,    21,    22,    23,    32,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    18,
      19,    20,    21,    22,    23,    -1,    31,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    30,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    26,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    26,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    26,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      26,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,    34,    35,    36,    37,    40,    42,     0,
      35,    37,    35,    42,    13,    38,    39,    13,    25,    29,
      31,    32,    26,    41,    42,     4,    13,    38,    27,    43,
      26,    39,    30,     7,     8,     9,    10,    12,    13,    31,
      36,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    43,    32,    25,    25,    46,
      25,     4,     6,    13,    17,    25,    31,    50,    56,    24,
      25,    29,    44,    28,    45,    31,    31,    41,    13,    48,
      56,     8,    56,    29,    56,    56,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    31,    56,    26,    56,
      57,    56,    28,    31,    26,    25,    26,    56,    26,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    32,
      26,    30,    56,    46,    56,    46,    30,    57,    24,    31,
      26,    11,    56,    48,    31,    46,    26,    46
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 79 "epic_bison.y"
    { 	
					root = (struct PROGRAM *) malloc(sizeof(struct PROGRAM));
					root->DeclList = (yyvsp[(1) - (2)].decl); 
					root->FuncList = (yyvsp[(2) - (2)].func); 
				;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 84 "epic_bison.y"
    { 	
					root = (struct PROGRAM *) malloc(sizeof(struct PROGRAM));
					root->FuncList = NULL;
					root->DeclList = (yyvsp[(1) - (1)].decl);
				;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 89 "epic_bison.y"
    { 	
					root = (struct PROGRAM *) malloc(sizeof(struct PROGRAM));
					root->FuncList = (yyvsp[(1) - (1)].func); 
					root->DeclList = NULL; 
				;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 94 "epic_bison.y"
    { 	
					root = (struct PROGRAM *) malloc(sizeof(struct PROGRAM));
					root->FuncList = NULL;
					root->DeclList = NULL;
				;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 104 "epic_bison.y"
    {
					(yyval.func) = (yyvsp[(1) - (1)].func); 
				;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 107 "epic_bison.y"
    {
					(yyvsp[(1) - (2)].func)->prev = (yyvsp[(2) - (2)].func); 
					(yyval.func) = (yyvsp[(1) - (2)].func); 
				;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 116 "epic_bison.y"
    { 
					(yyval.decl) = (yyvsp[(1) - (1)].decl); 
				;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 119 "epic_bison.y"
    { 
					struct DECLARATION *decl = (yyvsp[(1) - (2)].decl);
					while(decl->prev != NULL) {
						decl = decl->prev;		
					}
					decl->prev = (yyvsp[(2) - (2)].decl);
					(yyval.decl) = (yyvsp[(1) - (2)].decl);
				;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 132 "epic_bison.y"
    {
						(yyval.decl) = (struct DECLARATION *) malloc(sizeof(struct DECLARATION));
						(yyval.decl)->t = (yyvsp[(1) - (3)].typee); 
						(yyval.decl)->ilist = (yyvsp[(2) - (3)].idenf); 
						(yyval.decl)->prev = NULL; 
					;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 142 "epic_bison.y"
    { 
						(yyval.idenf) = (yyvsp[(1) - (1)].idenf); 
					;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 145 "epic_bison.y"
    { 
						(yyvsp[(1) - (3)].idenf)->prev = (yyvsp[(3) - (3)].idenf); 
						(yyval.idenf) = (yyvsp[(1) - (3)].idenf); 
					;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 154 "epic_bison.y"
    {
						
						(yyval.idenf) = (struct IDENTIFIER *) malloc(sizeof(struct IDENTIFIER));
						(yyval.idenf)->ID = (yyvsp[(1) - (1)].string);
						(yyval.idenf)->intnum = 0;
					;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 160 "epic_bison.y"
    { 
						(yyval.idenf) = (struct IDENTIFIER *) malloc(sizeof(struct IDENTIFIER));
						(yyval.idenf)->ID = (yyvsp[(1) - (4)].string); 
						(yyval.idenf)->intnum = (yyvsp[(3) - (4)].ivalue); 
					;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 170 "epic_bison.y"
    { 
										(yyval.func) = (struct FUNCTION *) malloc(sizeof(struct FUNCTION)); 
										(yyval.func)->t = (yyvsp[(1) - (6)].typee); 
										(yyval.func)->ID = (yyvsp[(2) - (6)].string);
										(yyval.func)->ParamList = (yyvsp[(4) - (6)].param); 
										(yyval.func)->CStmt = (yyvsp[(6) - (6)].cmpstmt); 
										(yyval.func)->prev = NULL; 
									;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 178 "epic_bison.y"
    {
										(yyval.func) = (struct FUNCTION *) malloc(sizeof(struct FUNCTION));
										(yyval.func)->t = (yyvsp[(1) - (5)].typee); 
										(yyval.func)->ID = (yyvsp[(2) - (5)].string);
										(yyval.func)->ParamList = NULL;
										(yyval.func)->CStmt = (yyvsp[(5) - (5)].cmpstmt); 
										(yyval.func)->prev = NULL;  
									;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 191 "epic_bison.y"
    { 
						(yyval.param) = (struct PARAMETER *) malloc(sizeof(struct PARAMETER));
						(yyval.param)->t = (yyvsp[(1) - (2)].typee); 
						(yyval.param)->id = (yyvsp[(2) - (2)].idenf); 
						(yyval.param)->prev = NULL;
					;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 197 "epic_bison.y"
    { 
						(yyval.param) = (struct PARAMETER *) malloc(sizeof(struct PARAMETER)); 
						(yyval.param)->t = (yyvsp[(1) - (4)].typee); 
						(yyval.param)->id = (yyvsp[(2) - (4)].idenf); 
						(yyval.param)->prev = (yyvsp[(4) - (4)].param); 
					;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 208 "epic_bison.y"
    { (yyval.typee) = eInt; ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 209 "epic_bison.y"
    { (yyval.typee) = eFloat; ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 215 "epic_bison.y"
    {
									(yyval.cmpstmt) = (struct COMPOUNDSTMT *) malloc(sizeof(struct COMPOUNDSTMT));
									(yyval.cmpstmt)->StmtList = (yyvsp[(2) - (3)].stmt);
									(yyval.cmpstmt)->DeclList = NULL;
								;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 220 "epic_bison.y"
    { 
									(yyval.cmpstmt) = (struct COMPOUNDSTMT *) malloc(sizeof(struct COMPOUNDSTMT));
									(yyval.cmpstmt)->DeclList = (yyvsp[(2) - (4)].decl); 
									(yyval.cmpstmt)->StmtList = (yyvsp[(3) - (4)].stmt); 
								;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 231 "epic_bison.y"
    { 
				(yyval.stmt) = (yyvsp[(1) - (1)].stmt);
			;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 234 "epic_bison.y"
    { 
				(yyval.stmt) = NULL;			
			;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 238 "epic_bison.y"
    {
				(yyval.stmt) = (yyvsp[(1) - (1)].stmt);
			   
			;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 242 "epic_bison.y"
    { 
				(yyvsp[(1) - (2)].stmt)->prev = (yyvsp[(2) - (2)].stmt); 
				(yyval.stmt) = (yyvsp[(1) - (2)].stmt);
			;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 252 "epic_bison.y"
    { 
					(yyval.stmt) = (struct STMT *) malloc(sizeof(struct STMT));
					(yyval.stmt)->e_stmt = eAssign; 
					(yyval.stmt)->stmt.assign_s = (yyvsp[(1) - (1)].assignstmt);
					(yyval.stmt)->prev = NULL;
				;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 258 "epic_bison.y"
    { 
					(yyval.stmt) = (struct STMT *) malloc(sizeof(struct STMT)); 
					(yyval.stmt)->e_stmt = eCall; 
					(yyval.stmt)->stmt.call_s = (yyvsp[(1) - (1)].callstmt);
					(yyval.stmt)->prev = NULL;
				;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 264 "epic_bison.y"
    { 
					(yyval.stmt) = (struct STMT *) malloc(sizeof(struct STMT));
					(yyval.stmt)->e_stmt = eRet; 
					(yyval.stmt)->stmt.return_s = (yyvsp[(1) - (1)].exp);
					(yyval.stmt)->prev = NULL; 
				;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 270 "epic_bison.y"
    { 
					(yyval.stmt) = (struct STMT *) malloc(sizeof(struct STMT));
					(yyval.stmt)->e_stmt = eWhile; 
					(yyval.stmt)->stmt.while_s = (yyvsp[(1) - (1)].whilestmt);
					(yyval.stmt)->prev = NULL;
				;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 276 "epic_bison.y"
    { 
					(yyval.stmt) = (struct STMT *) malloc(sizeof(struct STMT));
					(yyval.stmt)->e_stmt = eDoWhile; 
					(yyval.stmt)->stmt.dowhile_s = (yyvsp[(1) - (1)].dostmt);
					(yyval.stmt)->prev = NULL;
				;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 282 "epic_bison.y"
    { 
					(yyval.stmt) = (struct STMT *) malloc(sizeof(struct STMT));
					(yyval.stmt)->e_stmt = eFor; 
					(yyval.stmt)->stmt.for_s = (yyvsp[(1) - (1)].forstmt);
					(yyval.stmt)->prev = NULL;
				;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 288 "epic_bison.y"
    { 
					(yyval.stmt) = (struct STMT *) malloc(sizeof(struct STMT));
					(yyval.stmt)->e_stmt = eIf; 
					(yyval.stmt)->stmt.if_s = (yyvsp[(1) - (1)].ifstmt);
					(yyval.stmt)->prev = NULL;
				;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 294 "epic_bison.y"
    { 
					(yyval.stmt) = (struct STMT *) malloc(sizeof(struct STMT));
					(yyval.stmt)->e_stmt = eCompound; 
					(yyval.stmt)->stmt.compound_s = (yyvsp[(1) - (1)].cmpstmt);
					(yyval.stmt)->prev = NULL;
				;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 300 "epic_bison.y"
    { 
					(yyval.stmt) = (struct STMT *) malloc(sizeof(struct STMT));
					(yyval.stmt)->e_stmt = eSemi;
					(yyval.stmt)->prev = NULL;
				;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 312 "epic_bison.y"
    { 
								(yyval.assignstmt) = (struct ASSIGN *) malloc(sizeof(struct ASSIGN));
								(yyval.assignstmt)->ID = (yyvsp[(1) - (3)].string);
								(yyval.assignstmt)->index = NULL;
								(yyval.assignstmt)->expr = (yyvsp[(3) - (3)].exp); 
							;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 318 "epic_bison.y"
    { 
								(yyval.assignstmt) = (struct ASSIGN *) malloc(sizeof(struct ASSIGN));
								(yyval.assignstmt)->ID = (yyvsp[(1) - (6)].string); 
								(yyval.assignstmt)->index = (yyvsp[(3) - (6)].exp); 
								(yyval.assignstmt)->expr = (yyvsp[(6) - (6)].exp); 
							;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 330 "epic_bison.y"
    { 
							(yyval.callstmt) = (struct CALL *) malloc(sizeof(struct CALL));
							(yyval.callstmt)->ID = (yyvsp[(1) - (4)].string); 
							(yyval.callstmt)->arg = (yyvsp[(3) - (4)].arglist); 
						;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 335 "epic_bison.y"
    {
							(yyval.callstmt) = (struct CALL *) malloc(sizeof(struct CALL)); 
							(yyval.callstmt)->ID = (yyvsp[(1) - (3)].string);
							(yyval.callstmt)->arg = NULL;
						;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 345 "epic_bison.y"
    { 
						(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
						(yyval.exp)->e_expr = eExpr; 
						(yyval.exp)->expression.bracket = (yyvsp[(2) - (3)].exp); 
					;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 350 "epic_bison.y"
    { 
						(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
						(yyval.exp)->e_expr = eExpr;
						(yyval.exp)->expression.bracket = NULL;
					;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 360 "epic_bison.y"
    { 
								(yyval.whilestmt) = (struct WHILEs *) malloc(sizeof(struct WHILEs));
								(yyval.whilestmt)->condition = (yyvsp[(3) - (5)].exp); 
								(yyval.whilestmt)->stmt = (yyvsp[(5) - (5)].stmt); 
							;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 367 "epic_bison.y"
    { 
										(yyval.dostmt) = (struct DOWHILEs *) malloc(sizeof(struct DOWHILEs));
										(yyval.dostmt)->condition = (yyvsp[(5) - (7)].exp); 
										(yyval.dostmt)->stmt = (yyvsp[(2) - (7)].stmt); 
									;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 375 "epic_bison.y"
    { 
												(yyval.forstmt) = (struct FORs *) malloc(sizeof(struct FORs));
												(yyval.forstmt)->init = (yyvsp[(3) - (9)].assignstmt); 
												(yyval.forstmt)->condition = (yyvsp[(5) - (9)].exp); 
												(yyval.forstmt)->next = (yyvsp[(7) - (9)].assignstmt); 
												(yyval.forstmt)->stmt = (yyvsp[(9) - (9)].stmt); 
											;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 385 "epic_bison.y"
    { 
								(yyval.ifstmt) = (struct IFs *) malloc(sizeof(struct IFs));
								(yyval.ifstmt)->condition = (yyvsp[(3) - (5)].exp); 
								(yyval.ifstmt)->if_s = (yyvsp[(5) - (5)].stmt);
								(yyval.ifstmt)->else_s = NULL;
							;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 391 "epic_bison.y"
    { 
								(yyval.ifstmt) = (struct IFs *) malloc(sizeof(struct IFs));
								(yyval.ifstmt)->condition = (yyvsp[(3) - (7)].exp); 
								(yyval.ifstmt)->if_s = (yyvsp[(5) - (7)].stmt); 
								(yyval.ifstmt)->else_s = (yyvsp[(7) - (7)].stmt); 
							;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 402 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					(yyval.exp)->e_expr = eBinop; 
					(yyval.exp)->expression.binop_expr->bi = ePlus; 
					(yyval.exp)->expression.binop_expr->expr1 = (yyvsp[(1) - (3)].exp);
					(yyval.exp)->expression.binop_expr->expr2 = (yyvsp[(3) - (3)].exp);
				;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 410 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					(yyval.exp)->e_expr = eBinop; 
					(yyval.exp)->expression.binop_expr->bi = eMinus; 
					(yyval.exp)->expression.binop_expr->expr1 = (yyvsp[(1) - (3)].exp);
					(yyval.exp)->expression.binop_expr->expr2 = (yyvsp[(3) - (3)].exp);
				;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 418 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					(yyval.exp)->e_expr = eBinop; 
					(yyval.exp)->expression.binop_expr->bi = eMult; 
					(yyval.exp)->expression.binop_expr->expr1 = (yyvsp[(1) - (3)].exp);
					(yyval.exp)->expression.binop_expr->expr2 = (yyvsp[(3) - (3)].exp);
				;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 426 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					(yyval.exp)->e_expr = eBinop; 
					(yyval.exp)->expression.binop_expr->bi = eDiv; 
					(yyval.exp)->expression.binop_expr->expr1 = (yyvsp[(1) - (3)].exp);
					(yyval.exp)->expression.binop_expr->expr2 = (yyvsp[(3) - (3)].exp);
				;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 434 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					(yyval.exp)->e_expr = eBinop; 
					(yyval.exp)->expression.binop_expr->bi = eLT; 
					(yyval.exp)->expression.binop_expr->expr1 = (yyvsp[(1) - (3)].exp);
					(yyval.exp)->expression.binop_expr->expr2 = (yyvsp[(3) - (3)].exp);
				;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 442 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					(yyval.exp)->e_expr = eBinop; 
					(yyval.exp)->expression.binop_expr->bi = eLTE; 
					(yyval.exp)->expression.binop_expr->expr1 = (yyvsp[(1) - (3)].exp);
					(yyval.exp)->expression.binop_expr->expr2 = (yyvsp[(3) - (3)].exp);
				;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 450 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					(yyval.exp)->e_expr = eBinop; 
					(yyval.exp)->expression.binop_expr->bi = eGT; 
					(yyval.exp)->expression.binop_expr->expr1 = (yyvsp[(1) - (3)].exp);
					(yyval.exp)->expression.binop_expr->expr2 = (yyvsp[(3) - (3)].exp);
				;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 458 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					(yyval.exp)->e_expr = eBinop; 
					(yyval.exp)->expression.binop_expr->bi = eGTE; 
					(yyval.exp)->expression.binop_expr->expr1 = (yyvsp[(1) - (3)].exp);
					(yyval.exp)->expression.binop_expr->expr2 = (yyvsp[(3) - (3)].exp);
				;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 466 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					(yyval.exp)->e_expr = eBinop; 
					(yyval.exp)->expression.binop_expr->bi = eEQ; 
					(yyval.exp)->expression.binop_expr->expr1 = (yyvsp[(1) - (3)].exp);
					(yyval.exp)->expression.binop_expr->expr2 = (yyvsp[(3) - (3)].exp);
				;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 474 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->expression.binop_expr = (struct BINOP *) malloc(sizeof(struct BINOP));
					(yyval.exp)->e_expr = eBinop; 
					(yyval.exp)->expression.binop_expr->bi = eNEQ; 
					(yyval.exp)->expression.binop_expr->expr1 = (yyvsp[(1) - (3)].exp);
					(yyval.exp)->expression.binop_expr->expr2 = (yyvsp[(3) - (3)].exp);
				;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 482 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->expression.unop_expr = (struct UNOP *) malloc(sizeof(struct UNOP));
					(yyval.exp)->e_expr = eUnop; 
					(yyval.exp)->expression.unop_expr->u = eNegative; 
					(yyval.exp)->expression.unop_expr->expr = (yyvsp[(2) - (2)].exp);
				;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 489 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->e_expr = eIntnum; 
					(yyval.exp)->expression.intnum = (yyvsp[(1) - (1)].ivalue);  
				;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 494 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->e_expr = eFloatnum; 
					(yyval.exp)->expression.floatnum = (yyvsp[(1) - (1)].fvalue); 
				;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 499 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->expression.ID_expr = (struct IDs *) malloc(sizeof(struct IDs));
					(yyval.exp)->e_expr = eId; 
					(yyval.exp)->expression.ID_expr->ID = (yyvsp[(1) - (1)].string); 
				;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 505 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->expression.ID_expr = (struct IDs *) malloc(sizeof(struct IDs)); 
					(yyval.exp)->e_expr = eId; 
					(yyval.exp)->expression.ID_expr->ID = (yyvsp[(1) - (4)].string); 
					(yyval.exp)->expression.ID_expr->expr = (yyvsp[(3) - (4)].exp); 
				;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 512 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR)); 
					(yyval.exp)->e_expr = eExpr; 
					(yyval.exp)->expression.bracket = (yyvsp[(2) - (3)].exp); 
				;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 517 "epic_bison.y"
    { 
					(yyval.exp) = (struct EXPR *) malloc(sizeof(struct EXPR));
					(yyval.exp)->e_expr = eCallExpr; 
					(yyval.exp)->expression.call_expr = (yyvsp[(1) - (1)].callstmt); 
				;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 527 "epic_bison.y"
    { 
					(yyval.arglist) = (struct ARGLIST *) malloc(sizeof(struct ARGLIST));
					(yyval.arglist)->expr = (yyvsp[(1) - (1)].exp);
					(yyval.arglist)->prev = NULL;
				;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 532 "epic_bison.y"
    { 
					(yyval.arglist) = (struct ARGLIST *) malloc(sizeof(struct ARGLIST));
					(yyval.arglist)->expr = (yyvsp[(1) - (3)].exp); 
					(yyval.arglist)->prev = (yyvsp[(3) - (3)].arglist); 
				;}
    break;



/* Line 1455 of yacc.c  */
#line 2287 "epic_bison.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 539 "epic_bison.y"


