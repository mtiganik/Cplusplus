/// FILE NAME: main.cpp
/// PROJECT: Exercise15
/// AUTHOR: Mihkel Tiganik
/// CREATED: 15.06.2018
/// MODIFIED: 21.06.2018
///
/// DESCRIPTION:  Program asks user to enter a phone number
///  as integer. After that it prints all possible texts
///  that could be typed by this number
///  For number 762 there are 36 results

#include <iostream>
#include <string>

#include "functions15.h"

int main()
{
  int input = GetInteger();
  std::string inputString = std::to_string(input);
  DisplayTexts(input);

  std::system("pause");
  return 0;
}

