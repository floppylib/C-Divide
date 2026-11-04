# Roadmap

The target is a complete C÷ 1.0 release. Work may happen in parallel, but features will only be marked complete when they are implemented and tested.

## Foundation — current work

- [x] C++20 / CMake project
- [x] Initial lexer and source diagnostics
- [x] Initial syntax parser and checker
- [x] Basic .cdiv examples and tests
- [x] CI build and test workflow
- [x] Initial contributor and documentation structure
- [x] First native C++20 source-emission backend (preview)
- [x] Initial `cdiv build` and `cdiv run` commands
- [x] Native execution smoke test in CI
- [x] Multi-line block comments with an unterminated-comment diagnostic
- [x] Initial compiler environment report via cdiv doctor
- [x] Release workflow for Windows/Linux archives and a GHCR container image

## Language design

The long-term direction, including the Standard and System profiles, proposed ownership model, and native compilation architecture, is described in [Language design](language-design.md). These are design targets; only items marked as implemented below are available in the compiler.

## Milestones toward 1.0

These are development targets, not promises that a release is already complete.

1. **0.3 — Front-end architecture:** persistent AST, source spans, parser recovery, and separate compiler stages.
2. **0.4 — Semantic core:** scopes, name resolution, static types, conversions, function checking, and clear C÷-level diagnostics.
3. **0.5 — Language essentials:** finalized expressions and control flow, strings and collections, and a defined module/import system.
4. **0.6 — Runtime and memory:** standard-library foundation, error behavior, and a documented, testable memory model.
5. **0.7 — Stable native compiler:** replace the temporary C++ source emitter with a backend whose behavior is defined by the C÷ specification.
6. **0.8 — Developer tools:** formatter, useful debug information, language-server foundation, and package/dependency design.
7. **0.9 — Release candidate:** cross-platform compatibility testing, regression tests, reproducible builds, installers, and published binaries.
8. **1.0 — Language release:** freeze the specification, publish complete documentation, pass the supported-platform test matrix, and publish signed release artifacts.

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
- [x] Generate native executables for the currently supported subset through the host C++20 toolchain
- [ ] Replace the preview emitter with a stable, fully specified backend
- [ ] Implement runtime support and standard library
- [ ] Specify automatic and manual memory-management rules
- [ ] Add debugging information and useful compiler diagnostics

## Developer experience

- [x] Initial toolchain diagnostics through cdiv doctor

- [x] Initial cdiv run, build, and check commands
- [ ] Stabilize CLI behavior, diagnostics, and cross-platform compiler discovery
- [ ] Formatter and language-server support
- [ ] Package manager and dependency resolution
- [ ] Beginner-friendly tutorials and examples
- [ ] Signed release packages and checksums

## Distribution

- [x] GitHub Release workflow with checksums and Linux/Windows archives
- [x] GHCR container-image publishing workflow (first publication still requires a maintainer-run release)

- [x] Source archive download without Git
- [x] Release packaging workflow prepared for Windows x64 and Linux x64
- [ ] Publish the first tested binary release
- [ ] Add independent download mirrors when maintainers can support them

This roadmap is directional. A checkbox means the item has been delivered, not merely designed.
