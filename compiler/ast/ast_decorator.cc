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

#include "ast_decorator.h"
#include "ast_name.h"
#include "ast_arg_list.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstDecorator::_HexAstDecorator(
  HexAstName name,
  HexAstArgList args
):_name(name), _args(args)
{
  this->reprOK();
}

bool
_HexAstDecorator::reprOK()
{
  HEX_ASSERT(this->_name);
}

HexAstName
_HexAstDecorator::name()
{
  return this->_name;
}

HexAstArgList
_HexAstDecorator::args()
{
  return this->_args;
}

void
_HexAstDecorator::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstDecorator
_HexAstDecorator::create(
  HexAstName name,
  HexAstArgList args
)
{
  HEX_ASSERT(name);

  HexAstDecorator obj = new _HexAstDecorator(
    name,
    args
  );

  HEX_ASSERT(obj);

  return obj;
}
