# Getting started

This guide gets the current C÷ command-line front end building on a standard development machine.

## What you need

- CMake 3.20 or newer.
- A C++20 compiler:
  - Linux: GCC 11+ or Clang 14+ recommended.
  - Windows: Visual Studio 2022 C++ build tools or a recent MinGW-w64 toolchain.
- A terminal (PowerShell on Windows, Terminal on Linux).

You do not need Git. Download the source ZIP from the repository page and extract it.

## Linux

Install CMake and a compiler using your distribution's package manager. For Debian or Ubuntu:

~~~sh
sudo apt update
sudo apt install build-essential cmake
~~~

From the extracted project directory:

~~~sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure
~~~

The executable will be at build/cdiv.

To install it for your current user:

~~~sh
./scripts/install.sh build/cdiv
~~~

The installer copies the executable to ~/.local/bin. Make sure that directory is in your PATH.

## Windows

Install Visual Studio Build Tools with the **Desktop development with C++** workload and install CMake.

Open PowerShell in the extracted project directory:

~~~powershell
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
~~~

The executable is normally build/Release/cdiv.exe.

Install it for your user:

~~~powershell
.\scripts\install.ps1 -BinaryPath .\build\Release\cdiv.exe
~~~

Open a new terminal after installation so the updated user PATH is picked up.

## Try a source file

~~~sh
cdiv version
cdiv lex examples/hello.cdiv
cdiv check examples/hello.cdiv
~~~

At this stage, lex prints tokens and check validates syntax. Running C÷ programs and native-code generation are not implemented yet.

## Troubleshooting

- **CMake cannot find a compiler:** verify that your C++ compiler is installed and available in the terminal.
- **The C++ standard is too old:** use a C++20-capable compiler.
- **Windows cannot find cdiv after installation:** open a new PowerShell window and confirm that %LOCALAPPDATA%\Programs\C-Divide\bin is in your user PATH.
- **A test fails:** open an issue and include the command, operating system, compiler version, and complete error output.
