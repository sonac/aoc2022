//
// Created by Andrii Sumko on 03.12.22.
//

#include <iostream>
#include <set>
#include "day3.hpp"
#include "../utils/file.hpp"

// 65 - 90 uppercase
// 97 - 122 lowercase

int getPriority(char c) {
    if (int(c) >= 97)
        return int(c) - 96;
    return int(c) - 38;
}

char findCommon(std::vector<char> rs) {
    std::set<char> fh;
    int mid = rs.size() / 2;
    for (int i = 0; i < mid; i++) {
        fh.insert(rs[i]);
    }
    for (int i = mid; i < rs.size(); i++) {
        if (fh.contains(rs[i]))
            return rs[i];
    }
    return '0';
}

char findCommonInThree(std::vector<char> rs1, std::vector<char> rs2, std::vector<char> rs3) {
    std::set<char> s(rs1.begin(), rs1.end());
    std::set<char> s2;
    for (const char& it: rs2) {
        if (s.contains(it))
            s2.insert(it);
    }
    for (const char& it: rs3) {
        if (s2.contains(it))
            return it;
    }
    return '0';
}

void Day3::parseInput() {
    std::vector<std::string> lines;
    getData(lines, "input/day3.txt");
    for (const std::string& l: lines) {
        std::vector<char> rucksack(l.begin(), l.end());
        rucksacks.push_back(rucksack);
    }
}

void Day3::solve() {
    parseInput();
    std::cout << solveP1() << '\n';
    std::cout << solveP2() << '\n';
}

int Day3::solveP1() {
    int res = 0;
    for (const auto& r: rucksacks) {
        char cc = findCommon(r);
        res += getPriority(cc);
    }
    return res;
}

int Day3::solveP2() {
    int res = 0;
    for (int i = 2; i < rucksacks.size(); i += 3) {
        char cc = findCommonInThree(rucksacks[i-2], rucksacks[i-1], rucksacks[i]);
        res += getPriority(cc);
    }
    return res;
}