/// FILE NAME: functions07.cpp
/// PROJECT: Exercise07
/// AUTHOR: Mihkel Tiganik
/// CREATED: 21.06.2018
///
/// DESCRIPTION:  Definitions of functions for Exercise07

#include <iostream>

#include "functions07.h"

void startRandomNumerGame(int input) {
  int secret = input;
  int quesses = 0;
  int answer;
  do {
    std::cout << "quess a number between 0 and 100" << std::endl;
    std::cin >> answer;
    if (secret < answer) std::cout << "number is lower than " << answer << std::endl;
    else if (secret > answer) std::cout << "number is bigger than " << answer << std::endl;
    ++quesses;

  } while (secret != answer);
  std::cout << "Congratulation, secret number was " << answer << " it took you " << quesses << " times. " << std::endl;

}
