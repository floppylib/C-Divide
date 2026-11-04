# Changelog

Notable changes to C÷ are recorded here.

The project is under active development. Version numbers describe repository milestones; they do not imply that the language is feature-complete.

## Unreleased

- Improve onboarding, licensing, contributor guidance, and project documentation.
- Prepare cross-platform CI and release packaging.

## 0.2.0 — native backend preview

This is a development milestone, not the final C÷ 1.0 release.

### Added
- First C++20 source-emission backend for the currently supported C÷ subset.
- `cdiv build <file.cdiv> [-o output]` to generate a native executable through the host C++20 compiler.
- `cdiv run <file.cdiv>` to compile and run a C÷ source file.
- Initial native build and run output tests in the cross-platform CMake/CTest workflow.
- Documentation describing the preview backend and its current boundaries.
- A visible **Built with ChatGPT** credit badge in all 11 README translations.

### Supported in this preview
- Variables and basic type annotations.
- Numeric, boolean, and string literals.
- Arithmetic, comparison, and logical expressions.
- Output with `print`.
- `if / else`, `repeat`, and `while`.
- Top-level functions with typed parameters and return values.
- The initial `import math;` bridge to host C++ standard math functions.

### Important limitations
- The backend translates supported C÷ source into temporary C++20 source and invokes the host C++ compiler. It is not yet an independent C÷ machine-code backend.
- A persistent AST, complete semantic analysis, and static type checking are not implemented.
- General module resolution, a complete standard library, package management, and the final memory model are not implemented.
- The language specification is not frozen; unsupported constructs and some edge cases may be rejected or produce host compiler diagnostics.
- No official prebuilt C÷ compiler binaries are published yet.

## 0.1.0 — front-end foundation

- Add a C++20 and CMake project.
- Implement the initial lexer and source diagnostics.
- Implement an initial parser and syntax checker.
- Add basic examples and smoke tests.
