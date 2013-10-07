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

#include "ast_node.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_OPERATOR_H_
#define _AST_OPERATOR_H_

enum HexAstOperatorEnum {
  AST_OPERATOR_PLUS=0x01,
  AST_OPERATOR_MINUS=0x02,
  AST_OPERATOR_MUL=0x03,
  AST_OPERATOR_DIV=0x04,
  AST_OPERATOR_MOD=0x05,
  AST_OPERATOR_BITWISE_NOT=0x06,
  AST_OPERATOR_BITWISE_AND=0x07,
  AST_OPERATOR_BITWISE_OR=0x08,
  AST_OPERATOR_BITWISE_XOR=0x09,
  AST_OPERATOR_BITWISE_SHIFTLEFT=0x0A,
  AST_OPERATOR_BITWISE_SHIFTRIGHT=0x0B,
  AST_OPERATOR_EQ=0x0C,
  AST_OPERATOR_NEQ=0x0D,
  AST_OPERATOR_GT=0x0E,
  AST_OPERATOR_LT=0x0F,
  AST_OPERATOR_GEQ=0x10,
  AST_OPERATOR_LEQ=0x11,
  AST_OPERATOR_INC=0x12,
  AST_OPERATOR_DEC=0x13,
  AST_OPERATOR_ASSIGN_OP=0x14,
  AST_OPERATOR_ASSIGN_PLUS=0x15,
  AST_OPERATOR_ASSIGN_MINUS=0x16,
  AST_OPERATOR_ASSIGN_MUL=0x17,
  AST_OPERATOR_ASSIGN_DIV=0x18,
  AST_OPERATOR_ASSIGN_MOD=0x19,
  AST_OPERATOR_ASSIGN_BITWISE_AND=0x1A,
  AST_OPERATOR_ASSIGN_BITWISE_OR=0x1B,
  AST_OPERATOR_ASSIGN_BITWISE_XOR=0x1C,
  AST_OPERATOR_ASSIGN_SHIFTLEFT=0x1D,
  AST_OPERATOR_ASSIGN_SHIFTRIGHT=0x1E,
  AST_OPERATOR_INPUT=0x1F,
  AST_OPERATOR_OUTPUT=0x20
};

typedef class _HexAstOperator : public _HexAstNode {
public:
  _HexAstOperator(HexAstOperatorEnum);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstOperatorEnum op();

  static _HexAstOperator* create(HexAstOperatorEnum);
private:
  HexAstOperatorEnum _op;
} * HexAstOperator;

#endif /* _AST_OPERATOR_H_ */
