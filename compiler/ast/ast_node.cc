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


#include "ast_node.h"
#include "../../base/assert.h"


_HexAstNode::_HexAstNode()
{
}

void*
_HexAstNode::simplify()
{
  return this;
}

void*
_HexAstNode::standardize()
{
  return this;
}

bool
_HexAstNode::reprOK()
{
  return true;
}

bool
_HexAstNode::equal(void*)
{
  return false;
}

bool
_HexAstNode::isomorphic(void*)
{
  return false;
}

bool
_HexAstNode::equivalent(void*)
{
  return  false;
}
