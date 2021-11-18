/**
 * @file Token.cpp
 * @author Lincoln Scheer (https://github.com/BikeLinc/)
 * @brief Contains token related classes to be generated by 
 * the Lexer when the source code is converted into tokens.
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Token.h"

/**
 * @brief Construct a new Token:: Token object
 * 
 * @param type 
 * @param value 
 * @param rowPosition 
 * @param colPosition 
 */
Token::Token(TokenType type, std::string value, int rowPosition, int colPosition) {
    this->m_type = type;
    this->m_value = value;
    this->m_rowPosition = rowPosition;
    this->m_colPosition = colPosition;
}

/**
 * @brief Return Token's TokenType
 * 
 * @return TokenType 
 */
TokenType Token::getType() {
    return m_type;
}

/**
 * @brief Return Token's value
 * 
 * @return std::string 
 */
std::string Token::getValue() {
    return m_value;
}

/**
 * @brief Return Token's row position in the source file
 * 
 * @return int 
 */
int Token::getRowPosition() {
    return m_rowPosition;
}

/**
 * @brief Return Token's col position in the source file
 * 
 * @return int 
 */
int Token::getColPosition() {
    return m_colPosition;
}