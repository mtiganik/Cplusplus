/// FILE NAME: Set.cpp
/// PROJECT: Exercise26
/// AUTHOR: Mihkel Tiganik
/// CREATED: 20.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Definitions of Set methods

#include "Set.h"  
#include <algorithm> 

template<class T>
Set<T>::Set(T init)
{
	m_elems.push_back(init);
}

template<class T>
Set<T>::Set()
{
}

template<class T>
Set<T>::~Set()
{
}

template<class T>
void Set<T>::Push(T const& elem)
{
	m_elems.push_back(elem);
}

template<class T>
void Set<T>::DisplayValues()
{
	for (unsigned int i = 0; i < m_elems.size(); i++) {
		std::cout << m_elems[i] << std::endl;
	}
}

template<class T>
Set<T> Set<T>::GetIntersection(const Set& b) {
	Set<T> ans;
	for (unsigned int i = 0; i < m_elems.size(); i++) {
		for (unsigned int j = 0; j < b.m_elems.size(); j++){
			if (m_elems[i] == b.m_elems[j]) {
				ans.m_elems.push_back(m_elems[i]);
			}
		}
	}

	return ans;
}

template<class T>
Set<T> Set<T>::GetUnion(const Set & b)
{
	Set<T> ans;
	for (unsigned int i = 0; i < m_elems.size(); i++) {
		ans.m_elems.push_back(m_elems[i]);
	}
	
	for (unsigned int i = 0; i < b.m_elems.size(); i++) {
		bool flag = false;
		for (unsigned int j = 0; j < m_elems.size(); j++) {
			if (b.m_elems[i] == m_elems[j]) {
				flag = true;
				continue;
			}
		}
		if (!flag) ans.m_elems.push_back(b.m_elems[i]);
	}
	return ans;
}

template<class T>
Set<T> Set<T>::GetComplement(const Set & b)
{
	Set<T> ans;
	for (unsigned int i = 0; i < m_elems.size(); i++) {
		bool flag = true;
		for (unsigned int j = 0; j < b.m_elems.size(); j++) {
			if (m_elems[i] == b.m_elems[j]) {
				flag = false;
			}
		}
		if (flag) {
			ans.m_elems.push_back(m_elems[i]);
		}
	}
	return ans;
}

