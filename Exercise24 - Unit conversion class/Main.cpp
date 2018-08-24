/// FILE NAME: Main.cpp
/// PROJECT: Exercise24
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED: 22.06.2018
///
/// DESCRIPTION: Create a class length. It is possible 
///  to initialize it with different length types (cm,
///  m, in, ft). This class should support sum, difference,
///  multiplication and division operands.

#include <stdio.h>
#include <iostream>

#include "Length.h"

int main(void) {
	Length l1(10, "m");
	Length l2(15, "ft");
	std::cout << l1 << std::endl;
	std::cout << l2 << std::endl;
	std::cout << l1 + l2 << std::endl;
	std::cout << l1 - l2 << std::endl;
	std::cout << l1 * l2 << std::endl;
	std::cout << l1 / l2 << std::endl;

	std::system("pause");
	return 0;
}