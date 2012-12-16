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

#include <stddef.h>
#include "paramlist_factory.h"
#include "../../../base/utils.h"
#include "../../../base/memory.h"
#include "../../ast.h"

using ::testing::factory::ParamlistFactory;
using ::testing::factory::FactoryBase;


void* ParamlistFactory::create()
{
  size_t size = hex_rand_range(1, 5);

  ParameterList head = NULL; 

  while(size > 0) {
    ParameterList node = HEX_MALLOC(struct HexParameterList);
    Parameter param = HEX_MALLOC(struct HexParameter);

    memset(node, 0, sizeof(struct HexParameterList));

    param->type_qualifier_list = NULL;
    param->type_specifier = 0x01;
    param->parameter_name = generate_text(5, 10);
    param->is_ref = 0;

    node->parameter = param;

    if(head != NULL) {
      node->next = head;
    }

    head = node;

    size--;
  }

  _instances.push_back(head);

  return head;
}

void ParamlistFactory::clear()
{
  std::list<void*>::iterator it;
  for(it = _instances.begin(); it != _instances.end(); it++) {
    void *p = (void*)(*it);
    ParameterList paramlist = (ParameterList)p;

    ParameterList next=NULL;

    while(paramlist) {
      next = paramlist->next;

      Parameter param = paramlist->parameter;

      HEX_FREE(param->parameter_name);
      HEX_FREE(param);
      HEX_FREE(paramlist);

      paramlist = next;
    }
  }
}
