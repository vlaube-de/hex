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

#ifndef _BITMAP_H_
#define _BITMAP_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct HexBitmap *Bitmap;

Bitmap bitmap_create(size_t width, size_t height);

void bitmap_free(Bitmap *bitmap);

size_t bitmap_width(Bitmap bitmap);

size_t bitmap_height(Bitmap bitmap);

int bitmap_set_bit(Bitmap bitmap, size_t row, size_t col);

int bitmap_clear_bit(Bitmap bitmap, size_t row, size_t col);

int bitmap_is_set(Bitmap bitmap, size_t row, size_t col);

void bitmap_clear(Bitmap bitmap);


#ifdef __cplusplus
}
#endif

#endif /* _BITMAP_H_ */
