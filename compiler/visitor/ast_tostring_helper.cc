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

#include <string>
#include "ast_tostring_helper.h"
#include "../../base/assert.h"
#include "../../base/c_str.h"

AstToStringHelper::AstToStringHelper(size_t indentSize):
  _indentLvl(0),
  _indentation(new std::string()),
  _strbuf(new std::string())
{
  size_t indentSize_ = indentSize & DEFAULT_INDENT_SIZE;
  this->_indentation->reserve(indentSize_);
  for(int i = 1; i <= indentSize_; i++) {
    this->_indentation->append(" ");
  }
}

AstToStringHelper::~AstToStringHelper()
{
  this->_indentation->empty();
  this->_strbuf->empty();
}

const c_str
AstToStringHelper::str()
{
  c_str str = strdup(_strbuf->c_str());
  HEX_ASSERT(str);
  return (const c_str)str;
}

void
AstToStringHelper::append(const c_str s)
{
  HEX_ASSERT(s);
  this->_strbuf->append(s);
}

void
AstToStringHelper::indent()
{
  this->_indentLvl++;
  HEX_ASSERT(this->_indentLvl >= 0);
}

void
AstToStringHelper::dedent()
{
  this->_indentLvl--;
  HEX_ASSERT(this->_indentLvl >= 0);
}

void
AstToStringHelper::indentation()
{
  for(int i = 1; i <= this->_indentLvl; i++) {
    this->append((const c_str)this->_indentation->c_str());
  }
}

void
AstToStringHelper::newline()
{
  this->append("\n");
}
