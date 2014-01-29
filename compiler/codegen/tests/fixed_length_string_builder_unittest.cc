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

/* Unit test for compiler/codegen/fixed_length_string_builder.cc */


#include "../fixed_length_string_builder.h"
#include "../../../base/unittest.h"
#include "../../../base/assert.h"


class FixedLengthStringBuilderUnitTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    _stringbuilder = new FixedLengthStringBuilder(
      10,
      FIXED_LENGTH_STRING_ALIGNMENT_CENTER
    );
  }

  virtual void TearDown() {
    delete _stringbuilder;
  }

  void append_and_check_actual_string(
    const c_str inputString, const c_str expectedString=NULL);

  FixedLengthStringBuilder * _stringbuilder;
};

void
FixedLengthStringBuilderUnitTest::append_and_check_actual_string(
  const c_str inputString, const c_str expectedString)
{
  this->_stringbuilder->append(inputString);
  const c_str actualString = this->_stringbuilder->to_string();
  HEX_ASSERT(actualString);

  size_t expectedLength = this->_stringbuilder->max_length();
  size_t actualLength = strlen(actualString);
  ASSERT_LE(actualLength, expectedLength);

  if(expectedString) {
    ASSERT_STREQ(expectedString, actualString);
  }
}


TEST_F(FixedLengthStringBuilderUnitTest, TestInitialization)
{
  HEX_ASSERT(this->_stringbuilder);
}

TEST_F(FixedLengthStringBuilderUnitTest, TestAppendWithOverMaxLength)
{
  const c_str inputString = "This string is more than 10 characters.";
  this->append_and_check_actual_string(inputString);
}

TEST_F(FixedLengthStringBuilderUnitTest, TestTextPaddedWithWhitespace)
{
  const c_str inputString = "Hello";
  this->append_and_check_actual_string(inputString, "  Hello   ");
}

TEST_F(FixedLengthStringBuilderUnitTest, TestAppendEmptyString)
{
  const c_str inputString = "";
  this->append_and_check_actual_string(inputString, "          ");
}