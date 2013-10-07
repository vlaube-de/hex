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

#include "ast_using_stmt.h"
#include "ast_using_src.h"
#include "ast_node.h"
#include "ast_target_list.h"
#include "ast_identifier.h"
#include "ast_name.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstUsingStmtDirect::_HexAstUsingStmtDirect(
  HexAstName target,
  HexAstIdentifier alias
):_target(target), _alias(alias)
{
  this->reprOK();
}

void
_HexAstUsingStmtDirect::reprOK()
{
  HEX_ASSERT(this->_target);
}

HexAstName
_HexAstUsingStmtDirect::target()
{
  return this->_target.get();
}

HexAstIdentifier
_HexAstUsingStmtDirect::alias()
{
  return this->_alias.get();
}

void
_HexAstUsingStmtDirect::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstUsingStmtDirect
_HexAstUsingStmtDirect::create(
  HexAstName target,
  HexAstIdentifier alias
)
{
  HEX_ASSERT(target);

  HexAstUsingStmtDirect obj = new _HexAstUsingStmtDirect(target, alias);
  HEX_ASSERT(obj);
  return obj;
}

_HexAstUsingStmtRelative::_HexAstUsingStmtRelative(
  HexAstTargetList targets,
  HexAstUsingSrc src,
  HexAstIdentifier alias
):_targets(targets), _src(src), _alias(alias)
{
  this->reprOK();
}

void
_HexAstUsingStmtRelative::reprOK()
{
  HEX_ASSERT(this->src());
}

HexAstTargetList
_HexAstUsingStmtRelative::targets()
{
  return this->_targets.get();
}

HexAstUsingSrc
_HexAstUsingStmtRelative::src()
{
  return this->_src.get();
}

HexAstIdentifier
_HexAstUsingStmtRelative::alias()
{
  return this->_alias.get();
}

void
_HexAstUsingStmtRelative::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstUsingStmtRelative
_HexAstUsingStmtRelative::create(
  HexAstTargetList targets,
  HexAstUsingSrc src,
  HexAstIdentifier alias
)
{
  HEX_ASSERT(src);

  HexAstUsingStmtRelative obj = new _HexAstUsingStmtRelative(
    targets,
    src,
    alias
  );

  HEX_ASSERT(obj);

  return obj;
}
