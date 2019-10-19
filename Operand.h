//
// Created by Vladyslav PALADII on 2019-10-19.
//

#ifndef AVM_OPERAND_H
#define AVM_OPERAND_H


#include "IOperand.h"

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
IOperand const *Operand<T>::operator+(IOperand const &rhs) const {
    return nullptr;
}

template<class T>
IOperand const *Operand<T>::operator-(IOperand const &rhs) const {
    return nullptr;
}

template<class T>
IOperand const *Operand<T>::operator*(IOperand const &rhs) const {
    return nullptr;
}

template<class T>
IOperand const *Operand<T>::operator/(IOperand const &rhs) const {
    return nullptr;
}

template<class T>
IOperand const *Operand<T>::operator%(IOperand const &rhs) const {
    return nullptr;
}

template<class T>
std::string const &Operand<T>::toString() const {
    return m_string_repr;
}



#endif //AVM_OPERAND_H
