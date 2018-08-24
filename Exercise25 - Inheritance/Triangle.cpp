/// FILE NAME: Triangle.cpp
/// PROJECT: Exercise25
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Definitions of Triangle methods

#include "Triangle.h"
#include <math.h>


double Triangle::GetArea()
{
	if ((m_s1 + m_s1 > m_s3) && (m_s1 + m_s3 > m_s2) && (m_s2 + m_s3 > m_s1)) {
		double semiperimeter = (m_s1 + m_s2 + m_s3) / 2;
		return sqrt(semiperimeter*(semiperimeter - m_s1)*(semiperimeter - m_s2)*(semiperimeter - m_s3));
	}else
	return m_width * m_height / 2; // assume we have rectangular triangle
}

double Triangle::GetPerimeter()
{
	return m_s1 + m_s2 + m_s3;
}

Triangle::Triangle(double s1, double s2, double s3)
	: m_s1{ s1 }, m_s2{ s2 }, m_s3{ s3 }
{
	m_width = m_s1; m_height = 2* GetArea()/ m_s1; 
}

Triangle::Triangle(double width, double height)
	: Shape(width, height)
{
	// we assume it is rectangular triangle
	m_s1 = m_width; 
	m_s2 = m_height;
	m_s3 = sqrt(pow(m_width, 2) + pow(m_height, 2));
}

Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}
