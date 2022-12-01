//
// Created by Andrii Sumko on 01/12/2022.
//

#ifndef AOC2022_FILE_HPP
#define AOC2022_FILE_HPP
#include <string>

class File {
public:
    File();
    ~File();
    void readFile(std::string fileName);
    std::string getData();
private:
    std::string data;
};

void getData(std::vector<std::string> &lines, std::string fileName);

#endif //AOC2022_FILE_HPP
