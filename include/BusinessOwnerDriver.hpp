#ifndef BUSINESSOWNERDRIVER_HPP
#define BUSINESSOWNERDRIVER_HPP
#include <iostream>
#include <string>
#include "driver.hpp"
using namespace std;

class BusinessOwnerDriver : public Driver {
public:
	// Setter //
	void setBusinessName(string businessName);
private:
	string businessName;
};

#endif
