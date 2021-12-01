/**
 * @file SCC.cpp
 * @author Lincoln Scheer (github.com/BikeLinc)
 * @brief Stupid C Compiler (SCC) class is used to instatiate
 * the compiling of a C source file, get the ball rolling...
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "SCC.h"

SCC::SCC(std::string sourceFilePath) {
    std::string sourceCode;
    sourceCode = getSourceCode(sourceFilePath);

    compile(sourceCode);
}

std::string SCC::getSourceCode(std::string path) {
    std::ifstream file(path);
    std::string line;
    std::string sourceCode = "";

    // Does file exits?
    if(!file.is_open()) {
        std::cout << "Directory or File does not exitst: " << path << std::endl;
    }

    // Add lines to string
    while (std::getline(file, line)) {
        sourceCode += line;
        sourceCode += "\\n";
    }

    return sourceCode;
}

void SCC::compile(std::string sourceCode) {
    // Lexer
    Lexer lexer = Lexer(sourceCode);
    lexer.tokenize();
    // Parser

    // AST

    // Code Generation
}