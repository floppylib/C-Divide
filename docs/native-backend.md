# Native backend preview

C÷ 0.2.0 introduces the first executable native-code path.

## What happens

1. The lexer and parser validate the source file.
2. The native backend translates the supported C÷ subset into temporary C++20 source.
3. The configured host C++ compiler compiles and links that source into a native executable.
4. `cdiv run` launches a temporary executable and removes it after the process exits. `cdiv build` keeps the executable at the requested output path.

The backend uses the C++ compiler selected when C÷ itself was configured. Set the `CXX` environment variable to override it.

## Commands

```sh
cdiv check examples/hello.cdiv
cdiv run examples/hello.cdiv
cdiv build examples/hello.cdiv
cdiv build examples/hello.cdiv -o hello-program
```

The default build output is `build/hello` on Unix-like systems and `build/hello.exe` on Windows.

## Supported preview constructs

- Inferred assignments and typed variables: `int`, `float`, `double`, `bool`, `string`, and `str`.
- String, numeric, and boolean literals.
- Arithmetic, comparison, logical, and unary operators accepted by the parser.
- `print(...);`, `if / else if / else`, `repeat`, and `while`.
- Top-level functions with typed parameters and optional return types.
- `import math;`, which exposes the host C++ standard math functions.

## Current limitations

This is an early backend, not the finished C÷ 1.0 compiler. It does not yet provide complete static type checking, a stable C÷ intermediate representation, a standalone runtime, a complete standard library, user-defined module resolution, package management, or a finalized memory model. A C++ compiler diagnostic may refer to generated C++ rather than the original C÷ source. Function declarations must be at top level, and forward references between function bodies are not yet guaranteed.

The backend deliberately relies on an installed C++20 compiler instead of bundling LLVM. This keeps the initial toolchain small while the C÷ language specification and semantic analysis mature.
