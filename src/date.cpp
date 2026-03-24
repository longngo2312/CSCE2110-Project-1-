#include <iostream>
#include "date.hpp"
using namespace std;

Date::Date() {}

// Constructor With Date Input //
Date::Date(int d, int m, int y) {
	this->day = d;
	this->month = m;
	this->year = y;
}
