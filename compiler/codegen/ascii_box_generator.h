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

#ifndef _ASCII_BOX_GENERATOR_H_
#define _ASCII_BOX_GENERATOR_H_

class AsciiBoxGenerator {
public:
  AsciiBoxGenerator(size_t width);
  AsciiBoxGenerator(AsciiBoxGenerator&);

  size_t width();

  void line();
  void put_item(const c_str, const c_str);
  const c_str to_string();

private:
  size_t _width;
  size_t _actualWidth;

  std::string _stringbuilder;

  void _append(const c_str);
  void _put(char);
  void _newline();
  void _top_or_bottom();
};

#endif /* _ASCII_BOX_GENERATOR_H_ */