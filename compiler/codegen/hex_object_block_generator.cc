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
#include "ascii_box_generator.h"
#include "hex_object_block_generator.h"
#include "quadruple_instr.h"


#define DEFAULT_BLOCK_WIDTH 80

class QuadrupleInstrToStringHandler : public QuadrupleInstrHandler {
public:
  QuadrupleInstrToStringHandler(AsciiBoxGenerator * box_generator):
    _box_generator(box_generator)
  {
  }

  void operator()(quadruple_instr instr)
  {
    const c_str instr_str = QuadrupleCodeVectorGenerator::instr_to_str(instr);
    this->_box_generator->put_item("|", instr_str);
  }
private:
  AsciiBoxGenerator * _box_generator;
};

HexObjectBlockGenerator::HexObjectBlockGenerator(
  const c_str address,
  const c_str flags,
  const c_str scope_id,
  const c_str parent_scope_id,
  const c_str object_manager_id,
  QuadrupleCodeVectorGenerator * code_generator
):
  _address(address),
  _flags(flags),
  _scope_id(scope_id),
  _parent_scope_id(parent_scope_id),
  _object_manager_id(object_manager_id),
  _code_generator(code_generator)
{
  // Do nothing here.
}

HexObjectBlockGenerator::~HexObjectBlockGenerator()
{
  // Do nothing here.
}

const c_str
HexObjectBlockGenerator::address()
{
  return this->_address.get();
}

const c_str
HexObjectBlockGenerator::flags()
{
  return this->_flags.get();
}

const c_str
HexObjectBlockGenerator::scope_id()
{
  return this->_scope_id.get();
}

const c_str
HexObjectBlockGenerator::parent_scope_id()
{
  return this->_parent_scope_id.get();
}

const c_str
HexObjectBlockGenerator::object_manager_id()
{
  return this->_object_manager_id.get();
}

QuadrupleCodeVectorGenerator*
HexObjectBlockGenerator::code_generator()
{
  return this->_code_generator.get();
}

const c_str
HexObjectBlockGenerator::to_string()
{
  AsciiBoxGenerator box_generator(50);

  box_generator.put_item("|", this->address());
  box_generator.line();
  box_generator.put_item("|", this->flags());
  box_generator.line();
  box_generator.put_item("|", this->scope_id());
  box_generator.line();
  box_generator.put_item("|", this->parent_scope_id());
  box_generator.line();
  box_generator.put_item("|", this->object_manager_id());
  box_generator.line();

  QuadrupleInstrToStringHandler handler(&box_generator);
  this->code_generator()->iterate(&handler);

  return box_generator.to_string();
}