//
// Created by Andrii Sumko on 01/12/2022.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "file.hpp"

File::File() : data("") {}

File::~File() = default;

void File::readFile(std::string fileName) {
    std::ifstream fileToRead(fileName);
    std::string line;
    while (getline(fileToRead, line)) {
        data.append(line);
        data.append("\n");
    };
};

std::string File::getData() {
    return data;
}

void getData(std::vector<std::string> &lines, std::string fileName) {
    File f;
    f.readFile(fileName);
    std::string buf;
    std::stringstream ss(f.getData());
    while (getline(ss, buf, '\n'))
    {
        lines.push_back(buf);
    };
}