# Compiler architecture

C÷ is intended to become a native compiled language. The repository starts with a small, dependency-free C++20 front end so contributors can build it with a standard C++ compiler and CMake.

## Current pipeline

    .cdiv source
        |
        v
    Lexer  ---> tokens + source diagnostics
        |
        v
    Parser ---> syntax diagnostics

The initial parser validates declarations, statements, blocks, calls, and operator precedence. It currently does not build a persistent AST or perform semantic analysis.

## Planned pipeline

    .cdiv source
        -> Lexer
        -> Parser / AST
        -> Name and type analysis
        -> C÷ intermediate representation (IR)
        -> LLVM native-code backend
        -> platform linker
        -> native executable

The LLVM backend is a design target, not a dependency or completed feature in this initial commit. Keeping the front end independent of LLVM makes early language work easier to build and test.

## Design principles

- Readable syntax: familiar English keywords and punctuation.
- Native output: the long-term compiler produces platform executables.
- Two memory styles: the language design aims to support safe automatic management and explicit manual control; exact semantics are still to be specified.
- Portable tooling: C++20, CMake, and automated tests.
- Honest compatibility: language features are documented as implemented, planned, or undecided.

## Suggested source layout

- src/ — compiler implementation.
- include/ — public compiler interfaces as the codebase grows.
- tests/ — compiler and language tests.
- examples/ — small C÷ programs.
- docs/ — language and compiler documentation.
