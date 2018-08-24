/// FILE NAME: main.cpp
/// PROJECT: Exercise17
/// AUTHOR: Mihkel Tiganik
/// CREATED: 15.06.2018
/// MODIFIED: 22.06.2018
///
/// DESCRIPTION: Program gets a txt file as argument
///  After that it swap all even lines with odd lines

#include <iostream>

#include "functions17.h"

int main()
{
  std::string filename = "Exercise17.txt";
  SwapLines(filename);
  DisplayFile(filename);

  std::system("pause");
  return 0;
}
