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

#include "ast_slicing.h"
#include "ast_primary.h"
#include "ast_expr_associativity.h"
#include "ast_expr_precedence.h"
#include "ast_expr.h"
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"


_HexAstSlicing::_HexAstSlicing(
  HexAstSlicingType type,
  HexAstPrimary source,
  HexAstExpr start,
  HexAstExpr step,
  HexAstExpr stop
) :
  _type(type),
  _source(source),
  _start(start),
  _step(step),
  _stop(stop),
  _HexAstPrimary(
    EXPR_ASSOCIATIVITY_LEFT,
    EXPR_PRECEDENCE_PRIMARY_2
  )
{
  this->reprOK();
}

void
_HexAstSlicing::reprOK()
{
  HEX_ASSERT(this->type());
  HEX_ASSERT(this->source());
}

HexAstSlicingType
_HexAstSlicing::type()
{
  return this->_type;
}

HexAstPrimary
_HexAstSlicing::source()
{
  return this->_source.get();
}

HexAstExpr
_HexAstSlicing::start()
{
  return this->_start.get();
}

HexAstExpr
_HexAstSlicing::step()
{
  return this->_step.get();
}

HexAstExpr
_HexAstSlicing::stop()
{
  return this->_stop.get();
}

void
_HexAstSlicing::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstSlicing
_HexAstSlicing::create(
  HexAstSlicingType type,
  HexAstPrimary source,
  HexAstExpr start,
  HexAstExpr step,
  HexAstExpr stop
)
{
  HexAstSlicing obj = new _HexAstSlicing(
    type,
    source,
    start,
    step,
    stop
  );
  HEX_ASSERT(obj);
  return obj;
}
