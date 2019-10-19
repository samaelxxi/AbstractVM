//
// Created by Vladyslav PALADII on 2019-10-19.
//

#include <iostream>
#include <cassert>
#include "parsing/Lexer.h"
#include "input/FileReader.h"
#include "parsing/Parser.h"

void lexerTests()
{
    std::cout << "Lexer tests:" << std::endl;

    Lexer l;

    auto tokenize = [&](std::string s)
            {
        auto p = std::make_shared<std::vector<std::string>>();
        p->push_back(s);
        return l.tokenize(p);
            };

    auto check = [&](std::vector<Token> res, std::vector<Token> correct)
    {
        if (res.size() != correct.size())
        {
            std::cout << "Different size" << std::endl;
            return false;
        }
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i].m_type != correct[i].m_type ||
                res[i].m_value != correct[i].m_value)
            {
                std::cout << "Token [" << i << "] doesn't match" << std::endl;
                return false;
            }
        }
        return true;
    };

    auto test = [&](std::string inp, std::vector<Token> out)
    {
        std::cout << "Testing : " << inp << "     ";
        auto res = tokenize(inp);
        if (check(*((*res)[0]), out))
            std::cout << " || WORKS" << std::endl;
        else
            std::cout << " || FAIL" << std::endl;
    };

    test("push 42", {{TokenType::COMMAND, "push"}, {TokenType::ERROR, "42"}});
    test("pus int8(42)", {{TokenType::ERROR, "pus"}, {TokenType::OPERAND, "int8"}, {TokenType::INT_LITERAL, "(42)"}});
    test("double(42.42)", {{TokenType::OPERAND, "double"}, {TokenType::FLOAT_LITERAL, "(42.42)"}});
    test("double(4242)", {{TokenType::OPERAND, "double"}, {TokenType::INT_LITERAL, "(4242)"}});
    test("assert double(42.l2)", {{TokenType::COMMAND, "assert"}, {TokenType::OPERAND, "double"}, {TokenType::ERROR, "(42.l2)"}});
    test("push 42 ; error :)", {{TokenType::COMMAND, "push"}, {TokenType::ERROR, "42"}});
    test("push 42; error :)", {{TokenType::COMMAND, "push"}, {TokenType::ERROR, "42"}});
    test("push int32(42)", {{TokenType::COMMAND, "push"}, {TokenType::OPERAND, "int32"}, {TokenType::INT_LITERAL, "(42)"}});
    test("pop int32(42.1) kjkl hel;o", {{TokenType::COMMAND, "pop"}, {TokenType::OPERAND, "int32"}, {TokenType::FLOAT_LITERAL, "(42.1)"},
                                        {TokenType::ERROR, "kjkl"}, {TokenType::ERROR, "hel"}});

    std::cout << std::endl;
}

void parserTests()
{
    std::cout << "Parser tests: " << std::endl;

    Lexer l;
    Parser p;

    auto prepare = [&](std::string s)
    {
        auto t = std::make_shared<std::vector<std::string>>();
        t->push_back(s);
        return p.parse(l.tokenize(t));
    };

    auto output_test = [&](std::string s) { ;
        auto t = prepare(s);
        std::cout << "Input: " << s << " || RES: ";
        for (auto &i : *t) {
            std::string val = (i.getOperand()) ? i.getOperand()->toString() : "null";
            std::cout << "Instr: " << i.getType() << " | Value: " << val;
        }
        std::cout << std::endl;
    };

    auto exception_test = [&](std::string s)
    {
        std::cout << "Input: " << s << " || RES: ";
        try {
            auto t = prepare(s);
        }
        catch (const std::exception &exc)
        {
            std::cout << exc.what();
            return;
        }
        std::cout << std::endl;
    };

    output_test("push int8(42)");
    exception_test("pop int32(42) hello");
    exception_test("pop int32(42.42)");
    exception_test("pop int32(42)");
    exception_test("int32(42)");
    exception_test("(42)");
    exception_test("push (42)");

}

int main()
{
    lexerTests();
    parserTests();
}