/// FILE NAME: functions19.cpp
/// PROJECT: Exercise19
/// AUTHOR: Mihkel Tiganik
/// CREATED: 22.06.2018
///
/// DESCRIPTION:  Definitions of functions for Exercise19

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "functions19.h"



std::vector<std::string> Split(const std::string & s, char delim)
{
  std::vector<std::string> elems;
  Split(s, delim, back_inserter(elems));
  return elems;
}

template<typename Out>
void Split(const std::string &s, char delim, Out result) {
  std::stringstream ss(s);
  std::string item;
  while (getline(ss, item, delim)) {
    *(result++) = item;
  }
}

void DisplayResult(std::string filename)
{
  std::ifstream file(filename);
  if (!file) {
    std::cout << "Error, could not find file";
    abort();
  }
  std::string tokenValue, line;
  std::vector<std::string> lineVector;
  std::vector < std::vector<std::string> > result;
  while (getline(file, line)) {
    lineVector = Split(line, ';');
    result.push_back(lineVector);
  }

  for (unsigned int i = 0; i < result.size(); i++) {
    for (unsigned int j = 0; j < result[i].size(); j++) {
      std::cout << result[i][j] << "\t";
    }
    std::cout << std::endl;
  }
}
