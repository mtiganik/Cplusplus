/// FILE NAME: main.cpp
/// PROJECT: Exercise26
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED: 22.06.2018
///
/// DESCRIPTION: Create a generic class Set. It
///  contains an array of generic type. It should
///  contain methods that allow to get union,
///  intersection and complements with other sets


#include "Set.h"
#include "Set.cpp"

int main() {
		Set<int> intSet1(9);
		intSet1.Push(3);
		intSet1.Push(4);
		intSet1.Push(5);
		intSet1.Push(6);
		intSet1.Push(7);
		Set<int> intSet2;
		intSet2.Push(0);
		intSet2.Push(1);
		intSet2.Push(2);
		intSet2.Push(3);
		intSet2.Push(4);

		std::cout << "Intersection values from 2 int sets" << std::endl;
		Set<int> InterSection = intSet1.GetIntersection(intSet2);;
		InterSection.DisplayValues();
		std::cout << "Union values from 2 int sets" << std::endl;
		Set<int> Union = intSet1.GetUnion(intSet2);
		Union.DisplayValues();
		Set<int> Complement = intSet1.GetComplement(intSet2);
		std::cout << "Complent of set 1 from set 2" << std::endl;
		Complement.DisplayValues();

		Set<char> charSet1('a');
		charSet1.Push('b');
		charSet1.Push('c');
		charSet1.Push('d');
		charSet1.Push('e');
		charSet1.Push('f');
		Set<char> charSet2;
		charSet2.Push('d');
		charSet2.Push('e');
		charSet2.Push('f');
		charSet2.Push('g');
		charSet2.Push('h');
		charSet2.Push('i');
		std::cout << "Intersection values from 2 char sets" << std::endl;
		Set<char> InterSection2 = charSet1.GetIntersection(charSet2);
		InterSection2.DisplayValues();
		std::cout << "Union values from 2 char sets" << std::endl;
		Set<char> Union2 = charSet1.GetUnion(charSet2);
		Union2.DisplayValues();
		std::cout << "Complement values from 2 char sets" << std::endl;
		Set<char> Complemet2 = charSet1.GetComplement(charSet2);
		Complemet2.DisplayValues();

	std::system("pause");
	return 0;
}



