/// FILE NAME: functions19.h
/// PROJECT: Exercise19
/// AUTHOR: Mihkel Tiganik
/// CREATED: 22.06.2018
///
/// DESCRIPTION:  Declarations of functions for Exercise19

#ifndef EXERCISE19_HEADER_
#define EXERCISE19_HEADER_

#include <iostream>
#include <vector>

std::vector<std::string> Split(const std::string &s, char delim); 
template<typename Out>
void Split(const std::string &s, char delim, Out result);
void DisplayResult(std::string filename);

#endif // !EXERCISE19_HEADER_

