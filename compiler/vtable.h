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

#ifndef _VTABLE_H_
#define _VTABLE_H_

#include <stddef.h>
#include "scope.h"
#include "types.h"
#include "../base/hash.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef struct HexVtableEntry {
  hash_t id;
  hash_t parent_id;
  char *module_name;
  char *name;
  char *mingled_name;
  hex_scope_type_t scope_type;
  hex_type_t type;
  hex_type_qualifier_t type_qualifier;
  unsigned int indent_level;
} *VtableEntry;


typedef struct HexVtable *Vtable;

char* vtable_mingle_name(VtableEntry entry);

Vtable vtable_create();

size_t vtable_size(Vtable vtable);

size_t vtable_capacity(Vtable vtable);

void* vtable_put(
  Vtable vtable,
  hash_t parent_id,
  char *module_name,
  char *name,
  hex_scope_type_t scope_type,
  hex_type_t type,
  hex_type_qualifier_t type_qualifier,
  unsigned int indent_level);

VtableEntry vtable_lookup(
  Vtable vtable,
  char *module_name,
  char *name,
  unsigned int indent_level);

VtableEntry vtable_lookup_by_parent_id(
  Vtable vtable,
  hash_t parent_id,
  char *name
);

VtableEntry vtable_lookup_by_id(Vtable vtable, hash_t id);

int vtable_compare(VtableEntry entry1, VtableEntry entry2);

void vtable_free(Vtable *vtable);


#ifdef __cplusplus
}
#endif

#endif /* _VTABLE_H_ */
