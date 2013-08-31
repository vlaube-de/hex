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

#include <functional>
#include "../ast.h"
#include "ast_tostring_visitor.h"
#include "../../base/strbuf.h"

AstToStringVisitor::_AstToStringVisitor()
  :_strbuf(strbuf_create())
{
  this->_commaF = []() {
    this->append(", ");
  }

  this->_dotF = []() {
    this->append(".");
  }

  this->_newlineF = []() {
    this->append("\n");
  }
}

void
AstToStringVisitor::append(c_str s)
{
  strbuf_append(this->_strbuf, (const char*)strdup(s));
}

HexAstIdentifier
AstToStringVisitor::visit(HexAstIdentifier identifier)
{
  HexAstIdentifier _identifier = AstVisitor::visit(identifier);

  this->append(_identifier->_identifier);    

  return _identifier;
}

HexAstLiteral
AstToStringVisitor::visit(HexAstLiteral literal)
{
  HexAstLiteral _literal = AstVisitor::visit(literal);

  this->append(_literal->_value);

  return _literal;
}

HexAstCall
AstToStringVisitor::visit(HexAstCall call)
{
  HexAstCall _call = AstVisitor::visit(call);

  this->visit(_call->_source);
  this->append("(");
  if(_call->_arglist) {
    this->visit(_call->_arglist);
  }
  this->append(")");

  return _call;
}

HexAstAttributeRef
AstToStringVisitor::visit(HexAstAttributeRef ref)
{
  HexAstAttributeRef ref = AstVisitor::visit(ref);

  this->visit(_ref->_source);
  this->append(".");
  this->append(_ref->_attribute);

  return _ref;
}

HexAstSliceItem
AstToStringVisitor::visit(HexAstSliceItem item)
{
  HexAstSliceItem _item = AstVisitor::visit(item);

  // TODO: append string here...

  return _item;
}

HexAstSlicing
AstToStringVisitor::visit(HexAstSlicing slicing)
{
  HexAstSlicing _slicing = AstVisitor::visit(slicing);

  this->visit(_slicing->_source);
  this->append("[");
  this->visit(_slicing->_slice);
  this->append("]");

  return _slicing;
}

template<typename C, typename T>
void
AstToStringVisitor::iterate(AstListObj<C, T> obj, std::function<void()> f)
{
  HEX_ASSERT(obj);

  std::list<T>::iterator itr;
  for(itr=obj->_list->begin(), itr!=obj->_list->end(); itr++) {
    T t = (T)itr;
    this->visit(t);
    f();
  }
}

HexAstTargetList
AstToStringVisitor::visit(HexAstTargetList targets)
{
  HexAstTargetList _targets = AstVisitor::visit(targets);

  this->iterate<_HexAstTargetList, _HexAstIdentifier>(_targets, this->commaF);

  return _targets;
}

HexAstName
AstToStringVisitor::visit(HexAstName name)
{
  HewAstName _name = AstVisitor::visit(name);

  this->iterate<_HexAstName, _HexAstIdentifier>(_name, this->dotF);

  return _name;
}

HexAstNegateExpr
AstToStringVisitor::visit(HexAstNegateExpr expr)
{
  HexAstNegateExpr expr_ = AstVisitor::visit(expr);

  this->append("-");
  this->visit(expr_->_expr);

  return expr_;
}

HexAstNotExpr
AstToStringVisitor::visit(HexAstNotExpr expr)
{
  HexAstNotExpr expr_ = AstVisitor::visit(expr);

  this->append("not ");
  this->visit(expr_->_expr);

  return expr_;
}

HexAstBitwiseNotExpr
AstToStringVisitor::visit(HexAstBitwiseNotExpr expr)
{
  HexAstBitwiseNotExpr expr_ = AstVisitor::visit(expr);

  this->append("^");
  this->visit(expr_->_expr);

  return expr_;
}

HexAstIncrementExpr
AstToStringVisitor::visit(HexAstIncrementExpr expr)
{
  HexAstIncrementExpr expr_ = AstVisitor::visit(expr);

  this->visit(expr_->_expr);
  this->append("++");

  return expr_;
}

HexAstDecrementExpr
AstToStringVisitor::visit(HexAstDecrementExpr expr)
{
  HexAstDecrementExpr expr_ = AstVisitor::visit(expr);

  this->visit(expr_->_expr);
  this->append("--");

  return expr_;
}

HexAstExistentialExpr
AstToStringVisitor::visit(HexAstExistentialExpr expr)
{
  HexAstExistentialExpr expr_ = AstVisitor::visit(expr);

  this->visit(expr_);
  this->append("?");

  return expr_;
}

HexAstBinaryExpr
_AstToStirngVisitor::visit(HexAstBinaryExpr expr)
{
  HexAstBinaryExpr expr_ = AstVisitor::visit(expr);

  this->visit(expr_->left());
  this->append(expr_->op());
  this->visit(expr_->right());

  return expr_;
}

HexAstConditionalExpr
AstToStringVisitor::visit(HexAstConditionalExpr expr)
{
  HexAstConditionalExpr expr_ = AstVisitor::visit(expr);

  this->append("if ");
  this->visit(expr_->_predicate);
  this->append(" then ");
  this->visit(expr_->_consequent);
  this->append(" else ");
  this->visit(expr_->_substitute);

  return expr_;
}

HexAstYieldExpr
AstToStringVisitor::visit(HexAstYieldExpr expr)
{
  HexAstYieldExpr expr_ = AstVisitor::visit(expr);

  this->append("yield");
  if(expr_->_exprs) {
    this->append(" (");
    this->visit(expr_->_exprs);
    this->append(")");
  }
}

HexAstStringExpr
AstToStringVisitor::visit(HexAstStringExpr expr)
{
  HexAstStringExpr expr_ = AstVisitor::visit(expr);

  this->visit(expr_->_string);
  this->append("%");
  this->append("(");
  this->visit(expr_->_exprs);
  this->append(")");

  return expr_;
}

HexAstParenForm
AstToStringVisitor::visit(HexAstParenForm form)
{
  HexAstParenForm form_ = AstVisitor::visit(form);

  this->append("(");
  this->visit(form_->_exprs);
  this->append(")");

  return form_; 
}

HexAstExpList
AstToStringVisitor::visit(HexAstExprList exprlist)
{
  HexAstExprList exprlist_ = AstVisitor::visit(exprlist);

  this->iterate<_HexAstExprList, HexAstExpr>(exprlist_, this->_commaF);

  return exprlist_;
}

HexAstSimpleParamList
AstToStringVisitor::visit(HexAstSimpleParamList params)
{
  HexAstSimpleParamList params_ = AstVisitor::visit(params);

  this->iterate<_HexAstSimpleParamList, HexAstIdentifier>(params, this->_commaF);

  return params_;
}

HexAstKeywordVal
AstToStringVisitor::visit(HexAstKeywordVal keyval)
{
  HexAstKeywordVal keyval_ = AstVisitor::visit(keyval);

  this->visit(keyval_->_key);
  this->visit(keyval_->_val);

  return keyval_;
}

HexAstKeywordValList
AstToStringVisitor::visit(HexAstKeywordValList list)
{
  HexAstKeywordValList list_ = AstVisitor::visit(list);

  this->iterate<_HexAstKeywordValList, HexAstKeywordVal>(list_, this->_commaF);

  return list_;
}

HexAstParameterList
AstToStringVisitor::visit(HexAstParameterList params)
{
  HexAstParameterList params_ = AstVisitor::visit(params);

  // TODO: string here...

  return params_;
}

HexAstValList
AstToStringVisitor::visit(HexAstValList vallist)
{
  HexAstValList vallist_ = AstVisitor::visit(vallist);

  this->iterate<_HexAstValList, HexAstValAtom>(vallist_, this->_commaF);

  return vallist_;
}

HexAstValAtom
AstToStringVisitor::visit(HexAstValAtom atom)
{
  HexAstAtom atom_ = AstVisitor::visit(atom);

  // TODO: string here...

  return atom_;
}

HexAstArgList
AstToStringVisitor::visit(HexAstArgList arglist)
{
  HexAstArgList arglist_ = AstVisitor::visit(arglist);

  // TODO: string here...

  return arglist_;
}

HexAstComprehension
AstToStringVisitor::visit(HexAstComprehension comprehension)
{
  HexAstComprehension comprehension_ = AstVisitor::visit(comprehension);

  if(comprehension_->_dst) {
    this->visit(comprehension_->_dst);
    this->append(" ");
  }
  this->append("for ");

  this->visit(comprehension_->_candidates);
  this->append(" in ");
  this->visit(comprehension_->_src);

  if(comprehension_->_predicate) {
    this->append(" where ");
    this->visit(comprehension_->_predicate);
  }

  return comprehension_;
}

HexAstListForm
AstToStringVisitor::visit(HexAstListForm form)
{
  HexAstListForm form_ = AstVisitor::visit(form);

  this->append("[");

  if(form_->_type == AST_LIST_FORM_EXPR_LIST) {
    HexAstExprList exprlist = (HexAstExprList)(form_->_core);
    this->visit(exprlist);
  } else if(form_->_type == AST_LIST_FORM_COMPREHENSION) {
    HexAstComprehension comprehension = (HexAstComprehension)(form_->_core);
    this->visit(comprehension);
  }

  this->append("]");

  return form_;
}

HexAstFieldDef
AstToStringVisitor::visit(HexAstFieldDef def)
{
  HexAstFieldDef def_ = AstVisitor::visit(def);

  if(def_->_decorators) {
    this->visit(decorators);
  }

  this->visit(def_->_name);
  this->append(": ");
  this->visit(def_->_val);

  return def_;
}

HexAstMapField
AstToStringVisitor::visit(HexAstMapField field)
{
  HexAstMapField field_ = AstVisitor::visit(field);

  this->visit(field_->_key);
  this->append("=> ");
  this->visit(field_->_val);

  return field_;
}

HexAstMapFieldList
AstToStringVisitor::visit(HexAstMapFieldList list)
{
  HexAstMapFieldList list_ = AstVisitor::visit(list);

  this->iterate<_HexAstMapFieldList, HexAstMapField>(list_, this->_commaF);

  return list_;
}

HexAstMapForm
AstToStringVisitor::visit(HexAstMapForm map)
{
  HexAstMapForm map_ = AstVisitor::visit(map);

  this->append("{");

  if(map_->_list) {
    this->visit(map_->_list);
  }

  this->append("}");
  return map_;
}

HexAstFieldDefList
AstToStringVisitor::visit(HexAstFieldDefList list)
{
  HexAstFieldDefList list_ = AstVisitor::visit(list);

  this->iterate<_HexAstFieldDefList, HexAstFieldDef>(list_, this._commaF);

  return list_;
}

HexAstDictForm
AstToStringVisitor::visit(HexAstDictForm dict)
{
  HexAstDictForm dict_ = AstVisitor::visit(dict);

  this->append("{");

  if(dict_->_type == AST_DICT_FORM_EXPLICIT) {
    HexAstExprList exprlist = (HexAstExprlist)(dict_->_core);
    this->visit(exprlist);
  } else if (dict_->_type == AST_DICT_FORM_COMPREHENSION) {
    HexAstComprehension comprehension = (HxAstComprehension)(dict_->_core);
    this->visit(comprehension);
  }

  this->append("}");
  return map_;
}

HexAstDecorator
AstToStringVisitor::visit(HexAstDecorator decorator)
{
  HexAstDecorator decorator_ = AstVisitor::visit(decorator);

  this->append("@");
  this->append(decorator_->_name);
  if(decorator_->_args) {
    this->append("(");
    this->visit(decorator_->_args);
    this->append("(");
  }

  return decorator_;
}

HexAstDecoratorList
AstToStringVisitor::visit(HexAstDecoratorList decorators)
{
  HexAstDecoratorList decorators_ = AstVisitor::visit(decorators);

  this->iterate<_HexAstDecoratorList, HexAstDecorator>(decorators_, this->_newlineF);

  return decorators_;
}

HexAstOperator
AstToStringVisitor::visit(HexAstOperator op)
{
  HexAstOperator op_ = AstVisitor::visit(op);

  // TODO: string here...
  switch(op_->_op) {
    case AST_OPERATOR_PLUS:
      this->append("+");
      break;
    case AST_OPERATOR_MINUS:
      this->append("-");
      break;
    default:
      break;
  }

  return op_;
}

HexAstOperatorDef
AstToStringVisitor::visit(HexAstOperatorDef def)
{
  HexAstOperatorDef def_ = AstVisitor::visit(def);

  this->visit(def_->_op);
  this->append(": ");
  this->visit(def_->_lambda);

  return def_;
}

/*
HexAstAttributeDef
AstToStringVisitor::visit(HexAstAttributeDef def)
{
}
*/

HexAstAttributeDefList
AstToStringVisitor::visit(HexAstAttributeDefList defs)
{
  HexAstAttributeDefList defs_ = AstVisitor::visit(defs);

  this->iterate<_HexAstAttributeDefList, HexAstAttributeDef>(defs_, this->_newlineF);

  return defs_;
}

HexAstAssignmentStmt
AstToStringVisitor::visit(HexAstAssignmentStmt stmt)
{
  HexAstAssignmentStmt stmt_ = AstVisitor::visit(stmt);

  if(stmt_->_decorators) {
    this->visit(stmt_->_decorators);
  }
  this->visit(stmt_->_dst);
  this->append(" = ");
  if(stmt_->_defer) {
    this->append(" defer ");
  }

  if(stmt_->_type == AST_ASSIGNMENT_STMT_EXPR_LIST) {
    HexAstExprList exprlist = (HexAstExprList)(stmt_->src);
    this->visit(exprlist);
  } else if(stmt_->_type == AST_ASSIGNMENT_STMT_LAMBDA) {
    HexAstLambda lambda = (HexAstLambda)(stmt_->_src);
    this->visit(lambda);
  } else if(stmt_->_type == AST_ASSIGNMENT_STMT_TASK) {
    HexAstTaskDef task = (HexAstTaskDef)(stmt_->_src);
    this->visit(task);
  }

  return stmt_;
}

HexAstUsingSrc
AstToStringVisitor::visit(HexAstUsingSrc src)
{
  HexAstUsingSrc src_ = AstVisitor::visit(src);

  if(src_->_type == AST_USING_SRC_NAME) {
    HexAstName name = (HexAstName)(src_->_name);
    this->visit(name);
  } else if(src_->_type == AST_USING_SRC_DOT) {
    this->append(".");
  }

  return src_;
}

HexAstUsingStmtDirect
AstToStringVisitor::visit(HexAstUsingStmtDirect stmt)
{
  HexAstUsingStmtDirect stmt_ = AstVisitor::visit(stmt);

  this->append("using ");
  this->visit(stmt_->_target);
  this->append(" ");
  if(stmt_->_alias) {
    this->append(" as ");
    this->visit(stmt_->_alias);
  }

  this->append(";");

  return stmt_;
}

HexAstUsingStmtRelative
AstToStringVisitor::visit(HexAstUsingStmtRelative stmt)
{
  HexAstUsingStmtRelative stmt_ = AstVisitor::visit(stmt);

  this->append("using ");

  if(stmt_->_targets) {
    this->visit(stmt_->_targets);
  } else {
    this->append("*");
  }

  this->append(" in ");
  this->visit(stmt_->_src);

  if(stmt_->_alias) {
    this->append(" as ");
    this->visit(stmt_->_alias);
  }

  this->append(";");

  return stmt_;
}

HexAstElifStmt
AstToStringVisitor::visit(HexAstElifStmt stmt)
{
  HexAstElifStmt stmt_ = AstVisitor::visit(stmt);

  this->append("elif ");
  this->visit(stmt_->_predicate);
  this->append("{\n");
  this->visit(stmt_->_stmts);
  this->append("\n}");

  return stmt_;
}

HexAstElifGroup
AstToStringVisitor::visit(HexAstElifGroup group)
{
  HexAstElifGroup group_ = AstVisitor::visit(group);

  this->iterate<_HexAstElifStmtGroup, HexAstElifStmt>(group_, this->_newlineF);

  return group_;
}

HexAstElseStmt
AstToStringVisitor::visit(HexAstElseStmt stmt)
{
  HexAstElseStmt stmt_ = AstVisitor::visit(stmt);

  this->append("else {\n");
  this->visit(stmt_->_stmts);
  this->append("\n}");

  return stmt_;
}

HexAstIfStmt
AstToStringVisitor::visit(HexAstIfStmt stmt)
{
  HexAstIfStmt stmt_ = AstVisitor::visit(stmt);

  this->append("if {\n");
  this->visit(stmt_->_stmts);
  this->append("\n}");

  return stmt_;
}

HexAstForStmt
AstToStringVisitor::visit(HexAstForStmt stmt)
{
  HexAstForStmt stmt_ = AstVisitor::visit(stmt);

  this->append("for ");
  this->visit(stmt_->_targets);
  this->append(" in ");
  this->visit(stmt_->_exprs);

  if(stmt_->_predicate) {
    this->append(" where ");
    this->visit(stmt_->_predicate);
  }

  this->append(" {\n");
  this->visit(stmt_->_stmts);
  this->append("\n}");

  return stmt_;
}

HexAstWithStmt
AstToStringVisitor::visit(HexAstWithStmt stmt)
{
  HexAstWithStmt stmt_ = AstVisitor::visit(stmt);

  this->append("with ");
  this->visit(stmt_->_exprs);

  if(stmt_->alias) {
    this->append(" as ");
    this->visit(stmt_->_alias);
  }

  this->append(" {\n");
  this->visit(stmt_->_stmts);
  this->append("\n}");

  return stmt_;
}

HexAstLockStmt
AstToStringVisitor::visit(HexAstLockStmt stmt)
{
  HexAstLockStmt stmt_ = AstVisitor::visit(stmt);

  this->append("lock ");
  this->visit(stmt_->_exprs);
  this->append(" {\n");
  this->visit(stmt_->_stmts);
  this->append("\n}");

  return stmt_;
}


HexAstWhileStmt
AstToStringVisitor::visit(HexAstWhileStmt stmt)
{
  HexAstWhileStmt stmt_ = AstVisitor::visit(stmt);

  this->append("while ");
  this->visit(stmt_->_expr);

  this->append(" {\n");
  this->visit(stmt_->_stmts);
  this->append("\n}");

  return stmt_;
}

HexAstCatchStmt
AstToStringVisitor::visit(HexAstCatchStmt stmt)
{
  HexAstCatchStmt stmt_ = AstVisitor::visit(stmt);

  this->append("catch ");
  if(stmt_->_targets) {
    this->visit(stmt_->_targets);
    if(stmt_->_alias) {
      this->append(" as ");
      this->visit(stmt_->_alias);
      this->append(" ");
    }
  }

  this->append(" {\n");
  this->visit(stmt_->_stmts);
  this->append("\n}");

  return stmt_;
}

HexAstCatchStmtGroup
AstToStringVisitor::visit(HexAstCatchStmtGroup group)
{
  HexAstCatchStmtGroup group_ = AstVisitor::visit(group);

  this->iterate<_HexAstCatchStmtGroup, HexAstCatchStmt>(group_, this->_newlineF);

  return group_;
}

HexAstTryStmt
AstToStringVisitor::visit(HexAstTryStmt stmt)
{
  HexAstTryStmt stmt_ = AstVisitor::visit(stmt);

  this->append("try ");
  this->append(" {\n");
  this->visit(stmt_->_stmts);
  this->append("\n}");

  this->visit(stmt_->_catch_stmt_group);

  return stmt_;
}

HexAstClassDef
AstToStringVisitor::visit(HexAstClassDef def)
{
  HexAstClassDef def_ = AstVisitor::visit(def);

  if(def_->_decorators) {
    this->visit(def_->_decorators);
  }
  this->append("class ");
  this->visit(def_->_name);

  this->append(" ");

  if(def_->_parent) {
    this->append("extends ");
    this->visit(def_->_parent);
  }

  this->append(" {\n");
  this->visit(def_->_attributes);
  this->append("}\n");

  return def_;
}

HexAstLambdaSimple
AstToStringVisitor::visit(HexAstLambdaSimple lambda)
{
  HexAstLambdaSimple lambda_ = AstVisitor::visit(lambda);

  this->append("(");
  if(lambda_->_params) {
    this->visit(lambda_->_params);
  }
  this->append(") -> ");
  this->visit(lambda_->_expr);

  return lambda_;
}

HexAstLambdaComplex
AstToStringVisitor::visit(HexAstLambdaComplex lambda)
{
  HexAstLambdaComplex lambda_ = AstVisitor::visitor(lambda);

  this->append("(");
  if(lambda_->_params) {
    this->visit(lambda_->_params);
  }
  this->append(") => {\n");

  this->visit(lambda_->_stmts);
  this->append("}\n");

  return lambda_;
}

HexAstInputStmt
AstToStringVisitor::visit(HexAstInputStmt stmt)
{
  HexAstInputStmt stmt_ = AstVisitor::visit(stmt);

  this->iterate<_HexAstInputStmt, HexAstPrimary>(stmt_, this->_inputF);

  return stmt_;
}

HexAstOutputStmt
AstToStringVisitor::visit(HexAstOutputStmt stmt)
{
  HexAstOutputStmt stmt_ = AstVisitor::visit(stmt);

  this->iterate<_HexAstOutputStmt, HexAstPrimary>(stmt_, this->_outputF);

  return stmt_;
}

HexAstTaskState
AstToStringVisitor::visit(HexAstTaskState state_)
{
  HexAstTaskState state = AstVisitor::visit(state_);

  this->append(state->toString());

  return state;
}

HexAstConditionalPreposition
AstToStringVisitor::visit(HexAstConditionalPrepositon preposition_)
{
  HexAstConditionalPreposition preposition = AstVisitor::visit(preposition_);

  this->append(preposition->toString());
  
  return preposition;
}

HexAstConditionalClause
AstToStringVisitor::visit(HexAstConditionalClause clause_)
{
  HexAstConditionalClause clause = AstVisitor::visit(clause_);

  this->visit(clause->_preposition);
  this->append(" ");
  this->visit(clause->_exprs);
  this->append(" ");
  this->visit(clause->_state);

  return clause;
}

HexAstStartClauseSingle
AstToStringVisitor::visit(HexAstStartClauseSingle clause_)
{
  HexAstStartClauseSingle clause = AstVisitor::visit(clause_);

  this->append("start ");
  this->visit(clause->_target);
  this->append(" ");

  if(clause->_alias) {
    this->append(" as ");
    this->visit(clause->_alias);
  }

  this->visit(clause->_condition);

  return clause;
}

HexAstStartClauseMultiple
AstToStringVisitor::visit(HexAstClauseMultiple clause_)
{
  HexAstStartClauseMultiple clause = AstVisitor::visit(clause_);

  this->append("start ");
  this->visit(clause->_targets);

  if(clause->_alias) {
    this->append(" as ");
    this->visit(clause->_alias);
  }

  this->visit(clause->_condition);
  return clause;
}

HexAstPauseClause
AstToStringVisitor::visit(HexAstPauseClause clause_)
{
  HexAstPauseClause clause = AstVisitor::visit(clause_);

  this->append("pause ");
  this->visit(clause->_exprs);
  this->append(" ");
  this->visit(clause->_condition);

  return clause;
}

HexAstResumeClause
AstToStringVisitor::visit(HexAstResumeClause clause_)
{
  HexAstResumeClause clause = AstVisitor::visit(clause_);

  this->append("resume ");
  this->visit(clause->_exprs);
  this->append(" ");
  this->visit(clause->_condition);

  return clause;
}

HexAstCancelClause
AstToStringVisitor::visit(HexAstCancelClause clause_)
{
  HexAstCancelClause clause = AstVisitor::visit(clause_);

  this->append("resume ");
  this->visit(clause->_exprs);
  this->append(" ");
  this->visit(clause->_condition);

  return clause;
}

HexAstConditionalDelayClause
AstToStringVisitor::visit(HexAstDelayClause clause_)
{
  HexAstConditionalDelayClause clause = AstVisitor::visit(clause_);

  this->append("delay ");
  this->visit(clause->_exprs);
  this->append(" ");
  this->visit(clause->_condition);

  return clause;
}

HexAstFixedDelayClause
AstToStringVisitor::visit(HexAstFixedDelayClause clause_)
{
  HexAstFixedDelayClause clause = AstVisitor::visit(clause_);

  this->append("delay ");
  if(clause->_exprs) {
    this->append(" ");
    this->visit(clause->_exprs);
    this->append(" ");
  }
  this->append("by ");
  this->visit(clause->_delay);

  return clause;
}

HexAstStopClause
AstToStringVisitor::visit(HexAstStopClause clause_)
{
  HexAstStopClause clause = AstVisitor::visit(clause_);

  this->append("stop ");
  this->visit(clause->_exprs);
  this->append(" ");
  this->visit(clause->_condition);

  return clause;
}

HexAstTaskDef
AstToStringVisitor::visit(HexAstTaskDef def_)
{
  HexAstTaskDef def = AstVisitor::visit(def_);

  this->iterate<_HexAstTaskDef, HexAstTaskClause>(def, this->_commaF);

  return def;
}

HexAstAwaitStmt
AstToStringVisitor::visit(HexAstAwaitStmt stmt_)
{
  HexAstAwaitStmt stmt = AstVisitor::visit(stmt_);

  this->append("await {\n");
  this->visit(stmt->_stmts);
  this->append("}\n");

  return stmt;
}

HexAstReturnStmt
AstToStringVisitor::visit(HexAstReturnStmt stmt_)
{
  HexAstReturnStmt stmt = AstVisitor::visit(stmt_);

  this->append("return");
  if(clause->_return_vals) {
    this->append(" ");
    this->visit(clause->_return_vals);
  }
  if(clause->_predicate) {
    this->append(" if ");
    this->visit(clause->_predicate);
  }
  this->append(";");

  return stmt;
}

HexAstBreakStmt
AstToStringVisitor::visit(HexAstBreakStmt stmt_)
{
  HexAstBreakStmt stmt = AstVisitor::visit(stmt_);

  this->append("break");
  if(clause->_predicate) {
    this->append(" if ");
    this->visit(clause->_predicate);
  }
  this->append(";");

  return stmt;
}

HexAstContinueStmt
AstToStringVisitor::visit(HexAstContinueStmt stmt_)
{
  HexAstContinueStmt stmt = AstVisitor::visit(stmt_);

  this->append("continue");
  if(clause->_predicate) {
    this->append(" if ");
    this->visit(clause->_predicate);
  }
  this->append(";");
}

HexAstRaiseStmt
AstToStringVisitor::visit(HexAstRaiseStmt stmt_)
{
  HexAstRaiseStmt stmt = AstVisitor::visit(stmt_);

  this->append("raise ");
  this->visit(stmt->_expr);
  this->append(";");

  return stmt;
}

HexAstExprListStmt
AstToStringVisitor::visit(HexAstExprListStmt stmt_)
{
  HexAstExprListStmt stmt = AstVisitor::visit(stmt_);

  this->visit(stmt->_exprlist);
  this->append(";");

  return stmt;
}

HexAstStmtGroup
AstToStringVisitor::visit(HexAstStmtGroup group_)
{
  HexAstStmtGroup group = AstVisitor::visit(group_);

  this->iterate<_HexAstStmtGroup, HexAstStmt>(group, this->_newlineF);

  return group;
}

HexAstHexProgram
AstToStringVisitor::visit(HexAstHexProgram program_)
{
  HexAstHexProgram program = AstVisitor::visit(program_);

  this->visit(program->_stmts);

  return program;
}

