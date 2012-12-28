/*
 * HEX Programming Language
 * Copyright (C) 2012  Yanzheng Li
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

#include <stddef.h>
#include "../unittest.h"
#include "../memory.h"
#include "../assert.h"
#include "../bitmap.h"


TEST(bitmapTest, bitmap_createTest) {
 Bitmap bitmap = NULL;

 bitmap = bitmap_create(0, 10);
 HEX_ASSERT(bitmap == NULL);

 bitmap = bitmap_create(1, 0);
 HEX_ASSERT(bitmap == NULL);

 bitmap = bitmap_create(0, 0);
 HEX_ASSERT(bitmap == NULL);
}

TEST(bitmapTest, bitmap_createTest2) {
  Bitmap bitmap = NULL;
  size_t width = 1;
  size_t height = 1;

  bitmap = bitmap_create(width, height);
  HEX_ASSERT(bitmap);

  ASSERT_EQ(width, bitmap_width(bitmap));
  ASSERT_EQ(height, bitmap_height(bitmap));

  bitmap_free(&bitmap);

  HEX_ASSERT(bitmap == NULL);
}

TEST(bitmapTest, bitmap_set_bitTest1) {
  Bitmap bitmap = NULL;
  size_t width = 1;
  size_t height = 1;
  int res;

  bitmap = bitmap_create(width, height);
  HEX_ASSERT(bitmap);

  ASSERT_EQ(width, bitmap_width(bitmap));
  ASSERT_EQ(height, bitmap_height(bitmap));

  res = bitmap_set_bit(bitmap, 1, 0);
  ASSERT_EQ(0, res);

  bitmap_free(&bitmap);
  HEX_ASSERT(bitmap == NULL);
}

TEST(bitmapTest, bitmap_set_bitTest2) {
  Bitmap bitmap = NULL;
  size_t width = 1;
  size_t height = 1;
  int res;

  bitmap = bitmap_create(width, height);
  HEX_ASSERT(bitmap);

  ASSERT_EQ(width, bitmap_width(bitmap));
  ASSERT_EQ(height, bitmap_height(bitmap));

  res = bitmap_set_bit(bitmap, 0, 1);
  ASSERT_EQ(0, res);

  bitmap_free(&bitmap);
  HEX_ASSERT(bitmap == NULL);
}

TEST(bitmapTest, bitmap_set_bitTest3) {
  Bitmap bitmap = NULL;
  size_t width = 1;
  size_t height = 1;
  int res;

  bitmap = bitmap_create(width, height);
  HEX_ASSERT(bitmap);

  ASSERT_EQ(width, bitmap_width(bitmap));
  ASSERT_EQ(height, bitmap_height(bitmap));

  res = bitmap_set_bit(bitmap, 0, 0);
  ASSERT_EQ(1, res);

  res = bitmap_is_set(bitmap, 0, 0);
  ASSERT_EQ(1, res);

  bitmap_free(&bitmap);
  HEX_ASSERT(bitmap == NULL);
}

TEST(bitmapTest, BitmapSetAndClearBitTest1) {
  Bitmap bitmap = NULL;
  size_t width = 2;
  size_t height = 2;

  bitmap = bitmap_create(width, height);
  HEX_ASSERT(bitmap);

  ASSERT_EQ(width, bitmap_width(bitmap));
  ASSERT_EQ(height, bitmap_height(bitmap));

  ASSERT_EQ(1, bitmap_set_bit(bitmap, 0, 0));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 1, 0));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 0, 1));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 1, 1));

  ASSERT_EQ(1, bitmap_is_set(bitmap, 0, 0));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 1, 0));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 0, 1));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 1, 1));

  // now clear [1,0] and [0, 1]
  bitmap_clear_bit(bitmap, 1, 0);
  bitmap_clear_bit(bitmap, 0, 1);

  ASSERT_EQ(1, bitmap_is_set(bitmap, 0, 0));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 1, 0));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 0, 1));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 1, 1));

  bitmap_free(&bitmap);
  HEX_ASSERT(bitmap == NULL);
}

TEST(bitmapTest, BitmapSetAndClearBitTest2) {
  Bitmap bitmap = NULL;
  size_t width = 8;
  size_t height = 8;

  bitmap = bitmap_create(width, height);
  HEX_ASSERT(bitmap);

  ASSERT_EQ(width, bitmap_width(bitmap));
  ASSERT_EQ(height, bitmap_height(bitmap));

  ASSERT_EQ(1, bitmap_set_bit(bitmap, 0, 0));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 1, 1));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 2, 2));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 3, 3));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 4, 4));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 5, 5));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 6, 6));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 7, 7));
  ASSERT_EQ(0, bitmap_set_bit(bitmap, 8, 8));

  ASSERT_EQ(1, bitmap_is_set(bitmap, 0, 0));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 1, 1));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 2, 2));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 3, 3));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 4, 4));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 5, 5));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 6, 6));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 7, 7));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 8, 8));
  
  ASSERT_EQ(0, bitmap_is_set(bitmap, 0, 1));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 1, 2));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 2, 3));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 3, 4));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 4, 5));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 5, 6));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 6, 7));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 7, 8));
 
  bitmap_clear_bit(bitmap, 0, 0);
  bitmap_clear_bit(bitmap, 1, 1);
  bitmap_clear_bit(bitmap, 2, 2);
  bitmap_clear_bit(bitmap, 3, 3);
  bitmap_clear_bit(bitmap, 4, 4);
  bitmap_clear_bit(bitmap, 5, 5);
  bitmap_clear_bit(bitmap, 6, 6);
  bitmap_clear_bit(bitmap, 7, 7);
  bitmap_clear_bit(bitmap, 8, 8);
  
  ASSERT_EQ(0, bitmap_is_set(bitmap, 0, 0));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 1, 1));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 2, 2));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 3, 3));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 4, 4));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 5, 5));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 6, 6));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 7, 7));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 8, 8));

  bitmap_free(&bitmap);
  HEX_ASSERT(bitmap == NULL);
}

TEST(bitmapTest, BitmapSetAndClearBitTest3) {
  Bitmap bitmap = NULL;
  size_t width = 16;
  size_t height = 16;

  bitmap = bitmap_create(width, height);
  HEX_ASSERT(bitmap);

  ASSERT_EQ(width, bitmap_width(bitmap));
  ASSERT_EQ(height, bitmap_height(bitmap));

  ASSERT_EQ(1, bitmap_set_bit(bitmap, 0, 0));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 1, 1));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 2, 2));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 3, 3));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 4, 4));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 5, 5));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 6, 6));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 7, 7));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 8, 8));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 9, 9));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 10, 10));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 11, 11));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 12, 12));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 13, 13));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 14, 14));
  ASSERT_EQ(1, bitmap_set_bit(bitmap, 15, 15));
  ASSERT_EQ(0, bitmap_set_bit(bitmap, 16, 16));

  ASSERT_EQ(1, bitmap_is_set(bitmap, 0, 0));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 1, 1));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 2, 2));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 3, 3));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 4, 4));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 5, 5));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 6, 6));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 7, 7));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 8, 8));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 9, 9));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 10, 10));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 11, 11));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 12, 12));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 13, 13));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 14, 14));
  ASSERT_EQ(1, bitmap_is_set(bitmap, 15, 15));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 16, 16));

  size_t r = 0;
  size_t c = 0;
  for(r = 0; r < height; r++) {
    for(c = 0; c < width; c++) {
      ASSERT_EQ(r == c, bitmap_is_set(bitmap, r, c));
    }
  }
 
  bitmap_clear_bit(bitmap, 0, 0);
  bitmap_clear_bit(bitmap, 1, 1);
  bitmap_clear_bit(bitmap, 2, 2);
  bitmap_clear_bit(bitmap, 3, 3);
  bitmap_clear_bit(bitmap, 4, 4);
  bitmap_clear_bit(bitmap, 5, 5);
  bitmap_clear_bit(bitmap, 6, 6);
  bitmap_clear_bit(bitmap, 7, 7);
  bitmap_clear_bit(bitmap, 8, 8);
  bitmap_clear_bit(bitmap, 9, 9);
  bitmap_clear_bit(bitmap, 10, 10);
  bitmap_clear_bit(bitmap, 11, 11);
  bitmap_clear_bit(bitmap, 12, 12);
  bitmap_clear_bit(bitmap, 13, 13);
  bitmap_clear_bit(bitmap, 14, 14);
  bitmap_clear_bit(bitmap, 15, 15);
  
  ASSERT_EQ(0, bitmap_is_set(bitmap, 0, 0));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 1, 1));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 2, 2));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 3, 3));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 4, 4));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 5, 5));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 6, 6));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 7, 7));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 8, 8));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 9, 9));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 10, 10));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 11, 11));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 12, 12));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 13, 13));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 14, 14));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 15, 15));
  ASSERT_EQ(0, bitmap_is_set(bitmap, 16, 16));

  bitmap_free(&bitmap);
  HEX_ASSERT(bitmap == NULL);
}
