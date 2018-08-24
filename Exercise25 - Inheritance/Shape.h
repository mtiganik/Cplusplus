/// FILE NAME: Shape.h
/// PROJECT: Exercise25
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Header file for Shape

#ifndef EXERCISE25_SHAPE_
#define EXERCISE25_SHAPE_


class Shape
{
protected:
	double m_width;
	double m_height;
public:
	double GetWidth();
	void SetWidth(double width);
	double GetHeight();
	void SetHeight(double height);
	virtual double GetArea() = 0;
	virtual double GetPerimeter() = 0;
	Shape();
	Shape(double width, double height);
	~Shape();
};

#endif // !EXERCISE25_SHAPE_