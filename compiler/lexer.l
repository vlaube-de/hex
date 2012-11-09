/*
 * HEX Programming Language
 * Copyright (C) 2012  Yanzheng Li
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


%{
#include <stdio.h>
#include "parser.tab.h"

#define DEBUG
#undef DEBUG

#ifndef DEBUG

#define RETURN(our_type, yytext, token_type)        \
  switch(token_type) {                              \
    case DECIMALINTEGER:                            \
      yylval.integer = atoi(yytext);                \
      return DECIMALINTEGER;                        \
      break;                                        \
    case BININTEGER:                                \
      yylval.integer = atoi(yytext);                \
      return BININTEGER;                            \
      break;                                        \
    case OCTINTEGER:                                \
      yylval.integer = atoi(yytext);                \
      return OCTINTEGER;                            \
      break;                                        \
    case HEXINTEGER:                                \
      yylval.integer = atoi(yytext);                \
      return HEXINTEGER;                            \
      break;                                        \
    case FLOATINGNUM:                               \
      yylval.floating = atof(yytext);               \
      return FLOATINGNUM;                           \
      break;                                        \
    case CHARACTER_LITERAL:                         \
      yylval.character = yytext[1];                 \
      return CHARACTER_LITERAL;                     \
      break;                                        \
    case STRING_LITERAL:                            \
      yylval.string = yytext;                       \
      return STRING_LITERAL;                        \
      break;                                        \
    default:                                        \
      yylval.string = yytext;                       \
      return token_type;                            \
      break;                                        \
  } /* end of switch(token_type) */
#else

#define RETURN(our_type, yytext, token_type)        \
  printf("[%s]: %s\n", our_type, yytext);

#endif /* #define DEBUG */

int current_line_indent = 0;            /* indentation of current line */
int indent_level = 0;                   /* indentation level passed to parser */

%}

/* Multi-line comment state */
%x IN_COMMENT

/* String literal state */
%x IN_STRING

/* Indent level */
%x IN_INDENT

%option stack
%%

#keywords
"and"                       RETURN("KEYWORD", yytext, AND);
"as"                        RETURN("KEYWORD", yytext, AS);
"base"                      RETURN("KEYWORD", yytext, BASE);
"bool"                      RETURN("KEYWORD", yytext, BOOL);
"break"                     RETURN("KEYWORD", yytext, BREAK);
"case"                      RETURN("KEYWORD", yytext, CASE);
"catch"                     RETURN("KEYWORD", yytext, CATCH);
"char"                      RETURN("KEYWORD", yytext, CHAR);
"class"                     RETURN("KEYWORD", yytext, CLASS);
"const"                     RETURN("KEYWORD", yytext, CONST);
"continue"                  RETURN("KEYWORD", yytext, CONTINUE);
"coroutine"                 RETURN("KEYWORD", yytext, COROUTINE);
"def"                       RETURN("KEYWORD", yytext, DEF);
"defer"                     RETURN("KEYWORD", yytext, DEFER);
"default"                   RETURN("KEYWORD", yytext, DEFAULT);
"do"                        RETURN("KEYWORD", yytext, DO);
"double"                    RETURN("KEYWORD", yytext, DOUBLE);
"elif"                      RETURN("KEYWORD", yytext, ELIF);
"else"                      RETURN("KEYWORD", yytext, ELSE);
"ext"                       RETURN("KEYWORD", yytext, EXT);
"float"                     RETURN("KEYWORD", yytext, FLOAT);
"for"                       RETURN("KEYWORD", yytext, FOR);
"from"                      RETURN("KEYWORD", yytext, FROM);
"if"                        RETURN("KEYWORD", yytext, IF);
"import"                    RETURN("KEYWORD", yytext, IMPORT);
"in"                        RETURN("KEYWORD", yytext, IN);
"int"                       RETURN("KEYWORD", yytext, INT);
"interface"                 RETURN("KEYWORD", yytext, INTERFACE);
"is"                        RETURN("KEYWORD", yytext, IS);
"is not"                    RETURN("KEYWORD", yytext, IS_NOT);
"lazy"                      RETURN("KEYWORD", yytext, LAZY);
"lock"                      RETURN("KEYWORD", yytext, LOCK);
"long"                      RETURN("KEYWORD", yytext, LONG);
"new"                       RETURN("KEYWORD", yytext, NEW);
"not"                       RETURN("KEYWORD", yytext, NOT);
"or"                        RETURN("KEYWORD", yytext, OR);
"pass"                      RETURN("KEYWORD", yytext, PASS);
"private"                   RETURN("KEYWORD", yytext, PRIVATE);
"protected"                 RETURN("KEYWORD", yytext, PROTECTED);
"public"                    RETURN("KEYWORD", yytext, PUBLIC);
"ref"                       RETURN("KEYWORD", yytext, REF);
"return"                    RETURN("KEYWORD", yytext, RETURN);
"short"                     RETURN("KEYWORD", yytext, SHORT);
"sizeof"                    RETURN("KEYWORD", yytext, SIZEOF);
"stackalloc"                RETURN("KEYWORD", yytext, STACKALLOC);
"static"                    RETURN("KEYWORD", yytext, STATIC);
"string"                    RETURN("KEYWORD", yytext, STRING);
"struct"                    RETURN("KEYWORD", yytext, STRUCT);
"switch"                    RETURN("KEYWORD", yytext, SWITCH);
"task"                      RETURN("KEYWORD", yytext, TASK);
"then"                      RETURN("KEYWORD", yytext, THEN);
"this"                      RETURN("KEYWORD", yytext, THIS);
"throw"                     RETURN("KEYWORD", yytext, THROW);
"try"                       RETURN("KEYWORD", yytext, TRY);
"typeof"                    RETURN("KEYWORD", yytext, TYPEOF);
"uchar"                     RETURN("KEYWORD", yytext, UCHAR);
"uint"                      RETURN("KEYWORD", yytext, UINT);
"ulong"                     RETURN("KEYWORD", yytext, ULONG);
"unlock"                    RETURN("KEYWORD", yytext, UNLOCK);
"ushort"                    RETURN("KEYWORD", yytext, USHORT);
"virtual"                   RETURN("KEYWORD", yytext, VIRTUAL);
"volatile"                  RETURN("KEYWORD", yytext, VOLATILE);
"_weakref"                  RETURN("KEYWORD", yytext, WEAKREF);
"where"                     RETURN("KEYWORD", yytext, WHERE);
"while"                     RETURN("KEYWORD", yytext, WHILE);
"finally"                   RETURN("KEYWORD", yytext, FINALLY);

#identifiers
[_a-zA-Z][_a-zA-Z0-9]*      RETURN("IDENTIFIER", yytext, IDENTIFIER);

#character_literal
L?'(\\.|[^\\'])+'           RETURN("CHARACTER_LITERAL", yytext, CHARACTER_LITERAL);

#string_literal
L?\"(\\.|[^\\"])*\"         RETURN("STRING_LITERAL", yytext, STRING_LITERAL);

#inline_comment
\/\/.*                      RETURN("COMMENT", yytext, COMMENT);

#integer
([0]|[0-9]*)[lL]?           RETURN("INTEGER", yytext, DECIMALINTEGER);


#binary_integer
0[bB][0-1]+                 RETURN("BININTEGER", yytext, BININTEGER);

#oct_integer
0[oO][0-7]+                 RETURN("OCTINTEGER", yytext, OCTINTEGER);

#hexidecimal_integer
0[xX][0-9a-fA-F]+           RETURN("HEXINTEGER", yytext, HEXINTEGER);

#floating_number
[0-9]*\.[0-9]+([eE][-+]?[0-9]+)?  RETURN("FLOATINGNUM", yytext, FLOATINGNUM);


#arithmetic_operator
"+"                         RETURN("ARITHMETIC OPERATOR", yytext, PLUS_OP);
"-"                         RETURN("ARITHMETIC OPERATOR", yytext, MINUS_OP);
"*"                         RETURN("ARITHMETIC OPERATOR", yytext, MUL_OP);
"/"                         RETURN("ARITHMETIC OPERATOR", yytext, DIV_OP);
"%"                         RETURN("ARITHMETIC OPERATOR", yytext, MOD_OP);

#assignment_operator
"="                         RETURN("ASSIGNMENT OPERATOR", yytext, ASSIGN_OP);
"~="                        RETURN("ASSIGNMENT OPERATOR", yytext, ASSIGN_OP_WEAKREF);  
"+="                        RETURN("ASSIGNMENT OPERATOR", yytext, ASSIGN_PLUS);
"-="                        RETURN("ASSIGNMENT OPERATOR", yytext, ASSIGN_MINUS);
"*="                        RETURN("ASSIGNMENT OPERATOR", yytext, ASSIGN_MUL);
"/="                        RETURN("ASSIGNMENT OPERATOR", yytext, ASSIGN_DIV);
"%="                        RETURN("ASSIGNMENT OPERATOR", yytext, ASSIGN_MOD);

#bitwise_operator
"~"                         RETURN("BITWISE OPERATOR", yytext, BITWISE_NOT);
"&"                         RETURN("BITWISE OPERATOR", yytext, BITWISE_AND);
"|"                         RETURN("BITWISE OPERATOR", yytext, BITWISE_OR);
"^"                         RETURN("BITWISE OPERATOR", yytext, BITWISE_XOR);
"<<"                        RETURN("BITWISE OPERATOR", yytext, BITWISE_SHIFTLEFT);
">>"                        RETURN("BITWISE OPERATOR", yytext, BITWISE_SHIFTRIGHT); 
"&="                        RETURN("BITWISE OPERATOR", yytext, ASSIGN_BITWISE_AND);
"|="                        RETURN("BITWISE OPERATOR", yytext, ASSIGN_BITWISE_OR);
"^="                        RETURN("BITWISE OPERATOR", yytext, ASSIGN_BITWISE_XOR);
"<<="                       RETURN("BITWISE OPERATOR", yytext, ASSIGN_SHIFTLEFT);
">>="                       RETURN("BITWISE OPERATOR", yytext, ASSIGN_SHIFTRIGHT);

#equality_operator
"=="                        RETURN("EQUALITY OPERATOR", yytext, EQ_OP);
"!="                        RETURN("EQUALITY OPERATOR", yytext, NEQ_OP);
">"                         RETURN("EQUALITY OPERATOR", yytext, GREATER_OP);
"<"                         RETURN("EQUALITY OPERATOR", yytext, LESS_OP);
">="                        RETURN("EQUALITY OPERATOR", yytext, GEQ_OP);
"<="                        RETURN("EQUALITY OPERATOR", yytext, LEQ_OP);

#increment_&_decrement
"++"                        RETURN("INCREMENT", yytext, INC_OP);
"--"                        RETURN("DECREMENT", yytext, DEC_OP);

#lambda_operator
"=>"                        RETURN("LAMBDA OPERATOR", yytext, LAMBDA_OP);


#dot
"."                         RETURN("DOT", yytext, DOT);

#comma
","                         RETURN("COMMA", yytext, COMMA);

#semicolon
";"                         RETURN("SEMICOLON", yytext, SEMICOLON);

#colon
":"                         RETURN("COLON", yytext, COLON);

#bracket
"("                         RETURN("PARENTHESIS", yytext, LPAREN);
")"                         RETURN("PARENTHESIS", yytext, RPAREN);


#sqaure_bracket
"["                         RETURN("SQUARE_BRACKET", yytext, LBRACKET);
"]"                         RETURN("SQUARE_BRACKET", yytext, RBRACKET);


#curly_braces
"{"                         RETURN("CURLY_BRACE", yytext, LBRACE);
"}"                         RETURN("CURLY_BRACE", yytext, RBRACE);

#ellipsis
"..."                       RETURN("POND", yytext, ELLIPSIS);

#pond
"#"                         RETURN("POND", yytext, POND);

#at
"@"                         RETURN("AT", yytext, AT);

#multi-line_comment
<INITIAL>{
"/*"                        BEGIN(IN_COMMENT);
}

<IN_COMMENT>{
"*/"                        BEGIN(INITIAL);
[^*\n]+                     // eat comment in chunks
"*"                         // eat the lone star
\n                          yylineno++;
}

<INITIAL>\n                 {
                              current_line_indent = 0;
                              yy_push_state(IN_INDENT); /* this solves the "return NEWLINE before BEGIN(IN_INDENT)" issue */
                              printf("NEWLINE\n");
                              return NEWLINE;
                            }

#indentation
<IN_INDENT>"  "             {
                              current_line_indent++;
                            }

<IN_INDENT>\t               {
                              /* tab */
                              printf("TAB\n");
                            }

<IN_INDENT>\n               {
                              current_line_indent = 0; /* ignore blank line*/
                              printf("NEWLINE\n");
                              return NEWLINE;
                            }

<IN_INDENT>.                {
                              unput(*yytext);
                              /* puts the character back to input stream and scans next character */
                              if(current_line_indent  > indent_level) {
                                indent_level++;
                                printf("INDENT\n");
                                return INDENT;
                              } else if(current_line_indent  < indent_level) {
                                indent_level--;
                                printf("DEDENT\n");
                                return DEDENT;
                              } else {
                                BEGIN(INITIAL);
                              }
                            }

.                           {
                              /* ignore bad characters */
                            }


%%

int
main(int argc, char** argv)
{
  if((yyin = fopen(argv[1], "r")) == 0) {
      exit(1);
  }
  yylex();
  yyparse();
  return 0;
}