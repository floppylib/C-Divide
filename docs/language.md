# C÷ language guide (initial draft)

This document describes the syntax accepted by the current front end. It is an early language specification and may evolve before the 1.0 release.

## Hello world

    print("Hello, world!");

## Values and variables

    name = "Raha";
    age: int = 12;
    pi = 3.14;
    ready = true;

A variable may be assigned with name = value;. An optional type annotation can be written as name: type = value;. The current checker parses these forms but does not yet perform type checking or execute them.

## Conditions

    if age >= 18 {
        print("Adult");
    } else {
        print("Not an adult yet");
    }

else if is also accepted.

## Loops

    repeat 5 {
        print("Repeated");
    }

    while age > 0 {
        age = age - 1;
    }

## Functions

    fn add(a: int, b: int) -> int {
        return a + b;
    }

    answer = add(20, 22);

The return type after -> is optional in the current grammar. Parameters use name: type syntax.

## Modules

    import math;

Module resolution and the standard library are not implemented yet.

## Expressions and operators

The current parser recognizes numeric and string literals, true and false, identifiers, function calls, parentheses, unary !, +, -, and these binary operators from lower to higher precedence:

1. || 
2. && 
3. ==, !=
4. <, <=, >, >=
5. +, -
6. *, /, %

Statements end with semicolons, except block-based statements: if, repeat, while, and function declarations.

## Comments

    // A single-line comment.

## Current implementation boundary

The cdiv lex command tokenizes source code and cdiv check validates lexical and grammatical structure. They do not yet evaluate code, type-check expressions, resolve imports, manage memory, or emit native machine code. Those are planned compiler components, not current capabilities.
