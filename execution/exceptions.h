//
// Created by Vladyslav PALADII on 2019-10-22.
//

#include <stdexcept>
#include <string>

#ifndef AVM_EXCEPTIONS_H
#define AVM_EXCEPTIONS_H

#endif //AVM_EXCEPTIONS_H

class ExcWrongLineFormat : public std::logic_error {
public:
    explicit ExcWrongLineFormat(std::string const& msg) : std::logic_error(msg) { };
    char const *what() const noexcept override;
};

class ExcOverflow : public std::overflow_error {
public:
    explicit ExcOverflow(std::string const& msg) : std::overflow_error(msg) { };
    char const *what() const noexcept override;
};

class ExcUnderflow : public std::underflow_error {
public:
    explicit ExcUnderflow(std::string const& msg) : std::underflow_error(msg) { };
    char const *what() const noexcept override;
};

class ExcExit : public std::exception {};

class ExcStackIsEmpty : public std::runtime_error {
public:
    explicit ExcStackIsEmpty(std::string const& msg) : std::runtime_error(msg) { };
    char const *what() const noexcept override;
};

class ExcAssertion : public std::runtime_error {
public:
    explicit ExcAssertion(std::string const& msg) : std::runtime_error(msg) { };
    char const *what() const noexcept override;
};

class ExcZeroDivision : public std::runtime_error {
public:
    ExcZeroDivision() : std::runtime_error("") { };
    char const *what() const noexcept override;
};

class ExcPrintNonChar : public std::runtime_error {
public:
    ExcPrintNonChar() : std::runtime_error("") { };
    char const *what() const noexcept override;
};