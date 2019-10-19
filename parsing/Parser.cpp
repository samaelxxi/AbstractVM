//
// Created by Vladyslav PALADII on 2019-10-19.
//

#include <iostream>
#include "Parser.h"
#include "../OperandFactory.h"
#include "../consts.h"

std::shared_ptr<std::vector<Instruction>> Parser::parse(std::shared_ptr<std::vector<std::vector<Token>*>> tokens)
{
    auto instructions = std::make_shared<std::vector<Instruction>>();

    for (auto &toks : *tokens)
    {
        try {
            auto instr = parse_tokens(*toks);
            instructions->push_back(instr);
        }
        catch (const std::exception &exc)
        {
            std::cout << exc.what();
        }
    }

    return instructions;
}

Instruction Parser::parse_tokens(std::vector<Token> &tokens) {
    // first token always command
    if (tokens[0].m_type != TokenType::COMMAND)
        throw std::exception();
    if (tokens.size() == 1)
        return Instruction(tokens[0].m_value, nullptr);

    // Only 1 or 3 tokens possible
    if (tokens.size() != 3)
        throw std::exception();

    // if 3, then command should take value
    if (std::find(g_value_commands.begin(), g_value_commands.end(), tokens[0].m_value) == g_value_commands.end())
        throw std::exception();

    // second token is operand and third is literal
    if (tokens[1].m_type != TokenType::OPERAND || (tokens[2].m_type != TokenType::INT_LITERAL &&
                                                   tokens[2].m_type != TokenType::FLOAT_LITERAL))
        throw std::exception();

    // int operands can't support float literals
    if ((tokens[1].m_value == "int8" || tokens[1].m_value == "int16" || tokens[1].m_value == "int32") &&
            tokens[2].m_type == TokenType::FLOAT_LITERAL)
        throw std::exception();


    auto type = static_cast<eOperandType>(std::distance(g_operands.begin(), std::find(g_operands.begin(), g_operands.end(), tokens[1].m_value)));
    std::string literal = tokens[2].m_value.substr(1, tokens[2].m_value.size()-2);
    return Instruction(tokens[0].m_value, OperandFactory().createOperand(type, literal));
}
