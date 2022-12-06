//
// Created by Andrii Sumko on 06.12.22.
//

#include "day6.hpp"

#include <queue>
#include <set>

bool isUq(std::string str, int sz) {
    std::set<char> s;
    for (const char& c: str)
        s.insert(c);
    return s.size() == sz;
}

int Day6::solveP1() {
    for (int i = 4; i < data.size(); i++) {
        if (isUq(data.substr(i - 4, 4), 4)) {
            return i;
        }
    }
    return 0;
}

int Day6::solveP2() {
    for (int i = 14; i < data.size(); i++) {
        if (isUq(data.substr(i - 14, 14), 14)) {
            return i;
        }
    }
    return 0;
}
