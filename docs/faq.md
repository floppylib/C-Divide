# Frequently asked questions

## Is C÷ ready to write applications?

Not as a production-ready 1.0 language. The current preview can compile and run a supported subset through a host C++20 compiler. Full type checking, a complete standard library, robust modules, memory management, and stable native backends are still under development.

## Do I need Git or a GitHub account?

No. You can download the source as a ZIP archive without an account. Once prebuilt releases are published, public release downloads will also be available without signing in.

## Which platforms are supported?

The source is designed to build with C++20 and CMake. The prepared release workflow targets Windows x64 and Linux x64. Platform compatibility will be documented as it is tested.

## Why use C++ for the compiler?

C++20 gives the compiler implementation a portable, native toolchain and access to mature compiler infrastructure. LLVM is a planned backend, not a current dependency.

## What does C÷ stand for?

C÷ is read as “C-Divide”. The name is intended to be short and recognizable; it does not mean that the language is a C derivative.

## Can I contribute?

Yes. Start with CONTRIBUTING.md, and use the issue templates for bug reports or feature proposals.
