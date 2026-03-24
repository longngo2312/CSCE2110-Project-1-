#ifndef DRIVER_H
#define DRIVER_H
#include <iostream>
#include "date.h"
#include "address.h"
#include "ticket.h"
using namespace std;

class Driver {
public:
	// Setters //
	void setLicenseID(int id);
	void setName(string name);
	void setDOB(Date dob);
	void setAddress(Address address);
	void setExperience(int experienceYears);
	void setLicenseDate(Date licenseIssueDate);
	void setTicket(Ticket ticket);
	void setWorkType(string workType);

	// Getters //
	int getLicenseID();
	Date getLicenseDate();
	string getWorkType();

private:
	// Variables //
	int licenseID;
	string name;
	Date dob;
	Date licenseIssueDate;
	Address address;
	int experienceYears;
	bool hasTicket;
	Ticket ticket;
	string workType;
};

#endif
