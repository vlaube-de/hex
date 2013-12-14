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

/*


                              |
                        --====|====--
                              |  
                          .-"""""-. 
                        .'_________'. 
                       /_/_|__|__|_\_\
                      ;'-._       _.-';
 ,--------------------|    `-. .-'    |--------------------,
  ``""--..__    ___   ;       '       ;   ___    __..--""``
            `"-// \\.._\             /_..// \\-"`
               \\_//    '._       _.'    \\_//
                `"`        ``---``        `"`
*/

#include <vector>
#include "hex_parser_test_file.h"
#include "parser_test_base.h"

#ifndef _HEX_PARSER_XML_TEST_BASE_H_
#define _HEX_PARSER_XML_TEST_BASE_H_

class HexParserXmlTestBase : public HexParserTestBase {
protected:
  HexParserXmlTestBase(std::vector<HexTestFile> testfiles):
    HexParserTestBase(testfiles)
  {
    // Do nothing here.
  }

  virtual void test(int index);
};

#endif /* #ifndef _HEX_PARSER_XML_TEST_BASE_H_ */