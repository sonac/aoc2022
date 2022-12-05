//
// Created by Andrii Sumko on 05.12.22.
//

#ifndef AOC2022_DAY5_HPP
#define AOC2022_DAY5_HPP

#include <queue>
#include <stack>
#include "../utils/file.hpp"

struct Move {
    int cnt;
    int from;
    int to;
};

class Day5 {
public:
    Day5() {
        getData(lines, "input/day5.txt");
        for (int i = 0; i < 9; i++) {
            std::stack<char> s;
            initStacks.push_back(s);
        }
        parseInput();
        for (auto q: initStacks) {
            std::stack<char> s;
            while (!q.empty()) {
                char el = q.top();
                q.pop();
                s.push(el);
            }
            stacks.push_back(s);
        }
    }
    void solveP1();
    void solveP2();
private:
    void parseInput();
    void parseLine(std::string l);
    void parseMove(std::string l);
    void performMove();
    void performProMove();

    std::vector<std::string> lines;
    std::vector<std::stack<char>> initStacks;
    std::vector<std::stack<char>> stacks;
    std::queue<Move> moves;
};


#endif //AOC2022_DAY5_HPP
