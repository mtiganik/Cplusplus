/// FILE NAME: functions05.cpp
/// PROJECT: Exercise05
/// AUTHOR: Mihkel Tiganik
/// CREATED: 21.06.2018
///
/// DESCRIPTION:  Definitions of functions for Exercise05

#include <iostream>
#include <vector>

#include "functions05.h"

void convertToBinary(int x) {
  std::cout << "Number in Binary format" << std::endl;
  std::vector<char> arr;
  int bin, y = x, j = 0;

  do {
    bin = y % 2;
    y = y / 2;
    if (bin == 1)
      arr.push_back('1');
    else {
      arr.push_back('0');
    }
  } while (y > 0);

  reverse(arr.begin(), arr.end());

  for (auto x : arr) {
    j++;
    if (j % 4 == 0) {
      std::cout << " ";
    }
    std::cout << x;
  }
  std::cout << std::endl;
}

void convertToHex(int x)
{
  int y;
  std::vector<char> arr;
  int hex = 0;
  y = x;
  std::cout << "Number in Hex format" << std::endl;
  std::cout << "0x";
  do
  {
    hex = y % 16;
    y = y / 16;
    if (hex == 10)
      arr.push_back('A');
    else if (hex == 11)
      arr.push_back('B');
    else if (hex == 12)
      arr.push_back('C');
    else if (hex == 13)
      arr.push_back('D');
    else if (hex == 14)
      arr.push_back('E');
    else if (hex == 15)
      arr.push_back('F');
    else if (hex == 9)
      arr.push_back('9');
    else if (hex == 8)
      arr.push_back('8');
    else if (hex == 7)
      arr.push_back('7');
    else if (hex == 6)
      arr.push_back('6');
    else if (hex == 5)
      arr.push_back('5');
    else if (hex == 4)
      arr.push_back('4');
    else if (hex == 3)
      arr.push_back('3');
    else if (hex == 2)
      arr.push_back('2');
    else if (hex == 1)
      arr.push_back('1');
    else if (hex == 0)
      arr.push_back('0');

    else
      arr.push_back(static_cast<char>(hex));

  } while (y>0);

  reverse(arr.begin(), arr.end());
  //display all values;
  for (auto x : arr) {
    std::cout << x;
  }
  std::cout << std::endl;

}


int getInteger() {
  std::cout << "Enter Big integer";
  int returnInt;
  std::cin >> returnInt;
  std::cout << std::endl;

  return returnInt;
}
