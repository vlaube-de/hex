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

#ifndef _FTABLE_H_
#define _FTABLE_H_

#include <stddef.h>
#include "ast.h"
#include "types.h"
#include "../base/hash.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct HexFtableEntry {
  hash_t id;
  hash_t parent_id;
  char *module_name;
  char *name;
  hex_type_t return_type;
  void *paramlist;
  char *mingled_name;
} *FtableEntry;

typedef struct HexFtable *Ftable;

char* ftable_mingle_name(FtableEntry);

Ftable ftable_create();

size_t ftable_size(Ftable ftable);

size_t ftable_capacity(Ftable ftable);

FtableEntry ftable_put(
  Ftable ftable,
  hash_t parent_id,
  char *module_name,
  char *name,
  hex_type_t return_type,
  void *paramlist);

FtableEntry ftable_lookup(
  Ftable ftable,
  char *module_name,
  char *name,
  void *paramlist);

FtableEntry ftable_lookup_by_name(
  Ftable ftable,
  char *module_name,
  char *name);

FtableEntry ftable_lookup_by_parent_id(
  Ftable ftable,
  hash_t parent_id,
  char *name);

FtableEntry ftable_lookup_by_id(Ftable ftable, hash_t id);

void ftable_free(Ftable *ftable);

int ftable_compare(FtableEntry entry1, FtableEntry entry2);


#ifdef __cplusplus
}
#endif

#endif /* _FTABLE_H_ */
