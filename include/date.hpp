#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>
using namespace std;

class Date {
public:
	Date();
	// Constructor With Date Input //
	Date(int d, int m, int y);
private:
	// Date Variables //
	int day;
	int month;
	int year;
};

#endif
