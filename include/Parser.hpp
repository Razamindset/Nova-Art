#pragma once 

#include "Lexer.hpp"
#include"AST.hpp"
#include<memory>
#include<vector>


// The the current location in the tokens..
// Provide the methods to consume and process the next tokens
class Parser {
    public:
        Parser(const std::vector<Token>& tokens);

        // The main entry point for our application
        std::unique_ptr<ProgramNode> parse();
    
    private:
        std::vector<Token> tokens;
        int current = 0;

        // Grammer rules
        std::unique_ptr<Node> parseStatement();
        std::unique_ptr<Node> parseVarDec();
        std::unique_ptr<Node> parsePrint();
        std::unique_ptr<Node> parsePocho();

        // helper methods
        bool match(TokenType token); // Check if the current token is of the type
        Token consume(TokenType, std::string message); 
        bool check(TokenType type); // Look a the token wihtout consuming it 
        Token advance();
        Token peek();
        bool isAtEnd();
};