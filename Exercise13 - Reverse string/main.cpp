/// FILE NAME: main.cpp
/// PROJECT: Exercise13
/// AUTHOR: Mihkel Tiganik
/// CREATED: 14.06.2018
/// MODIFIED: 21.06.2018
///
/// DESCRIPTION: Program asks user to enter a string. after
///  that display a reverse string. For example for string
///  "Example", result is "elpmaxE"

#include <iostream>
#include <string>

#include "functions13.h"

int main()
{
  std::string _input = getString();
  std::string output = reverseString(_input);
  std::cout << output << std::endl;

  std::system("pause");
  return 0;
}
