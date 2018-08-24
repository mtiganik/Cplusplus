/// FILE NAME: Rectangle.cpp
/// PROJECT: Exercise25
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Definitions of Rectangle methods


#include "Rectangle.h"



double Rectangle::GetArea()
{
	return m_width * m_height;
}

double Rectangle::GetPerimeter()
{
	return 2 * m_width + 2 * m_height;
}

Rectangle::Rectangle(double width, double height)
	:Shape(width, height)
{
}

Rectangle::Rectangle()
{
}


Rectangle::~Rectangle()
{
}
