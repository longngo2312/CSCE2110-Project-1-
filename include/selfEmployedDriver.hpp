#ifndef SELFEMPLOYEDDRIVER_HPP
#define SELFEMPLOYEDDRIVER_HPP
#include <iostream>
#include <string>
#include "driver.hpp"
using namespace std;

class SelfEmployedDriver : public Driver {
public:
	// Setter //
	void setBusinessName(string businessName);
private:
	string businessName;
};

#endif
