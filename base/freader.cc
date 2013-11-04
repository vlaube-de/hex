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

#include "freader.h"
#include "assert.h"
#include "memory.h"
#include <iostream>
#include <fstream>
#include <sstream>

FileReader::FileReader(
) : _path(NULL)
{
  // Do nothing here.
}

FileReader::FileReader(
  const c_str path
) : _path((c_str)strdup(path))
{
  HEX_ASSERT(this->file_path());
}

FileReader::~FileReader()
{
  // Do nothing here.
}

const c_str
FileReader::file_path() const
{
  return this->_path.get();
}

void
FileReader::set_path(const c_str path)
{
  HEX_ASSERT(path);
  this->_path.reset(path);
}

bool
FileReader::read_file(c_str *p) const
{
  if(!this->file_path()) {
    return false;
  }

  std::ifstream file(this->file_path());
  std::stringstream buffer;

  buffer << file.rdbuf();
  file.close();

  std::string str = buffer.str();
  c_str s = (c_str)str.c_str();
  *p = strdup(s);

  return true;
}
