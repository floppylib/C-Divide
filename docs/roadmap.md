# Roadmap

The target is a complete C÷ 1.0 release. Work may happen in parallel, but features will only be marked complete when they are implemented and tested.

## Foundation — current work

- [x] C++20 / CMake project
- [x] Initial lexer and source diagnostics
- [x] Initial syntax parser and checker
- [x] Basic .cdiv examples and tests
- [x] CI build and test workflow
- [x] Initial contributor and documentation structure

## Language core

- [ ] Finalize the 1.0 language specification
- [ ] Build an AST with source spans
- [ ] Add name resolution and useful semantic diagnostics
- [ ] Define primitive types, inference rules, and conversions
- [ ] Add collections, strings, and standard control-flow constructs
- [ ] Define error handling and module/import semantics

## Compiler and runtime

- [ ] Design a stable intermediate representation
- [ ] Integrate an LLVM backend
- [ ] Generate native executables for supported targets
- [ ] Implement runtime support and standard library
- [ ] Specify automatic and manual memory-management rules
- [ ] Add debugging information and useful compiler diagnostics

## Developer experience

- [ ] Stable cdiv run, build, and check commands
- [ ] Formatter and language-server support
- [ ] Package manager and dependency resolution
- [ ] Beginner-friendly tutorials and examples
- [ ] Signed release packages and checksums

## Distribution

- [x] Source archive download without Git
- [x] Release packaging workflow prepared for Windows x64 and Linux x64
- [ ] Publish the first tested binary release
- [ ] Add independent download mirrors when maintainers can support them

This roadmap is directional. A checkbox means the item has been delivered, not merely designed.
