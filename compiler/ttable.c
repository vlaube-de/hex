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

#include <string.h>
#include <errno.h>
#include "../base/memory.h"
#include "../base/assert.h"
#include "../base/utils.h"
#include "../base/strbuf.h"
#include "../base/hashmap.h"
#include "../base/strbuf.h"
#include "../base/uuid.h"
#include "../base/hash.h"
#include "vtable.h"
#include "ftable.h"
#include "ttable.h"


#define TTABLE_DEFAULT_CAPACITY 20

struct HexTtableEntry {
  hash_t id;
  char *module_name;
  char *name;
  char *mingled_name;
  Vtable vtable;
  Ftable ftable;
};


struct HexTtable {
  Hashmap hashmap;
};


static
inline int _ttable_keycmpfunc(void *key1, void *key2)
{
  char *_key1 = (char*)key1;
  char *_key2 = (char*)key2;

  return strcmp(_key1, _key2) == 0;
}

static
inline hash_t _ttable_hashfunc(void *key)
{
  return hash_str((char*)key);
}

Ttable ttable_create()
{
  Hashmap hashmap = hashmap_create(
    TTABLE_DEFAULT_CAPACITY,
    _ttable_hashfunc,
    _ttable_keycmpfunc
  );

  if(!hashmap) {
    errno = ENOMEM;
    return NULL;
  } 

  Ttable ttable = HEX_MALLOC(struct HexTtable);

  if(!ttable) {
    HEX_FREE(hashmap);
    errno = ENOMEM;
    return NULL;
  }

  ttable->hashmap = hashmap;

  return ttable;
}

static
TtableEntry _ttable_create_entry(char *module_name, char *type_name)
{
  HEX_ASSERT(module_name);
  HEX_ASSERT(type_name);

  Vtable _vtable = vtable_create();

  if(!_vtable) {
    errno = ENOMEM;
    return NULL;
  }

  Ftable _ftable = ftable_create();

  if(!_ftable) {
    HEX_FREE(_vtable);
    errno = ENOMEM;
    return NULL;
  }

  TtableEntry entry = HEX_MALLOC(struct HexTtableEntry);
  HEX_ASSERT(entry);

  if(!entry) {
    HEX_FREE(_vtable);
    HEX_FREE(_ftable);
    errno = ENOMEM;
    return NULL;
  }

  entry->id = uuid_create_and_hash();
  entry->module_name = strdup(module_name);
  entry->name = strdup(type_name);
  entry->vtable = _vtable;
  entry->ftable = _ftable;
  entry->mingled_name = ttable_mingle_name(entry);

  return entry;
}

static
int _ttable_free_entry(void *key, void *value)
{
  HEX_ASSERT(key);
  HEX_ASSERT(value);

  char *_mingled_name = (char*)key;
  TtableEntry _entry = (TtableEntry)value;

  vtable_free(&_entry->vtable);
  ftable_free(&_entry->ftable);

  HEX_FREE(_mingled_name);

  HEX_ASSERT(_mingled_name == NULL);
  HEX_ASSERT(_entry->vtable == NULL);
  HEX_ASSERT(_entry->ftable == NULL);

  return 1;
}

char* ttable_mingle_name(TtableEntry entry)
{
  HEX_ASSERT(entry);

  Strbuf strbuf = strbuf_create();
  HEX_ASSERT(strbuf);

  strbuf_append(strbuf, entry->module_name);
  strbuf_append(strbuf, ".");
  strbuf_append(strbuf, entry->name);

  char *mingled_name = strdup(strbuf_cstr(strbuf));

  HEX_ASSERT(mingled_name);

  strbuf_free(&strbuf);
  HEX_ASSERT(strbuf == NULL);

  return mingled_name;
}

void ttable_free(Ttable *ttable)
{
  Ttable _ttable = *ttable;

  HEX_ASSERT(_ttable);

  hashmap_iterate(_ttable->hashmap, _ttable_free_entry, 0);
  hashmap_free(&_ttable->hashmap);

  HEX_ASSERT(_ttable->hashmap == NULL);

  HEX_FREE(_ttable);

  *ttable = _ttable;
}

size_t ttable_size(Ttable ttable)
{
  HEX_ASSERT(ttable);
  return hashmap_size(ttable->hashmap);
}

size_t ttable_capacity(Ttable ttable)
{
  HEX_ASSERT(ttable);
  return hashmap_capacity(ttable->hashmap);
}

void* ttable_put(
  Ttable ttable,
  char *module_name,
  char *name)
{
  HEX_ASSERT(ttable);
  HEX_ASSERT(module_name);
  HEX_ASSERT(name);

  TtableEntry _entry = (TtableEntry)_ttable_create_entry(module_name, name);

  HEX_ASSERT(_entry);

  return hashmap_put(ttable->hashmap, _entry->mingled_name, _entry); 
}

typedef struct HexTtableLookupArg {
  char *mingled_name;
} *TtableLookupArg;

static
inline int _ttable_lookup(void *key, void *value, void *arg)
{
  HEX_ASSERT(key);
  HEX_ASSERT(arg);

  char *mingled_name = (char*)key;
  TtableLookupArg _arg = (TtableLookupArg)arg;

  return strcmp(mingled_name, _arg->mingled_name) == 0;
}

TtableEntry ttable_lookup(Ttable ttable, char *module_name, char *name)
{
  HEX_ASSERT(ttable);
  HEX_ASSERT(name);

  TtableEntry _entry = _ttable_create_entry(module_name, name);

  struct HexTtableLookupArg arg = {
    .mingled_name = _entry->mingled_name
  };

  HEX_FREE(_entry);

  return (TtableEntry)hashmap_lookup(ttable->hashmap, _ttable_lookup, &arg); 
}

void* ttable_put_member(
  Ttable ttable,
  char *module_name,
  char *type_name,
  char *member_name,
  hex_type_t type,
  hex_type_qualifier_t type_qualifier)
{
  HEX_ASSERT(ttable);
  HEX_ASSERT(module_name);
  HEX_ASSERT(type_name);
  HEX_ASSERT(member_name);

  TtableEntry entry = ttable_lookup(ttable, module_name, type_name);

  RETURN_VAL_IF_NULL(entry, NULL);

  return vtable_put(
    entry->vtable,
    entry->mingled_name,
    member_name,
    HEX_VAR_SCOPE_TYPE_MEMBER,
    type,
    type_qualifier,
    0x01
  ); 
}

void* ttable_put_method(
  Ttable ttable,
  char *module_name,
  char *type_name,
  char *method_name,
  hex_type_t return_type,
  void* paramlist)
{
  HEX_ASSERT(ttable);
  HEX_ASSERT(module_name);
  HEX_ASSERT(type_name);
  HEX_ASSERT(method_name);

  TtableEntry entry = ttable_lookup(ttable, module_name, type_name);

  RETURN_VAL_IF_NULL(entry, NULL);

  return ftable_put(
    entry->ftable,
    entry->mingled_name,
    method_name,
    return_type,
    paramlist
  );
}

void* ttable_lookup_member(
  Ttable ttable,
  char *module_name,
  char *type_name,
  char *member_name)
{
  HEX_ASSERT(ttable);
  HEX_ASSERT(module_name);
  HEX_ASSERT(type_name);
  HEX_ASSERT(member_name);

  TtableEntry entry = ttable_lookup(ttable, module_name, type_name);

  RETURN_VAL_IF_NULL(entry, 0);

  void *p = vtable_lookup(
    entry->vtable,
    entry->mingled_name,
    member_name,
    0x01
  );

  return p;
}

void* ttable_lookup_method(
  Ttable ttable,
  char *module_name,
  char *type_name,
  char *method_name,
  void* paramlist)
{
  HEX_ASSERT(ttable);
  HEX_ASSERT(module_name);
  HEX_ASSERT(type_name);
  HEX_ASSERT(method_name);

  TtableEntry entry = ttable_lookup(ttable, module_name, type_name);

  RETURN_VAL_IF_NULL(entry, NULL);

  void *p = ftable_lookup(
    entry->ftable,
    entry->mingled_name,
    method_name,
    paramlist
  );

  return p;
}

hash_t ttable_get_entry_id(TtableEntry entry)
{
  HEX_ASSERT(entry);
  return entry->id;
}

int ttable_compare_entry_by_id(TtableEntry entry1, TtableEntry entry2)
{
  HEX_ASSERT(entry1);
  HEX_ASSERT(entry2);

  return entry1->id == entry2->id;
}

int ttable_compare_entry(TtableEntry entry1, TtableEntry entry2)
{
  HEX_ASSERT(entry1);
  HEX_ASSERT(entry2);

  return strcmp(entry1->mingled_name, entry2->mingled_name) == 0;
}
