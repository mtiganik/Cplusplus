/// FILE NAME: LineClass.cpp
/// PROJECT: Exercise27
/// AUTHOR: Mihkel Tiganik
/// CREATED: 15.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Definitions of LineClass methods

#include <iostream>
#include <stdio.h>
#include<iomanip>
#include<cmath>

#include "LineClass.h"

LineClass::LineClass()
{
}


LineClass::~LineClass()
{
}

void LineClass::gotoxy(int column, int line) {
	_coord.X = column;
	_coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		_coord
	);
}

void LineClass::getUserInput() {
	gotoxy(0, 0);
	float insertedXValue;
	std::cout << "Polynom from " << std::endl << "0 to " << getMaxXValue() << std::endl;
  std::cout << "Enter x value:" << std::endl;
  std::cin >> insertedXValue;
  std::cout << "Result for this value is: " << std::endl << GetValue(insertedXValue) << std::endl;
	gotoxy(0, 21);
}

void LineClass::DisplayPlot() {

	HDC hDC = GetDC(GetConsoleWindow());
	float maxXValue = getMaxXValue();
	float maxYValue = getMaxYValue();

	HPEN Pen1 = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
	SelectObject(hDC, Pen1);

	for (int i = 0; i < Arr.size(); i++) {
		if (!isEqual(Arr[i][0], 0) || !isEqual(Arr[i][1], 0)) {
			MoveToEx(hDC, 220, 220 - Arr[i][1] * 200 / maxYValue, NULL);
			LineTo(hDC, 220 + Arr[i][0] * 200 / maxXValue, 220 - Arr[i][1] * 200 / maxYValue);
			LineTo(hDC, 220 + Arr[i][0] * 200 / maxXValue, 220);
		}
	}

	HPEN Pen2 = CreatePen(PS_SOLID, 5, RGB(255, 0, 225));
	SelectObject(hDC, Pen2);

	for (int i = 0; i < Arr.size() - 1; i++) {
		MoveToEx(hDC, 220 + Arr[i][0] * 200 / maxXValue, 220 - Arr[i][1] * 200 / maxYValue, NULL);
		LineTo(hDC, 220 + Arr[i][0] * 200 / maxXValue, 220 - Arr[i][1] * 200 / maxYValue);
	}

	HPEN Pen3 = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen3);

	//x axis
	MoveToEx(hDC, 200, 220, NULL);
	LineTo(hDC, 440, 220);

	//y axis
	MoveToEx(hDC, 220, 0, NULL);
	LineTo(hDC, 220, 240);

	PolynomValues = GetPolynomValue();
	//for (int i = 0; i < PolynomValues.size(); i++) {
	//	cout << PolynomValues[i] << endl;
	//}
	// show polynom until zero value
	float maxValue = GetPolynomZeroValue();
	//cout << GetValue(7) << endl;
	//cout << maxValue << endl;

	HPEN Pen4 = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	SelectObject(hDC, Pen4);

	for (int i = 0; i < 200; i++) {
		MoveToEx(hDC, 220 + (i * maxValue / 200) * 200 / maxXValue, 220 - GetValue(i * maxValue / 200) * 200 / maxYValue, NULL);
		LineTo(hDC, 220 + ((i+1) * maxValue / 200) * 200 / maxXValue, 220 - GetValue((i+1) * maxValue / 200) * 200 / maxYValue);
	}
}

// returns Polynom value at current point
float LineClass::GetValue(float input) {
	return PolynomValues[0] + PolynomValues[1] * input + PolynomValues[2] * input*input;
}

float LineClass::GetPolynomZeroValue() {
	float x1 = (-PolynomValues[1] - sqrt(PolynomValues[1] * PolynomValues[1] - 4 * PolynomValues[0] * PolynomValues[2])) / (2 * PolynomValues[2]);
	float x2 = (-PolynomValues[1] + sqrt(PolynomValues[1] * PolynomValues[1] - 4 * PolynomValues[0] * PolynomValues[2])) / (2 * PolynomValues[2]);

	if (x1 > x2) {
		return x1;
	}
	else return x2;
}

// Polynomial fit taken from bragitoff.com 2015/09/c-program-for-polynomial-fit-least-squares/
std::vector<float> LineClass::GetPolynomValue(int degree) {
	int i, j, k, n = degree;
	const int N = Arr.size();
  std::cout.precision(4);                        //set precision
  std::cout.setf(std::ios::fixed);
  std::vector<float> x, y, returnVector;
	for (i = 0; i < N; i++) {
		x.push_back(Arr[i][0]);
		y.push_back(Arr[i][1]);
	}
	float X[2 * 2 + 1];                        //Array that will store the values of sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n)
	for (i = 0; i<2 * n + 1; i++)
	{
		X[i] = 0;
		for (j = 0; j<N; j++)
			X[i] = X[i] + pow(x[j], i);        //consecutive positions of the array will store N,sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n)
	}
	float B[2 + 1][2 + 2], a[2 + 1];            //B is the Normal matrix(augmented) that will store the equations, 'a' is for value of the final coefficients
	for (i = 0; i <= n; i++)
		for (j = 0; j <= n; j++)
			B[i][j] = X[i + j];            //Build the Normal matrix by storing the corresponding coefficients at the right positions except the last column of the matrix
	float Y[2 + 1];                    //Array to store the values of sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
	for (i = 0; i<n + 1; i++)
	{
		Y[i] = 0;
		for (j = 0; j<N; j++)
			Y[i] = Y[i] + pow(x[j], i)*y[j];        //consecutive positions will store sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
	}
	for (i = 0; i <= n; i++)
		B[i][n + 1] = Y[i];                //load the values of Y as the last column of B(Normal Matrix but augmented)
	n = n + 1;                //n is made n+1 because the Gaussian Elimination part below was for n equations, but here n is the degree of polynomial and for n degree we get n+1 equations

	for (i = 0; i<n; i++)                    //From now Gaussian Elimination starts(can be ignored) to solve the set of linear equations (Pivotisation)
		for (k = i + 1; k<n; k++)
			if (B[i][i]<B[k][i])
				for (j = 0; j <= n; j++)
				{
					float temp = B[i][j];
					B[i][j] = B[k][j];
					B[k][j] = temp;
				}
	for (i = 0; i<n - 1; i++)            //loop to perform the gauss elimination
		for (k = i + 1; k<n; k++)
		{
			float t = B[k][i] / B[i][i];
			for (j = 0; j <= n; j++)
				B[k][j] = B[k][j] - t * B[i][j];    //make the elements below the pivot elements equal to zero or elimnate the variables
		}
	for (i = n - 1; i >= 0; i--)                //back-substitution
	{                        //x is an array whose values correspond to the values of x,y,z..
		a[i] = B[i][n];                //make the variable to be calculated equal to the rhs of the last equation
		for (j = 0; j<n; j++)
			if (j != i)            //then subtract all the lhs values except the coefficient of the variable whose value                                   is being calculated
				a[i] = a[i] - B[i][j] * a[j];
		a[i] = a[i] / B[i][i];            //now finally divide the rhs by the coefficient of the variable to be calculated
	}
	gotoxy(0, 15);
	for (i = 0; i < n; i++) {
		returnVector.push_back(a[i]);
	}
	return returnVector;
}

float LineClass::getMaxXValue() {
	float MaxValue = Arr[0][0];
	for (int i = 1; i < Arr.size(); i++) {
		if (Arr[i][0] > Arr[i - 1][0]) {
			MaxValue = Arr[i][0];
		}
	}
	return MaxValue;
}

float LineClass::getMaxYValue() {
	float MaxValue = Arr[0][1];
	for (int i = 1; i < Arr.size(); i++) {
		if (Arr[i][1] > Arr[i - 1][1]) {
			MaxValue = Arr[i][1];
		}
	}
	return MaxValue;
}

void LineClass::getDataFromFile(std::string input) {
  std::vector<std::string> LineVector;
  std::vector<float> FloatVector;
	float value1, value2;
  std::string line;
  std::ifstream fs;
	fs.open(input);
	if (!fs) {
    std::cout << "Error, could not find file" << std::endl;
		abort();
	}
	while (getline(fs, line)) {
		FloatVector.clear();
		LineVector = split(line, ';');
		value1 = strtof((LineVector[0]).c_str(), 0);
		value2 = strtof((LineVector[1]).c_str(), 0);
		FloatVector.push_back(value1);
		FloatVector.push_back(value2);
		Arr.push_back(FloatVector);
	}
	fs.close();
}

std::vector<std::string> LineClass::split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, back_inserter(elems));
	return elems;
}

template<typename Out>
void LineClass::split(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (getline(ss, item, delim)) {
		*(result++) = item;
	}
}

COORD LineClass::GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
	{
		return cbsi.dwCursorPosition;
	}
	else
	{
		// The function failed. Call GetLastError() for details.
		COORD invalid = { 0, 0 };
		return invalid;
	}
}

inline bool LineClass::isEqual(double x, double y)
{
	const double epsilon =  1e-5;
	return abs(x - y) <= epsilon * abs(x);
}
