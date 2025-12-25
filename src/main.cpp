#include "Lexer.hpp"
#include "Utils.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// Arg count and arag value
int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cerr << "Usage: Pfproject file.urdu" << std::endl;
    }

    std::string filename = argv[1];

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: File not found!" << std::endl;
    }

    std::cout << "Starting Nova-Art Transpiler!" << std::endl;

    // let us start by printing the content of the loaded file
    std::stringstream buffer;
    buffer << file.rdbuf();

    Lexer lexer(buffer.str());
    std::vector<Token> tokens = lexer.scanTokens();

    for (const auto &token : tokens) {
        std::cout << "Type: " << tokenTypeToString(token.type) << " | Value: [" << token.lexeme
                  << "]"
                  << " | Line: " << token.line << std::endl;
    }

    // std::cout<< "File Content: \n"<< buffer.str()<< std::endl;

    return 0;
}