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

#include "ast_class_def.h"
#include "ast_compound_stmt.h"
#include "ast_name.h"
#include "ast_decorator_list.h"
#include "ast_attribute_def_list.h"
#include "ast_identifier.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstClassDef::_HexAstClassDef(
  HexAstDecoratorList decorators,
  HexAstIdentifier name,
  HexAstName parent,
  HexAstAttributeDefList attributes
):
  _decorators(decorators),
  _name(name),
  _parent(parent),
  _attributes(attributes),
  _HexAstCompoundStmt(NULL)
{
  this->reprOK();
}

void
_HexAstClassDef::reprOK()
{
  HEX_ASSERT(this->name());
}

HexAstDecoratorList
_HexAstClassDef::decorators()
{
  return this->_decorators.get();
}

HexAstIdentifier
_HexAstClassDef::name()
{
  return this->_name.get();
}

HexAstName
_HexAstClassDef::parent()
{
  return this->_parent.get();
}

HexAstAttributeDefList
_HexAstClassDef::attributes()
{
  return this->_attributes.get();
}

void
_HexAstClassDef::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstClassDef
_HexAstClassDef::create(
  HexAstDecoratorList decorators,
  HexAstIdentifier name,
  HexAstName parent,
  HexAstAttributeDefList attributes
)
{
  HEX_ASSERT(name);

  HexAstClassDef obj = new _HexAstClassDef(
    decorators,
    name,
    parent,
    attributes
  );

  HEX_ASSERT(obj);

  return obj;
}
