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

#ifndef _SYMTABLE_H_
#define _SYMTABLE_H_

#include <stddef.h>
#include "ast.h"
#include "types.h"
#include "scope.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HEX_SYMBOL_TYPE_TYPE                            0x0001
#define HEX_SYMBOL_TYPE_LOCAL_VARIABLE                  0x0002
#define HEX_SYMBOL_TYPE_GLOBAL_VARIABLE                 0x0004
#define HEX_SYMBOL_TYPE_FUNC                            0x0008
#define HEX_SYMBOL_TYPE_METHOD                          0x0016
#define HEX_SYMBOL_TYPE_MEMBER                          0x0032


typedef unsigned int hex_symbol_type_t;

typedef struct HexSymbol *Symbol;

typedef struct HexSymTable *SymTable;

SymTable symtable_create();

void symtable_free(SymTable*);

size_t symtable_size(SymTable);

size_t symtable_capacity(SymTable);

int symtable_compare_symbols(Symbol, Symbol);

Symbol symtable_put_var(
  SymTable symtable,
  char* module_name,
  hex_symbol_type_t symbol_type,
  hex_scope_type_t scope_type,
  char *name,
  hex_type_t type,
  hex_type_qualifier_t type_qualifier,
  unsigned int indent_level);

Symbol symtable_lookup_var(
  SymTable symtable, 
  char *module_name,
  char *name,
  unsigned int indent_level);

Symbol symtable_put_func(
  SymTable symtable,
  char *module_name,
  char *name,
  hex_type_t return_type,
  void *paramlist);

Symbol symtable_lookup_func(
  SymTable symtable,
  char *module_name,
  char *name,
  void* paramlist);

Symbol symtable_put_type(
  SymTable symtable,
  char *module_name,
  char *name);

Symbol symtable_put_member(
  SymTable symtable,
  char *module_name,
  char *type_name,
  char *member_name,
  hex_type_t type,
  hex_type_qualifier_t type_qualifier);

Symbol symtable_put_method(
  SymTable symtable,
  char *module_name,
  char *type_name,
  char *method_name,
  hex_type_t return_type,
  void *paramlist);

Symbol symtable_lookup_type(
  SymTable symtable,
  char *module_name,
  char *name);

Symbol symtable_lookup_member(
  SymTable symtable,
  char *module_name,
  char *type_name,
  char *member_name);

Symbol symtable_lookup_method(
  SymTable symtable,
  char *module_name,
  char *type_name,
  char *method_name,
  void *paramlist);


#ifdef __cplusplus
}
#endif


#endif /* _SYMTABLE_H_ */
