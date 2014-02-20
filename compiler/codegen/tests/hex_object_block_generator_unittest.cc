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

/* Unit test for compiler/codegen/hex_object_block_generator.cc */

#include <sneaker/libc/assert.h>
#include <sneaker/libc/c_str.h>
#include <sneaker/testing/_unittest.h>
#include "../hex_object_block_generator.h"
#include "../quadruple_code_vector_generator.h"


class HexObjectBlockGeneratorUnitTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    this->_code_generator = new QuadrupleCodeVectorGenerator();
    this->_code_generator->append(NULL, "add", "op1", "op2");
    this->_code_generator->append("label1", "jmp", "0x01", NULL);

    this->_generator = new HexObjectBlockGenerator(
      _address,
      _flags,
      _scope_id,
      _parent_scope_id,
      _object_manager_id,
      _code_generator
    );
  }

  virtual void TearDown() {
    delete this->_code_generator;
    delete this->_generator;
  }

  const c_str _address = "0x00000001";
  const c_str _flags = "0x01";
  const c_str _scope_id = "2";
  const c_str _parent_scope_id = "1";
  const c_str _object_manager_id = "5";
  QuadrupleCodeVectorGenerator * _code_generator;
  HexObjectBlockGenerator * _generator;
};

TEST_F(HexObjectBlockGeneratorUnitTest, TestInitialization)
{
  ASSERT(this->_generator);

  ASSERT_STREQ(_address, this->_generator->address());
  ASSERT_STREQ(_flags, this->_generator->flags());
  ASSERT_STREQ(_scope_id, this->_generator->scope_id());
  ASSERT_STREQ(_parent_scope_id, this->_generator->parent_scope_id());
  ASSERT_STREQ(_object_manager_id, this->_generator->object_manager_id());
  ASSERT_EQ(this->_code_generator, this->_generator->code_generator());
}

TEST_F(HexObjectBlockGeneratorUnitTest, TestGeneratorStringRepresentation)
{
  const c_str expected_str =  \
    "+------------------------------------------------+\n"
    "|                   0x00000001                   |\n"
    "|------------------------------------------------|\n"
    "|                      0x01                      |\n" 
    "|------------------------------------------------|\n"
    "|                       2                        |\n"
    "|------------------------------------------------|\n"
    "|                       1                        |\n"
    "|------------------------------------------------|\n"
    "|                       5                        |\n"
    "|------------------------------------------------|\n"
    "|                  add op1 op2                   |\n"
    "|                label1: jmp 0x01                |\n"
    "+------------------------------------------------+\n";

  const c_str actual_str = this->_generator->to_string();

  ASSERT_STREQ(expected_str, actual_str);
}