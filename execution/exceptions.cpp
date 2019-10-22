//
// Created by Vladyslav PALADII on 2019-10-19.
//

#include "exceptions.h"

char const *ExcWrongLineFormat::what() const noexcept {
    return (std::string("\033[1;31m Wrong line format:  \033[0m") + std::string(logic_error::what())).data();
}

char const *ExcOverflow::what() const noexcept {
    return (std::string("\033[1;35mOverflow\033[0m during creating of ") + overflow_error::what()).data();
}

char const *ExcUnderflow::what() const noexcept {
    return (std::string("\033[1;36mUnderflow\033[0m during creating of ") + underflow_error::what()).data();
}

char const *ExcStackIsEmpty::what() const noexcept {
    return (std::string("\033[1;31m ERROR \033[0m: Stack is empty before instruction : ") + runtime_error::what()).data();
}

char const *ExcAssertion::what() const noexcept {
    return (std::string("Assertion error : ") + runtime_error::what()).data();
}

char const *ExcZeroDivision::what() const noexcept {
    return "\033[1;31m ERROR \033[0m: trying to blow world(divide by zero)";
}

char const *ExcPrintNonChar::what() const noexcept {
    return "\033[1;31m ERROR \033[0m: can't print non int8 type";
}
