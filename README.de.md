<div align="center">
  <img src="assets/logo-padded.svg" alt="Offizielles C÷-Logo" width="144">
  <h1>C÷ · C-Divide</h1>
  <p><img alt="Built with ChatGPT" src="https://img.shields.io/badge/Built%20with-ChatGPT-10A37F?style=for-the-badge&logo=openai&logoColor=white"></p>
    <p align="center">
    <a href="https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip"><img alt="Quellcode als ZIP" src="https://img.shields.io/badge/Download-Source%20ZIP-238636?style=for-the-badge&logo=github&logoColor=white"></a>
    <a href="https://cmake.org/download/"><img alt="CMake 3.20+" src="https://img.shields.io/badge/Get-CMake%203.20%2B-064F8C?style=for-the-badge&logo=cmake&logoColor=white"></a>
    <a href="https://visualstudio.microsoft.com/visual-cpp-build-tools/"><img alt="C++-Buildtools für Windows" src="https://img.shields.io/badge/Windows-C%2B%2B%20Build%20Tools-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white"></a>
    <a href="https://www.msys2.org/"><img alt="MSYS2 / GCC" src="https://img.shields.io/badge/GCC-MSYS2-4D4D4D?style=for-the-badge"></a>
    <a href="https://releases.llvm.org/"><img alt="LLVM / Clang" src="https://img.shields.io/badge/Clang-LLVM-E36F1E?style=for-the-badge"></a>
  </p>
  <p><em>Zum Bauen benötigen Sie CMake 3.20+ und einen C++20-Compiler. Vorgefertigte C÷-Binärdateien sind noch nicht verfügbar.</em></p>
  <p><strong>Einfach zu lernen. Leistungsfähig beim Entwickeln.</strong></p>
  <p>Eine gut lesbare Programmiersprache mit dem Ziel nativer Kompilierung.</p>
</div>

<p><a href="README.md">English</a> · <a href="README.fa.md">فارسی</a> · <a href="README.ar.md">العربية</a> · <a href="README.de.md">Deutsch</a> · <a href="README.es.md">Español</a> · <a href="README.fr.md">Français</a> · <a href="README.hi.md">हिन्दी</a> · <a href="README.ja.md">日本語</a> · <a href="README.pt-BR.md">Português (Brasil)</a> · <a href="README.ru.md">Русский</a> · <a href="README.zh-CN.md">简体中文</a></p>

---

## Was ist C÷?

C÷ (ausgesprochen **C-Divide**) ist ein Open-Source-Projekt für eine Programmiersprache. Die Sprache soll für Einsteiger leicht zugänglich sein und zugleich die Struktur bieten, die für anspruchsvolle Software nötig ist.

Langfristig soll C÷ eine **nativ kompilierte Sprache** mit automatischer und expliziter Speicherverwaltung, einer Standardbibliothek und eigenen Entwicklerwerkzeugen werden.

> **Aktueller Stand:** C÷ enthält einen ersten Lexer, Parser und Syntaxprüfer sowie ein experimentelles natives Backend. `cdiv build` und `cdiv run` übersetzen den unterstützten Sprachumfang nach C++20 und nutzen den installierten C++-Compiler, um native Programme zu erzeugen. Vollständige semantische Analyse, Typprüfung, Module, Standardbibliothek und das endgültige Speichermodell sind noch in Arbeit. Dies ist noch nicht die fertige Version 1.0.

## Ein Blick auf die Syntax

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

Das Beispiel zeigt den geplanten Sprachstil. Das aktuelle Frontend kann unterstützte Konstrukte tokenisieren und syntaktisch prüfen. Programmausführung, semantische Analyse und Typprüfung befinden sich noch in Entwicklung. **Die Schlüsselwörter der Sprache C÷ sind derzeit Englisch**; übersetzte README-Dateien bedeuten nicht, dass lokalisierte Schlüsselwörter bereits unterstützt werden.

## Schnellstart

Zum Herunterladen des Quellcodes sind weder ein GitHub-Konto noch Git erforderlich.

**[Quellcode als ZIP herunterladen](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip)**

Zum Bauen werden ein C++20-Compiler und CMake 3.20 oder neuer benötigt.

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

Aktuelle Entwicklungswerkzeuge ausprobieren:

~~~sh
cdiv help
cdiv version
cdiv lex examples/hello.cdiv
cdiv check examples/hello.cdiv
~~~

<code>lex</code> zeigt Tokens, <code>check</code> prüft die Syntax, <code>build</code> erstellt ein natives Programm und <code>run</code> kompiliert und startet es. Für die letzten beiden Befehle wird ein C++20-Compiler benötigt.

## Entwicklungsstand

| Komponente | Status |
| --- | --- |
| C++20- / CMake-Projekt | ✅ |
| Lexer und Positionsdiagnosen | ✅ Erste Version |
| Parser und Syntaxprüfung | ✅ Erste Version |
| Variablen, Funktionen, Bedingungen und Schleifen | ✅ Unterstützter Teil wird kompiliert |
| Native C++20-Codegenerierung | ✅ Erste Vorschau |
| `cdiv build` und `cdiv run` | ✅ Erste Vorschau |
| Semantische Analyse und Typprüfung | 🛠 Geplant |
| Standardbibliothek, Module und Paketmanager | 🛠 Geplant |
| Formatter und Debugger | 🛠 Geplant |

Weitere Informationen stehen in der [Roadmap](docs/roadmap.md) und den [technischen Dokumenten](docs/getting-started.md).

## Downloads und Community

- **Quellcode:** [ZIP-Archiv](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip), ohne Konto.
- **Veröffentlichungen:** Vorgefertigte Pakete erscheinen auf der Seite [Releases](https://github.com/floppylib/C-Divide/releases), sobald ein Versions-Tag erstellt und der Release-Build erfolgreich abgeschlossen wurde. Derzeit gibt es noch keine vorgefertigten Pakete.
- **Mitwirken:** Bitte [CONTRIBUTING.md](CONTRIBUTING.md) und die [Sicherheitsrichtlinie](SECURITY.md) lesen.

## Dokumentation und Lizenz

Die technischen Leitfäden sind derzeit überwiegend auf Englisch. Übersetzungsbeiträge sind willkommen. Der Quellcode steht unter der [MIT-Lizenz](LICENSE), die Dokumentation unter [CC BY 4.0](LICENSE-DOCS).

---

<div align="center"><sub>Offen entwickelt. Zum Lernen entworfen. Auf Wachstum ausgelegt.</sub></div>
