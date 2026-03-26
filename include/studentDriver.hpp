#ifndef STUDENTDRIVER_HPP
#define STUDENTDRIVER_HPP
#include <iostream>
#include "driver.hpp"
using namespace std;

class StudentDriver : public Driver {
public:
	// Setter //
	void setUniversity(string university);
private:
	string university;
};

#endif
