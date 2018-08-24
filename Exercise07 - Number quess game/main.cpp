/// FILE NAME: main.cpp
/// PROJECT: Exercise07
/// AUTHOR: Mihkel Tiganik
/// CREATED: 08.06.2018
/// MODIFIED: 21.06.2018
///
/// DESCRIPTION: Program generates a random integer in 0...100 range and suggests user
///   to guess this number. If user enter a smaller or bigger number, the program should write
///   "Too low!" or "Too high!". If user enters a correct number, then program should display 
///   a win message and a number of attemps.

#include <iostream>
#include <time.h> 

#include "functions07.h"

int main()
{
  int iSecret;

  //initialize random seed: 
  srand(time(NULL));

  // generate secret number between 0 and 100: 
  iSecret = rand() % 100 + 0;
  // std::cout << iSecret << std::endl;
  startRandomNumerGame(iSecret);

  std::system("pause");
  return 0;
}

