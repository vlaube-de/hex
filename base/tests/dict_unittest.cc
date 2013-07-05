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

/* Unit test for base/dict.c */


#include "../unittest.h"
#include "../assert.h"
#include "../memory.h"
#include "../dict.h"


class DictTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    _dict = dict_create();
    HEX_ASSERT(_dict);
  }

  virtual void Teardown() {
    dict_free(&_dict);
    HEX_ASSERT(_dict == NULL);
  }

  Dict _dict;
};

typedef struct {
  char *key;
  char *val;
} KeyVal;

KeyVal fruits[] = {
  {"a", "apple"},
  {"b", "banana"},
  {"c", "coconut"}
};

KeyVal sky[] = {
  {"a", "air"},
  {"b", "balloon"},
  {"c", "cloud"}
};

KeyVal vehicles[] = {
  {"a", "airplane"},
  {"b", "boat"},
  {"c", "car"}
};


TEST_F(DictTest, dict_createTest) {
  HEX_ASSERT(_dict);
  ASSERT_EQ(0, dict_size(_dict));
}

TEST_F(DictTest, dict_putTest1) {
  dict_put(_dict, fruits[0].key, fruits[0].val);
  ASSERT_EQ(1, dict_size(_dict));
  dict_put(_dict, fruits[1].key, fruits[1].val);
  ASSERT_EQ(2, dict_size(_dict));
  dict_put(_dict, fruits[2].key, fruits[2].val);
  ASSERT_EQ(3, dict_size(_dict));

  char *val1 = (char*)dict_get(_dict, fruits[0].key);
  char *val2 = (char*)dict_get(_dict, fruits[1].key);
  char *val3 = (char*)dict_get(_dict, fruits[2].key);

  HEX_ASSERT(val1);
  HEX_ASSERT(val2);
  HEX_ASSERT(val3);

  ASSERT_STREQ(val1, fruits[0].val);
  ASSERT_STREQ(val2, fruits[1].val);
  ASSERT_STREQ(val3, fruits[2].val);
}

TEST_F(DictTest, dict_getTest) {
  dict_put(_dict, fruits[0].key, fruits[0].val);
  dict_put(_dict, fruits[1].key, fruits[1].val);
  dict_put(_dict, fruits[2].key, fruits[2].val);

  ASSERT_EQ(3, dict_size(_dict));

  ASSERT_EQ(fruits[0].val, dict_get(_dict, fruits[0].key));
  ASSERT_EQ(fruits[1].val, dict_get(_dict, fruits[1].key));
  ASSERT_EQ(fruits[2].val, dict_get(_dict, fruits[2].key));

  HEX_ASSERT(dict_put(_dict, sky[1].key, sky[1].val));

  ASSERT_EQ(3, dict_size(_dict));

  ASSERT_EQ(fruits[0].val, dict_get(_dict, fruits[0].key));
  ASSERT_EQ(sky[1].val, dict_get(_dict, sky[1].key));
  ASSERT_EQ(fruits[2].val, dict_get(_dict, fruits[2].key));

  HEX_ASSERT(dict_put(_dict, vehicles[2].key, vehicles[2].val));

  ASSERT_EQ(3, dict_size(_dict));

  ASSERT_EQ(fruits[0].val, (char*)dict_get(_dict, fruits[0].key));
  ASSERT_EQ(sky[1].val, (char*)dict_get(_dict, sky[1].key));
  ASSERT_EQ(vehicles[2].val, (char*)dict_get(_dict, vehicles[2].key));
}