/// FILE NAME: LineClass.h
/// PROJECT: Exercise27
/// AUTHOR: Mihkel Tiganik
/// CREATED: 15.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Header file for LineClass

#ifndef EXERCISE27_LINECLASS_
#define EXERCISE27_LINECLASS_

#include <Windows.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <iterator>

class LineClass
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD _coord;

	void gotoxy(int column, int line);
	COORD GetConsoleCursorPosition(HANDLE hConsoleOutput);
	std::vector<std::string> split(const std::string &s, char delim);


	template<typename Out>
	void split(const std::string &s, char delim, Out result);
  std::vector<float> PolynomValues;
  std::vector<float> GetPolynomValue(int degree = 2);

  std::vector< std::vector<float>> Arr; // getDataFromFile(string filename);
	float getMaxXValue();
	float getMaxYValue();
	inline bool isEqual(double x, double y);

	float GetValue(float input);
	float GetPolynomZeroValue();
public:
  LineClass();
  ~LineClass();
	void getDataFromFile(std::string input);
	void DisplayPlot();
	void getUserInput();
};

#endif // !EXERCISE27_LINECLASS_
