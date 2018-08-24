/// FILE NAME: main.cpp
/// PROJECT: Exercise06
/// AUTHOR: Mihkel Tiganik
/// CREATED: 07.06.2018
/// MODIFIED: 21.06.2018
///
/// DESCRIPTION: Ask for 1 char and print out following 10 letters alternating upper
/// and lower case, starting with the same case as the input and restarting from 'a'
/// if series goes over 'z'
///       T -> UvWxYzAbCd

#include <iostream>

#include "functions06.h"

int main()
{
  char input = getChar();
  std::cout << input << "->";
  printSequence(input);
  std::system("pause");
  return 0;
}

