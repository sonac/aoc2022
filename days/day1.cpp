//
// Created by Andrii Sumko on 01/12/2022.
//

#include <vector>

#include "day1.hpp"

#include "../utils/file.hpp"

void Day1::prepData() {
    std::vector<std::string> lines;
    getData(lines, "input/day1.txt");
    Elf *curElf = new Elf();
    for (auto l: lines) {
        if (l == "") {
            curElf->sumCalories();
            elves.push_back(*curElf);
            curElf = new Elf();
            continue;
        }
        curElf->sumCalories();
        curElf->items.push_back(std::stoi(l));
    }
    elves.push_back(*curElf);
}

bool cmpElvesByCcal(const Elf &a, const Elf &b) {
    return a.totalCalories > b.totalCalories;
}

int Day1::mostCalories() {
    int res = elves[0].totalCalories;
    for (Elf e: elves) {
        res = std::max(res, e.totalCalories);
    }
    return res;
}

int Day1::topThree() {
    std::sort(elves.begin(), elves.end(), cmpElvesByCcal);
    return elves[0].totalCalories + elves[1].totalCalories + elves[2].totalCalories;
}