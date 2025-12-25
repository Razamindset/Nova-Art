#pragma once
#include <string>
#include <vector>
#include <unordered_map>

enum TokenType {
    // Keywords
    RAKHO,
    FARMAO,
    POCHO,
    AGAR,
    WARNA,
    JABTAK,

    // Literals and Identifiers.
    IDENTIFIER,
    NUMBER,
    STRING,

    // Operators and Punctuation
    EQUALS,
    PLUS,
    MINUS,
    STAR,
    SLASH,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,

    // Meta
    END_OF_FILE,
    ERROR
};

struct Token {
    TokenType type;
    std::string lexeme; // The actual content of the token
    int line; //? For error reporting
};

class Lexer {
    public:
        Lexer(const std::string& source);
        std::vector<Token> scanTokens();
    
    private:
        std::string source;
        std::vector<Token> tokens;

        int start = 0;
        int current = 0;
        int line = 1;

        static const std::unordered_map<std::string, TokenType> keywords;

        bool isAtEnd(){ return current >= source.length(); };
        char advance(){ return source[current++]; };
        void addToken(TokenType token);
        void scanToken();
        void identifier();
        void number();
        void stringLiteral();
};