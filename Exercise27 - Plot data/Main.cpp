/// FILE NAME: Main.cpp
/// PROJECT: Exercise27
/// AUTHOR: Mihkel Tiganik
/// CREATED: 15.06.2018
/// MODIFIED: 22.06.2018
///
/// DESCRIPTION: Program receives a csv file with measured parameters
///  of function. First column represent measured values of X axis, and 
///  second column Y axis. Program creates parabolic function out of those
///  values. After that program suggests user to insert any float number
///  in range of X axis and program prints Y value at this point

#include <iostream>

#include "LineClass.h"

int main(void)
{
	std::string filename = "input.csv";  // only use csv files which have x y pairs just like "input.csv" has
	LineClass lineClass;
	lineClass.getDataFromFile(filename);
	lineClass.DisplayPlot();
	lineClass.getUserInput();

	system("pause");
	return 0;
}

