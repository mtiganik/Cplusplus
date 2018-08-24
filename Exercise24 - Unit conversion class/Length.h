/// FILE NAME: Length.h
/// PROJECT: Exercise24
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Header file for Length

#ifndef EXERCISE24_LENGTH_
#define EXERCISE24_LENGTH_

#include <string>
#include <stdio.h>
#include <iostream>
#include "enums.cpp"

// conversion values to cm
#define IN 0.393700787
#define FT 0.032808399
#define M 0.01

class Length
{
	double m_length;
	LengthType m_length_type;

	double ConversionValue();

public:

	void Print();
	friend std::ostream & operator << (std::ostream &out, Length a);
	friend Length operator+(Length a, Length b);
	friend Length operator-(Length a, Length b);
	friend Length operator*(Length a, Length b);
	friend Length operator/(Length a, Length b);

	Length(double length, std::string lengthType);
	Length(double length, LengthType lengthType);
	Length();
	~Length();

};

#endif // !EXERCISE24_LENGTH_