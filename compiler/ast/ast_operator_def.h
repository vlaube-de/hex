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

#include "ast_attribute_def.h"
#include "ast_operator.h"
#include "ast_lambda.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_OPERATOR_DEF_H_
#define _AST_OPERATOR_DEF_H_

typedef class _HexAstOperatorDef : public _HexAstAttributeDef {
public:
  _HexAstOperatorDef(HexAstOperator op, HexAstLambda);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstOperator op();
  HexAstLambda lambda();

  static _HexAstOperatorDef* create(HexAstOperator, HexAstLambda);
private:
  HexAstOperator _op;
  HexAstLambda _lambda;
} * HexAstOperatorDef;

#endif /* _AST_OPERATOR_DEF_H_ */
