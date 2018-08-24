/// FILE NAME: main.cpp
/// PROJECT: Exercise19
/// AUTHOR: Mihkel Tiganik
/// CREATED: 15.06.2018
/// MODIFIED: 22.06.2018
///
/// DESCRIPTION: Program gets a csv file as argument. It 
///  should parse it and display all data from csv in the
///  console as a table.

#include <iostream>

#include "functions19.h"

int main()
{
  std::string fileName = "Exercise19.csv";
  DisplayResult(fileName);

  std::system("pause");
  return 0;
}
