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

#include <stdlib.h>
#include "utils.h"
#include "assert.h"


void
set_nth_bit(int *val, char bit)
{
  int b = (1 << (bit-1));
  *val = *val | b;
}

void
clear_nth_bit(int *val, char bit)
{
  int b = (1 << (bit-1));
  *val = *val & (~b);
}

int
is_bit_set(int val, char bit)
{
  unsigned int v = val;
  int b = (1 << (bit-1));
  v = v & b;
  return (v >> (bit-1)) == 1;
}

int
inline hex_rand_top(int max)
{
  return rand() % max + 1;
}

int
inline hex_rand_range(int min, int max)
{
  int _rand = hex_rand_top(max);
  return MAX(min, _rand);
}

double
inline hex_randf_top(double max)
{
  double f = (double)rand() / RAND_MAX;
  double _rand = f * max;

  if(_rand < 1.0f) {
    _rand += 1.0f;
  }

  return _rand;
}

double
inline hex_randf_range(double min, double max)
{
  double f = (double)rand() / RAND_MAX;
  return min + f * (max - min);
}

static
inline char _rand_ascii()
{
  return '0' + hex_rand_top(127);
}

char*
generate_text(size_t len, size_t max)
{
  char *text=NULL;
  size_t _len=0;

  if(len && max) {
    _len = hex_rand_range(len, max); 
  } else if (len && !max) {
    _len = len;
  } else if (!len && max) {
    _len = hex_rand_range(1, max);
  } else {
    return NULL;
  }

  text = (char*)malloc(_len+1);
  memset(text, 0, _len+1);

  int i;
  for(i = 0; i < _len; i++) {
    text[i] = _rand_ascii();
  }

  return text;
}

char*
generate_loremipsum()
{
  char ipsum[] = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, "
    "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
    "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi "
    "ut aliquip ex ea commodo consequat. Duis aute irure dolor in "
    "reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla "
    "pariatur. Excepteur sint occaecat cupidatat non proident, sunt in "
    "culpa qui officia deserunt mollit anim id est laborum.";

  return strdup(ipsum);
}
