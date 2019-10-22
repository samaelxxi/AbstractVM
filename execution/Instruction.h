//
// Created by Vladyslav PALADII on 2019-10-19.
//

#ifndef AVM_INSTRUCTION_H
#define AVM_INSTRUCTION_H


#include <string>
#include "IOperand.h"

class Instruction
{
public:
    void execute(std::vector<IOperand const *>& stack);
    Instruction(std::string& type, IOperand const *operand):
        m_type(type), m_operand(operand) {};
    Instruction(const Instruction & other): m_type(other.m_type), m_operand(other.m_operand) {};

    std::string getType() { return m_type; };
    IOperand const *getOperand() {return m_operand;}

private:
    void push(std::vector<IOperand const *>& stack);
    void pop(std::vector<IOperand const *>& stack);
    void dump(std::vector<IOperand const *>& stack);
    void assert_(std::vector<IOperand const *>& stack);
    void add(std::vector<IOperand const *>& stack);
    void sub(std::vector<IOperand const *>& stack);
    void mul(std::vector<IOperand const *>& stack);
    void div(std::vector<IOperand const *>& stack);
    void mod(std::vector<IOperand const *>& stack);
    void print(std::vector<IOperand const *>& stack);
    void exit(std::vector<IOperand const *>& stack);
    void pow(std::vector<IOperand const *> &stack);
    void and_(std::vector<IOperand const *> &stack);
    void or_(std::vector<IOperand const *> &stack);
    void xor_(std::vector<IOperand const *> &stack);

    std::string m_type;
    IOperand const *m_operand;
};


#endif //AVM_INSTRUCTION_H
