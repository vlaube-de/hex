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


#include "parser_test_base.h"
#include "../ast/ast.h"
#include "../hex_parser.h"
#include "../ast/visitor/ast_tostring_visitor.h"
#include "../../base/unittest.h"
#include "../../base/memory.h"
#include "../../base/assert.h"


class HexParserReprTest : public HexParserTestBase {
protected:
  void test(const c_str);
};

void
HexParserReprTest::test(const c_str expected_str)
{
  AstToStringVisitor* visitor = new AstToStringVisitor();
  HexAstHexProgram program = NULL;

  parser->parse(expected_str, &program);
  program->accept(visitor);
  c_str actual_str = visitor->str();

  HEX_DELETE(visitor);

  ASSERT_STREQ(expected_str, actual_str);
}

TEST_F(HexParserReprTest, TestIdentifier) {
  test("a;");
  test("self;");
  test("abc;");
  test("_abc;");
  test("_;");
  test("___;");
  test("_123;");
  test("_x123;");
  test("_x242x_;");
  test("__test__;");
  test("x__x;");
}

TEST_F(HexParserReprTest, TestIntegerLiteral) {
  test("0;");
  test("123;");
  test("0123;");
  // test("+1234567890;");
  test("-0987654321;");

  // binaries
  test("0b00;");
  test("0b01;");
  test("-0b0101;");
  test("0B00;");
  test("0B01;");
  test("-0B0101;");

  // octals...
  test("0o00;");
  test("0o01;");
  test("-0o01234567;");
  test("0O00;");
  test("0O01;");
  test("-0O01234567;");

  // hexadecimals...
  test("0x00;");
  test("0xFF;");
  test("-0x0123456789ABCDEF;");
  test("0X00;");
  test("0XFF;");
  test("-0X0123456789ABCDEF;");
}

TEST_F(HexParserReprTest, TestFloatingLiteral) {
  test("0.0;");
  test("3.1415926;");
  test("-0.987654321;");
  test("0.05e+3;");
  test("8.46e-5;");
  test("-987.654e-321;");
}

TEST_F(HexParserReprTest, TestStringLiteral) {
  // double quote strings...
  test("\"\";");
  test("\"     \";");
  test("\"this is a string\";");
  test("\"1234567890\";");
  test("\"!@#$%^&*()_+\";");
  test("\"[]|;',./\";");
  test("\"<>/?\";");
  test("\"\n\t\r\";");

  // single quote strings...
  test("\'\';");
  test("\'     \';");
  test("\'this is a string\';");
  test("\'1234567890\';");
  test("\'!@#$%^&*()_+\';");
  // test("\'[]|;',./\';");
  test("\'<>/?\';");
  test("\'\n\t\r\';");
}

TEST_F(HexParserReprTest, TestCall) {
  test("hello_world();");
  test("print(\"Hello world!\");");
  test("person.set_age(24);");
  test("person.get_info().to_dict();");
  test("person.name.fmt();");
  test("person.father().name;");
  test("person.father().set_name(\'James\');");
}

TEST_F(HexParserReprTest, TestAttributeRef) {
  test("obj.attr.field;");
}

// TEST_F(HexParserReprTest, TestName) {
//   test("a.b.c.d.e.f.g.h;");
//   test("name1.name2.name3;");
// }

TEST_F(HexParserReprTest, TestTargetList) {
  test("[for name in names];");
  test("[for a, e, i, o, u in alphabets];");
}

TEST_F(HexParserReprTest, TestNegateExpr) {
  test("-(1);");
  test("-(1 + 1);");
}

TEST_F(HexParserReprTest, TestNotExpr) {
  test("not 1;");
  test("not not 1;");
  test("not 1 != 1;");
  test("not a is not b;");
}

TEST_F(HexParserReprTest, TestBitwiseNotExpr) {
  test("~123;");
  test("~(~123);");
  test("~n;");
  test("~(~n);");
}

TEST_F(HexParserReprTest, TestIncrementExpr) {
  test("c++;");
  test("(c++)++;");
  test("(1 + 2)++;");
}

TEST_F(HexParserReprTest, TestDecrementTest) {
  test("i--;");
  test("(c++)--;");
  test("c++--;");
}

TEST_F(HexParserReprTest, TestExistentialExpr) {
  test("a?;");
  test("(a or b)?;");
  test("((a or b)? and (c or d)?)?;");
}

TEST_F(HexParserReprTest, TestAdditiveExpr) {
  test("1 + 1;");
  test("3 - 2;");
  test("1 + 2 - 3;");
  test("1 + (2 - 3);");
}

TEST_F(HexParserReprTest, TestMultiplicativeExpr) {
  test("0 * 1;");
  test("3.14 * (3 - 9.543);");
  test("4.55 - (53 + 44) / 3;");
  test("100 % 20 == 5;");
}

TEST_F(HexParserReprTest, TestPowerExpr) {
  test("a ** 2;");
  test("a ** (2 + 2 % 1);");
  test("1 ** ((2 ** 3) ** 4);");
}

TEST_F(HexParserReprTest, TestBitwiseExpr) {
  test("1 & 2 | 3 ^ 4;");
  test("a << 3;");
  test("b >> (3 - 1);");
}

TEST_F(HexParserReprTest, TestComparisonExpr) {
  test("a == (2 != 3 or not true);");
  test("2 == 1 + 1;");
  test("1 != 2;");
  test("a is 2 or 3;");
  test("n > n - 1;");
  test("3 >= 2 + 1;");
  test("4 < 100 / 20;");
  test("gg <= glhf;");
  test("a in b in c in d;");
  test("a not in b not in c not in d;");
}

TEST_F(HexParserReprTest, TestLogicExpr) {
  test("a and b or c;");
}

TEST_F(HexParserReprTest, TestEllipseExpr) {
  test("1 in 1..100;");
  test("1..100 in 1...100;");
}

TEST_F(HexParserReprTest, TestConditionalExpr) {
  test("if a > 0 then a else b;");
  test("if a then if 2 == 1 + 1 then 1 else -1 else 99;");
}

TEST_F(HexParserReprTest, TestPseudoAssignExprs) {
  test("a += 1;");
  test("a += b -= c *= d /= e %= 1;");
  test("x &= y |= z ^= 1;");
  test("r >>= 1;");
  test("s <<= 2;");
}

TEST_F(HexParserReprTest, TestYieldExpr) {
  test("yield;");
  test("yield (yield);");
  test("yield (yield (1, 2, 3));");
}

TEST_F(HexParserReprTest, TestStringExpr) {
  test("\"My name is %s and I'm %d years old.\" % (\'Yanzheng Li\', 20);");
  test("\"This is a list of prime numbers.\" % (1, 3, 5, 7, 11, 13, 17, 19);");
}

TEST_F(HexParserReprTest, TestParenForm) {
  test("(1, 2, 3);");
  test("(1, (2, 3), (4, 5, 6), (7, 8, 9, 10));");
  test("(1, (3.1415926 * (2 + (17 / 2))), (100 % (10 + 10)));");
}

TEST_F(HexParserReprTest, TestListForm) {
  test("[];");
  test("[[], [], []];");
  test("[[[[[[[]]]]]]];");
  test("[[1], [2, 3], [4, 5, 6]];");
  test("[1, 2, 4, 8, 16, 32];");
  test("[for i in 1...100];");
  test("[for i in 1...100 if isprime(i)];");
  test("[i ** 2 for i in 1...100];");
  test("[i << 2 for i in 1...100 if isprime(i)];");
}

TEST_F(HexParserReprTest, TestDictForm) {
  test("{};");
  test("{a: 1, b: 2};");
  test("{list: [], paren: (1), dict: {}};");
  test(
  "{"
    "name: \"James Bond\", "
    "info: {"
      "age: 35, "
      "height: \'180cm\', "
      "weight: \'60kg\', "
      "occupations: [\'assassin\', \'secret agent\']"
    "}"
  "};"
  );
}

TEST_F(HexParserReprTest, TestMapForm) {
  test("{0x01 => 123, 0x0A => 789};");
  test(
  "{"
    "3.1415 => [3, 1, 4, 1, 5], "
    "0.00 => [0b00, 0o00, 0x00], "
    "5.457 => {"
      "0x01 => 5.235, "
      "0xFA => 333, "
      "0b01 => 94"
    "}"
  "};"
  );
}

TEST_F(HexParserReprTest, TestLambdaSimpleForm) {
  test("sqr = (x) -> x * x;");
  test("wrapper = (func, *args, **kwargs) -> func(session(), *args, **kwargs);");
}

TEST_F(HexParserReprTest, TestLambdaComplexForm) {
  test(
    "inc = (n) => {"
      "n++;"
    "};"
  );

  test(
    "@with_txn(session=true)"
"\n"
    "@log_error"
"\n"
    "commit_transaction = (session, changes, user_id, lock_db=true, **kwargs) => {"
      "log(\"Begin transaction from %s\" % user_id);"
      "changes = self.validate_and_filter_changes(changes, user_id);"
      "self._commit(changes, user_id, lock_db=lock_db, **kwargs);"
    "};"
  );

  test(
    "retry_on_error = (func, errors, retry_num=3, *args, **kwargs) => {"
      "for _ in 1...retry_num {"
        "try {"
          "func(*args, **kwargs);"
        "}"
        "catch e {"
          "if e not in errors {"
            "raise e;"
          "}"
        "}"
      "}"
    "};"
  );
}

TEST_F(HexParserReprTest, TestInputStmt) {
  test("stdout <<< logging.log <<< filters <<< src();");
}

TEST_F(HexParserReprTest, TestOutputStmt) {
  test("stdin >>> logging.log >>> filters >>> dst();");
}

TEST_F(HexParserReprTest, TestClassDefinition) {
  test("class MyObject;");

  test("class MyObject extends YourObject;");

  test(
    "class Person {"

      "name: null"
"\n"
      "age: null"
"\n"
      "country: null"
"\n"
      "gender: \'male\'"
"\n"
      "hobbies: []"
"\n"
      "skills: []"
"\n"
      "__init__: (name, age) => {"
        "self.name = name;"
        "self.age = age;"
      "}"
"\n"
      "hello: () => {"
        "print(\"Hello, my name is @name, I'm @age and I'm from @country\");"
      "}"
"\n"
      "set_age: (age) => {"
        "return if age < 0;"
        "self.age = age;"
      "}"
"\n"
    "}"
  );

  test(
    "@add_to_cache"
"\n"
    "class Student extends Person {"

      "grade: 8"
"\n"
      "school: null"
"\n"
      "courses: {}"
"\n"
      "grades: {}"
"\n"
      "enroll: (course) => {"
        "desired_course = school.courses.find(course);"
        "if desired_course and desired_course.grade <= self.grade {"
          "self.courses.add(desired_course.code);"
        "}"
      "}"
"\n"
      "drop: (course) => {"
        "desired_course = school.courses.find(course);"
        "if desired_course and len(courses) - 1 >= school.MIN_COURSES {"
          "self.courses.remove(desired_course.code);"
        "}"
      "}"
"\n"
    "}"
  );
}

TEST_F(HexParserReprTest, TestUsingStmt) {
  test("using http;");
  test("using rsa_hash as hash;");
  test("using qsort, bsort, isort in sorts;");
  test("using encid, decid in lib.core.id;");
  test("using encid, decid in .;");
  test("using * in lib;");
  test("using * in lib.core.id;");
}

TEST_F(HexParserReprTest, TestIfElseStmt) {
  test(
    "if argc == 0 {"
      "hello_world();"
    "}"
  );

  // TODO: space between elif's...
  test(
    "if argc == 0 {"
      "hello_world();"
    "}elif argc == 1 {"
      "print_usage();"
    "}else {"
      "exit(-1);"
    "}"
  );

  test(
    "if argc == 0 {"
      "hello_world();"
    "}elif argc == 1 {"
      "print_usage();"
    "}elif argc == 2 {"
      "run_job();"
    "}elif argc == 3 {"
      "run_job() async;"
    "}elif argc == 4 {"
      "run_job() async;"
    "}else {"
      "exit(-1);"
    "}"
  );

  test(
    "if argc == 0 {"
      "hello_world();"
    "}else {"
      "exit(-1);"
    "}"
  );

  test(
    "if obj.callback.call_count >= self.COUNT_LIMIT {"
      "log_call(obj);"
      "if obj.result {"
        "log_result(obj.result);"
      "}else {"
        "run_job() async;"
      "}"
    "}else {"
      "hello_world();"
    "}"
  );
}

TEST_F(HexParserReprTest, TestForStmt) {
  test(
    "for i in 1...100 {"
      "if isprime(i) {"
        "print(i);"
      "}"
    "}"
  );

  test(
    "for i, j in [(i, i * 2) for i in 1...100] where i + j >= 50 {"
      "compute(i, j);"
    "}"
  );
}

TEST_F(HexParserReprTest, TestWithStmt) {
  test(
    "with self.logic.begin(session=True) as session {"
      "user = models.User.load(session, id);"
      "user.call();"
    "}"
  );

  test(
    "with self.logic.begin(session=True), self.logic.cache() as session_cache {"
      "for user in self.get_users() {"
        "user.register(session_cache);"
      "}"
    "}"
  );
}

TEST_F(HexParserReprTest, TestWhileStmt) {
  test(
    "i = 0;"
    "while i <= 100 {"
      "sqr(i);"
      "i += 1;"
    "}"
  );
}

TEST_F(HexParserReprTest, TestLockStmt) {
  test(
    "lock self.counter {"
      "self.counter++;"
    "}"
  );

  test(
    "lock self.counter, self.cache {"
      "self.commit();"
    "}"
  );
}

TEST_F(HexParserReprTest, TestTryCatchStmt) {
  test(
    "try {"
      "self.do_something_dangerous();"
    "}catch {"
      "print(\'Everything is alright.\');"
    "}"
  );

  test(
    "try {"
      "self.do_something_dangerous();"
    "}catch IOError, SocketError, MemError as e {"
      "self.log_error(e);"
      "print(\'Everything is alright.\');"
    "}catch OperationalError {"
      "self.log_error(e);"
      "exit(-1);"
    "}"
  );
}

TEST_F(HexParserReprTest, TestAwaitStmt) {
  test(
    "await {"
      "for _ in 1...10 {"
        "self.run() async;"
      "}"
    "}"
  );
}

TEST_F(HexParserReprTest, TestTaskDefinition) {
  // test(
  //   "mytask = start t1,"
  //             "delay by mins(2),"
  //             "start (t2, t3, t4) as tasks,"
  //             "stop any(tasks) when any(tasks) stop,"
  //             "hello_world() after all(tasks) finish;"
  // );
}

TEST_F(HexParserReprTest, TestReturnStmt) {
  test("return;");
  test("return obj;");
  test("return num if isprime(num);");
  test("return 1, 2, 3;");
  test("return x, y, z if sum(x, y) == z;");
}

TEST_F(HexParserReprTest, TestBreakStmt) {
  test("break;");
  test("break if self.job.stopped;");

  test(
    "for _ in 1..100 {"
      "self.run();"
      "break if self.job.is_finished;"
    "}"
  );
}

TEST_F(HexParserReprTest, TestContinueStmt) {
  test("continue;");
  test("continue if self.skip(i);");

  test(
    "for _ in 1..100 {"
      "continue if not self.jobs(i).is_ready;"
      "self.run();"
    "}"
  );
}

TEST_F(HexParserReprTest, TestRaiseStmt) {
  test("raise IOError();");
  test("raise errors.OperationalError;");
}

TEST_F(HexParserReprTest, TestExprListStmt) {
  test("1;");
  test("myobj;");
  test("x, y, z;");
  test("[for _ in 1...100], (x, y, z), {a: 1, b: 2}, {1 => a, 2 => b};");
}
