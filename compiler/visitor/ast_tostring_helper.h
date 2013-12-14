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
#include <boost/smart_ptr.hpp>
#include "../../base/c_str.h"

#ifndef _AST_TOSTRING_HELPER_H_
#define _AST_TOSTRING_HELPER_H_

#define DEFAULT_INDENT_SIZE 2

class AstToStringHelper {
public:
  AstToStringHelper(size_t indentSize=DEFAULT_INDENT_SIZE);
  ~AstToStringHelper();

  const c_str str();

  void append(const c_str);
  void indent();
  void dedent();
  void indentation();
  void newline();

protected:
  size_t _indentLvl;
  boost::scoped_ptr<std::string> _indentation;
  boost::scoped_ptr<std::string> _strbuf;
};

#endif /* _AST_TOSTRING_HELPER_H_ */