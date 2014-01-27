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

#include "ast_node.h"

#ifndef _AST_ASSIGNMENT_FEATURE_H_
#define _AST_ASSIGNMENT_FEATURE_H_

enum HexAstAssignmentFeatureEnum {
  HEX_AST_ASSIGNMENT_FEATURE_NONE = 0x01,
  HEX_AST_ASSIGNMENT_FEATURE_DEFER = 0x02
};

typedef class _HexAstAssignmentFeature : public _HexAstNode {
public:
  _HexAstAssignmentFeature(HexAstAssignmentFeatureEnum feature):
    _feature(feature)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    HEX_ASSERT(this->feature());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstAssignmentFeatureEnum feature() { return _feature; }

private:
  HexAstAssignmentFeatureEnum _feature;
} * HexAstAssignmentFeature;

#endif /* _AST_ASSIGNMENT_FEATURE_H_ */