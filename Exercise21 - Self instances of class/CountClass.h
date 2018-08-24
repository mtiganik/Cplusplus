/// FILE NAME: CountClass.h
/// PROJECT: Exercise21
/// AUTHOR: Mihkel Tiganik
/// CREATED: 18.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Header file for CountClass

#ifndef EXERCISE21_COUNTCLASS_
#define EXERCISE21_COUNTCLASS_

class CountClass
{
	static int counter;
public:
	int count();
	CountClass();
	~CountClass();
};

#endif // !EXERCISE21_COUNTCLASS_