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
 * | identifiers, literals, tuples, list, dict         |     (), [], {}                                    |   left     |
 * | subscription, slicing, call, attribute reference  |                                                   |   left     |
 * | exponentiation                                    |     **                                            |   left     |
 * | positive, negative expression                     |     +, -                                          |   right    |
 * | increment, decrement                              |     ++, --                                        |   right    |
 * | bitwise not                                       |     ~                                             |   right    |
 * | existential                                       |     ?                                             |   left     |
 * | string composition                                |     %%                                            |   left     |
 * | multiplicative expression                         |     *, /, %                                       |   left     |
 * | additive expression                               |     +, -                                          |   left     |
 * | bitwise shift                                     |     <<, >>                                        |   left     |
 * | bitwise AND                                       |     &                                             |   left     |
 * | bitwise XOR                                       |     ^                                             |   left     |
 * | bitwise OR                                        |     |                                             |   left     |
 * | equality comparison                               |     ==, !=, is, is not, in, not in, >, <, >=, <=  |   left     |
 * | logical NOT                                       |     not                                           |   right    |
 * | logical AND                                       |     and                                           |   left     |
 * | logical OR                                        |     or                                            |   left     |
 * | range expression                                  |     ...                                           |   left     |
 * | conditional expression                            |     if else then                                  |   right    |
 * | input & output expression                         |     <<<, >>>                                      |   left     |
 * | yield expression                                  |     yield                                         |   left     |
 * | assignment, pseudo assignment                     |     =, +=, -=, *=, /=, %=, &=, ^=, |=, <<=, >>=   |   right    | 
 * |_______________________________________________________________________________________________________|____________|
 *
 ***********************************************************************************************************************/

#ifndef _AST_EXPR_ASSOCIATIVITY_H_
#define _AST_EXPR_ASSOCIATIVITY_H_

enum HexAstExprAssociativity {
  EXPR_ASSOCIATIVITY_LEFT  = 0x02,
  EXPR_ASSOCIATIVITY_RIGHT = 0x04
};

#endif /* _AST_EXPR_ASSOCIATIVITY_H_ */
