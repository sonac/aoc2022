cmake_minimum_required(VERSION 3.19)
project(aoc2022)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

add_executable(aoc2022 main.cpp days/day1.cpp days/day1.hpp utils/file.cpp utils/file.hpp days/day2.cpp days/day2.hpp days/day3.cpp days/day3.hpp days/day4.cpp days/day4.hpp)