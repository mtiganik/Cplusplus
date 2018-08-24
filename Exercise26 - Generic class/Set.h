/// FILE NAME: Set.h
/// PROJECT: Exercise26
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Header file for Set

#ifndef EXERCISE26_SET_
#define EXERCISE26_SET_

#include <iostream>
#include <vector>
#include <string>

template <class T>
class Set
{
private:
	std::vector<T> m_elems; // elemens
public:
	void Push(T const& elem);
	void DisplayValues();
	Set<T> GetIntersection(const Set& b);
	Set<T> GetUnion(const Set& b);
	Set<T> GetComplement(const Set& b);
	Set(T initi);
	Set();
	~Set();
};
#endif // !EXERCISE26_SET_





