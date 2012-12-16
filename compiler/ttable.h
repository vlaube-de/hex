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

#ifndef _TTABLE_H_
#define _TTABLE_H_

#include <stddef.h>
#include "scope.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct HexTtableEntry *TtableEntry;

typedef struct HexTtable *Ttable;

Ttable ttable_create();

void ttable_free(Ttable *ttable);

size_t ttable_size(Ttable ttable);

size_t ttable_capacity(Ttable ttable);

char* ttable_mingle_name(TtableEntry entry);

void* ttable_put(Ttable ttable, char *module_name, char *type_name);

TtableEntry ttable_lookup(Ttable ttable, char *module_name, char *type_name); 

void* ttable_put_member(
  Ttable ttable,
  char *module_name,
  char *type_name,
  char *member_name,
  hex_type_t type,
  hex_type_qualifier_t type_qualifier);

void* ttable_put_method(
  Ttable ttable,
  char *module_name,
  char *type_name,
  char *method_name,
  hex_type_t return_type,
  void* paramlist);

void* ttable_lookup_member(
  Ttable ttable,
  char *module_name,
  char *type_name,
  char *member_name);

void* ttable_lookup_method(
  Ttable ttable,
  char *module_name,
  char *type_name,
  char *method_name,
  void* paramlist);

hash_t ttable_get_entry_id(TtableEntry entry);

int ttable_compare_entry_by_id(TtableEntry entry1, TtableEntry entry2);

int ttable_compare_entry(TtableEntry entry1, TtableEntry entry2);

#ifdef __cplusplus
}
#endif

#endif /* _TTABLE_H_ */
