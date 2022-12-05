//
// Created by Andrii Sumko on 04.12.22.
//

#ifndef AOC2022_DAY4_HPP
#define AOC2022_DAY4_HPP

#include <set>

struct Shift {
    std::set<int> f;
    std::set<int> s;
};

class Day4 {
public:
    void solve();

private:
    void parseInput();
    int calculateFullyOverlappingPairs();
    int calculateOverlappingPairs();

    std::vector<Shift> input;
};


#endif //AOC2022_DAY4_HPP
