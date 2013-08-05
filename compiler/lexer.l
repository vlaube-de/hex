/*
 * HEX Programming Language
 * Copyright (C) 2013  Yanzheng Li
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


#define EAT_TOKEN(yytext, token_type)   \
  yylval.string = strdup(yytext);       \
  return token_type;

int new_line_returned = 0;
%}


%%
"#".*\n                             yylineno++;

"after"                             EAT_TOKEN(yytext, AFTER);
"and"                               EAT_TOKEN(yytext, AND);
"as"                                EAT_TOKEN(yytext, AS);
"async"								EAT_TOKEN(yytext, ASYNC);
"await"                             EAT_TOKEN(yytext, AWAIT);
"before"                            EAT_TOKEN(yytext, BEFORE);
"break"                             EAT_TOKEN(yytext, BREAK);
"by"                                EAT_TOKEN(yytext, BY);
"cancel"                            EAT_TOKEN(yytext, CANCEL);
"catch"                             EAT_TOKEN(yytext, CATCH);
"class"                             EAT_TOKEN(yytext, CLASS);
"continue"                          EAT_TOKEN(yytext, CONTINUE);
"defer"                             EAT_TOKEN(yytext, DEFER);
"delay"                             EAT_TOKEN(yytext, DELAY);
"delete"                            EAT_TOKEN(yytext, DELETE)
"elif"                              EAT_TOKEN(yytext, ELIF);
"else"                              EAT_TOKEN(yytext, ELSE);
"extends"                           EAT_TOKEN(yytext, EXTENDS);
"finish"                            EAT_TOKEN(yytext, FINISH);
"for"                               EAT_TOKEN(yytext, FOR);
"from"                              EAT_TOKEN(yytext, FROM);
"if"                                EAT_TOKEN(yytext, IF);
"in"                                EAT_TOKEN(yytext, IN);
"is"                                EAT_TOKEN(yytext, IS);
"lock"                              EAT_TOKEN(yytext, LOCK);
"not"                               EAT_TOKEN(yytext, NOT);
"operator"                          EAT_TOKEN(yytext, OPERATOR);
"or"                                EAT_TOKEN(yytext, OR);
"pause"                             EAT_TOKEN(yytext, PAUSE);
"resume"                            EAT_TOKEN(yytext, RESUME);
"return"                            EAT_TOKEN(yytext, RETURN);
"self"                              EAT_TOKEN(yytext, SELF);
"start"                             EAT_TOKEN(yytext, START);
"stop"                              EAT_TOKEN(yytext, STOP);
"then"                              EAT_TOKEN(yytext, THEN);
"throw"                             EAT_TOKEN(yytext, THROW);
"try"                               EAT_TOKEN(yytext, TRY);
"until"                             EAT_TOKEN(yytext, UNTIL);
"using"                             EAT_TOKEN(yytext, USING);
"when"                              EAT_TOKEN(yytext, WHEN);
"where"                             EAT_TOKEN(yytext, WHERE);
"while"                             EAT_TOKEN(yytext, WHILE);
"with"                              EAT_TOKEN(yytext, WITH);
"yield"                             EAT_TOKEN(yytext, YIELD);

[_a-zA-Z][_a-zA-Z0-9]*              EAT_TOKEN(yytext, IDENTIFIER);
'(\\.|[^\\'])*'                     EAT_TOKEN(yytext, STRING_LITERAL_SINGLE);
\"(\\.|[^\\"])*\"                   EAT_TOKEN(yytext, STRING_LITERAL_DOUBLE);
[0]|[0-9]*                          EAT_TOKEN(yytext, DECIMALINTEGER);
0[bB][0-1]+                         EAT_TOKEN(yytext, BININTEGER);
0[oO][0-7]+                         EAT_TOKEN(yytext, OCTINTEGER);
0[xX][0-9a-fA-F]+                   EAT_TOKEN(yytext, HEXINTEGER);
[0-9]*\.[0-9]+([eE][-+]?[0-9]+)?    EAT_TOKEN(yytext, FLOAT);

"+"                                 EAT_TOKEN(yytext, PLUS_OP);
"-"                                 EAT_TOKEN(yytext, MINUS_OP);
"*"                                 EAT_TOKEN(yytext, MUL_OP);
"/"                                 EAT_TOKEN(yytext, DIV_OP);
"%"                                 EAT_TOKEN(yytext, MOD_OP);
"="                                 EAT_TOKEN(yytext, ASSIGN_OP);
"+="                                EAT_TOKEN(yytext, ASSIGN_PLUS);
"-="                                EAT_TOKEN(yytext, ASSIGN_MINUS);
"*="                                EAT_TOKEN(yytext, ASSIGN_MUL);
"/="                                EAT_TOKEN(yytext, ASSIGN_DIV);
"%="                                EAT_TOKEN(yytext, ASSIGN_MOD);
"~"                                 EAT_TOKEN(yytext, BITWISE_NOT);
"&"                                 EAT_TOKEN(yytext, BITWISE_AND);
"|"                                 EAT_TOKEN(yytext, BITWISE_OR);
"^"                                 EAT_TOKEN(yytext, BITWISE_XOR);
"<<"                                EAT_TOKEN(yytext, BITWISE_SHIFTLEFT);
">>"                                EAT_TOKEN(yytext, BITWISE_SHIFTRIGHT); 
"&="                                EAT_TOKEN(yytext, ASSIGN_BITWISE_AND);
"|="                                EAT_TOKEN(yytext, ASSIGN_BITWISE_OR);
"^="                                EAT_TOKEN(yytext, ASSIGN_BITWISE_XOR);
"<<="                               EAT_TOKEN(yytext, ASSIGN_SHIFTLEFT);
">>="                               EAT_TOKEN(yytext, ASSIGN_SHIFTRIGHT);
"=="                                EAT_TOKEN(yytext, EQ_OP);
"!="                                EAT_TOKEN(yytext, NEQ_OP);
">"                                 EAT_TOKEN(yytext, GREATER_OP);
"<"                                 EAT_TOKEN(yytext, LESS_OP);
">="                                EAT_TOKEN(yytext, GEQ_OP);
"<="                                EAT_TOKEN(yytext, LEQ_OP);
"++"                                EAT_TOKEN(yytext, INC_OP);
"--"                                EAT_TOKEN(yytext, DEC_OP);
"<<<"                               EAT_TOKEN(yytext, INPUT_OP);
">>>"                               EAT_TOKEN(yytext, OUTPUT_OP);
"->"                                EAT_TOKEN(yytext, LAMBDA_OP);
"=>"                                EAT_TOKEN(yytext, ARROW);
"."                                 EAT_TOKEN(yytext, DOT);
","                                 EAT_TOKEN(yytext, COMMA);
";"                                 EAT_TOKEN(yytext, SEMICOLON);
":"                                 EAT_TOKEN(yytext, COLON);
"("                                 EAT_TOKEN(yytext, LPAREN);
")"                                 EAT_TOKEN(yytext, RPAREN);
"["                                 EAT_TOKEN(yytext, LBRACKET);
"]"                                 EAT_TOKEN(yytext, RBRACKET);
"{"                                 EAT_TOKEN(yytext, LBRACE);
"}"                                 EAT_TOKEN(yytext, RBRACE);
"..."                               EAT_TOKEN(yytext, ELLIPSIS);
".."                                EAT_TOKEN(yytext, ELLIPSIS_SHORT);
"@"                                 EAT_TOKEN(yytext, AT);
"**"                                EAT_TOKEN(yytext, STARS);

<INITIAL>\n                         {
                                        if(!new_line_returned)
                                        {
                                            new_line_returned = 1;
                                            return NEWLINE;
                                        }

                                    }

.                                   {
                                        /* ignore bad characters */
                                    }


%%
