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
#include <string.h>
#include <errno.h>
#include "../base/memory.h"
#include "../base/assert.h"
#include "../base/utils.h"
#include "../base/strbuf.h"
#include "../base/hashmap.h"
#include "../base/hash.h"
#include "../base/uuid.h"
#include "ast.h"
#include "scope.h"
#include "types.h"
#include "vtable.h"
#include "ftable.h"
#include "ttable.h"
#include "symtable.h"


#define DEFAULT_SYMTABLE_CAPACITY 20

struct HexSymbol {
  hash_t id;
  unsigned int symbol_type;
  char *module_name;
  union {
    VtableEntry _vtable_entry;
    FtableEntry _ftable_entry;
    TtableEntry _ttable_entry;
  };
};


struct HexSymTable {
  Hashmap _hashmap;
  Vtable _vtable;
  Ftable _ftable;
  Ttable _ttable;
};

/*
 * key is the mingled name of the symbol.
 * hash is the hash of the mingled name.
 */

static
inline int _symtable_keycmpfunc(void *key1, void *key2)
{
  char* _key1 = (char*)key1; 
  char* _key2 = (char*)key2; 

  return strcmp(_key1, _key2) == 0;
}

static
inline hash_t _symtable_hashfunc(void *key)
{
  return hash_str((char*)key); 
}

static
Symbol _symtable_create_symbol(
  SymTable symtable,
  hex_symbol_type_t symbol_type,
  char *module_name,
  void *entry)
{
  HEX_ASSERT(symtable);
  HEX_ASSERT(module_name);

  Symbol symbol = HEX_MALLOC(struct HexSymbol);
  memset(symbol, 0, sizeof(struct HexSymbol));

  char *mingled_name=NULL;

  switch(symbol_type)
  {
    case HEX_SYMBOL_TYPE_TYPE:
      {
        symbol->_ttable_entry = (TtableEntry)entry;
        symbol->id = ttable_get_entry_id(symbol->_ttable_entry);
        mingled_name = ttable_mingle_name((TtableEntry)entry);
      }
      break;
    case HEX_SYMBOL_TYPE_LOCAL_VARIABLE:
    case HEX_SYMBOL_TYPE_GLOBAL_VARIABLE:
    case HEX_SYMBOL_TYPE_MEMBER:
      {
        symbol->_vtable_entry = (VtableEntry)entry;
        symbol->id = symbol->_vtable_entry->id;
        mingled_name = vtable_mingle_name((VtableEntry)entry); 
      }
      break;
    case HEX_SYMBOL_TYPE_FUNC:
    case HEX_SYMBOL_TYPE_METHOD:
      {
        symbol->_ftable_entry = (FtableEntry)entry;
        symbol->id = symbol->_ftable_entry->id;
        mingled_name = ftable_mingle_name((FtableEntry)entry);
      }
      break;
    default:
      return NULL;
      break;
  }

  symbol->symbol_type = symbol_type;
  symbol->module_name = strdup(module_name);

  void* p = hashmap_put(
    symtable->_hashmap,
    mingled_name, 
    symbol
  );

  HEX_ASSERT(p);

  return symbol;
}

typedef struct HexSymTableLookupArg {
  char *module_name;
  char *mingled_name;
} *SymTableLookupArg;

static
int _symtable_lookup(void* key, void *value, void *arg)
{
  HEX_ASSERT(key);
  HEX_ASSERT(value);
  HEX_ASSERT(arg);

  char *symbol_mingled_name = (char*)key;
  Symbol symbol = (Symbol)value;
  SymTableLookupArg _arg= (SymTableLookupArg)arg;

  return strcmp(symbol_mingled_name, _arg->mingled_name) == 0 &&
    strcmp(symbol->module_name, _arg->module_name) == 0;
}

static
Symbol _symtable_get_symbol(SymTable symtable, char* module_name, char* mingled_name)
{
  HEX_ASSERT(symtable);

  struct HexSymTableLookupArg arg = {
    .module_name = module_name,
    .mingled_name = mingled_name
  };

  Symbol symbol = hashmap_lookup(
    symtable->_hashmap,
    _symtable_lookup,
    &arg
  );

  return symbol;
}

SymTable symtable_create()
{
  Hashmap hashmap = hashmap_create(
    DEFAULT_SYMTABLE_CAPACITY,
    _symtable_hashfunc,
    _symtable_keycmpfunc
  );

  Vtable vtable = vtable_create();
  Ftable ftable = ftable_create();
  Ttable ttable = ttable_create();

  SymTable symtable = HEX_MALLOC(struct HexSymTable);
  
  if(!symtable) {
    errno = ENOMEM;
    return NULL;
  }

  symtable->_hashmap = hashmap;
  symtable->_vtable = vtable;
  symtable->_ftable = ftable;
  symtable->_ttable = ttable;

  return symtable;
}

void symtable_free(SymTable *symtable)
{
  SymTable _symtable = *symtable;

  HEX_ASSERT(_symtable);

  hashmap_free(&_symtable->_hashmap);
  vtable_free(&_symtable->_vtable);
  ftable_free(&_symtable->_ftable);
  ttable_free(&_symtable->_ttable);

  HEX_FREE(_symtable);

  *symtable = _symtable;
}

size_t symtable_size(SymTable symtable)
{
  HEX_ASSERT(symtable);
  return hashmap_size(symtable->_hashmap);
}

size_t symtable_capacity(SymTable symtable)
{
  HEX_ASSERT(symtable);
  return hashmap_capacity(symtable->_hashmap);
}

int symtable_compare_symbols(Symbol symbol_1, Symbol symbol_2)
{
  HEX_ASSERT(symbol_1);
  HEX_ASSERT(symbol_2);

  RETURN_VAL_IF_TRUE(symbol_1->symbol_type != symbol_2->symbol_type, 0);

  RETURN_VAL_IF_TRUE(
    strcmp(symbol_1->module_name, symbol_2->module_name) != 0,
    0
  );

  switch(symbol_1->symbol_type)
  {
    case HEX_SYMBOL_TYPE_TYPE:
      {
        return ttable_compare_entry(symbol_1->_ttable_entry, symbol_2->_ttable_entry);       
      }
      break;
    case HEX_SYMBOL_TYPE_LOCAL_VARIABLE:
    case HEX_SYMBOL_TYPE_GLOBAL_VARIABLE:
    case HEX_SYMBOL_TYPE_MEMBER:
      {
        return vtable_compare(symbol_1->_vtable_entry, symbol_2->_vtable_entry);
      }
      break;
    case HEX_SYMBOL_TYPE_FUNC:
    case HEX_SYMBOL_TYPE_METHOD:
      {
        return ftable_compare(symbol_1->_ftable_entry, symbol_2->_ftable_entry);
      }
      break;
    default:
      return 0;
  }

  return 1;
}

Symbol symtable_put_var(
  SymTable symtable,
  char *module_name,
  hex_symbol_type_t symbol_type,
  hex_scope_type_t scope_type,
  char *name,
  hex_type_t type,
  hex_type_qualifier_t type_qualifier,
  unsigned int indent_level)
{
  HEX_ASSERT(symtable);
  HEX_ASSERT(module_name);

  switch(symbol_type)
  {
    case HEX_SYMBOL_TYPE_LOCAL_VARIABLE:
    case HEX_SYMBOL_TYPE_GLOBAL_VARIABLE:
      {
        VtableEntry entry = vtable_put(
          symtable->_vtable,
          module_name,
          name,
          scope_type,
          type,
          type_qualifier,
          indent_level
        );

        return _symtable_create_symbol(symtable, symbol_type, module_name, entry);
      }
      break;
    default:
      break;
  }

  return NULL;
}

Symbol symtable_lookup_var(
  SymTable symtable,
  char *module_name,
  char *name,
  unsigned int indent_level)
{
  HEX_ASSERT(symtable);
  HEX_ASSERT(module_name);

  VtableEntry entry = vtable_lookup(
    symtable->_vtable,
    module_name,
    name,
    indent_level
  );

  return _symtable_get_symbol(symtable, module_name, vtable_mingle_name(entry));
}

Symbol symtable_put_func(
  SymTable symtable,
  char *module_name,
  char *name,
  hex_type_t return_type,
  void *paramlist)
{
  HEX_ASSERT(symtable);

  FtableEntry entry = ftable_put(
    symtable->_ftable,
    module_name,
    name,
    return_type,
    paramlist
  );

  return _symtable_create_symbol(symtable, HEX_SYMBOL_TYPE_FUNC, module_name, entry);
}

Symbol symtable_lookup_func(
  SymTable symtable, char *module_name, char *name, void* paramlist)
{
  HEX_ASSERT(symtable);
  HEX_ASSERT(module_name);

  FtableEntry entry = ftable_lookup(
    symtable->_ftable,
    module_name,
    name,
    paramlist
  );

  return _symtable_get_symbol(symtable, module_name, ftable_mingle_name(entry));
}

Symbol symtable_put_type(
  SymTable symtable,
  char *module_name,
  char *name)
{
  HEX_ASSERT(symtable);
  HEX_ASSERT(module_name);
  HEX_ASSERT(name);

  TtableEntry entry = ttable_put(
    symtable->_ttable,
    module_name,
    name
  );

  return _symtable_create_symbol(symtable, HEX_SYMBOL_TYPE_TYPE, module_name, entry);
}

Symbol symtable_put_member(
  SymTable symtable,
  char *module_name,
  char *type_name,
  char *member_name,
  hex_type_t type,
  hex_type_qualifier_t type_qualifier)
{
  HEX_ASSERT(symtable);
  HEX_ASSERT(module_name);

  VtableEntry entry = (VtableEntry)ttable_put_member(
    symtable->_ttable,
    module_name,
    type_name,
    member_name,
    type,
    type_qualifier
  );

  return _symtable_create_symbol(symtable, HEX_SYMBOL_TYPE_MEMBER, module_name, entry);
}

Symbol symtable_put_method(
  SymTable symtable,
  char *module_name,
  char *type_name,
  char *method_name,
  hex_type_t return_type,
  void *paramlist)
{
  HEX_ASSERT(symtable);

  FtableEntry entry = (FtableEntry)ttable_put_method(
    symtable->_ttable,
    module_name,
    type_name,
    method_name,
    return_type,
    paramlist
  );

  return _symtable_create_symbol(symtable, HEX_SYMBOL_TYPE_METHOD, module_name, entry);
}

Symbol symtable_lookup_type(
  SymTable symtable,
  char *module_name,
  char *name)
{
  HEX_ASSERT(symtable);
  HEX_ASSERT(module_name);
  HEX_ASSERT(name);

  TtableEntry entry = ttable_lookup(
    symtable->_ttable,
    module_name,
    name
  );

  RETURN_VAL_IF_NULL(entry, NULL);

  return _symtable_get_symbol(symtable, module_name, ttable_mingle_name(entry)); 
}

Symbol symtable_lookup_member(
  SymTable symtable,
  char *module_name,
  char *type_name,
  char *member_name)
{
  HEX_ASSERT(symtable);

  VtableEntry entry = (VtableEntry)ttable_lookup_member(
    symtable->_ttable,
    module_name,
    type_name,
    member_name
  );

  return _symtable_get_symbol(symtable, module_name, vtable_mingle_name(entry));
}

Symbol symtable_lookup_method(
  SymTable symtable,
  char *module_name,
  char *type_name,
  char *method_name,
  void *paramlist)
{
  HEX_ASSERT(symtable);

  FtableEntry entry = (FtableEntry)ttable_lookup_method(
    symtable->_ttable,
    module_name,
    type_name,
    method_name,
    paramlist
  );

  return _symtable_get_symbol(symtable, module_name, ftable_mingle_name(entry));
}
