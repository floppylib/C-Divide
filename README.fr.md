<div align="center">
  <img src="assets/logo-padded.svg" alt="Logo officiel de C÷" width="144">
  <h1>C÷ · C-Divide</h1>
  <p><img alt="Built with ChatGPT" src="https://img.shields.io/badge/Built%20with-ChatGPT-10A37F?style=for-the-badge&logo=openai&logoColor=white"></p>
    <p align="center">
    <a href="https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip"><img alt="Sources ZIP" src="https://img.shields.io/badge/Download-Source%20ZIP-238636?style=for-the-badge&logo=github&logoColor=white"></a>
    <a href="https://cmake.org/download/"><img alt="CMake 3.20+" src="https://img.shields.io/badge/Get-CMake%203.20%2B-064F8C?style=for-the-badge&logo=cmake&logoColor=white"></a>
    <a href="https://visualstudio.microsoft.com/visual-cpp-build-tools/"><img alt="Outils C++ pour Windows" src="https://img.shields.io/badge/Windows-C%2B%2B%20Build%20Tools-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white"></a>
    <a href="https://www.msys2.org/"><img alt="MSYS2 / GCC" src="https://img.shields.io/badge/GCC-MSYS2-4D4D4D?style=for-the-badge"></a>
    <a href="https://releases.llvm.org/"><img alt="LLVM / Clang" src="https://img.shields.io/badge/Clang-LLVM-E36F1E?style=for-the-badge"></a>
  </p>
  <p><em>La compilation nécessite CMake 3.20+ et un compilateur C++20. Aucun binaire précompilé de C÷ n’est encore disponible.</em></p>
  <p><strong>Simple à apprendre. Puissant pour créer.</strong></p>
  <p>Un langage de programmation lisible conçu avec pour objectif la compilation native.</p>
</div>

<p><a href="README.md">English</a> · <a href="README.fa.md">فارسی</a> · <a href="README.ar.md">العربية</a> · <a href="README.de.md">Deutsch</a> · <a href="README.es.md">Español</a> · <a href="README.fr.md">Français</a> · <a href="README.hi.md">हिन्दी</a> · <a href="README.ja.md">日本語</a> · <a href="README.pt-BR.md">Português (Brasil)</a> · <a href="README.ru.md">Русский</a> · <a href="README.zh-CN.md">简体中文</a></p>

---

## Qu’est-ce que C÷ ?

C÷ (prononcé **C-Divide**) est un projet open source de langage de programmation. Son objectif est de rendre le code accessible aux débutants tout en conservant la structure nécessaire aux logiciels sérieux.

À long terme, C÷ vise à devenir un **langage compilé en code natif**, avec des options de gestion automatique et explicite de la mémoire, une bibliothèque standard et des outils de développement intégrés.

> **État réel :** ce dépôt contient actuellement les premières bases d’un lexer, d’un parser et d’un vérificateur syntaxique. Il n’exécute pas encore les programmes C÷ et ne produit pas de binaires natifs. Le projet avance vers une version 1.0 complète.

## Aperçu de la syntaxe

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

Cet exemple illustre le style visé. Le front-end actuel peut analyser les tokens et vérifier la syntaxe des constructions prises en charge ; l’exécution, l’analyse sémantique et le typage sont encore en développement. **Les mots-clés du langage C÷ sont actuellement en anglais** : la traduction de ce README ne signifie pas que des mots-clés localisés sont disponibles.

## Démarrage rapide

Aucun compte GitHub ni installation de Git n’est nécessaire pour télécharger les sources.

**[Télécharger les sources au format ZIP](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip)**

Pour compiler : un compilateur C++20 et CMake 3.20 ou une version ultérieure.

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

Essayez les outils de développement actuels :

~~~sh
cdiv help
cdiv version
cdiv lex examples/hello.cdiv
cdiv check examples/hello.cdiv
~~~

<code>lex</code> affiche les tokens et leur position dans le fichier. <code>check</code> vérifie la structure lexicale et grammaticale. Ces commandes n’exécutent pas de programmes et ne génèrent pas encore de binaires natifs.

## État du développement

| Composant | État |
| --- | --- |
| Projet C++20 / CMake | ✅ |
| Lexer et diagnostics de position | ✅ Première version |
| Parser et vérificateur syntaxique | ✅ Première version |
| Grammaire des variables, fonctions, conditions et boucles | ✅ Reconnue, non exécutée |
| Génération de code natif | 🛠 Prévue |
| Runtime et exécution | 🛠 Prévus |
| Analyse sémantique et des types | 🛠 Prévue |
| Bibliothèque standard, modules et gestionnaire de paquets | 🛠 Prévus |
| Formateur et débogueur | 🛠 Prévus |

Consultez la [feuille de route](docs/roadmap.md) et les [guides techniques](docs/getting-started.md).

## Téléchargements et communauté

- **Sources :** [archive ZIP](https://github.com/floppylib/C-Divide/archive/refs/heads/main.zip), sans compte nécessaire.
- **Versions :** les paquets précompilés seront publiés sur la page [Releases](https://github.com/floppylib/C-Divide/releases) après la création d’une version taguée et la réussite de sa compilation. Aucun paquet précompilé n’est encore disponible.
- **Contribuer :** consultez [CONTRIBUTING.md](CONTRIBUTING.md) et la [politique de sécurité](SECURITY.md).

## Documentation et licence

Les guides techniques sont pour le moment principalement rédigés en anglais. Les contributions à leur traduction sont les bienvenues. Le code source est sous licence [MIT](LICENSE) et la documentation sous [CC BY 4.0](LICENSE-DOCS).

---

<div align="center"><sub>Développé au grand jour. Conçu pour être appris. Prêt à évoluer.</sub></div>
