/// FILE NAME: main.cpp
/// PROJECT: Exercise18
/// AUTHOR: Mihkel Tiganik
/// CREATED: 15.06.2018
/// MODIFIED: 22.06.2018
///
/// DESCRIPTION: Program gets a txt file as argument. After
///  that it asks user to enter a source index, length and
///  destination index. Program copies text from source index
///  with length to the destination index.

#include <iostream>

#include "Swapper.h"

int main()
{
  std::string inputfile = "Exercise18PrimaryFile.txt";
  std::string outputfile = "Exercise18Output.txt";

  Swapper swapper;
  swapper.SetInputFile(inputfile);
  swapper.SetOutputFile(outputfile); // leave them both as outputfile if you want input and output to be same file
  //swapper.GetInput(8, 6, 25);	// automatic input set
  swapper.GetInput();  // with this user can enter values by itself
  swapper.DisplayOutput();

  std::system("pause");
  return 0;
}
