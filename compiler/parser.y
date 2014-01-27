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

/**************************************************************************************************************************
 *
 * |-----------------------------------------------------------------------------------------------------------------------|
 * |                                     HEX expression precedences and associativities                                    |
 * |-----------------------------------------------------------------------------------------------------------------------|
 * | Precedence decreases as list goes down.                                                                               |
 * | LR: left-to-right associativity.                                                                                      |
 * | RL: right-to-left associativity.                                                                                      |
 * |-----------------------------------------------------------------------------------------------------|-----------------|
 * | Description                                       |  Operator                                       |  Associativity  |
 * |---------------------------------------------------|-------------------------------------------------|-----------------|
 * | identifiers, literals, tuples, list, dict         |  (), [], {}                                     |        LR       |
 * | subscription, slicing, call, attribute reference  |                                                 |        LR       |
 * | exponentiation                                    |   **                                            |        LR       |
 * | positive, negative expression, bitwise not        |   +, -, ~                                       |        RL       |
 * | increment, decrement                              |   ++, --                                        |        LR       |
 * | existential                                       |   ?                                             |        LR       |
 * | string composition                                |   %%                                            |        LR       |
 * | multiplicative expression                         |   *, /, %                                       |        LR       |
 * | additive expression                               |   +, -                                          |        LR       |
 * | bitwise shift                                     |   <<, >>                                        |        LR       |
 * | bitwise AND                                       |   &                                             |        LR       |
 * | bitwise XOR                                       |   ^                                             |        LR       |
 * | bitwise OR                                        |   |                                             |        LR       |
 * | equality comparison                               |   ==, !=, is, is not, in, not in, >, <, >=, <=  |        LR       |
 * | logical NOT                                       |   not                                           |        RL       |
 * | logical AND                                       |   and                                           |        LR       |
 * | logical OR                                        |   or                                            |        LR       |
 * | range expressions                                 |   .., ...                                       |        LR       |
 * | conditional expression                            |   if else then                                  |        LR       |
 * | input & output expression                         |   <<<, >>>                                      |        LR       |
 * | yield expression                                  |   yield                                         |        LR       |
 * | assignment, pseudo assignment                     |   =, +=, -=, *=, /=, %=, &=, ^=, |=, <<=, >>=   |        LR       |
 * |_____________________________________________________________________________________________________|_________________|
 *
 **************************************************************************************************************************/

%{

#include <stdio.h>
#include "yacc_extern.h"
#include "ast/ast.h"

#define YYDEBUG 1
#define YYERROR_VERBOSE

%}

%union {
  char* string;
  class _HexAstIdentifier                     * hex_ast_identifier;
  class _HexAstIntegerLiteral                 * hex_ast_integer;
  class _HexAstStringLiteral                  * hex_ast_string;
  class _HexAstFloatLiteral                   * hex_ast_float;
  class _HexAstLiteral                        * hex_ast_literal;
  class _HexAstCall                           * hex_ast_call;
  class _HexAstAttributeRef                   * hex_ast_attribute_ref;
  class _HexAstSlicing                        * hex_ast_slicing;
  class _HexAstReference                      * hex_ast_reference;
  class _HexAstPrimary                        * hex_ast_primary;
  class _HexAstTargetList                     * hex_ast_target_list;
  class _HexAstName                           * hex_ast_name;
  class _HexAstNameList                       * hex_ast_name_list;
  class _HexAstUnaryExpr                      * hex_ast_unary_expr;
  class _HexAstBinaryExpr                     * hex_ast_binary_expr;
  class _HexAstConditionalExpr                * hex_ast_conditional_expr;
  class _HexAstAssignmentExpr                 * hex_ast_assignment_expr;
  class _HexAstYieldExpr                      * hex_ast_yield_expr;
  class _HexAstStringCompositionExpr          * hex_ast_string_composition_expr;
  class _HexAstComprehension                  * hex_ast_comprehension;
  class _HexAstGeneratorExpr                  * hex_ast_generator_expr;
  class _HexAstParenForm                      * hex_ast_paren_form;
  class _HexAstListForm                       * hex_ast_list_form;
  class _HexAstDictForm                       * hex_ast_dict_form;
  class _HexAstObjectForm                     * hex_ast_object_form;
  class _HexAstExpr                           * hex_ast_expr;
  class _HexAstExprList                       * hex_ast_expr_list;
  class _HexAstSimpleParam                    * hex_ast_simple_param;
  class _HexAstSimpleParamList                * hex_ast_simple_param_list;
  class _HexAstKeywordParam                   * hex_ast_keyword_param;
  class _HexAstKeywordParamList               * hex_ast_keyword_param_list;
  class _HexAstParameterList                  * hex_ast_parameter_list;
  class _HexAstSimpleArg                      * hex_ast_simple_arg;
  class _HexAstSimpleArgList                  * hex_ast_simple_arg_list;
  class _HexAstKeywordArg                     * hex_ast_keyword_arg;
  class _HexAstKeywordArgList                 * hex_ast_keyword_arg_list;
  class _HexAstArgList                        * hex_ast_arg_list;
  class _HexAstFieldDef                       * hex_ast_field_def;
  class _HexAstFieldDefList                   * hex_ast_field_def_list;
  class _HexAstKeyValuePair                   * hex_ast_key_value_pair;
  class _HexAstKeyValuePairList               * hex_ast_key_value_pair_list;
  class _HexAstAttributeValuePair             * hex_ast_attribute_value_pair;
  class _HexAstAttributeValuePairList         * hex_ast_attribute_value_pair_list;
  class _HexAstDecorator                      * hex_ast_decorator;
  class _HexAstDecoratorList                  * hex_ast_decorator_list;
  class _HexAstAssignmentSource               * hex_ast_assignment_source;
  class _HexAstAssignmentFeature              * hex_ast_assignment_feature;
  class _HexAstAssignmentStmt                 * hex_ast_assignment_stmt;
  size_t                                        hex_ast_using_src_level;
  class _HexAstUsingSrc                       * hex_ast_using_src;
  class _HexAstUsingStmt                      * hex_ast_using_stmt;
  class _HexAstElifStmt                       * hex_ast_elif_stmt;
  class _HexAstElifStmtGroup                  * hex_ast_elif_group;
  class _HexAstIfStmt                         * hex_ast_if_stmt;
  class _HexAstForStmt                        * hex_ast_for_stmt;
  class _HexAstWithStmt                       * hex_ast_with_stmt;
  class _HexAstLockStmt                       * hex_ast_lock_stmt;
  class _HexAstWhileStmt                      * hex_ast_while_stmt;
  class _HexAstCatchStmt                      * hex_ast_catch_stmt;
  class _HexAstCatchStmtGroup                 * hex_ast_catch_stmt_group;
  class _HexAstTryStmt                        * hex_ast_try_stmt;
  class _HexAstClassDef                       * hex_ast_class_def;
  class _HexAstLambda                         * hex_ast_lambda;
  class _HexAstInputStmt                      * hex_ast_input_stmt;
  class _HexAstOutputStmt                     * hex_ast_output_stmt;
  class _HexAstTaskState                      * hex_ast_task_state;
  class _HexAstConditionalPreposition         * hex_ast_conditional_preposition;
  class _HexAstConditionalClause              * hex_ast_conditional_clause;
  class _HexAstStartClause                    * hex_ast_start_clause;
  class _HexAstPauseClause                    * hex_ast_pause_clause;
  class _HexAstResumeClause                   * hex_ast_resume_clause;
  class _HexAstCancelClause                   * hex_ast_cancel_clause;
  class _HexAstStopClause                     * hex_ast_stop_clause;
  class _HexAstTaskClause                     * hex_ast_task_clause;
  class _HexAstTaskDef                        * hex_ast_task_def;
  class _HexAstAwaitStmt                      * hex_ast_await_stmt;
  class _HexAstCompoundStmt                   * hex_ast_compound_stmt;
  class _HexAstReturnStmt                     * hex_ast_return_stmt;
  class _HexAstBreakStmt                      * hex_ast_break_stmt;
  class _HexAstContinueStmt                   * hex_ast_continue_stmt;
  class _HexAstRaiseStmt                      * hex_ast_raise_stmt;
  class _HexAstExprListStmt                   * hex_ast_expr_list_stmt;
  class _HexAstSimpleIfStmt                   * hex_ast_simple_if_stmt;
  class _HexAstSimpleStmt                     * hex_ast_simple_stmt;
  class _HexAstStmt                           * hex_ast_stmt;
  class _HexAstStmtGroup                      * hex_ast_stmt_group;
  class _HexAstHexProgram                     * hex_ast_hex_program;
};

%token <string> AFTER
%token <string> AND
%token <string> AS
%token <string> AWAIT
%token <string> BEFORE
%token <string> BREAK
%token <string> BY
%token <string> CANCEL
%token <string> CATCH
%token <string> CLASS
%token <string> CONTINUE
%token <string> DEFER
%token <string> ELIF
%token <string> ELSE
%token <string> EXTENDS
%token <string> FINISH
%token <string> FOR
%token <string> FROM
%token <string> IF
%token <string> IN
%token <string> IS
%token <string> IS_NOT
%token <string> LAMBDA
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
%token <string> TO
%token <string> TRY
%token <string> USING
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


%left     COMMA
%right    ASSIGN_OP ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MUL ASSIGN_DIV ASSIGN_MOD 
          ASSIGN_BITWISE_AND ASSIGN_BITWISE_OR ASSIGN_BITWISE_XOR ASSIGN_SHIFTLEFT ASSIGN_SHIFTRIGHT
%left     YIELD
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

%type <hex_ast_identifier>                  identifier
%type <hex_ast_integer>                     integer_literal
%type <hex_ast_string>                      string_literal
%type <hex_ast_float>                       floating_literal
%type <hex_ast_literal>                     literal
%type <hex_ast_call>                        call
%type <hex_ast_attribute_ref>               attribute_ref
%type <hex_ast_slicing>                     slicing
%type <hex_ast_reference>                   reference
%type <hex_ast_primary>                     primary
%type <hex_ast_target_list>                 target_list
%type <hex_ast_name>                        name
%type <hex_ast_name_list>                   name_list
%type <hex_ast_unary_expr>                  unary_left_associated_expr
%type <hex_ast_unary_expr>                  unary_right_associated_expr
%type <hex_ast_unary_expr>                  unary_expr
%type <hex_ast_binary_expr>                 additive_expr
%type <hex_ast_binary_expr>                 multiplicative_expr
%type <hex_ast_binary_expr>                 power_expr
%type <hex_ast_binary_expr>                 bitwise_expr
%type <hex_ast_binary_expr>                 comparison_expr
%type <hex_ast_binary_expr>                 logic_expr
%type <hex_ast_binary_expr>                 range_expr
%type <hex_ast_binary_expr>                 assignment_expr
%type <hex_ast_conditional_expr>            conditional_expr
%type <hex_ast_yield_expr>                  yield_expr
%type <hex_ast_string_composition_expr>     string_composition_expr
%type <hex_ast_comprehension>               nested_comprehension
%type <hex_ast_comprehension>               expr_comprehension
%type <hex_ast_comprehension>               comprehension
%type <hex_ast_generator_expr>              generator_expr
%type <hex_ast_paren_form>                  paren_form
%type <hex_ast_list_form>                   list_form
%type <hex_ast_dict_form>                   dict_form
%type <hex_ast_object_form>                 object_form
%type <hex_ast_expr>                        expr
%type <hex_ast_expr_list>                   expr_list
%type <hex_ast_expr_list>                   expr_list_or_none
%type <hex_ast_simple_param>                simple_param
%type <hex_ast_simple_param_list>           simple_param_list
%type <hex_ast_keyword_param>               keyword_param
%type <hex_ast_keyword_param_list>          keyword_param_list
%type <hex_ast_identifier>                  arg
%type <hex_ast_identifier>                  kwarg
%type <hex_ast_parameter_list>              parameter_list
%type <hex_ast_parameter_list>              parameter_list_or_none
%type <hex_ast_simple_arg>                  simple_arg
%type <hex_ast_simple_arg_list>             simple_arg_list
%type <hex_ast_keyword_arg>                 keyword_arg
%type <hex_ast_keyword_arg_list>            keyword_arg_list
%type <hex_ast_primary>                     args_argument
%type <hex_ast_primary>                     kwargs_argument
%type <hex_ast_arg_list>                    arg_list
%type <hex_ast_arg_list>                    arg_list_or_none
%type <hex_ast_field_def>                   field_def
%type <hex_ast_field_def_list>              field_def_list
%type <hex_ast_field_def_list>              field_def_list_or_none
%type <hex_ast_key_value_pair>              key_value_pair
%type <hex_ast_key_value_pair_list>         key_value_pair_list
%type <hex_ast_attribute_value_pair>        attribute_value_pair
%type <hex_ast_attribute_value_pair_list>   attribute_value_pair_list
%type <hex_ast_decorator>                   decorator
%type <hex_ast_decorator_list>              decorator_list
%type <hex_ast_decorator_list>              decorator_list_or_none
%type <hex_ast_assignment_source>           assignment_source
%type <hex_ast_assignment_feature>          assignment_feature
%type <hex_ast_assignment_stmt>             assignment_stmt
%type <hex_ast_using_src_level>             using_src_level
%type <hex_ast_using_src>                   using_src
%type <hex_ast_using_stmt>                  using_stmt_absolute
%type <hex_ast_using_stmt>                  using_stmt_relative
%type <hex_ast_using_stmt>                  using_stmt
%type <hex_ast_elif_stmt>                   elif_stmt
%type <hex_ast_elif_group>                  elif_group
%type <hex_ast_elif_group>                  elif_group_or_none
%type <hex_ast_stmt_group>                  else_stmts
%type <hex_ast_stmt_group>                  else_stmts_or_none
%type <hex_ast_if_stmt>                     if_stmt
%type <hex_ast_for_stmt>                    for_stmt
%type <hex_ast_with_stmt>                   with_stmt
%type <hex_ast_lock_stmt>                   lock_stmt
%type <hex_ast_while_stmt>                  while_stmt
%type <hex_ast_catch_stmt>                  catch_stmt
%type <hex_ast_catch_stmt_group>            catch_stmt_group
%type <hex_ast_try_stmt>                    try_stmt
%type <hex_ast_class_def>                   class_def
%type <hex_ast_lambda>                      simple_lambda
%type <hex_ast_lambda>                      complex_lambda
%type <hex_ast_lambda>                      lambda
%type <hex_ast_input_stmt>                  input_stmt_list
%type <hex_ast_input_stmt>                  input_stmt
%type <hex_ast_output_stmt>                 output_stmt_list
%type <hex_ast_output_stmt>                 output_stmt
%type <hex_ast_task_state>                  task_state
%type <hex_ast_conditional_preposition>     conditional_preposition
%type <hex_ast_conditional_clause>          conditional_clause
%type <hex_ast_conditional_clause>          conditional_clause_or_none
%type <hex_ast_start_clause>                start_clause
%type <hex_ast_pause_clause>                pause_clause
%type <hex_ast_resume_clause>               resume_clause
%type <hex_ast_cancel_clause>               cancel_clause
%type <hex_ast_stop_clause>                 stop_clause
%type <hex_ast_task_clause>                 task_clause
%type <hex_ast_task_def>                    task_def
%type <hex_ast_await_stmt>                  await_stmt
%type <hex_ast_compound_stmt>               compound_stmt
%type <hex_ast_return_stmt>                 return_stmt
%type <hex_ast_break_stmt>                  break_stmt
%type <hex_ast_continue_stmt>               continue_stmt
%type <hex_ast_raise_stmt>                  raise_stmt
%type <hex_ast_expr_list_stmt>              expr_list_stmt
%type <hex_ast_simple_if_stmt>              simple_if_stmt
%type <hex_ast_simple_stmt>                 simple_stmt
%type <hex_ast_stmt>                        stmt
%type <hex_ast_stmt_group>                  stmt_group
%type <hex_ast_stmt_group>                  stmt_group_or_none
%type <hex_ast_hex_program>                 hex_program

%error-verbose
%debug

%{

%}

%%

hex_program
  : stmt_group_or_none                                                                              { $$ = _HexAstHexProgram::create($1); }
  ;

stmt_group_or_none
  : stmt_group                                                                                      { $$ = $1; }
  |                                                                                                 { $$ = NULL; }
  ;

stmt_group
  : stmt                                                                                            { $$ = AstListObj<_HexAstStmtGroup, HexAstStmt>::create($1);     }
  | stmt_group stmt                                                                                 { $$ = AstListObj<_HexAstStmtGroup, HexAstStmt>::extend($1, $2); }
  ;

stmt
  : compound_stmt                                                                                   { $$ = $1; }
  | simple_stmt                                                                                     { $$ = $1; }
  ;

simple_stmt
  : expr_list_stmt                                                                                  { $$ = $1; }
  | assignment_stmt                                                                                 { $$ = $1; }
  | using_stmt                                                                                      { $$ = $1; }
  | return_stmt                                                                                     { $$ = $1; }
  | continue_stmt                                                                                   { $$ = $1; }
  | raise_stmt                                                                                      { $$ = $1; }
  | break_stmt                                                                                      { $$ = $1; }
  | input_stmt                                                                                      { $$ = $1; }
  | output_stmt                                                                                     { $$ = $1; }
  | simple_if_stmt                                                                                  { $$ = $1; }
  ;

simple_if_stmt
  : IF expr COLON simple_stmt                                                                       { $$ = AstFactory<_HexAstSimpleIfStmt>::create<HexAstExpr, HexAstSimpleStmt>($2, $4); }
  ;

expr_list_stmt
  : expr_list SEMICOLON                                                                             { $$ = AstFactory<_HexAstExprListStmt>::create<HexAstExprList>($1); }
  ;

raise_stmt
  : RAISE expr SEMICOLON                                                                            { $$ = AstFactory<_HexAstRaiseStmt>::create<HexAstExpr>($2); }
  ;

continue_stmt
  : CONTINUE SEMICOLON                                                                              { $$ = AstFactory<_HexAstContinueStmt>::create<>(); }
  ;

break_stmt
  : BREAK SEMICOLON                                                                                 { $$ = AstFactory<_HexAstBreakStmt>::create<>(); }
  ;

return_stmt
  : RETURN expr_list_or_none SEMICOLON                                                              { $$ = AstFactory<_HexAstReturnStmt>::create<HexAstExprList>($2); }
  ;

compound_stmt
  : if_stmt                                                                                         { $$ = $1; }
  | while_stmt                                                                                      { $$ = $1; }
  | with_stmt                                                                                       { $$ = $1; }
  | lock_stmt                                                                                       { $$ = $1; }
  | try_stmt                                                                                        { $$ = $1; }
  | for_stmt                                                                                        { $$ = $1; }
  | class_def                                                                                       { $$ = $1; }
  | await_stmt                                                                                      { $$ = $1; }
  ;

await_stmt
  : AWAIT LBRACE stmt_group_or_none RBRACE                                                          { $$ = AstFactory<_HexAstAwaitStmt>::create<HexAstStmtGroup>($3); }
  ;

task_def
  : task_clause                                                                                     { $$ = AstListObj<_HexAstTaskDef, HexAstTaskClause>::create($1);     }
  | task_def COMMA task_clause                                                                      { $$ = AstListObj<_HexAstTaskDef, HexAstTaskClause>::extend($1, $3); }
  ;

task_clause
  : start_clause                                                                                    { $$ = $1; }
  | pause_clause                                                                                    { $$ = $1; }
  | stop_clause                                                                                     { $$ = $1; }
  | cancel_clause                                                                                   { $$ = $1; }
  | resume_clause                                                                                   { $$ = $1; }
  ;

stop_clause
  : STOP expr_list conditional_clause                                                               { $$ = AstFactory<_HexAstStopClause>::create<HexAstExprList, HexAstConditionalClause>($2, $3); }
  ;

cancel_clause
  : CANCEL expr_list conditional_clause                                                             { $$ = AstFactory<_HexAstCancelClause>::create<HexAstExprList, HexAstConditionalClause>($2, $3); }
  ;

resume_clause
  : RESUME expr_list conditional_clause                                                             { $$ = AstFactory<_HexAstResumeClause>::create<HexAstExprList, HexAstConditionalClause>($2, $3); }
  ;

pause_clause
  : PAUSE expr_list conditional_clause                                                              { $$ = AstFactory<_HexAstPauseClause>::create<HexAstExprList, HexAstConditionalClause>($2, $3); }
  ;

start_clause
  : START expr_list AS identifier conditional_clause_or_none                                        { $$ = AstFactory<_HexAstStartClause>::create<HexAstExprList, HexAstIdentifier, HexAstConditionalClause>($2, $4, $5); }
  ;

conditional_clause_or_none
  : conditional_clause                                                                              { $$ = $1; }
  |                                                                                                 { $$ = NULL; }
  ;

conditional_clause
  : conditional_preposition expr_list task_state                                                    { $$ = AstFactory<_HexAstConditionalClause>::create<HexAstConditionalPreposition, HexAstExprList, HexAstTaskState>($1, $2, $3); }
  ;

conditional_preposition
  : BEFORE                                                                                          { $$ = AstFactory<_HexAstConditionalPreposition>::create<HexAstConditionalPrepositionEnum>(AST_TASK_CONDITIONAL_PREPOSITION_BEFORE); }
  | AFTER                                                                                           { $$ = AstFactory<_HexAstConditionalPreposition>::create<HexAstConditionalPrepositionEnum>(AST_TASK_CONDITIONAL_PREPOSITION_AFTER);  }
  ;

task_state
  : START                                                                                           { $$ = AstFactory<_HexAstTaskState>::create<HexAstTaskStateEnum>(AST_TASK_STATE_START); }
  | PAUSE                                                                                           { $$ = AstFactory<_HexAstTaskState>::create<HexAstTaskStateEnum>(AST_TASK_STATE_PAUSE); }
  | CANCEL                                                                                          { $$ = AstFactory<_HexAstTaskState>::create<HexAstTaskStateEnum>(AST_TASK_STATE_CANCEL); }
  | RESUME                                                                                          { $$ = AstFactory<_HexAstTaskState>::create<HexAstTaskStateEnum>(AST_TASK_STATE_RESUME); }
  | FINISH                                                                                          { $$ = AstFactory<_HexAstTaskState>::create<HexAstTaskStateEnum>(AST_TASK_STATE_FINISH); }
  ;

output_stmt
  : output_stmt_list SEMICOLON                                                                      { $$ = $1; }
  ;

output_stmt_list
  : primary OUTPUT_OP primary                                                                       { $$ = AstListObj<_HexAstOutputStmt, HexAstPrimary>::create($1, $3); }
  | output_stmt_list OUTPUT_OP primary                                                              { $$ = AstListObj<_HexAstOutputStmt, HexAstPrimary>::extend($1, $3); }
  ;

input_stmt
  : input_stmt_list SEMICOLON                                                                       { $$ = $1; }
  ;

input_stmt_list
  : primary INPUT_OP primary                                                                        { $$ = AstListObj<_HexAstInputStmt, HexAstPrimary>::create($1, $3); }
  | input_stmt_list INPUT_OP primary                                                                { $$ = AstListObj<_HexAstInputStmt, HexAstPrimary>::extend($1, $3); }
  ;

lambda
  : simple_lambda                                                                                   { $$ = $1; }
  | complex_lambda                                                                                  { $$ = $1; }
  ;

complex_lambda
  : LAMBDA LPAREN parameter_list_or_none RPAREN ARROW LBRACE stmt_group_or_none RBRACE              { $$ = AstFactory<_HexAstComplexLambda>::create<HexAstParameterList, HexAstStmtGroup>($3, $7); }
  ;

simple_lambda
  : LAMBDA LPAREN parameter_list_or_none RPAREN LAMBDA_OP expr                                      { $$ = AstFactory<_HexAstSimpleLambda>::create<HexAstParameterList, HexAstExpr>($3, $6); }
  ;

class_def
  : decorator_list_or_none CLASS identifier                   SEMICOLON                             { $$ = AstFactory<_HexAstClassDef>::create<HexAstDecoratorList, HexAstIdentifier, HexAstNameList, HexAstFieldDefList>($1, $3, NULL, NULL); }
  | decorator_list_or_none CLASS identifier EXTENDS name_list SEMICOLON                             { $$ = AstFactory<_HexAstClassDef>::create<HexAstDecoratorList, HexAstIdentifier, HexAstNameList, HexAstFieldDefList>($1, $3, $5,   NULL); }
  | decorator_list_or_none CLASS identifier                   LBRACE field_def_list_or_none RBRACE  { $$ = AstFactory<_HexAstClassDef>::create<HexAstDecoratorList, HexAstIdentifier, HexAstNameList, HexAstFieldDefList>($1, $3, NULL, $5);   }
  | decorator_list_or_none CLASS identifier EXTENDS name_list LBRACE field_def_list_or_none RBRACE  { $$ = AstFactory<_HexAstClassDef>::create<HexAstDecoratorList, HexAstIdentifier, HexAstNameList, HexAstFieldDefList>($1, $3, $5,   $7);   }
  ;

try_stmt
  : TRY LBRACE stmt_group_or_none RBRACE catch_stmt_group else_stmts_or_none                        { $$ = AstFactory<_HexAstTryStmt>::create<HexAstStmtGroup, HexAstCatchStmtGroup, HexAstStmtGroup>($3, $5, $6); }
  ;

catch_stmt_group
  : catch_stmt                                                                                      { $$ = AstListObj<_HexAstCatchStmtGroup, HexAstCatchStmt>::create($1); }
  | catch_stmt_group catch_stmt                                                                     { $$ = AstListObj<_HexAstCatchStmtGroup, HexAstCatchStmt>::extend($1, $2); }
  ;

catch_stmt
  : CATCH                         LBRACE stmt_group_or_none RBRACE                                  { $$ = AstFactory<_HexAstCatchStmt>::create<HexAstNameList, HexAstIdentifier, HexAstStmtGroup>(NULL, NULL, $3); }
  | CATCH name_list               LBRACE stmt_group_or_none RBRACE                                  { $$ = AstFactory<_HexAstCatchStmt>::create<HexAstNameList, HexAstIdentifier, HexAstStmtGroup>($2,   NULL, $4); }
  | CATCH name_list AS identifier LBRACE stmt_group_or_none RBRACE                                  { $$ = AstFactory<_HexAstCatchStmt>::create<HexAstNameList, HexAstIdentifier, HexAstStmtGroup>($2,   $4,   $6); }
  ;

while_stmt
  : WHILE expr LBRACE stmt_group_or_none RBRACE                                                     { $$ = AstFactory<_HexAstWhileStmt>::create<HexAstExpr, HexAstStmtGroup>($2, $4); }
  ;

lock_stmt
  : LOCK name LBRACE stmt_group_or_none RBRACE                                                      { $$ = AstFactory<_HexAstLockStmt>::create<HexAstName, HexAstStmtGroup>($2, $4); }
  ;

with_stmt
  : WITH expr               LBRACE stmt_group_or_none RBRACE                                        { $$ = AstFactory<_HexAstWithStmt>::create<HexAstExpr, HexAstIdentifier, HexAstStmtGroup>($2, NULL, $4); }
  | WITH expr AS identifier LBRACE stmt_group_or_none RBRACE                                        { $$ = AstFactory<_HexAstWithStmt>::create<HexAstExpr, HexAstIdentifier, HexAstStmtGroup>($2, $4,   $6); }
  ;

for_stmt
  : FOR target_list IN expr_list         LBRACE stmt_group_or_none RBRACE                           { $$ = AstFactory<_HexAstForStmt>::create<HexAstTargetList, HexAstExprList, HexAstExpr, HexAstStmtGroup>($2, $4, NULL, $6); }
  | FOR target_list IN expr_list IF expr LBRACE stmt_group_or_none RBRACE                           { $$ = AstFactory<_HexAstForStmt>::create<HexAstTargetList, HexAstExprList, HexAstExpr, HexAstStmtGroup>($2, $4, $6,   $8); }
  ;

if_stmt
  : IF expr LBRACE stmt_group_or_none RBRACE elif_group_or_none else_stmts_or_none                  { $$ = AstFactory<_HexAstIfStmt>::create<HexAstExpr, HexAstStmtGroup, HexAstElifStmtGroup, HexAstStmtGroup>($2, $4, $6, $7); }
  ;

else_stmts_or_none
  : else_stmts                                                                                      { $$ = $1;   }
  |                                                                                                 { $$ = NULL; }
  ;

else_stmts
  : ELSE LBRACE stmt_group_or_none RBRACE                                                           { $$ = $3; }
  ;

elif_group_or_none
  : elif_group                                                                                      { $$ = $1;   }
  |                                                                                                 { $$ = NULL; }
  ;

elif_group
  : elif_stmt                                                                                       { $$ = AstListObj<_HexAstElifStmtGroup, HexAstElifStmt>::create($1);     }
  | elif_group elif_stmt                                                                            { $$ = AstListObj<_HexAstElifStmtGroup, HexAstElifStmt>::extend($1, $2); }
  ;

elif_stmt
  : ELIF expr LBRACE stmt_group_or_none RBRACE                                                      { $$ = AstFactory<_HexAstElifStmt>::create<HexAstExpr, HexAstStmtGroup>($2, $4); }
  ;

using_stmt
  : using_stmt_absolute                                                                             { $$ = $1; }
  | using_stmt_relative                                                                             { $$ = $1; }
  ;

using_stmt_absolute
  : USING name               SEMICOLON                                                              { $$ = AstFactory<_HexAstAbsoluteUsingStmt>::create<HexAstName, HexAstIdentifier>($2, NULL); }
  | USING name AS identifier SEMICOLON                                                              { $$ = AstFactory<_HexAstAbsoluteUsingStmt>::create<HexAstName, HexAstIdentifier>($2, $4);   }
  ;

using_stmt_relative
  : USING target_list IN using_src               SEMICOLON                                          { $$ = AstFactory<_HexAstRelativeUsingStmt>::create<HexAstTargetList, HexAstUsingSrc, HexAstIdentifier>($2,   $4, NULL); }
  | USING target_list IN using_src AS identifier SEMICOLON                                          { $$ = AstFactory<_HexAstRelativeUsingStmt>::create<HexAstTargetList, HexAstUsingSrc, HexAstIdentifier>($2,   $4, $6);   }
  | USING MUL_OP      IN using_src               SEMICOLON                                          { $$ = AstFactory<_HexAstRelativeUsingStmt>::create<HexAstTargetList, HexAstUsingSrc, HexAstIdentifier>(NULL, $4, NULL); }
  ;

using_src
  :                 name                                                                            { $$ = AstFactory<_HexAstUsingSrc>::create<size_t, HexAstName>(0,  $1);   }
  | using_src_level                                                                                 { $$ = AstFactory<_HexAstUsingSrc>::create<size_t, HexAstName>($1, NULL); }
  | using_src_level name                                                                            { $$ = AstFactory<_HexAstUsingSrc>::create<size_t, HexAstName>($1, $2);   }
  ;

using_src_level
  : DOT                                                                                             { $$ = 1;      }
  | using_src_level DOT                                                                             { $$ = $1 + 1; }
  ;

assignment_stmt
  : reference ASSIGN_OP assignment_feature assignment_source SEMICOLON                              { $$ = AstFactory<_HexAstAssignmentStmt>::create<HexAstReference, HexAstAssignmentFeature, HexAstAssignmentSource>($1, $3, $4); }
  ;

assignment_feature
  : DEFER                                                                                           { $$ = AstFactory<_HexAstAssignmentFeature>::create<HexAstAssignmentFeatureEnum>(HEX_AST_ASSIGNMENT_FEATURE_DEFER); }
  |                                                                                                 { $$ = AstFactory<_HexAstAssignmentFeature>::create<HexAstAssignmentFeatureEnum>(HEX_AST_ASSIGNMENT_FEATURE_NONE);  }
  ;

assignment_source
  : expr_list                                                                                       { $$ = $1; }
  | lambda                                                                                          { $$ = $1; }
  | task_def                                                                                        { $$ = $1; }
  ;

decorator_list_or_none
  : decorator_list                                                                                  { $$ = $1;   }
  |                                                                                                 { $$ = NULL; }
  ;

decorator_list
  : decorator                                                                                       { $$ = AstListObj<_HexAstDecoratorList, HexAstDecorator>::create($1);     }
  | decorator_list decorator                                                                        { $$ = AstListObj<_HexAstDecoratorList, HexAstDecorator>::extend($1, $2); }
  ;

decorator
  : AT name                                                                                         { $$ = AstFactory<_HexAstDecorator>::create<HexAstName, HexAstArgList>($2, NULL); }
  | AT name LPAREN arg_list_or_none RPAREN                                                          { $$ = AstFactory<_HexAstDecorator>::create<HexAstName, HexAstArgList>($2, $4);   }
  ;

attribute_value_pair_list
  : attribute_value_pair                                                                            { $$ = AstListObj<_HexAstAttributeValuePairList, HexAstAttributeValuePair>::create($1);     }
  | attribute_value_pair_list COMMA attribute_value_pair                                            { $$ = AstListObj<_HexAstAttributeValuePairList, HexAstAttributeValuePair>::extend($1, $3); }
  ;

attribute_value_pair
  : DOT identifier ASSIGN_OP simple_arg                                                             { $$ = AstFactory<_HexAstAttributeValuePair>::create<HexAstIdentifier, HexAstSimpleArg>($2, $4); }
  ;

key_value_pair_list
  : key_value_pair                                                                                  { $$ = AstListObj<_HexAstKeyValuePairList, HexAstKeyValuePair>::create($1);     }
  | key_value_pair_list COMMA key_value_pair                                                        { $$ = AstListObj<_HexAstKeyValuePairList, HexAstKeyValuePair>::extend($1, $3); }
  ;

key_value_pair
  : expr COLON simple_arg                                                                           { $$ = AstFactory<_HexAstKeyValuePair>::create<HexAstExpr, HexAstSimpleArg>($1, $3); }
  ;

field_def_list_or_none
  : field_def_list                                                                                  { $$ = $1;   }
  |                                                                                                 { $$ = NULL; }
  ;

field_def_list
  : field_def                                                                                       { $$ = AstListObj<_HexAstFieldDefList, HexAstFieldDef>::create($1);     }
  | field_def_list field_def                                                                        { $$ = AstListObj<_HexAstFieldDefList, HexAstFieldDef>::extend($1, $2); }
  ;

field_def
  : decorator_list_or_none identifier COLON simple_arg                                              { $$ = AstFactory<_HexAstFieldDef>::create<HexAstDecoratorList, HexAstIdentifier, HexAstSimpleArg>($1, $2, $4); }
  ;

arg_list_or_none
  : arg_list                                                                                        { $$ = $1;   }
  |                                                                                                 { $$ = NULL; }
  ;

arg_list
  : simple_arg_list COMMA args_argument COMMA keyword_arg_list COMMA kwargs_argument                 { $$ = AstFactory<_HexAstArgList>::create<HexAstSimpleArgList, HexAstPrimary, HexAstKeywordArgList, HexAstPrimary>($1,   $3,   $5,   $7  ); }
  | simple_arg_list COMMA args_argument COMMA keyword_arg_list                                       { $$ = AstFactory<_HexAstArgList>::create<HexAstSimpleArgList, HexAstPrimary, HexAstKeywordArgList, HexAstPrimary>($1,   $3,   $5,   NULL); }
  | simple_arg_list COMMA args_argument                        COMMA kwargs_argument                 { $$ = AstFactory<_HexAstArgList>::create<HexAstSimpleArgList, HexAstPrimary, HexAstKeywordArgList, HexAstPrimary>($1,   $3,   NULL, $5  ); }
  | simple_arg_list COMMA args_argument                                                              { $$ = AstFactory<_HexAstArgList>::create<HexAstSimpleArgList, HexAstPrimary, HexAstKeywordArgList, HexAstPrimary>($1,   $3,   NULL, NULL); }
  | simple_arg_list                     COMMA keyword_arg_list COMMA kwargs_argument                 { $$ = AstFactory<_HexAstArgList>::create<HexAstSimpleArgList, HexAstPrimary, HexAstKeywordArgList, HexAstPrimary>($1,   NULL, $3,   $5  ); }
  | simple_arg_list                     COMMA keyword_arg_list                                       { $$ = AstFactory<_HexAstArgList>::create<HexAstSimpleArgList, HexAstPrimary, HexAstKeywordArgList, HexAstPrimary>($1,   NULL, $3,   NULL); }
  | simple_arg_list                                            COMMA kwargs_argument                 { $$ = AstFactory<_HexAstArgList>::create<HexAstSimpleArgList, HexAstPrimary, HexAstKeywordArgList, HexAstPrimary>($1,   NULL, NULL, $3  ); }
  | simple_arg_list                                                                                  { $$ = AstFactory<_HexAstArgList>::create<HexAstSimpleArgList, HexAstPrimary, HexAstKeywordArgList, HexAstPrimary>($1,   NULL, NULL, NULL); }
  |                       args_argument COMMA keyword_arg_list COMMA kwargs_argument                 { $$ = AstFactory<_HexAstArgList>::create<HexAstSimpleArgList, HexAstPrimary, HexAstKeywordArgList, HexAstPrimary>(NULL, $1,   $3,   $5  ); }
  |                       args_argument COMMA keyword_arg_list                                       { $$ = AstFactory<_HexAstArgList>::create<HexAstSimpleArgList, HexAstPrimary, HexAstKeywordArgList, HexAstPrimary>(NULL, $1,   $3,   NULL); }
  |                       args_argument                        COMMA kwargs_argument                 { $$ = AstFactory<_HexAstArgList>::create<HexAstSimpleArgList, HexAstPrimary, HexAstKeywordArgList, HexAstPrimary>(NULL, $1,   NULL, $3  ); }
  |                       args_argument                                                              { $$ = AstFactory<_HexAstArgList>::create<HexAstSimpleArgList, HexAstPrimary, HexAstKeywordArgList, HexAstPrimary>(NULL, $1,   NULL, NULL); }
  |                                           keyword_arg_list COMMA kwargs_argument                 { $$ = AstFactory<_HexAstArgList>::create<HexAstSimpleArgList, HexAstPrimary, HexAstKeywordArgList, HexAstPrimary>(NULL, NULL, $1,   $3  ); }
  |                                           keyword_arg_list                                       { $$ = AstFactory<_HexAstArgList>::create<HexAstSimpleArgList, HexAstPrimary, HexAstKeywordArgList, HexAstPrimary>(NULL, NULL, $1,   NULL); }
  |                                                                  kwargs_argument                 { $$ = AstFactory<_HexAstArgList>::create<HexAstSimpleArgList, HexAstPrimary, HexAstKeywordArgList, HexAstPrimary>(NULL, NULL, NULL, $1  ); }
  ;

kwargs_argument
  : STARS primary                                                                                   { $$ = $2; }
  ;

args_argument
  : MUL_OP primary                                                                                  { $$ = $2; }
  ;

keyword_arg_list
  : keyword_arg                                                                                     { $$ = AstListObj<_HexAstKeywordArgList, HexAstKeywordArg>::create($1);     }
  | keyword_arg_list COMMA keyword_arg                                                              { $$ = AstListObj<_HexAstKeywordArgList, HexAstKeywordArg>::extend($1, $3); }
  ;

keyword_arg
  : identifier ASSIGN_OP simple_arg                                                                 { $$ = AstFactory<_HexAstKeywordArg>::create<HexAstIdentifier, HexAstSimpleArg>($1, $3); }
  ;

simple_arg_list
  : simple_arg                                                                                      { $$ = AstListObj<_HexAstSimpleArgList, HexAstSimpleArg>::create($1);     }
  | simple_arg_list COMMA simple_arg                                                                { $$ = AstListObj<_HexAstSimpleArgList, HexAstSimpleArg>::extend($1, $3); }
  ;

simple_arg
  : expr                                                                                            { $$ = $1; }
  | lambda                                                                                          { $$ = $1; }
  ;

parameter_list_or_none
  : parameter_list                                                                                  { $$ = $1;   }
  |                                                                                                 { $$ = NULL; }
  ;

parameter_list
  : simple_param_list COMMA arg COMMA keyword_param_list COMMA kwarg                                { $$ = AstFactory<_HexAstParameterList>::create<HexAstSimpleParamList, HexAstIdentifier, HexAstKeywordParamList, HexAstIdentifier>($1,   $3,   $5,   $7);   }
  | simple_param_list COMMA arg COMMA keyword_param_list                                            { $$ = AstFactory<_HexAstParameterList>::create<HexAstSimpleParamList, HexAstIdentifier, HexAstKeywordParamList, HexAstIdentifier>($1,   $3,   $5,   NULL); }
  | simple_param_list COMMA arg                          COMMA kwarg                                { $$ = AstFactory<_HexAstParameterList>::create<HexAstSimpleParamList, HexAstIdentifier, HexAstKeywordParamList, HexAstIdentifier>($1,   $3,   NULL, $5);   }
  | simple_param_list COMMA arg                                                                     { $$ = AstFactory<_HexAstParameterList>::create<HexAstSimpleParamList, HexAstIdentifier, HexAstKeywordParamList, HexAstIdentifier>($1,   $3,   NULL, NULL); }
  | simple_param_list           COMMA keyword_param_list COMMA kwarg                                { $$ = AstFactory<_HexAstParameterList>::create<HexAstSimpleParamList, HexAstIdentifier, HexAstKeywordParamList, HexAstIdentifier>($1,   NULL, $3,   $5);   }
  | simple_param_list           COMMA keyword_param_list                                            { $$ = AstFactory<_HexAstParameterList>::create<HexAstSimpleParamList, HexAstIdentifier, HexAstKeywordParamList, HexAstIdentifier>($1,   NULL, $3,   NULL); }
  | simple_param_list                                    COMMA kwarg                                { $$ = AstFactory<_HexAstParameterList>::create<HexAstSimpleParamList, HexAstIdentifier, HexAstKeywordParamList, HexAstIdentifier>($1,   NULL, NULL, $3);   }
  | simple_param_list                                                                               { $$ = AstFactory<_HexAstParameterList>::create<HexAstSimpleParamList, HexAstIdentifier, HexAstKeywordParamList, HexAstIdentifier>($1,   NULL, NULL, NULL); }
  |                         arg COMMA keyword_param_list COMMA kwarg                                { $$ = AstFactory<_HexAstParameterList>::create<HexAstSimpleParamList, HexAstIdentifier, HexAstKeywordParamList, HexAstIdentifier>(NULL, $1,   $3,   $5);   }
  |                         arg COMMA keyword_param_list                                            { $$ = AstFactory<_HexAstParameterList>::create<HexAstSimpleParamList, HexAstIdentifier, HexAstKeywordParamList, HexAstIdentifier>(NULL, $1,   $3,   NULL); }
  |                         arg                          COMMA kwarg                                { $$ = AstFactory<_HexAstParameterList>::create<HexAstSimpleParamList, HexAstIdentifier, HexAstKeywordParamList, HexAstIdentifier>(NULL, $1,   NULL, $3);   }
  |                         arg                                                                     { $$ = AstFactory<_HexAstParameterList>::create<HexAstSimpleParamList, HexAstIdentifier, HexAstKeywordParamList, HexAstIdentifier>(NULL, $1,   NULL, NULL); }
  |                                   keyword_param_list COMMA kwarg                                { $$ = AstFactory<_HexAstParameterList>::create<HexAstSimpleParamList, HexAstIdentifier, HexAstKeywordParamList, HexAstIdentifier>(NULL, NULL, $1,   $3);   }
  |                                   keyword_param_list                                            { $$ = AstFactory<_HexAstParameterList>::create<HexAstSimpleParamList, HexAstIdentifier, HexAstKeywordParamList, HexAstIdentifier>(NULL, NULL, $1,   NULL); }
  |                                                            kwarg                                { $$ = AstFactory<_HexAstParameterList>::create<HexAstSimpleParamList, HexAstIdentifier, HexAstKeywordParamList, HexAstIdentifier>(NULL, NULL, NULL, $1);   }
  ;

kwarg
  : STARS identifier                                                                                { $$ = $2; }
  ;

arg
  : MUL_OP identifier                                                                               { $$ = $2; }
  ;

keyword_param_list
  : keyword_param                                                                                   { $$ = AstListObj<_HexAstKeywordParamList, HexAstKeywordParam>::create($1);     } 
  | keyword_param_list COMMA keyword_param                                                          { $$ = AstListObj<_HexAstKeywordParamList, HexAstKeywordParam>::extend($1, $3); } 
  ;

keyword_param
  :         identifier ASSIGN_OP simple_arg                                                         { $$ = AstFactory<_HexAstKeywordParam>::create<HexAstName, HexAstIdentifier, HexAstSimpleArg>(NULL, $1, $3); }
  | AT name identifier ASSIGN_OP simple_arg                                                         { $$ = AstFactory<_HexAstKeywordParam>::create<HexAstName, HexAstIdentifier, HexAstSimpleArg>($2,   $3, $5); }
  ;

simple_param_list
  : simple_param                                                                                    { $$ = AstListObj<_HexAstSimpleParamList, HexAstSimpleParam>::create($1);     }
  | simple_param_list COMMA simple_param                                                            { $$ = AstListObj<_HexAstSimpleParamList, HexAstSimpleParam>::extend($1, $3); }
  ;

simple_param
  :         identifier                                                                              { $$ = AstFactory<_HexAstSimpleParam>::create<HexAstName, HexAstIdentifier>(NULL, $1); }
  | AT name identifier                                                                              { $$ = AstFactory<_HexAstSimpleParam>::create<HexAstName, HexAstIdentifier>($2,   $3); }
  ;

expr_list_or_none
  : expr_list                                                                                       { $$ = $1;   }
  |                                                                                                 { $$ = NULL; }
  ;

expr_list
  : expr                                                                                            { $$ = AstListObj<_HexAstExprList, HexAstExpr>::create($1);     }
  | expr_list COMMA expr                                                                            { $$ = AstListObj<_HexAstExprList, HexAstExpr>::extend($1, $3); }
  ;

expr
  : primary                                                                                         { $$ = $1; }
  | unary_expr                                                                                      { $$ = $1; }
  | additive_expr                                                                                   { $$ = $1; }
  | multiplicative_expr                                                                             { $$ = $1; }
  | power_expr                                                                                      { $$ = $1; }
  | bitwise_expr                                                                                    { $$ = $1; }
  | comparison_expr                                                                                 { $$ = $1; }
  | logic_expr                                                                                      { $$ = $1; }
  | range_expr                                                                                      { $$ = $1; }
  | conditional_expr                                                                                { $$ = $1; }
  | assignment_expr                                                                                 { $$ = $1; }
  | yield_expr                                                                                      { $$ = $1; }
  | string_composition_expr                                                                         { $$ = $1; }
  | generator_expr                                                                                  { $$ = $1; }
  ;

object_form
  : LBRACE attribute_value_pair_list RBRACE                                                         { $$ = AstFactory<_HexAstObjectForm>::create<HexAstAttributeValuePairList>($2); }
  ;

dict_form
  : LBRACE                     RBRACE                                                               { $$ = AstFactory<_HexAstExplicitDictForm>::create<HexAstKeyValuePairList>(NULL); }
  | LBRACE key_value_pair_list RBRACE                                                               { $$ = AstFactory<_HexAstExplicitDictForm>::create<HexAstKeyValuePairList>($2);   }
  | LBRACE comprehension       RBRACE                                                               { $$ = AstFactory<_HexAstImplicitDictForm>::create<HexAstComprehension>($2);      }
  ;

list_form
  : LBRACKET               RBRACKET                                                                 { $$ = AstFactory<_HexAstExplicitListForm>::create<HexAstExprList>(NULL);    }
  | LBRACKET expr_list     RBRACKET                                                                 { $$ = AstFactory<_HexAstExplicitListForm>::create<HexAstExprList>($2);      }
  | LBRACKET comprehension RBRACKET                                                                 { $$ = AstFactory<_HexAstImplicitListForm>::create<HexAstComprehension>($2); }
  ;

paren_form
  : LPAREN expr_list_or_none RPAREN                                                                 { $$ = AstFactory<_HexAstParenForm>::create<HexAstExprList>($2); }
  ;

generator_expr
  : LPAREN comprehension RPAREN                                                                     { $$ = AstFactory<_HexAstGeneratorExpr>::create<HexAstComprehension>($2); }
  ;

comprehension
  : nested_comprehension                                                                            { $$ = $1; }
  | expr_comprehension                                                                              { $$ = $1; }
  ;

nested_comprehension
  : comprehension FOR target_list IN expr_list                                                      { $$ = AstFactory<_HexAstNestedComprehension>::create<HexAstComprehension, HexAstTargetList, HexAstExprList, HexAstExpr>($1, $3, $5, NULL); }
  | comprehension FOR target_list IN expr_list IF expr                                              { $$ = AstFactory<_HexAstNestedComprehension>::create<HexAstComprehension, HexAstTargetList, HexAstExprList, HexAstExpr>($1, $3, $5, $7);   }
  ;

expr_comprehension
  : expr_list FOR target_list IN expr_list                                                          { $$ = AstFactory<_HexAstExprComprehension>::create<HexAstExprList, HexAstTargetList, HexAstExprList, HexAstExpr>($1, $3, $5, NULL); }
  | expr_list FOR target_list IN expr_list IF expr                                                  { $$ = AstFactory<_HexAstExprComprehension>::create<HexAstExprList, HexAstTargetList, HexAstExprList, HexAstExpr>($1, $3, $5, $7);   }
  ;

string_composition_expr
  : string_literal STRING_OP paren_form                                                             { $$ = AstFactory<_HexAstStringCompositionExpr>::create<HexAstStringLiteral, HexAstParenForm>($1, $3); }
  ;

yield_expr
  : YIELD                                                                                           { $$ = AstFactory<_HexAstYieldExpr>::create<HexAstExprList>(NULL); }
  | YIELD LPAREN expr_list RPAREN                                                                   { $$ = AstFactory<_HexAstYieldExpr>::create<HexAstExprList>($3);   }
  ;

assignment_expr
  : expr ASSIGN_PLUS        expr                                                                    { $$ = AstFactory<_HexAstAdditionAssignmentExpr>::create<HexAstExpr, HexAstExpr>($1, $3);          }
  | expr ASSIGN_MINUS       expr                                                                    { $$ = AstFactory<_HexAstSubtractionAssignmentExpr>::create<HexAstExpr, HexAstExpr>($1, $3);       }
  | expr ASSIGN_MUL         expr                                                                    { $$ = AstFactory<_HexAstMultiplicationAssignmentExpr>::create<HexAstExpr, HexAstExpr>($1, $3);    }
  | expr ASSIGN_DIV         expr                                                                    { $$ = AstFactory<_HexAstDivisionAssignmentExpr>::create<HexAstExpr, HexAstExpr>($1, $3);          }
  | expr ASSIGN_MOD         expr                                                                    { $$ = AstFactory<_HexAstModulusAssignmentExpr>::create<HexAstExpr, HexAstExpr>($1, $3);           }
  | expr ASSIGN_BITWISE_AND expr                                                                    { $$ = AstFactory<_HexAstBitwiseANDAssignmentExpr>::create<HexAstExpr, HexAstExpr>($1, $3);        }
  | expr ASSIGN_BITWISE_OR  expr                                                                    { $$ = AstFactory<_HexAstBitwiseORAssignmentExpr>::create<HexAstExpr, HexAstExpr>($1, $3);         }
  | expr ASSIGN_BITWISE_XOR expr                                                                    { $$ = AstFactory<_HexAstBitwiseXORAssignmentExpr>::create<HexAstExpr, HexAstExpr>($1, $3);        }
  | expr ASSIGN_SHIFTLEFT   expr                                                                    { $$ = AstFactory<_HexAstBitwiseLeftShiftAssignmentExpr>::create<HexAstExpr, HexAstExpr>($1, $3);  }
  | expr ASSIGN_SHIFTRIGHT  expr                                                                    { $$ = AstFactory<_HexAstBitwiseRightShiftAssignmentExpr>::create<HexAstExpr, HexAstExpr>($1, $3); }
  ;

conditional_expr
  : IF expr THEN expr ELSE expr                                                                     { $$ = AstFactory<_HexAstConditionalExpr>::create<HexAstExpr, HexAstExpr>($2, $4, $6); }
  ;

range_expr
  : expr ELLIPSIS       expr                                                                        { $$ = AstFactory<_HexAstInclusiveRangeExpr>::create<HexAstExpr, HexAstExpr>($1, $3); }
  | expr ELLIPSIS_SHORT expr                                                                        { $$ = AstFactory<_HexAstExclusiveRangeExpr>::create<HexAstExpr, HexAstExpr>($1, $3); }
  ;

logic_expr
  : expr AND expr                                                                                   { $$ = AstFactory<_HexAstLogicalANDExpr>::create<HexAstExpr, HexAstExpr>($1, $3); }
  | expr OR  expr                                                                                   { $$ = AstFactory<_HexAstLogicalORExpr>::create<HexAstExpr, HexAstExpr>($1, $3);  }
  ;

comparison_expr
  : expr EQ_OP      expr                                                                            { $$ = AstFactory<_HexAstEqualsExpr>::create<HexAstExpr, HexAstExpr>($1, $3);          }
  | expr NEQ_OP     expr                                                                            { $$ = AstFactory<_HexAstNotEqualExpr>::create<HexAstExpr, HexAstExpr>($1, $3);        }
  | expr IS         expr                                                                            { $$ = AstFactory<_HexAstIsExpr>::create<HexAstExpr, HexAstExpr>($1, $3);              }
  | expr IS_NOT     expr                                                                            { $$ = AstFactory<_HexAstIsNotExpr>::create<HexAstExpr, HexAstExpr>($1, $3);           }
  | expr LESS_OP    expr                                                                            { $$ = AstFactory<_HexAstLessThanExpr>::create<HexAstExpr, HexAstExpr>($1, $3);        }
  | expr GREATER_OP expr                                                                            { $$ = AstFactory<_HexAstGreaterThanExpr>::create<HexAstExpr, HexAstExpr>($1, $3);     }
  | expr LEQ_OP     expr                                                                            { $$ = AstFactory<_HexAstLessOrEqualsExpr>::create<HexAstExpr, HexAstExpr>($1, $3);    }
  | expr GEQ_OP     expr                                                                            { $$ = AstFactory<_HexAstGreaterOrEqualsExpr>::create<HexAstExpr, HexAstExpr>($1, $3); }
  | expr IN         expr                                                                            { $$ = AstFactory<_HexAstInExpr>::create<HexAstExpr, HexAstExpr>($1, $3);              }
  | expr NOT IN     expr                                                                            { $$ = AstFactory<_HexAstNotInExpr>::create<HexAstExpr, HexAstExpr>($1, $4);           }
  ;

bitwise_expr
  : expr BITWISE_AND        expr                                                                    { $$ = AstFactory<_HexAstBitwiseANDExpr>::create<HexAstExpr, HexAstExpr>($1, $3);        }
  | expr BITWISE_OR         expr                                                                    { $$ = AstFactory<_HexAstBitwiseORExpr>::create<HexAstExpr, HexAstExpr>($1, $3);         }
  | expr BITWISE_XOR        expr                                                                    { $$ = AstFactory<_HexAstBitwiseXORExpr>::create<HexAstExpr, HexAstExpr>($1, $3);        }
  | expr BITWISE_SHIFTLEFT  expr                                                                    { $$ = AstFactory<_HexAstBitwiseLeftShiftExpr>::create<HexAstExpr, HexAstExpr>($1, $3);  }
  | expr BITWISE_SHIFTRIGHT expr                                                                    { $$ = AstFactory<_HexAstBitwiseRightShiftExpr>::create<HexAstExpr, HexAstExpr>($1, $3); }
  ;

power_expr
  : expr STARS expr                                                                                 { $$ = AstFactory<_HexAstPowerExpr>::create<HexAstExpr, HexAstExpr>($1, $3); }
  ;

multiplicative_expr
  : expr MUL_OP expr                                                                                { $$ = AstFactory<_HexAstMultiplicationExpr>::create<HexAstExpr, HexAstExpr>($1, $3); }
  | expr DIV_OP expr                                                                                { $$ = AstFactory<_HexAstDivisionExpr>::create<HexAstExpr, HexAstExpr>($1, $3);       }
  | expr MOD_OP expr                                                                                { $$ = AstFactory<_HexAstModulusExpr>::create<HexAstExpr, HexAstExpr>($1, $3);        }
  ;

additive_expr
  : expr PLUS_OP  expr                                                                              { $$ = AstFactory<_HexAstAdditionExpr>::create<HexAstExpr, HexAstExpr>($1, $3);    }
  | expr MINUS_OP expr                                                                              { $$ = AstFactory<_HexAstSubtractionExpr>::create<HexAstExpr, HexAstExpr>($1, $3); }
  ;

unary_expr
  : unary_left_associated_expr                                                                      { $$ = $1; }
  | unary_right_associated_expr                                                                     { $$ = $1; }
  ;

unary_right_associated_expr
  : PLUS_OP     expr %prec UPLUS                                                                    { $$ = AstFactory<_HexAstPositiveExpr>::create<HexAstExpr>($2);   }
  | MINUS_OP    expr %prec UMINUS                                                                   { $$ = AstFactory<_HexAstNegativeExpr>::create<HexAstExpr>($2);   }
  | NOT         expr                                                                                { $$ = AstFactory<_HexAstNotExpr>::create<HexAstExpr>($2);        }
  | BITWISE_NOT expr                                                                                { $$ = AstFactory<_HexAstBitwiseNotExpr>::create<HexAstExpr>($2); }
  ;

unary_left_associated_expr
  : expr INC_OP                                                                                     { $$ = AstFactory<_HexAstIncrementExpr>::create<HexAstExpr>($1);   }
  | expr DEC_OP                                                                                     { $$ = AstFactory<_HexAstDecrementExpr>::create<HexAstExpr>($1);   }
  | expr EXISTENTIAL_OP                                                                             { $$ = AstFactory<_HexAstExistentialExpr>::create<HexAstExpr>($1); }
  ;

name_list
  : name                                                                                            { $$ = AstListObj<_HexAstNameList, HexAstName>::create($1);     }
  | name_list COMMA name                                                                            { $$ = AstListObj<_HexAstNameList, HexAstName>::extend($1, $3); }
  ;

name
  : identifier                                                                                      { $$ = AstListObj<_HexAstName, HexAstIdentifier>::create($1);     }
  | name DOT identifier                                                                             { $$ = AstListObj<_HexAstName, HexAstIdentifier>::extend($1, $3); }
  ;

target_list
  : identifier                                                                                      { $$ = AstListObj<_HexAstTargetList, HexAstIdentifier>::create($1);     }
  | target_list COMMA identifier                                                                    { $$ = AstListObj<_HexAstTargetList, HexAstIdentifier>::extend($1, $3); }
  ;

primary
  : literal                                                                                         { $$ = $1; }
  | reference                                                                                       { $$ = $1; }
  | call                                                                                            { $$ = $1; }
  | paren_form                                                                                      { $$ = $1; }
  | list_form                                                                                       { $$ = $1; }
  | dict_form                                                                                       { $$ = $1; }
  | object_form                                                                                     { $$ = $1; }
  ;

reference
  : identifier                                                                                      { $$ = $1; }
  | slicing                                                                                         { $$ = $1; }
  | attribute_ref                                                                                   { $$ = $1; }
  ;

slicing
  : primary LBRACKET expr COLON expr COLON expr RBRACKET                                            { $$ = AstFactory<_HexAstSlicing>::create<HexAstSlicingEnum, HexAstPrimary, HexAstExpr, HexAstExpr, HexAstExpr>(AST_SLICING_TYPE_1, $1, $3,   $5,   $7);   }
  | primary LBRACKET expr COLON expr COLON      RBRACKET                                            { $$ = AstFactory<_HexAstSlicing>::create<HexAstSlicingEnum, HexAstPrimary, HexAstExpr, HexAstExpr, HexAstExpr>(AST_SLICING_TYPE_2, $1, $3,   $5,   NULL); }
  | primary LBRACKET expr COLON expr            RBRACKET                                            { $$ = AstFactory<_HexAstSlicing>::create<HexAstSlicingEnum, HexAstPrimary, HexAstExpr, HexAstExpr, HexAstExpr>(AST_SLICING_TYPE_3, $1, $3,   $5,   NULL); }
  | primary LBRACKET expr COLON      COLON expr RBRACKET                                            { $$ = AstFactory<_HexAstSlicing>::create<HexAstSlicingEnum, HexAstPrimary, HexAstExpr, HexAstExpr, HexAstExpr>(AST_SLICING_TYPE_4, $1, $3,   NULL, $6);   }
  | primary LBRACKET expr COLON      COLON      RBRACKET                                            { $$ = AstFactory<_HexAstSlicing>::create<HexAstSlicingEnum, HexAstPrimary, HexAstExpr, HexAstExpr, HexAstExpr>(AST_SLICING_TYPE_5, $1, $3,   NULL, NULL); }
  | primary LBRACKET      COLON expr COLON expr RBRACKET                                            { $$ = AstFactory<_HexAstSlicing>::create<HexAstSlicingEnum, HexAstPrimary, HexAstExpr, HexAstExpr, HexAstExpr>(AST_SLICING_TYPE_6, $1, NULL, $4,   $6);   }
  | primary LBRACKET      COLON expr COLON      RBRACKET                                            { $$ = AstFactory<_HexAstSlicing>::create<HexAstSlicingEnum, HexAstPrimary, HexAstExpr, HexAstExpr, HexAstExpr>(AST_SLICING_TYPE_7, $1, NULL, $4,   NULL); }
  | primary LBRACKET      COLON      COLON expr RBRACKET                                            { $$ = AstFactory<_HexAstSlicing>::create<HexAstSlicingEnum, HexAstPrimary, HexAstExpr, HexAstExpr, HexAstExpr>(AST_SLICING_TYPE_8, $1, NULL, NULL, $5);   }
  | primary LBRACKET      COLON      COLON      RBRACKET                                            { $$ = AstFactory<_HexAstSlicing>::create<HexAstSlicingEnum, HexAstPrimary, HexAstExpr, HexAstExpr, HexAstExpr>(AST_SLICING_TYPE_9, $1, NULL, NULL, NULL); }
  | primary LBRACKET      COLON                 RBRACKET                                            { $$ = AstFactory<_HexAstSlicing>::create<HexAstSlicingEnum, HexAstPrimary, HexAstExpr, HexAstExpr, HexAstExpr>(AST_SLICING_TYPE_A, $1, NULL, NULL, NULL); }
  | primary LBRACKET      COLON            expr RBRACKET                                            { $$ = AstFactory<_HexAstSlicing>::create<HexAstSlicingEnum, HexAstPrimary, HexAstExpr, HexAstExpr, HexAstExpr>(AST_SLICING_TYPE_B, $1, NULL, NULL, $4);   }
  | primary LBRACKET expr                       RBRACKET                                            { $$ = AstFactory<_HexAstSlicing>::create<HexAstSlicingEnum, HexAstPrimary, HexAstExpr, HexAstExpr, HexAstExpr>(AST_SLICING_TYPE_C, $1, $3,   NULL, NULL); }
  | primary LBRACKET expr COLON                 RBRACKET                                            { $$ = AstFactory<_HexAstSlicing>::create<HexAstSlicingEnum, HexAstPrimary, HexAstExpr, HexAstExpr, HexAstExpr>(AST_SLICING_TYPE_D, $1, $3,   NULL, NULL); }
  ;

attribute_ref
  : primary DOT identifier                                                                          { $$ = AstFactory<_HexAstAttributeRef>::create<HexAstPrimary, HexAstIdentifier>($1, $3); }
  ;

call
  : primary LPAREN arg_list_or_none RPAREN                                                          { $$ = AstFactory<_HexAstCall>::create<HexAstPrimary, HexAstArgList>($1, $3); }
  ;

literal
  : integer_literal                                                                                 { $$ = $1; }
  | floating_literal                                                                                { $$ = $1; }
  | string_literal                                                                                  { $$ = $1; }
  ;

floating_literal
  : FLOAT                                                                                           { $$ = AstFactory<_HexAstFloatLiteral>::create<char*>($1); }
  ;

string_literal
  : STRING_LITERAL_SINGLE                                                                           { $$ = AstFactory<_HexAstSingleQuoteStringLiteral>::create<char*>($1); }
  | STRING_LITERAL_DOUBLE                                                                           { $$ = AstFactory<_HexAstDoubleQuoteStringLiteral>::create<char*>($1); }
  ;

integer_literal
  : DECIMALINTEGER                                                                                  { $$ = AstFactory<_HexAstDecimalIntegerLiteral>::create<char*>($1); }
  | BININTEGER                                                                                      { $$ = AstFactory<_HexAstBinaryIntegerLiteral>::create<char*>($1); }
  | OCTINTEGER                                                                                      { $$ = AstFactory<_HexAstOctalIntegerLiteral>::create<char*>($1); }
  | HEXINTEGER                                                                                      { $$ = AstFactory<_HexAstHexadecimalIntegerLiteral>::create<char*>($1); }
  ;

identifier
  : IDENTIFIER                                                                                      { $$ = AstFactory<_HexAstIdentifier>::create<char*>($1); }
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