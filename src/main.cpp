#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

// SPDX-License-Identifier: MIT

namespace cdiv {

enum class Kind {
    Identifier, Number, String,
    KwPrint, KwIf, KwElse, KwRepeat, KwWhile, KwFn, KwReturn, KwImport,
    KwTrue, KwFalse,
    LParen, RParen, LBrace, RBrace, Comma, Colon, Semicolon, Arrow,
    Plus, Minus, Star, Slash, Percent,
    Equal, EqualEqual, Bang, BangEqual, Less, LessEqual, Greater, GreaterEqual,
    AndAnd, OrOr, End, Invalid
};

struct Token {
    Kind kind;
    std::string lexeme;
    int line;
    int column;
};

struct Diagnostic {
    int line;
    int column;
    std::string message;
};

std::string_view kind_name(Kind kind) {
    switch (kind) {
        case Kind::Identifier: return "identifier";
        case Kind::Number: return "number";
        case Kind::String: return "string";
        case Kind::KwPrint: return "print";
        case Kind::KwIf: return "if";
        case Kind::KwElse: return "else";
        case Kind::KwRepeat: return "repeat";
        case Kind::KwWhile: return "while";
        case Kind::KwFn: return "fn";
        case Kind::KwReturn: return "return";
        case Kind::KwImport: return "import";
        case Kind::KwTrue: return "true";
        case Kind::KwFalse: return "false";
        case Kind::LParen: return "(";
        case Kind::RParen: return ")";
        case Kind::LBrace: return "{";
        case Kind::RBrace: return "}";
        case Kind::Comma: return ",";
        case Kind::Colon: return ":";
        case Kind::Semicolon: return ";";
        case Kind::Arrow: return "->";
        case Kind::Plus: return "+";
        case Kind::Minus: return "-";
        case Kind::Star: return "*";
        case Kind::Slash: return "/";
        case Kind::Percent: return "%";
        case Kind::Equal: return "=";
        case Kind::EqualEqual: return "==";
        case Kind::Bang: return "!";
        case Kind::BangEqual: return "!=";
        case Kind::Less: return "<";
        case Kind::LessEqual: return "<=";
        case Kind::Greater: return ">";
        case Kind::GreaterEqual: return ">=";
        case Kind::AndAnd: return "&&";
        case Kind::OrOr: return "||";
        case Kind::End: return "end of file";
        case Kind::Invalid: return "invalid token";
    }
    return "unknown";
}

class Lexer {
public:
    explicit Lexer(std::string_view source) : source_(source) {}

    std::vector<Token> scan() {
        while (!at_end()) {
            start_ = current_;
            start_line_ = line_;
            start_column_ = column_;
            scan_one();
        }
        tokens_.push_back({Kind::End, "", line_, column_});
        return tokens_;
    }

    const std::vector<Diagnostic>& diagnostics() const { return diagnostics_; }

private:
    std::string_view source_;
    std::vector<Token> tokens_;
    std::vector<Diagnostic> diagnostics_;
    std::size_t start_ = 0;
    std::size_t current_ = 0;
    int line_ = 1;
    int column_ = 1;
    int start_line_ = 1;
    int start_column_ = 1;

    bool at_end() const { return current_ >= source_.size(); }
    char peek() const { return at_end() ? '\0' : source_[current_]; }
    char peek_next() const { return current_ + 1 >= source_.size() ? '\0' : source_[current_ + 1]; }

    char advance() {
        const char c = source_[current_++];
        if (c == '\n') { ++line_; column_ = 1; }
        else { ++column_; }
        return c;
    }

    bool match(char expected) {
        if (at_end() || source_[current_] != expected) return false;
        advance();
        return true;
    }

    void add(Kind kind) {
        tokens_.push_back({kind, std::string(source_.substr(start_, current_ - start_)), start_line_, start_column_});
    }

    void error(std::string message) {
        diagnostics_.push_back({start_line_, start_column_, std::move(message)});
    }

    static bool alpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
    }
    static bool digit(char c) { return c >= '0' && c <= '9'; }

    void scan_one() {
        const char c = advance();
        switch (c) {
            case ' ': case '\r': case '\t': return;
            case '\n': return;
            case '(': add(Kind::LParen); return;
            case ')': add(Kind::RParen); return;
            case '{': add(Kind::LBrace); return;
            case '}': add(Kind::RBrace); return;
            case ',': add(Kind::Comma); return;
            case ':': add(Kind::Colon); return;
            case ';': add(Kind::Semicolon); return;
            case '+': add(Kind::Plus); return;
            case '*': add(Kind::Star); return;
            case '%': add(Kind::Percent); return;
            case '-': add(match('>') ? Kind::Arrow : Kind::Minus); return;
            case '=': add(match('=') ? Kind::EqualEqual : Kind::Equal); return;
            case '!': add(match('=') ? Kind::BangEqual : Kind::Bang); return;
            case '<': add(match('=') ? Kind::LessEqual : Kind::Less); return;
            case '>': add(match('=') ? Kind::GreaterEqual : Kind::Greater); return;
            case '&':
                if (match('&')) add(Kind::AndAnd);
                else { add(Kind::Invalid); error("expected '&' after '&'"); }
                return;
            case '|':
                if (match('|')) add(Kind::OrOr);
                else { add(Kind::Invalid); error("expected '|' after '|'"); }
                return;
            case '/':
                if (match('/')) {
                    while (!at_end() && peek() != '\n') advance();
                } else add(Kind::Slash);
                return;
            case '"': scan_string(); return;
            default: break;
        }

        if (digit(c)) { scan_number(); return; }
        if (alpha(c)) { scan_identifier(); return; }
        add(Kind::Invalid);
        error(std::string("unexpected character '") + c + "'");
    }

    void scan_string() {
        while (!at_end() && peek() != '"') {
            if (peek() == '\n') {
                error("string literals cannot contain an unescaped newline");
                add(Kind::Invalid);
                return;
            }
            if (peek() == '\\') {
                advance();
                if (at_end()) break;
                const char escaped = advance();
                if (escaped != 'n' && escaped != 't' && escaped != 'r' && escaped != '"' && escaped != '\\') {
                    error("unsupported string escape sequence");
                }
            } else advance();
        }
        if (at_end()) {
            add(Kind::Invalid);
            error("unterminated string literal");
            return;
        }
        advance();
        add(Kind::String);
    }

    void scan_number() {
        while (digit(peek())) advance();
        if (peek() == '.' && digit(peek_next())) {
            advance();
            while (digit(peek())) advance();
        }
        add(Kind::Number);
    }

    void scan_identifier() {
        while (alpha(peek()) || digit(peek())) advance();
        const std::string text(source_.substr(start_, current_ - start_));
        static const std::unordered_map<std::string, Kind> keywords = {
            {"print", Kind::KwPrint}, {"if", Kind::KwIf}, {"else", Kind::KwElse},
            {"repeat", Kind::KwRepeat}, {"while", Kind::KwWhile}, {"fn", Kind::KwFn},
            {"return", Kind::KwReturn}, {"import", Kind::KwImport},
            {"true", Kind::KwTrue}, {"false", Kind::KwFalse}
        };
        const auto found = keywords.find(text);
        add(found == keywords.end() ? Kind::Identifier : found->second);
    }
};

class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens) : tokens_(tokens) {}

    bool parse() {
        while (!check(Kind::End)) {
            const auto before = current_;
            declaration_or_statement();
            if (current_ == before) advance();
        }
        return diagnostics_.empty();
    }

    const std::vector<Diagnostic>& diagnostics() const { return diagnostics_; }

private:
    const std::vector<Token>& tokens_;
    std::vector<Diagnostic> diagnostics_;
    std::size_t current_ = 0;

    const Token& peek() const { return tokens_[current_]; }
    const Token& previous() const { return tokens_[current_ - 1]; }
    bool check(Kind kind) const { return peek().kind == kind; }
    bool is_at_end() const { return check(Kind::End); }
    const Token& advance() { if (!is_at_end()) ++current_; return previous(); }
    bool match(Kind kind) { if (!check(kind)) return false; advance(); return true; }

    bool consume(Kind kind, const std::string& message) {
        if (check(kind)) { advance(); return true; }
        report(peek(), message);
        return false;
    }

    void report(const Token& token, std::string message) {
        diagnostics_.push_back({token.line, token.column, std::move(message)});
    }

    void synchronize() {
        while (!is_at_end()) {
            if (current_ > 0 && previous().kind == Kind::Semicolon) return;
            switch (peek().kind) {
                case Kind::KwFn: case Kind::KwIf: case Kind::KwRepeat: case Kind::KwWhile:
                case Kind::KwPrint: case Kind::KwReturn: case Kind::KwImport: return;
                default: advance(); break;
            }
        }
    }

    void declaration_or_statement() {
        if (match(Kind::KwFn)) { function_declaration(); return; }
        statement();
    }

    void function_declaration() {
        if (!consume(Kind::Identifier, "expected a function name after 'fn'")) { synchronize(); return; }
        if (!consume(Kind::LParen, "expected '(' after function name")) { synchronize(); return; }
        if (!check(Kind::RParen)) {
            do {
                if (!consume(Kind::Identifier, "expected a parameter name")) { synchronize(); return; }
                if (!consume(Kind::Colon, "expected ':' after parameter name")) { synchronize(); return; }
                if (!consume(Kind::Identifier, "expected a parameter type")) { synchronize(); return; }
            } while (match(Kind::Comma));
        }
        if (!consume(Kind::RParen, "expected ')' after parameters")) { synchronize(); return; }
        if (match(Kind::Arrow) && !consume(Kind::Identifier, "expected a return type after '->'")) {
            synchronize(); return;
        }
        block();
    }

    void statement() {
        if (match(Kind::KwPrint)) { print_statement(); return; }
        if (match(Kind::KwIf)) { if_statement(); return; }
        if (match(Kind::KwRepeat)) { repeat_statement(); return; }
        if (match(Kind::KwWhile)) { while_statement(); return; }
        if (match(Kind::KwReturn)) { return_statement(); return; }
        if (match(Kind::KwImport)) { import_statement(); return; }
        if (match(Kind::LBrace)) { block_contents(); return; }
        if (check(Kind::Identifier) && current_ + 1 < tokens_.size() &&
            (tokens_[current_ + 1].kind == Kind::Equal || tokens_[current_ + 1].kind == Kind::Colon)) {
            assignment_statement(); return;
        }
        expression_statement();
    }

    void print_statement() {
        if (!consume(Kind::LParen, "expected '(' after 'print'")) { synchronize(); return; }
        if (!expression()) { synchronize(); return; }
        if (!consume(Kind::RParen, "expected ')' after print value")) { synchronize(); return; }
        if (!consume(Kind::Semicolon, "expected ';' after print statement")) synchronize();
    }

    void if_statement() {
        if (!expression()) { synchronize(); return; }
        block();
        if (match(Kind::KwElse)) {
            if (match(Kind::KwIf)) if_statement();
            else block();
        }
    }

    void repeat_statement() {
        if (!expression()) { synchronize(); return; }
        block();
    }

    void while_statement() {
        if (!expression()) { synchronize(); return; }
        block();
    }

    void return_statement() {
        if (!check(Kind::Semicolon) && !expression()) { synchronize(); return; }
        if (!consume(Kind::Semicolon, "expected ';' after return")) synchronize();
    }

    void import_statement() {
        if (!consume(Kind::Identifier, "expected a module name after 'import'")) { synchronize(); return; }
        if (!consume(Kind::Semicolon, "expected ';' after import")) synchronize();
    }

    void assignment_statement() {
        advance(); // identifier
        if (match(Kind::Colon)) {
            if (!consume(Kind::Identifier, "expected a type after ':'")) { synchronize(); return; }
        }
        if (!consume(Kind::Equal, "expected '=' in assignment")) { synchronize(); return; }
        if (!expression()) { synchronize(); return; }
        if (!consume(Kind::Semicolon, "expected ';' after assignment")) synchronize();
    }

    void expression_statement() {
        if (!expression()) { synchronize(); return; }
        if (!consume(Kind::Semicolon, "expected ';' after expression")) synchronize();
    }

    void block() {
        if (!consume(Kind::LBrace, "expected '{' to start a block")) { synchronize(); return; }
        block_contents();
    }

    void block_contents() {
        while (!check(Kind::RBrace) && !is_at_end()) declaration_or_statement();
        if (!consume(Kind::RBrace, "expected '}' after block")) synchronize();
    }

    int precedence(Kind kind) const {
        switch (kind) {
            case Kind::OrOr: return 1;
            case Kind::AndAnd: return 2;
            case Kind::EqualEqual: case Kind::BangEqual: return 3;
            case Kind::Less: case Kind::LessEqual: case Kind::Greater: case Kind::GreaterEqual: return 4;
            case Kind::Plus: case Kind::Minus: return 5;
            case Kind::Star: case Kind::Slash: case Kind::Percent: return 6;
            default: return 0;
        }
    }

    bool expression(int min_precedence = 1) {
        if (!unary()) return false;
        while (precedence(peek().kind) >= min_precedence) {
            const int op_precedence = precedence(advance().kind);
            if (!expression(op_precedence + 1)) return false;
        }
        return true;
    }

    bool unary() {
        if (match(Kind::Bang) || match(Kind::Minus) || match(Kind::Plus)) return unary();
        return primary();
    }

    bool primary() {
        if (match(Kind::Number) || match(Kind::String) || match(Kind::KwTrue) || match(Kind::KwFalse)) return true;
        if (match(Kind::Identifier)) {
            while (match(Kind::LParen)) {
                if (!check(Kind::RParen)) {
                    do { if (!expression()) return false; } while (match(Kind::Comma));
                }
                if (!consume(Kind::RParen, "expected ')' after function arguments")) return false;
            }
            return true;
        }
        if (match(Kind::LParen)) {
            if (!expression()) return false;
            return consume(Kind::RParen, "expected ')' after expression");
        }
        report(peek(), "expected an expression");
        return false;
    }
};

} // namespace cdiv

#include "native_backend.hpp"

namespace cdiv {

std::string read_file(const std::string& path) {
    std::ifstream input(path, std::ios::binary);
    if (!input) throw std::runtime_error("cannot open file: " + path);
    std::ostringstream contents;
    contents << input.rdbuf();
    return contents.str();
}

void print_diagnostics(const std::vector<Diagnostic>& diagnostics, const std::string& path) {
    for (const auto& diagnostic : diagnostics) {
        std::cerr << path << ':' << diagnostic.line << ':' << diagnostic.column
                  << ": error: " << diagnostic.message << '\n';
    }
}

bool generate_native_source(const std::string& path, std::string& generated) {
    const std::string source = read_file(path);
    Lexer lexer(source);
    const auto tokens = lexer.scan();
    if (!lexer.diagnostics().empty()) {
        print_diagnostics(lexer.diagnostics(), path);
        return false;
    }

    Parser parser(tokens);
    if (!parser.parse()) {
        print_diagnostics(parser.diagnostics(), path);
        return false;
    }

    NativeBackend backend(tokens);
    generated = backend.generate();
    return true;
}

int build_source_file(const std::string& path, const std::filesystem::path& output) {
    std::string generated;
    if (!generate_native_source(path, generated)) return 1;
    return build_native_program(generated, output);
}

int run_source_file(const std::string& path) {
    std::string generated;
    if (!generate_native_source(path, generated)) return 1;
#ifdef _WIN32
    const auto executable = unique_temp_path(".exe");
#else
    const auto executable = unique_temp_path("");
#endif
    const int built = build_native_program(generated, executable);
    if (built != 0) return built;
    const int result = run_native_program(executable);
    std::error_code ignored;
    std::filesystem::remove(executable, ignored);
    return result;
}

void print_help() {
    std::cout << "C÷ native compiler\n"
              << "Usage:\n"
              << "  cdiv help                         Show this help\n"
              << "  cdiv version                      Show version\n"
              << "  cdiv lex <file.cdiv>              Print lexical tokens\n"
              << "  cdiv check <file.cdiv>            Check source syntax\n"
              << "  cdiv build <file.cdiv> [-o path]  Build a native executable\n"
              << "  cdiv run <file.cdiv>              Build and run a program\n"
              << "\nSet CXX to choose the host C++20 compiler (g++, clang++, or cl).\n";
}

} // namespace cdiv

int main(int argc, char** argv) {
    using namespace cdiv;
    if (argc < 2) { print_help(); return 0; }

    const std::string command = argv[1];
    if (command == "help" || command == "--help" || command == "-h") { print_help(); return 0; }
    if (command == "version" || command == "--version") {
        std::cout << "C÷ 0.2.0 (native backend preview)\n";
        return 0;
    }

    try {
        if (command == "build") {
            if (argc != 3 && argc != 5) {
                std::cerr << "error: usage: cdiv build <file.cdiv> [-o output]\n";
                return 2;
            }
            const std::string path = argv[2];
            std::filesystem::path output;
            if (argc == 5) {
                if (std::string(argv[3]) != "-o") {
                    std::cerr << "error: expected '-o' before output path\n";
                    return 2;
                }
                output = argv[4];
            } else {
                output = std::filesystem::current_path() / "build" /
                         std::filesystem::path(path).stem();
#ifdef _WIN32
                output += ".exe";
#endif
            }
            const int result = build_source_file(path, output);
            if (result == 0) std::cout << "Built native executable: " << output.string() << '\n';
            return result;
        }

        if (command == "run") {
            if (argc != 3) {
                std::cerr << "error: usage: cdiv run <file.cdiv>\n";
                return 2;
            }
            return run_source_file(argv[2]);
        }

        if (command != "lex" && command != "check") {
            std::cerr << "error: unknown command '" << command << "'\n";
            print_help();
            return 2;
        }
        if (argc != 3) {
            std::cerr << "error: command '" << command << "' requires one source file\n";
            return 2;
        }

        const std::string path = argv[2];
        const std::string source = read_file(path);
        Lexer lexer(source);
        const auto tokens = lexer.scan();
        if (!lexer.diagnostics().empty()) {
            print_diagnostics(lexer.diagnostics(), path);
            return 1;
        }

        if (command == "lex") {
            for (const auto& token : tokens) {
                std::cout << token.line << ':' << token.column << "  " << kind_name(token.kind);
                if (!token.lexeme.empty()) std::cout << "  '" << token.lexeme << "'";
                std::cout << '\n';
            }
            return 0;
        }

        Parser parser(tokens);
        if (!parser.parse()) {
            print_diagnostics(parser.diagnostics(), path);
            return 1;
        }
        std::cout << "OK: " << path << " passed lexical and syntax checks.\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << "error: " << error.what() << '\n';
        return 1;
    }
}
