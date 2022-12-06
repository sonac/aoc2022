//
// Created by Andrii Sumko on 06.12.22.
//

#ifndef AOC2022_DAY6_HPP
#define AOC2022_DAY6_HPP

#include "day.hpp"

class Day6 : public Day {
public:
    Day6() {
        getLines("input/day6.txt");
        data = lines[0];
    }
    int solveP1() override;
    int solveP2() override;
    void parseInput() override {};


private:
    std::string data;
};


#endif //AOC2022_DAY6_HPP
