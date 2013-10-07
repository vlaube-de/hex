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

#include "ast_lambda.h"
#include "ast_parameter_list.h"
#include "ast_stmt_group.h"
#include "ast_expr.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstLambda::_HexAstLambda(
  HexAstParameterList params
):_params(params)
{
  this->reprOK();
}

void
_HexAstLambda::reprOK()
{
  // Do nothing here.
}

HexAstParameterList
_HexAstLambda::params()
{
  return this->_params.get();
}

_HexAstLambdaSimple::_HexAstLambdaSimple(
  HexAstParameterList params,
  HexAstExpr expr
):_HexAstLambda(params), _expr(expr)
{
  this->reprOK();
}

void
_HexAstLambdaSimple::reprOK()
{
  HEX_ASSERT(this->expr());
}

HexAstExpr
_HexAstLambdaSimple::expr()
{
  return this->_expr.get();
}

void
_HexAstLambdaSimple::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstLambdaSimple
_HexAstLambdaSimple::create(
  HexAstParameterList params,
  HexAstExpr expr
)
{
  HEX_ASSERT(expr);

  HexAstLambdaSimple obj = new _HexAstLambdaSimple(
    params,
    expr
  );

  HEX_ASSERT(obj);

  return obj;
}

_HexAstLambdaComplex::_HexAstLambdaComplex(
  HexAstParameterList params,
  HexAstStmtGroup stmts
):_HexAstLambda(params), _stmts(stmts)
{
  this->reprOK();
}

void
_HexAstLambdaComplex::reprOK()
{
  // Do nothing here.
}

HexAstStmtGroup
_HexAstLambdaComplex::stmts()
{
  return this->_stmts.get();
}

void
_HexAstLambdaComplex::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstLambdaComplex
_HexAstLambdaComplex::create(
  HexAstParameterList params,
  HexAstStmtGroup stmts
)
{
  HexAstLambdaComplex obj = new _HexAstLambdaComplex(
    params,
    stmts
  );

  HEX_ASSERT(obj);

  return obj;
}
