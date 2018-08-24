/// FILE NAME: functions10.cpp
/// PROJECT: Exercise10
/// AUTHOR: Mihkel Tiganik
/// CREATED: 21.06.2018
///
/// DESCRIPTION:  Definitions of functions for Exercise10

#include <iostream>

#include "functions10.h"

void printCircle(int input) {
  int radius, loopRadius;

  switch (input) {
  case(1):
    radius = 0;
    break;
  case(2):
    radius = 1;
    break;
  case(3):
  case(4):
    radius = 2;
    break;
  case(5):
    radius = 3;
    break;
  case(6):
  case(7):
    radius = 4;
    break;
  case(8):
  case(9):
  case(10):
    radius = 5;
    break;
  default:
    radius = 6;
    break;
  }
  loopRadius = radius;

  for (int i = 0; i< 2 * input - 1; ++i) {
    for (int j = 0; j < 2 * input - 1; ++j) {
      if (j < input) {
        if ((j - loopRadius) < 0) std::cout << " ";
        else std::cout << "*";
      }
      else if (j == input) std::cout << "*";
      else {
        if ((2 * input - j - loopRadius) > 1) std::cout << "*";
        else std::cout << " ";
      }
    }
    std::cout << std::endl;
    if (i < input && loopRadius > 0) --loopRadius;

    if (i >= input && 2 * input - 2 - i <= radius) ++loopRadius;
  }

}

int getInteger() {
  std::cout << "Enter integer";
  int returnInt;
  std::cin >> returnInt;
  std::cout << std::endl;

  return returnInt;
}
