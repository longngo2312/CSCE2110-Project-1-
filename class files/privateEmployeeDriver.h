#include <iostream>
#ifndef PRIVATEEMPLOYEEDRIVER_H
#define PRIVATEEMPLOYEEDRIVER_H
#include "driver.h"
using namespace std;

class PrivateEmployeeDriver : public Driver {
public:
	// Setter //
	void setCompany(string company);
private:
	string company;
};

#endif