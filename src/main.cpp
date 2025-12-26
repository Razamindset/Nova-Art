#include "Lexer.hpp"
#include "Utils.hpp"
#include "Parser.hpp"
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

    Parser parser(tokens);
    auto program = parser.parse();
    
    std::string cppCode = program->transpile();

    // std::cout << "--- Transpiled C++ Code ---\n" << cppCode << std::endl;


    // The the transpiled c++ code
    std::string outFileName = "output.cpp";
    std::ofstream outFile(outFileName);
    outFile << cppCode;
    outFile.close();
    std::cout << "[Step 1] C++ code generated in output.cpp" << std::endl;

    // Compile the generated code....
    std::cout << "[Step 2] Compiling..." << std::endl;
    int compileResult = std::system("g++ output.cpp -o app.exe");

    if(compileResult == 0){
        std::cout << "[Step 3] Success! Running your program:\n";
        std::cout << "---------------------------------------" << std::endl << std::endl;
        std::system(".\\app.exe");
    } else {
        std::cerr << "[Error] Compilation failed!" << std::endl;
    }


    return 0;
}