# Translations and localization

C÷ welcomes contributors who make the project easier to understand around the world.

## Available README languages

| Language | File |
| --- | --- |
| English | [README.md](README.md) |
| فارسی — Persian | [README.fa.md](README.fa.md) |
| العربية — Arabic | [README.ar.md](README.ar.md) |
| Deutsch — German | [README.de.md](README.de.md) |
| Español — Spanish | [README.es.md](README.es.md) |
| Français — French | [README.fr.md](README.fr.md) |
| हिन्दी — Hindi | [README.hi.md](README.hi.md) |
| 日本語 — Japanese | [README.ja.md](README.ja.md) |
| Português (Brasil) — Brazilian Portuguese | [README.pt-BR.md](README.pt-BR.md) |
| Русский — Russian | [README.ru.md](README.ru.md) |
| 简体中文 — Simplified Chinese | [README.zh-CN.md](README.zh-CN.md) |

## What is translated today?

The project overview (README) is available in the languages above. The technical guides, language specification, compiler diagnostics, command-line interface, and C÷ language keywords are not localized yet. The source language currently uses English keywords.

English README content is the reference for project status and technical facts. A translated page must not claim that a planned feature is already implemented or that a release is available when it is not.

## How to contribute a translation

1. Choose the README for your language, or create a new file using the pattern `README.<locale>.md`.
2. Compare it with [README.md](README.md) before making changes.
3. Keep commands, code samples, file paths, URLs, license names, and version numbers unchanged unless the source has changed.
4. Preserve the current implementation status. In particular, do not describe C÷ as a finished compiler: the current front end does not execute programs or generate native executables.
5. Use natural language rather than translating technical identifiers such as `lexer`, `parser`, `CMake`, or `C++20` inconsistently.
6. Open a pull request and mention which sections were translated or updated.

Please review machine-assisted translations carefully. Clarity and technical accuracy matter more than literal word-for-word translation.

## Adding a new language

Add the new README file, then add its link to the language switcher in every README. Also update the language table in this document. Use a recognizable locale suffix, such as `README.it.md` for Italian or `README.ko.md` for Korean.

Thank you for helping make C÷ more welcoming and accessible.
