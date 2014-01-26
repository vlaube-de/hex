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


#include "hex_bytecode_generator.h"
#include "hex_compilation_unit_metadata.h"
#include "../ast2/ast_hex_program.h"


HexBytecodeGenerator::HexBytecodeGenerator(
  HexCompilationUnitMetadata * metadata,
  HexAstHexProgram ast
):
  _metadata(metadata),
  _ast(ast)
{
  this->check_invariance();
}

void
HexBytecodeGenerator::check_invariance()
{
  HEX_ASSERT(this->metadata());
  HEX_ASSERT(this->ast());
}

HexCompilationUnitMetadata*
HexBytecodeGenerator::metadata()
{
  return this->_metadata.get();
}

HexAstHexProgram
HexBytecodeGenerator::ast()
{
  return this->_ast.get();
}