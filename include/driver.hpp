#ifndef DRIVER_HPP
#define DRIVER_HPP
#include "date.hpp"
#include "address.hpp"
#include "ticket.hpp"
#include "MedicalCondition.hpp"
using namespace std;

class Driver {
public:
	Driver();

	// Setters //
	void setLicenseID(int id);
	void setName(string name);
	void setDOB(Date dob);
	void setAddress(Address address);
	void setExperience(int experienceYears);
	void setLicenseDate(Date licenseIssueDate);
	void setTicket(Ticket ticket);
	void setWorkType(string workType);
	void setMedicalCondition(MedicalCondition condition);

	// Getters //
	int getLicenseID();
	string getName();
	Date getDOB();
	Date getLicenseDate();
	Address getAddress();
	int getExperience();
	bool getHasTicket();
	Ticket getTicket();
	string getWorkType();
	MedicalCondition getMedicalCondition();

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
	MedicalCondition medicalCondition;
};

#endif
