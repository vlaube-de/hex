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
#include "ast_typed.h"
#include "../../base/assert.h"

_HexAstUsingStmtDirect::_HexAstUsingStmtDirect(
  HexAstName target,
  HexAstIdentifier alias
):_target(target), _alias(alias)
{
  this->reprOK();
}

bool
_HexAstUsingStmtDirect::reprOK()
{
  HEX_ASSERT(this->_target);
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
  HexAstIdentifier alias,
  ast_type_t type
):_targets(targets), _src(src), _alias(alias), AstTyped(type)
{
  this->reprOK();
}

bool
_HexAstUsingStmtRelative::reprOK()
{
  HEX_ASSERT(this->_src);
  HEX_ASSERT(this->_type);
  if(this->_type==AST_USING_STMT_RELATIVE_TARGET) {
    HEX_ASSERT(this->_targets);
  }
}

HexAstUsingStmtRelative
_HexAstUsingStmtRelative::create(
  HexAstTargetList targets,
  HexAstUsingSrc src,
  HexAstIdentifier alias,
  ast_type_t type
)
{
  HEX_ASSERT(src);
  HEX_ASSERT(type);

  HexAstUsingStmtRelative obj = new _HexAstUsingStmtRelative(
    targets,
    src,
    alias,
    type
  );

  HEX_ASSERT(obj);

  return obj;
}
