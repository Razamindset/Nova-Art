#include <string>
#include "Lexer.hpp"

std::string tokenTypeToString(TokenType type) {
    switch (type) {
        case RAKHO:      return "RAKHO";
        case FARMAO:     return "FARMAO";
        case POCHO:     return "POCHO";
        case AGAR:        return "AGAR";
        case WARNA:       return "WARNA";
        case JABTAK:      return "JABTAK";
        case IDENTIFIER:  return "IDENTIFIER";
        case NUMBER:      return "NUMBER";
        case STRING:      return "STRING";
        case EQUALS:      return "EQUALS";
        case PLUS:        return "PLUS";
        case MINUS:       return "MINUS";
        case STAR:        return "STAR";
        case SLASH:       return "SLASH";
        case LEFT_PAREN:  return "LEFT_PAREN";
        case RIGHT_PAREN: return "RIGHT_PAREN";
        case COLON:       return "COLON";
        case END_OF_FILE: return "EOF";
        case ERROR:       return "ERROR";
        default:          return "UNKNOWN";
    }
}