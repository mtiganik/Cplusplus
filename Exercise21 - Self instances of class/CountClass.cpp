/// FILE NAME: CountClass.cpp
/// PROJECT: Exercise21
/// AUTHOR: Mihkel Tiganik
/// CREATED: 18.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Definitions of CountClass methods

#include <iostream>

#include "CountClass.h"

int CountClass::counter = 0;

CountClass::CountClass()
{
	counter++;
}

int CountClass::count() {
	return counter;
}

CountClass::~CountClass()
{
	counter--;
}
