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
 * All binary instructions are in the form of source -> destination
 *
 * -----------------------------------------------------------------
 * | Instruction set                                               |
 * |---------------------------------------------------------------|
 * | Instruction           | Description                                                 |
 * |-------------------------------------------------------------------------------------|
 * | Objects and attributes.                                                              |
 * |---------------------------------------------------------------------------------------|
 * |  getattr src name     | Get the attribute from the source and make $temp point to it. |
 * |  hasattr src name     | Check if the source has the specified attribute, returns a boolean and place it into $temp. |
 * |  setattr dst name     | Set the specified attribute of the destination point to $acu.
 * |  delattr src name     | Delete the specified attribute from the source.
 * |  putvar name          | Put a variable with the specified name and place it onto the current stack frame. |
 * |  putivsvar name       | Put an visible variable with the specified name and place it onto the current stack frame. |
 * |  delvar name          | Delete the variable with the specified name from the current stack frame.
 * |  delivsvar name       | Delete the invisible variable with the specified name from the current stack frame.
 * |  copy src dst         | Copy the reference from the source to the destination.  |
 * |  allocobj dst         | Allocate a new object and place it on the heap, its address is copied to dst. |
 * |-----------------------------------------------------------------------------------------|
 * |  Functions and stack frames.                                                            |
 * |------------------------------------------------------------------------------------------|
 * |  allocsf              | Allocate a new stack frame and put it on top of the current one. |
 * |  popsf                | Pop the last stack frame on top of the stack, and make the stack pointer point to the last stack frame. |
 * |  jump dst             | Jump to the destination instruction address. |
 * |  pusharg src          | Push the specified argument onto the next stack frame.
 * |  poparg dst           | Pop the top parameter at the current stack frame and assign it to the destination. | 
 * |------------------------------------------------------------------------------------------------------------|
 * | Primitive types
 * |-----------------------------------------------------------------------------------------|
 * | uint num            | Create a primitive unsigned decimal integer with the specified number and assign it to $temp. |  
 * | int num            | Create a primitive signed decimal integer with the specified number and assign it to $temp. |
 * | float mantissa exponent | Create a primitive floating number with the specified mantissa and exponent and assign it to $temp. |
 * | str string              | Create a pritimive string and assign it to $temp. |
 * | bytes length            | Create a pritimive byte array with the specified length and assign it to $temp. |
 * |-------------------------------------------------------------------------------------------|
 * | Arithmetic instructions
 * |--------------------------------------------------------------------------------------
 * | add src1 src2            | Add two numbers together, and put the result to $temp. |
 * | sub src1 src2            | Substract src2 from src1, and put the result to $temp. |
 * | mul src1 src2            | Multiply two numbers, and put the result to $temp. |
 * | div src1 src2            | Divide two numbers, and put the result to $temp. |
 * | mod src1 src2            | Modulus two numbers, and put the result to $temp. |
 * | pow src1 src2            | Compute src1 to the power of src2, and put the result to $temp. |
 * |---------------------------------------------------------------------------------------------|
 * | Equality instructions
 * |----------------------------------------------------------------------------------------|
 * | eq src1 src2             | Computers the equality between two numbers, and put the result to $tem
 * | neq src1 src2
 * | lt src1 src2
 * | gt src1 src2
 * | le
 * | ge
 * |------------------------------------------------------------------------------------|
 * | Branch instructions
 * |------------------------------------------------------------------|
 * * bra addr
 * | beq val addr
 * | bne val addr
 * | blt val addr
 * | bgt val addr
 * | ble val addr
 * | bge val addr
 * |----------------------------------------------------------------------------------|
 *
 * |
 */

#include <boost/tuple/tuple.hpp>
#include "codegen_visitor.h"
#include "../ast/ast.h"
#include "../../base/c_str.h"

typedef boost::tuple<c_str, c_str, c_str, c_str> inst_t;

#define ACCUMULATOR "$acu"
#define TEMP "$temp"

HexCodeGenVisitor::HexCodeGenVisitor()
{
}

HexCodeGenVisitor::~HexCodeGenVisitor()
{
}

void
HexCodeGenVisitor::add_inst(c_str addr, c_str inst, c_str op1, c_str op2)
{
}

template<class T, class Function>
void
HexCodeGenVisitor::iterate(std::list<T>* list, Function f, int startAt)
{
  typename std::list<T>::iterator itr = list->begin();
  while(startAt > 0) {
    itr++;
    startAt--;
  }

  for(itr=list->begin(); itr != list->end(); itr++) {
    f((T)(*itr));
  }
}

template<class T, class Function>
void
HexCodeGenVisitor::iterate_with_index(std::list<T>* list, Function f)
{
  typename std::list<T>::iterator itr = list->begin();

  int i = 0;
  for(itr=list->begin(); itr != list->end(); itr++) {
    f((T)(*itr), i);
    i++;
  }
}

HexAstIdentifier
HexCodeGenVisitor::visit(HexAstIdentifier identifier_)
{
  HexAstIdentifier identifier = AstVisitor::visit(identifier_);

  this->add_inst(NULL, "load", identifier->value(), ACCUMULATOR);

  return identifier;
}

HexAstIntegerLiteral
HexCodeGenVisitor::visit(HexAstIntegerLiteral literal_)
{
  HexAstIntegerLiteral literal = AstVisitor::visit(literal_);

  this->add_inst(NULL, "obj", ACCUMULATOR, NULL);
  this->add_inst(NULL, "int", literal->value(), NULL);
  this->add_inst(NULL, "setval", TEMP, ACCUMULATOR);

  return literal;
}

HexAstFloatLiteral
HexCodeGenVisitor::visit(HexAstFloatLiteral literal_)
{
  HexAstFloatLiteral literal = AstVisitor::visit(literal_);

  this->add_inst(NULL, "obj", ACCUMULATOR, NULL);
  this->add_inst(NULL, "float", literal->value(), NULL);
  this->add_inst(NULL, "setval", TEMP, ACCUMULATOR);

  return literal;
}

HexAstStringLiteral
HexCodeGenVisitor::visit(HexAstStringLiteral literal_)
{
  HexAstStringLiteral literal = AstVisitor::visit(literal_);

  this->add_inst(NULL, "obj", ACCUMULATOR, NULL);
  this->add_inst(NULL, "string", literal->value(), NULL);
  this->add_inst(NULL, "setval", TEMP, ACCUMULATOR);

  return literal;
}

HexAstCall
HexCodeGenVisitor::visit(HexAstCall call_)
{
  HexAstCall call = AstVisitor::visit(call_);

  // Load the caller into $acu.
  call->source()->accept(this);

  // Allocate a special variable that's not invisible
  // to the code, and copy the address of the caller into it.
  this->add_inst(NULL, "invvar", "x", NULL);
  this->add_inst(NULL, "laddr", ACCUMULATOR, NULL);
  this->add_inst(NULL, "copy", TEMP, "x");

  // Allocate a new stack frame for the new call.
  this->add_inst(NULL, "allocsf", NULL, NULL);

  // Put the arguments on the new stack frame.
  call->arglist()->accept(this);

  // Finally, jump to the code address.
  this->add_inst(NULL, "jump", "x", NULL);

  return call;
}

HexAstAttributeRef
HexCodeGenVisitor::visit(HexAstAttributeRef ref_)
{
  HexAstAttributeRef ref = AstVisitor::visit(ref_);

  ref->source()->accept(this);
  this->add_inst(NULL, "getattr", ACCUMULATOR, ref->attribute()->value()); // Load the attribute of the object in the accumulator into $temp.
  this->add_inst(NULL, "copy", TEMP, ACCUMULATOR); // Copy the value in $temp into $acu.

  return ref;
}

HexAstSlicing
HexCodeGenVisitor::visit(HexAstSlicing slicing_)
{
  HexAstSlicing slicing = AstVisitor::visit(slicing_);

  // Load the source into $acu.
  slicing->source()->accept(this);

  // Copy the source from $acu to $temp.
  this->add_inst(NULL, "copy", ACCUMULATOR, TEMP);

  // Load the slice item into $acu.
  slicing->slice()->accept(this);

  // Put the slice item as an argument.
  this->add_inst(NULL, "putarg", ACCUMULATOR, NULL);

  // Load the souce back into $acu.
  this->add_inst(NULL, "copy", TEMP, ACCUMULATOR);

  // Load the __index__ function from $acu(holds the source) into $temp.
  this->add_inst(NULL, "getattr", ACCUMULATOR, "__index__");

  // Call the __index__ function.
  this->add_inst(NULL, "call", TEMP, NULL);

  return slicing;
}

HexAstTargetList
HexCodeGenVisitor::visit(HexAstTargetList targets_)
{
  HexAstTargetList targets = AstVisitor::visit(targets_);

  return targets;
}

HexAstName
HexCodeGenVisitor::visit(HexAstName name_)
{
  HexAstName name = AstVisitor::visit(name_);

  // Load the first target into $acu.
  HexAstIdentifier first = name->list()->front();
  first->accept(this);

  // Starting at the 2nd element, iterate through.
  this->iterate<HexAstIdentifier>(
    name->list(),
    [this](HexAstIdentifier identifier) {
      this->add_inst(NULL, "getattr", ACCUMULATOR, identifier->value()); // Load the attribute of the object in $acu into $temp.
      this->add_inst(NULL, "copy", TEMP, ACCUMULATOR); // Copy the value in $temp into $acu.
    },
    1
  );

  return name;
}

void
HexCodeGenVisitor::cgen_unary_expr(HexAstUnaryExpr expr, c_str method)
{
  // Load the target expr into $acu.
  expr->expr()->accept(this);

  // Load the method into temp.
  this->add_inst(NULL, "getattr", ACCUMULATOR, method);

  // Put the object itself onto the next stack.
  this->add_inst(NULL, "putarg", ACCUMULATOR, NULL);

  // Call the method.
  this->add_inst(NULL, "call", TEMP, NULL);

}

HexAstPositiveExpr
HexCodeGenVisitor::visit(HexAstPositiveExpr expr_)
{
  HexAstPositiveExpr expr = AstVisitor::visit(expr_);

  this->cgen_unary_expr(expr, "__pos__");

  return expr;
}

HexAstNegativeExpr
HexCodeGenVisitor::visit(HexAstNegativeExpr expr_)
{
  HexAstNegativeExpr expr = AstVisitor::visit(expr_);

  this->cgen_unary_expr(expr, "__neg__");

  return expr;
}

HexAstNotExpr
HexCodeGenVisitor::visit(HexAstNotExpr expr_)
{
  HexAstNotExpr expr = AstVisitor::visit(expr_);

  this->cgen_unary_expr(expr, "__not__");

  return expr;
}

HexAstBitwiseNotExpr
HexCodeGenVisitor::visit(HexAstBitwiseNotExpr expr_)
{
  HexAstBitwiseNotExpr expr = AstVisitor::visit(expr_);

  this->cgen_unary_expr(expr, "__bnot__");

  return expr;
}

HexAstIncrementExpr
HexCodeGenVisitor::visit(HexAstIncrementExpr expr_)
{
  HexAstIncrementExpr expr = AstVisitor::visit(expr_);

  this->cgen_unary_expr(expr, "__inc__");

  return expr;
}

HexAstDecrementExpr
HexCodeGenVisitor::visit(HexAstDecrementExpr expr_)
{
  HexAstDecrementExpr expr = AstVisitor::visit(expr_);

  this->cgen_unary_expr(expr, "__dec__");

  return expr;
}

HexAstExistentialExpr
HexCodeGenVisitor::visit(HexAstExistentialExpr expr_)
{
  HexAstExistentialExpr expr = AstVisitor::visit(expr_);
  return expr;
}

void
HexCodeGenVisitor::cgen_binary_expr(HexAstBinaryExpr expr, c_str method)
{
  // Load the right expr into $acu.
  expr->right()->accept(this);

  // Put the object itself onto the next stack.
  this->add_inst(NULL, "putarg", ACCUMULATOR, NULL);

  // Load the left expr into $acu.
  expr->left()->accept(this);

  // Load the __add__ function into $temp.
  this->add_inst(NULL, "getattr", ACCUMULATOR, method);

  // Put the object onto the next stack.
  this->add_inst(NULL, "putarg", ACCUMULATOR, NULL);

  // Call the __add__ function.
  this->add_inst(NULL, "call", TEMP, NULL);

}

HexAstAddExpr
HexCodeGenVisitor::visit(HexAstAddExpr expr_)
{
  HexAstAddExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__add__");

  return expr;
}

HexAstMinusExpr
HexCodeGenVisitor::visit(HexAstMinusExpr expr_)
{
  HexAstMinusExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__minus__");

  return expr;
}

HexAstMultiplyExpr
HexCodeGenVisitor::visit(HexAstMultiplyExpr expr_)
{
  HexAstMultiplyExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__mul__");

  return expr;
}

HexAstDivideExpr
HexCodeGenVisitor::visit(HexAstDivideExpr expr_)
{
  HexAstDivideExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__div__");

  return expr;
}

HexAstModulusExpr
HexCodeGenVisitor::visit(HexAstModulusExpr expr_)
{
  HexAstModulusExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__mod__");

  return expr;
}

HexAstPowerExpr
HexCodeGenVisitor::visit(HexAstPowerExpr expr_)
{
  HexAstPowerExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__pow__");

  return expr; 
}

HexAstBitwiseAndExpr
HexCodeGenVisitor::visit(HexAstBitwiseAndExpr expr_)
{
  HexAstBitwiseAndExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__band__");

  return expr;
}

HexAstBitwiseOrExpr
HexCodeGenVisitor::visit(HexAstBitwiseOrExpr expr_)
{
  HexAstBitwiseOrExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__bor__");

  return expr;
}

HexAstBitwiseXorExpr
HexCodeGenVisitor::visit(HexAstBitwiseXorExpr expr_)
{
  HexAstBitwiseXorExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__bxor__");

  return expr;
}

HexAstBitwiseShiftLeftExpr
HexCodeGenVisitor::visit(HexAstBitwiseShiftLeftExpr expr_)
{
  HexAstBitwiseShiftLeftExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__blsh__");

  return expr;
}

HexAstBitwiseShiftRightExpr
HexCodeGenVisitor::visit(HexAstBitwiseShiftRightExpr expr_)
{
  HexAstBitwiseShiftRightExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__brsh__");

  return expr;
}

HexAstEqualsExpr
HexCodeGenVisitor::visit(HexAstEqualsExpr expr_)
{
  HexAstEqualsExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__eq__");

  return expr;
}

HexAstNotEqualExpr
HexCodeGenVisitor::visit(HexAstNotEqualExpr expr_)
{
  HexAstNotEqualExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__neq__");

  return expr;
}

HexAstIsExpr
HexCodeGenVisitor::visit(HexAstIsExpr expr_)
{
  HexAstIsExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__is__");

  return expr;
}

HexAstIsNotExpr
HexCodeGenVisitor::visit(HexAstIsNotExpr expr_)
{
  HexAstIsNotExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__isnt__");

  return expr;
}

HexAstLessThanExpr
HexCodeGenVisitor::visit(HexAstLessThanExpr expr_)
{
  HexAstLessThanExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__lt__");

  return expr;
}

HexAstGreaterThanExpr
HexCodeGenVisitor::visit(HexAstGreaterThanExpr expr_)
{
  HexAstGreaterThanExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__gt__");

  return expr;
}

HexAstGreaterOrEqualsExpr
HexCodeGenVisitor::visit(HexAstGreaterOrEqualsExpr expr_)
{
  HexAstGreaterOrEqualsExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__ge__");

  return expr;
}

HexAstLessOrEqualsExpr
HexCodeGenVisitor::visit(HexAstLessOrEqualsExpr expr_)
{
  HexAstLessOrEqualsExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__le__");

  return expr;
}

HexAstInExpr
HexCodeGenVisitor::visit(HexAstInExpr expr_)
{
  HexAstInExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__in__");

  return expr;
}

HexAstNotInExpr
HexCodeGenVisitor::visit(HexAstNotInExpr expr_)
{
  HexAstNotInExpr expr = AstVisitor::visit(expr_);

  this->cgen_binary_expr(expr, "__nin__");

  return expr;
}

HexAstAndExpr
HexCodeGenVisitor::visit(HexAstAndExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstOrExpr
HexCodeGenVisitor::visit(HexAstOrExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstInclusiveRangeExpr
HexCodeGenVisitor::visit(HexAstInclusiveRangeExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstExclusiveRangeExpr
HexCodeGenVisitor::visit(HexAstExclusiveRangeExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstConditionalExpr
HexCodeGenVisitor::visit(HexAstConditionalExpr expr_)
{
  HexAstConditionalExpr expr = AstVisitor::visit(expr_);

  // Evaluate the predicate expression
  expr->predicate()->accept(this);

  // If predicate evaluates to false, then branch.
  this->add_inst(NULL, "beq", 0, "label_x");

  // Under the true condition, evaluate the consequent
  // expression and place its value onto $acu.
  expr->consequent()->accept(this);

  // Under the false condition, evaluate the alternate
  // expression and place its value onto $acu.
  this->add_inst("label_x", NULL, NULL, NULL);
  expr->alternate()->accept(this);

  return expr;
}

void
HexCodeGenVisitor::cgen_pseudo_binary_expr(HexAstBinaryExpr expr, c_str method)
{
  this->cgen_binary_expr(expr, method);
  //this->add_inst(NULL, "copy",  
}

HexAstPseudoAssignPlusExpr
HexCodeGenVisitor::visit(HexAstPseudoAssignPlusExpr expr_)
{
  HexAstPseudoAssignPlusExpr expr = AstVisitor::visit(expr_);

  this->cgen_pseudo_binary_expr(expr, "__add__");

  return expr;
}

HexAstPseudoAssignMinusExpr
HexCodeGenVisitor::visit(HexAstPseudoAssignMinusExpr expr_)
{
  HexAstPseudoAssignMinusExpr expr = AstVisitor::visit(expr_);

  this->cgen_pseudo_binary_expr(expr, "__minus__");

  return expr;
}

HexAstPseudoAssignMultiplyExpr
HexCodeGenVisitor::visit(HexAstPseudoAssignMultiplyExpr expr_)
{
  HexAstPseudoAssignMultiplyExpr expr = AstVisitor::visit(expr_);

  this->cgen_pseudo_binary_expr(expr, "__mul__");

  return expr;
}

HexAstPseudoAssignDivideExpr
HexCodeGenVisitor::visit(HexAstPseudoAssignDivideExpr expr_)
{
  HexAstPseudoAssignDivideExpr expr = AstVisitor::visit(expr_);

  this->cgen_pseudo_binary_expr(expr, "__div__");

  return expr;
}

HexAstPseudoAssignModulusExpr
HexCodeGenVisitor::visit(HexAstPseudoAssignModulusExpr expr_)
{
  HexAstPseudoAssignModulusExpr expr = AstVisitor::visit(expr_);

  this->cgen_pseudo_binary_expr(expr, "__mod__");

  return expr;
}

HexAstPseudoAssignBitwiseAndExpr
HexCodeGenVisitor::visit(HexAstPseudoAssignBitwiseAndExpr expr_)
{
  HexAstPseudoAssignBitwiseAndExpr expr = AstVisitor::visit(expr_);

  this->cgen_pseudo_binary_expr(expr, "__band__");

  return expr;
}

HexAstPseudoAssignBitwiseOrExpr
HexCodeGenVisitor::visit(HexAstPseudoAssignBitwiseOrExpr expr_)
{
  HexAstPseudoAssignBitwiseOrExpr expr = AstVisitor::visit(expr_);

  this->cgen_pseudo_binary_expr(expr, "__bor__");

  return expr;
}

HexAstPseudoAssignBitwiseXorExpr
HexCodeGenVisitor::visit(HexAstPseudoAssignBitwiseXorExpr expr_)
{
  HexAstPseudoAssignBitwiseXorExpr expr = AstVisitor::visit(expr_);

  this->cgen_pseudo_binary_expr(expr, "__bxor__");

  return expr;
}

HexAstPseudoAssignBitwiseLeftShiftExpr
HexCodeGenVisitor::visit(HexAstPseudoAssignBitwiseLeftShiftExpr expr_)
{
  HexAstPseudoAssignBitwiseLeftShiftExpr expr = AstVisitor::visit(expr_);

  this->cgen_pseudo_binary_expr(expr, "__blsh__");

  return expr;
}

HexAstPseudoAssignBitwiseRightShiftExpr
HexCodeGenVisitor::visit(HexAstPseudoAssignBitwiseRightShiftExpr expr_)
{
  HexAstPseudoAssignBitwiseRightShiftExpr expr = AstVisitor::visit(expr_);

  this->cgen_pseudo_binary_expr(expr, "__brsh__");

  return expr;
}

HexAstYieldExpr
HexCodeGenVisitor::visit(HexAstYieldExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstStringExpr
HexCodeGenVisitor::visit(HexAstStringExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstParenForm
HexCodeGenVisitor::visit(HexAstParenForm form)
{
  HEX_ASSERT(form);
  return form; 
}

HexAstExprList
HexCodeGenVisitor::visit(HexAstExprList exprlist)
{
  HEX_ASSERT(exprlist);
  return exprlist;
}

HexAstSimpleParam
HexCodeGenVisitor::visit(HexAstSimpleParam param)
{
  HEX_ASSERT(param);
  return param;
}

HexAstSimpleParamList
HexCodeGenVisitor::visit(HexAstSimpleParamList params_)
{
  HexAstSimpleParamList params = AstVisitor::visit(params_);

  this->iterate_with_index<HexAstSimpleParam>(
    params->list(),
    [this](HexAstSimpleParam param, int index) {
      this->add_inst(NULL, "getarg", "index", param->name()->value()); // TODO: convert index to string.
    }
  );

  return params;
}

HexAstKeywordParam
HexCodeGenVisitor::visit(HexAstKeywordParam param_)
{
  HexAstKeywordParam param = AstVisitor::visit(param_); 

  return param;
}

HexAstKeywordParamList
HexCodeGenVisitor::visit(HexAstKeywordParamList params)
{
  HEX_ASSERT(params);
  return params;
}

HexAstKeywordVal
HexCodeGenVisitor::visit(HexAstKeywordVal keyval)
{
  HEX_ASSERT(keyval);
  return keyval;
}

HexAstKeywordValList
HexCodeGenVisitor::visit(HexAstKeywordValList list)
{
  HEX_ASSERT(list);
  return list;
}

HexAstParameterList
HexCodeGenVisitor::visit(HexAstParameterList params)
{
  HEX_ASSERT(params);
  return params;
}

HexAstValAtom
HexCodeGenVisitor::visit(HexAstValAtom atom)
{
  HEX_ASSERT(atom);
  return atom;
}

HexAstValList
HexCodeGenVisitor::visit(HexAstValList vallist)
{
  HEX_ASSERT(vallist);
  return vallist;
}

HexAstArgList
HexCodeGenVisitor::visit(HexAstArgList arglist_)
{
  HexAstArgList arglist = AstVisitor::visit(arglist_);

  /*
   * A bit of magic needed to pass arguments to the callee.
   *
   * Because at the caller's point of view, we have no
   * clue about the signature of the callee. Hence in order
   * to pass a dynamic set of simple arguments and
   * positional arguments, here's what we are going to do:
   *
   * 1. Pack all simple arguments into a list object in the order
   * they are defined, and pack all positional arguments into
   * a dict object, both in the way they are defined.
   *
   * 2. Then, place both the list and the dict object onto the next
   * stack frame. In the caller's side, it will have to unpack
   * the arguments from these two obejcts and match them to its
   * parameters, and delete the two objects from its stack.
   *
   */

  HexAstValList simple_args = arglist->simple_args();
  HexAstIdentifier args = arglist->args();
  HexAstKeywordValList keyword_args = arglist->keyword_args();
  HexAstIdentifier kwargs = arglist->kwargs();

  this->add_inst(NULL, "invvar", "__args__", NULL);
  // TODO: Instantiate the list object and place it into $acu.
  this->add_inst(NULL, "copy", ACCUMULATOR, "__args__");

  this->add_inst(NULL, "invvar", "__args_append__", NULL);
  this->add_inst(NULL, "getattr", "__args__", "append");
  this->add_inst(NULL, "copy", TEMP, "__args_append__");

  this->add_inst(NULL, "invvar", "__kwargs__", NULL);
  // TODO: Instantiate the dict object and place it into $acu.
  this->add_inst(NULL, "copy", ACCUMULATOR, "__kwargs__");

  this->add_inst(NULL, "invvar", "__kwargs_put__", NULL);
  this->add_inst(NULL, "getattr", "__kwargs__", "put");
  this->add_inst(NULL, "copy", TEMP, "__kwargs_put__");

  if(simple_args) {
    this->iterate<HexAstValAtom>(
      simple_args->list(),
      [this](HexAstValAtom simple_arg) {
        // Load the simple argument into $acu.
        simple_arg->accept(this);

        this->add_inst(NULL, "putarg", "__args__", NULL);
        this->add_inst(NULL, "putarg", "ACCUMULATOR", NULL);
        this->add_inst(NULL, "jump", "__args_append__", NULL);
      }
    );
  }

  if(args) {
    // TODO: Check if *args is an iterable...

    // Load into $acu.
    args->accept(this);

    this->add_inst(NULL, "invvar", "__args_update__", NULL);
    this->add_inst(NULL, "getattr", "__args__", "update");
    this->add_inst(NULL, "copy", TEMP, "__args_update__");

    this->add_inst(NULL, "putarg", "__args__", NULL);
    this->add_inst(NULL, "putarg", ACCUMULATOR, NULL);
    this->add_inst(NULL, "jump", "__args_update__", NULL);
  }

  if(keyword_args) {
    this->iterate<HexAstKeywordVal>(
      keyword_args->list(),
      [this](HexAstKeywordVal keyword_val) {
        this->add_inst(NULL, "putarg", "__kwargs__", NULL);

        keyword_val->key()->accept(this);
        this->add_inst(NULL, "putarg", ACCUMULATOR, NULL);
        keyword_val->val()->accept(this);
        this->add_inst(NULL, "putarg", ACCUMULATOR, NULL);
        this->add_inst(NULL, "jump", "__kwargs_update__", NULL);
      }
    );
  }

  if(kwargs) {
    // TODO: Check if *kargs is a dict...
    kwargs->accept(this);

    this->add_inst(NULL, "invvar", "__kwargs_update__", NULL);
    this->add_inst(NULL, "getattr", "__kwargs__", "update");
    this->add_inst(NULL, "copy", TEMP, "__kwargs_update__");

    this->add_inst(NULL, "putarg", "__kwargs__", NULL);
    this->add_inst(NULL, "putarg", ACCUMULATOR, NULL);
    this->add_inst(NULL, "jump", "__kwargs_update__", NULL);
  }

  return arglist;
}

HexAstComprehension
HexCodeGenVisitor::visit(HexAstComprehension comprehension_)
{
  HexAstComprehension comprehension = AstVisitor::visit(comprehension_);

  return comprehension;
}

HexAstExplicitListForm
HexCodeGenVisitor::visit(HexAstExplicitListForm form_)
{
  HexAstExplicitListForm form = AstVisitor::visit(form_);

  return form;
}

HexAstImplicitListForm
HexCodeGenVisitor::visit(HexAstImplicitListForm form)
{
  HEX_ASSERT(form);
  return form;
}

HexAstFieldDef
HexCodeGenVisitor::visit(HexAstFieldDef def)
{
  HEX_ASSERT(def);
  return def;
}

HexAstFieldDefList
HexCodeGenVisitor::visit(HexAstFieldDefList list)
{
  HEX_ASSERT(list);
  return list;
}

HexAstKeyValuePair
HexCodeGenVisitor::visit(HexAstKeyValuePair pair)
{
  HEX_ASSERT(pair);
  return pair;
}

HexAstKeyValuePairList
HexCodeGenVisitor::visit(HexAstKeyValuePairList list)
{
  HEX_ASSERT(list);
  return list;
}

HexAstExplicitDictForm
HexCodeGenVisitor::visit(HexAstExplicitDictForm dict)
{
  HEX_ASSERT(dict);
  return dict;
}

HexAstImplicitDictForm
HexCodeGenVisitor::visit(HexAstImplicitDictForm dict)
{
  HEX_ASSERT(dict);
  return dict;
}

HexAstDecorator
HexCodeGenVisitor::visit(HexAstDecorator decorator)
{
  HEX_ASSERT(decorator);
  return decorator;
}

HexAstDecoratorList
HexCodeGenVisitor::visit(HexAstDecoratorList decorators)
{
  HEX_ASSERT(decorators);
  return decorators;
}

HexAstExprListAssignmentStmt
HexCodeGenVisitor::visit(HexAstExprListAssignmentStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstLambdaAssignmentStmt
HexCodeGenVisitor::visit(HexAstLambdaAssignmentStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstTaskDefAssignmentStmt
HexCodeGenVisitor::visit(HexAstTaskDefAssignmentStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstUsingSrc
HexCodeGenVisitor::visit(HexAstUsingSrc src)
{
  HEX_ASSERT(src);
  return src;
}

HexAstUsingStmtDirect
HexCodeGenVisitor::visit(HexAstUsingStmtDirect stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstUsingStmtRelative
HexCodeGenVisitor::visit(HexAstUsingStmtRelative stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstElifStmt
HexCodeGenVisitor::visit(HexAstElifStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstElifStmtGroup
HexCodeGenVisitor::visit(HexAstElifStmtGroup group)
{
  HEX_ASSERT(group);
  return group;
}

HexAstElseStmt
HexCodeGenVisitor::visit(HexAstElseStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstIfStmt
HexCodeGenVisitor::visit(HexAstIfStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstForStmt
HexCodeGenVisitor::visit(HexAstForStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstWithStmt
HexCodeGenVisitor::visit(HexAstWithStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstLockStmt
HexCodeGenVisitor::visit(HexAstLockStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstWhileStmt
HexCodeGenVisitor::visit(HexAstWhileStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstCatchStmt
HexCodeGenVisitor::visit(HexAstCatchStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstCatchStmtGroup
HexCodeGenVisitor::visit(HexAstCatchStmtGroup stmts)
{
  HEX_ASSERT(stmts);
  return stmts;
}

HexAstTryStmt
HexCodeGenVisitor::visit(HexAstTryStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstClassDef
HexCodeGenVisitor::visit(HexAstClassDef def)
{
  HEX_ASSERT(def);
  return def;
}

HexAstLambdaSimple
HexCodeGenVisitor::visit(HexAstLambdaSimple lambda)
{
  HEX_ASSERT(lambda);
  return lambda;
}

HexAstLambdaComplex
HexCodeGenVisitor::visit(HexAstLambdaComplex lambda)
{
  HEX_ASSERT(lambda);
  return lambda;
}

HexAstInputStmt
HexCodeGenVisitor::visit(HexAstInputStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstOutputStmt
HexCodeGenVisitor::visit(HexAstOutputStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstTaskState
HexCodeGenVisitor::visit(HexAstTaskState state)
{
  HEX_ASSERT(state);
  return state;
}

HexAstConditionalPreposition
HexCodeGenVisitor::visit(HexAstConditionalPreposition preposition)
{
  HEX_ASSERT(preposition); 
  return preposition;
}

HexAstConditionalClause
HexCodeGenVisitor::visit(HexAstConditionalClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstStartClauseSingle
HexCodeGenVisitor::visit(HexAstStartClauseSingle clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstStartClauseMultiple
HexCodeGenVisitor::visit(HexAstStartClauseMultiple clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstPauseClause
HexCodeGenVisitor::visit(HexAstPauseClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstResumeClause
HexCodeGenVisitor::visit(HexAstResumeClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstCancelClause
HexCodeGenVisitor::visit(HexAstCancelClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstConditionalDelayClause
HexCodeGenVisitor::visit(HexAstConditionalDelayClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstFixedDelayClause
HexCodeGenVisitor::visit(HexAstFixedDelayClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstStopClause
HexCodeGenVisitor::visit(HexAstStopClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstTaskDef
HexCodeGenVisitor::visit(HexAstTaskDef def)
{
  HEX_ASSERT(def);
  return def;
}

HexAstAwaitStmt
HexCodeGenVisitor::visit(HexAstAwaitStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstReturnStmt
HexCodeGenVisitor::visit(HexAstReturnStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstBreakStmt
HexCodeGenVisitor::visit(HexAstBreakStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstContinueStmt
HexCodeGenVisitor::visit(HexAstContinueStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstRaiseStmt
HexCodeGenVisitor::visit(HexAstRaiseStmt stmt)
{
  HEX_ASSERT(stmt); 
  return stmt;
}

HexAstExprListStmt
HexCodeGenVisitor::visit(HexAstExprListStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstStmtGroup
HexCodeGenVisitor::visit(HexAstStmtGroup group)
{
  HEX_ASSERT(group);
  return group;
}

HexAstHexProgram
HexCodeGenVisitor::visit(HexAstHexProgram program)
{
  HEX_ASSERT(program);
  return program;
}
