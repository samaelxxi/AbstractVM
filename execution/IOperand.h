//
// Created by Vladyslav PALADII on 2019-10-19.
//

#ifndef AVM_IOPERAND_H
#define AVM_IOPERAND_H

#include <string>

enum class eOperandType
{
    INT8 = 0,
    INT16 = 1,
    INT32 = 2,
    FLOAT = 3,
    DOUBLE = 4
};

class IOperand

{
public:
    virtual int getPrecision() const = 0;
    virtual eOperandType getType() const = 0;

    virtual IOperand const * operator+( IOperand const & rhs) const = 0;
    virtual IOperand const * operator-( IOperand const & rhs) const = 0;
    virtual IOperand const * operator*( IOperand const & rhs) const = 0;
    virtual IOperand const * operator/( IOperand const & rhs) const = 0;
    virtual IOperand const * operator%( IOperand const & rhs) const = 0;
    virtual IOperand const * operator|( IOperand const & rhs) const = 0;
    virtual IOperand const * operator||( IOperand const & rhs) const = 0;
    virtual IOperand const * operator&( IOperand const & rhs) const = 0;
    virtual IOperand const * operator^( IOperand const & rhs) const = 0;
    // Precision of the type of the instance

    virtual std::string const & toString() const = 0;
    virtual ~IOperand() = default;

};

#endif //AVM_IOPERAND_H
