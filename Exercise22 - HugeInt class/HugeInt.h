/// FILE NAME: HugeInt.h
/// PROJECT: Exercise22
/// AUTHOR: Mihkel Tiganik
/// CREATED: 18.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Header file for HugeInt

#ifndef EXERCISE22_HUGEINT_
#define EXERCISE22_HUGEINT_

#include <iostream>
#include <string>
#include <vector>

class HugeInt
{
  std::vector<int> huge_int_arr_;
	void Separate(long double a);

public:
	HugeInt(std::string s);
	HugeInt(long double a);
	HugeInt();
	~HugeInt();

	void Print(HugeInt a);
	friend std::ostream & operator << (std::ostream &out, HugeInt a);
	friend bool operator<(HugeInt a, HugeInt b);
	friend bool operator>(HugeInt a, HugeInt b);
	friend bool operator<=(HugeInt a, HugeInt b);
	friend bool operator>=(HugeInt a, HugeInt b);
	friend bool operator==(HugeInt a, HugeInt b);
	friend bool operator!=(HugeInt a, HugeInt b);
	friend HugeInt operator+(HugeInt a, HugeInt b);
	friend HugeInt operator*(HugeInt a, HugeInt b);
	friend HugeInt operator-(HugeInt a, HugeInt b);
	friend HugeInt operator/(HugeInt a, HugeInt b);
	friend HugeInt operator%(HugeInt a, HugeInt b);

	template<typename T>
	T& operator=(const T& other);
};

#endif // !EXERCISE22_HUGEINT_