//
// Created by Vladyslav PALADII on 2019-10-19.
//

#include <fstream>
#include <iostream>
#include "AbstractVM.h"
#include "input/FileReader.h"
#include "parsing/Token.h"
#include "execution/Instruction.h"
#include "input/CinReader.h"
#include "execution/exceptions.h"


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
    {
        std::cout << "Some lines contain errors, execution is impossible" << std::endl;
        exit(1);
    }
    bool is_exit = false;
    for (auto &instr : *instructions)
    {
        try
        {
            instr.execute(m_stack);
        }
        catch (ExcExit &exc)
        {
            is_exit = true;
            break;
        }
        catch (const std::exception &exc)
        {
            is_exit = true;
            std::cout << exc.what() << std::endl;
            break;
        }
    }
    if (!is_exit)
        std::cout << "\033[1;31m ERROR \u001b[0m: no exit instruction" << std::endl;
}
