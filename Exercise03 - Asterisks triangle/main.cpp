/// FILE NAME: main.cpp
/// PROJECT: Exercise03
/// AUTHOR: Mihkel Tiganik
/// CREATED: 06.06.2018
/// MODIFIED: 21.06.2018
///
/// DESCRIPTION: Ask for 1 integer and draw a triangle made with asteriks of give size, like:
///      3 -> *
///           **
///           ***

#include <iostream>

#include "functions03.h"

int main()
{
  int input = getInteger();
  printAsterixTriangle(input);
  std::system("pause");
  return 0;
}
