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

#include "ast_expr_list.h"
#include "ast_string_expr.h"
#include "ast_string_literal.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"


_HexAstStringExpr::_HexAstStringExpr(
  HexAstStringLiteral string,
  HexAstExprList exprs
):_string(string), _exprs(exprs)
{
  this->reprOK(); 
}

void
_HexAstStringExpr::reprOK()
{
  HEX_ASSERT(this->string());
  HEX_ASSERT(this->exprs());
}

HexAstStringLiteral
_HexAstStringExpr::string()
{
  return this->_string.get();
}

HexAstExprList
_HexAstStringExpr::exprs()
{
  return this->_exprs.get();
}

void
_HexAstStringExpr::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstStringExpr
_HexAstStringExpr::create(
  HexAstStringLiteral string,
  HexAstExprList exprs
)
{
  HEX_ASSERT(string);
  HEX_ASSERT(exprs);

  HexAstStringExpr obj = new _HexAstStringExpr(string, exprs);
  HEX_ASSERT(obj);
  return obj;
}
