//
// Created by Andrii Sumko on 02/12/2022.
//

#include <set>
#include <iostream>
#include "day2.hpp"
#include "../utils/file.hpp"

const std::vector<char> rps {'A', 'B', 'C'};
const std::map<char, int> rewards {{'A', 1}, {'B', 2}, {'C', 3}};
const std::map<char, int> pNums {{'A', 3}, {'B', 2}, {'C', 1}};
const std::map<char, int> opNums {{'A', 1}, {'B', 2}, {'C', 3}};

void Day2::prepData() {
    std::vector<std::string> lines;
    getData(lines, "input/day2.txt");
    for (const std::string& l: lines) {
        oppInput.push_back(l[0]);
        playerInput.push_back(l[2]);
    }
}

int calcWinLoss(char op, char p) {
    int r = pNums.at(p) + opNums.at(op);
    if (r == 4) {
        return 3;
    }
    if (r == 5 || r == 2) {
        return 0;
    }
    return 6;
}

int getRoundRes(char op, char p) {
    return rewards.at(p) + calcWinLoss(op, p);
}

int Day2::straightForward() {
    /** LMAO read better
     *
    for (const auto& p: allCombinations(getUq(playerInput))) {
        std::map<char, char> curMap {{p[0], rps[0]}, {p[1], rps[1]}, {p[2], rps[2]}};
        int curRes = 0;
        for (int i = 0; i < playerInput.size(); i++) {
            curRes += getRoundRes(oppInput[i], curMap.at(playerInput[i]));
        }
        if (curRes > curMax)
            curMax = curRes;
    } */
    int res = 0;
    std::map<char, char> curMap {{'X', 'A'}, {'Y', 'B'}, {'Z', 'C'}};
    for (int i = 0; i < playerInput.size(); i++) {
        res += getRoundRes(oppInput[i], curMap.at(playerInput[i]));
    }
    return res;
}

char getNext(char c) {
    auto it = std::find(rps.begin(), rps.end(), c);
    if (it == (rps.end() - 1)) {
        return rps[0];
    }
    int index = it - rps.begin() + 1;
    return rps[index];
}

char getPrev(char c) {
    auto it = std::find(rps.begin(), rps.end(), c);
    if (it == rps.begin()) {
        return rps[2];
    }
    int index = it - rps.begin() - 1;
    return rps[index];
}

char getStrategyChoice(char op, char p) {
    if (p == 'X') {
        return getPrev(op);
    }
    if (p == 'Y') {
        return op;
    }
    return getNext(op);
}

int Day2::strategyDriven() {
    int res = 0;
    for (int i = 0; i < playerInput.size(); i++) {
        res += getRoundRes(oppInput[i], getStrategyChoice(oppInput[i], playerInput[i]));
    }
    return res;
}

void Day2::solve() {
    prepData();
    std::cout << straightForward() << '\n';
    std::cout << strategyDriven() << '\n';
}

