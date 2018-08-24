/// FILE NAME: main.cpp
/// PROJECT: Exercise10
/// AUTHOR: Mihkel Tiganik
/// CREATED: 12.06.2018
/// MODIFIED: 21.06.2018
///
/// DESCRIPTION: Program asks user to enter a radius of circle as integer.
///  After that a circle with specified radius is drawn.
///  Example for radius 4:
///
///           * * *
///         * * * * *
///       * * * * * * *
///       * * * * * * *
///       * * * * * * *
///         * * * * *
///           * * *

#include <iostream>

#include "functions10.h"

int main()
{
  int input = getInteger();
  printCircle(input);

  std::system("pause");
  return 0;
}
