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
 * Forward declaration of AST types.
 * 
 * This is needed to solve the circular dependency between
 * definitions in compiler/ast/ and compiler/ast/visitors/
 *
 * Please update this file every time there are type
 * changes occur under compiler/ast/
 */
typedef class _HexAstIdentifier * HexAstIdentifier;
typedef class _HexAstIntegerLiteral * HexAstIntegerLiteral;
typedef class _HexAstFloatLiteral * HexAstFloatLiteral;
typedef class _HexAstStringLiteral * HexAstStringLiteral;
typedef class _HexAstCall * HexAstCall;
typedef class _HexAstAttributeRef * HexAstAttributeRef;
typedef class _HexAstSliceItem * HexAstSliceItem;
typedef class _HexAstSlicing * HexAstSlicing;
typedef class _HexAstTargetList * HexAstTargetList;
typedef class _HexAstName * HexAstName;
typedef class _HexAstPositiveExpr * HexAstPositiveExpr;
typedef class _HexAstNegativeExpr * HexAstNegativeExpr;
typedef class _HexAstNotExpr * HexAstNotExpr;
typedef class _HexAstBitwiseNotExpr * HexAstBitwiseNotExpr;
typedef class _HexAstIncrementExpr * HexAstIncrementExpr;
typedef class _HexAstDecrementExpr * HexAstDecrementExpr;
typedef class _HexAstExistentialExpr * HexAstExistentialExpr;
typedef class _HexAstAddExpr * HexAstAddExpr;
typedef class _HexAstMinusExpr * HexAstMinusExpr;
typedef class _HexAstMultiplyExpr * HexAstMultiplyExpr;
typedef class _HexAstDivideExpr * HexAstDivideExpr;
typedef class _HexAstModulusExpr * HexAstModulusExpr;
typedef class _HexAstPowerExpr * HexAstPowerExpr;
typedef class _HexAstBitwiseAndExpr * HexAstBitwiseAndExpr;
typedef class _HexAstBitwiseOrExpr * HexAstBitwiseOrExpr;
typedef class _HexAstBitwiseXorExpr * HexAstBitwiseXorExpr;
typedef class _HexAstBitwiseShiftLeftExpr * HexAstBitwiseShiftLeftExpr;
typedef class _HexAstBitwiseShiftRightExpr * HexAstBitwiseShiftRightExpr;
typedef class _HexAstEqualsExpr * HexAstEqualsExpr;
typedef class _HexAstNotEqualExpr * HexAstNotEqualExpr;
typedef class _HexAstIsExpr * HexAstIsExpr;
typedef class _HexAstIsNotExpr * HexAstIsNotExpr;
typedef class _HexAstLessThanExpr * HexAstLessThanExpr;
typedef class _HexAstGreaterThanExpr * HexAstGreaterThanExpr;
typedef class _HexAstGreaterOrEqualsExpr * HexAstGreaterOrEqualsExpr;
typedef class _HexAstLessOrEqualsExpr * HexAstLessOrEqualsExpr;
typedef class _HexAstInExpr * HexAstInExpr;
typedef class _HexAstNotInExpr * HexAstNotInExpr;
typedef class _HexAstAndExpr * HexAstAndExpr;
typedef class _HexAstOrExpr * HexAstOrExpr;
typedef class _HexAstInclusiveRangeExpr * HexAstInclusiveRangeExpr;
typedef class _HexAstExclusiveRangeExpr * HexAstExclusiveRangeExpr;
typedef class _HexAstConditionalExpr * HexAstConditionalExpr;
typedef class _HexAstPseudoAssignPlusExpr * HexAstPseudoAssignPlusExpr;
typedef class _HexAstPseudoAssignMinusExpr * HexAstPseudoAssignMinusExpr;
typedef class _HexAstPseudoAssignMultiplyExpr * HexAstPseudoAssignMultiplyExpr;
typedef class _HexAstPseudoAssignDivideExpr * HexAstPseudoAssignDivideExpr;
typedef class _HexAstPseudoAssignModulusExpr * HexAstPseudoAssignModulusExpr;
typedef class _HexAstPseudoAssignBitwiseAndExpr * HexAstPseudoAssignBitwiseAndExpr;
typedef class _HexAstPseudoAssignBitwiseOrExpr * HexAstPseudoAssignBitwiseOrExpr;
typedef class _HexAstPseudoAssignBitwiseXorExpr * HexAstPseudoAssignBitwiseXorExpr;
typedef class _HexAstPseudoAssignBitwiseLeftShiftExpr * HexAstPseudoAssignBitwiseLeftShiftExpr;
typedef class _HexAstPseudoAssignBitwiseRightShiftExpr * HexAstPseudoAssignBitwiseRightShiftExpr;
typedef class _HexAstYieldExpr * HexAstYieldExpr;
typedef class _HexAstStringExpr * HexAstStringExpr;
typedef class _HexAstParenForm * HexAstParenForm;
typedef class _HexAstExprList * HexAstExprList;
typedef class _HexAstSimpleParamList * HexAstSimpleParamList;
typedef class _HexAstKeywordVal * HexAstKeywordVal;
typedef class _HexAstKeywordValList * HexAstKeywordValList;
typedef class _HexAstParameterList * HexAstParameterList;
typedef class _HexAstValList * HexAstValList;
typedef class _HexAstValAtom * HexAstValAtom;
typedef class _HexAstArgList * HexAstArgList;
typedef class _HexAstComprehension * HexAstComprehension;
typedef class _HexAstListForm * HexAstListForm;
typedef class _HexAstExplicitListForm * HexAstExplicitListForm;
typedef class _HexAstImplicitListForm * HexAstImplicitListForm;
typedef class _HexAstFieldDef * HexAstFieldDef;
typedef class _HexAstMapField * HexAstMapField;
typedef class _HexAstMapFieldList * HexAstMapFieldList;
typedef class _HexAstMapForm * HexAstMapForm;
typedef class _HexAstFieldDefList * HexAstFieldDefList;
typedef class _HexAstDictForm * HexAstDictForm;
typedef class _HexAstExplicitDictForm * HexAstExplicitDictForm;
typedef class _HexAstImplicitDictForm * HexAstImplicitDictForm;
typedef class _HexAstDecorator * HexAstDecorator;
typedef class _HexAstDecoratorList * HexAstDecoratorList;
typedef class _HexAstOperator * HexAstOperator;
typedef class _HexAstOperatorDef * HexAstOperatorDef;
typedef class _HexAstAttributeDefList * HexAstAttributeDefList;
typedef class _HexAstExprListAssignmentStmt * HexAstExprListAssignmentStmt;
typedef class _HexAstLambdaAssignmentStmt * HexAstLambdaAssignmentStmt;
typedef class _HexAstTaskDefAssignmentStmt * HexAstTaskDefAssignmentStmt;
typedef class _HexAstUsingSrc * HexAstUsingSrc;
typedef class _HexAstUsingStmtDirect * HexAstUsingStmtDirect;
typedef class _HexAstUsingStmtRelative * HexAstUsingStmtRelative;
typedef class _HexAstElifStmt * HexAstElifStmt;
typedef class _HexAstElifStmtGroup * HexAstElifStmtGroup;
typedef class _HexAstElseStmt * HexAstElseStmt;
typedef class _HexAstIfStmt * HexAstIfStmt;
typedef class _HexAstForStmt * HexAstForStmt;
typedef class _HexAstWithStmt * HexAstWithStmt;
typedef class _HexAstLockStmt * HexAstLockStmt;
typedef class _HexAstWhileStmt * HexAstWhileStmt;
typedef class _HexAstCatchStmt * HexAstCatchStmt;
typedef class _HexAstCatchStmtGroup * HexAstCatchStmtGroup;
typedef class _HexAstTryStmt * HexAstTryStmt;
typedef class _HexAstClassDef * HexAstClassDef;
typedef class _HexAstLambdaSimple * HexAstLambdaSimple;
typedef class _HexAstLambdaComplex * HexAstLambdaComplex;
typedef class _HexAstInputStmt * HexAstInputStmt;
typedef class _HexAstOutputStmt * HexAstOutputStmt;
typedef class _HexAstTaskState * HexAstTaskState;
typedef class _HexAstConditionalPreposition * HexAstConditionalPreposition;
typedef class _HexAstConditionalClause * HexAstConditionalClause;
typedef class _HexAstStartClauseSingle * HexAstStartClauseSingle;
typedef class _HexAstStartClauseMultiple * HexAstStartClauseMultiple;
typedef class _HexAstPauseClause * HexAstPauseClause;
typedef class _HexAstResumeClause * HexAstResumeClause;
typedef class _HexAstCancelClause * HexAstCancelClause;
typedef class _HexAstConditionalDelayClause * HexAstConditionalDelayClause;
typedef class _HexAstFixedDelayClause * HexAstFixedDelayClause;
typedef class _HexAstStopClause * HexAstStopClause;
typedef class _HexAstTaskDef * HexAstTaskDef;
typedef class _HexAstAwaitStmt * HexAstAwaitStmt;
typedef class _HexAstReturnStmt * HexAstReturnStmt;
typedef class _HexAstBreakStmt * HexAstBreakStmt;
typedef class _HexAstContinueStmt * HexAstContinueStmt;
typedef class _HexAstRaiseStmt * HexAstRaiseStmt;
typedef class _HexAstExprListStmt * HexAstExprListStmt;
typedef class _HexAstStmtGroup * HexAstStmtGroup;
typedef class _HexAstHexProgram * HexAstHexProgram;
