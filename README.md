<!-- C÷ project home -->
<div align="center">
  <img src="assets/logo-padded.svg" alt="Official C÷ logo" width="144">
  <h1>C÷ · C-Divide</h1>
  <p><img alt="Built with ChatGPT" src="https://img.shields.io/badge/Built%20with-ChatGPT-10A37F?style=for-the-badge&logo=openai&logoColor=white"></p>
    <p align="center">
    <a href="https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip"><img alt="Source ZIP" src="https://img.shields.io/badge/Download-Source%20ZIP-238636?style=for-the-badge&logo=github&logoColor=white"></a>
    <a href="https://cmake.org/download/"><img alt="CMake 3.20+" src="https://img.shields.io/badge/Get-CMake%203.20%2B-064F8C?style=for-the-badge&logo=cmake&logoColor=white"></a>
    <a href="https://visualstudio.microsoft.com/visual-cpp-build-tools/"><img alt="Windows C++ Build Tools" src="https://img.shields.io/badge/Windows-C%2B%2B%20Build%20Tools-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white"></a>
    <a href="https://www.msys2.org/"><img alt="MSYS2 / GCC" src="https://img.shields.io/badge/GCC-MSYS2-4D4D4D?style=for-the-badge"></a>
    <a href="https://releases.llvm.org/"><img alt="LLVM / Clang" src="https://img.shields.io/badge/Clang-LLVM-E36F1E?style=for-the-badge"></a>
  </p>
  <p><em>To build from source you need CMake 3.20+ and a C++20 compiler. Prebuilt C÷ binaries are not available yet.</em></p>
  <p><strong>Simple to learn. Powerful to build.</strong></p>
  <p>A readable programming language with a native-compilation goal.</p>
  <p>
    <a href="https://github.com/floppylib/C-Divide/actions/workflows/ci.yml"><img alt="CI" src="https://img.shields.io/github/actions/workflow/status/floppylib/C-Divide/ci.yml?branch=main&label=build%20%26%20tests"></a>
    <a href="LICENSE"><img alt="MIT License" src="https://img.shields.io/badge/code-MIT-2ea44f.svg"></a>
    <a href="LICENSE-DOCS"><img alt="Documentation CC BY 4.0" src="https://img.shields.io/badge/docs-CC%20BY%204.0-blue.svg"></a>
    <img alt="C++20" src="https://img.shields.io/badge/compiler-C%2B%2B20-00599C.svg">
    <img alt="Current stage" src="https://img.shields.io/badge/status-native%20backend%20preview-2878B5.svg">
  </p>
  <p>
    <a href="README.md">English</a> · <a href="README.fa.md">فارسی</a> · <a href="README.ar.md">العربية</a> ·
    <a href="README.de.md">Deutsch</a> · <a href="README.es.md">Español</a> · <a href="README.fr.md">Français</a> ·
    <a href="README.hi.md">हिन्दी</a> · <a href="README.ja.md">日本語</a> · <a href="README.pt-BR.md">Português (Brasil)</a> ·
    <a href="README.ru.md">Русский</a> · <a href="README.zh-CN.md">简体中文</a>
  </p>
  <p>
    <a href="#quick-start">Quick start</a> · <a href="docs/getting-started.md">Getting started</a> ·
    <a href="docs/language.md">Language guide</a> · <a href="docs/architecture.md">Architecture</a> ·
    <a href="docs/roadmap.md">Roadmap</a>
  </p>
</div>

---

## ✨ What is C÷?

C÷ (pronounced **C-Divide**) is an open programming-language project. Its goal is to make code approachable for new programmers without giving up the structure needed for serious software.

The long-term direction is a **native-compiled language** with automatic and manual memory-management options, a useful standard library, and friendly developer tools.

> **Current status:** C÷ has an initial lexer, parser, syntax checker, and a preview native backend. `cdiv build` and `cdiv run` translate the supported language subset into C++20 and invoke the host C++ compiler to produce a native executable. Type checking, complete module handling, a standard library, and the final memory model are still under development. This is not the finished 1.0 release yet.

## 🚀 A taste of the syntax

~~~cdiv
name = "Hello, C÷!";
print(name);

age = 20;
if age >= 18 {
    print("Welcome!");
} else {
    print("Keep learning!");
}

fn add(a: int, b: int) -> int {
    return a + b;
}
~~~

This illustrates the language style. The current compiler can tokenize and syntax-check supported constructs, then compile a supported subset to native code through its C++20 backend. Full semantic analysis, type checking, and runtime/library facilities are still under development. **C÷ source keywords are currently English**; translated README files do not mean that localized language keywords are implemented.

## 🧭 Project principles

| Principle | Direction |
| --- | --- |
| Readability | Familiar words, clean blocks, predictable syntax |
| Performance | Native executable output is the goal |
| Memory | Automatic and explicit control, with safety rules to be specified |
| Portability | Windows and Linux first; other platforms can follow |
| Tooling | Clear CLI, useful diagnostics, formatter and package tools |
| Accessibility | Source archives and simple installers; no Git knowledge required |

## ⚡ Quick start

### 1. Get the source — no Git required

You do **not** need a GitHub account, Git, or a terminal to download the source archive.

**[⬇ Download the source as a ZIP](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip)**

Unzip it, then open the extracted folder in a terminal. If you prefer Git:

~~~sh
git clone https://github.com/floppylib/C-Divide.git
cd C-Divide
~~~

### 2. Build it

Requirements: a C++20 compiler and CMake 3.20 or newer.

**Linux**

~~~sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure
~~~

**Windows — PowerShell**

~~~powershell
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
~~~

### 3. Try the development tools

The executable is named <code>cdiv</code> (or <code>cdiv.exe</code> on Windows).

~~~sh
cdiv help
cdiv version
cdiv lex examples/hello.cdiv
cdiv check examples/hello.cdiv
cdiv run examples/hello.cdiv
cdiv build examples/hello.cdiv
~~~

- <code>lex</code> displays tokens and their source positions.
- <code>check</code> checks lexical and grammatical structure.

`run` compiles the source to a temporary native executable and launches it. `build` writes a native executable to `build/` (or to a path supplied with `-o`). Both commands require a working C++20 compiler; set `CXX` to select it.

## 📦 Downloads

- **Source code:** use the ZIP link above. No account is required.
- **Prebuilt compiler tools:** packages will be published on the [Releases page](https://github.com/floppylib/C-Divide/releases) after a version tag is created and the release build succeeds.
- **Install scripts:** <code>scripts/install.sh</code> and <code>scripts/install.ps1</code> are provided for installing a built executable into the user's account.

**Prebuilt packages are not published yet.** The release workflow is prepared, but downloads will only appear after a tagged release is built successfully.

## 🧩 What's implemented?

| Component | Status |
| --- | --- |
| C++20 / CMake project | ✅ |
| Lexer and source-position diagnostics | ✅ Initial version |
| Parser and syntax checker | ✅ Initial version |
| Variables, calls, functions, conditions and loops | ✅ Parsed; supported subset compiles |
| Native C++20 code-generation backend | ✅ Initial preview |
| `cdiv build` and `cdiv run` | ✅ Initial preview |
| Automated build and test workflow | ✅ Configured |
| Full semantic and static type analysis | 🛠 Planned |
| Complete runtime and standard library | 🛠 Planned |
| Semantic and type analysis | 🛠 Planned |
| Standard library and module system | 🛠 Planned |
| Memory-management model | 🧭 Design work |
| Package manager, formatter and debugger | 🛠 Planned |

See the [roadmap](docs/roadmap.md) for planned milestones.

## 📚 Documentation

| Guide | What you'll find |
| --- | --- |
| [Getting started](docs/getting-started.md) | Build C÷ on Windows or Linux |
| [Language guide](docs/language.md) | Syntax recognized by the current front end |
| [Architecture](docs/architecture.md) | Compiler structure and components |
| [Native backend](docs/native-backend.md) | How native builds work and current limits |
| [Changelog](CHANGELOG.md) | Version history and implementation boundaries |
| [Roadmap](docs/roadmap.md) | Planned milestones |
| [FAQ](docs/faq.md) | Common questions |
| [Downloads](docs/downloads.md) | Source archives and release packages |

The native backend preview and its current boundaries are described in [Native backend](docs/native-backend.md). The README is available in the languages listed above. The technical guides remain English-first for now. See [TRANSLATIONS.md](TRANSLATIONS.md) to help localize the project.

## 🤝 Community

Suggestions, bug reports, documentation improvements, and code contributions are welcome.

- Read [CONTRIBUTING.md](CONTRIBUTING.md) before opening a pull request.
- Use the issue templates for bug reports and feature ideas.
- Review the [Code of Conduct](CODE_OF_CONDUCT.md) and [Security Policy](SECURITY.md).

A clear bug report or a better example is a valuable contribution.

## 📜 Licensing

- **Source code:** [MIT License](LICENSE).
- **Documentation:** [Creative Commons Attribution 4.0](LICENSE-DOCS).

Third-party components, if introduced later, will be listed in [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

---

<div align="center">
  <sub>Built in the open. Designed to be learned. Made to grow.</sub>
</div>
