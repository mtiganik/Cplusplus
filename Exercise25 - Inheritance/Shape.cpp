/// FILE NAME: Shape.cpp
/// PROJECT: Exercise25
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Definitions of Shape methods


#include "Shape.h"



double Shape::GetWidth()
{
	return m_width;
}

void Shape::SetWidth(double width)
{
	m_width = width;
}

double Shape::GetHeight()
{
	return m_height;
}

void Shape::SetHeight(double height)
{
	m_height = height;
}

Shape::Shape()
{
	m_height = m_width = 0;
}

Shape::Shape(double width, double height)
	: m_width{width}, m_height{height}
{
}


Shape::~Shape()
{
}
