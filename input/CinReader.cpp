//
// Created by Vladyslav PALADII on 2019-10-19.
//

#include <iostream>
#include "CinReader.h"

std::shared_ptr<std::vector<std::string>> CinReader::readLines() const {
    auto lines = std::make_shared<std::vector<std::string>>();

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == ";;") {
            lines->push_back("exit");
            break;
        }
        lines->push_back(line);
    }

    return lines;
}
