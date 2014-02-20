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
#include <sneaker/libc/assert.h>
#include "ast_expr.h"
#include "ast_reference.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_SLICING_H_
#define _AST_SLICING_H_

enum HexAstSlicingEnum {
  AST_SLICING_TYPE_1 = 0x01,
  AST_SLICING_TYPE_2 = 0x02,
  AST_SLICING_TYPE_3 = 0x03,
  AST_SLICING_TYPE_4 = 0x04,
  AST_SLICING_TYPE_5 = 0x05,
  AST_SLICING_TYPE_6 = 0x06,
  AST_SLICING_TYPE_7 = 0x07,
  AST_SLICING_TYPE_8 = 0x08,
  AST_SLICING_TYPE_9 = 0x09,
  AST_SLICING_TYPE_A = 0x0A,
  AST_SLICING_TYPE_B = 0x0B,
  AST_SLICING_TYPE_C = 0x0C,
  AST_SLICING_TYPE_D = 0x0D
};

typedef class _HexAstSlicing : public _HexAstReference {
public:
  _HexAstSlicing(
    HexAstSlicingEnum type,
    HexAstPrimary source,
    HexAstExpr start,
    HexAstExpr step,
    HexAstExpr stop
  ):
    _type(type),
    _source(source),
    _start(start),
    _step(step),
    _stop(stop),
    _HexAstReference(
      EXPR_ASSOCIATIVITY_LEFT,
      EXPR_PRECEDENCE_PRIMARY_2
    )
  {
    this->reprOK();
  }

  virtual void reprOK() {
    ASSERT(this->type());
    ASSERT(this->source());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstSlicingEnum type() { return this->_type; }
  HexAstPrimary source() { return this->_source.get(); }
  HexAstExpr start() { return this->_start.get(); }
  HexAstExpr step() { return this->_step.get(); }
  HexAstExpr stop() { return this->_stop.get(); }

private:
  HexAstSlicingEnum _type;
  boost::scoped_ptr<_HexAstPrimary> _source;
  boost::scoped_ptr<_HexAstExpr> _start;
  boost::scoped_ptr<_HexAstExpr> _step;
  boost::scoped_ptr<_HexAstExpr> _stop;
} * HexAstSlicing;

#endif /* _AST_SLICING_H_ */