/// FILE NAME: functions13.cpp
/// PROJECT: Exercise13
/// AUTHOR: Mihkel Tiganik
/// CREATED: 21.06.2018
///
/// DESCRIPTION:  Definitions of functions for Exercise13

#include <iostream>
#include <string>

#include "functions13.h"

std::string reverseString(std::string input) {
  reverse(input.begin(), input.end());
  return input;
}

std::string getString() {
  std::cout << "Enter string" << std::endl;
  std::string returnString;
  std::cin >> returnString;
  std::cout << std::endl;
  return returnString;
}
