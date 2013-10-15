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


/************************************************************************************************************************
 *
 * |-------------------------------------------------------------------------------------------------------|------------|
 * |                   HEX expression precedence (precedence decreases as list goes down)                  |            |
 * |-------------------------------------------------------------------------------------------------------|------------|
 * | Description                                       |    Operator                                       |   Level    |
 * |---------------------------------------------------|---------------------------------------------------|------------|
 * | identifiers, literals, tuples, list, dict         |     (), [], {}                                    |    0x17    |
 * | subscription, slicing, call, attribute reference  |                                                   |    0x16    |
 * | exponentiation                                    |     **                                            |    0x15    |
 * | positive, negative expression                     |     +, -                                          |    0x14    |
 * | increment, decrement                              |     ++, --                                        |    0x13    |
 * | bitwise not                                       |     ~                                             |    0x12    |
 * | existential                                       |     ?                                             |    0x11    |
 * | string composition                                |     %%                                            |    0x10    |
 * | multiplicative expression                         |     *, /, %                                       |    0x0F    |
 * | additive expression                               |     +, -                                          |    0x0E    |
 * | bitwise shift                                     |     <<, >>                                        |    0x0D    |
 * | bitwise AND                                       |     &                                             |    0x0C    |
 * | bitwise XOR                                       |     ^                                             |    0x0B    |
 * | bitwise OR                                        |     |                                             |    0x0A    |
 * | equality comparison                               |     ==, !=, is, is not, in, not in, >, <, >=, <=  |    0x09    |
 * | logical NOT                                       |     not                                           |    0x08    |
 * | logical AND                                       |     and                                           |    0x07    |
 * | logical OR                                        |     or                                            |    0x06    |
 * | range expression                                  |     ...                                           |    0x05    |
 * | conditional expression                            |     if else then                                  |    0x04    |
 * | input & output expression                         |     <<<, >>>                                      |    0x03    |
 * | yield expression                                  |     yield                                         |    0x02    |
 * | assignment, pseudo assignment                     |     =, +=, -=, *=, /=, %=, &=, ^=, |=, <<=, >>=   |    0x01    |
 * |_______________________________________________________________________________________________________|____________|
 *
 *       The order of the list should the REVERSE of the order of these tokens defined in parser.y
 *
 ***********************************************************************************************************************/

#ifndef _AST_EXPR_PRECEDENCE_H_
#define _AST_EXPR_PRECEDENCE_H_

enum HexAstExprPrecedence {
  EXPR_PRECEDENCE_PRIMARY_1           = 0x17,
  EXPR_PRECEDENCE_PRIMARY_2           = 0x16,
  EXPR_PRECEDENCE_EXPONENTIATION      = 0x15,
  EXPR_PRECEDENCE_UNARY_1             = 0x14,
  EXPR_PRECEDENCE_UNARY_2             = 0x13,
  EXPR_PRECEDENCE_BITWISE_NOT         = 0x12,
  EXPR_PRECEDENCE_EXISTENTIAL         = 0x11,
  EXPR_PRECEDENCE_STRING_COMPOSITION  = 0x10,
  EXPR_PRECEDENCE_MULTIPLICATIVE_EXPR = 0x0F,
  EXPR_PRECEDENCE_ADDITIVE_EXPR       = 0x0E,
  EXPR_PRECEDENCE_BITWISE_SHIFT       = 0x0D,
  EXPR_PRECEDENCE_BITWISE_AND         = 0x0C,
  EXPR_PRECEDENCE_BITWISE_XOR         = 0x0B,
  EXPR_PRECEDENCE_BITWISE_OR          = 0x0A,
  EXPR_PRECEDENCE_EQUALITY            = 0x09,
  EXPR_PRECEDENCE_LOGICAL_NOT         = 0x08,
  EXPR_PRECEDENCE_LOGICAL_AND         = 0x07,
  EXPR_PRECEDENCE_LOGICAL_OR          = 0x06,
  EXPR_PRECEDENCE_RANGE_EXPR          = 0x05,
  EXPR_PRECEDENCE_CONDITIONAL_EXPR    = 0x04,
  EXPR_PRECEDENCE_IO_EXPR             = 0x03,
  EXPR_PRECEDENCE_YIELD_EXPR          = 0x02,
  EXPR_PRECEDENCE_ASSIGNMENT          = 0x01
};

#endif /* _AST_EXPR_PRECEDENCE_H_ */
