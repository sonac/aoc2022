#include <iostream>

#include "days/day1.hpp"
#include "days/day2.hpp"

int main() {
    Day1 d1;
    d1.prepData();
    std::cout << d1.mostCalories() << std::endl;
    std::cout << d1.topThree() << std::endl;
    Day2 d2;
    d2.solve();
    return 0;
}
