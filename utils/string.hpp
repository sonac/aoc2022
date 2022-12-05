//
// Created by Andrii Sumko on 05.12.22.
//

#ifndef AOC2022_STRING_HPP
#define AOC2022_STRING_HPP

#include <vector>
#include <sstream>

std::vector<std::string> strToVec(std::string s, char delim) {
    std::stringstream ss(s);
    std::string buf;
    std::vector<std::string> res;
    while (getline(ss, buf, delim)) {
        res.push_back(buf);
    }
    return res;
}
#endif //AOC2022_STRING_HPP
