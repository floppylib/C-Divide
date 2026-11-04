# C÷ language design

**Status: design proposal for the 0.x series.** This document defines the direction of the language; it is not a claim that these features are already implemented by the 0.2.1 preview compiler. The implementation status remains tracked in the [roadmap](roadmap.md).

## Vision

C÷ aims to combine an approachable, expressive programming experience with the control required for systems programming. It should be suitable for scripts, command-line tools, desktop software, services, games, embedded software, and operating systems.

The guiding principle is:

> **One language. Every layer.**

C÷ is not intended to be a Python clone or a Rust syntax clone. It will have its own coherent syntax, type system, runtime model, and tools.

## One language, two programming profiles

These are compilation profiles of the same language, not separate dialects.

### Standard profile

The default profile is for everyday application development:

- Static types with useful type inference.
- Readable declarations and predictable control flow.
- A complete standard library for text, files, collections, networking, processes, and concurrency.
- Safe defaults for memory and data access.
- Straightforward testing, formatting, package management, and debugging tools.

### System profile

The system profile is for kernels, drivers, embedded targets, and other freestanding programs:

- No mandatory hosted runtime or operating-system services.
- Explicit control over allocation, memory layout, and ABI boundaries.
- Interoperability with C and carefully scoped assembly.
- Explicitly marked unsafe operations for hardware access and low-level primitives.
- Target-specific linker scripts, startup code, and platform support supplied by the toolchain.

The system profile must not silently weaken the safety rules of the standard profile. Low-level operations should be visible at the call site and documented.

## Type-system direction

The planned type system is static and inference-friendly. The compiler should infer obvious local types while allowing explicit annotations at public API and hardware boundaries.

The design should include:

- Integer and floating-point types with specified widths and overflow behavior.
- Boolean, character, string, tuple, array, and growable collection types.
- Enums and algebraic data types.
- Generics and traits/interfaces for reusable abstractions.
- Nullable/optional values and result-based error handling.
- Explicit conversions rather than surprising implicit coercions.

The exact names, inference rules, and conversion rules will be frozen only after tests and a language specification exist.

## Memory and safety model

The proposed default is deterministic ownership and borrowing:

- Each owned heap value has a clear owner.
- Moving a value transfers ownership.
- Shared borrows are read-only; mutable borrows are exclusive.
- Lifetimes and aliasing rules are checked by the compiler.
- Safe code cannot perform arbitrary pointer arithmetic or access invalid memory.
- Explicit allocation APIs are available where predictable system-level control is required.
- Raw pointers, inline assembly, memory-mapped I/O, and other inherently unsafe operations require an explicit unsafe boundary.

This is a design target, not an implemented memory manager. The compiler must not advertise memory safety until the rules are implemented and extensively tested.

## Native compilation and portability

The intended compiler pipeline is:

~~~text
C÷ source
   -> lexer
   -> parser and AST
   -> name resolution and type checking
   -> typed intermediate representation
   -> optimization
   -> code generation
   -> platform linker
   -> executable or library
~~~

The backend must be replaceable. C÷ should not be permanently tied to generated C++ source.

Planned target families:

| Target family | Intended output |
| --- | --- |
| Windows | PE executable and libraries |
| Linux | ELF executable and libraries |
| macOS | Mach-O executable and libraries |
| Web | WebAssembly modules |
| Embedded / OS development | Freestanding target images and object files |

A target is supported only when its code generator, ABI, system libraries or SDK, linker, and tests are available. A target option by itself does not make cross-compilation work.

## Toolchain experience

The long-term CLI should provide coherent commands for:

- cdiv new — create a project.
- cdiv check — validate syntax and semantics.
- cdiv build — compile for a selected target and profile.
- cdiv run — build and run a hosted program.
- cdiv test — run project tests.
- cdiv fmt — format source files.
- cdiv doctor — explain missing tools and environment problems.
- cdiv pkg — manage dependencies after the package format and registry are specified.

The eventual project manifest should record compiler requirements, dependencies, features, build profiles, and target settings in a reproducible format.

## Example direction

The following snippets are illustrative proposals. They are **not accepted by the 0.2.0 compiler**.

~~~cdiv
// Standard profile: approachable application code.
fn greet(name: String) -> String {
    return "Hello, " + name;
}

fn main() -> Int {
    let message = greet("C÷");
    print(message);
    return 0;
}
~~~

~~~cdiv
// System profile: freestanding entry points and explicit unsafe boundaries.
// Exact syntax is still to be designed.
@freestanding
fn kernel_entry() -> Never {
    unsafe {
        // Platform-specific hardware interaction.
    }
}
~~~

## Implementation order

1. Build a persistent AST with source spans and reliable parser recovery.
2. Add scopes, name resolution, static types, and C÷-level diagnostics.
3. Specify the core type system, error model, and module rules.
4. Specify ownership, borrowing, lifetimes, and unsafe boundaries.
5. Add the standard library and a freestanding core.
6. Introduce a typed intermediate representation and a stable native backend.
7. Add tested target support, project tooling, package management, and editor integration.

Each capability becomes part of the language only after implementation, tests, and documentation agree.
