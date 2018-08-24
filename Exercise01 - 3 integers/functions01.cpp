/// FILE NAME: functions01.cpp
/// PROJECT: Exercise01
/// AUTHOR: Mihkel Tiganik
/// CREATED: 21.06.2018
///
/// DESCRIPTION:  Definitions of functions for Exercise01

#include <iostream>

#include "functions01.h"

int getSmallest(int i1, int i2, int i3) {
	if (i1 <= i2 && i1 <= i3) {
		return i1;
	}
	else if (i2 <= i3) {
		return i2;
	}
	else return i3;
}

int getBiggest(int i1, int i2, int i3) {
	if (i1 >= i2 && i1 >= i3)
	{
		return i1;
	}
	else if (i2 >= i3)
	{
		return i2;
	}
	else return i3;
}

int getProduct(int i1, int i2, int i3) {
	return i1 * i2*i3;
}

int getSum(int i1, int i2, int i3) {
	return i1 + i2 + i3;
}

int getInteger(int input) {
	switch (input) {
	case(1):
		std::cout << "Enter first integer\n";
		break;
	case(2):
		std::cout << "Enter second integer\n";
		break;
	case(3):
		std::cout << "Enter third integer\n";
		break;
	default:
		std::cout << "Enter integer\n";
		break;
	}
	int returnInt;
	std::cin >> returnInt;
	std::cout << "\n";
	return returnInt;
}

int getInteger() {
	std::cout << "Enter integer";
	int returnInt;
	std::cin >> returnInt;
	return returnInt;
}
