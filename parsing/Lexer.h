//
// Created by Vladyslav PALADII on 2019-10-19.
//

#ifndef AVM_LEXER_H
#define AVM_LEXER_H


#include <string>
#include <vector>
#include "Token.h"

class Lexer {
public:
    std::shared_ptr<std::vector<std::vector<Token>*>> tokenize(std::shared_ptr<std::vector<std::string>>);

private:
    std::vector<Token> *tokenize_line(std::string& line);
};


#endif //AVM_LEXER_H
