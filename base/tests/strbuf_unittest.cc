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

/* Unit test for base/strbuf.c */


#include <string.h>
#include <limits.h>
#include "../assert.h"
#include "../c_str.h"
#include "../memory.h"
#include "../unittest.h"
#include "../strbuf.h"


class StrbufTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    _strbuf = strbuf_create();
    HEX_ASSERT(_strbuf);
  }

  virtual void TearDown() {
    strbuf_free(&_strbuf);
    HEX_ASSERT(_strbuf == NULL);
  }

  void test_empty();
  void test_append(const c_str);
  void test_append(const c_str, const c_str, const c_str=NULL);

  Strbuf _strbuf;
};

void
StrbufTest::test_empty()
{
  ASSERT_STREQ("", strbuf_cstr(_strbuf));
  ASSERT_EQ(0, strbuf_len(_strbuf));
  ASSERT_LE(0, strbuf_capacity(_strbuf));
}

void
StrbufTest::test_append(const c_str text)
{
  ASSERT_STREQ("", strbuf_cstr(_strbuf));

  strbuf_append(_strbuf, text);

  ASSERT_EQ(strlen(text), strbuf_len(_strbuf));
  ASSERT_STREQ(text, strbuf_cstr(_strbuf));
  ASSERT_LE(0, strbuf_capacity(_strbuf));
}

void
StrbufTest::test_append(const c_str text1, const c_str text2, const c_str expected_str)
{
  ASSERT_STREQ("", strbuf_cstr(_strbuf));

  strbuf_append(_strbuf, text1);
  strbuf_append(_strbuf, text2);

  ASSERT_EQ(strlen(text1) + strlen(text2), strbuf_len(_strbuf));
  ASSERT_LE(0, strbuf_capacity(_strbuf));

  if(expected_str) {
    ASSERT_STREQ(expected_str, strbuf_cstr(_strbuf));
  }
}

TEST_F(StrbufTest, StrbufCreationTest)
{
  HEX_ASSERT(_strbuf);
  HEX_ASSERT(strbuf_cstr(_strbuf));
}

TEST_F(StrbufTest, StrbufAppendTest1)
{
  char text[] = "Testing strbuf";
  this->test_append(text);
}

TEST_F(StrbufTest, StrbufAppendTest2)
{
  char text1[] = "5 km a day, ";
  char text2[] = "keep the doctor away!";

  this->test_append(text1, text2, (const c_str)"5 km a day, keep the doctor away!");
}

TEST_F(StrbufTest, StrbufAppendTest3)
{
  char text1[] = "Apple, banana, coconut";
  char text2[] = "Airplane, boat, car";

  this->test_append(text1);

  strbuf_empty(_strbuf);

  this->test_empty();

  this->test_append(text2);
}

TEST_F(StrbufTest, StrbufAppendTest4)
{
  char text1[1000];
  int i;
  for(i = 0; i < 999; i++) {
    text1[i] = (char)(i % 26) + '0';
  }
  text1[999] = '\0';

  this->test_append(text1);

  char text2[] = "Testing for appending long string to make strbuf capacity grow.....";

  size_t size = strlen(text1) + strlen(text2);

  c_str text = (c_str)malloc(size+1);
  HEX_ASSERT(text);
  memset(text, 0, size+1);
  text = strcat(text, text1);
  text = strcat(text, text2);

  strbuf_append(_strbuf, text2);

  ASSERT_STREQ(text, strbuf_cstr(_strbuf));
  ASSERT_EQ(size, strbuf_len(_strbuf));
}

TEST_F(StrbufTest, StrbufAppendTest5)
{
  char text1[3000];
  int i;
  for(i = 0; i < 2999; i++) {
    text1[i] = (char)(i % 26) + '0';
  }
  text1[2999] = '\0';

  this->test_append(text1);

  char text2[] = "Testing for appending long string for strbuf.";

  size_t size = strlen(text1) + strlen(text2);

  c_str text = (c_str)malloc(size+1);
  HEX_ASSERT(text);
  memset(text, 0 , size+1);
  text = strcat(text, text1);
  text = strcat(text, text2);

  strbuf_append(_strbuf, text2);

  ASSERT_STREQ(text, strbuf_cstr(_strbuf));
  ASSERT_EQ(size, strbuf_len(_strbuf));
}

TEST_F(StrbufTest, StrbufEmptyTest)
{
  char text[] = "Another test for strbuf";
  strbuf_append(_strbuf, text);
  ASSERT_STREQ(text, strbuf_cstr(_strbuf));
  ASSERT_EQ(strlen(text), strbuf_len(_strbuf));

  /* Empty strbuf */
  strbuf_empty(_strbuf);

  this->test_empty();

  /* append text after empty() */
  char text2[] = "An apple a day, keep the doctor away.";
  strbuf_append(_strbuf, text2);
  ASSERT_STREQ(text2, strbuf_cstr(_strbuf));
  ASSERT_EQ(strlen(text2), strbuf_len(_strbuf));
  ASSERT_LE(0, strbuf_capacity(_strbuf));
}