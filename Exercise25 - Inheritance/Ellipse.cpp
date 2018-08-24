/// FILE NAME: Ellipse.cpp
/// PROJECT: Exercise25
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Definitions of Ellipse methods


#include "Ellipse.h"



double Ellipse::GetArea()
{
	return PI * m_width * m_height;
}

double Ellipse::GetPerimeter()
{
	return 2 * PI * sqrt((pow(m_width,2) + pow(m_height,2))/2);
}

Ellipse::Ellipse()
{
}

Ellipse::Ellipse(double width, double height)
	: Shape(width, height)
{
}


Ellipse::~Ellipse()
{
}
