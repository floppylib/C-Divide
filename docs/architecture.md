# Compiler architecture

C÷ is intended to become a native compiled language. The current implementation is a small, dependency-free C++20 front end.

## Current pipeline

~~~text
.cdiv source
    |
    v
Lexer  ---> tokens + source diagnostics
    |
    v
Parser ---> syntax diagnostics
~~~

The lexer recognizes identifiers, keywords, literals, operators, punctuation, comments, and source positions. The parser validates declarations, statements, blocks, function signatures, calls, and operator precedence. It does not yet build a persistent AST or perform semantic analysis.

## Planned pipeline

~~~text
.cdiv source
    -> Lexer
    -> Parser / AST
    -> Name and type analysis
    -> C÷ intermediate representation (IR)
    -> LLVM native-code backend
    -> platform linker
    -> native executable
~~~

LLVM is a planned backend, not a current dependency. Keeping early front-end work independent of LLVM keeps the first build small and approachable.

## Design principles

- Readable syntax: familiar English keywords and punctuation.
- Native output: the long-term compiler produces platform executables.
- Two memory styles: the language aims to support safe automatic management and explicit manual control; exact semantics remain to be specified.
- Portable tooling: C++20, CMake, and automated tests.
- Honest compatibility: distinguish implemented features from planned features.

## Repository layout

- src/ — compiler implementation.
- tests/ — compiler and language tests.
- examples/ — small C÷ programs.
- docs/ — language and compiler documentation.
- scripts/ — local installation helpers.
- .github/workflows/ — continuous integration and release packaging.
