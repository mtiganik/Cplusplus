/// FILE NAME: main.cpp
/// PROJECT: Exercise05
/// AUTHOR: Mihkel Tiganik
/// CREATED: 07.06.2018
/// MODIFIED: 21.06.2018
///
/// DESCRIPTION: Ask for 1 integer and convert it in hexadecimal and binary format

#include <iostream>

#include "functions05.h"

int main()
{
  int input;
  input = getInteger();
  convertToHex(input);
  convertToBinary(input);

  std::system("pause");
  return 0;
}
