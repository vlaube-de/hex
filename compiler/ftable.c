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
#include "../base/hash.h"
#include "../base/hashmap.h"
#include "ftable.h"


#define FTABLE_DEFAULT_CAPACITY 10


struct HexFtable {
  Hashmap hashmap;
};

static
inline int _ftable_keycmpfunc(void *key1, void *key2)
{
  HEX_ASSERT(key1);
  HEX_ASSERT(key2);

  char *_key1 = (char*)key1;
  char *_key2 = (char*)key2;

  return strcmp(_key1, _key2) == 0; 
}

static
inline hash_t _ftable_hashfunc(void *key)
{
  HEX_ASSERT(key);
  return hash_str((char*)key);
}

char* ftable_mingle_name(FtableEntry entry)
{
  HEX_ASSERT(entry);
  HEX_ASSERT(entry->module_name);
  HEX_ASSERT(entry->name);

  Strbuf strbuf = strbuf_create();
  HEX_ASSERT(strbuf);

  strbuf_append(strbuf, (const char*)entry->module_name);
  strbuf_append(strbuf, ".");
  strbuf_append(strbuf, (const char*)entry->name);

  ParameterList paramlist = (ParameterList)entry->paramlist;
  while(paramlist) {
    Parameter param = paramlist->parameter;

    HEX_ASSERT(param);
    HEX_ASSERT(param->parameter_name);

    strbuf_append(strbuf, "_");
    strbuf_append(strbuf, (const char*)param->parameter_name);
    strbuf_append(strbuf, "-");

    if(param->type_specifier) {
      char buf[10];
      snprintf(buf, sizeof(buf), "%d", param->type_specifier);
      strbuf_append(strbuf, buf);
    } else {
      strbuf_append(strbuf, (const char*)param->custom_type);
    }

    paramlist = paramlist->next;
  }

  char *mingled_name = strdup(strbuf_cstr(strbuf));

  HEX_ASSERT(mingled_name);

  HEX_FREE(strbuf);

  return mingled_name;
}

Ftable ftable_create()
{
  Hashmap hashmap = hashmap_create(
    FTABLE_DEFAULT_CAPACITY,
    _ftable_hashfunc,
    _ftable_keycmpfunc
  );

  if(!hashmap) {
    errno = ENOMEM;
    return NULL;
  }

  Ftable ftable = HEX_MALLOC(struct HexFtable);

  if(!ftable) {
    errno = ENOMEM;
    hashmap_free(&hashmap);
    return NULL;
  }

  ftable->hashmap = hashmap;
  
  return ftable;
}
 
size_t ftable_size(Ftable ftable)
{
  HEX_ASSERT(ftable);
  return hashmap_size(ftable->hashmap);
}

size_t ftable_capacity(Ftable ftable)
{
  HEX_ASSERT(ftable);
  return hashmap_capacity(ftable->hashmap);
}

FtableEntry ftable_put(
  Ftable ftable,
  hash_t parent_id,
  char *module_name,
  char *name,
  hex_type_t return_type,
  void *paramlist)
{
  HEX_ASSERT(ftable);
  HEX_ASSERT(module_name);
  HEX_ASSERT(name);

  FtableEntry entry = HEX_MALLOC(struct HexFtableEntry);
  RETURN_VAL_IF_NULL(entry, NULL);

  memset(entry, 0, sizeof(struct HexFtableEntry));

  entry->parent_id = parent_id;
  entry->module_name = strdup(module_name);
  entry->name = strdup(name);
  entry->return_type = return_type;
  entry->paramlist = paramlist;

  entry->mingled_name = ftable_mingle_name(entry);
  entry->id = hash_str(entry->mingled_name);

  return (FtableEntry)hashmap_put(ftable->hashmap, entry->mingled_name, entry);
}

typedef struct HexFtableLookupArg {
  char *module_name;
  char *name;
  char *mingled_name;
} *FtableLookupArg;

static
int _ftable_lookup(void *key, void *value, void *arg)
{
  HEX_ASSERT(key);
  HEX_ASSERT(arg);

  FtableLookupArg _arg = (FtableLookupArg)arg;
  char *_key = (char*)key;
 
  HEX_ASSERT(_key);
  HEX_ASSERT(_arg->mingled_name);

  return strcmp(_key, _arg->mingled_name) == 0;
}

FtableEntry ftable_lookup(
  Ftable ftable,
  char *module_name,
  char *name,
  void *paramlist)
{
  HEX_ASSERT(ftable);
  HEX_ASSERT(module_name);
  HEX_ASSERT(name);

  FtableEntry _entry = HEX_MALLOC(struct HexFtableEntry);
  HEX_ASSERT(_entry);

  _entry->module_name = strdup(module_name);
  _entry->name = strdup(name);
  _entry->paramlist = paramlist;
  _entry->mingled_name = ftable_mingle_name(_entry);

  struct HexFtableLookupArg arg = {
    .mingled_name = _entry->mingled_name
  };

  FtableEntry entry = (FtableEntry)hashmap_lookup(
    ftable->hashmap,
    _ftable_lookup,
    &arg
  );

  HEX_FREE(_entry->mingled_name);
  HEX_FREE(_entry);

  return entry;
}

static
int _ftable_lookup_by_name(void *key, void *value, void *arg)
{
  HEX_ASSERT(key);
  HEX_ASSERT(arg);

  FtableLookupArg _arg = (FtableLookupArg)arg;
  FtableEntry entry = (FtableEntry)value;

  return strcmp(_arg->module_name, entry->module_name) == 0 &&
    strcmp(_arg->name, entry->name) == 0;
}

FtableEntry ftable_lookup_by_name(Ftable ftable, char *module_name, char *name)
{
  HEX_ASSERT(ftable);
  HEX_ASSERT(module_name);
  HEX_ASSERT(name);

  struct HexFtableLookupArg arg = {
    .module_name = module_name,
    .name = name
  };

  FtableEntry entry = (FtableEntry)hashmap_lookup(
    ftable->hashmap,
    _ftable_lookup_by_name,
    &arg
  );

  return entry;
}

typedef struct HexFtableLookupByParentIdArg {
  hash_t parent_id;
  char *name;
} *FtableLookupByParentIdArg;

static
int _ftable_lookup_by_parent_id(void* key, void* value, void* arg)
{
  HEX_ASSERT(value);
  HEX_ASSERT(arg);

  FtableEntry _entry = (FtableEntry)value;
  FtableLookupByParentIdArg _arg = (FtableLookupByParentIdArg)arg;

  return _entry->parent_id == _arg->parent_id &&
    strcmp(_entry->name, _arg->name) == 0;
}

FtableEntry ftable_lookup_by_parent_id(
  Ftable ftable,
  hash_t parent_id,
  char *name)
{
  HEX_ASSERT(ftable);
  HEX_ASSERT(parent_id);
  HEX_ASSERT(name);

  struct HexFtableLookupByParentIdArg arg = {
    .parent_id = parent_id,
    .name = name
  };

  FtableEntry entry = (FtableEntry)hashmap_lookup(
    ftable->hashmap,
    _ftable_lookup_by_parent_id,
    &arg
  );

  return entry;
}

typedef struct HexFtableLookupByIdArg {
  hash_t id;
} *FtableLookupByIdArg;

static
int _ftable_lookup_by_id(void *key, void *value, void *arg)
{
  HEX_ASSERT(value);
  HEX_ASSERT(arg);

  FtableLookupByIdArg _arg = (FtableLookupByIdArg)arg;
  FtableEntry _entry = (FtableEntry)value;

  return _entry->id == _arg->id;
}

FtableEntry ftable_lookup_by_id(Ftable ftable, hash_t id)
{
  HEX_ASSERT(ftable);
  HEX_ASSERT(id);

  struct HexFtableLookupByIdArg arg = {
    .id = id
  };

  FtableEntry entry = (FtableEntry)hashmap_lookup(
    ftable->hashmap,
    _ftable_lookup_by_id,
    &arg
  );

  return entry;
}

void ftable_free(Ftable *ftable)
{
  Ftable _ftable = *ftable;

  HEX_ASSERT(_ftable);

  hashmap_free(&_ftable->hashmap);

  HEX_FREE(_ftable);

  *ftable = _ftable;
}

int ftable_compare(FtableEntry entry1, FtableEntry entry2)
{
  HEX_ASSERT(entry1);
  HEX_ASSERT(entry2);

  int _res = entry1->id == entry2->id;
  int res = strcmp(entry1->mingled_name, entry2->mingled_name) == 0;
  int res2 = entry1->parent_id == entry2->parent_id;

  HEX_ASSERT(_res == res);

  return res;
}
