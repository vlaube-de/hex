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

/* Unit test for compiler/codegen/quadruple_code_vector_generator.cc */


#include <vector>
#include "../quadruple_code_vector_generator.h"
#include "../quadruple_instr.h"
#include "../../../base/unittest.h"
#include "../../../base/assert.h"


class QuadrupleCodeVectorGeneratorUnitTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    this->_generator = new QuadrupleCodeVectorGenerator();
  }

  virtual void Teardown() {
    delete this->_generator;
  }

  void check_code_vector(std::vector<quadruple_instr>&);

  QuadrupleCodeVectorGenerator * _generator;
};

class QuadrupleInstrHandlerForUnitTest : public QuadrupleInstrHandler {
public:
  QuadrupleInstrHandlerForUnitTest(
    std::vector<quadruple_instr> & expected_code_vector
  )
  {
    _expected_code_vector = & expected_code_vector;
  }

  void operator()(quadruple_instr actual_instr)
  {
    quadruple_instr expected_instr = _expected_code_vector->at(_index);

    ASSERT_EQ(expected_instr.get<0>(), actual_instr.get<0>());
    ASSERT_EQ(expected_instr.get<1>(), actual_instr.get<1>());
    ASSERT_EQ(expected_instr.get<2>(), actual_instr.get<2>());
    ASSERT_EQ(expected_instr.get<3>(), actual_instr.get<3>());

    _index++;
  }
private:
  int _index=0;
  std::vector<quadruple_instr> * _expected_code_vector;
};

void
QuadrupleCodeVectorGeneratorUnitTest::check_code_vector(
  std::vector<quadruple_instr> & expected_code_vector
)
{
  QuadrupleInstrHandlerForUnitTest * handler = \
    new QuadrupleInstrHandlerForUnitTest(expected_code_vector);

  this->_generator->iterate(handler);
}

TEST_F(QuadrupleCodeVectorGeneratorUnitTest, TestInitialization)
{
  HEX_ASSERT(this->_generator);
  ASSERT_EQ(0, this->_generator->size());
}

TEST_F(QuadrupleCodeVectorGeneratorUnitTest, TestAppendOneInstr)
{
  this->_generator->append("label1", "add", "op1", "op2");
  ASSERT_EQ(1, this->_generator->size());

  std::vector<quadruple_instr> expected_code_vector = {
    quadruple_instr("label1", "add", "op1", "op2")
  };

  this->check_code_vector(expected_code_vector);
}

TEST_F(QuadrupleCodeVectorGeneratorUnitTest, TestAppendMultipleInstrs)
{
  this->_generator->append("label1", "add", "op1", "op2");
  this->_generator->append(NULL, "add", "op1", "op2");
  this->_generator->append(NULL, "jmp", "0x01", NULL);

  ASSERT_EQ(3, this->_generator->size());

  std::vector<quadruple_instr> expected_code_vector = {
    quadruple_instr("label1", "add", "op1", "op2"),
    quadruple_instr(NULL, "add", "op1", "op2"),
    quadruple_instr(NULL, "jmp", "0x01", NULL)
  };

  this->check_code_vector(expected_code_vector);
}