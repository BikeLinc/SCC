/**
 * @file Lexer.h
 * @author Lincoln Scheer (https://github.com/BikeLinc/)
 * @brief Lexer takes very simple C programs and compiles them
 * into assembly programs in order to generate executables
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <vector>
#include <iostream>
#include <string>
#include <cctype>

#include "Token.h"

class Lexer {
public:
    Lexer(std::string sourceCode);
    void tokenize();
    std::vector<Token> getTokens();
private:
    std::vector<Token> tokens;
    std::string source;
    std::string literalBuffer = ""; // Holds A->Z
    std::string numberBuffer = ""; // Holds 0->9 & '.'
    bool escapeSequence = false;
    int row = 1;
    int col = 0;
    void generateToken(TokenType type, std::string value, int rowPosition, int colPosition);
    bool isOperator(char character);
    bool isKeyword(std::string string);
    void doEscapeSequence(char character);
    void pushFilledLiteralBuffer();
    void pushFilledNumberBuffer();
    void pushFilledBuffers();
};