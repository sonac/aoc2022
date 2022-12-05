//
// Created by Andrii Sumko on 05.12.22.
//
#include <iostream>

#include "day5.hpp"
#include "../utils/string.hpp"


void Day5::parseInput() {
    int i = 0;
    while (!isdigit(lines[i][1])) {
        parseLine(lines[i]);
        i++;
    }
    i+= 2;
    for (; i < lines.size(); i++) {
        parseMove(lines[i]);
    }
}

void Day5::solveP1() {
    while (!moves.empty()) {
        performMove();
    }
    for (auto s: stacks) {
        if (!s.empty())
            std::cout << s.top();
    }
    std::cout << '\n';
}

void Day5::solveP2() {
    while (!moves.empty()) {
        performProMove();
    }
    for (auto s: stacks) {
        if (!s.empty())
            std::cout << s.top();
    }
    std::cout << '\n';
}

//[N] [C]
void Day5::parseLine(std::string l) {
    int q = 0;
    for (int i = 1; i < l.size(); i+=4) {
        if (l[i] != ' ')
            initStacks[q].push(l[i]);
        q++;
    }
}

//move 1 from 2 to 1
void Day5::parseMove(std::string l) {
    Move m;
    std::vector<std::string> tokens = strToVec(l, ' ');
    m.cnt = std::stoi(tokens[1]);
    m.from = std::stoi(tokens[3]);
    m.to = std::stoi(tokens[5]);
    moves.push(m);
}

void Day5::performMove() {
    Move m = moves.front();
    moves.pop();
    for (int i = 0; i < m.cnt; i++) {
        char el = stacks[m.from - 1].top();
        stacks[m.from - 1].pop();
        stacks[m.to - 1].push(el);
    }
}

void Day5::performProMove() {
    Move m = moves.front();
    moves.pop();
    std::stack<char> tmp;
    for (int i = 0; i < m.cnt; i++) {
        char el = stacks[m.from - 1].top();
        stacks[m.from - 1].pop();
        tmp.push(el);
    }
    while (!tmp.empty()) {
        char el = tmp.top();
        tmp.pop();
        stacks[m.to - 1].push(el);
    }
}
