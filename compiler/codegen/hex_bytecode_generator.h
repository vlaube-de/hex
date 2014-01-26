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

/*
 * This is the top level object responsible for generating
 * the compiled bytecode for a .hex input module.
 *
 * This class is responsible for taking an AST as input and
 * generate the compiled bytecode for the entire compilation unit.
 */

#include <boost/smart_ptr.hpp>
#include "hex_compilation_unit_metadata.h"
#include "../ast2/ast_hex_program.h"

#ifndef _HEX_BYTECODE_GENERATOR_H_
#define _HEX_BYTECODE_GENERATOR_H_

class HexBytecodeGenerator {
public:
  HexBytecodeGenerator(HexCompilationUnitMetadata*, HexAstHexProgram);

  HexCompilationUnitMetadata* metadata();
  HexAstHexProgram ast();

private:
  boost::scoped_ptr<HexCompilationUnitMetadata> _metadata;
  boost::scoped_ptr<_HexAstHexProgram> _ast;

  void check_invariance();
};

#endif /* _HEX_BYTECODE_GENERATOR_H_ */