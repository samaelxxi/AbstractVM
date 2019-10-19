//
// Created by Vladyslav PALADII on 2019-10-19.
//

#ifndef AVM_FILEREADER_H
#define AVM_FILEREADER_H


#include "IInputReader.h"

class FileReader: public IInputReader
{
public:
    explicit FileReader(std::string& filename);
    std::shared_ptr<std::vector<std::string>> readLines() const override;

    ~FileReader() = default;
    FileReader(FileReader& other) = delete;
    FileReader &operator=(FileReader &other) = delete;

private:
    std::string m_filename;
};


#endif //AVM_FILEREADER_H
