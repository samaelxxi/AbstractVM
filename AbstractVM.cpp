//
// Created by Vladyslav PALADII on 2019-10-19.
//

#include <fstream>
#include <iostream>
#include "AbstractVM.h"
#include "input/FileReader.h"
#include "parsing/Token.h"
#include "Instruction.h"
#include "input/CinReader.h"


void AbstractVM::runFromFile(std::string filename)
{
    FileReader reader(filename);
    run(&reader);
}

void AbstractVM::runFromCin()
{
    CinReader reader;
    run(&reader);
}

void AbstractVM::run(IInputReader *fr)
{
    auto lines = fr->readLines();
    if (lines == nullptr)
        exit(1);

    auto tokens = m_lexer.tokenize(lines);

    auto instructions = m_parser.parse(tokens);
    if (instructions == nullptr)
        exit(1);

    for (auto &instr : *instructions)
    {
        try
        {
            instr.execute(m_stack);
        }
        catch (const std::exception &exc)
        {
            std::cout << exc.what();
            break;
        }
    }
}
