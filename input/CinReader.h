//
// Created by Vladyslav PALADII on 2019-10-19.
//

#ifndef AVM_CINREADER_H
#define AVM_CINREADER_H


#include "IInputReader.h"

class CinReader : public IInputReader
{
    std::shared_ptr<std::vector<std::string>> readLines() const override;
};


#endif //AVM_CINREADER_H
