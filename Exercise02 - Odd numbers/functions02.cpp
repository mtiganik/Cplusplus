/// FILE NAME: functions.cpp
/// PROJECT: Exercise02
/// AUTHOR: Mihkel Tiganik
/// CREATED: 21.06.2018
///
/// DESCRIPTION:  Definitions of functions for Exercise02

#include <iostream>

#include "functions02.h"

int getSumOfAllOddNumbers(int input) {
	int sum = 0;
	for (int i = input; i >= 1; --i) {
		if (i % 2 == 1) {
			sum += i;
		}
	}
	return sum;
}

int getInteger() {
	std::cout << "Enter integer";
	int returnInt;
	std::cin >> returnInt;
	std::cout << "\n";

	return returnInt;
}
