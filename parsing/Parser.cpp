//
// Created by Vladyslav PALADII on 2019-10-19.
//

#include <iostream>
#include "Parser.h"
#include "../execution/OperandFactory.h"
#include "../consts.h"
#include "../execution/exceptions.h"

std::shared_ptr<std::vector<Instruction>> Parser::parse(std::shared_ptr<std::vector<std::vector<Token>*>> tokens)
{
    auto instructions = std::make_shared<std::vector<Instruction>>();

    bool is_correct = true;
    for (auto &toks : *tokens)
    {
        try {
            auto instr = parse_tokens(*toks);
            instructions->push_back(instr);
        }
        catch (const std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
            is_correct = false;
        }
    }
    if (is_correct)
        return instructions;
    return nullptr;
}

std::string tokensToString(std::vector<Token> &tokens)
{
    std::string res;
    for (auto &token : tokens)
    {
        res += token.m_value;
        res += ' ';
    }
    return res;
}

Instruction Parser::parse_tokens(std::vector<Token> &tokens) {
    // first token always command
    if (tokens[0].m_type != TokenType::COMMAND)
        throw ExcWrongLineFormat(tokensToString(tokens));

    // if command takes value but only one token
    if (std::find(g_value_commands.begin(), g_value_commands.end(), tokens[0].m_value) != g_value_commands.end() &&
        tokens.size() == 1)
        throw ExcWrongLineFormat(tokensToString(tokens));


    if (tokens.size() == 1)
        return Instruction(tokens[0].m_value, nullptr);

    // Only 1 or 3 tokens possible
    if (tokens.size() != 3)
        throw ExcWrongLineFormat(tokensToString(tokens));


    // if 3, then command should take value
    if (std::find(g_value_commands.begin(), g_value_commands.end(), tokens[0].m_value) == g_value_commands.end())
        throw ExcWrongLineFormat(tokensToString(tokens));

    // second token is operand and third is literal
    if (tokens[1].m_type != TokenType::OPERAND || (tokens[2].m_type != TokenType::INT_LITERAL &&
                                                   tokens[2].m_type != TokenType::FLOAT_LITERAL))
        throw ExcWrongLineFormat(tokensToString(tokens));

    // int operands can't support float literals
    if ((tokens[1].m_value == "int8" || tokens[1].m_value == "int16" || tokens[1].m_value == "int32") &&
            tokens[2].m_type == TokenType::FLOAT_LITERAL)
        throw ExcWrongLineFormat(tokensToString(tokens));


    auto type = static_cast<eOperandType>(std::distance(g_operands.begin(), std::find(g_operands.begin(), g_operands.end(), tokens[1].m_value)));
    std::string literal = tokens[2].m_value.substr(1, tokens[2].m_value.size()-2);
    return Instruction(tokens[0].m_value, OperandFactory().createOperand(type, literal));
}
