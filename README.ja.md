<div align="center">
  <img src="assets/logo-padded.svg" alt="C÷ 公式ロゴ" width="144">
  <h1>C÷ · C-Divide</h1>
  <p><img alt="Built with ChatGPT" src="https://img.shields.io/badge/Built%20with-ChatGPT-10A37F?style=for-the-badge&logo=openai&logoColor=white"></p>
    <p align="center">
    <a href="https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip"><img alt="ソースコード ZIP" src="https://img.shields.io/badge/Download-Source%20ZIP-238636?style=for-the-badge&logo=github&logoColor=white"></a>
    <a href="https://cmake.org/download/"><img alt="CMake 3.20+" src="https://img.shields.io/badge/Get-CMake%203.20%2B-064F8C?style=for-the-badge&logo=cmake&logoColor=white"></a>
    <a href="https://visualstudio.microsoft.com/visual-cpp-build-tools/"><img alt="Windows C++ ビルドツール" src="https://img.shields.io/badge/Windows-C%2B%2B%20Build%20Tools-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white"></a>
    <a href="https://www.msys2.org/"><img alt="MSYS2 / GCC" src="https://img.shields.io/badge/GCC-MSYS2-4D4D4D?style=for-the-badge"></a>
    <a href="https://releases.llvm.org/"><img alt="LLVM / Clang" src="https://img.shields.io/badge/Clang-LLVM-E36F1E?style=for-the-badge"></a>
  </p>
  <p><em>ソースのビルドには CMake 3.20 以降と C++20 コンパイラが必要です。C÷ のビルド済みバイナリはまだ公開されていません。</em></p>
  <p><strong>学びやすく、開発に強い。</strong></p>
  <p>読みやすさを重視し、ネイティブコンパイルを目指すプログラミング言語です。</p>
</div>

<p><a href="README.md">English</a> · <a href="README.fa.md">فارسی</a> · <a href="README.ar.md">العربية</a> · <a href="README.de.md">Deutsch</a> · <a href="README.es.md">Español</a> · <a href="README.fr.md">Français</a> · <a href="README.hi.md">हिन्दी</a> · <a href="README.ja.md">日本語</a> · <a href="README.pt-BR.md">Português (Brasil)</a> · <a href="README.ru.md">Русский</a> · <a href="README.zh-CN.md">简体中文</a></p>

---

## C÷ とは？

C÷（読み方：**C-Divide**）は、オープンソースのプログラミング言語プロジェクトです。初めてプログラミングを学ぶ人にも分かりやすく、将来的には本格的なソフトウェア開発に必要な構造も備えることを目指しています。

長期的な目標は、メモリの自動管理と明示的な管理の両方を選べる、**ネイティブ実行ファイルへコンパイルできる言語**です。標準ライブラリと開発者向けツールも提供する予定です。

> **現在の正確な状態：** このリポジトリには、初期段階の字句解析器、構文解析器、構文チェック機能があります。C÷のプログラム実行やネイティブ実行ファイルの生成には、まだ対応していません。完全な1.0リリースを目指して開発中です。

## 構文の例

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

これは目指している言語スタイルの例です。現在のフロントエンドは対応済みの構文をトークン化し、文法を検査できます。プログラムの実行、意味解析、型検査は開発中です。**C÷言語本体のキーワードは現在英語です**。README の翻訳は、各言語のキーワードに対応しているという意味ではありません。

## クイックスタート

ソースコードのダウンロードにGitHubアカウントやGitのインストールは必要ありません。

**[ソースコードをZIPでダウンロード](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip)**

ビルド要件：C++20対応コンパイラとCMake 3.20以降。

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

現在の開発ツールを試すには：

~~~sh
cdiv help
cdiv version
cdiv lex examples/hello.cdiv
cdiv check examples/hello.cdiv
~~~

<code>lex</code> はトークンとソース内の位置を表示します。<code>check</code> は字句構造と文法構造を検査します。これらのコマンドは、まだプログラムを実行したりネイティブ実行ファイルを生成したりしません。

## 開発状況

| コンポーネント | 状況 |
| --- | --- |
| C++20 / CMake プロジェクト | ✅ |
| 字句解析と位置情報付き診断 | ✅ 初期版 |
| 構文解析と構文チェック | ✅ 初期版 |
| 変数・関数・条件分岐・ループの文法 | ✅ 解析可能、実行は不可 |
| ネイティブコード生成 | 🛠 予定 |
| ランタイムとプログラム実行 | 🛠 予定 |
| 意味解析と型検査 | 🛠 予定 |
| 標準ライブラリ、モジュール、パッケージ管理 | 🛠 予定 |
| フォーマッターとデバッガー | 🛠 予定 |

詳しくは[ロードマップ](docs/roadmap.md)と[技術ドキュメント](docs/getting-started.md)をご覧ください。

## ダウンロードとコミュニティ

- **ソースコード：** [ZIPアーカイブ](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip)。アカウントは不要です。
- **リリース：** バージョンタグを作成し、リリースビルドが成功した後、[Releasesページ](https://github.com/floppylib/C-Divide/releases)にビルド済みパッケージを公開します。現時点では公開済みパッケージはありません。
- **参加方法：** [CONTRIBUTING.md](CONTRIBUTING.md)と[セキュリティポリシー](SECURITY.md)をご確認ください。

## ドキュメントとライセンス

技術ガイドは現在、主に英語で提供されています。翻訳への協力を歓迎します。ソースコードは[MITライセンス](LICENSE)、ドキュメントは[CC BY 4.0](LICENSE-DOCS)です。

---

<div align="center"><sub>オープンに開発し、学びやすく設計し、成長できる言語へ。</sub></div>
