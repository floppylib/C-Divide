<div align="center">
  <img src="assets/logo-padded.svg" alt="Logotipo oficial de C÷" width="144">
  <h1>C÷ · C-Divide</h1>
    <p align="center">
    <a href="https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip"><img alt="Código fuente ZIP" src="https://img.shields.io/badge/Download-Source%20ZIP-238636?style=for-the-badge&logo=github&logoColor=white"></a>
    <a href="https://cmake.org/download/"><img alt="CMake 3.20+" src="https://img.shields.io/badge/Get-CMake%203.20%2B-064F8C?style=for-the-badge&logo=cmake&logoColor=white"></a>
    <a href="https://visualstudio.microsoft.com/visual-cpp-build-tools/"><img alt="Herramientas C++ para Windows" src="https://img.shields.io/badge/Windows-C%2B%2B%20Build%20Tools-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white"></a>
    <a href="https://www.msys2.org/"><img alt="MSYS2 / GCC" src="https://img.shields.io/badge/GCC-MSYS2-4D4D4D?style=for-the-badge"></a>
    <a href="https://releases.llvm.org/"><img alt="LLVM / Clang" src="https://img.shields.io/badge/Clang-LLVM-E36F1E?style=for-the-badge"></a>
  </p>
  <p><em>Para compilar necesitas CMake 3.20+ y un compilador C++20. Todavía no hay binarios precompilados de C÷.</em></p>
  <p><strong>Fácil de aprender. Potente para crear.</strong></p>
  <p>Un lenguaje de programación legible con el objetivo de compilar a código nativo.</p>
</div>

<p><a href="README.md">English</a> · <a href="README.fa.md">فارسی</a> · <a href="README.ar.md">العربية</a> · <a href="README.de.md">Deutsch</a> · <a href="README.es.md">Español</a> · <a href="README.fr.md">Français</a> · <a href="README.hi.md">हिन्दी</a> · <a href="README.ja.md">日本語</a> · <a href="README.pt-BR.md">Português (Brasil)</a> · <a href="README.ru.md">Русский</a> · <a href="README.zh-CN.md">简体中文</a></p>

---

## ¿Qué es C÷?

C÷ (pronunciado **C-Divide**) es un proyecto de lenguaje de programación de código abierto. Busca que aprender a programar sea accesible sin renunciar a la estructura necesaria para crear software serio.

La visión a largo plazo es un **lenguaje compilado a código nativo**, con opciones de gestión automática y explícita de memoria, una biblioteca estándar y herramientas de desarrollo propias.

> **Estado real:** el repositorio contiene una primera base de lexer, parser y comprobación sintáctica. Todavía no ejecuta programas C÷ ni genera ejecutables nativos. El objetivo del proyecto es llegar a una versión 1.0 completa.

## Un vistazo a la sintaxis

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

Este ejemplo muestra el estilo previsto. El front end actual puede tokenizar y comprobar la sintaxis de las construcciones compatibles; la ejecución, el análisis semántico y los tipos siguen en desarrollo. **Las palabras clave del lenguaje C÷ son actualmente inglesas**; traducir este README no significa que existan palabras clave localizadas.

## Inicio rápido

No necesitas una cuenta de GitHub ni instalar Git para descargar el código fuente.

**[Descargar el código fuente en ZIP](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip)**

Requisitos para compilar: un compilador C++20 y CMake 3.20 o posterior.

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

Prueba las herramientas actuales:

~~~sh
cdiv help
cdiv version
cdiv lex examples/hello.cdiv
cdiv check examples/hello.cdiv
~~~

<code>lex</code> muestra los tokens y sus posiciones. <code>check</code> comprueba la estructura léxica y gramatical. Estos comandos no ejecutan programas ni generan ejecutables nativos.

## Estado de desarrollo

| Componente | Estado |
| --- | --- |
| Proyecto C++20 / CMake | ✅ |
| Lexer y diagnósticos de posición | ✅ Versión inicial |
| Parser y comprobador sintáctico | ✅ Versión inicial |
| Gramática de variables, funciones, condiciones y bucles | ✅ Se reconoce, no se ejecuta |
| Generación de código nativo | 🛠 Planificado |
| Runtime y ejecución | 🛠 Planificado |
| Análisis semántico y de tipos | 🛠 Planificado |
| Biblioteca estándar, módulos y gestor de paquetes | 🛠 Planificado |
| Formateador y depurador | 🛠 Planificado |

Consulta la [hoja de ruta](docs/roadmap.md) y las [guías técnicas](docs/getting-started.md).

## Descargas y comunidad

- **Código fuente:** [archivo ZIP](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip), sin necesidad de cuenta.
- **Versiones:** los paquetes precompilados aparecerán en [Releases](https://github.com/floppylib/C-Divide/releases) cuando se publique una versión etiquetada y la compilación de lanzamiento termine correctamente. Todavía no hay paquetes precompilados publicados.
- **Contribuir:** lee [CONTRIBUTING.md](CONTRIBUTING.md) y consulta la [política de seguridad](SECURITY.md).

## Documentación y licencia

Las guías técnicas están disponibles principalmente en inglés por ahora. Se aceptan contribuciones para traducirlas. El código fuente usa la licencia [MIT](LICENSE) y la documentación usa [CC BY 4.0](LICENSE-DOCS).

---

<div align="center"><sub>Desarrollado en abierto. Diseñado para aprender. Preparado para crecer.</sub></div>
