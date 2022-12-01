cmake_minimum_required(VERSION 3.19)
project(aoc2022)

set(CMAKE_CXX_STANDARD 20)

add_executable(aoc2022 main.cpp days/day1.cpp days/day1.hpp utils/file.cpp utils/file.hpp)