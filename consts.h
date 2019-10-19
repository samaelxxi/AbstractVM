//
// Created by Vladyslav PALADII on 2019-10-19.
//

#ifndef AVM_CONSTS_H
#define AVM_CONSTS_H

#include <string>
#include <array>

constexpr int commands_num = 11;

static std::array<std::string, commands_num> g_commands
{
    "push",
    "pop",
    "dump",
    "assert",
    "add",
    "sub",
    "mul",
    "div",
    "mod",
    "print",
    "exit"
};

static std::array<std::string, commands_num> g_value_commands
{
    "push",
    "assert",
};

static std::array<std::string, 5> g_operands =
{
    "int8",
    "int16",
    "int32",
    "float",
    "double"
};

#endif //AVM_CONSTS_H
