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
#include "ascii_box_generator.h"
#include "fixed_length_string_builder.h"

#define BOX_DEFAULT_ALIGNMENT FIXED_LENGTH_STRING_ALIGNMENT_CENTER

AsciiBoxGenerator::AsciiBoxGenerator(size_t width):
  _width(width)
{
  this->_actualWidth = this->width() - 2;
  this->_top_or_bottom();
}

AsciiBoxGenerator::AsciiBoxGenerator(AsciiBoxGenerator & other)
{
  this->_width = other.width();
  this->_actualWidth = this->width() - 2;
  this->_top_or_bottom();
}

size_t
AsciiBoxGenerator::width()
{
  return this->_width;
}

void
AsciiBoxGenerator::_append(const c_str str)
{
  this->_stringbuilder.append(str);
}

void
AsciiBoxGenerator::_put(char c)
{
  this->_stringbuilder.push_back(c);
}

void
AsciiBoxGenerator::_newline()
{
  this->_put('\n');
}

void
AsciiBoxGenerator::_top_or_bottom()
{
  std::string buf(this->_actualWidth, '-');
  this->put_item("+", (const c_str)buf.c_str());
}

void
AsciiBoxGenerator::line()
{
  std::string buf(this->_actualWidth, '-');
  this->put_item("|", (const c_str)buf.c_str());
}

void
AsciiBoxGenerator::put_item(const c_str side, const c_str str)
{
  FixedLengthStringBuilder sb(this->_actualWidth, BOX_DEFAULT_ALIGNMENT);
  sb.append(str);

  this->_append(side);
  this->_stringbuilder.append(sb.to_string());
  this->_append(side);
  this->_newline();
}

const c_str
AsciiBoxGenerator::to_string()
{
  this->_top_or_bottom();
  return (const c_str)this->_stringbuilder.c_str();
}