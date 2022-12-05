//
// Created by Andrii Sumko on 04.12.22.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "day4.hpp"
#include "../utils/file.hpp"

std::set<int> buildSet(int s, int e) {
    std::set<int> res;
    for (int i=s; i <= e; i++)
        res.insert(i);
    return res;
}

Shift parseLine(const std::string& line) {
    std::string fPart = line.substr(0, line.find(','));
    std::string sPart = line.substr(line.find(',') + 1, line.size());
    std::string fBegin = fPart.substr(0, fPart.find('-'));
    std::string fEnd = fPart.substr(fPart.find('-') + 1, fPart.size());
    std::string sBegin = sPart.substr(0, sPart.find('-'));
    std::string sEnd = sPart.substr(sPart.find('-') + 1, sPart.size());

    std::set<int> fShift = buildSet(std::stoi(fBegin), std::stoi(fEnd));
    std::set<int> sShift = buildSet(std::stoi(sBegin), std::stoi(sEnd));

    Shift res = {fShift, sShift};

    return res;
}

bool haveIntersection(std::set<int> s1, std::set<int> s2) {
    std::vector<int> v;
    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(v));

    return !v.empty();
}

void Day4::solve() {
    parseInput();
    std::cout << calculateFullyOverlappingPairs() << '\n';
    std::cout << calculateOverlappingPairs() << '\n';
}

int Day4::calculateFullyOverlappingPairs() {
    int res = 0;
    for (const Shift& s: input) {
        if (std::includes(s.f.begin(), s.f.end(), s.s.begin(), s.s.end()) ||
            std::includes(s.s.begin(), s.s.end(), s.f.begin(), s.f.end()))
            res++;
    }
    return res;
}

int Day4::calculateOverlappingPairs() {
    int res = 0;
    for (const Shift& s: input) {
        if (haveIntersection(s.f, s.s))
            res++;
    }
    return res;
}

void Day4::parseInput() {
    std::vector<std::string> lines;
    getData(lines, "input/day4.txt");
    // line looks like 2-4,6-8 -> need to split by comma and then by dash
    for (const std::string& l: lines) {
        Shift s = parseLine(l);
        input.push_back(s);
    }
}