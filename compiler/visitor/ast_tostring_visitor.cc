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

// #include <stdio.h>
#include <algorithm>
#include "../ast/ast.h"
#include "ast_tostring_visitor.h"
#include "../../base/strbuf.h"
#include "../../base/assert.h"

AstToStringVisitor::AstToStringVisitor()
  :_strbuf(strbuf_create())
{
  HEX_ASSERT(_strbuf);
}

AstToStringVisitor::~AstToStringVisitor()
{
  strbuf_free(&_strbuf);
}

c_str
AstToStringVisitor::str()
{
  return strbuf_cstr(_strbuf);
}

void
AstToStringVisitor::append(const c_str s)
{
  strbuf_append(this->_strbuf, strdup(s));
}

template<class T, class Function>
void
AstToStringVisitor::iterate(std::list<T>* list, Function f, const c_str delimiter, bool breakOnLast)
{
  typename std::list<T>::iterator itr;
  for(itr=list->begin(); itr != list->end();) {
    f((T)(*itr));
    if(++itr == list->end() && breakOnLast) break;
    this->append(delimiter);
  }
}

HexAstIdentifier
AstToStringVisitor::visit(HexAstIdentifier identifier_)
{
  HexAstIdentifier identifier = AstVisitor::visit(identifier_);

  this->append(identifier->value());

  return identifier;
}

HexAstIntegerLiteral
AstToStringVisitor::visit(HexAstIntegerLiteral literal_)
{
  HexAstIntegerLiteral literal = AstVisitor::visit(literal_);

  this->append(literal->value());

  return literal;
}

HexAstFloatLiteral
AstToStringVisitor::visit(HexAstFloatLiteral literal_)
{
  HexAstFloatLiteral literal = AstVisitor::visit(literal_);

  this->append(literal->value());

  return literal;
}

HexAstStringLiteral
AstToStringVisitor::visit(HexAstStringLiteral literal_)
{
  HexAstStringLiteral literal = AstVisitor::visit(literal_);

  this->append(literal->value());

  return literal;
}

HexAstCall
AstToStringVisitor::visit(HexAstCall call_)
{
  HexAstCall call = AstVisitor::visit(call_);

  call->source()->accept(this);
  this->append("(");
  if(call->arglist()) {
    call->arglist()->accept(this);
  }
  this->append(")");

  if(call->isAsync()) {
    this->append(" async");
  }

  return call;
}

HexAstAttributeRef
AstToStringVisitor::visit(HexAstAttributeRef ref_)
{
  HexAstAttributeRef ref = AstVisitor::visit(ref_);

  ref->source()->accept(this);
  this->append(".");
  ref->attribute()->accept(this);

  return ref;
}

HexAstSlicing
AstToStringVisitor::visit(HexAstSlicing slicing_)
{
  HexAstSlicing slicing = AstVisitor::visit(slicing_);

  slicing->source()->accept(this);
  this->append("[");
  slicing->slice()->accept(this);
  this->append("]");

  return slicing;
}

HexAstTargetList
AstToStringVisitor::visit(HexAstTargetList targets_)
{
  HexAstTargetList targets = AstVisitor::visit(targets_);

  this->iterate<HexAstIdentifier>(
    targets->list(),
    [this](HexAstIdentifier identifier) {
      identifier->accept(this);
    },
    this->_commaDelimiter
  );

  return targets;
}

HexAstName
AstToStringVisitor::visit(HexAstName name_)
{
  HexAstName name = AstVisitor::visit(name_);

  this->iterate<HexAstIdentifier>(
    name->list(),
    [this](HexAstIdentifier identifier) {
      identifier->accept(this);
    },
    this->_dotDelimiter
  );

  return name;
}

HexAstPositiveExpr
AstToStringVisitor::visit(HexAstPositiveExpr expr_)
{
  HexAstPositiveExpr expr = AstVisitor::visit(expr_);

  this->append("+");
  expr->expr()->accept(this);

  return expr;
}

HexAstNegativeExpr
AstToStringVisitor::visit(HexAstNegativeExpr expr_)
{
  HexAstNegativeExpr expr = AstVisitor::visit(expr_);

  this->append("-");
  expr->expr()->accept(this);

  return expr;
}

HexAstNotExpr
AstToStringVisitor::visit(HexAstNotExpr expr_)
{
  HexAstNotExpr expr = AstVisitor::visit(expr_);

  this->append("not ");
  expr->expr()->accept(this);

  return expr;
}

HexAstBitwiseNotExpr
AstToStringVisitor::visit(HexAstBitwiseNotExpr expr_)
{
  HexAstBitwiseNotExpr expr = AstVisitor::visit(expr_);

  this->append("~");
  expr->expr()->accept(this);

  return expr;
}

HexAstIncrementExpr
AstToStringVisitor::visit(HexAstIncrementExpr expr_)
{
  HexAstIncrementExpr expr = AstVisitor::visit(expr_);

  expr->expr()->accept(this);
  this->append("++");

  return expr;
}

HexAstDecrementExpr
AstToStringVisitor::visit(HexAstDecrementExpr expr_)
{
  HexAstDecrementExpr expr = AstVisitor::visit(expr_);

  expr->expr()->accept(this);
  this->append("--");

  return expr;
}

HexAstExistentialExpr
AstToStringVisitor::visit(HexAstExistentialExpr expr_)
{
  HexAstExistentialExpr expr = AstVisitor::visit(expr_);

  expr->expr()->accept(this);
  this->append("?");

  return expr;
}

HexAstAddExpr
AstToStringVisitor::visit(HexAstAddExpr expr_)
{
  HexAstAddExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" + ");
  expr->right()->accept(this);

  return expr;
}

HexAstMinusExpr
AstToStringVisitor::visit(HexAstMinusExpr expr_)
{
  HexAstMinusExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" - ");
  expr->right()->accept(this);

  return expr;
}

HexAstMultiplyExpr
AstToStringVisitor::visit(HexAstMultiplyExpr expr_)
{
  HexAstMultiplyExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" * ");
  expr->right()->accept(this);

  return expr;
}

HexAstDivideExpr
AstToStringVisitor::visit(HexAstDivideExpr expr_)
{
  HexAstDivideExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" / ");
  expr->right()->accept(this);

  return expr;
}

HexAstModulusExpr
AstToStringVisitor::visit(HexAstModulusExpr expr_)
{
  HexAstModulusExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" % ");
  expr->right()->accept(this);

  return expr;
}

HexAstPowerExpr
AstToStringVisitor::visit(HexAstPowerExpr expr_)
{
  HexAstPowerExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" ** ");
  expr->right()->accept(this);

  return expr;
}

HexAstBitwiseAndExpr
AstToStringVisitor::visit(HexAstBitwiseAndExpr expr_)
{
  HexAstBitwiseAndExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" & ");
  expr->right()->accept(this);

  return expr;
}

HexAstBitwiseOrExpr
AstToStringVisitor::visit(HexAstBitwiseOrExpr expr_)
{
  HexAstBitwiseOrExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" | ");
  expr->right()->accept(this);

  return expr;
}

HexAstBitwiseXorExpr
AstToStringVisitor::visit(HexAstBitwiseXorExpr expr_)
{
  HexAstBitwiseXorExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" ^ ");
  expr->right()->accept(this);

  return expr;
}

HexAstBitwiseShiftLeftExpr
AstToStringVisitor::visit(HexAstBitwiseShiftLeftExpr expr_)
{
  HexAstBitwiseShiftLeftExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" << ");
  expr->right()->accept(this);

  return expr;
}

HexAstBitwiseShiftRightExpr
AstToStringVisitor::visit(HexAstBitwiseShiftRightExpr expr_)
{
  HexAstBitwiseShiftRightExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" >> ");
  expr->right()->accept(this);

  return expr;
}

HexAstEqualsExpr
AstToStringVisitor::visit(HexAstEqualsExpr expr_)
{
  HexAstEqualsExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" == ");
  expr->right()->accept(this);

  return expr;
}

HexAstNotEqualExpr
AstToStringVisitor::visit(HexAstNotEqualExpr expr_)
{
  HexAstNotEqualExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" != ");
  expr->right()->accept(this);

  return expr;
}

HexAstIsExpr
AstToStringVisitor::visit(HexAstIsExpr expr_)
{
  HexAstIsExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" is ");
  expr->right()->accept(this);

  return expr;
}

HexAstIsNotExpr
AstToStringVisitor::visit(HexAstIsNotExpr expr_)
{
  HexAstIsNotExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" is not ");
  expr->right()->accept(this);

  return expr;
}

HexAstLessThanExpr
AstToStringVisitor::visit(HexAstLessThanExpr expr_)
{
  HexAstLessThanExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" < ");
  expr->right()->accept(this);

  return expr;
}

HexAstGreaterThanExpr
AstToStringVisitor::visit(HexAstGreaterThanExpr expr_)
{
  HexAstGreaterThanExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" > ");
  expr->right()->accept(this);

  return expr;
}

HexAstGreaterOrEqualsExpr
AstToStringVisitor::visit(HexAstGreaterOrEqualsExpr expr_)
{
  HexAstGreaterOrEqualsExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" >= ");
  expr->right()->accept(this);

  return expr;
}

HexAstLessOrEqualsExpr
AstToStringVisitor::visit(HexAstLessOrEqualsExpr expr_)
{
  HexAstLessOrEqualsExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" <= ");
  expr->right()->accept(this);

  return expr;
}

HexAstInExpr
AstToStringVisitor::visit(HexAstInExpr expr_)
{
  HexAstInExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" in ");
  expr->right()->accept(this);

  return expr;
}

HexAstNotInExpr
AstToStringVisitor::visit(HexAstNotInExpr expr_)
{
  HexAstNotInExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" not in ");
  expr->right()->accept(this);

  return expr;
}

HexAstAndExpr
AstToStringVisitor::visit(HexAstAndExpr expr_)
{
  HexAstAndExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" and ");
  expr->right()->accept(this);

  return expr;
}

HexAstOrExpr
AstToStringVisitor::visit(HexAstOrExpr expr_)
{
  HexAstOrExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" or ");
  expr->right()->accept(this);

  return expr;
}

HexAstInclusiveRangeExpr
AstToStringVisitor::visit(HexAstInclusiveRangeExpr expr_)
{
  HexAstInclusiveRangeExpr expr = AstVisitor::visit(expr_);

  if(expr->begin()) expr->begin()->accept(this);
  this->append("...");
  if(expr->end()) expr->end()->accept(this);

  return expr;
}

HexAstExclusiveRangeExpr
AstToStringVisitor::visit(HexAstExclusiveRangeExpr expr_)
{
  HexAstExclusiveRangeExpr expr = AstVisitor::visit(expr_);

  if(expr->begin()) expr->begin()->accept(this);
  this->append("..");
  if(expr->end()) expr->end()->accept(this);

  return expr;
}

HexAstPseudoAssignPlusExpr
AstToStringVisitor::visit(HexAstPseudoAssignPlusExpr expr_)
{
  HexAstPseudoAssignPlusExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" += ");
  expr->right()->accept(this);

  return expr;
}

HexAstPseudoAssignMinusExpr
AstToStringVisitor::visit(HexAstPseudoAssignMinusExpr expr_)
{
  HexAstPseudoAssignMinusExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" -= ");
  expr->right()->accept(this);

  return expr;
}

HexAstPseudoAssignMultiplyExpr
AstToStringVisitor::visit(HexAstPseudoAssignMultiplyExpr expr_)
{
  HexAstPseudoAssignMultiplyExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" *= ");
  expr->right()->accept(this);

  return expr;
}

HexAstPseudoAssignDivideExpr
AstToStringVisitor::visit(HexAstPseudoAssignDivideExpr expr_)
{
  HexAstPseudoAssignDivideExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" /= ");
  expr->right()->accept(this);

  return expr;
}

HexAstPseudoAssignModulusExpr
AstToStringVisitor::visit(HexAstPseudoAssignModulusExpr expr_)
{
  HexAstPseudoAssignModulusExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" %= ");
  expr->right()->accept(this);

  return expr;
}

HexAstPseudoAssignBitwiseAndExpr
AstToStringVisitor::visit(HexAstPseudoAssignBitwiseAndExpr expr_)
{
  HexAstPseudoAssignBitwiseAndExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" &= ");
  expr->right()->accept(this);

  return expr;
}

HexAstPseudoAssignBitwiseOrExpr
AstToStringVisitor::visit(HexAstPseudoAssignBitwiseOrExpr expr_)
{
  HexAstPseudoAssignBitwiseOrExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" |= ");
  expr->right()->accept(this);

  return expr;
}

HexAstPseudoAssignBitwiseXorExpr
AstToStringVisitor::visit(HexAstPseudoAssignBitwiseXorExpr expr_)
{
  HexAstPseudoAssignBitwiseXorExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" ^= ");
  expr->right()->accept(this);

  return expr;
}

HexAstPseudoAssignBitwiseLeftShiftExpr
AstToStringVisitor::visit(HexAstPseudoAssignBitwiseLeftShiftExpr expr_)
{
  HexAstPseudoAssignBitwiseLeftShiftExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" <<= ");
  expr->right()->accept(this);

  return expr;
}

HexAstPseudoAssignBitwiseRightShiftExpr
AstToStringVisitor::visit(HexAstPseudoAssignBitwiseRightShiftExpr expr_)
{
  HexAstPseudoAssignBitwiseRightShiftExpr expr = AstVisitor::visit(expr_);

  expr->left()->accept(this);
  this->append(" >>= ");
  expr->right()->accept(this);

  return expr;
}

HexAstConditionalExpr
AstToStringVisitor::visit(HexAstConditionalExpr expr_)
{
  HexAstConditionalExpr expr = AstVisitor::visit(expr_);

  this->append("if ");
  expr->predicate()->accept(this);
  this->append(" then ");
  expr->consequent()->accept(this);
  this->append(" else ");
  expr->alternate()->accept(this);

  return expr;
}

HexAstYieldExpr
AstToStringVisitor::visit(HexAstYieldExpr expr_)
{
  HexAstYieldExpr expr = AstVisitor::visit(expr_);

  this->append("yield");
  if(expr->exprs()) {
    this->append(" (");
    expr->exprs()->accept(this);
    this->append(")");
  }

  return expr;
}

HexAstStringExpr
AstToStringVisitor::visit(HexAstStringExpr expr_)
{
  HexAstStringExpr expr = AstVisitor::visit(expr_);

  expr->string()->accept(this);
  this->append("%");
  this->append("(");
  expr->exprs()->accept(this);
  this->append(")");

  return expr;
}

HexAstParenForm
AstToStringVisitor::visit(HexAstParenForm form_)
{
  HexAstParenForm form = AstVisitor::visit(form_);

  this->append("(");
  if(form->exprs()) {
    form->exprs()->accept(this);
  }
  this->append(")");

  return form; 
}

HexAstExprList
AstToStringVisitor::visit(HexAstExprList exprlist_)
{
  HexAstExprList exprlist = AstVisitor::visit(exprlist_);

  this->iterate<HexAstExpr>(
    exprlist->list(),
    [this](HexAstExpr expr) {
      expr->accept(this);
    },
    this->_commaDelimiter
  );

  return exprlist;
}

HexAstSimpleParam
AstToStringVisitor::visit(HexAstSimpleParam param_)
{
  HexAstSimpleParam param = AstVisitor::visit(param_);

  if(param->type()) {
    this->append("@");
    param->type()->accept(this);
    this->append(" ");
  }
  param->name()->accept(this);

  return param;
}

HexAstSimpleParamList
AstToStringVisitor::visit(HexAstSimpleParamList params_)
{
  HexAstSimpleParamList params = AstVisitor::visit(params_);

  this->iterate<HexAstSimpleParam>(
    params->list(),
    [this](HexAstSimpleParam param) {
      param->accept(this);
    },
    this->_commaDelimiter
  );

  return params;
}

HexAstKeywordParam
AstToStringVisitor::visit(HexAstKeywordParam param_)
{
  HexAstKeywordParam param = AstVisitor::visit(param_);

  if(param->type()) {
    this->append("@");
    param->type()->accept(this);
    this->append(" ");
  }
  param->name()->accept(this);
  this->append("=");
  param->value()->accept(this);

  return param;
}

HexAstKeywordParamList
AstToStringVisitor::visit(HexAstKeywordParamList params_)
{
  HexAstKeywordParamList params = AstVisitor::visit(params_);

  this->iterate<HexAstKeywordParam>(
    params->list(),
    [this](HexAstKeywordParam param) {
      param->accept(this);
    },
    this->_commaDelimiter
  ); 

  return params;
}

HexAstKeywordVal
AstToStringVisitor::visit(HexAstKeywordVal keyval_)
{
  HexAstKeywordVal keyval = AstVisitor::visit(keyval_);

  keyval->key()->accept(this);
  this->append("=");
  keyval->val()->accept(this);

  return keyval;
}

HexAstKeywordValList
AstToStringVisitor::visit(HexAstKeywordValList list_)
{
  HexAstKeywordValList list = AstVisitor::visit(list_);

  this->iterate<HexAstKeywordVal>(
    list->list(),
    [this](HexAstKeywordVal val) {
      val->accept(this);
    },
    this->_commaDelimiter
  );

  return list;
}

HexAstParameterList
AstToStringVisitor::visit(HexAstParameterList params_)
{
  HexAstParameterList params = AstVisitor::visit(params_);

  bool prev = false;

  if(params->simple_params()) {
    params->simple_params()->accept(this);
    prev = true;
  }

  if(params->keyword_params()) {
    if(prev) this->append(", ");
    params->keyword_params()->accept(this); 
    prev = true;
  }

  if(params->args()) {
    if(prev) this->append(", ");
    this->append("*");
    params->args()->accept(this);
    prev = true;
  }

  if(params->kwargs()) {
    if(prev) this->append(", ");
    this->append("**");
    params->kwargs()->accept(this);
    prev = true;
  }

  return params;
}

HexAstValList
AstToStringVisitor::visit(HexAstValList vallist_)
{
  HexAstValList vallist = AstVisitor::visit(vallist_);

  this->iterate<HexAstValAtom>(
    vallist->list(),
    [this](HexAstValAtom val) {
      val->accept(this);
    },
    this->_commaDelimiter
  );

  return vallist;
}

HexAstArgList
AstToStringVisitor::visit(HexAstArgList arglist_)
{
  HexAstArgList arglist = AstVisitor::visit(arglist_);

  bool prev = false;

  if(arglist->simple_args()) {
    arglist->simple_args()->accept(this);
    prev = true;
  }

  if(arglist->keyword_args()) {
    if(prev) this->append(", ");
    arglist->keyword_args()->accept(this);
    prev = true;
  }

  if(arglist->args()) {
    if(prev) this->append(", ");
    this->append("*");
    arglist->args()->accept(this);
    prev = true;
  }

  if(arglist->kwargs()) {
    if(prev) this->append(", ");
    this->append("**");
    arglist->kwargs()->accept(this);
    prev = true;
  }

  return arglist;
}

HexAstComprehension
AstToStringVisitor::visit(HexAstComprehension comprehension_)
{
  HexAstComprehension comprehension = AstVisitor::visit(comprehension_);

  if(comprehension->dst()) {
    comprehension->dst()->accept(this);
    this->append(" ");
  }
  this->append("for ");

  comprehension->candidates()->accept(this);
  this->append(" in ");
  comprehension->src()->accept(this);

  if(comprehension->predicate()) {
    this->append(" if ");
    comprehension->predicate()->accept(this);
  }

  return comprehension;
}

HexAstComprehensionList
AstToStringVisitor::visit(HexAstComprehensionList comprehensions_)
{
  HexAstComprehensionList comprehensions = AstVisitor::visit(comprehensions_);

  this->iterate<HexAstComprehension>(
    comprehensions->list(),
    [this](HexAstComprehension comprehension) {
      comprehension->accept(this);
    },
    this->_spaceDelimiter
  );

  return comprehensions;
}

HexAstExplicitListForm
AstToStringVisitor::visit(HexAstExplicitListForm form_)
{
  HexAstExplicitListForm form = AstVisitor::visit(form_);

  this->append("[");

  if(form->elements()) {
    HexAstExprList elements = form->elements();
    elements->accept(this);
  }

  this->append("]");

  return form;
}

HexAstImplicitListForm
AstToStringVisitor::visit(HexAstImplicitListForm form_)
{
  HexAstImplicitListForm form = AstVisitor::visit(form_);

  this->append("[");

  HexAstComprehensionList comprehensions = form->comprehensions();
  comprehensions->accept(this);

  this->append("]");

  return form;
}

HexAstFieldDef
AstToStringVisitor::visit(HexAstFieldDef def_)
{
  HexAstFieldDef def = AstVisitor::visit(def_);

  if(def->decorators()) {
    def->decorators()->accept(this);
  }

  def->name()->accept(this);
  this->append(": ");
  def->val()->accept(this);

  return def;
}

HexAstFieldDefList
AstToStringVisitor::visit(HexAstFieldDefList list_)
{
  HexAstFieldDefList list = AstVisitor::visit(list_);

  this->iterate<HexAstFieldDef>(
    list->list(),
    [this](HexAstFieldDef field) {
      field->accept(this);
    },
    this->_newlineDelimiter
  );

  return list;
}

HexAstKeyValuePair
AstToStringVisitor::visit(HexAstKeyValuePair pair_)
{
  HexAstKeyValuePair pair = AstVisitor::visit(pair_);

  pair->key()->accept(this);
  this->append(": ");
  pair->value()->accept(this);

  return pair;
}

HexAstKeyValuePairList
AstToStringVisitor::visit(HexAstKeyValuePairList list_)
{
  HexAstKeyValuePairList list = AstVisitor::visit(list_);

  this->iterate<HexAstKeyValuePair>(
    list->list(),
    [this](HexAstKeyValuePair pair) {
      pair->accept(this);
    },
    this->_commaDelimiter
  );

  return list;
}

HexAstExplicitDictForm
AstToStringVisitor::visit(HexAstExplicitDictForm dict_)
{
  HexAstExplicitDictForm dict = AstVisitor::visit(dict_);

  this->append("{");

  if(dict->fields()) {
    HexAstKeyValuePairList fields = dict->fields();
    fields->accept(this);
  }

  this->append("}");

  return dict;
}

HexAstImplicitDictForm
AstToStringVisitor::visit(HexAstImplicitDictForm dict_)
{
  HexAstImplicitDictForm dict = AstVisitor::visit(dict_);

  this->append("{");

  HexAstComprehensionList comprehensions = dict->comprehensions();
  comprehensions->accept(this);

  this->append("}");

  return dict;
}

HexAstDecorator
AstToStringVisitor::visit(HexAstDecorator decorator_)
{
  HexAstDecorator decorator = AstVisitor::visit(decorator_);

  this->append("@");
  decorator->name()->accept(this);
  if(decorator->args()) {
    this->append("(");
    decorator->args()->accept(this);
    this->append(")");
  }

  return decorator;
}

HexAstDecoratorList
AstToStringVisitor::visit(HexAstDecoratorList decorators_)
{
  HexAstDecoratorList decorators = AstVisitor::visit(decorators_);

  this->iterate<HexAstDecorator>(
    decorators->list(),
    [this](HexAstDecorator decorator) {
      decorator->accept(this);
    },
    this->_newlineDelimiter,
    false
  );

  return decorators;
}

HexAstExprListAssignmentStmt
AstToStringVisitor::visit(HexAstExprListAssignmentStmt stmt_)
{
  HexAstExprListAssignmentStmt stmt = AstVisitor::visit(stmt_);

  stmt->target()->accept(this);
  this->append(" = ");
  if(stmt->defer()) {
    this->append(" defer ");
  }

  HexAstExprList exprlist = stmt->src();
  exprlist->accept(this);

  this->append(";");

  return stmt;
}

HexAstLambdaAssignmentStmt
AstToStringVisitor::visit(HexAstLambdaAssignmentStmt stmt_)
{
  HexAstLambdaAssignmentStmt stmt = AstVisitor::visit(stmt_);

  if(stmt->decorators()){
    stmt->decorators()->accept(this);
  }
  stmt->target()->accept(this);
  this->append(" = ");
  if(stmt->defer()) {
    this->append(" defer ");
  }

  HexAstLambda lambda = stmt->src();
  lambda->accept(this);

  this->append(";");

  return stmt;
}

HexAstTaskDefAssignmentStmt
AstToStringVisitor::visit(HexAstTaskDefAssignmentStmt stmt_)
{
  HexAstTaskDefAssignmentStmt stmt = AstVisitor::visit(stmt_);

  stmt->target()->accept(this);
  this->append(" = ");
  if(stmt->defer()) {
    this->append(" defer ");
  }

  HexAstTaskDef task = stmt->src();
  task->accept(this);

  this->append(";");

  return stmt;
}

HexAstUsingSrc
AstToStringVisitor::visit(HexAstUsingSrc src_)
{
  HexAstUsingSrc src = AstVisitor::visit(src_);

  size_t level = src->level();
  HexAstName name = src->name();

  for(int i = 0; i < level; i++) {
    this->append(".");
  }

  if(src->name()) {
    src->name()->accept(this);
  }

  return src;
}

HexAstUsingStmtDirect
AstToStringVisitor::visit(HexAstUsingStmtDirect stmt_)
{
  HexAstUsingStmtDirect stmt = AstVisitor::visit(stmt_);

  this->append("using ");
  stmt->target()->accept(this);

  if(stmt->alias()) {
    this->append(" as ");
    stmt->alias()->accept(this);
  }

  this->append(";");

  return stmt;
}

HexAstUsingStmtRelative
AstToStringVisitor::visit(HexAstUsingStmtRelative stmt_)
{
  HexAstUsingStmtRelative stmt = AstVisitor::visit(stmt_);

  this->append("using ");

  if(stmt->targets()) {
    stmt->targets()->accept(this);
  } else {
    this->append("*");
  }

  this->append(" in ");
  stmt->src()->accept(this);

  if(stmt->alias()) {
    this->append(" as ");
    stmt->alias()->accept(this);
  }

  this->append(";");

  return stmt;
}

HexAstElifStmt
AstToStringVisitor::visit(HexAstElifStmt stmt_)
{
  HexAstElifStmt stmt = AstVisitor::visit(stmt_);

  this->append("elif ");
  stmt->predicate()->accept(this);
  this->append(" {");
  stmt->stmts()->accept(this);
  this->append("}");

  return stmt;
}

HexAstElifStmtGroup
AstToStringVisitor::visit(HexAstElifStmtGroup group_)
{
  HexAstElifStmtGroup group = AstVisitor::visit(group_);

  for_each(group->list()->begin(), group->list()->end(),
    [this](HexAstElifStmt stmt) {
      stmt->accept(this);
      this->append("");
    }
  );

  return group;
}

HexAstElseStmt
AstToStringVisitor::visit(HexAstElseStmt stmt_)
{
  HexAstElseStmt stmt = AstVisitor::visit(stmt_);

  this->append("else {");
  stmt->stmts()->accept(this);
  this->append("}");

  return stmt;
}

HexAstIfStmt
AstToStringVisitor::visit(HexAstIfStmt stmt_)
{
  HexAstIfStmt stmt = AstVisitor::visit(stmt_);

  this->append("if");
  if(stmt->predicate()) {
    this->append(" ");
    stmt->predicate()->accept(this);
  }
  this->append(" {");
  stmt->stmts()->accept(this);
  this->append("}");

  if(stmt->elif_stmts()) {
    stmt->elif_stmts()->accept(this);
    this->append("");
  }
  if(stmt->else_stmt()) {
    stmt->else_stmt()->accept(this);
    this->append("");
  }

  return stmt;
}

HexAstForStmt
AstToStringVisitor::visit(HexAstForStmt stmt_)
{
  HexAstForStmt stmt = AstVisitor::visit(stmt_);

  this->append("for ");
  stmt->targets()->accept(this);
  this->append(" in ");
  stmt->exprs()->accept(this);

  if(stmt->predicate()) {
    this->append(" where ");
    stmt->predicate()->accept(this);
  }

  this->append(" {");
  stmt->stmts()->accept(this);
  this->append("}");

  return stmt;
}

HexAstWithStmt
AstToStringVisitor::visit(HexAstWithStmt stmt_)
{
  HexAstWithStmt stmt = AstVisitor::visit(stmt_);

  this->append("with ");
  stmt->exprs()->accept(this);

  if(stmt->alias()) {
    this->append(" as ");
    stmt->alias()->accept(this);
  }

  this->append(" {");
  stmt->stmts()->accept(this);
  this->append("}");

  return stmt;
}

HexAstLockStmt
AstToStringVisitor::visit(HexAstLockStmt stmt_)
{
  HexAstLockStmt stmt = AstVisitor::visit(stmt_);

  this->append("lock ");
  stmt->exprs()->accept(this);
  this->append(" {");
  stmt->stmts()->accept(this);
  this->append("}");

  return stmt;
}


HexAstWhileStmt
AstToStringVisitor::visit(HexAstWhileStmt stmt_)
{
  HexAstWhileStmt stmt = AstVisitor::visit(stmt_);

  this->append("while ");
  stmt->expr()->accept(this);

  this->append(" {");
  stmt->stmts()->accept(this);
  this->append("}");

  return stmt;
}

HexAstCatchStmt
AstToStringVisitor::visit(HexAstCatchStmt stmt_)
{
  HexAstCatchStmt stmt = AstVisitor::visit(stmt_);

  this->append("catch");
  if(stmt->targets()) {
    this->append(" ");
    stmt->targets()->accept(this);
    if(stmt->alias()) {
      this->append(" as ");
      stmt->alias()->accept(this);
    }
  }

  this->append(" {");
  stmt->stmts()->accept(this);
  this->append("}");

  return stmt;
}

HexAstCatchStmtGroup
AstToStringVisitor::visit(HexAstCatchStmtGroup stmts_)
{
  HexAstCatchStmtGroup stmts = AstVisitor::visit(stmts_);

  this->iterate<HexAstCatchStmt>(
    stmts->list(),
    [this](HexAstCatchStmt stmt) {
      stmt->accept(this);
    },
    this->_nullDelimiter
  );

  return stmts;
}

HexAstTryStmt
AstToStringVisitor::visit(HexAstTryStmt stmt_)
{
  HexAstTryStmt stmt = AstVisitor::visit(stmt_);

  this->append("try {");
  stmt->stmts()->accept(this);
  this->append("}");

  stmt->catch_stmt_group()->accept(this);

  return stmt;
}

HexAstClassDef
AstToStringVisitor::visit(HexAstClassDef def_)
{
  HexAstClassDef def = AstVisitor::visit(def_);

  if(def->decorators()) {
    def->decorators()->accept(this);
  }
  this->append("class ");
  def->name()->accept(this);

  if(def->parent()) {
    this->append(" extends ");
    def->parent()->accept(this);
  }

  if(def->attributes()) {
    this->append(" {");
    def->attributes()->accept(this);
    this->append("\n}");
  } else {
    this->append(";");
  }

  return def;
}

HexAstLambdaSimple
AstToStringVisitor::visit(HexAstLambdaSimple lambda_)
{
  HexAstLambdaSimple lambda = AstVisitor::visit(lambda_);

  this->append("(");
  if(lambda->params()) {
    lambda->params()->accept(this);
  }
  this->append(") -> ");
  lambda->expr()->accept(this);

  return lambda;
}

HexAstLambdaComplex
AstToStringVisitor::visit(HexAstLambdaComplex lambda_)
{
  HexAstLambdaComplex lambda = AstVisitor::visit(lambda_);

  this->append("(");
  if(lambda->params()) {
    lambda->params()->accept(this);
  }

  this->append(") => {");
  lambda->stmts()->accept(this);
  this->append("}");

  return lambda;
}

HexAstInputStmt
AstToStringVisitor::visit(HexAstInputStmt stmt_)
{
  HexAstInputStmt stmt = AstVisitor::visit(stmt_);

  this->iterate<HexAstPrimary>(
    stmt->list(),
    [this](HexAstPrimary primary) {
      primary->accept(this);
    },
    this->_inputDelimiter
  );

  this->append(";");

  return stmt;
}

HexAstOutputStmt
AstToStringVisitor::visit(HexAstOutputStmt stmt_)
{
  HexAstOutputStmt stmt = AstVisitor::visit(stmt_);

  this->iterate<HexAstPrimary>(
    stmt->list(),
    [this](HexAstPrimary primary) {
      primary->accept(this);
    },
    this->_outputDelimiter
  );

  this->append(";");

  return stmt;
}

HexAstTaskState
AstToStringVisitor::visit(HexAstTaskState state_)
{
  HexAstTaskState state = AstVisitor::visit(state_);

  char* s = NULL;

  switch(state->state()) {
    case AST_TASK_STATE_START:
      s = "start";
      break;
    case AST_TASK_STATE_PAUSE:
      s = "pause";
      break;
    case AST_TASK_STATE_CANCEL:
      s = "cancel";
      break;
    case AST_TASK_STATE_RESUME:
      s = "resume";
      break;
    case AST_TASK_STATE_FINISH:
      s = "finish";
      break;
    case AST_TASK_STATE_STOP:
      s = "stop";
      break;
    default:
      break;
  }

  HEX_ASSERT(s);
  this->append(s);

  return state;
}

HexAstConditionalPreposition
AstToStringVisitor::visit(HexAstConditionalPreposition preposition_)
{
  HexAstConditionalPreposition preposition = AstVisitor::visit(preposition_);

  char* s = NULL;

  switch(preposition->preposition()) {
    case AST_TASK_CONDITIONAL_PREPOSITION_BEFORE:
      s = "before";
      break;
    case AST_TASK_CONDITIONAL_PREPOSITION_AFTER:
      s = "after";
      break;
    case AST_TASK_CONDITIONAL_PREPOSITION_WHEN:
      s = "when";
      break;
    default:
      break;
  }

  HEX_ASSERT(s);
  this->append(s);

  return preposition;
}

HexAstConditionalClause
AstToStringVisitor::visit(HexAstConditionalClause clause_)
{
  HexAstConditionalClause clause = AstVisitor::visit(clause_);

  clause->preposition()->accept(this);
  this->append(" ");
  clause->exprs()->accept(this);
  this->append(" ");
  clause->state()->accept(this);

  return clause;
}

HexAstStartClauseSingle
AstToStringVisitor::visit(HexAstStartClauseSingle clause_)
{
  HexAstStartClauseSingle clause = AstVisitor::visit(clause_);

  this->append("start ");
  clause->target()->accept(this);

  if(clause->alias()) {
    this->append(" as ");
    clause->alias()->accept(this);
  }

  if(clause->condition()) {
    this->append(" ");
    clause->condition()->accept(this);
  }

  return clause;
}

HexAstStartClauseMultiple
AstToStringVisitor::visit(HexAstStartClauseMultiple clause_)
{
  HexAstStartClauseMultiple clause = AstVisitor::visit(clause_);

  this->append("start ");

  this->append("(");
  clause->targets()->accept(this);
  this->append(")");

  if(clause->alias()) {
    this->append(" as ");
    clause->alias()->accept(this);
  }

  if(clause->condition()) {
    this->append(" ");
    clause->condition()->accept(this);
  }

  return clause;
}

HexAstPauseClause
AstToStringVisitor::visit(HexAstPauseClause clause_)
{
  HexAstPauseClause clause = AstVisitor::visit(clause_);

  this->append("pause ");
  clause->exprs()->accept(this);
  this->append(" ");
  clause->condition()->accept(this);

  return clause;
}

HexAstResumeClause
AstToStringVisitor::visit(HexAstResumeClause clause_)
{
  HexAstResumeClause clause = AstVisitor::visit(clause_);

  this->append("resume ");
  clause->exprs()->accept(this);
  this->append(" ");
  clause->condition()->accept(this);

  return clause;
}

HexAstCancelClause
AstToStringVisitor::visit(HexAstCancelClause clause_)
{
  HexAstCancelClause clause = AstVisitor::visit(clause_);

  this->append("resume ");
  clause->exprs()->accept(this);
  this->append(" ");
  clause->condition()->accept(this);

  return clause;
}

HexAstConditionalDelayClause
AstToStringVisitor::visit(HexAstConditionalDelayClause clause_)
{
  HexAstConditionalDelayClause clause = AstVisitor::visit(clause_);

  this->append("delay ");
  clause->exprs()->accept(this);
  this->append(" ");
  clause->condition()->accept(this);

  return clause;
}

HexAstFixedDelayClause
AstToStringVisitor::visit(HexAstFixedDelayClause clause_)
{
  HexAstFixedDelayClause clause = AstVisitor::visit(clause_);

  this->append("delay ");
  if(clause->exprs()) {
    this->append(" ");
    clause->exprs()->accept(this);
    this->append(" ");
  }
  this->append("by ");
  clause->delay()->accept(this);

  return clause;
}

HexAstStopClause
AstToStringVisitor::visit(HexAstStopClause clause_)
{
  HexAstStopClause clause = AstVisitor::visit(clause_);

  this->append("stop ");
  clause->exprs()->accept(this);
  this->append(" ");
  clause->condition()->accept(this);

  return clause;
}

HexAstTaskDef
AstToStringVisitor::visit(HexAstTaskDef def_)
{
  HexAstTaskDef def = AstVisitor::visit(def_);

  this->iterate<HexAstTaskClause>(
    def->list(),
    [this](HexAstTaskClause clause) {
      clause->accept(this);
    },
    this->_commaDelimiter
  );

  return def;
}

HexAstAwaitStmt
AstToStringVisitor::visit(HexAstAwaitStmt stmt_)
{
  HexAstAwaitStmt stmt = AstVisitor::visit(stmt_);

  this->append("await {");
  stmt->stmts()->accept(this);
  this->append("}");

  return stmt;
}

HexAstReturnStmt
AstToStringVisitor::visit(HexAstReturnStmt stmt_)
{
  HexAstReturnStmt stmt = AstVisitor::visit(stmt_);

  this->append("return");
  if(stmt->return_vals()) {
    this->append(" ");
    stmt->return_vals()->accept(this);
  }
  if(stmt->predicate()) {
    this->append(" if ");
    stmt->predicate()->accept(this);
  }
  this->append(";");

  return stmt;
}

HexAstBreakStmt
AstToStringVisitor::visit(HexAstBreakStmt stmt_)
{
  HexAstBreakStmt stmt = AstVisitor::visit(stmt_);

  this->append("break");
  if(stmt->predicate()) {
    this->append(" if ");
    stmt->predicate()->accept(this);
  }
  this->append(";");

  return stmt;
}

HexAstContinueStmt
AstToStringVisitor::visit(HexAstContinueStmt stmt_)
{
  HexAstContinueStmt stmt = AstVisitor::visit(stmt_);

  this->append("continue");
  if(stmt->predicate()) {
    this->append(" if ");
    stmt->predicate()->accept(this);
  }
  this->append(";");

  return stmt;
}

HexAstRaiseStmt
AstToStringVisitor::visit(HexAstRaiseStmt stmt_)
{
  HexAstRaiseStmt stmt = AstVisitor::visit(stmt_);

  this->append("raise ");
  stmt->expr()->accept(this);
  this->append(";");

  return stmt;
}

HexAstExprListStmt
AstToStringVisitor::visit(HexAstExprListStmt stmt_)
{
  HexAstExprListStmt stmt = AstVisitor::visit(stmt_);

  stmt->exprs()->accept(this);
  this->append(";");

  return stmt;
}

HexAstStmtGroup
AstToStringVisitor::visit(HexAstStmtGroup stmts_)
{
  HexAstStmtGroup stmts = AstVisitor::visit(stmts_);

  this->iterate<HexAstStmt>(
    stmts->list(),
    [this](HexAstStmt stmt) {
      stmt->accept(this);
    },
    this->_nullDelimiter
  );

  return stmts;
}

HexAstHexProgram
AstToStringVisitor::visit(HexAstHexProgram program_)
{
  HexAstHexProgram program = AstVisitor::visit(program_);

  program->stmts()->accept(this);

  return program;
}
