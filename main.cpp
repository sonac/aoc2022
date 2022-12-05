#include <iostream>

#include "days/day1.hpp"
#include "days/day2.hpp"
#include "days/day3.hpp"
#include "days/day4.hpp"

int main() {
    Day1 d1;
    Day2 d2;
    Day3 d3;
    Day4 d4;
    d1.prepData();
    std::cout << d1.mostCalories() << std::endl;
    std::cout << d1.topThree() << std::endl;
    d2.solve();
    d3.solve();
    d4.solve();
    return 0;
}
