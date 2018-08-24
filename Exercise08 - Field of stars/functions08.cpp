/// FILE NAME: functions08.cpp
/// PROJECT: Exercise08
/// AUTHOR: Mihkel Tiganik
/// CREATED: 21.06.2018
///
/// DESCRIPTION:  Definitions of functions for Exercise08

#include <iostream>
#include <time.h> 

#include "functions08.h"

void FieldOfStars(int stars) {
  int problability = 1500 / stars;
  int generator;
  int starCounter = 0;
  srand(time(NULL));
  for (int i = 0; i < 30; ++i) {
    for (int j = 0; j < 50; ++j) {
      generator = rand() % problability;
      if (generator == 0) {
        std::cout << "*";
        starCounter++;
      }
      else std::cout << " ";
    }std::cout << std::endl;
  }
  //std::cout << "Actual number of stars: " << starCounter << std::endl;

}
