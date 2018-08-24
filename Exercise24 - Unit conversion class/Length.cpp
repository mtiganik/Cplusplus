/// FILE NAME: Length.cpp
/// PROJECT: Exercise24
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Definitions of Length methods

#include "Length.h"

void Length::Print() {
	switch (m_length_type) {
	case(cm):
		printf("%.3f cm", m_length);
		break;
	case(m):
		printf("%.3f meters", m_length);
		break;
	case(in):
		printf("%.3f inches", m_length);
		break;
	case(ft):
		printf("%.3f ft", m_length);
		break;
	default:
		printf("%.3f", m_length);
		break;
	}
}

std::ostream & operator << (std::ostream &out, Length a) {
	a.Print();
	return out;
}

Length operator+(Length a, Length b) {
	
	double LengthValue =a.m_length + b.m_length * a.ConversionValue() / b.ConversionValue();
	Length ans(LengthValue, a.m_length_type);
	return ans;

}

Length operator-(Length a, Length b) {

	double LengthValue = a.m_length - b.m_length * a.ConversionValue() / b.ConversionValue();
	Length ans(LengthValue, a.m_length_type);
	return ans;

}

Length operator*(Length a, Length b) {

	double LengthValue = a.m_length * b.m_length * a.ConversionValue() / b.ConversionValue();
	Length ans(LengthValue, a.m_length_type);
	return ans;

}

Length operator/(Length a, Length b) {

	double LengthValue = a.m_length / (b.m_length * a.ConversionValue() / b.ConversionValue());
	Length ans(LengthValue, a.m_length_type);
	return ans;

}

Length::Length(double length, std::string lengthType)
{
	m_length = length;
	if (lengthType == "cm") m_length_type = cm;
	else if (lengthType == "CM") m_length_type = cm;
	else if (lengthType == "Cm") m_length_type = cm;
	else if (lengthType == "m") m_length_type = m;
	else if (lengthType == "M") m_length_type = m;
	else if (lengthType == "in") m_length_type = in;
	else if (lengthType == "In") m_length_type = in;
	else if (lengthType == "IN") m_length_type = in;
	else if (lengthType == "ft") m_length_type = ft;
	else if (lengthType == "FT") m_length_type = ft;
	else if (lengthType == "Ft") m_length_type = ft;
	else m_length_type = cm; // default
}

Length::Length(double length, LengthType lengthType)
	: m_length{length} , m_length_type{lengthType}
{

}

Length::Length()
{
}

Length::~Length()
{
}

double Length::ConversionValue() {
	switch (m_length_type) {
	case(cm):
		return 1;
		break;
	case(m):
		return M;
		break;
	case(in):
		return IN;
		break;
	case(ft):
		return FT;
		break;
	default:
		return 1;
		break;

	}
}