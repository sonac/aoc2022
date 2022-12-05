//
// Created by Andrii Sumko on 05.12.22.
//

#ifndef AOC2022_DAY_HPP
#define AOC2022_DAY_HPP

#include <vector>
#include <iostream>
#include "../utils/file.hpp"

class Day {
public:
    void solve() {
        std::cout << solveP1() << '\n' << solveP2() << '\n';
    }
protected:
    virtual void parseInput() = 0;
    virtual int solveP1() = 0;
    virtual int solveP2() = 0;

    void getLines(std::string filename) {
        getData(lines, filename);
    }
    std::vector<std::string> lines;
};

#endif //AOC2022_DAY_HPP
