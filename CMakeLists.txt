cmake_minimum_required(VERSION 3.14)
project(avm)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_FLAGS  -Wall -Wextra -Werror)


add_executable(tests tests.cpp execution/IOperand.h AbstractVM.cpp AbstractVM.h parsing/Lexer.cpp parsing/Lexer.h
        parsing/Parser.cpp parsing/Parser.h input/FileReader.cpp input/FileReader.h input/IInputReader.h
        parsing/Token.h execution/OperandFactory.cpp execution/OperandFactory.h execution/Instruction.cpp execution/Instruction.h input/CinReader.cpp
        input/CinReader.h consts.h tests.cpp)
add_executable(avm main.cpp execution/IOperand.h AbstractVM.cpp AbstractVM.h parsing/Lexer.cpp parsing/Lexer.h
        parsing/Parser.cpp parsing/Parser.h input/FileReader.cpp input/FileReader.h input/IInputReader.h
        parsing/Token.h execution/OperandFactory.cpp execution/OperandFactory.h execution/Instruction.cpp execution/Instruction.h input/CinReader.cpp
        input/CinReader.h consts.h execution/exceptions.cpp execution/Operand.h)