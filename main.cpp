#include <iostream>

#include "days/day1.hpp"

int main() {
    Day1 d;
    d.prepData();
    std::cout << d.mostCalories() << std::endl;
    std::cout << d.topThree() << std::endl;
    return 0;
}
