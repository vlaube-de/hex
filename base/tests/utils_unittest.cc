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

/* Unit test for base/utils.c */


#include <string.h>
#include "../unittest.h"
#include "../memory.h"
#include "../utils.h"
#include "../assert.h"


/*******************************************
 * Tests for MAX(a,b)
 *******************************************/
TEST(MaxTest, MaxOfPositiveInteger) {
  EXPECT_EQ(6, MAX(5,6));
  EXPECT_EQ(6, MAX(0,6));
}

TEST(MaxTest, MaxOfNegativeInteger) {
  EXPECT_EQ(-5, MAX(-5,-6));
  EXPECT_EQ(0, MAX(-5,0));
}

TEST(MaxTest, MaxOfPositiveFloatingNumber) {
  EXPECT_EQ(880.0f, MAX(0.2f, 880.0f));
  EXPECT_EQ(0.1f, MAX(0.0f, 0.1f));
}

TEST(MaxTest, MaxOfNegativeFloatingNumber) {
  EXPECT_EQ(-5.0f, MAX(-5.0f, -6.0f));
  EXPECT_EQ(0.0f, MAX(-5.0f, 0.0f));
}


/*******************************************
 * Tests for MIN(a,b)
 *******************************************/
TEST(MinTest, MinOfPositiveInteger) {
  EXPECT_EQ(5, MIN(5,6));
  EXPECT_EQ(0, MIN(5,0));
}

TEST(MinTest, MinOfNegativeInteger) {
  EXPECT_EQ(-6, MIN(-5, -6));
  EXPECT_EQ(-6, MIN(0, -6));
}

TEST(MinTest, MinOfPositiveFloatingNumber) {
  EXPECT_EQ(5.0f, MIN(5.0f, 6.0f));
  EXPECT_EQ(0.0f, MIN(0.0f, 5.0f));
}

TEST(MinTest, MinOfNegativeFloatingNumber) {
  EXPECT_EQ(-6.0f, MIN(-5.0f, -6.0f));
  EXPECT_EQ(-6.0f, MIN(0.0f, -6.0f));
}

/*******************************************
 * Tests for:
 * RETURN_IF_NULL(val)
 *******************************************/
TEST(RETURN_IF_NULLTest, PassNullTest) {
  char *val = NULL;
  RETURN_IF_NULL(val);
  ASSERT_EQ(1, 2);
}

TEST(RETURN_IF_NULLTest, PassNotNullTest) {
  char *val = (char*)malloc(sizeof(char));
  ASSERT_TRUE(val != NULL);
  RETURN_IF_NULL(val);
  free(val);
}

/*******************************************
 * Tests for:
 * RETURN_IF_TRUE(val)
 *******************************************/
TEST(RETURN_IF_TRUETest, PassTrueTest) {
  int val = 1 == 1;
  RETURN_IF_TRUE(val);
  ASSERT_EQ(1,2);
}

TEST(RETURN_IF_TRUETest, PassFalseTest) {
  int val = 1 == 2;
  RETURN_IF_TRUE(val);
  ASSERT_EQ(1, 1);
}

/*******************************************
 * Tests for:
 * RETURN_IF_FALSE(val)
 *******************************************/
TEST(RETURN_IF_FALSETest, PassTrueTest) {
  int val = 1 == 1;
  RETURN_IF_FALSE(val);
  ASSERT_EQ(1, 1);
}

TEST(RETURN_IF_FALSETest, PassFalseTest) {
  int val = 1 == 2;
  RETURN_IF_FALSE(val);
  ASSERT_EQ(1, 2);
}

/*******************************************
 * Tests for:
 * RETURN_IF_EQUALS(val1, val2)
 *******************************************/
TEST(RETURN_IF_EQUALSTest, PassTrueTest) {
  int val1 = 1;
  int val2 = 1;
  RETURN_IF_EQUALS(val1, val2);
  ASSERT_EQ(1, 2);
}

TEST(RETURN_IF_EQUALSTest, PassFalseTest) {
  int val1 = 1;
  int val2 = 2;
  RETURN_IF_EQUALS(val1, val2);
  ASSERT_EQ(1, 1);
}

/*******************************************
 * Tests for:
 * void set_nth_bit(int *val, char bit) 
 *******************************************/
TEST(set_nth_bitTest, Set1stBit) {
  int val=0;
  set_nth_bit(&val, 1);
  EXPECT_EQ(0x00000001, val);
}

TEST(set_nth_bitTest, Set2ndBit) {
  int val=0;
  set_nth_bit(&val, 2);
  EXPECT_EQ(0x00000002, val);
}

TEST(set_nth_bitTest, Set4thBit) {
  int val=0;
  set_nth_bit(&val, 4);
  EXPECT_EQ(0x000000008, val);
}

TEST(set_nth_bitTest, Set8thBit) {
  int val=0;
  set_nth_bit(&val, 8);
  EXPECT_EQ(128, val);
}

TEST(set_nth_bitTest, Set16thBit) {
  int val=0;
  set_nth_bit(&val, 16);
  EXPECT_EQ(32768, val);
}

TEST(set_nth_bitTest, Set32thBit) {
  int val=0;
  set_nth_bit(&val, 32);
  unsigned int val2 = 1;
  val2 <<= 31;

  EXPECT_EQ((int)((val2)*(-1)), val);
}


/*******************************************
 * Tests for:
 * void clear_nth_bit(int *val, char bit) 
 *******************************************/
TEST(clear_nth_bitTest, Clear1stBit) {
  int val=0x00001;
  clear_nth_bit(&val, 1);
  EXPECT_EQ(0, val);
}

TEST(clear_nth_bitTest, Clear2ndBit) {
  int val=0x0002;
  clear_nth_bit(&val, 2);
  EXPECT_EQ(0, val);
}

TEST(clear_nth_bitTest, Clear4thBit) {
  int val=0x0008;
  clear_nth_bit(&val, 4);
  EXPECT_EQ(0, val);
}

TEST(clear_nth_bitTest, Clear8thBit) {
  int val=128;
  clear_nth_bit(&val, 8);
  EXPECT_EQ(0, val);
}

TEST(clear_nth_bitTest, Clear16thBit) {
  int val=32768;
  clear_nth_bit(&val, 16);
  EXPECT_EQ(0, val);
}

TEST(clear_nth_bitTest, Clear32thBit) {
  int val=0;
  unsigned int val2 = 1;
  val2 <<= 31;
  val = val2 * (-1);
  clear_nth_bit(&val, 32);
  EXPECT_EQ(0, val);
}


/*******************************************
 * Tests for:
 * void is_bit_set(int val, char bit) 
 *******************************************/
TEST(is_bit_setTest, TestBitSetOnZeroValueInteger) {
  int val=0;
  EXPECT_FALSE(is_bit_set(val, 1));
}

TEST(is_bit_setTest, TestSetOn1stBit) {
  int val=1;
  EXPECT_TRUE(is_bit_set(val, 1));
}

TEST(is_bit_setTest, TestSetOn2ndBit) {
  int val=2;
  EXPECT_FALSE(is_bit_set(val, 1));
  EXPECT_TRUE(is_bit_set(val, 2));
}

TEST(is_bit_setTest, TestSetOn4thBit) {
  int val=8;
  EXPECT_FALSE(is_bit_set(val, 1));
  EXPECT_FALSE(is_bit_set(val, 2));
  EXPECT_TRUE(is_bit_set(val, 4));
}

TEST(is_bit_setTest, TestSetOn8thBit) {
  int val=128;
  EXPECT_FALSE(is_bit_set(val, 1));
  EXPECT_FALSE(is_bit_set(val, 2));
  EXPECT_FALSE(is_bit_set(val, 4));
  EXPECT_TRUE(is_bit_set(val, 8));
}

TEST(is_bit_setTest, TestSetOn16thBit) {
  int val=32768;
  EXPECT_FALSE(is_bit_set(val, 1));
  EXPECT_FALSE(is_bit_set(val, 2));
  EXPECT_FALSE(is_bit_set(val, 4));
  EXPECT_FALSE(is_bit_set(val, 8));
  EXPECT_TRUE(is_bit_set(val, 16));
}

TEST(is_bit_setTest, TestSetOn32thBit) { 
  int val=0;
  unsigned int val2 = 1;
  val2 <<= 31;
  val = val2 * (-1); 
  EXPECT_FALSE(is_bit_set(val, 1));
  EXPECT_FALSE(is_bit_set(val, 2));
  EXPECT_FALSE(is_bit_set(val, 4));
  EXPECT_FALSE(is_bit_set(val, 8));
  EXPECT_FALSE(is_bit_set(val, 16));
  EXPECT_TRUE(is_bit_set(val, 32));
}

/*******************************************
 * Tests for:
 * hex_rand_top(int top)
 *******************************************/
TEST(hex_rand_topTest, hex_rand_topTest) {
  int i;
  for(i = 1; i <= 5000; i++) {
    ASSERT_LE(hex_rand_top(i), i);
  }
}

/*******************************************
 * Tests for:
 * hex_rand_range(int min, int max)
 *******************************************/
TEST(hex_rand_rangeTest, hex_rand_rangeTest) {
  int i;
  int min = 20;
  for(i = min; i <= 5000; i++) {
    int _rand = hex_rand_range(min, i);
    ASSERT_LE(min, _rand);
    ASSERT_GE(i, _rand);
  }
}

/*******************************************
 * Tests for:
 * hex_randf_top(double top)
 *******************************************/
TEST(hex_randf_topTest, hex_randf_topTest) {
  int i;
  for(i = 1.0f; i <= 5000.0f; i++) {
    ASSERT_LE(hex_rand_top(i), i);
  }
}

/*******************************************
 * Tests for:
 * hex_randf_range(double min, double max)
 *******************************************/
TEST(hex_randf_rangeTest, hex_randf_rangeTest) {
  double i;
  double min = 20.0f;
  for(i = min; i <= 5000.0f; i++) {
    double _rand = hex_randf_range(min, i);
    ASSERT_LE(min, _rand);
    ASSERT_GE(i, _rand);
  }
}

/*******************************************
 * Tests for:
 * generate_text(size_t len, size_t max) 
 *******************************************/
TEST(generate_textTest, PassNonZeroLenAndMaxTest) {
  char *text = generate_text(6, 12);
  HEX_ASSERT(text);
  ASSERT_LE(6, strlen(text));
  ASSERT_GE(12, strlen(text));
}

TEST(generate_textTest, PassZeroMinAndMaxTest) {
  char *text = generate_text(0, 0);
  HEX_ASSERT(text == NULL);
}

TEST(generate_textTest, PassNonZeroLenAndZeroMaxTest) {
  int i;
  for(i = 1; i <= 5000; i++) {
    char *text = generate_text(i, 0);
    HEX_ASSERT(text);
    ASSERT_EQ(i, strlen(text));
    HEX_FREE(text);
  }
}

TEST(generate_textTest, PassZeroLenAndNonZeroMaxTest) {
  int i;
  for(i = 1; i <= 5000; i++) {
    char *text = generate_text(0, i);
    HEX_ASSERT(text);
    ASSERT_GE(i, strlen(text));
    HEX_FREE(text);
  }
}

/*******************************************
 * Tests for:
 * generate_loremipsum()
 *******************************************/
TEST(generate_loremipsumTest, generate_loremipsumTest) {
  char *ipsum = generate_loremipsum();
  HEX_ASSERT(ipsum);
  ASSERT_GE(strlen(ipsum), 0);
  HEX_FREE(ipsum);
}