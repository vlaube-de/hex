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
#include <sneaker/libc/c_str.h>

#ifndef _FIXED_LENGTH_STRING_BUILDER_H_
#define _FIXED_LENGTH_STRING_BUILDER_H_

enum FixedLengthStringAlignment {
  FIXED_LENGTH_STRING_ALIGNMENT_LEFT   = 0x01,
  FIXED_LENGTH_STRING_ALIGNMENT_CENTER = 0x02,
  FIXED_LENGTH_STRING_ALIGNMENT_RIGHT  = 0x04
};

class FixedLengthStringBuilder {
public:
  FixedLengthStringBuilder(
    size_t maxLength,
    FixedLengthStringAlignment alignment,
    bool padWithWhitespace=true
  );

  const c_str to_string();
  size_t size();
  void append(const c_str);

  size_t max_length();
  FixedLengthStringAlignment alignment();
  bool pad_with_whitespace();

private:
  size_t _maxLength;
  FixedLengthStringAlignment _alignment;
  bool _padWithWhitespace;

  std::string _stringbuilder;

  void _check_size();

  const c_str _to_string();
  void pad_whitespace_left(size_t);
  void pad_whitespace_center(size_t);
  void pad_whitespace_right(size_t);
  const c_str get_whitespace_by_size(size_t);
};

#endif /* _FIXED_LENGTH_STRING_BUILDER_H_ */