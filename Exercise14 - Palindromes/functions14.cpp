/// FILE NAME: functions14.cpp
/// PROJECT: Exercise14
/// AUTHOR: Mihkel Tiganik
/// CREATED: 21.06.2018
///
/// DESCRIPTION:  Definitions of functions for Exercise14

#include <algorithm>
#include <iostream>
#include <string>

#include "functions14.h"

std::string GetString() {
  std::cout << "Enter string\n";
  std::string returnString;
  std::cin >> returnString;
  std::cout << std::endl;
  return returnString;

}

bool IsPalindrome(std::string _input) {

  std::string input = _input;

  // remove whitespaces
  input.erase(remove_if(input.begin(), input.end(), isspace), input.end());

  // remove other characters
  input.erase(std::remove_if(input.begin(),
    input.end(),
    [](char c)
  { return c == ',' || c == '.' || c == '!' || c == ':'; }),
    input.end());

  // tolowercase
  std::transform(input.begin(), input.end(), input.begin(), ::tolower);

  int counterMaxValue = input.size();
  for (int i = 0; i < counterMaxValue / 2; i++) {
    if (input[i] != input[counterMaxValue - i - 1]) {
      return false;
    }
  }
  return true;
}

