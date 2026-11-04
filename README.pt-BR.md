<div align="center">
  <img src="assets/logo-padded.svg" alt="Logotipo oficial do C÷" width="144">
  <h1>C÷ · C-Divide</h1>
  <p><img alt="Built with ChatGPT" src="https://img.shields.io/badge/Built%20with-ChatGPT-10A37F?style=for-the-badge&logo=openai&logoColor=white"></p>
    <p align="center">
    <a href="https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip"><img alt="Código-fonte ZIP" src="https://img.shields.io/badge/Download-Source%20ZIP-238636?style=for-the-badge&logo=github&logoColor=white"></a>
    <a href="https://cmake.org/download/"><img alt="CMake 3.20+" src="https://img.shields.io/badge/Get-CMake%203.20%2B-064F8C?style=for-the-badge&logo=cmake&logoColor=white"></a>
    <a href="https://visualstudio.microsoft.com/visual-cpp-build-tools/"><img alt="Ferramentas C++ para Windows" src="https://img.shields.io/badge/Windows-C%2B%2B%20Build%20Tools-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white"></a>
    <a href="https://www.msys2.org/"><img alt="MSYS2 / GCC" src="https://img.shields.io/badge/GCC-MSYS2-4D4D4D?style=for-the-badge"></a>
    <a href="https://releases.llvm.org/"><img alt="LLVM / Clang" src="https://img.shields.io/badge/Clang-LLVM-E36F1E?style=for-the-badge"></a>
  </p>
  <p><em>Para compilar, você precisa do CMake 3.20+ e de um compilador C++20. Ainda não há binários pré-compilados do C÷.</em></p>
  <p><strong>Fácil de aprender. Poderoso para criar.</strong></p>
  <p>Uma linguagem de programação legível com objetivo de compilação nativa.</p>
</div>

<p><a href="README.md">English</a> · <a href="README.fa.md">فارسی</a> · <a href="README.ar.md">العربية</a> · <a href="README.de.md">Deutsch</a> · <a href="README.es.md">Español</a> · <a href="README.fr.md">Français</a> · <a href="README.hi.md">हिन्दी</a> · <a href="README.ja.md">日本語</a> · <a href="README.pt-BR.md">Português (Brasil)</a> · <a href="README.ru.md">Русский</a> · <a href="README.zh-CN.md">简体中文</a></p>

---

## O que é C÷?

C÷ (pronunciado **C-Divide**) é um projeto de linguagem de programação de código aberto. A proposta é facilitar o aprendizado sem abrir mão da estrutura necessária para desenvolver software sério.

A visão de longo prazo é uma **linguagem compilada para código nativo**, com opções de gerenciamento automático e explícito de memória, uma biblioteca padrão e ferramentas próprias para desenvolvedores.

> **Estado atual:** C÷ possui lexer, parser e verificador sintático iniciais, além de um backend nativo experimental. `cdiv build` e `cdiv run` traduzem a parte compatível da linguagem para C++20 e usam o compilador C++ do sistema para gerar um executável nativo. Análise semântica completa, verificação de tipos, módulos, biblioteca padrão e modelo de memória ainda estão em desenvolvimento. Esta ainda não é a versão final 1.0.

## Um exemplo da sintaxe

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

O exemplo mostra o estilo planejado para a linguagem. O front-end atual consegue tokenizar e verificar a sintaxe das construções compatíveis; execução, análise semântica e verificação de tipos ainda estão em desenvolvimento. **As palavras-chave da linguagem C÷ continuam em inglês**; a tradução deste README não significa que palavras-chave localizadas já sejam aceitas.

## Início rápido

Não é necessário ter uma conta no GitHub nem instalar o Git para baixar o código-fonte.

**[Baixar o código-fonte em ZIP](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip)**

Para compilar, você precisa de um compilador C++20 e CMake 3.20 ou superior.

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

Experimente as ferramentas de desenvolvimento atuais:

~~~sh
cdiv help
cdiv version
cdiv lex examples/hello.cdiv
cdiv check examples/hello.cdiv
~~~

<code>lex</code> mostra tokens, <code>check</code> verifica a sintaxe, <code>build</code> gera um executável nativo e <code>run</code> compila e executa o programa. Os dois últimos comandos exigem um compilador C++20.

## Estado do desenvolvimento

| Componente | Estado |
| --- | --- |
| Projeto C++20 / CMake | ✅ |
| Lexer e diagnóstico de posições | ✅ Versão inicial |
| Parser e verificador sintático | ✅ Versão inicial |
| Variáveis, funções, condições e loops | ✅ A parte compatível é compilada |
| Geração nativa via C++20 | ✅ Prévia inicial |
| Comandos `cdiv build` e `cdiv run` | ✅ Prévia inicial |
| Análise semântica e de tipos | 🛠 Planejadas |
| Biblioteca padrão, módulos e gerenciador de pacotes | 🛠 Planejados |
| Formatador e depurador | 🛠 Planejados |

Veja o [roadmap](docs/roadmap.md) e os [guias técnicos](docs/getting-started.md).

## Downloads e comunidade

- **Código-fonte:** [arquivo ZIP](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip), sem precisar de conta.
- **Versões:** pacotes pré-compilados serão publicados na página [Releases](https://github.com/floppylib/C-Divide/releases) quando houver uma versão marcada e o processo de build for concluído com sucesso. Ainda não há pacotes pré-compilados disponíveis.
- **Contribuição:** leia [CONTRIBUTING.md](CONTRIBUTING.md) e a [política de segurança](SECURITY.md).

## Documentação e licença

Por enquanto, os guias técnicos são escritos principalmente em inglês. Contribuições para traduzi-los são bem-vindas. O código-fonte usa a licença [MIT](LICENSE) e a documentação usa [CC BY 4.0](LICENSE-DOCS).

---

<div align="center"><sub>Desenvolvido de forma aberta. Feito para aprender. Pronto para crescer.</sub></div>
