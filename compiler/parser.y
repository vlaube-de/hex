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

/*
The sky is your limit...
越过了这一片海洋，我们就能自由飞翔
天空就在不远前方，你会找到你的梦想。。。

         .----.                                                  .'.
        |  /   '                                                 |  '
        |  |    '                                                '  :
        |  | HEX '             .-~~~-.               .-~-.        \ |
        |  |      '          .\\   .//'._+_________.'.'  /_________\|
        |  |___ ...'.__..--~~ .\\__//_.-     . . .' .'  /      :  |  `.
        |.-"  .'  /                          . .' .'   /.      :_.|__.'
       <    .'___/                           .' .'    /|.      : .'|\
        ~~--..                             .' .'     /_|.      : | | \
          /_.' ~~--..__             .----.'_.'      /. . . . . . | |  |
                      ~~--.._______'.__.'  .'      /____________.' :  /
                               .'   .''.._'______.'                '-'
                               '---'
*/

%{

#include <stdio.h>
#include "yacc_extern.h"
#include "ast/ast.h"

#define YYDEBUG 1
#define YYERROR_VERBOSE

%}

%union {
  char* string;
  class _HexAstIdentifier* hex_ast_identifier;
  class _HexAstIntegerLiteral* hex_ast_integer;
  class _HexAstStringLiteral* hex_ast_string;
  class _HexAstFloatLiteral* hex_ast_float;
  class _HexAstLiteral* hex_ast_literal;
  class _HexAstCall* hex_ast_call;
  class _HexAstAttributeRef* hex_ast_attribute_ref;
  class _HexAstSlicing* hex_ast_slicing;
  class _HexAstPrimary* hex_ast_primary;
  class _HexAstTargetList* hex_ast_target_list;
  class _HexAstName* hex_ast_name;
  class _HexAstUnaryExpr* hex_ast_unary_expr;
  class _HexAstBinaryExpr* hex_ast_binary_expr;
  class _HexAstConditionalExpr* hex_ast_conditional_expr;
  class _HexAstRangeExpr* hex_ast_range_expr;
  class _HexAstYieldExpr* hex_ast_yield_expr;
  class _HexAstStringExpr* hex_ast_string_expr;
  class _HexAstParenForm* hex_ast_paren_form;
  class _HexAstExpr* hex_ast_expr;
  class _HexAstExprList* hex_ast_expr_list;
  class _HexAstSimpleParamList* hex_ast_simple_param_list;
  class _HexAstKeywordVal* hex_ast_keyword_val;
  class _HexAstKeywordValList* hex_ast_keyword_val_list;
  class _HexAstParameterList* hex_ast_parameter_list;
  class _HexAstValList* hex_ast_val_list;
  class _HexAstValAtom* hex_ast_val_atom;
  class _HexAstArgList* hex_ast_arg_list;
  class _HexAstComprehension* hex_ast_comprehension;
  class _HexAstListForm* hex_ast_list_form;
  class _HexAstFieldDef* hex_ast_field_def;
  class _HexAstMapField* hex_ast_map_field;
  class _HexAstMapFieldList* hex_ast_map_field_list;
  class _HexAstMapForm* hex_ast_map_form;
  class _HexAstFieldDefList* hex_ast_field_def_list;
  class _HexAstDictForm* hex_ast_dict_form;
  class _HexAstDecorator* hex_ast_decorator;
  class _HexAstDecoratorList* hex_ast_decorator_list;
  class _HexAstOperator* hex_ast_operator;
  class _HexAstOperatorDef* hex_ast_operator_def;
  class _HexAstAttributeDef* hex_ast_attribute_def;
  class _HexAstAttributeDefList* hex_ast_attribute_def_list;
  class _HexAstAssignmentStmt* hex_ast_assignment_stmt;
  class _HexAstUsingSrc* hex_ast_using_src;
  class _HexAstUsingStmt* hex_ast_using_stmt;
  class _HexAstElifStmt* hex_ast_elif_stmt;
  class _HexAstElifStmtGroup* hex_ast_elif_group;
  class _HexAstElseStmt* hex_ast_else_stmt;
  class _HexAstIfStmt* hex_ast_if_stmt;
  class _HexAstForStmt* hex_ast_for_stmt;
  class _HexAstWithStmt* hex_ast_with_stmt;
  class _HexAstLockStmt* hex_ast_lock_stmt;
  class _HexAstWhileStmt* hex_ast_while_stmt;
  class _HexAstCatchStmt* hex_ast_catch_stmt;
  class _HexAstCatchStmtGroup* hex_ast_catch_stmt_group;
  class _HexAstTryStmt* hex_ast_try_stmt;
  class _HexAstClassDef* hex_ast_class_def;
  class _HexAstLambda* hex_ast_lambda;
  class _HexAstInputStmt* hex_ast_input_stmt;
  class _HexAstOutputStmt* hex_ast_output_stmt;
  class _HexAstTaskState* hex_ast_task_state;
  class _HexAstConditionalPreposition* hex_ast_conditional_preposition;
  class _HexAstConditionalClause* hex_ast_conditional_clause;
  class _HexAstStartClause* hex_ast_start_clause;
  class _HexAstPauseClause* hex_ast_pause_clause;
  class _HexAstResumeClause* hex_ast_resume_clause;
  class _HexAstCancelClause* hex_ast_cancel_clause;
  class _HexAstDelayClause* hex_ast_delay_clause;
  class _HexAstStopClause* hex_ast_stop_clause;
  class _HexAstTaskClause* hex_ast_task_clause;
  class _HexAstTaskDef* hex_ast_task_def;
  class _HexAstAwaitStmt* hex_ast_await_stmt;
  class _HexAstCompoundStmt* hex_ast_compound_stmt;
  class _HexAstReturnStmt* hex_ast_return_stmt;
  class _HexAstBreakStmt* hex_ast_break_stmt;
  class _HexAstContinueStmt* hex_ast_continue_stmt;
  class _HexAstRaiseStmt* hex_ast_raise_stmt;
  class _HexAstExprListStmt* hex_ast_expr_list_stmt;
  class _HexAstSimpleStmt* hex_ast_simple_stmt;
  class _HexAstStmt* hex_ast_stmt;
  class _HexAstStmtGroup* hex_ast_stmt_group;
  class _HexAstHexProgram* hex_ast_hex_program;
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
%token <string> IS_NOT
%token <string> LOCK
%token <string> NOT
%token <string> OPERATOR
%token <string> OR
%token <string> PAUSE
%token <string> RAISE
%token <string> RESUME
%token <string> RETURN
%token <string> START
%token <string> STOP
%token <string> THEN
%token <string> TRY
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
%token <string> EXISTENTIAL_OP
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
%token <string> STRING_OP

/***********************************************************************************************************
 *
 * |-------------------------------------------------------------------------------------------------------|
 * |                   HEX expression precedence (precedence decreases as list goes down)                  |
 * |-------------------------------------------------------------------------------------------------------|
 * | Description                                       |    Operator                                       |
 * |---------------------------------------------------|---------------------------------------------------|
 * | identifiers, literals, tuples, list, dict         |     (), [], {}                                    |
 * | subscription, slicing, call, attribute reference  |                                                   |
 * | exponentiation                                    |     **                                            |
 * | positive, negative expression                     |     +, -                                          |
 * | bitwise not                                       |     ~                                             |
 * | increment, decrement                              |     ++, --                                        |
 * | existential                                       |     ?                                             |
 * | string composition                                |     %%                                            |
 * | multiplicative expression                         |     *, /, %                                       |
 * | additive expression                               |     +, -                                          |
 * | bitwise shift                                     |     <<, >>                                        |
 * | bitwise AND                                       |     &                                             |
 * | bitwise XOR                                       |     ^                                             |
 * | bitwise OR                                        |     |                                             |
 * | equality comparison                               |     ==, !=, is, is not, in, not in, >, <, >=, <=  |
 * | logical NOT                                       |     not                                           |
 * | logical AND                                       |     and                                           |
 * | logical OR                                        |     or                                            |
 * | range expression                                  |     ...                                           |
 * | conditional expression                            |     if else then                                  |
 * | input & output expression                         |     <<<, >>>                                      |
 * | assignment, pseudo assignment                     |     =, +=, -=, *=, /=, %=, &=, ^=, |=, <<=, >>=   |
 * |________________________________________________________________________________________________________
 *
 **********************************************************************************************************/

%left     COMMA
%right    ASSIGN_OP ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MUL ASSIGN_DIV ASSIGN_MOD 
          ASSIGN_BITWISE_AND ASSIGN_BITWISE_OR ASSIGN_BITWISE_XOR ASSIGN_SHIFTLEFT ASSIGN_SHIFTRIGHT
%left     INPUT_OP OUTPUT_OP
%right    IF THEN ELSE
%left     ELLIPSIS ELLIPSIS_SHORT
%left     OR
%left     AND
%right    NOT
%left     EQ_OP NEQ_OP IS IS_NOT IN GREATER_OP LESS_OP GEQ_OP LEQ_OP
%left     BITWISE_OR
%left     BITWISE_XOR
%left     BITWISE_AND
%left     BITWISE_SHIFTLEFT BITWISE_SHIFTRIGHT
%left     PLUS_OP MINUS_OP
%left     MUL_OP DIV_OP MOD_OP
%left     STRING_OP
%left     EXISTENTIAL_OP
%right    BITWISE_NOT
%nonassoc DEC_OP INC_OP
%nonassoc UPLUS UMINUS
%left     STARS
%left     IDENTIFIER STRING_LITERAL_SINGLE STRING_LITERAL_DOUBLE
          DECIMALINTEGER BININTEGER OCTINTEGER HEXINTEGER FLOAT
          LBRACKET RBRACKET LPAREN RPAREN LBRACE RBRACE


%type <hex_ast_integer> integer
%type <hex_ast_string> string
%type <hex_ast_literal> literal
%type <hex_ast_call> call
%type <hex_ast_attribute_ref> attribute_ref
%type <hex_ast_slicing> slicing
%type <hex_ast_identifier> identifier
%type <hex_ast_primary> primary
%type <hex_ast_target_list> target_tail
%type <hex_ast_target_list> target_list
%type <hex_ast_name> name
%type <hex_ast_unary_expr> unary_expr
%type <hex_ast_binary_expr> additive_expr
%type <hex_ast_binary_expr> multiplicative_expr
%type <hex_ast_binary_expr> power_expr
%type <hex_ast_binary_expr> bitwise_expr
%type <hex_ast_binary_expr> comparison_expr
%type <hex_ast_binary_expr> logic_expr
%type <hex_ast_range_expr> range_expr
%type <hex_ast_conditional_expr> conditional_expr
%type <hex_ast_binary_expr> pseudo_assign_expr
%type <hex_ast_yield_expr> yield_expr
%type <hex_ast_string_expr> string_expr
%type <hex_ast_paren_form> paren_form
%type <hex_ast_expr> expr
%type <hex_ast_expr_list> expr_list
%type <hex_ast_simple_param_list> simple_param_list
%type <hex_ast_keyword_val> keyword_val
%type <hex_ast_keyword_val_list> keyword_val_list
%type <hex_ast_identifier> arg_val
%type <hex_ast_identifier> kwarg_val
%type <hex_ast_parameter_list> parameter_list
%type <hex_ast_val_list> val_list
%type <hex_ast_val_atom> val_atom
%type <hex_ast_arg_list> arg_list
%type <hex_ast_comprehension> comprehension
%type <hex_ast_list_form> list_form
%type <hex_ast_field_def> field_def
%type <hex_ast_map_field> map_field
%type <hex_ast_map_field_list> map_field_list
%type <hex_ast_map_form> map_form
%type <hex_ast_field_def_list> field_def_list
%type <hex_ast_dict_form> dict_form
%type <hex_ast_decorator> decorator
%type <hex_ast_decorator_list> decorator_list
%type <hex_ast_operator> operator
%type <hex_ast_operator_def> operator_def
%type <hex_ast_attribute_def> attribute_def
%type <hex_ast_attribute_def_list> attribute_def_list
%type <hex_ast_assignment_stmt> assignment_stmt
%type <hex_ast_using_src> using_src
%type <hex_ast_using_stmt> using_stmt
%type <hex_ast_elif_stmt> elif_stmt
%type <hex_ast_elif_group> elif_group
%type <hex_ast_else_stmt> else_stmt
%type <hex_ast_if_stmt> if_stmt
%type <hex_ast_for_stmt> for_stmt
%type <hex_ast_with_stmt> with_stmt
%type <hex_ast_lock_stmt> lock_stmt
%type <hex_ast_while_stmt> while_stmt
%type <hex_ast_catch_stmt> catch_stmt
%type <hex_ast_catch_stmt_group> catch_stmt_group
%type <hex_ast_try_stmt> try_stmt
%type <hex_ast_class_def> class_def
%type <hex_ast_lambda> lambda
%type <hex_ast_input_stmt> input_stmt_list
%type <hex_ast_input_stmt> input_stmt
%type <hex_ast_output_stmt> output_stmt_list
%type <hex_ast_output_stmt> output_stmt
%type <hex_ast_task_state> task_state
%type <hex_ast_conditional_preposition> conditional_preposition
%type <hex_ast_conditional_clause> conditional_clause
%type <hex_ast_start_clause> start_clause
%type <hex_ast_pause_clause> pause_clause
%type <hex_ast_resume_clause> resume_clause
%type <hex_ast_cancel_clause> cancel_clause
%type <hex_ast_delay_clause> delay_clause
%type <hex_ast_stop_clause> stop_clause
%type <hex_ast_task_clause> task_clause
%type <hex_ast_task_def> task_def
%type <hex_ast_await_stmt> await_stmt
%type <hex_ast_compound_stmt> compound_stmt
%type <hex_ast_return_stmt> return_stmt
%type <hex_ast_break_stmt> break_stmt
%type <hex_ast_continue_stmt> continue_stmt
%type <hex_ast_raise_stmt> raise_stmt
%type <hex_ast_expr_list_stmt> expr_list_stmt
%type <hex_ast_simple_stmt> simple_stmt
%type <hex_ast_stmt> stmt
%type <hex_ast_stmt_group> stmt_group
%type <hex_ast_hex_program> input

%error-verbose
%debug

%{

%}

%%

input
  : stmt_group                                  { $$ = _HexAstHexProgram::create($1); }
  |                                             { $$ = _HexAstHexProgram::create(NULL); }
  ;

stmt_group
  : stmt                                        { $$ = AstListObj<_HexAstStmtGroup, HexAstStmt>::create($1); }
  | stmt_group stmt                             { $$ = AstListObj<_HexAstStmtGroup, HexAstStmt>::expand($1, $2); }
  ;

stmt
  : compound_stmt                               { $$ = $1; }
  | simple_stmt                                 { $$ = $1; }
  ;

simple_stmt
  : expr_list_stmt                              { $$ = $1; }
  | assignment_stmt                             { $$ = $1; }
  | using_stmt                                  { $$ = $1; }
  | return_stmt                                 { $$ = $1; }
  | continue_stmt                               { $$ = $1; }
  | raise_stmt                                  { $$ = $1; }
  | break_stmt                                  { $$ = $1; }
  | input_stmt                                  { $$ = $1; }
  | output_stmt                                 { $$ = $1; }
  ;

expr_list_stmt
  : expr_list SEMICOLON                         { $$ = _HexAstExprListStmt::create($1); }
  ;

raise_stmt
  : RAISE expr SEMICOLON                        { $$ = _HexAstRaiseStmt::create($2); }
  ;

continue_stmt
  : CONTINUE SEMICOLON                          { $$ = _HexAstContinueStmt::create(NULL); }
  | CONTINUE IF expr SEMICOLON                  { $$ = _HexAstContinueStmt::create($3); }
  ;

break_stmt
  : BREAK SEMICOLON                             { $$ = _HexAstBreakStmt::create(NULL); }
  | BREAK IF expr SEMICOLON                     { $$ = _HexAstBreakStmt::create($3); }
  ;

return_stmt
  : RETURN SEMICOLON                            { $$ = _HexAstReturnStmt::create(NULL, NULL); }
  | RETURN expr_list SEMICOLON                  { $$ = _HexAstReturnStmt::create($2, NULL); }
  | RETURN IF expr SEMICOLON                    { $$ = _HexAstReturnStmt::create(NULL, $3); }
  | RETURN expr_list IF expr SEMICOLON          { $$ = _HexAstReturnStmt::create($2, $4); }
  ;

compound_stmt
  : if_stmt                                     { $$ = $1; }
  | while_stmt                                  { $$ = $1; }
  | with_stmt                                   { $$ = $1; }
  | lock_stmt                                   { $$ = $1; }
  | try_stmt                                    { $$ = $1; }
  | for_stmt                                    { $$ = $1; }
  | await_stmt                                  { $$ = $1; }
  | class_def                                   { $$ = $1; }
  ;

await_stmt
  : AWAIT LBRACE stmt_group RBRACE               { $$ = _HexAstAwaitStmt::create($3); }
  ;

task_def
  : task_clause                                 { $$ = AstListObj<_HexAstTaskDef, HexAstTaskClause>::create($1); }
  | task_def COMMA task_clause                  { $$ = AstListObj<_HexAstTaskDef, HexAstTaskClause>::expand($1, $3); }
  ;

task_clause
  : start_clause                                    { $$ = $1; }
  | pause_clause                                    { $$ = $1; }
  | stop_clause                                     { $$ = $1; }
  | cancel_clause                                   { $$ = $1; }
  | delay_clause                                    { $$ = $1; }
  | resume_clause                                   { $$ = $1; }
  ;

stop_clause
  : STOP expr_list conditional_clause                                     { $$ = _HexAstStopClause::create($2, $3); }
  ;

delay_clause
  : DELAY expr_list conditional_clause                                    { $$ = _HexAstConditionalDelayClause::create($2, $3); }
  | DELAY expr_list BY expr                                               { $$ = _HexAstFixedDelayClause::create($2, $4); }
  | DELAY BY expr                                                         { $$ = _HexAstFixedDelayClause::create(NULL, $3); }
  ;

cancel_clause
  : CANCEL expr_list conditional_clause                                   { $$ = _HexAstCancelClause::create($2, $3); }
  ;

resume_clause
  : RESUME expr_list conditional_clause                                   { $$ = _HexAstResumeClause::create($2, $3); }
  ;

pause_clause
  : PAUSE expr_list conditional_clause                                    { $$ = _HexAstPauseClause::create($2, $3); }
  ;

start_clause
  : START name                                                            { $$ = _HexAstStartClauseSingle::create($2, NULL, NULL); }
  | START LPAREN target_list RPAREN                                       { $$ = _HexAstStartClauseMultiple::create($3, NULL, NULL); }
  | START LPAREN target_list RPAREN AS identifier                         { $$ = _HexAstStartClauseMultiple::create($3, $6, NULL); }
  | START name conditional_clause                                         { $$ = _HexAstStartClauseSingle::create($2, NULL, $3); }
  | START name AS identifier conditional_clause                           { $$ = _HexAstStartClauseSingle::create($2, $4, $5); }
  | START LPAREN target_list RPAREN conditional_clause                    { $$ = _HexAstStartClauseMultiple::create($3, NULL, $5); }
  | START LPAREN target_list RPAREN AS identifier conditional_clause      { $$ = _HexAstStartClauseMultiple::create($3, $6, $7); }
  ;

conditional_clause
  : conditional_preposition expr_list task_state                          { $$ = _HexAstConditionalClause::create($1, $2, $3); }
  ;

conditional_preposition
  : BEFORE                                                       { $$ = _HexAstConditionalPreposition::create(AST_TASK_CONDITIONAL_PREPOSITION_BEFORE); }
  | AFTER                                                        { $$ = _HexAstConditionalPreposition::create(AST_TASK_CONDITIONAL_PREPOSITION_AFTER); }
  | WHEN                                                         { $$ = _HexAstConditionalPreposition::create(AST_TASK_CONDITIONAL_PREPOSITION_WHEN); }
  ;

task_state
  : START                                                                 { $$ = _HexAstTaskState::create(AST_TASK_STATE_START); }
  | PAUSE                                                                 { $$ = _HexAstTaskState::create(AST_TASK_STATE_PAUSE); }
  | CANCEL                                                                { $$ = _HexAstTaskState::create(AST_TASK_STATE_CANCEL); }
  | RESUME                                                                { $$ = _HexAstTaskState::create(AST_TASK_STATE_RESUME); }
  | FINISH                                                                { $$ = _HexAstTaskState::create(AST_TASK_STATE_FINISH); }
  | STOP                                                                  { $$ = _HexAstTaskState::create(AST_TASK_STATE_STOP); }
  ;

output_stmt
  : output_stmt_list SEMICOLON                                      { $$ = $1; }
  ;

output_stmt_list
  : primary OUTPUT_OP primary                                       { $$ = AstListObj<_HexAstOutputStmt, HexAstPrimary>::create($1, $3); }
  | output_stmt_list OUTPUT_OP primary                              { $$ = AstListObj<_HexAstOutputStmt, HexAstPrimary>::expand($1, $3); }
  ;

input_stmt
  : input_stmt_list SEMICOLON                                       { $$ = $1; }
  ;

input_stmt_list
  : primary INPUT_OP primary                                        { $$ = AstListObj<_HexAstInputStmt, HexAstPrimary>::create($1, $3); } 
  | input_stmt_list INPUT_OP primary                                { $$ = AstListObj<_HexAstInputStmt, HexAstPrimary>::expand($1, $3); }
  ;

lambda
  : LPAREN parameter_list RPAREN ARROW LBRACE stmt_group RBRACE                       { $$ = _HexAstLambdaComplex::create($2, $6); }
  | LPAREN RPAREN ARROW LBRACE stmt_group RBRACE                                      { $$ = _HexAstLambdaComplex::create(NULL, $5); }
  | LPAREN parameter_list RPAREN LAMBDA_OP expr                                       { $$ = _HexAstLambdaSimple::create($2, $5); }
  | LPAREN RPAREN LAMBDA_OP expr                                                      { $$ = _HexAstLambdaSimple::create(NULL, $4); }
  | LPAREN parameter_list RPAREN ARROW LBRACE RBRACE                                  { $$ = _HexAstLambdaComplex::create($2, NULL); }
  | LPAREN RPAREN ARROW LBRACE RBRACE                                                 { $$ = _HexAstLambdaComplex::create(NULL, NULL); }
  ;

class_def
  : CLASS identifier SEMICOLON                                                        { $$ = _HexAstClassDef::create(NULL, $2, NULL, NULL); }
  | CLASS identifier EXTENDS name SEMICOLON                                           { $$ = _HexAstClassDef::create(NULL, $2, $4, NULL); }
  | CLASS identifier LBRACE attribute_def_list RBRACE                                 { $$ = _HexAstClassDef::create(NULL, $2, NULL, $4); }
  | CLASS identifier EXTENDS name LBRACE attribute_def_list RBRACE                    { $$ = _HexAstClassDef::create(NULL, $2, $4, $6); }
  | decorator_list CLASS identifier LBRACE attribute_def_list RBRACE                  { $$ = _HexAstClassDef::create($1, $3, NULL, $5); }
  | decorator_list CLASS identifier EXTENDS name LBRACE attribute_def_list RBRACE     { $$ = _HexAstClassDef::create($1, $3, $5, $7); }
  | decorator_list CLASS identifier LBRACE RBRACE                                     { $$ = _HexAstClassDef::create($1, $3, NULL, NULL); }
  | decorator_list CLASS identifier EXTENDS name LBRACE RBRACE                        { $$ = _HexAstClassDef::create($1, $3, $5, NULL); }
  ;

try_stmt
  : TRY LBRACE stmt_group RBRACE catch_stmt_group                     { $$ = _HexAstTryStmt::create($3, $5); }
  ;

catch_stmt_group
  : catch_stmt                                                        { $$ = AstListObj<_HexAstCatchStmtGroup, HexAstCatchStmt>::create($1); }
  | catch_stmt_group catch_stmt                                       { $$ = AstListObj<_HexAstCatchStmtGroup, HexAstCatchStmt>::expand($1, $2); }
  ;

catch_stmt
  : CATCH LBRACE stmt_group RBRACE                                    { $$ = _HexAstCatchStmt::create(NULL, NULL, $3); }
  | CATCH target_list LBRACE stmt_group RBRACE                        { $$ = _HexAstCatchStmt::create($2, NULL, $4); }
  | CATCH target_list AS identifier LBRACE stmt_group RBRACE          { $$ = _HexAstCatchStmt::create($2, $4, $6); }
  ;

while_stmt
  : WHILE expr LBRACE stmt_group RBRACE                               { $$ = _HexAstWhileStmt::create($2, $4); }
  ;

lock_stmt
  : LOCK expr_list LBRACE stmt_group RBRACE                           { $$ = _HexAstLockStmt::create($2, $4); }
  ;

with_stmt
  : WITH expr_list LBRACE stmt_group RBRACE                           { $$ = _HexAstWithStmt::create($2, NULL, $4); }
  | WITH expr_list AS identifier LBRACE stmt_group RBRACE             { $$ = _HexAstWithStmt::create($2, $4, $6); }
  ;

for_stmt
  : FOR target_list IN expr_list LBRACE stmt_group RBRACE             { $$ = _HexAstForStmt::create($2, $4, NULL, $6); }
  | FOR target_list IN expr_list WHERE expr LBRACE stmt_group RBRACE  { $$ = _HexAstForStmt::create($2, $4, $6, $8); }
  ;

if_stmt
  : IF expr LBRACE stmt_group RBRACE                        { $$ = _HexAstIfStmt::create($2, $4, NULL, NULL); }
  | IF expr LBRACE stmt_group RBRACE else_stmt              { $$ = _HexAstIfStmt::create($2, $4, NULL, $6); }
  | IF expr LBRACE stmt_group RBRACE elif_group             { $$ = _HexAstIfStmt::create($2, $4, $6, NULL); }
  | IF expr LBRACE stmt_group RBRACE elif_group else_stmt   { $$ = _HexAstIfStmt::create($2, $4, $6, $7); }
  ;

else_stmt
  : ELSE LBRACE stmt_group RBRACE                           { $$ = _HexAstElseStmt::create($3); }
  ;

elif_group
  : elif_stmt                                               { $$ = AstListObj<_HexAstElifStmtGroup, HexAstElifStmt>::create($1); }
  | elif_group elif_stmt                                    { $$ = AstListObj<_HexAstElifStmtGroup, HexAstElifStmt>::expand($1, $2); }
  ;

elif_stmt                              
  : ELIF expr LBRACE stmt_group RBRACE                      { $$ = _HexAstElifStmt::create($2, $4); }
  ;

using_stmt
  : USING name SEMICOLON                                    { $$ = _HexAstUsingStmtDirect::create($2, NULL); }
  | USING name AS identifier SEMICOLON                      { $$ = _HexAstUsingStmtDirect::create($2, $4); }
  | USING target_list IN using_src SEMICOLON                { $$ = _HexAstUsingStmtRelative::create($2, $4, NULL, AST_USING_STMT_RELATIVE_TARGET); }
  | USING target_list IN using_src AS identifier SEMICOLON  { $$ = _HexAstUsingStmtRelative::create($2, $4, $6, AST_USING_STMT_RELATIVE_TARGET); }
  | USING MUL_OP IN using_src SEMICOLON                     { $$ = _HexAstUsingStmtRelative::create(NULL, $4, NULL, AST_USING_STMT_RELATIVE_ALL); }
  ;

using_src
  : name                                                  { $$ = _HexAstUsingSrc::create($1, AST_USING_SRC_NAME); }
  | DOT                                                   { $$ = _HexAstUsingSrc::create(NULL, AST_USING_SRC_DOT); }
  ;

assignment_stmt
  : primary ASSIGN_OP expr_list SEMICOLON                 { $$ = _HexAstAssignmentStmt::create(NULL, $1, $3, AST_ASSIGNMENT_STMT_EXPR_LIST, false); }
  | primary ASSIGN_OP DEFER expr_list SEMICOLON           { $$ = _HexAstAssignmentStmt::create(NULL, $1, $4, AST_ASSIGNMENT_STMT_EXPR_LIST, true); }
  | primary ASSIGN_OP lambda SEMICOLON                    { $$ = _HexAstAssignmentStmt::create(NULL, $1, $3, AST_ASSIGNMENT_STMT_LAMBDA, false); }
  | decorator_list primary ASSIGN_OP lambda SEMICOLON     { $$ = _HexAstAssignmentStmt::create($1, $2, $4, AST_ASSIGNMENT_STMT_LAMBDA, false); }
  | primary ASSIGN_OP task_def SEMICOLON                  { $$ = _HexAstAssignmentStmt::create(NULL, $1, $3, AST_ASSIGNMENT_STMT_TASK, false); }
  ;

attribute_def_list
  : attribute_def                             { $$ = AstListObj<_HexAstAttributeDefList, HexAstAttributeDef>::create($1); }
  | attribute_def_list attribute_def          { $$ = AstListObj<_HexAstAttributeDefList, HexAstAttributeDef>::expand($1, $2); }
  ;

attribute_def
  : field_def                                 { $$ = $1; }
  | operator_def                              { $$ = $1; } 
  ;

operator_def
  : operator COLON lambda                     { $$ = _HexAstOperatorDef::create($1, $3); }
  ;

operator
  : OPERATOR PLUS_OP                          { $$ = _HexAstOperator::create(AST_OPERATOR_PLUS); }
  | OPERATOR MINUS_OP                         { $$ = _HexAstOperator::create(AST_OPERATOR_MINUS); }
  | OPERATOR MUL_OP                           { $$ = _HexAstOperator::create(AST_OPERATOR_MUL); }
  | OPERATOR DIV_OP                           { $$ = _HexAstOperator::create(AST_OPERATOR_DIV); }
  | OPERATOR MOD_OP                           { $$ = _HexAstOperator::create(AST_OPERATOR_MOD); }
  | OPERATOR BITWISE_NOT                      { $$ = _HexAstOperator::create(AST_OPERATOR_BITWISE_NOT); }
  | OPERATOR BITWISE_AND                      { $$ = _HexAstOperator::create(AST_OPERATOR_BITWISE_AND); }
  | OPERATOR BITWISE_OR                       { $$ = _HexAstOperator::create(AST_OPERATOR_BITWISE_OR); }
  | OPERATOR BITWISE_XOR                      { $$ = _HexAstOperator::create(AST_OPERATOR_BITWISE_XOR); }
  | OPERATOR BITWISE_SHIFTLEFT                { $$ = _HexAstOperator::create(AST_OPERATOR_BITWISE_SHIFTLEFT); }
  | OPERATOR BITWISE_SHIFTRIGHT               { $$ = _HexAstOperator::create(AST_OPERATOR_BITWISE_SHIFTRIGHT); }
  | OPERATOR EQ_OP                            { $$ = _HexAstOperator::create(AST_OPERATOR_EQ); }
  | OPERATOR NEQ_OP                           { $$ = _HexAstOperator::create(AST_OPERATOR_NEQ); }
  | OPERATOR GREATER_OP                       { $$ = _HexAstOperator::create(AST_OPERATOR_GT); }
  | OPERATOR LESS_OP                          { $$ = _HexAstOperator::create(AST_OPERATOR_LT); }
  | OPERATOR GEQ_OP                           { $$ = _HexAstOperator::create(AST_OPERATOR_GEQ); }
  | OPERATOR LEQ_OP                           { $$ = _HexAstOperator::create(AST_OPERATOR_LEQ); }
  | OPERATOR INC_OP                           { $$ = _HexAstOperator::create(AST_OPERATOR_INC); }
  | OPERATOR DEC_OP                           { $$ = _HexAstOperator::create(AST_OPERATOR_DEC); }
  | OPERATOR ASSIGN_OP                        { $$ = _HexAstOperator::create(AST_OPERATOR_ASSIGN_OP); }
  | OPERATOR ASSIGN_PLUS                      { $$ = _HexAstOperator::create(AST_OPERATOR_ASSIGN_PLUS); }
  | OPERATOR ASSIGN_MINUS                     { $$ = _HexAstOperator::create(AST_OPERATOR_ASSIGN_MINUS); }
  | OPERATOR ASSIGN_MUL                       { $$ = _HexAstOperator::create(AST_OPERATOR_ASSIGN_MUL); }
  | OPERATOR ASSIGN_DIV                       { $$ = _HexAstOperator::create(AST_OPERATOR_ASSIGN_DIV); }
  | OPERATOR ASSIGN_MOD                       { $$ = _HexAstOperator::create(AST_OPERATOR_ASSIGN_MOD); }
  | OPERATOR ASSIGN_BITWISE_AND               { $$ = _HexAstOperator::create(AST_OPERATOR_ASSIGN_BITWISE_AND); }
  | OPERATOR ASSIGN_BITWISE_OR                { $$ = _HexAstOperator::create(AST_OPERATOR_ASSIGN_BITWISE_OR); }
  | OPERATOR ASSIGN_BITWISE_XOR               { $$ = _HexAstOperator::create(AST_OPERATOR_ASSIGN_BITWISE_XOR); }
  | OPERATOR ASSIGN_SHIFTLEFT                 { $$ = _HexAstOperator::create(AST_OPERATOR_ASSIGN_SHIFTLEFT); }
  | OPERATOR ASSIGN_SHIFTRIGHT                { $$ = _HexAstOperator::create(AST_OPERATOR_ASSIGN_SHIFTRIGHT); }
  | OPERATOR INPUT_OP                         { $$ = _HexAstOperator::create(AST_OPERATOR_INPUT); }
  | OPERATOR OUTPUT_OP                        { $$ = _HexAstOperator::create(AST_OPERATOR_OUTPUT); }
  ;

decorator_list
  : decorator                                   { $$ = AstListObj<_HexAstDecoratorList, HexAstDecorator>::create($1); }
  | decorator_list decorator                    { $$ = AstListObj<_HexAstDecoratorList, HexAstDecorator>::expand($1, $2); }
  ;

decorator
  : AT name                                     { $$ = _HexAstDecorator::create($2, NULL); }
  | AT name LPAREN arg_list RPAREN              { $$ = _HexAstDecorator::create($2, $4); }
  ;

dict_form
  : LBRACE RBRACE                               { $$ = _HexAstDictForm::create(NULL, AST_DICT_FORM_EMPTY); }
  | LBRACE field_def_list RBRACE                { $$ = _HexAstDictForm::create($2, AST_DICT_FORM_EXPLICIT); }
  | LBRACE comprehension RBRACE                 { $$ = _HexAstDictForm::create($2, AST_DICT_FORM_COMPREHENSION); }
  ;

field_def_list
  : field_def                                   { $$ = AstListObj<_HexAstFieldDefList, HexAstFieldDef>::create($1); } 
  | field_def_list COMMA field_def              { $$ = AstListObj<_HexAstFieldDefList, HexAstFieldDef>::expand($1, $3); }
  ;

map_form
  : LBRACE map_field_list RBRACE                { $$ = _HexAstMapForm::create($2); }
  ;

map_field_list
  : map_field                                   { $$ = AstListObj<_HexAstMapFieldList, HexAstMapField>::create($1); }
  | map_field_list COMMA map_field              { $$ = AstListObj<_HexAstMapFieldList, HexAstMapField>::expand($1, $3); }
  ;

map_field
  : expr ARROW val_atom                         { $$ = _HexAstMapField::create($1, $3); }
  ;

field_def
  : identifier COLON val_atom                   { $$ = _HexAstFieldDef::create(NULL, $1, $3); }
  | decorator_list identifier COLON val_atom    { $$ = _HexAstFieldDef::create($1, $2, $4); }
  ;

list_form
  : LBRACKET RBRACKET                           { $$ = _HexAstListForm::create(NULL, AST_LIST_FORM_EMPTY); }
  | LBRACKET expr_list RBRACKET                 { $$ = _HexAstListForm::create($2, AST_LIST_FORM_EXPR_LIST); }
  | LBRACKET comprehension RBRACKET             { $$ = _HexAstListForm::create($2, AST_LIST_FORM_COMPREHENSION); }
  ;

comprehension
  : FOR target_list IN expr_list                      { $$ = _HexAstComprehension::create(NULL, $2, $4, NULL); }
  | FOR target_list IN expr_list IF expr              { $$ = _HexAstComprehension::create(NULL, $2, $4, $6); }
  | expr_list FOR target_list IN expr_list            { $$ = _HexAstComprehension::create($1, $3, $5, NULL); }
  | expr_list FOR target_list IN expr_list IF expr    { $$ = _HexAstComprehension::create($1, $3, $5, $7); }
  ;

arg_list
  : val_list                                                        { $$ = _HexAstArgList::create($1, NULL, NULL, NULL); }
  | keyword_val_list                                                { $$ = _HexAstArgList::create(NULL, $1, NULL, NULL); }
  | arg_val                                                         { $$ = _HexAstArgList::create(NULL, NULL, $1, NULL); }
  | kwarg_val                                                       { $$ = _HexAstArgList::create(NULL, NULL, NULL, $1); }
  | val_list COMMA keyword_val_list                                 { $$ = _HexAstArgList::create($1, $3, NULL, NULL); }
  | val_list COMMA arg_val                                          { $$ = _HexAstArgList::create($1, NULL, $3, NULL); }
  | val_list COMMA kwarg_val                                        { $$ = _HexAstArgList::create($1, NULL, NULL, $3); }
  | val_list COMMA arg_val COMMA kwarg_val                          { $$ = _HexAstArgList::create($1, NULL, $3, $5); }
  | val_list COMMA keyword_val_list COMMA arg_val                   { $$ = _HexAstArgList::create($1, $3, $5, NULL); }
  | val_list COMMA keyword_val_list COMMA kwarg_val                 { $$ = _HexAstArgList::create($1, $3, NULL, $5); }
  | val_list COMMA keyword_val_list COMMA arg_val COMMA kwarg_val   { $$ = _HexAstArgList::create($1, $3, $5, $7); }
  | keyword_val_list COMMA arg_val                                  { $$ = _HexAstArgList::create(NULL, $1, $3, NULL); }
  | keyword_val_list COMMA kwarg_val                                { $$ = _HexAstArgList::create(NULL, $1, NULL, $3); }
  | keyword_val_list COMMA arg_val COMMA kwarg_val                  { $$ = _HexAstArgList::create(NULL, $1, $3, $5); }
  | arg_val COMMA kwarg_val                                         { $$ = _HexAstArgList::create(NULL, NULL, $1, $3); }
  ;

val_atom
  : expr                                { $$ = _HexAstValAtom::create($1, AST_VAL_ATOM_EXPR); }
  | lambda                              { $$ = _HexAstValAtom::create($1, AST_VAL_ATOM_LAMBDA); }
  ;

val_list
  : val_atom                            { $$ = AstListObj<_HexAstValList, HexAstValAtom>::create($1); }
  | val_list COMMA val_atom             { $$ = AstListObj<_HexAstValList, HexAstValAtom>::expand($1, $3); }
  ;

parameter_list
  : simple_param_list                                                       { $$ = _HexAstParameterList::create($1, NULL, NULL, NULL); }
  | keyword_val_list                                                        { $$ = _HexAstParameterList::create(NULL, $1, NULL, NULL); }
  | arg_val                                                                 { $$ = _HexAstParameterList::create(NULL, NULL, $1, NULL); }
  | kwarg_val                                                               { $$ = _HexAstParameterList::create(NULL, NULL, NULL, $1); }
  | simple_param_list COMMA keyword_val_list                                { $$ = _HexAstParameterList::create($1, $3, NULL, NULL); }
  | simple_param_list COMMA arg_val                                         { $$ = _HexAstParameterList::create($1, NULL, $3, NULL); }
  | simple_param_list COMMA kwarg_val                                       { $$ = _HexAstParameterList::create($1, NULL, NULL, $3); }
  | simple_param_list COMMA arg_val COMMA kwarg_val                         { $$ = _HexAstParameterList::create($1, NULL, $3, $5); }
  | simple_param_list COMMA keyword_val_list COMMA arg_val                  { $$ = _HexAstParameterList::create($1, $3, $5, NULL); }
  | simple_param_list COMMA keyword_val_list COMMA kwarg_val                { $$ = _HexAstParameterList::create($1, $3, NULL, $5); }
  | simple_param_list COMMA keyword_val_list COMMA arg_val COMMA kwarg_val  { $$ = _HexAstParameterList::create($1, $3, $5, $7); }
  | keyword_val_list COMMA arg_val                                          { $$ = _HexAstParameterList::create(NULL, $1, $3, NULL); }
  | keyword_val_list COMMA kwarg_val                                        { $$ = _HexAstParameterList::create(NULL, $1, NULL, $3); }
  | keyword_val_list COMMA arg_val COMMA kwarg_val                          { $$ = _HexAstParameterList::create(NULL, $1, $3, $5); }
  | arg_val COMMA kwarg_val                                                 { $$ = _HexAstParameterList::create(NULL, NULL, $1, $3); }
  ;

kwarg_val
  : STARS identifier                      { $$ = $2; }
  ;

arg_val
  : MUL_OP identifier                     { $$ = $2; }
  ;

keyword_val_list
  : keyword_val                           { $$ = AstListObj<_HexAstKeywordValList, HexAstKeywordVal>::create($1); }
  | keyword_val_list COMMA keyword_val    { $$ = AstListObj<_HexAstKeywordValList, HexAstKeywordVal>::expand($1, $3); }
  ;

keyword_val
  : identifier ASSIGN_OP val_atom         { $$ = _HexAstKeywordVal::create($1, $3); }
  ;

simple_param_list
  : identifier                            { $$ = AstListObj<_HexAstSimpleParamList, HexAstIdentifier>::create($1); }
  | simple_param_list COMMA identifier    { $$ = AstListObj<_HexAstSimpleParamList, HexAstIdentifier>::expand($1, $3); }
  ;

expr_list
  : expr                                  { $$ = AstListObj<_HexAstExprList, HexAstExpr>::create($1); }
  | expr_list COMMA expr                  { $$ = AstListObj<_HexAstExprList, HexAstExpr>::expand($1, $3); }
  ;

expr
  : primary                               { $$ = $1; }
  | unary_expr                            { $$ = $1; }
  | additive_expr                         { $$ = $1; }
  | multiplicative_expr                   { $$ = $1; }
  | power_expr                            { $$ = $1; }
  | bitwise_expr                          { $$ = $1; }
  | comparison_expr                       { $$ = $1; }
  | logic_expr                            { $$ = $1; }
  | range_expr                            { $$ = $1; }
  | conditional_expr                      { $$ = $1; }
  | pseudo_assign_expr                    { $$ = $1; }
  | yield_expr                            { $$ = $1; }
  | string_expr                           { $$ = $1; }
  | paren_form                            { $$ = $1; }
  ;

paren_form
  : LPAREN RPAREN                         { $$ = _HexAstParenForm::create(NULL); }
  | LPAREN expr_list RPAREN               { $$ = _HexAstParenForm::create($2); }
  ;

string_expr
  : string STRING_OP LPAREN expr_list RPAREN  { $$ = _HexAstStringExpr::create($1, $4); }
  ;

yield_expr
  : YIELD                                 { $$ = _HexAstYieldExpr::create(NULL); }
  | YIELD LPAREN expr_list RPAREN         { $$ = _HexAstYieldExpr::create($3); }
  ;

pseudo_assign_expr
  : expr ASSIGN_PLUS expr                 { $$ = _HexAstBinaryExpr::create<_HexAstPseudoAssignPlusExpr>($1, $3); }
  | expr ASSIGN_MINUS expr                { $$ = _HexAstBinaryExpr::create<_HexAstPseudoAssignMinusExpr>($1, $3); }
  | expr ASSIGN_MUL expr                  { $$ = _HexAstBinaryExpr::create<_HexAstPseudoAssignMultiplyExpr>($1, $3); }
  | expr ASSIGN_DIV expr                  { $$ = _HexAstBinaryExpr::create<_HexAstPseudoAssignDivideExpr>($1, $3); }
  | expr ASSIGN_MOD expr                  { $$ = _HexAstBinaryExpr::create<_HexAstPseudoAssignModulusExpr>($1, $3); }
  | expr ASSIGN_BITWISE_AND expr          { $$ = _HexAstBinaryExpr::create<_HexAstPseudoAssignBitwiseAndExpr>($1, $3); }
  | expr ASSIGN_BITWISE_OR expr           { $$ = _HexAstBinaryExpr::create<_HexAstPseudoAssignBitwiseOrExpr>($1, $3); }
  | expr ASSIGN_BITWISE_XOR expr          { $$ = _HexAstBinaryExpr::create<_HexAstPseudoAssignBitwiseXorExpr>($1, $3); }
  | expr ASSIGN_SHIFTLEFT expr            { $$ = _HexAstBinaryExpr::create<_HexAstPseudoAssignBitwiseLeftShiftExpr>($1, $3); }
  | expr ASSIGN_SHIFTRIGHT expr           { $$ = _HexAstBinaryExpr::create<_HexAstPseudoAssignBitwiseRightShiftExpr>($1, $3); }
  ;

conditional_expr
  : IF expr THEN expr ELSE expr           { $$ = _HexAstConditionalExpr::create($2, $4, $6); }
  ;

range_expr
  : expr ELLIPSIS expr         { $$ = _HexAstInclusiveRangeExpr::create($1, $3); }
  | expr ELLIPSIS_SHORT expr   { $$ = _HexAstExclusiveRangeExpr::create($1, $3); }
  ;

logic_expr
  : expr AND expr                         { $$ = _HexAstBinaryExpr::create<_HexAstAndExpr>($1, $3); }
  | expr OR expr                          { $$ = _HexAstBinaryExpr::create<_HexAstOrExpr>($1, $3); }
  ;

comparison_expr
  : expr EQ_OP expr                       { $$ = _HexAstBinaryExpr::create<_HexAstEqualsExpr>($1, $3); }
  | expr NEQ_OP expr                      { $$ = _HexAstBinaryExpr::create<_HexAstNotEqualExpr>($1, $3); }
  | expr IS expr                          { $$ = _HexAstBinaryExpr::create<_HexAstIsExpr>($1, $3); }
  | expr IS_NOT expr                      { $$ = _HexAstBinaryExpr::create<_HexAstIsNotExpr>($1, $3); }
  | expr LESS_OP expr                     { $$ = _HexAstBinaryExpr::create<_HexAstLessThanExpr>($1, $3); }
  | expr GREATER_OP expr                  { $$ = _HexAstBinaryExpr::create<_HexAstGreaterThanExpr>($1, $3); }
  | expr LEQ_OP expr                      { $$ = _HexAstBinaryExpr::create<_HexAstLessOrEqualsExpr>($1, $3); }
  | expr GEQ_OP expr                      { $$ = _HexAstBinaryExpr::create<_HexAstGreaterOrEqualsExpr>($1, $3); }
  | expr IN expr                          { $$ = _HexAstBinaryExpr::create<_HexAstInExpr>($1, $3); }
  | expr NOT IN expr                      { $$ = _HexAstBinaryExpr::create<_HexAstNotInExpr>($1, $4); }
  ;

bitwise_expr
  : expr BITWISE_AND expr                 { $$ = _HexAstBinaryExpr::create<_HexAstBitwiseAndExpr>($1, $3); }
  | expr BITWISE_OR expr                  { $$ = _HexAstBinaryExpr::create<_HexAstBitwiseOrExpr>($1, $3); }
  | expr BITWISE_XOR expr                 { $$ = _HexAstBinaryExpr::create<_HexAstBitwiseXorExpr>($1, $3); }
  | expr BITWISE_SHIFTLEFT expr           { $$ = _HexAstBinaryExpr::create<_HexAstBitwiseShiftLeftExpr>($1, $3); }
  | expr BITWISE_SHIFTRIGHT expr          { $$ = _HexAstBinaryExpr::create<_HexAstBitwiseShiftRightExpr>($1, $3); }
  ;

power_expr
  : expr STARS expr                       { $$ = _HexAstBinaryExpr::create<_HexAstPowerExpr>($1, $3); }
  ;

multiplicative_expr
  : expr MUL_OP expr                      { $$ = _HexAstBinaryExpr::create<_HexAstMultiplyExpr>($1, $3); }
  | expr DIV_OP expr                      { $$ = _HexAstBinaryExpr::create<_HexAstDivideExpr>($1, $3); }
  | expr MOD_OP expr                      { $$ = _HexAstBinaryExpr::create<_HexAstModulusExpr>($1, $3); }
  ;

additive_expr
  : expr PLUS_OP expr                     { $$ = _HexAstBinaryExpr::create<_HexAstAddExpr>($1, $3); }
  | expr MINUS_OP expr                    { $$ = _HexAstBinaryExpr::create<_HexAstMinusExpr>($1, $3); }
  ;

unary_expr
  : PLUS_OP expr %prec UPLUS              { $$ = _HexAstUnaryExpr::create<_HexAstPositiveExpr>($2); }
  | MINUS_OP expr %prec UMINUS            { $$ = _HexAstUnaryExpr::create<_HexAstNegativeExpr>($2); }
  | NOT expr                              { $$ = _HexAstUnaryExpr::create<_HexAstNotExpr>($2); }
  | BITWISE_NOT expr                      { $$ = _HexAstUnaryExpr::create<_HexAstBitwiseNotExpr>($2); }
  | expr INC_OP                           { $$ = _HexAstUnaryExpr::create<_HexAstIncrementExpr>($1); }
  | expr DEC_OP                           { $$ = _HexAstUnaryExpr::create<_HexAstDecrementExpr>($1); }
  | expr EXISTENTIAL_OP                   { $$ = _HexAstUnaryExpr::create<_HexAstExistentialExpr>($1); }
  ;

name
  : identifier                            { $$ = AstListObj<_HexAstName, HexAstIdentifier>::create($1); }
  | name DOT identifier                   { $$ = AstListObj<_HexAstName, HexAstIdentifier>::expand($1, $3); }
  ;

target_list
  : identifier target_tail                { $$ = AstListObj<_HexAstTargetList, HexAstIdentifier>::create_or_expand($1, $2); }
  ;

target_tail
  : COMMA identifier target_tail          { $$ = AstListObj<_HexAstTargetList, HexAstIdentifier>::create_or_expand($2, $3); }
  |                                       { $$ = NULL; }
  ;

primary
  : identifier                            { $$ = $1; }
  | literal                               { $$ = $1; }
  | slicing                               { $$ = $1; }
  | call                                  { $$ = $1; }
  | attribute_ref                         { $$ = $1; }
  | list_form                             { $$ = $1; }
  | dict_form                             { $$ = $1; }
  | map_form                              { $$ = $1; }
  ;

identifier
  : IDENTIFIER                            { $$ = _HexAstIdentifier::create($1); }
  ;

slicing
  : primary LBRACKET expr RBRACKET        { $$ = _HexAstSlicing::create($1, $3); }
  ;

attribute_ref
  : primary DOT identifier                { $$ = _HexAstAttributeRef::create($1, $3); }
  ;

call
  : primary LPAREN RPAREN                 { $$ = _HexAstCall::create($1, NULL, false); }
  | primary LPAREN arg_list RPAREN        { $$ = _HexAstCall::create($1, $3, false); }
  | primary LPAREN RPAREN ASYNC           { $$ = _HexAstCall::create($1, NULL, true); }
  | primary LPAREN arg_list RPAREN ASYNC  { $$ = _HexAstCall::create($1, $3, true); }
  ;

literal
  : integer                               { $$ = $1; }
  | FLOAT                                 { $$ = _HexAstFloatLiteral::create($1); }
  | string                                { $$ = $1; }
  ;

string
  : STRING_LITERAL_SINGLE                 { $$ = _HexAstStringLiteral::create(AST_STRING_LITERAL_SINGLE_QUOTE, $1); }
  | STRING_LITERAL_DOUBLE                 { $$ = _HexAstStringLiteral::create(AST_STRING_LITERAL_DOUBLE_QUOTE, $1); }
  ;

integer
  : DECIMALINTEGER                        { $$ = _HexAstIntegerLiteral::create(AST_INTEGER_LITERAL_DECIMAL, $1); }
  | BININTEGER                            { $$ = _HexAstIntegerLiteral::create(AST_INTEGER_LITERAL_BINARY, $1); }
  | OCTINTEGER                            { $$ = _HexAstIntegerLiteral::create(AST_INTEGER_LITERAL_OCTAL, $1); }
  | HEXINTEGER                            { $$ = _HexAstIntegerLiteral::create(AST_INTEGER_LITERAL_HEXADECIMAL, $1); }
  ;

%%


int yyerror(const char *err) {
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
