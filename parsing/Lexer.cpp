//
// Created by Vladyslav PALADII on 2019-10-19.
//

#include <sstream>
#include "Lexer.h"
#include "../consts.h"
#include <algorithm>


bool isFloat( std::string myString ) {
    std::istringstream iss(myString);
    float f;
    iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

bool isInt( std::string myString ) {
    std::istringstream iss(myString);
    int f;
    iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}


std::shared_ptr<std::vector<std::vector<Token>*>> Lexer::tokenize(std::shared_ptr<std::vector<std::string>> lines)
{
    auto tokens = std::make_shared<std::vector<std::vector<Token>*>>();

    for (auto &line : *lines)
    {
        auto token_vect = tokenize_line(line);
        tokens->push_back(token_vect);
    }

    return tokens;
}

std::vector<Token> *Lexer::tokenize_line(std::string &line) {
    auto token_vect = new std::vector<Token>();


    std::istringstream iss(line);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());

    int word_idx = 0;
    std::string next_word = words[word_idx];
    while (word_idx < words.size())
    {
        bool new_word = false;
        // Check if comment
        size_t comment_idx = next_word.find(';');
        if (comment_idx != std::string::npos)
        {
            next_word = next_word.substr(0, comment_idx);
            word_idx = words.size();
        }
        if (next_word.empty())
        {
            word_idx++;
            next_word = words[word_idx];
            continue;
        }
        // Check for OPERAND token
        bool operand = false;
        for (auto &op_lit : g_operands)
        {
            if (next_word.rfind(op_lit, 0) == 0)
            {
                token_vect->push_back({TokenType::OPERAND, op_lit});
                next_word = next_word.substr(op_lit.size(), next_word.size());
                operand = true;
                break;
            }
        }
        if (operand)
            continue;
        // Check for COMMAND token
        bool command = false;
        for (auto &comm : g_commands) {
            if (next_word.rfind(comm, 0) == 0) {
                token_vect->push_back({TokenType::COMMAND, comm});
                next_word = next_word.substr(comm.size(), next_word.size());
                command = true;
                break;
            }
        }
        if (command)
            continue;

        // Check for INT or FLOAT
        if (next_word[0] == '(' && next_word[next_word.size()-1] == ')')
        {
            if (isInt(next_word.substr(1, next_word.size() -2)))
                token_vect->push_back({TokenType::INT_LITERAL, next_word});
            else if (isFloat(next_word.substr(1, next_word.size() -2)))
                token_vect->push_back({TokenType::FLOAT_LITERAL, next_word});
            else
                token_vect->push_back({TokenType::ERROR, next_word});
        }
        else  // ERROR CASE
            token_vect->push_back({TokenType::ERROR, next_word});
        word_idx++;
        next_word = words[word_idx];
    }

    return token_vect;
}
