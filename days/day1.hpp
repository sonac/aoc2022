//
// Created by Andrii Sumko on 01/12/2022.
//

#ifndef AOC2022_DAY1_HPP
#define AOC2022_DAY1_HPP

#include <vector>

struct Elf {
    std::vector<int> items;
    int totalCalories;
    void sumCalories() {
        int tot = 0;
        for (int i: items)
            tot += i;
        totalCalories = tot;
    }
};

class Day1 {
public:
    void prepData();
    int mostCalories();
    int topThree();
private:
    std::vector<Elf> elves;

};


#endif //AOC2022_DAY1_HPP
