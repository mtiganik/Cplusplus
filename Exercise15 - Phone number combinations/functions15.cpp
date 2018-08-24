/// FILE NAME: functions15.cpp
/// PROJECT: Exercise15
/// AUTHOR: Mihkel Tiganik
/// CREATED: 21.06.2018
///
/// DESCRIPTION:  Definitions of functions for Exercise15

#include <iostream>
#include <string>
#include <vector>

#include "functions15.h"

int GetInteger() {
  std::cout << "Enter integer";
  int returnInt;
  std::cin >> returnInt;
  std::string compareString = std::to_string(returnInt);
  if (compareString.find("0") != std::string::npos || compareString.find("1") != std::string::npos) {
    std::cout << "Please don't add 0's or 1's to this integer" << std::endl;
    return GetInteger();
  }
  std::cout << std::endl;

  return returnInt;
}


void DisplayTexts(int inputInt) {
  std::string str = std::to_string(inputInt);
  std::vector<std::string> Arr;
  std::vector<std::string> finalArr;

  int ArrStarter = 0; int rememberArrStarter = 0; int ArrSize = 0;

  std::string temp;

  // Initialize first vector elements
  switch (str[0]) {
  case('2'):
    Arr.push_back("a");
    Arr.push_back("b");
    Arr.push_back("c");
    break;
  case('3'):
    Arr.push_back("d");
    Arr.push_back("e");
    Arr.push_back("f");
    break;
  case('4'):
    Arr.push_back("g");
    Arr.push_back("h");
    Arr.push_back("i");
    break;
  case('5'):
    Arr.push_back("j");
    Arr.push_back("k");
    Arr.push_back("l");
    break;
  case('6'):
    Arr.push_back("m");
    Arr.push_back("n");
    Arr.push_back("o");
    break;
  case('7'):
    Arr.push_back("p");
    Arr.push_back("q");
    Arr.push_back("r");
    Arr.push_back("s");
    break;
  case('8'):
    Arr.push_back("t");
    Arr.push_back("u");
    Arr.push_back("v");
    break;
  case('9'):
    Arr.push_back("w");
    Arr.push_back("x");
    Arr.push_back("y");
    Arr.push_back("z");
    break;
  default:
    break;
  }



  // initialize with other elements
  for (int i = 1; i < str.size(); i++) {
    ArrSize = Arr.size();
    for (int k = ArrStarter; k < ArrSize; k++) {

      // initializing parameter rememberArrStarter for next iteration
      if (k == ArrStarter) {
        rememberArrStarter = Arr.size();
      }

      //get current vector value
      temp = Arr[k];

      // add more elements to Array
      switch (str[i]) {
      case('2'):
        Arr.push_back(temp + "a");
        Arr.push_back(temp + "b");
        Arr.push_back(temp + "c");
        break;
      case('3'):
        Arr.push_back(temp + "d");
        Arr.push_back(temp + "e");
        Arr.push_back(temp + "f");
        break;
      case('4'):
        Arr.push_back(temp + "g");
        Arr.push_back(temp + "h");
        Arr.push_back(temp + "i");
        break;
      case('5'):
        Arr.push_back(temp + "j");
        Arr.push_back(temp + "k");
        Arr.push_back(temp + "l");
        break;
      case('6'):
        Arr.push_back(temp + "m");
        Arr.push_back(temp + "n");
        Arr.push_back(temp + "o");
        break;
      case('7'):
        Arr.push_back(temp + "p");
        Arr.push_back(temp + "q");
        Arr.push_back(temp + "r");
        Arr.push_back(temp + "s");
        break;
      case('8'):
        Arr.push_back(temp + "t");
        Arr.push_back(temp + "u");
        Arr.push_back(temp + "v");
        break;
      case('9'):
        Arr.push_back(temp + "w");
        Arr.push_back(temp + "x");
        Arr.push_back(temp + "y");
        Arr.push_back(temp + "z");
        break;
      default:
        break;
      }
    }
    ArrStarter = rememberArrStarter;
  }

  // make new array wich only has last elements
  for (int i = ArrStarter; i < Arr.size(); i++) {
    finalArr.push_back(Arr[i]);
  }

  std::cout << "Possible mobile numbers for this number combination, are as follows:" << std::endl;
  for (int i = 0; i < finalArr.size(); i++) {
    std::cout << finalArr[i] << std::endl;
  }

}

