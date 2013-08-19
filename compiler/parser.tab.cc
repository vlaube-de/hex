/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AFTER = 258,
     AND = 259,
     AS = 260,
     ASYNC = 261,
     AWAIT = 262,
     BEFORE = 263,
     BREAK = 264,
     BY = 265,
     CANCEL = 266,
     CATCH = 267,
     CLASS = 268,
     CONTINUE = 269,
     DEFER = 270,
     DELAY = 271,
     DELETE = 272,
     ELIF = 273,
     ELSE = 274,
     EXTENDS = 275,
     FINISH = 276,
     FINALLY = 277,
     FOR = 278,
     FROM = 279,
     IF = 280,
     IN = 281,
     IS = 282,
     LOCK = 283,
     NOT = 284,
     OPERATOR = 285,
     OR = 286,
     PAUSE = 287,
     RAISE = 288,
     RESUME = 289,
     RETURN = 290,
     SELF = 291,
     START = 292,
     STOP = 293,
     THEN = 294,
     TRY = 295,
     USING = 296,
     WHEN = 297,
     WHERE = 298,
     WHILE = 299,
     WITH = 300,
     YIELD = 301,
     IDENTIFIER = 302,
     STRING_LITERAL_SINGLE = 303,
     STRING_LITERAL_DOUBLE = 304,
     DECIMALINTEGER = 305,
     BININTEGER = 306,
     OCTINTEGER = 307,
     HEXINTEGER = 308,
     FLOAT = 309,
     PLUS_OP = 310,
     MINUS_OP = 311,
     MUL_OP = 312,
     DIV_OP = 313,
     MOD_OP = 314,
     ASSIGN_OP = 315,
     ASSIGN_PLUS = 316,
     ASSIGN_MINUS = 317,
     ASSIGN_MUL = 318,
     ASSIGN_DIV = 319,
     ASSIGN_MOD = 320,
     BITWISE_NOT = 321,
     BITWISE_AND = 322,
     BITWISE_OR = 323,
     BITWISE_XOR = 324,
     BITWISE_SHIFTLEFT = 325,
     BITWISE_SHIFTRIGHT = 326,
     ASSIGN_BITWISE_AND = 327,
     ASSIGN_BITWISE_OR = 328,
     ASSIGN_BITWISE_XOR = 329,
     ASSIGN_SHIFTLEFT = 330,
     ASSIGN_SHIFTRIGHT = 331,
     EQ_OP = 332,
     NEQ_OP = 333,
     GREATER_OP = 334,
     LESS_OP = 335,
     GEQ_OP = 336,
     LEQ_OP = 337,
     INC_OP = 338,
     DEC_OP = 339,
     INPUT_OP = 340,
     OUTPUT_OP = 341,
     LAMBDA_OP = 342,
     ARROW = 343,
     EXISTENTIAL_OP = 344,
     DOT = 345,
     COMMA = 346,
     SEMICOLON = 347,
     COLON = 348,
     LPAREN = 349,
     RPAREN = 350,
     LBRACKET = 351,
     RBRACKET = 352,
     LBRACE = 353,
     RBRACE = 354,
     ELLIPSIS = 355,
     ELLIPSIS_SHORT = 356,
     AT = 357,
     STARS = 358,
     PERCENT = 359,
     NEWLINE = 360,
     UMINUS = 361
   };
#endif
/* Tokens.  */
#define AFTER 258
#define AND 259
#define AS 260
#define ASYNC 261
#define AWAIT 262
#define BEFORE 263
#define BREAK 264
#define BY 265
#define CANCEL 266
#define CATCH 267
#define CLASS 268
#define CONTINUE 269
#define DEFER 270
#define DELAY 271
#define DELETE 272
#define ELIF 273
#define ELSE 274
#define EXTENDS 275
#define FINISH 276
#define FINALLY 277
#define FOR 278
#define FROM 279
#define IF 280
#define IN 281
#define IS 282
#define LOCK 283
#define NOT 284
#define OPERATOR 285
#define OR 286
#define PAUSE 287
#define RAISE 288
#define RESUME 289
#define RETURN 290
#define SELF 291
#define START 292
#define STOP 293
#define THEN 294
#define TRY 295
#define USING 296
#define WHEN 297
#define WHERE 298
#define WHILE 299
#define WITH 300
#define YIELD 301
#define IDENTIFIER 302
#define STRING_LITERAL_SINGLE 303
#define STRING_LITERAL_DOUBLE 304
#define DECIMALINTEGER 305
#define BININTEGER 306
#define OCTINTEGER 307
#define HEXINTEGER 308
#define FLOAT 309
#define PLUS_OP 310
#define MINUS_OP 311
#define MUL_OP 312
#define DIV_OP 313
#define MOD_OP 314
#define ASSIGN_OP 315
#define ASSIGN_PLUS 316
#define ASSIGN_MINUS 317
#define ASSIGN_MUL 318
#define ASSIGN_DIV 319
#define ASSIGN_MOD 320
#define BITWISE_NOT 321
#define BITWISE_AND 322
#define BITWISE_OR 323
#define BITWISE_XOR 324
#define BITWISE_SHIFTLEFT 325
#define BITWISE_SHIFTRIGHT 326
#define ASSIGN_BITWISE_AND 327
#define ASSIGN_BITWISE_OR 328
#define ASSIGN_BITWISE_XOR 329
#define ASSIGN_SHIFTLEFT 330
#define ASSIGN_SHIFTRIGHT 331
#define EQ_OP 332
#define NEQ_OP 333
#define GREATER_OP 334
#define LESS_OP 335
#define GEQ_OP 336
#define LEQ_OP 337
#define INC_OP 338
#define DEC_OP 339
#define INPUT_OP 340
#define OUTPUT_OP 341
#define LAMBDA_OP 342
#define ARROW 343
#define EXISTENTIAL_OP 344
#define DOT 345
#define COMMA 346
#define SEMICOLON 347
#define COLON 348
#define LPAREN 349
#define RPAREN 350
#define LBRACKET 351
#define RBRACKET 352
#define LBRACE 353
#define RBRACE 354
#define ELLIPSIS 355
#define ELLIPSIS_SHORT 356
#define AT 357
#define STARS 358
#define PERCENT 359
#define NEWLINE 360
#define UMINUS 361




/* Copy the first part of user declarations.  */
#line 19 "parser.y"


#include <stdio.h>
#include "yacc_extern.h"
#include "ast.h"

#define YYDEBUG 1
#define YYERROR_VERBOSE



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 30 "parser.y"
{
  char* string;
}
/* Line 193 of yacc.c.  */
#line 323 "parser.tab.cc"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 167 "parser.y"




/* Line 216 of yacc.c.  */
#line 339 "parser.tab.cc"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  126
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  323
/* YYNRULES -- Number of states.  */
#define YYNSTATES  586

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   361

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    36,    40,
      43,    48,    51,    56,    59,    63,    68,    74,    76,    78,
      80,    82,    84,    86,    88,    90,    95,    97,   101,   103,
     105,   107,   109,   111,   113,   117,   121,   126,   130,   134,
     138,   142,   145,   150,   157,   161,   167,   173,   181,   185,
     187,   189,   191,   193,   195,   197,   199,   201,   203,   206,
     210,   214,   217,   221,   225,   233,   240,   246,   251,   258,
     264,   268,   274,   280,   288,   295,   304,   309,   316,   322,
     330,   336,   338,   341,   346,   352,   360,   366,   372,   378,
     386,   394,   404,   410,   417,   424,   432,   437,   439,   442,
     448,   452,   458,   464,   472,   478,   480,   482,   487,   493,
     498,   504,   509,   511,   514,   516,   518,   522,   525,   528,
     531,   534,   537,   540,   543,   546,   549,   552,   555,   558,
     561,   564,   567,   570,   573,   576,   579,   582,   585,   588,
     591,   594,   597,   600,   603,   606,   609,   612,   615,   618,
     620,   623,   626,   632,   635,   639,   643,   645,   649,   653,
     655,   659,   663,   667,   672,   675,   679,   683,   688,   695,
     701,   709,   711,   713,   715,   717,   721,   725,   729,   735,
     741,   747,   755,   759,   763,   769,   773,   775,   777,   779,
     783,   785,   787,   789,   791,   795,   799,   803,   809,   815,
     821,   829,   833,   837,   843,   847,   850,   853,   855,   859,
     863,   865,   869,   871,   875,   877,   879,   881,   883,   885,
     887,   889,   891,   893,   895,   897,   899,   901,   903,   907,
     910,   916,   918,   923,   927,   931,   935,   939,   943,   947,
     951,   955,   959,   963,   970,   974,   978,   982,   986,   990,
     994,   998,  1002,  1006,  1010,  1014,  1018,  1023,  1027,  1031,
    1035,  1039,  1043,  1047,  1051,  1055,  1059,  1063,  1067,  1070,
    1073,  1076,  1079,  1082,  1084,  1088,  1091,  1095,  1096,  1098,
    1100,  1102,  1104,  1106,  1108,  1110,  1112,  1114,  1119,  1121,
    1123,  1126,  1129,  1133,  1139,  1144,  1148,  1153,  1157,  1160,
    1164,  1168,  1172,  1177,  1182,  1188,  1190,  1192,  1194,  1196,
    1198,  1200,  1202,  1204
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     108,     0,    -1,   109,    -1,    -1,   110,    -1,   109,   110,
      -1,   117,    -1,   111,    -1,   112,    -1,   149,    -1,   147,
      -1,   116,    -1,   114,    -1,   113,    -1,   115,    -1,   132,
      -1,   130,    -1,   173,    92,    -1,    33,   174,    92,    -1,
      14,    92,    -1,    14,    25,   174,    92,    -1,     9,    92,
      -1,     9,    25,   174,    92,    -1,    35,    92,    -1,    35,
     173,    92,    -1,    35,    25,   174,    92,    -1,    35,   173,
      25,   174,    92,    -1,   143,    -1,   139,    -1,   141,    -1,
     140,    -1,   136,    -1,   142,    -1,   118,    -1,   135,    -1,
       7,    98,   109,    99,    -1,   120,    -1,   119,    91,   120,
      -1,   126,    -1,   125,    -1,   121,    -1,   123,    -1,   122,
      -1,   124,    -1,    38,   173,   127,    -1,    16,   173,   127,
      -1,    16,   173,    10,   174,    -1,    16,    10,   174,    -1,
      11,   173,   127,    -1,    34,   173,   127,    -1,    32,   173,
     127,    -1,    37,   188,    -1,    37,    94,   189,    95,    -1,
      37,    94,   189,    95,     5,    47,    -1,    37,   188,   127,
      -1,    37,   188,     5,    47,   127,    -1,    37,    94,   189,
      95,   127,    -1,    37,    94,   189,    95,     5,    47,   127,
      -1,   128,   173,   129,    -1,     8,    -1,     3,    -1,    42,
      -1,    37,    -1,    32,    -1,    11,    -1,    34,    -1,    21,
      -1,    38,    -1,   131,    92,    -1,   191,    86,   191,    -1,
     131,    86,   191,    -1,   133,    92,    -1,   191,    85,   191,
      -1,   133,    85,   191,    -1,    94,   167,    95,    88,    98,
     109,    99,    -1,    94,    95,    88,    98,   109,    99,    -1,
      94,   167,    95,    87,   174,    -1,    94,    95,    87,   174,
      -1,    94,   167,    95,    88,    98,    99,    -1,    94,    95,
      88,    98,    99,    -1,    13,    47,    92,    -1,    13,    47,
      20,   188,    92,    -1,    13,    47,    98,   150,    99,    -1,
      13,    47,    20,   188,    98,   150,    99,    -1,   154,    13,
      47,    98,   150,    99,    -1,   154,    13,    47,    20,   188,
      98,   150,    99,    -1,    13,    47,    98,    99,    -1,    13,
      47,    20,   188,    98,    99,    -1,   154,    13,    47,    98,
      99,    -1,   154,    13,    47,    20,   188,    98,    99,    -1,
      40,    98,   109,    99,   137,    -1,   138,    -1,   137,   138,
      -1,    12,    98,   109,    99,    -1,    12,   189,    98,   109,
      99,    -1,    12,   189,     5,    47,    98,   109,    99,    -1,
      44,   174,    98,   109,    99,    -1,    28,   173,    98,   109,
      99,    -1,    45,   173,    98,   109,    99,    -1,    45,   173,
       5,    47,    98,   109,    99,    -1,    23,   189,    26,   173,
      98,   109,    99,    -1,    23,   189,    26,   173,    43,   174,
      98,   109,    99,    -1,    25,   174,    98,   109,    99,    -1,
      25,   174,    98,   109,    99,   144,    -1,    25,   174,    98,
     109,    99,   145,    -1,    25,   174,    98,   109,    99,   145,
     144,    -1,    19,    98,   109,    99,    -1,   146,    -1,   145,
     146,    -1,    18,   174,    98,   109,    99,    -1,    41,   188,
      92,    -1,    41,   188,     5,    47,    92,    -1,    41,   189,
      26,   148,    92,    -1,    41,   189,    26,   148,     5,    47,
      92,    -1,    41,    57,    26,   148,    92,    -1,   188,    -1,
      90,    -1,   191,    60,   173,    92,    -1,   191,    60,    15,
     173,    92,    -1,   191,    60,   134,    92,    -1,   154,   191,
      60,   134,    92,    -1,   191,    60,   119,    92,    -1,   151,
      -1,   150,   151,    -1,   161,    -1,   152,    -1,   153,    93,
     134,    -1,    30,    55,    -1,    30,    56,    -1,    30,    57,
      -1,    30,    58,    -1,    30,    59,    -1,    30,    66,    -1,
      30,    67,    -1,    30,    68,    -1,    30,    69,    -1,    30,
      70,    -1,    30,    71,    -1,    30,    77,    -1,    30,    78,
      -1,    30,    79,    -1,    30,    80,    -1,    30,    81,    -1,
      30,    82,    -1,    30,    83,    -1,    30,    84,    -1,    30,
      60,    -1,    30,    61,    -1,    30,    62,    -1,    30,    63,
      -1,    30,    64,    -1,    30,    65,    -1,    30,    72,    -1,
      30,    73,    -1,    30,    74,    -1,    30,    75,    -1,    30,
      76,    -1,    30,    85,    -1,    30,    86,    -1,   155,    -1,
     154,   155,    -1,   102,   188,    -1,   102,   188,    94,   164,
      95,    -1,    98,    99,    -1,    98,   157,    99,    -1,    98,
     163,    99,    -1,   161,    -1,   157,    91,   161,    -1,    98,
     159,    99,    -1,   160,    -1,   159,    91,   160,    -1,   174,
      88,   165,    -1,    47,    93,   165,    -1,   154,    47,    93,
     134,    -1,    96,    97,    -1,    96,   173,    97,    -1,    96,
     163,    97,    -1,    23,   189,    26,   173,    -1,    23,   189,
      26,   173,    25,   174,    -1,   173,    23,   189,    26,   173,
      -1,   173,    23,   189,    26,   173,    25,   174,    -1,   166,
      -1,   170,    -1,   169,    -1,   168,    -1,   166,    91,   170,
      -1,   166,    91,   169,    -1,   166,    91,   168,    -1,   166,
      91,   169,    91,   168,    -1,   166,    91,   170,    91,   169,
      -1,   166,    91,   170,    91,   168,    -1,   166,    91,   170,
      91,   169,    91,   168,    -1,   170,    91,   169,    -1,   170,
      91,   168,    -1,   170,    91,   169,    91,   168,    -1,   169,
      91,   168,    -1,   174,    -1,   134,    -1,   165,    -1,   166,
      91,   165,    -1,   172,    -1,   170,    -1,   169,    -1,   168,
      -1,   172,    91,   170,    -1,   172,    91,   169,    -1,   172,
      91,   168,    -1,   172,    91,   169,    91,   168,    -1,   172,
      91,   170,    91,   169,    -1,   172,    91,   170,    91,   168,
      -1,   172,    91,   170,    91,   169,    91,   168,    -1,   170,
      91,   169,    -1,   170,    91,   168,    -1,   170,    91,   169,
      91,   168,    -1,   169,    91,   168,    -1,   103,    47,    -1,
      57,    47,    -1,   171,    -1,   170,    91,   171,    -1,    47,
      60,   165,    -1,    47,    -1,   172,    91,    47,    -1,   174,
      -1,   173,    91,   174,    -1,   191,    -1,   187,    -1,   186,
      -1,   185,    -1,   184,    -1,   183,    -1,   182,    -1,   181,
      -1,   180,    -1,   179,    -1,   178,    -1,   177,    -1,   176,
      -1,   175,    -1,    94,   173,    95,    -1,   174,    89,    -1,
     197,   104,    94,   173,    95,    -1,    46,    -1,    46,    94,
     173,    95,    -1,   174,    61,   174,    -1,   174,    62,   174,
      -1,   174,    63,   174,    -1,   174,    64,   174,    -1,   174,
      65,   174,    -1,   174,    72,   174,    -1,   174,    73,   174,
      -1,   174,    74,   174,    -1,   174,    75,   174,    -1,   174,
      76,   174,    -1,    25,   174,    39,   174,    19,   174,    -1,
     174,   100,   174,    -1,   174,   101,   174,    -1,   174,     4,
     174,    -1,   174,    31,   174,    -1,   174,    77,   174,    -1,
     174,    78,   174,    -1,   174,    27,   174,    -1,   174,    80,
     174,    -1,   174,    79,   174,    -1,   174,    82,   174,    -1,
     174,    81,   174,    -1,   174,    26,   174,    -1,   174,    29,
      26,   174,    -1,   174,    67,   174,    -1,   174,    68,   174,
      -1,   174,    69,   174,    -1,   174,    70,   174,    -1,   174,
      71,   174,    -1,   174,   103,   174,    -1,   174,    57,   174,
      -1,   174,    58,   174,    -1,   174,    59,   174,    -1,   174,
      55,   174,    -1,   174,    56,   174,    -1,    56,   174,    -1,
      29,   174,    -1,    66,   174,    -1,   174,    83,    -1,   174,
      84,    -1,    47,    -1,   188,    90,    47,    -1,    47,   190,
      -1,    91,    47,   190,    -1,    -1,    47,    -1,   196,    -1,
     192,    -1,   195,    -1,   194,    -1,   162,    -1,   156,    -1,
     158,    -1,    36,    -1,   191,    96,   193,    97,    -1,    93,
      -1,   174,    -1,   174,    93,    -1,    93,   174,    -1,   174,
      93,   174,    -1,   174,    93,   174,    93,   174,    -1,   174,
      93,   174,    93,    -1,   174,    93,    93,    -1,    93,   174,
      93,   174,    -1,    93,   174,    93,    -1,    93,    93,    -1,
      93,    93,   174,    -1,   191,    90,    47,    -1,   191,    94,
      95,    -1,   191,    94,   164,    95,    -1,   191,    94,    95,
       6,    -1,   191,    94,   164,    95,     6,    -1,   198,    -1,
      54,    -1,   197,    -1,    48,    -1,    49,    -1,    50,    -1,
      51,    -1,    52,    -1,    53,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   174,   174,   175,   179,   180,   184,   185,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   201,   205,   209,
     210,   214,   215,   219,   220,   221,   222,   226,   227,   228,
     229,   230,   231,   232,   233,   237,   241,   242,   246,   247,
     248,   249,   250,   251,   255,   259,   260,   261,   265,   269,
     273,   277,   278,   279,   280,   281,   282,   283,   287,   291,
     292,   293,   297,   298,   299,   300,   301,   302,   306,   310,
     311,   315,   319,   320,   324,   325,   326,   327,   328,   329,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     346,   350,   351,   355,   356,   357,   361,   365,   369,   370,
     374,   375,   379,   380,   381,   382,   386,   390,   391,   395,
     399,   400,   401,   402,   403,   407,   408,   412,   413,   414,
     415,   416,   420,   421,   425,   426,   430,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   469,
     470,   474,   475,   479,   480,   481,   485,   486,   490,   494,
     495,   499,   503,   504,   508,   509,   510,   514,   515,   516,
     517,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   539,   540,   544,   545,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   567,   571,   575,   576,   580,
     584,   585,   589,   590,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   612,
     616,   620,   621,   625,   626,   627,   628,   629,   630,   631,
     632,   633,   634,   638,   642,   643,   647,   648,   652,   653,
     654,   655,   656,   657,   658,   659,   660,   664,   665,   666,
     667,   668,   672,   676,   677,   678,   682,   683,   687,   688,
     689,   690,   691,   695,   696,   700,   704,   705,   709,   710,
     711,   712,   713,   714,   715,   716,   717,   721,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   734,   735,   736,
     740,   744,   745,   746,   747,   751,   752,   753,   757,   758,
     762,   763,   764,   765
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AFTER", "AND", "AS", "ASYNC", "AWAIT",
  "BEFORE", "BREAK", "BY", "CANCEL", "CATCH", "CLASS", "CONTINUE", "DEFER",
  "DELAY", "DELETE", "ELIF", "ELSE", "EXTENDS", "FINISH", "FINALLY", "FOR",
  "FROM", "IF", "IN", "IS", "LOCK", "NOT", "OPERATOR", "OR", "PAUSE",
  "RAISE", "RESUME", "RETURN", "SELF", "START", "STOP", "THEN", "TRY",
  "USING", "WHEN", "WHERE", "WHILE", "WITH", "YIELD", "IDENTIFIER",
  "STRING_LITERAL_SINGLE", "STRING_LITERAL_DOUBLE", "DECIMALINTEGER",
  "BININTEGER", "OCTINTEGER", "HEXINTEGER", "FLOAT", "PLUS_OP", "MINUS_OP",
  "MUL_OP", "DIV_OP", "MOD_OP", "ASSIGN_OP", "ASSIGN_PLUS", "ASSIGN_MINUS",
  "ASSIGN_MUL", "ASSIGN_DIV", "ASSIGN_MOD", "BITWISE_NOT", "BITWISE_AND",
  "BITWISE_OR", "BITWISE_XOR", "BITWISE_SHIFTLEFT", "BITWISE_SHIFTRIGHT",
  "ASSIGN_BITWISE_AND", "ASSIGN_BITWISE_OR", "ASSIGN_BITWISE_XOR",
  "ASSIGN_SHIFTLEFT", "ASSIGN_SHIFTRIGHT", "EQ_OP", "NEQ_OP", "GREATER_OP",
  "LESS_OP", "GEQ_OP", "LEQ_OP", "INC_OP", "DEC_OP", "INPUT_OP",
  "OUTPUT_OP", "LAMBDA_OP", "ARROW", "EXISTENTIAL_OP", "DOT", "COMMA",
  "SEMICOLON", "COLON", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "LBRACE", "RBRACE", "ELLIPSIS", "ELLIPSIS_SHORT", "AT", "STARS",
  "PERCENT", "NEWLINE", "UMINUS", "$accept", "input", "stmt_group", "stmt",
  "simple_stmt", "expr_list_stmt", "raise_stmt", "continue_stmt",
  "break_stmt", "return_stmt", "compound_stmt", "await_stmt", "task_def",
  "task_clause", "stop_clause", "delay_clause", "cancel_clause",
  "resume_clause", "pause_clause", "start_clause", "conditional_clause",
  "conditional_preposition", "task_state", "output_stmt",
  "output_stmt_list", "input_stmt", "input_stmt_list", "lambda",
  "class_def", "try_stmt", "catch_stmt_group", "catch_stmt", "while_stmt",
  "lock_stmt", "with_stmt", "for_stmt", "if_stmt", "else_stmt",
  "elif_group", "elif_stmt", "using_stmt", "using_src", "assignment_stmt",
  "attribute_def_list", "attribute_def", "operator_def", "operator",
  "decorator_list", "decorator", "dict_form", "field_def_list", "map_form",
  "map_field_list", "map_field", "field_def", "list_form", "comprehension",
  "arg_list", "val_atom", "val_list", "parameter_list", "kwarg_val",
  "arg_val", "keyword_val_list", "keyword_val", "simple_param_list",
  "expr_list", "expr", "existential_expr", "string_expr", "yield_expr",
  "pseudo_assign_expr", "conditional_expr", "range_expr", "logic_expr",
  "comparison_expr", "bitwise_expr", "power_expr", "multiplicative_expr",
  "additive_expr", "unary_expr", "name", "target_list", "target_tail",
  "primary", "slicing", "slice_item", "attribute_ref", "call", "literal",
  "string", "integer", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   108,   108,   109,   109,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   112,   113,   114,
     114,   115,   115,   116,   116,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   118,   119,   119,   120,   120,
     120,   120,   120,   120,   121,   122,   122,   122,   123,   124,
     125,   126,   126,   126,   126,   126,   126,   126,   127,   128,
     128,   128,   129,   129,   129,   129,   129,   129,   130,   131,
     131,   132,   133,   133,   134,   134,   134,   134,   134,   134,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     136,   137,   137,   138,   138,   138,   139,   140,   141,   141,
     142,   142,   143,   143,   143,   143,   144,   145,   145,   146,
     147,   147,   147,   147,   147,   148,   148,   149,   149,   149,
     149,   149,   150,   150,   151,   151,   152,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   154,
     154,   155,   155,   156,   156,   156,   157,   157,   158,   159,
     159,   160,   161,   161,   162,   162,   162,   163,   163,   163,
     163,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   165,   165,   166,   166,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   168,   169,   170,   170,   171,
     172,   172,   173,   173,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   175,
     176,   177,   177,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   179,   180,   180,   181,   181,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   183,   183,   183,
     183,   183,   184,   185,   185,   185,   186,   186,   187,   187,
     187,   187,   187,   188,   188,   189,   190,   190,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   192,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     194,   195,   195,   195,   195,   196,   196,   196,   197,   197,
     198,   198,   198,   198
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       4,     2,     4,     2,     3,     4,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     3,     3,     3,
       3,     2,     4,     6,     3,     5,     5,     7,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       3,     2,     3,     3,     7,     6,     5,     4,     6,     5,
       3,     5,     5,     7,     6,     8,     4,     6,     5,     7,
       5,     1,     2,     4,     5,     7,     5,     5,     5,     7,
       7,     9,     5,     6,     6,     7,     4,     1,     2,     5,
       3,     5,     5,     7,     5,     1,     1,     4,     5,     4,
       5,     4,     1,     2,     1,     1,     3,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     5,     2,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     4,     2,     3,     3,     4,     6,     5,
       7,     1,     1,     1,     1,     3,     3,     3,     5,     5,
       5,     7,     3,     3,     5,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     3,     3,     5,     5,     5,
       7,     3,     3,     5,     3,     2,     2,     1,     3,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       5,     1,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     6,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     1,     3,     2,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       2,     2,     3,     5,     4,     3,     4,     3,     2,     3,
       3,     3,     4,     4,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   296,     0,     0,     0,     0,   241,   288,   318,   319,
     320,   321,   322,   323,   316,     0,     0,     0,     0,     0,
       0,     0,     2,     4,     7,     8,    13,    12,    14,    11,
       6,    33,    16,     0,    15,     0,    34,    31,    28,    30,
      29,    32,    27,    10,     9,     0,   159,   294,   295,   293,
       0,   222,   237,   236,   235,   234,   233,   232,   231,   230,
     229,   228,   227,   226,   225,   224,   290,   292,   291,   289,
     317,   315,     0,     0,    21,     0,     0,    19,   287,     0,
       0,     0,   224,     0,   279,     0,     0,    23,     0,     0,
     283,     0,     0,     0,     0,     0,     0,   278,   280,     0,
       0,   174,     0,     0,   288,   163,     0,     0,     0,   169,
     166,     0,     0,   222,   283,   161,     1,     5,     0,    68,
       0,    71,     0,   160,     0,   317,     0,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   281,
     282,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,   285,
       0,     0,     0,     0,     0,    18,     0,     0,    24,     0,
       0,     0,     0,   110,     0,     0,     0,     0,     0,   238,
       0,   176,     0,   175,     0,     0,     0,   164,     0,   168,
     165,     0,     0,    70,    73,     0,     0,   223,   256,   265,
     260,     0,   257,   276,   277,   273,   274,   275,   243,   244,
     245,   246,   247,   267,   268,   269,   270,   271,   248,   249,
     250,   251,   252,   258,   259,   262,   261,   264,   263,   254,
     255,   272,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,    40,    42,    41,    43,    39,    38,     0,     0,
      72,    69,   310,   288,     0,   311,     0,   197,     0,   198,
     181,   184,   183,   182,   217,   196,   298,   299,     0,     0,
      35,    22,     0,     0,     0,    86,     0,   122,   125,     0,
     124,    20,   287,     0,     0,     0,     0,    25,     0,     0,
     116,     0,   115,     0,   284,     0,     0,     0,     0,   242,
       0,     0,   172,     0,   167,   170,     0,   171,     0,     0,
       0,     0,     0,   266,     0,     0,     0,     0,     0,     0,
       0,    51,     0,   288,     0,     0,   203,   202,   201,   200,
       0,   121,   119,   117,     0,   216,   313,   215,   312,     0,
       0,     0,   308,   301,   300,   297,     0,    81,     0,   127,
     128,   129,   130,   131,   146,   147,   148,   149,   150,   151,
     132,   133,   134,   135,   136,   137,   152,   153,   154,   155,
     156,   138,   139,   140,   141,   142,   143,   144,   145,   157,
     158,    82,   123,     0,   286,     0,     0,     0,   102,    97,
      26,     0,    90,    91,   114,   111,     0,   112,    96,     0,
      98,   177,     0,   173,   162,     0,    88,     0,   220,   120,
      60,    59,    61,    48,     0,   118,    47,     0,    45,    50,
      49,     0,     0,    54,    44,     0,     0,     0,     0,     0,
       0,    37,   219,   314,   199,   187,   186,   185,   195,     0,
     193,   192,   218,   309,   307,   305,   302,   240,    87,     0,
     126,     0,     0,   253,     0,     0,   103,   104,   107,     0,
       0,    92,     0,     0,     0,   179,     0,    84,     0,    46,
      52,     0,    77,     0,     0,     0,   214,   212,   211,   221,
     206,   205,   204,     0,     0,     0,   306,   304,    83,     0,
     100,     0,     0,   105,   108,     0,     0,     0,   113,    99,
     178,     0,    89,     0,    64,    66,    63,    65,    62,    67,
      58,     0,    56,    55,    79,     0,    76,     0,     0,     0,
       0,   188,   190,   189,   194,   303,     0,     0,     0,    93,
       0,     0,   180,    85,    53,    75,    78,     0,   213,   207,
     209,   208,     0,   101,     0,   106,     0,    94,    57,    74,
       0,   191,   109,     0,   210,    95
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,   270,   271,   272,   273,   274,   275,   276,   277,
     443,   444,   540,    42,    43,    44,    45,   287,    46,    47,
     422,   423,    48,    49,    50,    51,    52,   486,   487,   488,
      53,   321,    54,   306,   307,   308,   309,    55,    56,    57,
     117,    58,   118,   119,   310,    59,   112,   288,   289,   290,
     355,   291,   292,   293,   294,   359,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   322,    89,   189,    92,    76,   298,    77,    78,    79,
      80,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -362
static const yytype_int16 yypact[] =
{
    3540,   -55,    13,     1,    29,    79,  4022,  4022,  4022,  4022,
    3890,  -362,    63,    -7,  4022,  4022,    77,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  4022,  4022,  4022,  3857,  2078,
     127,   185,  3540,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,    58,  -362,   -25,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,    21,  -362,  -362,  -362,  -362,
     118,  1922,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,   247,  -362,  -362,  -362,  -362,
      84,  -362,  3540,  4022,  -362,    -3,  4022,  -362,   110,   211,
    4022,   705,   144,    88,   392,   867,  4022,  -362,    -1,  3540,
      10,   220,    30,   222,   948,    20,  4022,  -362,   200,   -29,
      79,  -362,   156,     5,   163,  -362,    32,   -52,   -14,  -362,
    -362,   161,     6,  1029,  -362,   -10,  -362,  -362,   783,  -362,
     783,  -362,   219,  -362,   240,  -362,  4022,  -362,  4022,  4022,
    4022,   262,  4022,  4022,  4022,  4022,  4022,  4022,  4022,  4022,
    4022,  4022,  4022,  4022,  4022,  4022,  4022,  4022,  4022,  4022,
    4022,  4022,  4022,  4022,  4022,  4022,  4022,  4022,  4022,  -362,
    -362,  -362,  4022,  4022,  4022,  3603,   783,   783,   221,  3714,
    3923,   197,  2244,  1110,   127,  -362,    56,  1191,   248,  -362,
    4022,  1272,  4022,  3540,  3540,  -362,   786,  4022,  -362,  2316,
      90,   254,   257,  -362,    90,  3540,   264,  3540,    96,  -362,
     295,  -362,    79,  -362,  4055,   231,    46,  -362,  4022,  -362,
    -362,  4055,  3822,   144,   144,     2,   229,  1922,   641,   592,
     592,  4022,   641,  2084,  2084,  2165,  2165,  2165,   -20,   -20,
     -20,   -20,   -20,   200,   200,   200,  3722,  3722,   -20,   -20,
     -20,   -20,   -20,   592,   592,   592,   592,   592,   592,  2003,
    2003,  3641,  4022,  4022,   553,  4022,  4022,    89,  4022,  3789,
     141,  -362,  -362,  -362,  -362,  -362,  -362,  -362,   233,   201,
     144,   144,  -362,   271,   288,   334,   298,  -362,   252,  -362,
     258,  -362,   259,   266,  -362,  1922,  3956,  1353,   256,  4022,
    -362,  -362,   -39,  4099,   163,  -362,   115,  -362,  -362,   293,
    -362,  -362,   110,    44,  1436,  2388,  2460,  -362,  1517,   373,
    -362,   307,   302,   308,  -362,    40,  2532,   305,  2604,  -362,
    4022,   367,  -362,   229,  -362,  -362,  1029,  -362,   309,   127,
     119,   100,   313,   592,    34,   218,  4022,    23,    34,    34,
      79,    41,    34,   199,   226,   311,  -362,   316,   318,   319,
     386,  -362,  -362,  -362,  4055,  -362,  -362,  -362,   406,  3822,
     323,   151,  4022,  1598,  3989,  -362,   124,  -362,   121,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,   229,  -362,  4022,  3540,  4022,   301,  -362,
    -362,    14,   373,  -362,  -362,  -362,   372,  -362,  -362,  3540,
    -362,    16,  4022,  -362,  -362,    48,  -362,   137,   271,  -362,
    -362,  -362,  -362,  -362,  4022,  -362,  1922,  4022,  -362,  -362,
    -362,   327,   380,  -362,  -362,  4022,   330,   230,   323,   151,
     155,  -362,  -362,  -362,  -362,  -362,   340,   342,  -362,   271,
    -362,   344,  -362,  1922,  4022,  -362,  1679,  -362,  -362,   145,
    -362,  1760,  2676,  -362,  4022,   338,  -362,   301,  -362,  3540,
      15,  -362,   322,  2748,  4022,    33,   292,  -362,   122,  1922,
     300,   208,  1922,  2820,  4022,   341,  -362,  -362,   349,   271,
    -362,   351,   352,   323,   151,   323,  1922,  4022,  -362,  3540,
    -362,  1841,  3540,  -362,  -362,  2892,   398,  3540,  -362,  -362,
    1922,  4022,  -362,   299,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,   399,  -362,  -362,  -362,  2964,  1922,  3036,   323,   323,
     151,  -362,  -362,   359,  -362,  1922,  3108,  3540,  3180,  -362,
     353,  3252,  1922,  -362,   208,  -362,  -362,  3324,  -362,  -362,
    -362,   369,   323,  -362,  3396,  -362,  3540,  -362,  -362,  -362,
     323,  -362,  -362,  3468,  -362,  -362
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -362,  -362,   -78,   -30,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,    98,  -362,  -362,  -362,  -362,  -362,  -362,
    -336,  -362,  -362,  -362,  -362,  -362,  -362,  -170,  -362,  -362,
    -362,    39,  -362,  -362,  -362,  -362,  -362,   -17,  -362,   -16,
    -362,   268,  -362,  -326,  -298,  -362,  -362,    81,   -28,  -362,
    -362,  -362,  -362,   244,   -26,  -362,   444,   255,  -191,  -362,
    -362,   179,  -263,  -260,  -361,  -362,   242,   216,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,   -12,    -6,   162,     0,  -362,  -362,  -362,  -362,  -362,
     -36,  -362
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -288
static const yytype_int16 yytable[] =
{
      75,   102,   127,   120,   182,   278,   357,   103,   412,   358,
     472,   448,   449,   450,   437,   453,   454,   184,   125,   135,
     526,   199,   339,   332,   197,   206,   440,   133,   212,   212,
     337,   441,    75,   447,   132,   201,  -287,   440,    83,   216,
     100,   494,   441,    82,   440,   426,   452,   217,    85,   441,
     101,   202,   479,   377,    86,   134,   342,    11,   531,   378,
     130,    88,   136,   169,   170,   442,   209,   131,    17,    18,
      19,    20,    21,    22,    23,    24,   442,   218,   357,   215,
     202,   358,    75,   442,   222,   219,   303,   415,   133,   185,
     136,   198,   135,   304,   135,   186,   136,   136,   472,    75,
     340,   188,   213,   304,   210,    84,   466,   136,   471,   467,
     116,   136,   489,   527,   136,   315,   316,    28,   207,    29,
     202,    87,   203,    30,   136,   136,    88,   326,   223,   328,
     224,   202,   427,   534,    30,   136,   124,   124,   202,   412,
     135,   135,   416,   535,   128,   303,   496,   438,    30,   303,
     129,   303,   127,   472,   536,   305,   537,   284,    30,   538,
     539,    99,   304,   433,   542,   543,   304,   303,   304,   127,
     533,   106,   302,   462,   124,   303,   280,   281,   464,   136,
     320,   412,    75,   350,   304,   126,   194,   136,   181,   472,
     334,   329,   304,    75,    75,   354,   508,   511,   469,    75,
     512,   188,   509,   286,   138,    75,   331,    75,   284,   136,
     137,   440,   284,   136,   411,   136,   441,    30,   436,   477,
     478,    30,    91,    30,    94,    95,   139,   140,   578,   141,
     104,   142,   360,   361,   178,   412,   497,   190,   179,    30,
     180,   107,   108,   480,   518,   123,   200,    30,   204,    93,
     442,   553,    98,   211,   286,   351,   214,   105,   286,   364,
     220,   148,   149,   150,   151,   152,   225,   116,   282,   109,
     113,   122,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   127,   127,   571,   231,   171,
    -220,   299,   136,   363,  -220,   312,   127,   116,   127,   183,
     226,   323,   187,   440,   324,   541,   191,   175,   441,   136,
     445,   327,   196,   455,   456,    75,    75,   504,   505,   484,
     485,   330,   303,   341,   333,   362,    75,   435,    75,   303,
     178,   364,   176,   177,   179,   365,   180,   178,   482,   304,
     366,   179,   442,   180,   451,   367,   304,   368,   208,   369,
     370,   493,   227,   375,   228,   229,   230,   371,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   421,   413,   116,   259,   260,
     261,   532,   202,   432,    30,   295,   297,   262,   563,   424,
     425,    30,   264,   429,   434,   439,   457,   458,   314,   459,
     460,   525,   463,   318,   528,   490,    75,   279,   265,   492,
     266,   116,   500,   267,   268,   545,   286,   501,   503,    75,
     295,   513,   313,   514,   336,   515,   522,   295,   295,   547,
     548,   556,   549,   550,   558,   560,   564,   343,   356,   561,
     572,   576,   127,   148,   149,   150,   151,   152,   461,   116,
     580,   491,   335,   127,   158,   159,   160,   161,   162,   567,
     523,   524,   325,   121,   414,   169,   170,   338,     0,   574,
       0,   171,    75,     0,     0,     0,     0,     0,     0,    75,
       0,     0,     0,    75,     0,   127,     0,     0,   583,     0,
       0,     0,     0,    75,   344,   345,   347,   348,   349,     0,
     352,   109,   373,     0,     0,   127,     0,     0,   116,    75,
     356,     0,    75,     0,     0,    75,   127,    75,   127,     0,
       0,   127,     0,     0,     0,     0,     0,   127,     0,     0,
       0,   376,     0,     0,   127,    75,     0,    75,   465,   468,
     470,     0,     0,   127,     0,     0,    75,    75,    75,     0,
     116,    75,   446,   346,     0,     0,     0,    75,     0,     0,
       0,     0,   431,     0,    75,     0,    75,   116,    90,     0,
     295,     0,     8,    75,     0,   295,     0,     0,   473,    11,
     476,     0,     0,     0,     0,     0,   138,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    25,
       0,     0,     0,     0,   116,     0,     0,     0,     0,    26,
       0,   141,     0,   142,     0,     0,     0,     0,     0,     0,
       0,   481,     0,   483,     0,     0,     0,   506,   507,   510,
       0,     0,     0,     0,     0,     0,     0,    27,     0,    28,
       0,    29,     0,   148,   149,   150,   151,   152,     0,     0,
       0,     0,     0,   499,   158,   159,   160,   161,   162,     0,
     141,   502,     0,     0,   495,   169,   170,     0,     0,     0,
       0,   171,     0,     0,     0,     0,   498,     0,     0,     0,
     516,     0,   551,   552,   554,     0,     0,     0,     0,     0,
     521,     0,   148,   149,   150,   151,   152,     0,     0,   138,
     530,     0,     0,   158,   159,   160,   161,   162,     0,     0,
     546,     0,     0,     0,   169,   170,     0,   568,   569,   570,
     171,   139,   140,   555,   141,     0,   142,     0,     0,     0,
       0,     0,     0,     0,   192,     0,     0,   562,     0,     0,
       0,   581,     0,     0,     0,     0,     0,     0,     0,   584,
     143,   144,   145,   146,   147,     0,   148,   149,   150,   151,
     152,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     138,     0,     0,     0,   171,     0,     0,     0,     0,     0,
       0,     0,     0,   193,     0,   172,   173,     0,   174,     0,
       0,     0,   139,   140,     0,   141,     0,   142,     0,    11,
       0,     0,     0,     0,     0,   192,     0,     0,     0,     0,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
       0,   143,   144,   145,   146,   147,     0,   148,   149,   150,
     151,   152,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   138,     0,     0,     0,   171,     0,     0,   317,    28,
       0,    29,     0,     0,     0,     0,   172,   173,     0,   174,
       0,     0,     0,   139,   140,     0,   141,     0,   142,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   145,   146,   147,     0,   148,   149,
     150,   151,   152,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   138,     0,     0,     0,   171,     0,     0,   195,
       0,     0,     0,     0,     0,     0,     0,   172,   173,     0,
     174,     0,     0,     0,   139,   140,     0,   141,     0,   142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   144,   145,   146,   147,     0,   148,
     149,   150,   151,   152,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   138,     0,     0,     0,   171,     0,     0,
       0,     0,     0,     0,     0,     0,   205,     0,   172,   173,
       0,   174,     0,     0,     0,   139,   140,     0,   141,     0,
     142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   144,   145,   146,   147,     0,
     148,   149,   150,   151,   152,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   138,     0,     0,   221,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   172,
     173,     0,   174,     0,     0,     0,   139,   140,     0,   141,
       0,   142,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   144,   145,   146,   147,
       0,   148,   149,   150,   151,   152,     0,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   138,     0,     0,     0,   171,
       0,     0,   301,     0,     0,     0,     0,     0,     0,     0,
     172,   173,     0,   174,     0,     0,     0,   139,   140,     0,
     141,     0,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,   145,   146,
     147,     0,   148,   149,   150,   151,   152,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   138,     0,     0,     0,
     171,     0,     0,   311,     0,     0,     0,     0,     0,     0,
       0,   172,   173,     0,   174,     0,     0,     0,   139,   140,
       0,   141,     0,   142,     0,     0,     0,     0,     0,     0,
       0,   192,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   144,   145,
     146,   147,     0,   148,   149,   150,   151,   152,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   138,     0,     0,
       0,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   172,   173,     0,   174,     0,     0,     0,   139,
     140,     0,   141,     0,   142,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
     145,   146,   147,     0,   148,   149,   150,   151,   152,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,     0,     0,
     138,     0,   171,     0,     0,     0,   374,     0,     0,     0,
       0,     0,     0,   172,   173,   417,   174,     0,     0,     0,
       0,     0,   139,   140,     0,   141,     0,   142,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   145,   146,   147,     0,   148,   149,   150,
     151,   152,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   138,     0,     0,     0,   171,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   172,   173,     0,   174,
       0,     0,     0,   139,   140,     0,   141,     0,   142,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   145,   146,   147,     0,   148,   149,
     150,   151,   152,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   138,     0,     0,     0,   171,     0,     0,   420,
       0,     0,     0,     0,     0,     0,     0,   172,   173,     0,
     174,     0,     0,     0,   139,   140,     0,   141,     0,   142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   144,   145,   146,   147,     0,   148,
     149,   150,   151,   152,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   138,     0,     0,     0,   171,     0,     0,
       0,   474,     0,     0,     0,     0,     0,     0,   172,   173,
       0,   174,     0,     0,     0,   139,   140,     0,   141,     0,
     142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   144,   145,   146,   147,     0,
     148,   149,   150,   151,   152,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   138,     0,     0,     0,   171,     0,
       0,     0,   517,     0,     0,     0,     0,     0,     0,   172,
     173,     0,   174,     0,     0,     0,   139,   140,     0,   141,
       0,   142,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   144,   145,   146,   147,
       0,   148,   149,   150,   151,   152,     0,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   138,     0,     0,     0,   171,
       0,     0,     0,     0,     0,     0,     0,     0,   519,     0,
     172,   173,     0,   174,     0,     0,     0,   139,   140,     0,
     141,     0,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,   145,   146,
     147,     0,   148,   149,   150,   151,   152,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   138,     0,     0,     0,
     171,     0,     0,     0,     0,     0,     0,     0,     0,   557,
       0,   172,   173,     0,   174,     0,     0,     0,   139,   140,
       0,   141,     0,   142,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   144,   145,
     146,   147,     0,   148,   149,   150,   151,   152,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   138,     0,     0,
       0,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   172,   173,     0,   174,     0,     0,     0,   139,
     140,     0,   141,     0,   142,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
     145,   146,   147,     0,   148,   149,   150,   151,   152,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   138,     0,
       0,     0,   171,     0,     0,     0,     0,     0,     0,     0,
       0,   110,     0,    90,     0,     0,   174,     8,     0,     0,
     139,   140,     0,   141,    11,   142,     0,     0,     0,     0,
       0,     0,     0,     0,    16,   114,    18,    19,    20,    21,
      22,    23,    24,     0,    25,     0,     0,     0,     0,     0,
       0,   145,   146,   147,    26,   148,   149,   150,   151,   152,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   138,
       0,     0,    27,   171,    28,     0,    29,   115,     0,     0,
      30,     0,     0,     0,     0,     0,     0,   174,     0,     0,
       0,   139,   140,     0,   141,     0,   142,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,   150,   151,
     152,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
       0,     1,     0,     2,   171,     0,     0,     3,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     5,   174,     6,
       0,     0,     7,     8,     0,     0,     0,     9,     0,    10,
      11,     0,     0,     0,    12,    13,     0,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     2,     0,     0,     0,     3,
       4,     0,     0,     0,     0,     0,     0,     0,    27,     5,
      28,     6,    29,   300,     7,     8,    30,     0,     0,     9,
       0,    10,    11,     0,     0,     0,    12,    13,     0,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,     0,     0,
       0,     3,     4,     0,     0,     0,     0,     0,     0,     0,
      27,     5,    28,     6,    29,   319,     7,     8,    30,     0,
       0,     9,     0,    10,    11,     0,     0,     0,    12,    13,
       0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     2,
       0,     0,     0,     3,     4,     0,     0,     0,     0,     0,
       0,     0,    27,     5,    28,     6,    29,   418,     7,     8,
      30,     0,     0,     9,     0,    10,    11,     0,     0,     0,
      12,    13,     0,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     2,     0,     0,     0,     3,     4,     0,     0,     0,
       0,     0,     0,     0,    27,     5,    28,     6,    29,   419,
       7,     8,    30,     0,     0,     9,     0,    10,    11,     0,
       0,     0,    12,    13,     0,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,     0,     0,     0,     3,     4,     0,
       0,     0,     0,     0,     0,     0,    27,     5,    28,     6,
      29,   428,     7,     8,    30,     0,     0,     9,     0,    10,
      11,     0,     0,     0,    12,    13,     0,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     2,     0,     0,     0,     3,
       4,     0,     0,     0,     0,     0,     0,     0,    27,     5,
      28,     6,    29,   430,     7,     8,    30,     0,     0,     9,
       0,    10,    11,     0,     0,     0,    12,    13,     0,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,     0,     0,
       0,     3,     4,     0,     0,     0,     0,     0,     0,     0,
      27,     5,    28,     6,    29,   520,     7,     8,    30,     0,
       0,     9,     0,    10,    11,     0,     0,     0,    12,    13,
       0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     2,
       0,     0,     0,     3,     4,     0,     0,     0,     0,     0,
       0,     0,    27,     5,    28,     6,    29,   529,     7,     8,
      30,     0,     0,     9,     0,    10,    11,     0,     0,     0,
      12,    13,     0,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     2,     0,     0,     0,     3,     4,     0,     0,     0,
       0,     0,     0,     0,    27,     5,    28,     6,    29,   544,
       7,     8,    30,     0,     0,     9,     0,    10,    11,     0,
       0,     0,    12,    13,     0,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,     0,     0,     0,     3,     4,     0,
       0,     0,     0,     0,     0,     0,    27,     5,    28,     6,
      29,   559,     7,     8,    30,     0,     0,     9,     0,    10,
      11,     0,     0,     0,    12,    13,     0,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     2,     0,     0,     0,     3,
       4,     0,     0,     0,     0,     0,     0,     0,    27,     5,
      28,     6,    29,   565,     7,     8,    30,     0,     0,     9,
       0,    10,    11,     0,     0,     0,    12,    13,     0,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,     0,     0,
       0,     3,     4,     0,     0,     0,     0,     0,     0,     0,
      27,     5,    28,     6,    29,   566,     7,     8,    30,     0,
       0,     9,     0,    10,    11,     0,     0,     0,    12,    13,
       0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     2,
       0,     0,     0,     3,     4,     0,     0,     0,     0,     0,
       0,     0,    27,     5,    28,     6,    29,   573,     7,     8,
      30,     0,     0,     9,     0,    10,    11,     0,     0,     0,
      12,    13,     0,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     2,     0,     0,     0,     3,     4,     0,     0,     0,
       0,     0,     0,     0,    27,     5,    28,     6,    29,   575,
       7,     8,    30,     0,     0,     9,     0,    10,    11,     0,
       0,     0,    12,    13,     0,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,     0,     0,     0,     3,     4,     0,
       0,     0,     0,     0,     0,     0,    27,     5,    28,     6,
      29,   577,     7,     8,    30,     0,     0,     9,     0,    10,
      11,     0,     0,     0,    12,    13,     0,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     2,     0,     0,     0,     3,
       4,     0,     0,     0,     0,     0,     0,     0,    27,     5,
      28,     6,    29,   579,     7,     8,    30,     0,     0,     9,
       0,    10,    11,     0,     0,     0,    12,    13,     0,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,     0,     0,
       0,     3,     4,     0,     0,     0,     0,     0,     0,     0,
      27,     5,    28,     6,    29,   582,     7,     8,    30,     0,
       0,     9,     0,    10,    11,     0,     0,     0,    12,    13,
       0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     2,
       0,     0,     0,     3,     4,     0,     0,     0,     0,     0,
       0,     0,    27,     5,    28,     6,    29,   585,     7,     8,
      30,     0,     0,     9,     0,    10,    11,     0,     0,     0,
      12,    13,     0,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,     0,   263,   264,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,     0,     8,     0,    27,   265,    28,   266,    29,    11,
     267,   268,    30,     0,     0,   138,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    25,
       0,     0,     0,     0,     0,     0,     0,   139,   140,    26,
     141,     0,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,     0,    28,
       0,    29,   148,   149,   150,   151,   152,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   138,     0,     0,     0,
     171,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,     8,     0,     0,     0,     0,   139,   140,
      11,   141,     0,   142,     0,     0,     0,     0,     0,     0,
      16,   283,    18,    19,    20,    21,    22,    23,    24,     0,
      25,   284,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,   148,   149,   150,   151,   152,     0,   153,
     154,   155,     0,     0,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,     0,   269,   285,
      28,   171,    29,     0,    90,     0,     0,   286,     8,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,   353,    18,    19,    20,
      21,    22,    23,    24,     0,    25,   284,    90,     0,     0,
       0,     8,     0,     0,     0,    26,     0,     0,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,   283,
      18,    19,    20,    21,    22,    23,    24,     0,    25,   284,
     110,     0,    90,    27,   354,    28,     8,    29,    26,     0,
       0,     0,   286,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,    25,     0,    96,   269,     0,    28,     8,
      29,     0,     0,    26,     0,   286,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,     0,    90,     0,
       0,    27,     8,    28,   111,    29,    26,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    25,
       0,    90,    97,     0,    27,     8,    28,     0,    29,    26,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,     0,    90,     0,   296,    27,     8,    28,
       0,    29,    26,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,    25,     0,    90,     0,   372,
      27,     8,    28,     0,    29,    26,     0,     0,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,     0,
      90,     0,   475,    27,     8,    28,     0,    29,    26,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,    25,     0,     0,     0,     0,    27,     0,    28,     0,
      29,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
       0,    28,     0,    29,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410
};

static const yytype_int16 yycheck[] =
{
       0,    13,    32,    29,    82,   175,   269,    13,   306,   269,
     371,   347,   348,   349,   340,   351,   352,    20,    30,    55,
       5,    99,    20,   214,    25,     5,     3,    55,    23,    23,
     221,     8,    32,    10,    13,     5,    26,     3,    25,    91,
      47,    25,     8,    98,     3,     5,     5,    99,    47,     8,
      57,    90,   378,    92,    25,    55,   226,    36,    25,    98,
      85,    47,    91,    83,    84,    42,    95,    92,    47,    48,
      49,    50,    51,    52,    53,    54,    42,    91,   341,    47,
      90,   341,    82,    42,    94,    99,    30,    43,   116,    92,
      91,    92,   128,    47,   130,    98,    91,    91,   459,    99,
      98,    91,    97,    47,   110,    92,   369,    91,   371,   369,
      29,    91,    98,    98,    91,   193,   194,    96,    98,    98,
      90,    92,    92,   102,    91,    91,    47,   205,   128,   207,
     130,    90,    92,    11,   102,    91,    47,    47,    90,   437,
     176,   177,    98,    21,    86,    30,    98,    47,   102,    30,
      92,    30,   182,   514,    32,    99,    34,    57,   102,    37,
      38,    98,    47,   333,   500,   501,    47,    30,    47,   199,
     496,    94,   184,   364,    47,    30,   176,   177,   369,    91,
      90,   479,   182,    94,    47,     0,    98,    91,   104,   550,
     216,    95,    47,   193,   194,    95,   459,   460,    47,   199,
     460,    91,    47,   103,     4,   205,   212,   207,    57,    91,
      92,     3,    57,    91,    99,    91,     8,   102,    99,    95,
      99,   102,     6,   102,     8,     9,    26,    27,   564,    29,
      14,    31,    91,    92,    90,   533,    99,    26,    94,   102,
      96,    25,    26,   413,    99,    29,    26,   102,    26,     7,
      42,   514,    10,    97,   103,   267,    93,    15,   103,    60,
      99,    61,    62,    63,    64,    65,    47,   186,    47,    27,
      28,    29,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,   315,   316,   550,    26,    89,
      91,    94,    91,    92,    95,    47,   326,   216,   328,    83,
      60,    47,    86,     3,    47,     5,    90,    60,     8,    91,
      92,    47,    96,    87,    88,   315,   316,    87,    88,    18,
      19,    26,    30,    94,    93,    92,   326,   339,   328,    30,
      90,    60,    85,    86,    94,    47,    96,    90,   416,    47,
       6,    94,    42,    96,   350,    47,    47,    95,   106,    91,
      91,   429,   136,    97,   138,   139,   140,    91,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    12,    93,   306,   172,   173,
     174,    99,    90,    26,   102,   179,   180,    11,    99,    92,
      92,   102,    16,    98,    95,    92,    95,    91,   192,    91,
      91,   489,     6,   197,    92,   421,   416,   175,    32,    47,
      34,   340,    95,    37,    38,   503,   103,    47,    98,   429,
     214,    91,   190,    91,   218,    91,    98,   221,   222,    98,
      91,   519,    91,    91,   522,    47,    47,   231,   269,   527,
      91,    98,   482,    61,    62,    63,    64,    65,   360,   378,
      91,   422,   218,   493,    72,    73,    74,    75,    76,   547,
     487,   487,   204,    29,   312,    83,    84,   222,    -1,   557,
      -1,    89,   482,    -1,    -1,    -1,    -1,    -1,    -1,   489,
      -1,    -1,    -1,   493,    -1,   525,    -1,    -1,   576,    -1,
      -1,    -1,    -1,   503,   262,   263,   264,   265,   266,    -1,
     268,   269,   296,    -1,    -1,   545,    -1,    -1,   437,   519,
     341,    -1,   522,    -1,    -1,   525,   556,   527,   558,    -1,
      -1,   561,    -1,    -1,    -1,    -1,    -1,   567,    -1,    -1,
      -1,   299,    -1,    -1,   574,   545,    -1,   547,   369,   370,
     371,    -1,    -1,   583,    -1,    -1,   556,   557,   558,    -1,
     479,   561,   346,    10,    -1,    -1,    -1,   567,    -1,    -1,
      -1,    -1,   330,    -1,   574,    -1,   576,   496,    25,    -1,
     364,    -1,    29,   583,    -1,   369,    -1,    -1,   372,    36,
     374,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      -1,    -1,    -1,    -1,   533,    -1,    -1,    -1,    -1,    66,
      -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   415,    -1,   417,    -1,    -1,    -1,   458,   459,   460,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,
      -1,    98,    -1,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,   447,    72,    73,    74,    75,    76,    -1,
      29,   455,    -1,    -1,   432,    83,    84,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    -1,   444,    -1,    -1,    -1,
     474,    -1,   513,   514,   515,    -1,    -1,    -1,    -1,    -1,
     484,    -1,    61,    62,    63,    64,    65,    -1,    -1,     4,
     494,    -1,    -1,    72,    73,    74,    75,    76,    -1,    -1,
     504,    -1,    -1,    -1,    83,    84,    -1,   548,   549,   550,
      89,    26,    27,   517,    29,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,   531,    -1,    -1,
      -1,   572,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       4,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,   100,   101,    -1,   103,    -1,
      -1,    -1,    26,    27,    -1,    29,    -1,    31,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     4,    -1,    -1,    -1,    89,    -1,    -1,    92,    96,
      -1,    98,    -1,    -1,    -1,    -1,   100,   101,    -1,   103,
      -1,    -1,    -1,    26,    27,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     4,    -1,    -1,    -1,    89,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,
     103,    -1,    -1,    -1,    26,    27,    -1,    29,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     4,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,   100,   101,
      -1,   103,    -1,    -1,    -1,    26,    27,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     4,    -1,    -1,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,    -1,   103,    -1,    -1,    -1,    26,    27,    -1,    29,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     4,    -1,    -1,    -1,    89,
      -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,    -1,   103,    -1,    -1,    -1,    26,    27,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     4,    -1,    -1,    -1,
      89,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100,   101,    -1,   103,    -1,    -1,    -1,    26,    27,
      -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     4,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,    -1,   103,    -1,    -1,    -1,    26,
      27,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    -1,    -1,
       4,    -1,    89,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    -1,   100,   101,    19,   103,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     4,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,   103,
      -1,    -1,    -1,    26,    27,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     4,    -1,    -1,    -1,    89,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,
     103,    -1,    -1,    -1,    26,    27,    -1,    29,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     4,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
      -1,   103,    -1,    -1,    -1,    26,    27,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     4,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,    -1,   103,    -1,    -1,    -1,    26,    27,    -1,    29,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     4,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,
     100,   101,    -1,   103,    -1,    -1,    -1,    26,    27,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     4,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,   100,   101,    -1,   103,    -1,    -1,    -1,    26,    27,
      -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     4,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,    -1,   103,    -1,    -1,    -1,    26,
      27,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     4,    -1,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    -1,    25,    -1,    -1,   103,    29,    -1,    -1,
      26,    27,    -1,    29,    36,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    66,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     4,
      -1,    -1,    94,    89,    96,    -1,    98,    99,    -1,    -1,
     102,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    26,    27,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,     7,    -1,     9,    89,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,   103,    25,
      -1,    -1,    28,    29,    -1,    -1,    -1,    33,    -1,    35,
      36,    -1,    -1,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    23,
      96,    25,    98,    99,    28,    29,   102,    -1,    -1,    33,
      -1,    35,    36,    -1,    -1,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    23,    96,    25,    98,    99,    28,    29,   102,    -1,
      -1,    33,    -1,    35,    36,    -1,    -1,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    23,    96,    25,    98,    99,    28,    29,
     102,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    23,    96,    25,    98,    99,
      28,    29,   102,    -1,    -1,    33,    -1,    35,    36,    -1,
      -1,    -1,    40,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    23,    96,    25,
      98,    99,    28,    29,   102,    -1,    -1,    33,    -1,    35,
      36,    -1,    -1,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    23,
      96,    25,    98,    99,    28,    29,   102,    -1,    -1,    33,
      -1,    35,    36,    -1,    -1,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    23,    96,    25,    98,    99,    28,    29,   102,    -1,
      -1,    33,    -1,    35,    36,    -1,    -1,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    23,    96,    25,    98,    99,    28,    29,
     102,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    23,    96,    25,    98,    99,
      28,    29,   102,    -1,    -1,    33,    -1,    35,    36,    -1,
      -1,    -1,    40,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    23,    96,    25,
      98,    99,    28,    29,   102,    -1,    -1,    33,    -1,    35,
      36,    -1,    -1,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    23,
      96,    25,    98,    99,    28,    29,   102,    -1,    -1,    33,
      -1,    35,    36,    -1,    -1,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    23,    96,    25,    98,    99,    28,    29,   102,    -1,
      -1,    33,    -1,    35,    36,    -1,    -1,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    23,    96,    25,    98,    99,    28,    29,
     102,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    23,    96,    25,    98,    99,
      28,    29,   102,    -1,    -1,    33,    -1,    35,    36,    -1,
      -1,    -1,    40,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    23,    96,    25,
      98,    99,    28,    29,   102,    -1,    -1,    33,    -1,    35,
      36,    -1,    -1,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    23,
      96,    25,    98,    99,    28,    29,   102,    -1,    -1,    33,
      -1,    35,    36,    -1,    -1,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    23,    96,    25,    98,    99,    28,    29,   102,    -1,
      -1,    33,    -1,    35,    36,    -1,    -1,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    23,    96,    25,    98,    99,    28,    29,
     102,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      40,    41,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    -1,    94,    32,    96,    34,    98,    36,
      37,    38,   102,    -1,    -1,     4,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    66,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,
      -1,    98,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     4,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    26,    27,
      36,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    -1,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    94,    95,
      96,    89,    98,    -1,    25,    -1,    -1,   103,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    66,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      23,    -1,    25,    94,    95,    96,    29,    98,    66,    -1,
      -1,    -1,   103,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    -1,    25,    94,    -1,    96,    29,
      98,    -1,    -1,    66,    -1,   103,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    -1,    25,    -1,
      -1,    94,    29,    96,    97,    98,    66,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      -1,    25,    92,    -1,    94,    29,    96,    -1,    98,    66,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    -1,    25,    -1,    93,    94,    29,    96,
      -1,    98,    66,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    -1,    25,    -1,    93,
      94,    29,    96,    -1,    98,    66,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    -1,
      25,    -1,    93,    94,    29,    96,    -1,    98,    66,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    -1,    -1,    -1,    -1,    94,    -1,    96,    -1,
      98,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      -1,    96,    -1,    98,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     9,    13,    14,    23,    25,    28,    29,    33,
      35,    36,    40,    41,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    56,    66,    94,    96,    98,
     102,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   130,   131,   132,   133,   135,   136,   139,   140,
     141,   142,   143,   147,   149,   154,   155,   156,   158,   162,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   191,   192,   194,   195,   196,
     197,   198,    98,    25,    92,    47,    25,    92,    47,   189,
      25,   174,   191,   173,   174,   174,    25,    92,   173,    98,
      47,    57,   188,   189,   174,   173,    94,   174,   174,   173,
      23,    97,   163,   173,    47,    99,   154,   157,   159,   160,
     161,   163,   173,   174,    47,   188,     0,   110,    86,    92,
      85,    92,    13,   155,   191,   197,    91,    92,     4,    26,
      27,    29,    31,    55,    56,    57,    58,    59,    61,    62,
      63,    64,    65,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    89,   100,   101,   103,    60,    85,    86,    90,    94,
      96,   104,   109,   174,    20,    92,    98,   174,    91,   190,
      26,   174,    39,    98,    98,    92,   174,    25,    92,   109,
      26,     5,    90,    92,    26,    98,     5,    98,   173,    95,
     189,    97,    23,    97,    93,    47,    91,    99,    91,    99,
      99,    88,    94,   191,   191,    47,    60,   174,   174,   174,
     174,    26,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,    11,    15,    16,    32,    34,    37,    38,    94,
     119,   120,   121,   122,   123,   124,   125,   126,   134,   173,
     191,   191,    47,    47,    57,    95,   103,   134,   164,   165,
     166,   168,   169,   170,   171,   174,    93,   174,   193,    94,
      99,    92,   188,    30,    47,    99,   150,   151,   152,   153,
     161,    92,    47,   173,   174,   109,   109,    92,   174,    99,
      90,   148,   188,    47,    47,   148,   109,    47,   109,    95,
      26,   189,   165,    93,   161,   160,   174,   165,   164,    20,
      98,    94,   134,   174,   173,   173,    10,   173,   173,   173,
      94,   188,   173,    47,    95,   167,   168,   169,   170,   172,
      91,    92,    92,    92,    60,    47,     6,    47,    95,    91,
      91,    91,    93,   174,    93,    97,   173,    92,    98,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    99,   151,    93,   190,    43,    98,    19,    99,    99,
      92,    12,   137,   138,    92,    92,     5,    92,    99,    98,
      99,   173,    26,   134,    95,   188,    99,   150,    47,    92,
       3,     8,    42,   127,   128,    92,   174,    10,   127,   127,
     127,   189,     5,   127,   127,    87,    88,    95,    91,    91,
      91,   120,   165,     6,   165,   168,   169,   170,   168,    47,
     168,   169,   171,   174,    93,    93,   174,    95,    99,   150,
     134,   174,   109,   174,    18,    19,   144,   145,   146,    98,
     189,   138,    47,   109,    25,   173,    98,    99,   173,   174,
      95,    47,   174,    98,    87,    88,   168,   168,   169,    47,
     168,   169,   170,    91,    91,    91,   174,    93,    99,    98,
      99,   174,    98,   144,   146,   109,     5,    98,    92,    99,
     174,    25,    99,   150,    11,    21,    32,    34,    37,    38,
     129,     5,   127,   127,    99,   109,   174,    98,    91,    91,
      91,   168,   168,   169,   168,   174,   109,    98,   109,    99,
      47,   109,   174,    99,    47,    99,    99,   109,   168,   168,
     168,   169,    91,    99,   109,    99,    98,    99,   127,    99,
      91,   168,    99,   109,   168,    99
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
      
/* Line 1267 of yacc.c.  */
#line 2851 "parser.tab.cc"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 768 "parser.y"



int yyerror(char *err) {
  if(err) {
    fprintf(stderr, "Parsing error: [%s]\n", err);
  }
}

/* Return 1 stops at EOF,
 * return 0 continues reading. 
 */
int yywrap() {
  return 1;
}

