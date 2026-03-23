#include <iostream>
#ifndef GOVERNMENTDRIVER_H
#define GOVERNMENTDRIVER_H
#include "driver.h"
using namespace std;

class GovernmentDriver : public Driver {
public:
	// Setter //
	void setDepartment(string department);
private:
	string department;
};

#endif