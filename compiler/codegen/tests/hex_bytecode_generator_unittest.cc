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

/* Unit test for compiler/codegen/hex_bytecode_generator.cc */

#include "../hex_bytecode_generator.h"
#include "../hex_compilation_unit_metadata.h"
#include "../../ast/ast.h"
#include "../../../base/unittest.h"
#include "../../../base/assert.h"


class HexBytecodeGeneratorUnitTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    _ast = _HexAstHexProgram::create(NULL);
    _metadata = new HexCompilationUnitMetadata();
    _generator = new HexBytecodeGenerator(_metadata, _ast);
  }

  virtual void TearDown() {
    delete _generator;
  }

  HexAstHexProgram _ast;
  HexCompilationUnitMetadata * _metadata;
  HexBytecodeGenerator * _generator;
};


TEST_F(HexBytecodeGeneratorUnitTest, TestInitialization)
{
  HEX_ASSERT(this->_generator);
  ASSERT_EQ(this->_ast, this->_generator->ast());
  ASSERT_EQ(this->_metadata, this->_generator->metadata());
}