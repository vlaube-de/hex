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
#include <math.h>
#include "memory.h"
#include "utils.h"
#include "assert.h"
#include "bitmap.h"

#define ROW(row) floor((double)(row) / sizeof(char))
#define COL(col) floor((double)(col) / sizeof(char))

struct HexBitmap {
  char **_content;
  size_t _width;
  size_t _height;
};


Bitmap bitmap_create(size_t width, size_t height)
{
  RETURN_VAL_IF_FALSE(width > 0, NULL);
  RETURN_VAL_IF_FALSE(height > 0, NULL);

  Bitmap bitmap = HEX_MALLOC(struct HexBitmap);

  if(!bitmap) {
    errno = ENOMEM;
    return NULL;
  }

  unsigned int _rows = ceil((double)height / sizeof(char));
  unsigned int _cols = ceil((double)width / sizeof(char));
  int i;

  char **_content=NULL;

  _content = (char**)calloc(_rows, sizeof(char*));
  for(i = 0; i < _rows; i++) {
    _content[i] = (char*)calloc(_cols, sizeof(char));
    memset(_content[i], 0, _cols);
  }

  bitmap->_content = _content;
  bitmap->_width = width;
  bitmap->_height = height;

  return bitmap;
}

void bitmap_free(Bitmap *bitmap)
{
  Bitmap _bitmap = *bitmap;

  HEX_ASSERT(_bitmap);

  int i;
  for(i = 0; i < _bitmap->_height; i++) {
    HEX_FREE(_bitmap->_content[i]);
  }

  HEX_FREE(_bitmap);

  *bitmap = _bitmap;
}

size_t bitmap_width(Bitmap bitmap)
{
  HEX_ASSERT(bitmap);
  return bitmap->_width;
}

size_t bitmap_height(Bitmap bitmap)
{
  HEX_ASSERT(bitmap);
  return bitmap->_height;
}

int bitmap_set_bit(Bitmap bitmap, size_t row, size_t col)
{
  HEX_ASSERT(bitmap);

  RETURN_VAL_IF_FALSE(bitmap->_width > col, 0);
  RETURN_VAL_IF_FALSE(bitmap->_height > row, 0);

  size_t r = ROW(row);
  size_t c = COL(col);

  int val = (int)bitmap->_content[r][c];

  /*
   * row % sizeof(char) - MSB [0,1,2,3,4,5,6,7] LSB
   * set_nth_bit        - MSB [8,7,6,5,4,3,2,1] LSB
   */
  int bit = sizeof(char) - row % sizeof(char);

  HEX_ASSERT((bit >= 0));
  HEX_ASSERT((bit <= sizeof(char)));

  set_nth_bit(&val, bit);

  bitmap->_content[r][c] = (char)val;

  return 1;
}

int bitmap_clear_bit(Bitmap bitmap, size_t row, size_t col)
{
  HEX_ASSERT(bitmap);

  RETURN_VAL_IF_FALSE(bitmap->_width > col, 0);
  RETURN_VAL_IF_FALSE(bitmap->_height > row, 0);

  size_t r = ROW(row);
  size_t c = COL(col);

  int val = (int)bitmap->_content[r][c];

  int bit = sizeof(char) - row % sizeof(char);

  HEX_ASSERT((bit >= 0));
  HEX_ASSERT((bit <= sizeof(char)));

  clear_nth_bit(&val, bit);

  bitmap->_content[r][c] = (char)val;

  return 1;
}

int bitmap_is_set(Bitmap bitmap, size_t row, size_t col)
{
  HEX_ASSERT(bitmap);

  RETURN_VAL_IF_FALSE(bitmap->_width > col, 0);
  RETURN_VAL_IF_FALSE(bitmap->_height > row, 0);

  size_t r = ROW(row);
  size_t c = COL(col);

  int val = (int)bitmap->_content[r][c];

  int bit = sizeof(char) - row % sizeof(char);

  HEX_ASSERT((bit >= 0));
  HEX_ASSERT((bit <= sizeof(char)));

  return is_bit_set(val, bit);
}

void bitmap_clear(Bitmap bitmap)
{
  HEX_ASSERT(bitmap);

  int i;
  for(i = 0; i < bitmap->_height; i++) {
    char *row = bitmap->_content[i];
    memset(row, 0, bitmap->_width);
  }
}
