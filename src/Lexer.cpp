/**
 * @file Lexer.cpp
 * @author Lincoln Scheer (https://github.com/BikeLinc/)
 * @brief Lexer takes very simple C programs and compiles them
 * into assembly programs in order to generate executables
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Lexer.h"

Lexer::Lexer(std::string sourceCode) {
    this->source = sourceCode;
}

void Lexer::tokenize() {

    for(int index = 0; index < source.length(); index++) {
        char character = source[index];
        col++;
        if (isalpha(character)) {
            if(!escapeSequence) {
                literalBuffer += character;
            } else {
                doEscapeSequence(character);
                escapeSequence = false;
            }
        } else if (isnumber(character) || character == '.') {
            pushFilledLiteralBuffer();
            numberBuffer += character;
        } else if (isOperator(character)) {
            pushFilledBuffers();
            generateToken(OPERATOR, std::string(1, character), row, col);
        } else if (character == '\\') {
            escapeSequence = true;
        } else {
            pushFilledBuffers();
        }
    }

    for(int i = 0; i < tokens.size(); i++) {
        Token token = tokens[i];
        std::cout << "( " << token.getType() << " : \'" << token.getValue()  << "\' ) ";
    }
    /*
        if character is letter
            if escapeSequence
                -> do escape sequence behavior
                    -> n 
                        push filled buffers
                        row++
                -> escapeSequence = false
            else
                -> add character to literal buffer
        else if character is number
            -> push filled literal buffer
            -> add character to number buffer
        else if character is operator
            -> push all filled buffers
            -> generate operator token
        else if character is \
            -> escapeSequence = true
        else 
            -> push all filled buffers
        */
    /*

       lit:

       num: 

       seq: K_int, I_main, O_(, O-), O_{, K_return, C_2, O_;, 

       */
}

std::vector<Token> Lexer::getTokens() {
    return tokens;
}

void Lexer::generateToken(TokenType type, std::string value, int rowPosition, int colPosition) {
    Token token(type, value, rowPosition, colPosition);
    tokens.push_back(token);
}

bool Lexer::isOperator(char character) {
    return ((character == '(')||(character == ')')||(character == '{')||(character == '}')||(character == ';')||(character == ')'));
}

bool Lexer::isKeyword(std::string string) {
    return ((string == "int")||(string == "return"));
}

void Lexer::doEscapeSequence(char character) {
    if(character == 'n') {
        pushFilledBuffers();
        row++;
        col = 0;
    }
}

void Lexer::pushFilledLiteralBuffer() {
    if(literalBuffer != "") {
        if(isKeyword(literalBuffer)) {
            generateToken(KEYWORD, literalBuffer, row, (col - literalBuffer.size()));
        } else {
            generateToken(IDENTIFIER, literalBuffer, row, (col - literalBuffer.size()));
        }
        literalBuffer = "";
    }
}

void Lexer::pushFilledNumberBuffer() {
    if(numberBuffer != "") {
        generateToken(CONSTANT, numberBuffer, row, (col - numberBuffer.size()));
        numberBuffer = "";
    }
}

void Lexer::pushFilledBuffers() {
    pushFilledLiteralBuffer();
    pushFilledNumberBuffer();
}