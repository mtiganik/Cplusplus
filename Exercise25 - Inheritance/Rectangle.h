/// FILE NAME: Rectangle.h
/// PROJECT: Exercise25
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Header file for Rectangle

#ifndef EXERCISE25_RECTANGLE_
#define EXERCISE25_RECTANGLE_

#include "Shape.h"
class Rectangle :
	public Shape
{
public:
	double GetArea();
	double GetPerimeter();
	Rectangle(double width, double height);
	Rectangle();
	~Rectangle();
};

#endif // !EXERCISE25_RECTANGLE_