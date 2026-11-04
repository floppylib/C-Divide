# Contributing to C÷

Thanks for taking an interest in C÷. Contributions of code, tests, examples, and documentation are welcome.

## Before you start

1. Read the README and language guide.
2. For a large change, open an issue first so the design can be discussed.
3. Keep pull requests focused. One clear improvement per PR is easier to review.

## Development setup

Requirements: C++20 compiler and CMake 3.20+.

~~~sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure
~~~

On Windows, use cmake --build build --config Debug and ctest --test-dir build -C Debug --output-on-failure.

## Code contributions

- Match the existing C++ style and keep the implementation straightforward.
- Add or update tests for behavior changes.
- Include source positions in diagnostics where practical.
- Do not silently describe planned features as implemented.
- Avoid adding dependencies unless there is a clear technical reason.
- Update documentation when syntax, commands, or behavior changes.

## Language design proposals

C÷ aims for readable syntax, a manageable learning curve, portability, and native compilation. Explain the problem a proposal solves, show a small .cdiv example, and mention trade-offs.

## Pull request checklist

- [ ] The change has a clear scope and description.
- [ ] The project builds successfully.
- [ ] Relevant tests pass.
- [ ] New behavior has tests.
- [ ] Documentation is updated if needed.
- [ ] No unrelated generated files or build output are included.

By contributing, you agree that your contributions to source code are submitted under the MIT License and documentation contributions under CC BY 4.0, unless a contribution is explicitly marked otherwise.
