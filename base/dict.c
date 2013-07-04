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

#include <string.h>
#include "hashmap.h"
#include "dict.h"
#include "assert.h"
#include "memory.h"
#include "utils.h"
#include "hash.h"


#define DICT_DEFAULT_CAPACITY 16

struct HexDict {
  Hashmap hashmap;
};

static
inline int _dict_keycmpfunc(void* key1, void* key2)
{
  HEX_ASSERT(key1);
  HEX_ASSERT(key2);

  char *_key1 = (char*)key1;
  char *_key2 = (char*)key2;

  return strcmp(_key1, _key2) == 0;
}

static
inline hash_t _dict_hashfunc(void* key)
{
  return hash_str((char*)key);
}

Dict dict_create()
{
  Dict dict = HEX_MALLOC(struct HexDict);

  if(!dict) {
    errno = ENOMEM;
    return NULL;
  }

  Hashmap hashmap = hashmap_create(
    DICT_DEFAULT_CAPACITY,
    _dict_hashfunc,
    _dict_keycmpfunc
  );

  if(!hashmap) {
    errno = ENOMEM;
    return NULL;
  }

  dict->hashmap = hashmap;

  return dict;
}

size_t dict_size(Dict dict)
{
  HEX_ASSERT(dict);
  return hashmap_size(dict->hashmap);
}

void dict_free(Dict *dict)
{
  Dict _dict = *dict;

  HEX_ASSERT(_dict);

  hashmap_free(&_dict->hashmap);

  HEX_FREE(_dict);

  *dict = _dict;
}

void* dict_put(Dict dict, const char *key, void* val)
{
  HEX_ASSERT(dict);
  HEX_ASSERT(key);
  HEX_ASSERT(val);

  return hashmap_put(dict->hashmap, (char*)key, val);
}

void* dict_get(Dict dict, const char *key)
{
  HEX_ASSERT(dict);
  HEX_ASSERT(key);

  return hashmap_get(dict->hashmap, (char*)key);
}