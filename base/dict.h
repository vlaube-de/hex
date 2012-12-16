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

/*
 * A dictionary container for storing key-value pairs with the keys
 * being strings.
 */

#ifndef _DICT_H_
#define _DICT_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct HexDict *Dict;

Dict dict_create();

size_t dict_size(Dict dict);

void dict_free(Dict *dict);

void* dict_put(Dict dict, const char *key, void* val);

void* dict_get(Dict dict, const char *key);


#ifdef __cplusplus
}
#endif


#endif /* _DICT_H_ */
