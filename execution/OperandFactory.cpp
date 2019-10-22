//
// Created by Vladyslav PALADII on 2019-10-19.
//

#include "OperandFactory.h"
#include "Operand.h"
#include "IOperand.h"
#include "exceptions.h"
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
    try {
        double val = std::stod(value);
        return new Operand<double>(val, eOperandType::DOUBLE);
    }
    catch (std::exception &exc)
    {
        throw ExcOverflow(value);
    }
}

IOperand const *OperandFactory::createFloat(std::string const &value) const {
    auto *ptr = value.data();
    errno = 0;
    char *end;
    float val = std::strtof(ptr, &end);

    if (errno == ERANGE)
        throw ExcOverflow(value);
    return new Operand<float>(val, eOperandType::FLOAT);
}

IOperand const *OperandFactory::createInt32(std::string const &value) const {
    try {
        double val = std::stod(value);

        if (val > std::numeric_limits<int32_t>::max())
            throw ExcOverflow(value);
        else if (val < std::numeric_limits<int32_t>::min())
            throw ExcUnderflow(value);

        return new Operand<int32_t>(val, eOperandType::INT32);
    }
    catch (std::exception &exc)
    {
        throw ExcOverflow(value);
    }
}

#include <iostream>
IOperand const *OperandFactory::createInt16(std::string const &value) const {
    try {
        double val = std::stod(value);

        if (val > std::numeric_limits<int16_t>::max())
            throw ExcOverflow(value);
        else if (val < std::numeric_limits<int16_t>::min())
            throw ExcUnderflow(value);

    return new Operand<int16_t>(val, eOperandType::INT16);
    }
    catch (std::exception &exc)
    {
        throw ExcOverflow(value);
    }
}

IOperand const *OperandFactory::createInt8(std::string const &value) const {
    try {
        double val = std::stod(value);

        if (val > std::numeric_limits<int8_t>::max())
            throw ExcOverflow(value);
        else if (val < std::numeric_limits<int8_t>::min())
            throw ExcUnderflow(value);

        return new Operand<int8_t>(val, eOperandType::INT8);   
    }
    catch (std::exception &exc)
    {
        throw ExcOverflow(value);
    }
}
