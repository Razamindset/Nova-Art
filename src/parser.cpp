#include "../include/Parser.hpp"
#include<memory>
#include<iostream>

Parser::Parser(const std::vector<Token>& t) : tokens(t), current(0) {}

std::unique_ptr<ProgramNode> Parser::parse(){
    auto program = std::make_unique<ProgramNode>();

    while (!isAtEnd()){
        auto stm = parseStatement();

        if(stm){
            program->statements.push_back(std::move(stm));
        }
    }

    return program;
}

std::unique_ptr<Node> Parser::parseStatement(){
    // Check which grammer to follow
    if(match(RAKHO)) return parseVarDec();
    if(match(FARMAO)) return parsePrint();
    if(match(POCHO)) return parsePocho();
    if(match(AGAR)) return parseConditional();

    // If we don't recognize the token
    if(!isAtEnd()){
        std::cerr << "Ghalti (Line " << peek().line << "): '" 
                  << peek().lexeme << "' samajh nahi aaya." << std::endl;
        advance();
    }

    return nullptr;
}

std::unique_ptr<Node> Parser::parseVarDec(){
    Token name = consume(IDENTIFIER, "Looking for variable name");

    consume(EQUALS, "'=' is needed");

    Token value = advance();

    return std::make_unique<VarDeclNode>(name.lexeme, value.lexeme);
}

std::unique_ptr<Node> Parser::parsePrint(){
    Token value = advance();
    bool isStr = (value.type == STRING);
    return std::make_unique<PrintNode>(value.lexeme, isStr);
}

std::unique_ptr<Node> Parser::parsePocho(){
    Token name = consume(IDENTIFIER, "Need variable name after Pocho");

    return std::make_unique<InputNode>(name.lexeme);
}

std::unique_ptr<Node> Parser::parseConditional(){
    // Conditional header
    consume(LEFT_PAREN, "Expected: ( after agar");
    Token value1 = consume(IDENTIFIER, "Expected: first value for evluation");

    consume(COMPARISON, "Expected == (comparison operator) after Identifier.");

    // Could be identifier or a number or string
    Token value2 = advance();

    consume(RIGHT_PAREN, "Expected: ) to end the conditional.");
    consume(LEFT_BRAKET, "Expected: { to start the If body");

    // body for the conditional
    
    auto content  = std::make_unique<ConditionalContentNode>();
    while (!check(RIGHT_BRAKET) && !isAtEnd()){
        auto stm = parseStatement();

        if(stm){
            content->statements.push_back(std::move(stm));
        }
    }

    // Closing parans
    consume(RIGHT_BRAKET, "Expected: } for ending the conditional");

    // Create the node with this data...
    return std::make_unique<ConditionNode>(value1.lexeme, value2.lexeme, std::move(content));
}

// helpers
Token Parser::consume(TokenType type, std::string message){
    if(check(type)) return advance();

    // In a real compiler, you'd throw an exception here
    std::cerr << "Ghalti (Line " << peek().line << "): " << message << std::endl;
    return Token{ERROR, "", peek().line};
}


bool Parser::match(TokenType type){
    if(check(type)) {
        advance();
        return true;
    }

    return false;
}

bool Parser::check(TokenType type){
    if(isAtEnd()) return false;
    return peek().type == type;
}

Token Parser::advance(){
    if(!isAtEnd()) current++;
    return tokens[current - 1];
}

Token Parser::peek(){
    return tokens[current];
}

bool Parser::isAtEnd(){
    return tokens[current].type == END_OF_FILE;
}