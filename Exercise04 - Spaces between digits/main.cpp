/// FILE NAME: main.cpp
/// PROJECTT: Exercise04
/// AUTHOR: Mihkel Tiganik
/// CREATED: 06.06.2018
/// MODIFIED: 21.06.2018
///
/// DESCRIPTION: Ask for 1 integer and print out every digit interleaved with 3 spaces:
///		   123 -> 1   2   3

#include <iostream>

#include "functions04.h"

int main()
{
  int input = getInput();
  printDigitsWithWhiteSpace(input);
  std::system("pause");
  return 0;
}

