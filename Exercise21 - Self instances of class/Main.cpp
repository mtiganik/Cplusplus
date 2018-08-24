/// FILE NAME: Main.cpp
/// PROJECT: Exercise21
/// AUTHOR: Mihkel Tiganik
/// CREATED: 18.06.2018
/// MODIFIED: 22.06.2018
///
/// DESCRIPTION: There is class that will count the number
///  of self instances. Class have a public member 'counter'
///  which shows current active instances of this class

#include <iostream>

#include "CountClass.h"

int main(void)
{
	CountClass c1;
	CountClass c2;
	CountClass c3;
	CountClass c4;

	std::cout << "number of objects: " << c1.count() << std::endl;
	c1.~CountClass();
  std::cout << "number of objects: " << c1.count() << std::endl;

	system("pause");
	return 0;
}