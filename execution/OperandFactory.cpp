//
// Created by Vladyslav PALADII on 2019-10-19.
//

#include "OperandFactory.h"
#include "Operand.h"
#include "IOperand.h"
#include <vector>
#include <sstream>



IOperand const *OperandFactory::createOperand(eOperandType type, std::string const &value) const
{
    typedef IOperand const * (OperandFactory::*form_func)(std::string const &value) const;
    static constexpr form_func m_map[] =
            {
                    &OperandFactory::createInt8,
                    &OperandFactory::createInt16,
                    &OperandFactory::createInt32,
                    &OperandFactory::createFloat,
                    &OperandFactory::createDouble
            };

    return (this->*(m_map[static_cast<int>(type)]))(value);
}

IOperand const *OperandFactory::createDouble(std::string const &value) const {
    double val = std::stod(value);

    return new Operand<double>(val, eOperandType::DOUBLE);
}

IOperand const *OperandFactory::createFloat(std::string const &value) const {
    auto *ptr = value.data();
    errno = 0;
    char *end;
    float val = std::strtof(ptr, &end);

    if (errno == ERANGE)
        throw std::out_of_range("stof argument out of range");
    return new Operand<float>(val, eOperandType::FLOAT);
}

IOperand const *OperandFactory::createInt32(std::string const &value) const {
    long val = std::stoi(value);

    if (val > INT32_MAX || val < INT32_MIN)
        throw std::exception();

    return new Operand<int32_t>(val, eOperandType::INT32);
}

IOperand const *OperandFactory::createInt16(std::string const &value) const {
    long val = std::stoi(value);

    if (val > INT16_MAX || val < INT16_MIN)
        throw std::exception();

    return new Operand<int16_t>(val, eOperandType::INT16);
}

IOperand const *OperandFactory::createInt8(std::string const &value) const {
    long val = std::stoi(value);

    if (val > INT8_MAX || val < INT8_MIN)
        throw std::exception();

    return new Operand<int8_t>(val, eOperandType::INT8);
}
