/**
 * @file SCC.h
 * @author Lincoln Scheer (github.com/BikeLinc)
 * @brief Stupid C Compiler (SCC) class is used to instatiate
 * the compiling of a C source file, get the ball rolling...
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <fstream>
#include <string>

#include "Lexer.h"

/**
 * @brief SCC class orchestrates the entire compilation proccess
 * by calling each sub-system class (Lexer, Parser, etc...)
 * 
 */

class SCC {
public:
    SCC(std::string sourceFilePath);
    std::string getSourceCode(std::string path);
    void compile(std::string sourceCode);
};