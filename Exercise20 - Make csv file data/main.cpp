/// FILE NAME: main.cpp
/// PROJECT: Exercise20
/// AUTHOR: Mihkel Tiganik
/// CREATED: 15.06.2018
/// MODIFIED: 22.06.2018
///
/// DESCRIPTION: Program asks user to enter a name of csv file and 
///  input string. After that it will create a valid csv file with
///  specified name and inserted data
///  Example of string:
///  "Cell 11, Cell12, "This, is; cell, 13;"; Cell21, Cell22, Cell23;"

#include <iostream>

#include "CsvCreator.h"

int main()
{
  CsvCreator creator;
  creator.GetUserInput();
  creator.WriteToFile();

  std::system("pause");
  return 0;
}
