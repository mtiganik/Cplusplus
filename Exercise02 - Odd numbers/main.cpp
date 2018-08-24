/// FILE NAME: main.cpp
/// PROJECTT: Exercise02
/// AUTHOR: Mihkel Tiganik
/// CREATED: 06.06.2018
/// MODIFIED: 21.06.2018
///
/// DESCRIPTION: Ask for 1 integer and sum all odd numbers between 1 and the given number

#include <iostream>

#include "functions02.h"

int main()
{
	int input = getInteger();
	std::cout << "Sum of odd numbers from " << input << " to 1 is " << getSumOfAllOddNumbers(input) << std::endl;

	std::system("pause");
	return 0;
}
