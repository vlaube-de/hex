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

#include <stdlib.h>
#include <stdio.h>
#include "yacc_extern.h"
#include "hex_parser.h"

int
main(int argc, char **argv)
{
  int res = 0;

  res = hex_parse(argv[1]);

  if(res == 0) {
    printf("Hex Parsing successful.\n");
  } else if(res == 1) {
    printf("Hex Parse error!!!\n");
    exit(EXIT_FAILURE);
  } else if(res == 2) {
    printf("Hex insufficient memory for parsing!\n");
    exit(EXIT_FAILURE);
  }
}
