//
// Created by Vladyslav PALADII on 2019-10-19.
//

#ifndef AVM_TOKEN_H
#define AVM_TOKEN_H

#include <string>

enum class TokenType
{
    COMMAND,
    OPERAND,
    INT_LITERAL,
    FLOAT_LITERAL,
    ERROR
};

struct Token
{
    enum TokenType m_type;
    std::string m_value;
};

#endif //AVM_TOKEN_H
