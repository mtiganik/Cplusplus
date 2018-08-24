/// FILE NAME: Main.cpp
/// PROJECT: Exercise23
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED: 22.06.2018
///
/// DESCRIPTION: Create a class of ComplexType, which
///  contains a real and imaginary parts. This class
///  should support sum, difference, multiplication
///  and division operands

#include <stdio.h>
#include <iostream>
#include <math.h>

#include "ComplexType.h"


int main(void) {
	ComplexType c1(4, 5);
	ComplexType c2(5, 8);

	std::cout << c1 + c2 << std::endl;
	std::cout << c1 - c2 << std::endl;
	std::cout << c1 * c2 << std::endl;
	std::cout << c1 / c2 << std::endl;

	std::system("pause");
	return 0;
}