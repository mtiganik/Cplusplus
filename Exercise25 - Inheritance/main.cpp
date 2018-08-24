/// FILE NAME: main.cpp
/// PROJECT: Exercise25
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED: 22.06.2018
///
/// DESCRIPTION: Create Triangle, Rectangle and Ellipse
///  classes. They should inherent from Shape class. They
///  all should contain width and height fields, and methods
///  to get perimeter and area. In addition, triangle should
///  should contain all 3 side sizes

#include "Shape.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "Rectangle.h"
#include <iostream>

int main(void) {
	Ellipse e1(1,2);
	Rectangle r1(1, 2);
	Triangle t1(1, 2);
	Triangle t2(2, 2, 3);
	std::cout << t1.GetArea() << std::endl;
	std::cout << t1.GetPerimeter() << std::endl;
	std::cout << t2.GetArea() << std::endl;
	std::cout << t2.GetPerimeter() << std::endl;

	std::cout << e1.GetArea() << std::endl;
	std::cout << r1.GetArea() << std::endl;

	
	std::system("pause");
	return 0;
}