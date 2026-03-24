#ifndef STUDENTDRIVER_H
#define STUDENTDRIVER_H
#include <iostream>
#include "driver.h"
using namespace std;

class StudentDriver : public Driver {
public:
	// Setter //
	void setUniversity(string university);
private:
	string university;
};

#endif
