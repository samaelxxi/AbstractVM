//
// Created by Vladyslav PALADII on 2019-10-19.
//

#include "Instruction.h"
#include "../consts.h"
#include "IOperand.h"
#include <vector>
#include <iostream>
#include <cmath>

void Instruction::execute(std::vector<IOperand const *>& stack)
{
    typedef void (Instruction::*form_func)(std::vector<IOperand const *> &stack);
    static constexpr form_func m_map[] =
            {
                    &Instruction::push,
                    &Instruction::pop,
                    &Instruction::dump,
                    &Instruction::assert_,
                    &Instruction::add,
                    &Instruction::sub,
                    &Instruction::mul,
                    &Instruction::div,
                    &Instruction::mod,
                    &Instruction::print,
                    &Instruction::exit
            };

    auto idx = (std::distance(g_commands.begin(), std::find(g_commands.begin(), g_commands.end(), m_type)));
    return (this->*(m_map[idx]))(stack);
}

void Instruction::push(std::vector<IOperand const *> &stack) {
    stack.push_back(m_operand);
}

void Instruction::pop(std::vector<IOperand const *> &stack) {
    if (stack.empty())
        throw std::exception();
    stack.pop_back();
}

void Instruction::dump(std::vector<IOperand const *> &stack) {
    for (auto &op : stack)
        std::cout << op->toString() << std::endl;
}

void Instruction::assert_(std::vector<IOperand const *> &stack) {
    if (stack.empty() ||
        stack.back()->toString() != m_operand->toString() ||
        stack.back()->getType() != m_operand->getType())
        throw std::exception();
}

void Instruction::add(std::vector<IOperand const *> &stack) {
    if (stack.size() < 2)
        throw std::exception();
    auto first = stack.back();
    auto second = stack[stack.size()-2];
    stack.pop_back();
    stack.pop_back();

    auto new_elem = *first + *second;
    stack.push_back(new_elem);
}

void Instruction::sub(std::vector<IOperand const *> &stack) {
    if (stack.size() < 2)
        throw std::exception();

    auto first = stack.back();
    auto second = stack[stack.size()-2];
    stack.pop_back();
    stack.pop_back();

    auto new_elem = *first - *second;
    stack.push_back(new_elem);
}

void Instruction::mul(std::vector<IOperand const *> &stack) {
    if (stack.size() < 2)
        throw std::exception();

    auto first = stack.back();
    auto second = stack[stack.size()-2];
    stack.pop_back();
    stack.pop_back();

    auto new_elem = *first * *second;
    stack.push_back(new_elem);
}

void Instruction::div(std::vector<IOperand const *> &stack) {
    if (stack.size() < 2)
        throw std::exception();

    auto first = stack.back();
    auto second = stack[stack.size()-2];
    stack.pop_back();
    stack.pop_back();

    if (std::stod(second->toString()) == 0)
        throw std::exception();

    auto new_elem = *first / *second;
    stack.push_back(new_elem);
}

void Instruction::mod(std::vector<IOperand const *> &stack) {
    if (stack.size() < 2)
        throw std::exception();

    auto first = stack.back();
    auto second = stack[stack.size()-2];
    stack.pop_back();
    stack.pop_back();

    if (std::stod(second->toString()) == 0)
        throw std::exception();

    auto new_elem = *first % *second;
    stack.push_back(new_elem);
}

void Instruction::print(std::vector<IOperand const *> &stack) {
    if (stack.back()->getType() != eOperandType::INT8)
        throw std::exception();
    std::cout << static_cast<char>(std::stoi(stack.back()->toString()));
}

void Instruction::exit(std::vector<IOperand const *> &stack) {
    throw std::exception();
}
