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
#include "fixed_length_string_builder.h"
#include "../../base/assert.h"
#include "../../base/c_str.h"

FixedLengthStringBuilder::FixedLengthStringBuilder(
  size_t maxLength,
  FixedLengthStringAlignment alignment,
  bool padWithWhitespace
):
  _maxLength(maxLength),
  _alignment(alignment),
  _padWithWhitespace(padWithWhitespace)
{
  // Do nothing here.
}

const c_str
FixedLengthStringBuilder::_to_string()
{
  return (const c_str)this->_stringbuilder.c_str();
}

const c_str
FixedLengthStringBuilder::to_string()
{
  if(!this->pad_with_whitespace()) {
    return this->_to_string();
  }

  size_t extra_size = this->max_length() - this->size();

  if(extra_size == 0) {
    return this->_to_string();
  }

  switch(this->alignment())
  {
    case FIXED_LENGTH_STRING_ALIGNMENT_LEFT:
      this->pad_whitespace_left(extra_size);
      break;
    case FIXED_LENGTH_STRING_ALIGNMENT_CENTER:
      this->pad_whitespace_center(extra_size);
      break;
    case FIXED_LENGTH_STRING_ALIGNMENT_RIGHT:
      this->pad_whitespace_right(extra_size);
      break;
    default:
      break;
  }

  return this->_to_string();
}

size_t
FixedLengthStringBuilder::size()
{
  return this->_stringbuilder.size();
}

void
FixedLengthStringBuilder::append(const c_str string)
{
  if(this->size() >= this->max_length()) {
    return;
  }

  this->_stringbuilder.append(string);

  while(this->size() > this->max_length()) {
    this->_stringbuilder.pop_back();
  }

  this->_check_size();
}

size_t
FixedLengthStringBuilder::max_length()
{
  return this->_maxLength;
}

FixedLengthStringAlignment
FixedLengthStringBuilder::alignment()
{
  return this->_alignment;
}

bool
FixedLengthStringBuilder::pad_with_whitespace()
{
  return this->_padWithWhitespace;
}

void
FixedLengthStringBuilder::_check_size()
{
  HEX_ASSERT(this->size() <= this->max_length());
}

void
FixedLengthStringBuilder::pad_whitespace_left(size_t extra_size)
{
  const c_str padding = this->get_whitespace_by_size(extra_size);
  this->_stringbuilder.insert(0, padding);
}

void
FixedLengthStringBuilder::pad_whitespace_center(size_t extra_size)
{
  size_t left_size = extra_size / 2;
  size_t right_size = extra_size - left_size;

  this->pad_whitespace_left(left_size);
  this->pad_whitespace_right(right_size);
}

void
FixedLengthStringBuilder::pad_whitespace_right(size_t extra_size)
{
  const c_str padding = this->get_whitespace_by_size(extra_size);
  this->_stringbuilder.append(padding);
}

const c_str
FixedLengthStringBuilder::get_whitespace_by_size(size_t size)
{
  std::string buf(size, ' ');
  const c_str s = (const c_str)buf.c_str();
  return strdup(s);
}