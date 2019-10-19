//
// Created by Vladyslav PALADII on 2019-10-19.
//

#include <fstream>
#include "FileReader.h"

FileReader::FileReader(std::string& filename) :
        m_filename(filename)
{}

std::shared_ptr<std::vector<std::string>> FileReader::readLines() const
{
    auto lines = std::make_shared<std::vector<std::string>>();
    std::fstream fs(m_filename);

    if (!fs.good())
        return nullptr;

    std::string line;
    while (getline(fs, line)) {
        lines->push_back(line);
    }
    fs.close();

    return lines;
}
