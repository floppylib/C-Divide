<div align="center">
  <img src="assets/IMG_20261104_222603.png" alt="Logotipo oficial do C÷" width="144">
  <h1>C÷ · C-Divide</h1>
  <p><strong>Fácil de aprender. Poderoso para criar.</strong></p>
  <p>Uma linguagem de programação legível com objetivo de compilação nativa.</p>
</div>

<p><a href="README.md">English</a> · <a href="README.fa.md">فارسی</a> · <a href="README.ar.md">العربية</a> · <a href="README.de.md">Deutsch</a> · <a href="README.es.md">Español</a> · <a href="README.fr.md">Français</a> · <a href="README.hi.md">हिन्दी</a> · <a href="README.ja.md">日本語</a> · <a href="README.pt-BR.md">Português (Brasil)</a> · <a href="README.ru.md">Русский</a> · <a href="README.zh-CN.md">简体中文</a></p>

---

## O que é C÷?

C÷ (pronunciado **C-Divide**) é um projeto de linguagem de programação de código aberto. A proposta é facilitar o aprendizado sem abrir mão da estrutura necessária para desenvolver software sério.

A visão de longo prazo é uma **linguagem compilada para código nativo**, com opções de gerenciamento automático e explícito de memória, uma biblioteca padrão e ferramentas próprias para desenvolvedores.

> **Estado real do projeto:** este repositório contém uma base inicial de lexer, parser e verificação sintática. Ainda não executa programas C÷ nem gera executáveis nativos. O desenvolvimento está caminhando para uma versão 1.0 completa.

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

<code>lex</code> mostra os tokens e suas posições no código. <code>check</code> verifica a estrutura léxica e gramatical. Esses comandos ainda não executam programas nem geram executáveis nativos.

## Estado do desenvolvimento

| Componente | Estado |
| --- | --- |
| Projeto C++20 / CMake | ✅ |
| Lexer e diagnóstico de posições | ✅ Versão inicial |
| Parser e verificador sintático | ✅ Versão inicial |
| Gramática de variáveis, funções, condições e loops | ✅ Reconhecida, ainda não executada |
| Geração de código nativo | 🛠 Planejada |
| Runtime e execução de programas | 🛠 Planejados |
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
