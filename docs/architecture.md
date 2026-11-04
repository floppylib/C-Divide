# Compiler architecture

C÷ is intended to become a native compiled language. The current compiler is implemented in C++20 and includes a preview native backend. That backend translates the supported subset of C÷ into C++20 and invokes the host C++ compiler and linker.

## Current pipeline

~~~text
.cdiv source
    |
    v
Lexer  ---> tokens + source diagnostics
    |
    v
Parser ---> syntax validation
    |
    v
C++20 source emitter (supported subset)
    |
    v
Host C++20 compiler + linker
    |
    v
Native executable
~~~

The lexer recognizes identifiers, keywords, literals, operators, punctuation, comments, and source positions. The parser validates declarations, statements, blocks, function signatures, calls, and operator precedence. The preview backend emits C++20 for variables, supported expressions, output, conditionals, loops, and functions. It does not yet build a persistent AST or perform complete semantic/type analysis.

## Planned pipeline

~~~text
.cdiv source
    -> Lexer
    -> Parser / AST
    -> Name and type analysis
    -> C÷ intermediate representation (IR)
    -> Optimizations
    -> Stable native-code backend (LLVM or another tested target)
    -> platform linker
    -> native executable
~~~

LLVM is not currently a dependency. The preview backend delegates final machine-code generation and linking to the user's installed C++20 compiler. A future stable backend may use LLVM or another backend after the language semantics and IR are defined.

## Design principles

- Readable syntax: familiar English keywords and punctuation.
- Native output: the current preview can produce executables for the supported subset; the long-term compiler will have a stable, directly managed backend.
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
