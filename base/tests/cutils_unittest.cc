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

/* Unit test for base/cutils.c */


#include <string.h>
#include <limits.h>
#include "../unittest.h"
#include "../memory.h"
#include "../assert.h"
#include "../cutils.h"

#define _INT_MIN_ -32767
#define _INT_MAX_ 32767

/**********************************************
 * Test for:
 * char* itoa(int value, char *str, int base);
 **********************************************/
TEST(itoaTest, itoaBase10NegativeIntegerTest) {
  int i;
  for(i = _INT_MIN_; i < 0; i++) {
    char expected_str[15];
    char *actual_str = NULL;
    snprintf(expected_str, sizeof(expected_str), "%d", i);
    actual_str = itoa(i, actual_str, 10);
    ASSERT_STREQ(expected_str, actual_str);
    HEX_FREE(actual_str);
  }
}

TEST(itoaTest, itoaBase10PositiveIntegerTest) {
  int i;
  for(i = 0; i < _INT_MAX_; i++) {
    char expected_str[15];
    char *actual_str = NULL;
    snprintf(expected_str, sizeof(expected_str), "%d", i);
    actual_str = itoa(i, actual_str, 10);
    ASSERT_STREQ(expected_str, actual_str);
    HEX_FREE(actual_str);
  }
}

/***********************************
 * itoa Base 2
 * *********************************/

TEST(itoaTest, Base2_PositiveIntegerTest1) {
  char *str=NULL;
  str = itoa((int)0, str, 2);
  ASSERT_STREQ("0", str);
  HEX_FREE(str);
}

TEST(itoaTest, Base2_PositiveIntegerTest2) {
  char *str=NULL;
  str = itoa((int)1, str, 2);
  ASSERT_STREQ("1", str);
  HEX_FREE(str);
}

TEST(itoaTest, Base2_PositiveIntegerTest3) {
  char *str=NULL;
  str = itoa((int)2, str, 2);
  ASSERT_STREQ("10", str);
  HEX_FREE(str);
}

TEST(itoaTest, Base2_PositiveIntegerTest4) {
  char *str=NULL;
  str = itoa((int)4, str, 2);
  ASSERT_STREQ("100", str);
  HEX_FREE(str);
}

TEST(itoaTest, Base2_PositiveIntegerTest5) {
  char *str=NULL;
  str = itoa((int)7, str, 2);
  ASSERT_STREQ("111", str);
  HEX_FREE(str);
}

TEST(itoaTest, Base2_PositiveIntegerTest6) {
  char *str=NULL;
  str = itoa((int)512, str, 2);
  ASSERT_STREQ("1000000000", str);
  HEX_FREE(str);
}

TEST(itoaTest, Base2_PositiveIntegerTest7) {
  char *str=NULL;
  str = itoa((int)1024, str, 2);
  ASSERT_STREQ("10000000000", str);
  HEX_FREE(str);
}

TEST(itoaTest, Base2_PositiveIntegerTest8) {
  char *str=NULL;
  str = itoa((int)(1024+512), str, 2);
  ASSERT_STREQ("11000000000", str);
  HEX_FREE(str);
}

/***********************************
 * itoa Base 8
 * *********************************/
TEST(itoaTest, Base8_PositiveIntegerTest1) {
  char *str=NULL;
  str = itoa((int)7, str, 8);
  ASSERT_STREQ("7", str);
  HEX_FREE(str);
}

TEST(itoaTest, Base8_PositiveIntegerTest2) {
  char *str=NULL;
  str = itoa((int)8, str, 8);
  ASSERT_STREQ("10", str);
  HEX_FREE(str);
}

TEST(itoaTest, Base8_PositiveIntegerTest3) {
  char *str=NULL;
  str = itoa((int)15, str, 8);
  ASSERT_STREQ("17", str);
  HEX_FREE(str);
}

TEST(itoaTest, Base8_PositiveIntegerTest4) {
  char *str=NULL;
  str = itoa((int)16, str, 8);
  ASSERT_STREQ("20", str);
  HEX_FREE(str);
}

TEST(itoaTest, Base8_PositiveIntegerTest5) {
  char *str=NULL;
  str = itoa((int)64, str, 8);
  ASSERT_STREQ("100", str);
  HEX_FREE(str);
}

/*******************************************************************************
 * Test for:
 * int atoi(const char * str);
 ******************************************************************************/
TEST(atoiTest, NullStringTest) {
  ASSERT_EQ(0, atoi(NULL));
}

TEST(atoiTest, ValidBase10NegativeIntegerTest) {
  int i;
  for(i = _INT_MIN_; i < 0; i++) {
    int expected_int = i;
    char expected_str[10];
    snprintf(expected_str, sizeof(expected_str), "%d", i);
    int actual_int = atoi(expected_str);
    ASSERT_EQ(expected_int, actual_int);
  }
}

TEST(atoiTest, ValidBase10PositiveIntegerTest) {
  int i;
  for(i = 0; i <= _INT_MAX_; i++) {
    int expected_int = i;
    char expected_str[10];
    snprintf(expected_str, sizeof(expected_str), "%d", i);
    int actual_int = atoi(expected_str);
    ASSERT_EQ(expected_int, actual_int);
  }
}

TEST(atoiTest, ValidBase10PositiveIntegerWithSignTest) {
  int i;
  for(i = 0; i <= _INT_MAX_; i++) {
    int expected_int = i;
    char expected_str[10];
    snprintf(expected_str+1, sizeof(expected_str)-1, "%d", i);
    expected_str[0] = '+';
    int actual_int = atoi(expected_str);
    ASSERT_EQ(expected_int, actual_int);
  }
}

TEST(atoiTest, InvalidBase10PositiveIntegerTest1) {
  char str[] = "++123";
  int expected_int = atoi(str);
  int actual_int = 0;
  ASSERT_EQ(expected_int, actual_int);
}

TEST(atoiTest, InvalidBase10PositiveIntegerTest2) {
  char str[] = "+123++";
  int expected_int = atoi(str);
  int actual_int = 123;
  ASSERT_EQ(expected_int, actual_int);
}

TEST(atoiTest, InvalidBase10PositiveIntegerTest3) {
  char str[] = " 123 ";
  int expected_int = atoi(str);
  int actual_int = 123;
  ASSERT_EQ(expected_int, actual_int);
}

TEST(atoiTest, InvalidBase10NegativeIntegerTest1) {
  char str[] = "--123";
  int expected_int = atoi(str);
  int actual_int = 0;
  ASSERT_EQ(expected_int, actual_int);
}

TEST(atoiTest, InvalidBase10NegativeIntegerTest2) {
  char str[] = "-123--";
  int expected_int = atoi(str);
  int actual_int = -123;
  ASSERT_EQ(expected_int, actual_int);
}

TEST(atoiTest, InvalidBase10NegativeIntegerTest3) {
  char str[] = " -123 ";
  int expected_int = atoi(str);
  int actual_int = -123;
  ASSERT_EQ(expected_int, actual_int);
}