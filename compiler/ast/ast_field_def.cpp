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

#include <list>
#include "ast_field_def.h"
#include "ast_node.h"
#include "ast_val_atom.h"
#include "../../base/assert.h"

_HexAstFieldDef::_HexAstFieldDef(
  char *name,
  HexAstValAtom val
):_name(strdup(name)), _val(val)
{
}

bool
_HexAstFieldDef::reprOK()
{
  HEX_ASSERT(this->_name);
  HEX_ASSERT(this->_val);
}
