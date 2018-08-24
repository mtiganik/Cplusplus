/// FILE NAME: functions04.cpp
/// PROJECT: Exercise04
/// AUTHOR: Mihkel Tiganik
/// CREATED: 21.06.2018
///
/// DESCRIPTION:  Definitions of functions for Exercise04

#include <iostream>
#include <string>
#include <vector>

#include "functions04.h"

void printDigitsWithWhiteSpace(int input) {
  int converter = input;
  std::vector<int> convertVector;
  do {
    convertVector.push_back(converter % 10);
    converter /= 10;

  } while (converter > 0);
  for (int i = convertVector.size()-1; i >=0; --i) {
    std::cout << convertVector[i] << "   ";
  }

    std::cout << std::endl;
}


int getInput() {
  std::cout << "Big number";
  int returnNumber;
  std::cin >> returnNumber;
  std::cout << std::endl;

  return returnNumber;
}
