<div align="center">
  <img src="assets/logo-padded.svg" alt="C÷ 官方标志" width="144">
  <h1>C÷ · C-Divide</h1>
  <p><img alt="Built with ChatGPT" src="https://img.shields.io/badge/Built%20with-ChatGPT-10A37F?style=for-the-badge&logo=openai&logoColor=white"></p>
    <p align="center">
    <a href="https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip"><img alt="ZIP 源代码" src="https://img.shields.io/badge/Download-Source%20ZIP-238636?style=for-the-badge&logo=github&logoColor=white"></a>
    <a href="https://cmake.org/download/"><img alt="CMake 3.20+" src="https://img.shields.io/badge/Get-CMake%203.20%2B-064F8C?style=for-the-badge&logo=cmake&logoColor=white"></a>
    <a href="https://visualstudio.microsoft.com/visual-cpp-build-tools/"><img alt="Windows C++ 构建工具" src="https://img.shields.io/badge/Windows-C%2B%2B%20Build%20Tools-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white"></a>
    <a href="https://www.msys2.org/"><img alt="MSYS2 / GCC" src="https://img.shields.io/badge/GCC-MSYS2-4D4D4D?style=for-the-badge"></a>
    <a href="https://releases.llvm.org/"><img alt="LLVM / Clang" src="https://img.shields.io/badge/Clang-LLVM-E36F1E?style=for-the-badge"></a>
  </p>
  <p><em>从源码构建需要 CMake 3.20+ 和 C++20 编译器。C÷ 的预编译二进制文件目前尚未发布。</em></p>
  <p><strong>易于学习，强大而实用。</strong></p>
  <p>一门注重可读性、以原生编译为长期目标的编程语言。</p>
</div>

<p><a href="README.md">English</a> · <a href="README.fa.md">فارسی</a> · <a href="README.ar.md">العربية</a> · <a href="README.de.md">Deutsch</a> · <a href="README.es.md">Español</a> · <a href="README.fr.md">Français</a> · <a href="README.hi.md">हिन्दी</a> · <a href="README.ja.md">日本語</a> · <a href="README.pt-BR.md">Português (Brasil)</a> · <a href="README.ru.md">Русский</a> · <a href="README.zh-CN.md">简体中文</a></p>

---

## C÷ 是什么？

C÷（读作 **C-Divide**）是一个开源编程语言项目。它希望让初学者更容易上手，同时保留构建严肃软件所需的结构和能力。

长期目标是打造一门**可编译为原生可执行代码的语言**，提供自动和显式内存管理选项、标准库以及完善的开发工具。

> **当前状态：** C÷ 已具备初步的词法分析器、语法分析器和语法检查器，并加入了实验性的原生后端。`cdiv build` 和 `cdiv run` 会把受支持的语言子集转换为 C++20，并调用系统 C++ 编译器生成原生可执行文件。完整语义分析、类型检查、模块、标准库和最终内存模型仍在开发中；这还不是最终的 1.0 版本。

## 语法示例

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

这段代码展示了计划中的语言风格。当前前端可以对已支持的结构进行词法分析和语法检查；程序执行、语义分析和类型检查仍在开发中。**C÷ 语言本身的关键字目前使用英语**；README 的翻译不代表已经支持本地化关键字。

## 快速开始

下载源代码不需要 GitHub 账号，也不需要安装 Git。

**[下载 ZIP 源代码](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip)**

构建要求：C++20 编译器，以及 CMake 3.20 或更高版本。

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

尝试当前的开发工具：

~~~sh
cdiv help
cdiv version
cdiv lex examples/hello.cdiv
cdiv check examples/hello.cdiv
~~~

<code>lex</code> 显示词法单元，<code>check</code> 检查语法，<code>build</code> 生成原生可执行文件，<code>run</code> 则编译并运行程序。后两个命令需要 C++20 编译器。

## 开发状态

| 组件 | 状态 |
| --- | --- |
| C++20 / CMake 项目 | ✅ |
| 词法分析器和位置诊断 | ✅ 初始版本 |
| 语法分析器和语法检查 | ✅ 初始版本 |
| 变量、函数、条件和循环 | ✅ 支持的子集可以编译 |
| 通过 C++20 生成原生代码 | ✅ 初始预览版 |
| `cdiv build` 与 `cdiv run` | ✅ 初始预览版 |
| 语义分析和类型检查 | 🛠 计划中 |
| 标准库、模块系统和包管理器 | 🛠 计划中 |
| 格式化工具和调试器 | 🛠 计划中 |

更多信息请查看[路线图](docs/roadmap.md)和[技术文档](docs/getting-started.md)。

## 下载与社区

- **源代码：** [ZIP 压缩包](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip)，无需账号。
- **正式发布：** 创建版本标签且发布构建成功后，预编译包会出现在 [Releases 页面](https://github.com/floppylib/C-Divide/releases)。目前尚未发布预编译包。
- **参与贡献：** 请先阅读 [CONTRIBUTING.md](CONTRIBUTING.md) 和[安全政策](SECURITY.md)。

## 文档与许可证

目前技术指南主要以英文编写，欢迎社区帮助翻译。源代码采用 [MIT 许可证](LICENSE)，文档采用 [CC BY 4.0](LICENSE-DOCS)。

---

<div align="center"><sub>开放协作开发，为学习而设计，为成长而构建。</sub></div>
