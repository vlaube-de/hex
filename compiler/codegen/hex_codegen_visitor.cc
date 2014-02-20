/*
 * HEX Programming Language
 * Copyrexpr (C) 2013  Yanzheng Li
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

#include <sneaker/libc/assert.h>
#include "hex_codegen_visitor.h"
#include "hex_object_block_generator.h"
#include "hex_stmt_codegen_visitor.h"
#include "../ast/ast.h"

HexCodeGenerationVisitor::HexCodeGenerationVisitor(
  HexCompilationUnitMetadata * metadata,
  HexAstHexProgram ast
):
  _metadata(metadata),
  _ast(ast),
  _blocks(new std::list<HexObjectBlockGenerator*>())
{
}

std::list<HexObjectBlockGenerator*>*
HexCodeGenerationVisitor::generate()
{
  this->ast()->accept(this);
  return this->_blocks;
}

HexCompilationUnitMetadata*
HexCodeGenerationVisitor::metadata()
{
  return this->_metadata.get();
}

HexAstHexProgram
HexCodeGenerationVisitor::ast()
{
  return this->_ast.get();
}

template<class T>
void
HexCodeGenerationVisitor::iterate(std::list<T>* list)
{
  typename std::list<T>::iterator itr;
  for(itr=list->begin(); itr != list->end(); itr++) {
    ((T)(*itr))->accept(this);
  }
}

HexAstClassDef
HexCodeGenerationVisitor::visit(HexAstClassDef classdef_)
{
  HexAstClassDef classdef = AstVisitor::visit(classdef_);

  QuadrupleCodeVectorGenerator * cv_generator = NULL;
  HexStmtCodeGenerationVisitor stmt_visitor;

  // Generate object block
  // TODO: to be implemented...
  HexObjectBlockGenerator * object_block = new HexObjectBlockGenerator(
    "",
    "",
    "",
    "",
    "",
    cv_generator
  );

  return classdef;
}

HexAstSimpleLambda
HexCodeGenerationVisitor::visit(HexAstSimpleLambda lambda_)
{
  HexAstSimpleLambda lambda = AstVisitor::visit(lambda_);

  QuadrupleCodeVectorGenerator * cv_generator = NULL;
  HexStmtCodeGenerationVisitor stmt_visitor;

  lambda->expr()->accept(&stmt_visitor);

  cv_generator = stmt_visitor.cv_generator();

  // Generate object block
  // TODO: to be implemented...
  HexObjectBlockGenerator * object_block = new HexObjectBlockGenerator(
    "",
    "",
    "",
    "",
    "",
    cv_generator
  );

  return lambda;
}

HexAstComplexLambda
HexCodeGenerationVisitor::visit(HexAstComplexLambda lambda_)
{
  HexAstComplexLambda lambda = AstVisitor::visit(lambda_);

  QuadrupleCodeVectorGenerator * cv_generator = NULL;
  HexStmtCodeGenerationVisitor stmt_visitor;

  if(lambda->stmts()) {
    lambda->stmts()->accept(&stmt_visitor);
  }

  cv_generator = stmt_visitor.cv_generator();

  // Generate object block
  // TODO: to be implemented...
  HexObjectBlockGenerator * object_block = new HexObjectBlockGenerator(
    "",
    "",
    "",
    "",
    "",
    cv_generator
  );

  if(lambda->stmts()) {
    lambda->stmts()->accept(this);
  }

  return lambda;
}

HexAstStmtGroup
HexCodeGenerationVisitor::visit(HexAstStmtGroup stmts_)
{
  HexAstStmtGroup stmts = AstVisitor::visit(stmts_);

  this->iterate<HexAstStmt>(stmts->list());

  return stmts;
}

HexAstHexProgram
HexCodeGenerationVisitor::visit(HexAstHexProgram program_)
{
  HexAstHexProgram program = AstVisitor::visit(program_);

  QuadrupleCodeVectorGenerator * cv_generator = NULL;
  HexStmtCodeGenerationVisitor stmt_visitor;

  if(program->stmts()) {
    program->stmts()->accept(&stmt_visitor);
  }

  cv_generator = stmt_visitor.cv_generator();

  // Generate object block
  // TODO: to be implemented...
  HexObjectBlockGenerator * object_block = new HexObjectBlockGenerator(
    "",
    "",
    "",
    "",
    "",
    cv_generator
  );

  if(program->stmts()) {
    program->stmts()->accept(this);
  }

  return program;
}