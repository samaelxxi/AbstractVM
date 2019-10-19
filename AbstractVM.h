//
// Created by Vladyslav PALADII on 2019-10-19.
//

#ifndef AVM_ABSTRACTVM_H
#define AVM_ABSTRACTVM_H


#include "parsing/Lexer.h"
#include "parsing/Parser.h"
#include "execution/IOperand.h"
#include "input/IInputReader.h"
#include <vector>


class AbstractVM {

public:
    AbstractVM() = default;
    ~AbstractVM() = default;
    AbstractVM(AbstractVM& other) = delete;
    AbstractVM &operator=(AbstractVM &other) = delete;

    void runFromCin();
    void runFromFile(std::string filename);
    void run(IInputReader *);

private:
    Lexer m_lexer;
    Parser m_parser;
    std::vector<IOperand const *> m_stack;

};


#endif //AVM_ABSTRACTVM_H
