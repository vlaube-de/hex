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

#include "ast_catch_stmt.h"
#include "ast_compound_stmt.h"
#include "ast_target_list.h"
#include "ast_stmt_group.h"
#include "ast_identifier.h"
#include "../../base/assert.h"

_HexAstCatchStmt::_HexAstCatchStmt(
  HexAstTargetList targets,
  HexAstIdentifier alias,
  HexAstStmtGroup stmts
):_targets(targets), _alias(alias), _HexAstCompoundStmt(stmts)
{
  this->reprOK();
}

bool
_HexAstCatchStmt::reprOK()
{
  return true;
}

HexAstCatchStmt
_HexAstCatchStmt::create(
  HexAstTargetList targets,
  HexAstIdentifier alias,
  HexAstStmtGroup stmts
)
{
  HexAstCatchStmt obj = new _HexAstCatchStmt(
    targets,
    alias,
    stmts
  );

  HEX_ASSERT(obj);

  return obj;
}
