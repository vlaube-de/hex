%{
#include <stdio.h>

#define YYSTYPE char*
extern YYSTYPE yylval;
%}

%union
{
  char character;
  char* string;
  int integer;
  double float;
}

%token AND AS
%token BASE BOOL BREAK
%token CASE CATCH CHAR CLASS CONST CONTINUE COROUTINE
%token DEF DEFER DEFAULT DO DOUBLE
%token ELSE ENUM EXT FLOAT FOR IF IMPORT IN INT INTERFACE
%token LAZY LONG
%token NEW NOT
%token OR
%token PASS PRIVATE PROTECTED PUBLIC
%token RETURN
%token SHORT SIZEOF STACKALLOC STATIC STRING STRUCT SWITCH
%token TASK THIS THROW TRY TYPEOF UCHAR UINT ULONG USHORT
%token VIRTUAL VOLATILE
%token WHERE WHILE
%token FINALLY

%token IDENTIFIER

%token <character> CHARACTER_LITERAL

%token <string> STRING_LITERAL

%token COMMENT

%token <integer> DECIMALINTEGER BININTEGER OCTINTEGER HEXINTEGER

%token <float> FLOATINGNUM

%token PLUS_OP MINUS_OP MUL_OP DIV_OP MOD_OP

%token ASSIGN_OP PLUS_ASSIGN MINUS_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN

%token NOT_BITWISE AND_BITWISE OR_BITWISE XOR_BITWISE SHIFTLEFT_BITWISE SHIFTRIGHT_BITWISE
%token NOT_ASSIGN AND_ASSIGN OR_ASSIGN XOR_ASSIGN SHIFTLEFT_ASSIGN SHIFTRIGHT_ASSIGN

%token EQ_OP GREATER_OP LESS_OP GEQ_OP LEQ_OP

%token INC_OP DEC_OP

%token LAMBDA_OP

%token ELLIPSIS

%token POND



%%

input: /* empty line */
  ;

INTEGER
  : DECIMALINTEGER
  | BININTEGER
  | OCTINTEGER
  | HEXINTEGER
  ;

LITERAL
  : CHARACTER_LITERAL
  | STRING_LITERAL
  | INTEGER
  | FLOATINGNUM
  ;

unary_operator
  : PLUS_OP
  | MINUS_OP
  | INC_OP
  | DEC_OP
  | NOT_BITWISE
  | NOT
  ;

assignment_operator
  : ASSIGN_OP
  | ASSIGN_OP [NEW]
  | ASSIGN_OP [LAZY NEW]
  | MUL_ASSIGN
  | DIV_ASSIGN
  | MOD_ASSIGN
  | PLUS_ASSIGN
  | MINUS_ASSIGN
  | SHIFTLEFT_ASSIGN
  | SHIFTRIGHT_ASSIGN
  | NOT_ASSIGN
  | AND_ASSIGN
  | OR_ASSIGN
  | XOR_ASSIGN
  | [LAZY] NEW
  ;

/******************** expressions ********************/

/* 
 *  Primary expressions
 */
primary_expr
  : IDENTIFIER
  | STRING_LITERAL
  | expr
  ;

/*
 *  Postfix expression
 *
 *  Postfix expression consist of primary expressions in which
 *  postfix operators follow a primary expression. The postfix
 *  operator. The postfix operators are listed below:
 *
 *  Operator Name                |         Operator Notation
 *  _____________________________|____________________________
 *                               |
 *  Subscript operator           |         []
 *  Function call operators      |         ()
 *  Member access                |         .
 *  Postfix increment operator   |         ++
 *  Postfix decrement operator   |         --
 *
 */
postfix_expr
  : primary_expr
  | postfix_expr '[' expr ']'
  | postfix_expr '(' ')'
  | postfix_expr '(' arg_expr_list ')'
  | postfix_expr '.' IDENTIFIER
  | postfix_expr INC_OP
  | postfix_expr DEC_OP
  ;

/*
 *  Argument expression list
 */
arg_expr_list
  : assignment_expr
  | assignment_expr AS IDENTIFIER
  | arg_expr_list ',' assignment_expr
  | arg_expr_list ',' assignment_expr AS IDENTIFIER
  ;

/*
 *  Unary expression
 */
unary_expr
  : postfix_expr
  | INC_OP unary_expr
  | DEC_OP unary_expr
  | unary_operator cast_expr
  | SIZEOF IDENTIDIER | TYPE
  | SIZEOF '(' IDENTIFIER | TYPE ')'
  ;

/*
 *  Cast expression
 */
cast_expr
  : unary_expr
  | '(' typename ')' cast_expr
  ;

/*
 *  Multiplicative expression
 */
multiplicative_expr
  : cast_expr
  | multiplicative_expr MUL_OP cast_expr
  | multiplicative_expr DIV_OP cast_expr
  | multiplicative_expr MOD_OP cast_expr
  ;

/*
 *  Additive expression
 */
additive_expr
  : multiplicative_expr
  | additive_expr PLUS_OP multiplicative_expr
  | additive_expr MINUS_OP multiplicative_expr
  ;

/*
 * Shift expression
 */
shift_expr
  : additive_expr
  | shift_expr SHIFTLEFT_BITWISE additive_expr
  | shift_expr SHIFTRIGHT_BITWISE additive_expr
  ;

/*
 * Relational expression
 */
relational_expr
  : shift_expr
  | relational_expr LESS_OP shift_expr
  | relational_expr GREATER_OP shift_expr
  | relational_expr LE_OP shift_expr
  | relational_expr GE_OP shift_expr
  ;

/*
 *  Equality expression
 */
equality_expr
  : relational_expr
  | equality_expr EQ_OP relational_expr
  | equality_expr NEQ_OP relational_expr
  ;

/*
 *  Bitwise AND expression
 */
and_expr
  : equality_expr
  | and_expr '&' equality_expr
  ;

/*
 *  Bitwise XOR expression
 */
exclusive_or_expr
  : and_expr
  | exclusive_or_expr '^' and_expr
  ;

/*
 *  Bitwise OR expression
 */
inclusive_or_expr
  : exclusive_or_expr
  | inclusive_or_expr '|' exclusive_or_expr
  ;

/*
 *  Logical AND expression
 */
logical_and_expr
  : inclusive_or_expr
  | logical_and_expr AND inclusive_or_expr
  ;

/*
 *  Logical OR expression
 */
logical_or_expr
  : logical_and_expr
  | logical_or_expr OR logical_and_expr
  ;

/*
 *  Conditional expression
 */
conditional_expr
  : logical_or_expr
  | expression IF logical_or_expr ELSE conditional_expr
  ;

/*
 * Constant expression
 */
const_expr
  : conditional_expr
  ;

/*
 *  Assignment expression
 */
assignment_expr
  : conditional_expr
  | unary_expr assignment_operator assignment_expr
  ;

/*
 *  Lambda expression
 */
lambda_expr
  : arg_expr_list LAMBDA_OP expression
  ;

/* 
 *  expression
 */
expr
  : assignment_expr
  | expression ',' assignment_expr
  ;


/******************** declarations ********************/


/*
 *  Declaration
 */
declaration
  : declaration_specifiers NEWLINE
  | declaration_specifiers init_declarator_list NEWLINE
  ;

/*
 *  Declaration specifiers
 */
declaration_specifiers
  : storage_class_specifier
  | storage_class_specifier declaration_specifiers
  | type_specifier
  | type_specifier declaration_specifiers
  | type_qualifier
  | type_qualifier declaration_specifiers
  ;

/*
 *  Init declaration list
 */
init_declarator_list
  : init_declarator
  | init_declarator_list ',' init_declarator
  ;

/*
 *  Init declarator
 */
init_declarator
  : declarator
  | init_declarator_list ',' init_declarator
  ;

/*
 *  Declarator
 */
declarator
  : direct_declarator
  ;

/*
 *  Direct declarator
 */
direct_declarator
  : IDENTIFIER
  | '(' declarator ')'
  | direct_declarator '[' const_expr ']'
  | direct_declarator '[' ']'
  ;

/*
 *  Storage class specifier 
 */
storage_class_specifier
  : STATIC
  ;

/*
 *  Type specifier
 */
type_specifier
  : CHAR
  | SHORT
  | INT
  | LONG
  | FLOAT
  | DOUBLE
  | UCHAR
  | USHORT
  | UINT
  | ULONG
  | IDENTIFIER
  ;

/*
 *  Type qualifier
 */
type_qualifier
  : CONST
  | VOLATILE
  ;

/*
 *  Type qualifier list
 */
 type_qualifier_list
  : type_qualifier
  | type_qualifier_list type_qualifier
  ;

/*
 *  Identifier list
 */
identifier_list
  : IDENTIFIER
  | identifier_list ',' IDENTIFIER
  ;

/*
 * Parameter type list
 */
paramter_type_list
  : parameter_list
  | parameter_list ',' ELIPSIS
  ;

/*
 *  Parameter list
 */
parameter_list
  : parameter_declaration
  | parameter_list, parameter_declaration
  ;

/*
 *  Parameter declaration
 */
parameter_declaration
  : IDENTIFIER
  | declaration_specifiers declarator
  ;


/******************** initializers ********************/

/*
 *  Initializer
 *
 *  Initializers for basic data structures supported by HEX.
 *
 *  Examples of these basic structures:
 *
 *  Type          |   Literal Example                                               |       Description
 *  ______________|_________________________________________________________________|________________________________________
 *                |                                                                 |
 *  list          |   ["HEX", 5, 'e']                                               |   Mutable array-type list
 *  array         |   int numbers[5] = {1,2,3,4,5}                                  |   Immutable sequence of data
 *  tuple         |   ("HEX", 5, 'e')                                               |   Immutable tuple
 *  struct        |   {name = "HEX", version = 0.1}                                 |   Mutable struct
 *  set           |   [("HEX", 5, 'e')]                                             |   Unordered collection of unique data
 *  map           |   {"apple" : "sweet", "orange" : "sour"}                        |   Key-value dictionary
 *  multimap      |   {"apple" : ("sweet", "red"), "orange" : ("sour", "orange")}   |   Single key multiple value dictionary 
 */
initializer
  : assignment_expr
  | '[' list_initializer_list ']'               /* list */
  | '[' list_initializer_list ',' ']'           /* list */
  | '{' array_initializer_list '}'              /* array */
  | '{' array_initializer_list ',' '}'          /* array */
  | '(' tuple_initializer_list ')'              /* tuple */
  | '(' tuple_initializer_list ',' ')'          /* tuple */
  | '{' struct_initializer_list '}'             /* struct */
  | '{' struct_initializer_list ',' '}'         /* struct */
  | '(' '[' set_initializer_list  ']' ')'       /* set */
  | '(' '[' set_initializer_list ','  ']' ')'   /* set */
  | '{' map_initializer_list '}'                /* map */
  | '{' map_initializer_list ',' '}'            /* map */
  | '{' multimap_initializer_list '}'           /* multimap */
  | '{' multimap_initializer_list ',' '}'       /* multimap */
  ;

/*
 *  List initializer list
 */
list_initializer_list
  : initializer
  | list_initializer_list ',' initializer
  ;

/*
 *  Array initializer list
 */
array_initializer_list
  : list_initializer_list
  | array_initializer_list ',' list_initializer_list
  ;

/*
 *  Tuple initializer list
 */
tuple_initializer_list
  : array_initializer_list
  | tuple_initializer_list ',' array_initializer_list
  ;

/*
 *  Struct initializer list
 */
struct_initializer_list
  : IDENTIFIER '=' LITERAL
  | IDENTIFIER '=' initializer
  | struct_initializer_list ',' IDENTIFIER '=' LITERAL
  | struct_initializer_list ',' IDENTIFIER '=' initializer
  ;

/*
 *  Set initializer list
 */
set_initializer_list
  : tuple_initializer_list
  | set_initializer_list ',' tuple_initializer_list
  ;

/*
 *  Map initializer list
 */
map_initializer_list
  : LITERAL ':' LITERAL
  | LITERAL ':' set_initializer_list
  | IDENTIFIER ':' LITERAL
  | IDENTIFIER ':' set_initializer_list
  | map_initializer_list ',' LITERAL ':' LITERAL
  | map_initializer_list ',' LITERAL ':' set_initializer_list
  | map_initializer_list ',' IDENTIFIER ':' LITERAL
  | map_initializer_list ',' IDENTIFIER ':' set_initializer_list
  ;

/*
 *  Multimap initializer list
 */
multimap_initializer_list
  : LITERAL ':' '(' ')'
  | LITERAL ':' '(' map_initializer_list ')'
  | IDENTIFIER ':' '(' ')'
  | IDENTIFIER ':' '(' map_initializer_list ')'
  | multimap_initializer_list ',' LITERAL ':' '(' ')'
  | multimap_initializer_list ',' LITERAL ':' '(' map_initializer_list ')'
  | multimap_initializer_list ',' IDENTIFIER ':' '(' ')'
  | multimap_initializer_list ',' IDENTIFIER ':' set_initializer_list
  ;


/******************** statements ********************/


/*
 *  Statement
 */
stmr
  : expr_stmt
  | if_stmt
  | for_stmt
  | while_stmt
  | dowhile_stmt
  | try_stmt
  | jump_stmt
  ;

/*
 *  Statement list
 */
stmt_list
  : stmt
  | stmt_list stmt
  ;

/*
 *  Expression statement
 */
expr_stmt
  : expr NEWLINE
  ;

/*
 * If statement
 */
if_stmt
  : IF expr : stmt (ELIF expr ':' stmt)* [ELSE ':' stmt]
  ;

/*
 *  For statement
 */
for_stmt
  : FOR target_list IN expr [WHERE comp_expr] stmt
  ;

/*
 *  While statement
 */
while_stmt
  : WHILE expr ':' stmt
  ;

/*
 *  Do-while statement
 */
dowhile_stmt
  : DO stmt WHILE expr
  ;

/*
 *  Try statement
 */
try_stmt
  : TRY ':' stmt CATCH expr ':' (FINALLY stmt)
  ;

/*
 *  Jump statement
 */
jump_statement
  : CONTINUE NEWLINE
  | BREAK NEWLINE
  | RETURN NEWLINE
  | RETURN expr NEWLINE
  ;

/*
 *  Pass statement
 */
pass_stmt
  : PASS NEWLINE
  ;


/******************** function ********************/


/*
 *  Function declaration specifier
 */
func_declaration_specifier
  : DEF
  ;

/*
 *  function_definition
 */
func_definition
  : func_declaration_specifier [declaration_specifiers] IDENTIFIER stmt_list
  ;


%%

int yyerror(char* s) {
	printf("%s\n", s);
}

/* Return 1 stops at EOF,
 * return 0 continues reading. 
 */
int yywrap() {
  return 1;
}

int main() {
	yyparse();
}