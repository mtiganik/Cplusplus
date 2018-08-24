/// FILE NAME: main.cpp
/// PROJECT: Exercise01
/// AUTHOR: Mihkel Tiganik
/// CREATED: 06.06.2018
/// MODIFIED: 21.06.2018
///
/// DESCRIPTION: Ask for 3 integers from the user and print out sum, product, biggest, smallest

#include <iostream>

#include "functions01.h"

int main() 
{
	int i1 = getInteger(1);
	int i2 = getInteger(2);
	int i3 = getInteger(3);
	std::cout << "Sum of " << i1 << ", " << i2 << ", " << i3 << " is " << getSum(i1, i2, i3) << "\n";
	std::cout << "Product of " << i1 << ", " << i2 << ", " << i3 << " is " << getProduct(i1, i2, i3) << "\n";
	std::cout << "Biggest number of " << i1 << ", " << i2 << ", " << i3 << " is " << getBiggest(i1, i2, i3) << "\n";
	std::cout << "Smallest number of " << i1 << ", " << i2 << ", " << i3 << " is " << getSmallest(i1, i2, i3) << "\n";

	std::system("pause");
	return 0;
}