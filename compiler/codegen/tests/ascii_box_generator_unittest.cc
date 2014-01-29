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

/* Unit test for compiler/codegen/ascii_box_generator.cc */


#include "../ascii_box_generator.h"
#include "../../../base/unittest.h"
#include "../../../base/assert.h"


class AsciiBoxGeneratorUnitTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    this->_generator = new AsciiBoxGenerator(10);
  }

  virtual void TearDown() {
    delete this->_generator;
  }

  AsciiBoxGenerator * _generator;
};

TEST_F(AsciiBoxGeneratorUnitTest, TestInitialization)
{
  HEX_ASSERT(this->_generator);
  ASSERT_EQ(10, this->_generator->width());
}

TEST_F(AsciiBoxGeneratorUnitTest, TestEmptyBox)
{
  const c_str expected_str = "+--------+\n"
                             "+--------+\n";
  const c_str actual_str = this->_generator->to_string();

  ASSERT_STREQ(expected_str, actual_str);
}

TEST_F(AsciiBoxGeneratorUnitTest, TestInsertLines)
{
  this->_generator->line();
  this->_generator->line();
  this->_generator->line();

  const c_str expected_str = "+--------+\n"
                             "|--------|\n"
                             "|--------|\n"
                             "|--------|\n"
                             "+--------+\n";
  const c_str actual_str = this->_generator->to_string();

  ASSERT_STREQ(expected_str, actual_str);
}

TEST_F(AsciiBoxGeneratorUnitTest, TestInsertOneEmptyRow)
{
  this->_generator->put_item("|", "");

  const c_str expected_str = "+--------+\n"
                             "|        |\n"
                             "+--------+\n";
  const c_str actual_str = this->_generator->to_string();

  ASSERT_STREQ(expected_str, actual_str);
}

TEST_F(AsciiBoxGeneratorUnitTest, TestInsertOneRowWithGreaterWidth)
{
  this->_generator->put_item("|", "Hello world");

  const c_str expected_str = "+--------+\n"
                             "|Hello wo|\n"
                             "+--------+\n";
  const c_str actual_str = this->_generator->to_string();

  ASSERT_STREQ(expected_str, actual_str);
}

TEST_F(AsciiBoxGeneratorUnitTest, TestInsertMultipleRows)
{
  this->_generator->put_item("|", "Hello");
  this->_generator->put_item("|", "world");
  this->_generator->line();
  this->_generator->put_item("|", "() ()");
  this->_generator->put_item("|", "(' x ')");

  const c_str expected_str = "+--------+\n"
                             "| Hello  |\n"
                             "| world  |\n"
                             "|--------|\n"
                             "| () ()  |\n"
                             "|(' x ') |\n"
                             "+--------+\n";
  const c_str actual_str = this->_generator->to_string();

  ASSERT_STREQ(expected_str, actual_str);
}

TEST_F(AsciiBoxGeneratorUnitTest, TestInsertMultipleRowsWithGreaterWidth)
{
  this->_generator->put_item("|", "Hello world");
  this->_generator->put_item("|", "Today is a good day");
  this->_generator->line();
  this->_generator->put_item("|", "An apple a day, keep the doctor away");
  this->_generator->put_item("|", "Never give up");

  const c_str expected_str = "+--------+\n"
                             "|Hello wo|\n"
                             "|Today is|\n"
                             "|--------|\n"
                             "|An apple|\n"
                             "|Never gi|\n"
                             "+--------+\n";
  const c_str actual_str = this->_generator->to_string();

  ASSERT_STREQ(expected_str, actual_str);
}