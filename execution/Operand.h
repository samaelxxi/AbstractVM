//
// Created by Vladyslav PALADII on 2019-10-19.
//

#ifndef AVM_OPERAND_H
#define AVM_OPERAND_H

#include "IOperand.h"
#include "OperandFactory.h"
#include <cmath>

template <class T>
class Operand : public IOperand
{
public:
    Operand(T value, eOperandType type);
    ~Operand() = default;

    int getPrecision() const override ;
    eOperandType getType() const override ;

    IOperand const * operator+( IOperand const & rhs) const override ;
    IOperand const * operator-( IOperand const & rhs) const override ;
    IOperand const * operator*( IOperand const & rhs) const override ;
    IOperand const * operator/( IOperand const & rhs) const override ;
    IOperand const * operator%( IOperand const & rhs) const override ;

    std::string const & toString() const override ;

    static double getDoubleValue(IOperand const & rhs);
    static int getIntValue(IOperand const & rhs);

private:
    T m_value;
    eOperandType m_type;
    int m_precision;
    std::string const m_string_repr;
};

template<class T>
Operand<T>::Operand(T value, eOperandType type) :
    m_value(value),
    m_type(type),
    m_precision(static_cast<int>(type)),
    m_string_repr(std::to_string(m_value))
{}

template<class T>
int Operand<T>::getPrecision() const {
    return m_precision;
}

template<class T>
eOperandType Operand<T>::getType() const {
    return m_type;
}

template<class T>
IOperand const *Operand<T>::operator+(IOperand const &rhs) const
{
    eOperandType new_type = (getType() > rhs.getType()) ? getType() : rhs.getType();
    std::string val_str;
    val_str = std::to_string(m_value + Operand::getDoubleValue(rhs));
    return OperandFactory().createOperand(new_type, val_str);
}

template<class T>
IOperand const *Operand<T>::operator-(IOperand const &rhs) const {
    eOperandType new_type = (getType() > rhs.getType()) ? getType() : rhs.getType();
    std::string val_str;
    val_str = std::to_string(m_value - Operand::getDoubleValue(rhs));
    return OperandFactory().createOperand(new_type, val_str);
}

template<class T>
IOperand const *Operand<T>::operator*(IOperand const &rhs) const {
    eOperandType new_type = (getType() > rhs.getType()) ? getType() : rhs.getType();
    std::string val_str;
    val_str = std::to_string(m_value * Operand::getDoubleValue(rhs));
    return OperandFactory().createOperand(new_type, val_str);
}

template<class T>
IOperand const *Operand<T>::operator/(IOperand const &rhs) const {
    eOperandType new_type = (getType() > rhs.getType()) ? getType() : rhs.getType();
    std::string val_str;
    val_str = std::to_string(m_value / Operand::getDoubleValue(rhs));
    return OperandFactory().createOperand(new_type, val_str);
}

template<class T>
IOperand const *Operand<T>::operator%(IOperand const &rhs) const {
    eOperandType new_type = (getType() > rhs.getType()) ? getType() : rhs.getType();
    std::string val_str;
    if (new_type > eOperandType::INT32)
        val_str = std::to_string(fmod(m_value, Operand::getDoubleValue(rhs)));

    return OperandFactory().createOperand(new_type, val_str);
}

template<class T>
std::string const &Operand<T>::toString() const {
    return m_string_repr;
}

template<class T>
double Operand<T>::getDoubleValue(IOperand const &rhs) {
    return std::stod(rhs.toString());
}

template<class T>
int Operand<T>::getIntValue(IOperand const &rhs) {
    return std::stoi(rhs.toString());
}

#endif //AVM_OPERAND_H
