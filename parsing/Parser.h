//
// Created by Vladyslav PALADII on 2019-10-19.
//

#ifndef AVM_PARSER_H
#define AVM_PARSER_H


#include "Token.h"
#include "../execution/Instruction.h"
#include <vector>

class Parser {
public:
    std::shared_ptr<std::vector<Instruction>> parse(std::shared_ptr<std::vector<std::vector<Token>*>> tokens);

private:
    Instruction parse_tokens(std::vector<Token> &tokens);
};


#endif //AVM_PARSER_H
