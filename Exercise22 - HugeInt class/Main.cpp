/// FILE NAME: Main.cpp
/// PROJECT: Exercise22
/// AUTHOR: Mihkel Tiganik
/// CREATED: 18.06.2018
/// MODIFIED: 22.06.2018
///
/// DESCRIPTION: Create a HugeInt class which can contain
///  integers with 100 digits. This class overwrites all
///  common operations (+,-,=,*,/,%,<<,==,!=,>,<=,<,<=)

#include <iostream>

#include "HugeInt.h"


int main(void) {
	HugeInt h1("1111222233334444555566667777888899990000");
	HugeInt h2("1111222233334444555566667777888899990000");
	HugeInt h3("1234567890000000000");
	HugeInt h4("101");
	HugeInt h5 = 123432143;

	if (h1 != h2) {
		std::cout << "true" ;
	}
	else std::cout << "false";
  std::cout << std::endl;

  std::cout << h1 + h3 << std::endl;
  std::cout << h1 * h2 << std::endl; // There are some bugs, but it was best I could do
  std::cout << h3 - h4 << std::endl; // h3 has to be bigger than h4, oterwise -1
  std::cout << h3 / h4 << std::endl; // h4 can't be bigger that 1e9
  std::cout << h3 % h4 << std::endl; // h4 can't be bigger that 1e9
  std::cout << h5 << std::endl;
  std::system("pause");
	return 0;
}