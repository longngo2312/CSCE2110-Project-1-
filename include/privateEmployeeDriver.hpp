#ifndef PRIVATEEMPLOYEEDRIVER_HPP
#define PRIVATEEMPLOYEEDRIVER_HPP
#include <iostream>
#include "driver.hpp"
using namespace std;

class PrivateEmployeeDriver : public Driver {
public:
	// Setter //
	void setCompany(string company);
private:
	string company;
};

#endif
