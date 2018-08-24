/// FILE NAME: Ellipse.h
/// PROJECT: Exercise25
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Header file for Ellipse

#ifndef EXERCISE25_ELLIPSE_
#define EXERCISE25_ELLIPSE_

#include <math.h>

#include "Shape.h"

#define PI 3.14159265359
class Ellipse :
	public Shape
{
public:
	double GetArea();
	double GetPerimeter();
	Ellipse();
	Ellipse(double width, double height);
	~Ellipse();
};

#endif // !EXERCISE25_ELLIPSE_