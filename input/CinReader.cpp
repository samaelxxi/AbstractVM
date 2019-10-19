//
// Created by Vladyslav PALADII on 2019-10-19.
//

#include <iostream>
#include "CinReader.h"

std::shared_ptr<std::vector<std::string>> CinReader::readLines() const {
    auto lines = std::make_shared<std::vector<std::string>>();


    std::string line;
    while (true) {
        std::cin >> line;
        if (line == ";;")
            break;
        lines->push_back(line);
    }

    for (auto &l : *lines)
        std::cout << l << std::endl;

    return lines;
}
