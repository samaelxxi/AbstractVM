//
// Created by Vladyslav PALADII on 2019-10-19.
//

#ifndef AVM_OPERANDFACTORY_H
#define AVM_OPERANDFACTORY_H

#include <vector>
#include "IOperand.h"

class OperandFactory
{
public:
    IOperand const * createOperand( eOperandType type, std::string const & value ) const;

private:
    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;



};


#endif //AVM_OPERANDFACTORY_H
