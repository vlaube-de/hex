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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 30 "parser.y"
{
  char* string;
}
/* Line 1529 of yacc.c.  */
#line 265 "parser.tab.hh"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

