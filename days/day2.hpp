//
// Created by Andrii Sumko on 02/12/2022.
//

#ifndef AOC2022_DAY2_HPP
#define AOC2022_DAY2_HPP


#include <map>
#include <vector>

class Day2 {
public:
    std::vector<char> oppInput;
    std::vector<char> playerInput;
    void prepData();
    int straightForward();
    int strategyDriven();
    void solve();
};


#endif //AOC2022_DAY2_HPP
