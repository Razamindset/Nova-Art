#include "../include/Lexer.hpp"
#include <iostream>
#include <algorithm>

Lexer::Lexer(const std::string& src): source(src) {}

// Loop through the file to extract tokens
std::vector<Token> Lexer::scanTokens(){
    while (!isAtEnd()){
        start = current;
        scanToken();
    }
    // When end of file add EOF to the tokens
    tokens.push_back({END_OF_FILE, "", line});

    return tokens;
}

void Lexer::addToken(TokenType type){
    std::string text = source.substr(start, current - start);
    tokens.push_back({type, text, line});
}

void Lexer::number(){
    while (isdigit(source[current])) advance();

    //! For now we can skip decimals 
    // If we want to keep decimals we can check if the token is a . then loop again
    if(source[current] == '.' && isdigit(source[current + 1])){
        advance(); //consume the .
        while (isdigit(source[current])) advance();
    }
    
    addToken(NUMBER);
}

// Initilize the keywords. Using a map will provide O(N) access.
const std::unordered_map<std::string, TokenType> Lexer::keywords = {
    {"rakho", RAKHO},
    {"farmao", FARMAO},
    {"pocho", POCHO},
    {"agar", AGAR},
    {"warna", WARNA},
    {"jabtak", JABTAK}
};

void Lexer::scanToken(){
    char c = advance();

    switch (c){
        case '(': addToken(LEFT_PAREN); break;
        case ')':addToken(RIGHT_PAREN); break;
        case '+':addToken(PLUS); break;
        case '-':addToken(MINUS); break;
        case '*':addToken(STAR); break;
        case '/':addToken(SLASH); break;
        case '=':addToken(EQUALS); break;
        case ':':addToken(COLON); break;
        case '"': stringLiteral(); break;
        case ' ':
        case '\r':
        case '\t': break; // Ignore whitespace
        case '\n': line++; break;

        default:
            if(isdigit(c)){
                number();
            } else if(isalpha(c) || c == '_'){
                identifier();
            } else {
                std::cerr<< "Line: "<< line<< " Unknown character\n";
            }
            break;
        }
}

// This function will read the whole word to see if it is a valid idetifier or not.
void Lexer::identifier(){
    while (isalnum(source[current]) || source[current] == '_') advance();
    
    std::string text = source.substr(start, current - start);
    
    // All of our identifiers are in lower case so we can convert if we want
    std::string lowerText = text;
    std::transform(lowerText.begin(), lowerText.end(), lowerText.begin(), ::tolower);
    
    TokenType type = IDENTIFIER;
    // If the token exists in the dictionary then add to the tokens
    if(keywords.count(lowerText)){
        type = keywords.at(lowerText);
    }

    addToken(type);
}

void Lexer::stringLiteral(){
    while(source[current] != '"' && !isAtEnd()){
        if(source[current] == '\n') line++;
        advance();
    }

    if(isAtEnd()){
        std::cerr << "Line: " << line << " Unfinished string!\n";
        return;
    }

    advance(); // consume the closing "

    std::string value = source.substr(start + 1, current - start - 2);
    tokens.push_back({STRING, value, line});
}