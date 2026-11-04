# C÷ (C-Divide)

**Simple to learn. Powerful to build.**

C÷ is a language project focused on approachable syntax and the long-term goal of compiling to native executables.

> The repository currently contains the first compiler front end, not the complete 1.0 language or native-code compiler.

## A first look

```cdiv
name = "Hello, C÷!";
print(name);
```

## Build

Requirements: a C++20 compiler and CMake 3.20 or newer.

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

## Use the front end

```sh
cdiv help
cdiv version
cdiv lex examples/hello.cdiv
cdiv check examples/hello.cdiv
```

- lex prints tokens with source positions.
- check reports lexical and syntax errors.

These commands do not run programs or produce native machine code yet.

## Implementation status

| Component | Status |
|---|---|
| C++20 / CMake project | Implemented |
| Lexer and source diagnostics | Initial implementation |
| Parser and syntax checker | Initial implementation |
| Function / condition / loop syntax | Parsed; not executed |
| Semantic and type analysis | Planned |
| AST and intermediate representation | Planned |
| LLVM native-code backend | Planned |
| Standard library and module resolution | Planned |
| Memory-management model | Design work |
| Package manager, formatter and debugger | Planned |

The goal is a complete C÷ 1.0 release. This repository is its foundation, not a beta product declaration.

## Documentation

- [Language guide](docs/language.md)
- [Compiler architecture](docs/architecture.md)

## Contributing

Issues and pull requests are welcome. Include a small .cdiv test case when reporting bugs.

## License

No license has been selected or added yet. Public visibility should not be mistaken for permission to reuse, modify, or redistribute the code.
