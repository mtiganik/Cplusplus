/// FILE NAME: HugeInt.cpp
/// PROJECT: Exercise22
/// AUTHOR: Mihkel Tiganik
/// CREATED: 18.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Definitions of HugeInt methods


#include "HugeInt.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdio>


template<typename T>
T& HugeInt::operator=(const T& other) {
	if (this != &other) {
		if (other.size != size) {
			delete[] hugeInt;
			size = 0;
			hugeInt = nullptr;
			hugeInt = new int[other.hugeInt];
			hugeInt.size = other.size;
		}
		copy(other.hugeInt, other.hugeInt + other.size, hugeInt);
	}
	return *this;
}

HugeInt::HugeInt(std::string s)
{
	if (s.size() == 0) { huge_int_arr_.push_back(0); }
	while (s.size() % 9 != 0) s = '0' + s;
	for (int i = 0; i < s.size(); i += 9) {
		int v = 0;
		for (int j = i; j < i + 9; j++) { v = v * 10 + (s[j] - '0'); }

		huge_int_arr_.push_back(v);
	}
}

void HugeInt::Print(HugeInt a) {
	for (int i = 0; i < a.huge_int_arr_.size(); i++) {
		if (i == 0) {
			printf("%d", a.huge_int_arr_[i]);
		}
		else printf("%09d", a.huge_int_arr_[i]);
	}
  std::cout << std::endl;
}

std::ostream & operator << (std::ostream &out, HugeInt a) {
	a.Print(a);
	return out;
}


HugeInt operator+(HugeInt a, HugeInt b) {
  std::vector<int> ReverseVector;
	HugeInt ans;

	long base = 1e9;
	int carry = 0;
	int index = (a.huge_int_arr_ > b.huge_int_arr_) ? a.huge_int_arr_.size() - 1 : b.huge_int_arr_.size() - 1;
	if (a.huge_int_arr_.size() == b.huge_int_arr_.size()) {
		for (int i = index; i >= 0; i--) {
			if (i < a.huge_int_arr_.size()) carry += a.huge_int_arr_[i];
			if (i < b.huge_int_arr_.size()) carry += b.huge_int_arr_[i];
			ReverseVector.push_back(carry % base);
			carry /= base;
		}
		if (carry) ReverseVector.push_back(carry);
	}
	else if (a.huge_int_arr_.size() > b.huge_int_arr_.size()) {
		int bSize = b.huge_int_arr_.size() - 1;
		for (int i = index; i >= 0; i--) {
			if (i < a.huge_int_arr_.size()) carry += a.huge_int_arr_[i];
			if (bSize >= 0) carry += b.huge_int_arr_[bSize];
			bSize--;
			ReverseVector.push_back(carry % base);
			carry /= base;
		}
		if (carry) ReverseVector.push_back(carry);
	}
	else {
		int aSize = a.huge_int_arr_.size() - 1;
		for (int i = index; i >= 0; i--) {
			if (i < b.huge_int_arr_.size()) carry += b.huge_int_arr_[i];
			if (aSize >= 0) carry += a.huge_int_arr_[aSize];
			aSize--;
			ReverseVector.push_back(carry % base);
			carry /= base;
		}
		if (carry) ReverseVector.push_back(carry);
	}
	// Make answer in correct order
	for (int i = ReverseVector.size() - 1; i >= 0; i--) {
		ans.huge_int_arr_.push_back(ReverseVector[i]);
	}
	return ans;
}

HugeInt operator-(HugeInt a, HugeInt b) {
	HugeInt ans;
  std::vector<long> ReverseVector;
	int carry = 0;
	long base = 1e9;
	if (a.huge_int_arr_[0] < b.huge_int_arr_[0] && a.huge_int_arr_.size() <= b.huge_int_arr_.size()) {
		ReverseVector.push_back(-1);
    std::cout << "Minus values not implemented" << std::endl;
	}
	else {
		int bCounter = b.huge_int_arr_.size() - 1;
		for (int i = a.huge_int_arr_.size() - 1; i >= 0; i--) {
			if (a.huge_int_arr_[i] > (bCounter >= 0 ? b.huge_int_arr_[bCounter] : 0)) {
				ReverseVector.push_back((long)a.huge_int_arr_[i] + carry - (bCounter >= 0 ? (long)b.huge_int_arr_[bCounter] : 0) );
				carry = 0;
			}
			else {
				ReverseVector.push_back(base + (long)a.huge_int_arr_[i] + carry - (bCounter >= 0 ? (long)b.huge_int_arr_[bCounter] : 0));
				carry = -1;
			}
			bCounter--;
		}
	}
	for (int i = ReverseVector.size() - 1; i >= 0; i--) {
		ans.huge_int_arr_.push_back(ReverseVector[i]);
	}
	return ans;
}

HugeInt operator/(HugeInt a, HugeInt b) {
	HugeInt ans;
	if (b.huge_int_arr_.size() > 1) { 
    std::cout << "Division with numbers greater that 1e9 not implemented" << std::endl;
		ans.huge_int_arr_.push_back(-1); 
		return ans; 
	}
	int divisor = b.huge_int_arr_[0];
  std::vector<long> answerVector;
  std::vector<long> reverseVector;
	long base = 1e9;
	long long carrier = 0;

	for (int i = 0; i < a.huge_int_arr_.size(); i++) {
		answerVector.push_back((carrier * base  + a.huge_int_arr_[i]) / divisor);
		carrier = a.huge_int_arr_[i] % divisor;
	}
	carrier = 0;
	int counter = 0;
	for (int i = answerVector.size() - 1; i >= 0; i--) {
		carrier = answerVector[i]*pow(10, (long)log10((long)carrier + 1) +  counter )  + carrier;
		if (carrier / base > 0 || i == 0) {
			reverseVector.push_back(carrier % base);
			carrier /= base;
		}
		if (counter == 0) {
			counter++;
		}
	}
	if (carrier != 0) {
		reverseVector.push_back(carrier % base);
	}
	for (int i = reverseVector.size() - 1; i >= 0 ; i--) {
		ans.huge_int_arr_.push_back(reverseVector[i]);
	}
	return ans;
}

HugeInt operator%(HugeInt a, HugeInt b) {
	HugeInt ans;
	if (b.huge_int_arr_.size() > 1) {
    std::cout << "Modulus with divisioner greater than 1e9 not implemented" << std::endl;
		ans.huge_int_arr_.push_back(-1);
		return ans;
	}
	long divisor = b.huge_int_arr_[0];
	if (a.huge_int_arr_[a.huge_int_arr_.size() - 1] > divisor) {
		ans.huge_int_arr_.push_back(a.huge_int_arr_[a.huge_int_arr_.size() - 1] % divisor);
	}
	else {
		if (a.huge_int_arr_.size() == 1) {
			ans.huge_int_arr_.push_back(a.huge_int_arr_[0]);
		}
		else {
			ans.huge_int_arr_.push_back( (long long)(a.huge_int_arr_[1] * pow(10, 9) + a.huge_int_arr_[0]) % divisor);
		}
	}
	return ans;

}

HugeInt operator*(HugeInt a, HugeInt b) {
	HugeInt ans;
  std::vector<int> ReverseVector;
	long base = 1e9;
	ReverseVector.assign(a.huge_int_arr_.size() + b.huge_int_arr_.size(), 0);

	for (int i = a.huge_int_arr_.size() - 1; i >= 0; i--) {
		long carry = 0ll;
		for (int j = b.huge_int_arr_.size(); j > 0 || carry > 0; j--) {
			long long s = ReverseVector[i + j] + carry + (long)a.huge_int_arr_[i] * (j > 0 /*b.HugeIntArr.size()*/
				? (long)b.huge_int_arr_[j - 1] : 0ll);
			ReverseVector[i + j] = (s % base);
			carry = s / base;
		}
	}
	for (int i = 0; i < ReverseVector.size(); i++) {
		if (ReverseVector[i] != 0) {
			ans.huge_int_arr_.push_back(ReverseVector[i]);
		}
	}

	return ans;

}


bool operator<(HugeInt a, HugeInt b)
{
	if (a.huge_int_arr_.size() != b.huge_int_arr_.size()) return (a.huge_int_arr_.size() < b.huge_int_arr_.size());
	for (int i = 0; i < a.huge_int_arr_.size(); i++) {
		if (a.huge_int_arr_[i] != b.huge_int_arr_[i]) return (a.huge_int_arr_[i] < b.huge_int_arr_[i]);
	}
	return false;
}

bool operator>(HugeInt a, HugeInt b) {
	return (b < a);
}

bool operator==(HugeInt a, HugeInt b) {
	return (!(a < b) && !(b < a));
}

bool operator<=(HugeInt a, HugeInt b) {
	return (a < b || a == b);
}

bool operator>=(HugeInt a, HugeInt b) {
	return(b < a || b == a);
}

bool operator!=(HugeInt a, HugeInt b) {
	return !(a == b);
}

void HugeInt::Separate(long double a) {
	long carrier = 0, a_ = a;
	int base = 1e9;
	do {
		huge_int_arr_.push_back((int)a_ % base);
		a_ /= base;
	} while (a_ > 0);
}


HugeInt::HugeInt(long double a) 
{
	Separate(a);
}

HugeInt::HugeInt()
{

}


HugeInt::~HugeInt()
{
}
