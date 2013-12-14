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

/* Stub for HEX parser.
 *
 * Calls the HEX parser to parse the input file.
 * i.e.
 * parser_stub.out tests/hex_sample.hex
 */

#include <stdlib.h>
#include <stdio.h>
#include "hex_parser.h"

int
main(int argc, char **argv)
{
  printf("Parsing file: %s ...\n", argv[1]);

  HexParser *parser = new HexParser();
  int res = parser->parse_from_file(argv[1], NULL);

  delete parser;

  if(res == 0) {
    printf("Hex Parsing successful.\n");
  } else if(res == 1) {
    printf("Hex Parse error!!!\n");
    exit(EXIT_FAILURE);
  } else if(res == 2) {
    printf("Hex insufficient memory for parsing!\n");
    exit(EXIT_FAILURE);
  }

  return 0;
}