#ifndef GOVERNMENTDRIVER_HPP
#define GOVERNMENTDRIVER_HPP
#include <iostream>
#include "driver.hpp"
using namespace std;

class GovernmentDriver : public Driver {
public:
	// Setter //
	void setDepartment(string department);
private:
	string department;
};

#endif
