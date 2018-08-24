/// FILE NAME: functions17.cpp
/// PROJECT: Exercise17
/// AUTHOR: Mihkel Tiganik
/// CREATED: 22.06.2018
///
/// DESCRIPTION:  Definitions of functions for Exercise17

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "functions17.h"

void SwapLines(std::string input) {
  //vector for storing file lines
  std::vector<std::string> fileLine;
  std::ifstream fin(input.c_str());
  if (!fin) {
    std::cerr << "error: open file for input failed!" << std::endl;
    abort();
  }
  std::string line;
  char ch;
  while (getline(fin, line)) {
    fileLine.push_back(line);
  }
  fin.close();

  for (int i = 1; i < fileLine.size(); i += 2) { // takes even lines and swamp with odd lines
    iter_swap(fileLine.begin() + i, fileLine.begin() + i - 1);
  }

  std::ofstream fout(input.c_str());
  if (!fout) {
    std::cerr << "error: open file for output failed!" << std::endl;
    abort();
  }
  // write new lines to file
  for (int i = 0; i < fileLine.size(); i++) {
    fout << fileLine[i] << std::endl;
  }
  fout.close();
}

void DisplayFile(std::string input) {
  std::ifstream fin(input.c_str());
  if (!fin) {
    std::cerr << "error: open file for input failed!" << std::endl;
    abort();
  }
  std::string line;
  while (getline(fin, line)) {
    std::cout << line << std::endl;
  }
  fin.close();
}