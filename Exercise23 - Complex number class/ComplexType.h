/// FILE NAME: ComplexType.h
/// PROJECT: Exercise23
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Header file for ComplexType

#ifndef EXERCISE23_COMPLEXTYPE_
#define EXERCISE23_COMPLEXTYPE_

#include <iostream>
#include <string>
#include <cstdio>


class ComplexType
{
	double m_real;
	double m_imaginary;
	bool isNearlyEqual(double x, double y);

public:
	ComplexType();
	ComplexType(double real, double imaginary);
	~ComplexType();
	friend std::ostream & operator << (std::ostream &out, ComplexType a);
	friend ComplexType operator+(ComplexType a, ComplexType b);
	friend ComplexType operator-(ComplexType a, ComplexType b);
	friend ComplexType operator*(ComplexType a, ComplexType b);
	friend ComplexType operator/(ComplexType a, ComplexType b);

	void Print();
	double GetRadius();
	double GetAngle();
};

#endif // !EXERCISE23_COMPLEXTYPE_