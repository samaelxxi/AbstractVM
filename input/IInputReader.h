//
// Created by Vladyslav PALADII on 2019-10-19.
//

#ifndef AVM_IINPUTREADER_H
#define AVM_IINPUTREADER_H

#include <string>
#include <vector>

class IInputReader
{
public:
    virtual std::shared_ptr<std::vector<std::string>> readLines() const = 0;
};

#endif //AVM_IINPUTREADER_H
