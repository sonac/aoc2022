//
// Created by Andrii Sumko on 03.12.22.
//

#ifndef AOC2022_DAY3_HPP
#define AOC2022_DAY3_HPP


#include <vector>

class Day3 {
public:
    void solve();

private:
    void parseInput();
    int solveP1();
    int solveP2();
    std::vector<std::vector<char>> rucksacks;
};


#endif //AOC2022_DAY3_HPP
