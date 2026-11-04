<!-- SPDX-License-Identifier: CC-BY-4.0 -->

# C÷ language guide (initial draft)

This document describes the syntax accepted by the current front end. It is an early language specification and may evolve before the 1.0 release.

## Hello world

~~~cdiv
print("Hello, world!");
~~~

## Values and variables

~~~cdiv
name = "Raha";
age: int = 12;
pi = 3.14;
ready = true;
~~~

A variable may be assigned with name = value;. An optional type annotation can be written as name: type = value;. The syntax checker accepts these forms. The preview native backend compiles supported assignments; type annotations currently map `int` to a 64-bit integer, `float`/`double` to a double, `bool` to a boolean, and `string`/`str` to `std::string` in generated C++.

## Conditions

~~~cdiv
if age >= 18 {
    print("Adult");
} else {
    print("Not an adult yet");
}
~~~

else if is also accepted.

## Loops

~~~cdiv
repeat 5 {
    print("Repeated");
}

while age > 0 {
    age = age - 1;
}
~~~

## Functions

~~~cdiv
fn add(a: int, b: int) -> int {
    return a + b;
}

answer = add(20, 22);
~~~

The return type after -> is optional in the current grammar. Parameters use name: type syntax.

## Modules

~~~cdiv
import math;
~~~

`import math;` is supported by the native preview and exposes host C++ standard math functions. General module resolution and the C÷ standard library are not implemented yet.

## Expressions and operators

The current parser recognizes numeric and string literals, true and false, identifiers, function calls, parentheses, unary !, +, -, and these binary operators (from lower to higher precedence):

1. ||
2. && 
3. ==, !=
4. <, <=, >, >=
5. +, -
6. *, /, %

Statements end with semicolons, except block-based statements (if, repeat, while, and function declarations).

## Comments

~~~cdiv
// A single-line comment.

/*
   A multi-line comment.
   The lexer ignores everything until the closing marker.
*/
~~~

Unterminated block comments are reported as lexical errors. Nested block comments are not supported in this preview.

## Current implementation boundary

`cdiv lex` tokenizes source code and `cdiv check` validates lexical and grammatical structure. `cdiv build` and `cdiv run` compile the currently supported subset through the host C++20 compiler. Complete static type checking, general import resolution, memory management, and a standalone C÷ runtime are still not implemented.
