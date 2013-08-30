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

/* Unit tests for base/assert.h */

#include "../unittest.h"
#include "../assert.h"

TEST(AssertTest, TestAssertLiterals) {
  HEX_ASSERT(1);
  HEX_ASSERT(' ');
  HEX_ASSERT("");
}

TEST(AssertTest, TestAssertExpressions) {
  HEX_ASSERT(1 || 0);
  HEX_ASSERT(true || false);
  HEX_ASSERT(1==1 || 1==0);
  HEX_ASSERT(1 && 1);
  HEX_ASSERT(1==0x01);
  HEX_ASSERT(1==(1==1?1:0));
}
