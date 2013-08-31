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

#include <functional>
#include "ast_visitor.h"
#include "../../base/strbuf.h"
#include "../../base/c_str.h"

#ifndef _AST_TOSTRING_VISITOR_H_
#define _AST_TOSTRING_VISITOR_H_

class AstToStringVisitor : public AstVisitor {
public:
  AstToStringVisitor();

protected:
  Strbuf _strbuf;

  void append(c_str);

  template<typename C, typename T>
  void visit(AstListObj<C, T>, std::functional<void()>);

  std::functional<void()> _commaF;
  std::functional<void()> _dotF;
  std::functional<void()> _newlineF;
  std::functional<void()> _inputF;
  std::functional<void()> _outputF;

};

#endif /* _AST_TOSTRING_VISITOR_H_ */
