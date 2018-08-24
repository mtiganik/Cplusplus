/// FILE NAME: ComplexType.cpp
/// PROJECT: Exercise23
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Definitions of ComplexType methods

#include <stdlib.h>
#include <iostream>
#include <math.h>

#include "ComplexType.h"

#define PI 3.1415926535897932384626433

ComplexType::ComplexType() :
  m_real{ 0 }, m_imaginary{ 0 }
{
}

ComplexType::ComplexType(double real, double imaginary)
  : m_real{ real }, m_imaginary{ imaginary }
{
}

ComplexType::~ComplexType()
{
}

std::ostream & operator << (std::ostream &out, ComplexType a) {
	a.Print();
	return out;
}

ComplexType operator+(ComplexType a, ComplexType b) {
	ComplexType ans;
	ans.m_real = a.m_real + b.m_real;
	ans.m_imaginary = a.m_imaginary + b.m_imaginary;
	return ans;
}

ComplexType operator-(ComplexType a, ComplexType b) {
	ComplexType ans;
	ans.m_real = a.m_real - b.m_real;
	ans.m_imaginary = a.m_imaginary - b.m_imaginary;
	return ans;
}

ComplexType operator*(ComplexType a, ComplexType b) {
	ComplexType ans;
	ans.m_real = a.m_real * b.m_real - a.m_imaginary * b.m_imaginary;
	ans.m_imaginary = a.m_real * b.m_imaginary + a.m_imaginary * b.m_real;
	return ans;
}

ComplexType operator/(ComplexType a, ComplexType b) {
	ComplexType ans;
	double modulus = a.GetRadius() / b.GetRadius();
	ans.m_real = modulus * cos(a.GetAngle() - b.GetAngle());
	ans.m_imaginary = modulus * sin(a.GetAngle() - b.GetAngle());
	return ans;
}

void ComplexType::Print() {
  printf("%3.3f + i%3.3f", m_real, m_imaginary);
}


double ComplexType::GetRadius() {
	return sqrt(pow(m_real, 2) + pow(m_imaginary, 2));
}

double ComplexType::GetAngle() {
	if (m_real > 0) return atan(m_imaginary / m_real);
	if (m_real < 0 && m_imaginary >= 0) return atan(m_imaginary / m_real) + PI;
	if (m_real < 0 && m_imaginary < 0) return atan(m_imaginary / m_real) - PI;
	if (isNearlyEqual(m_real,0) && m_imaginary > 0) return PI / 2;
	if (isNearlyEqual(m_real, 0) && m_imaginary < 0) return -PI / 2;
	else return -1;
}

bool ComplexType::isNearlyEqual(double x, double y) {
	const double epsilon = 1e-5;
	return std::abs(x - y) <= epsilon * std::abs(x);
}

