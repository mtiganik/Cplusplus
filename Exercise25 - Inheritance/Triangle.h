/// FILE NAME: Triangle.h
/// PROJECT: Exercise25
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Header file for Triangle

#ifndef EXERCISE25_TRIANGLE_
#define EXERCISE25_TRIANGLE_

#include "Shape.h"

class Triangle :
	public Shape
{
	double m_s1, m_s2, m_s3;
public:
	double GetArea();
	double GetPerimeter();
	Triangle(double s1, double s2, double s3);
	Triangle(double width, double height);
	Triangle();
	~Triangle();
};

#endif // !EXERCISE25_TRIANGLE_