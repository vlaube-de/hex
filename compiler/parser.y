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

#define YYDEBUG 1
#define YYERROR_VERBOSE

yydebug = 0;


%}

%union {
  char* string;
};

%token <string> AFTER
%token <string> AND
%token <string> AS
%token <string> ASYNC
%token <string> AWAIT
%token <string> BEFORE
%token <string> BREAK
%token <string> BY
%token <string> CANCEL
%token <string> CATCH
%token <string> CLASS
%token <string> CONTINUE
%token <string> DEFER
%token <string> DELAY
%token <string> DELETE
%token <string> ELIF
%token <string> ELSE
%token <string> EXTENDS
%token <string> FINISH
%token <string> FINALLY
%token <string> FOR
%token <string> FROM
%token <string> IF
%token <string> IN
%token <string> IS
%token <string> LOCK
%token <string> NOT
%token <string> OPERATOR
%token <string> OR
%token <string> PAUSE
%token <string> RESUME
%token <string> RETURN
%token <string> SELF
%token <string> START
%token <string> STOP
%token <string> THEN
%token <string> THROW
%token <string> TRY
%token <string> UNTIL
%token <string> USING
%token <string> WHEN
%token <string> WHERE
%token <string> WHILE
%token <string> WITH
%token <string> YIELD

%token <string> IDENTIFIER
%token <string> STRING_LITERAL_SINGLE
%token <string> STRING_LITERAL_DOUBLE
%token <string> DECIMALINTEGER
%token <string> BININTEGER
%token <string> OCTINTEGER
%token <string> HEXINTEGER
%token <string> FLOAT
%token <string> PLUS_OP
%token <string> MINUS_OP
%token <string> MUL_OP
%token <string> DIV_OP
%token <string> MOD_OP
%token <string> ASSIGN_OP
%token <string> ASSIGN_PLUS
%token <string> ASSIGN_MINUS
%token <string> ASSIGN_MUL
%token <string> ASSIGN_DIV
%token <string> ASSIGN_MOD
%token <string> BITWISE_NOT
%token <string> BITWISE_AND
%token <string> BITWISE_OR
%token <string> BITWISE_XOR
%token <string> BITWISE_SHIFTLEFT
%token <string> BITWISE_SHIFTRIGHT
%token <string> ASSIGN_BITWISE_AND
%token <string> ASSIGN_BITWISE_OR
%token <string> ASSIGN_BITWISE_XOR
%token <string> ASSIGN_SHIFTLEFT
%token <string> ASSIGN_SHIFTRIGHT
%token <string> EQ_OP
%token <string> NEQ_OP
%token <string> GREATER_OP
%token <string> LESS_OP
%token <string> GEQ_OP
%token <string> LEQ_OP
%token <string> INC_OP
%token <string> DEC_OP
%token <string> INPUT_OP
%token <string> OUTPUT_OP
%token <string> LAMBDA_OP
%token <string> ARROW
%token <string> DOT
%token <string> COMMA
%token <string> SEMICOLON
%token <string> COLON
%token <string> LPAREN
%token <string> RPAREN
%token <string> LBRACKET
%token <string> RBRACKET
%token <string> LBRACE
%token <string> RBRACE
%token <string> ELLIPSIS
%token <string> ELLIPSIS_SHORT
%token <string> AT
%token <string> STARS

%token NEWLINE

%left     IDENTIFIER
%left     ELLIPSIS ELLIPSIS_SHORT
%left     LAMBDA_OP ARROW
%right    ASSIGN_OP
%left     ASSIGN_PLUS ASSIGN_MINUS
%left     ASSIGN_MUL ASSIGN_DIV ASSIGN_MOD
%left     ASSIGN_BITWISE_AND ASSIGN_BITWISE_OR ASSIGN_BITWISE_XOR ASSIGN_SHIFTLEFT ASSIGN_SHIFTRIGHT
%left     IF THEN ELSE
%left     OR AND
%left     BITWISE_NOT BITWISE_AND BITWISE_OR BITWISE_XOR
%left     EQ_OP NEQ_OP IS NOT
%left     GREATER_OP LESS_OP GEQ_OP LEQ_OP
%left     BITWISE_SHIFTLEFT BITWISE_SHIFTRIGHT
%left     PLUS_OP MINUS_OP
%left     MUL_OP DIV_OP MOD_OP
%nonassoc DEC_OP INC_OP
%left     LBRACE RBRACE
%left     LBRACKET RBRACKET
%left     LPAREN RPAREN
%left     COMMA

%nonassoc UMINUS


%error-verbose
%debug

%{

%}

%%

input
  : stmt_group
  ;

stmt_group
  : stmt
  | stmt_group stmt
  ;

stmt
  : compound_stmt
  | simple_stmt
  ;

simple_stmt
  : expr_list SEMICOLON
  | assignment_stmt
  | using_stmt
  | return_stmt
  | continue_stmt
  | break_stmt
  | input_stmt
  | output_stmt
  ;

continue_stmt
  : CONTINUE SEMICOLON
  | CONTINUE IF expr SEMICOLON
  ;

break_stmt
  : BREAK SEMICOLON
  | BREAK IF expr SEMICOLON
  ;

return_stmt
  : RETURN SEMICOLON
  | RETURN expr_list SEMICOLON
  | RETURN IF expr SEMICOLON
  | RETURN expr_list IF expr SEMICOLON
  ;

compound_stmt
  : if_stmt
  | while_stmt
  | with_stmt
  | lock_stmt
  | try_stmt
  | for_stmt
  | await_stmt
  | class_def
  ;

await_stmt
  : AWAIT LBRACE stmt_group RBRACE
  ;

task_def
  : task_clause
  | task_def COMMA task_clause
  ;

task_clause
  : start_clause
  | pause_clause
  | stop_clause
  | cancel_clause
  | delay_clause
  | resume_clause
  ;

stop_clause
  : STOP expr_list conditional_clause
  ;

delay_clause
  : DELAY expr_list conditional_clause
  | DELAY expr_list BY expr
  | DELAY BY expr
  ;

cancel_clause
  : CANCEL expr_list conditional_clause
  ;

resume_clause
  : RESUME expr_list conditional_clause
  ;

pause_clause
  : PAUSE expr_list conditional_clause
  ;

start_clause
  : START IDENTIFIER
  | START LPAREN target_list RPAREN
  | START LPAREN target_list RPAREN AS IDENTIFIER
  | START IDENTIFIER conditional_clause
  | START LPAREN target_list RPAREN conditional_clause
  | START LPAREN target_list RPAREN AS IDENTIFIER conditional_clause
  ;

conditional_clause
  : conditional_preposition expr_list task_state
  ;

conditional_preposition
  : BEFORE
  | AFTER
  | WHEN
  | UNTIL
  ;

task_state
  : START
  | PAUSE
  | CANCEL
  | RESUME
  | FINISH
  | STOP
  ;

output_stmt
  : output_stmt_list SEMICOLON
  ;

output_stmt_list
  : primary OUTPUT_OP primary
  | output_stmt_list OUTPUT_OP primary
  ;

input_stmt
  : input_stmt_list SEMICOLON
  ;

input_stmt_list
  : primary INPUT_OP primary
  | input_stmt_list INPUT_OP primary
  ;

lambda
  : LPAREN parameter_list RPAREN ARROW LBRACE stmt_group RBRACE
  | LPAREN RPAREN ARROW LBRACE stmt_group RBRACE
  | LPAREN parameter_list RPAREN LAMBDA_OP expr_list
  | LPAREN RPAREN LAMBDA_OP expr_list
  | LPAREN parameter_list RPAREN ARROW LBRACE RBRACE
  | LPAREN RPAREN ARROW LBRACE RBRACE
  ;

class_def
  : CLASS IDENTIFIER LBRACE attribute_def_list RBRACE
  | CLASS IDENTIFIER EXTENDS name LBRACE attribute_def_list RBRACE
  | decorator_list CLASS IDENTIFIER LBRACE attribute_def_list RBRACE
  | decorator_list CLASS IDENTIFIER EXTENDS name LBRACE attribute_def_list RBRACE
  | CLASS IDENTIFIER LBRACE RBRACE
  | CLASS IDENTIFIER EXTENDS name LBRACE RBRACE
  | decorator_list CLASS IDENTIFIER LBRACE RBRACE
  | decorator_list CLASS IDENTIFIER EXTENDS name LBRACE RBRACE
  ;

try_stmt
  : TRY LBRACE stmt_group RBRACE catch_stmt_group
  ;

catch_stmt_group
  : catch_stmt
  | catch_stmt_group catch_stmt
  ;

catch_stmt
  : CATCH LBRACE stmt_group RBRACE
  | CATCH target_list LBRACE stmt_group RBRACE
  | CATCH target_list AS IDENTIFIER LBRACE stmt_group RBRACE
  ;

while_stmt
  : WHILE expr LBRACE stmt_group RBRACE
  ;

lock_stmt
  : LOCK expr_list LBRACE stmt_group RBRACE
  ;

with_stmt
  : WITH expr_list LBRACE stmt_group RBRACE
  | WITH expr_list AS IDENTIFIER LBRACE stmt_group RBRACE
  ;

for_stmt
  : FOR target_list IN expr_list LBRACE stmt_group RBRACE
  | FOR target_list IN expr_list WHERE expr LBRACE stmt_group RBRACE
  ;

if_stmt
  : IF expr LBRACE stmt_group RBRACE
  | IF expr LBRACE stmt_group RBRACE else_stmt
  | IF expr LBRACE stmt_group RBRACE elif_group
  | IF expr LBRACE stmt_group RBRACE elif_group else_stmt
  ;

else_stmt
  : ELSE LBRACE stmt_group RBRACE
  ;

elif_group
  : elif_stmt
  | elif_group elif_stmt
  ;

elif_stmt                              
  : ELIF expr LBRACE stmt_group RBRACE
  ;

using_stmt
  : USING name SEMICOLON
  | USING name AS IDENTIFIER SEMICOLON
  | USING target_list IN using_src SEMICOLON
  | USING target_list IN using_src AS IDENTIFIER SEMICOLON
  | USING MUL_OP IN using_src SEMICOLON
  ;

using_src
  : name
  | DOT
  ;

assignment_stmt
  : target_list ASSIGN_OP expr_list SEMICOLON
  | target_list ASSIGN_OP DEFER expr_list SEMICOLON
  | target_list ASSIGN_OP lambda SEMICOLON
  | target_list ASSIGN_OP task_def SEMICOLON
  ;

attribute_def_list
  : attribute_def
  | attribute_def_list attribute_def
  ;

attribute_def
  : field_def_single
  | field_def_double
  | operator_def
  ;

operator_def
  : operator COLON lambda
  ;

operator
  : OPERATOR PLUS_OP
  | OPERATOR MINUS_OP
  | OPERATOR MUL_OP
  | OPERATOR DIV_OP
  | OPERATOR MOD_OP
  | OPERATOR BITWISE_NOT
  | OPERATOR BITWISE_AND
  | OPERATOR BITWISE_OR
  | OPERATOR BITWISE_XOR
  | OPERATOR BITWISE_SHIFTLEFT
  | OPERATOR BITWISE_SHIFTRIGHT
  | OPERATOR EQ_OP
  | OPERATOR NEQ_OP
  | OPERATOR GREATER_OP
  | OPERATOR LESS_OP
  | OPERATOR GEQ_OP
  | OPERATOR LEQ_OP
  | OPERATOR INC_OP
  | OPERATOR DEC_OP
  | OPERATOR ASSIGN_OP
  | OPERATOR ASSIGN_PLUS
  | OPERATOR ASSIGN_MINUS
  | OPERATOR ASSIGN_MUL
  | OPERATOR ASSIGN_DIV
  | OPERATOR ASSIGN_MOD
  | OPERATOR ASSIGN_BITWISE_AND
  | OPERATOR ASSIGN_BITWISE_OR
  | OPERATOR ASSIGN_BITWISE_XOR
  | OPERATOR ASSIGN_SHIFTLEFT
  | OPERATOR ASSIGN_SHIFTRIGHT
  | OPERATOR INPUT_OP
  | OPERATOR OUTPUT_OP
  ;

decorator_list
  : decorator
  | decorator_list decorator
  ;

decorator
  : AT name
  | AT name LPAREN arg_list RPAREN
  ;

dict_form
  : LBRACE dict_form_list RBRACE
  | LBRACE comprehension RBRACE
  ;

dict_form_list
  : field_def_single
  | dict_form_list COMMA field_def_single
  ;

field_def_double
  : IDENTIFIER COLON COLON expr
  | IDENTIFIER COLON COLON lambda
  | decorator_list IDENTIFIER COLON COLON lambda
  ;

field_def_single
  : IDENTIFIER COLON expr
  | IDENTIFIER COLON lambda
  | decorator_list IDENTIFIER COLON lambda
  ;

list_form
  : LBRACKET expr_list RBRACKET
  | LBRACKET comprehension RBRACKET
  ;

comprehension
  : FOR target_list IN expr_list
  | FOR target_list IN expr_list IF expr
  | expr_list FOR target_list IN expr_list
  | expr_list FOR target_list IN expr_list IF expr
  ;

arg_list
  : val_list
  | keyword_val_list
  | arg_val
  | kwarg_val
  | val_list COMMA keyword_val_list
  | val_list COMMA arg_val
  | val_list COMMA kwarg_val
  | val_list COMMA arg_val COMMA kwarg_val
  | val_list COMMA keyword_val_list COMMA arg_val
  | val_list COMMA keyword_val_list COMMA kwarg_val
  | val_list COMMA keyword_val_list COMMA arg_val COMMA kwarg_val
  | keyword_val_list COMMA arg_val
  | keyword_val_list COMMA kwarg_val
  | keyword_val_list COMMA arg_val COMMA kwarg_val
  | arg_val COMMA kwarg_val
  ;

val_list
  : expr
  | lambda
  | val_list COMMA expr
  | val_list COMMA lambda
  ;

parameter_list
  : simple_param_list
  | keyword_val_list
  | arg_val
  | kwarg_val
  | simple_param_list COMMA keyword_val_list
  | simple_param_list COMMA arg_val
  | simple_param_list COMMA kwarg_val
  | simple_param_list COMMA arg_val COMMA kwarg_val
  | simple_param_list COMMA keyword_val_list COMMA arg_val
  | simple_param_list COMMA keyword_val_list COMMA kwarg_val
  | simple_param_list COMMA keyword_val_list COMMA arg_val COMMA kwarg_val
  | keyword_val_list COMMA arg_val
  | keyword_val_list COMMA kwarg_val
  | keyword_val_list COMMA arg_val COMMA kwarg_val
  | arg_val COMMA kwarg_val
  ;

kwarg_val
  : STARS IDENTIFIER
  ;

arg_val
  : MUL_OP IDENTIFIER
  ;

keyword_val_list
  : keyword_val
  | keyword_val_list COMMA keyword_val
  ;

keyword_val
  : IDENTIFIER ASSIGN_OP expr
  | AT IDENTIFIER ASSIGN_OP expr
  ;

simple_param_list
  : simple_param
  | simple_param_list COMMA simple_param
  ;

simple_param
  : IDENTIFIER
  | AT IDENTIFIER
  ;

expr_list
  : expr
  | expr_list COMMA expr
  ;

expr
  : primary
  | unary_expr
  | additive_expr
  | multiplicative_expr
  | bitwise_expr
  | comparison_expr
  | logic_expr
  | range_expr
  | conditional_expr
  | pseudo_assign_expr
  | yield_expr
  | LPAREN unary_expr RPAREN
  | LPAREN additive_expr RPAREN
  | LPAREN multiplicative_expr RPAREN
  | LPAREN bitwise_expr RPAREN
  | LPAREN comparison_expr RPAREN
  | LPAREN logic_expr RPAREN
  | LPAREN range_expr RPAREN
  | LPAREN conditional_expr RPAREN
  | LPAREN pseudo_assign_expr RPAREN
  | LPAREN yield_expr RPAREN
  ;

yield_expr
  : YIELD
  | YIELD LPAREN expr_list RPAREN
  ;

pseudo_assign_expr
  : expr ASSIGN_PLUS expr
  | expr ASSIGN_MINUS expr
  | expr ASSIGN_MUL expr
  | expr ASSIGN_DIV expr
  | expr ASSIGN_MOD expr
  | expr ASSIGN_BITWISE_AND expr
  | expr ASSIGN_BITWISE_OR expr
  | expr ASSIGN_BITWISE_XOR expr
  | expr ASSIGN_SHIFTLEFT expr
  | expr ASSIGN_SHIFTRIGHT expr
  ;

conditional_expr
  : IF expr THEN expr ELSE expr
  ;

range_expr
  : expr ELLIPSIS expr
  | expr ELLIPSIS_SHORT expr
  ;

logic_expr
  : expr AND expr
  | expr OR expr
  ;

comparison_expr
  : expr EQ_OP expr
  | expr NEQ_OP expr
  | expr IS expr
  | expr LESS_OP expr
  | expr GREATER_OP expr
  | expr LEQ_OP expr
  | expr GEQ_OP expr
  ;

bitwise_expr
  : expr BITWISE_AND expr
  | expr BITWISE_OR expr
  | expr BITWISE_XOR expr
  | expr BITWISE_SHIFTLEFT expr
  | expr BITWISE_SHIFTRIGHT expr
  ;

multiplicative_expr
  : expr MUL_OP expr
  | expr DIV_OP expr
  | expr MOD_OP expr
  ;

additive_expr
  : expr PLUS_OP expr
  | expr MINUS_OP expr
  ;

unary_expr
  : MINUS_OP expr %prec UMINUS
  | NOT expr
  | BITWISE_NOT expr
  ;

name
  : IDENTIFIER
  | name DOT IDENTIFIER
  ;

target_list
  : IDENTIFIER target_tail
  ;

target_tail
  : COMMA IDENTIFIER target_tail
  |
  ;

primary
  : IDENTIFIER
  | literal
  | slicing
  | call
  | attribute_ref
  | list_form
  | dict_form
  | SELF
  ;

slicing
  : primary LBRACKET slice_item RBRACKET
  ;

slice_item
  : COLON
  | expr
  | expr COLON expr
  | expr COLON expr COLON expr
  | expr COLON expr COLON
  | expr COLON COLON
  | COLON expr COLON expr
  | COLON expr COLON
  | COLON COLON
  ;

attribute_ref
  : primary DOT IDENTIFIER
  ;

call
  : primary LPAREN RPAREN
  | primary LPAREN arg_list RPAREN
  | primary LPAREN RPAREN ASYNC
  | primary LPAREN arg_list RPAREN ASYNC
  ;

literal
  : integer
  | FLOAT
  | string
  ;

string
  : STRING_LITERAL_SINGLE
  | STRING_LITERAL_DOUBLE
  ;

integer
  : DECIMALINTEGER
  | BININTEGER
  | OCTINTEGER
  | HEXINTEGER
  ;

%%


int yyerror(char *err) {
  if(err) {
    fprintf(stderr, "Parsing erorr(%s) %s [line %d]\n", err, __FILE__, __LINE__);
  }
}

/* Return 1 stops at EOF,
 * return 0 continues reading. 
 */
int yywrap() {
  return 1;
}
