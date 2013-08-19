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


#include <stdio.h>
#include "parser.tab.hh"
#include "yacc_extern.h"

int hex_parse(const char *path)
{
  int res = 0;
  if((yyin = fopen(path, "r")) == 0) {
    printf("Failed opening file %s\n", path);
    return -1;
  }

  YY_FLUSH_BUFFER;
  yylex();
  res = yyparse(yyin);

  return res;
}
