/// FILE NAME: functions03.cpp
/// PROJECT: Exercise03
/// AUTHOR: Mihkel Tiganik
/// CREATED: 21.06.2018
///
/// DESCRIPTION:  Definitions of functions for Exercise03

#include <iostream>

#include "functions03.h"

void printAsterixTriangle(int input) {
  int j;
  for (int i = 1; i <= input; ++i) {
    j = i;
    while (j > 0) {
      std::cout << " *";
      --j;
    }
    std::cout << std::endl;
  }
}

int getInteger() {
  std::cout << "Enter integer";
  int returnInt;
  std::cin >> returnInt;
  std::cout << std::endl;
  return returnInt;
}

