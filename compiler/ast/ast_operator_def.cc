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

#include "ast_operator_def.h"
#include "ast_operator.h"
#include "ast_lambda.h"
#include "ast_operator.h"
#include "../../base/assert.h"

_HexAstOperatorDef::_HexAstOperatorDef(
  HexAstOperator op,
  HexAstLambda lambda
):_op(op), _lambda(lambda)
{
  this->reprOK();
}

bool
_HexAstOperatorDef::reprOK()
{
  HEX_ASSERT(this->_op);
  HEX_ASSERT(this->_lambda);
}

HexAstOperatorDef
_HexAstOperatorDef::create(
  HexAstOperator op,
  HexAstLambda lambda
)
{
  HEX_ASSERT(op);
  HEX_ASSERT(lambda);

  HexAstOperatorDef obj = new _HexAstOperatorDef(op, lambda);

  HEX_ASSERT(obj);

  return obj;
}
