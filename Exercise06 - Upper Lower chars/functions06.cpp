/// FILE NAME: functions06.cpp
/// PROJECT: Exercise06
/// AUTHOR: Mihkel Tiganik
/// CREATED: 21.06.2018
///
/// DESCRIPTION:  Definitions of functions for Exercise06

#include <iostream>

#include "functions06.h"

void printSequence(char startChar) {
  int intChar = int(startChar) + 1;
  std::cout << char(intChar);
  for (int i = 0; i < 9; ++i) {
    if (65 <= intChar && intChar <= 90) {
      intChar = intChar + 33;
    }
    else if (97 <= intChar && intChar <= 122) {
      intChar = intChar - 31;
    }
    if (intChar == 123) {
      intChar = 97;

    }
    else if (intChar == 91) {
      intChar = 65;
    }
    std::cout << char(intChar);

  }
  std::cout << std::endl;
}


char getChar() {
  std::cout << "Enter char "<< std::endl;
  char returnChar;
  std::cin >> returnChar;
  std::cout << std::endl;
  if ((65 <= int(returnChar) && int(returnChar) <= 90) || (97 <= int(returnChar) && int(returnChar) <= 122)) {

    return returnChar;
  }
  else {
    std::cout << "this is not a valid char" << std::endl;
    return getChar();
  }
}
