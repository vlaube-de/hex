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

#include <boost/smart_ptr.hpp>
#include "c_str.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#ifndef _FILE_READER_H_
#define _FILE_READER_H_

class FileReader {
public:
  FileReader();
  FileReader(const c_str);
  ~FileReader();

  const c_str file_path() const;
  void set_path(const c_str);

  bool read_file(c_str*) const;
protected:
  boost::scoped_ptr<char> _path;
};

#endif /* _FILE_READER_H_ */
