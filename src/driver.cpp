#include <iostream>
#include "driver.h"
using namespace std;

// Setters //
void Driver::setLicenseID(int id) {
	this->licenseID = id;
}
void Driver::setName(string name) {
	this->name = name;
}
void Driver::setDOB(Date dob) {
	this->dob = dob;
}
void Driver::setAddress(Address address) {
	this->address = address;
}
void Driver::setExperience(int experienceYears) {
	this->experienceYears = experienceYears;
}
void Driver::setLicenseDate(Date licenseIssueDate) {
	this->licenseIssueDate = licenseIssueDate;
}
void Driver::setTicket(Ticket ticket) {
	this->ticket = ticket;
	hasTicket = true;
}
void Driver::setWorkType(string workType) {
	this->workType = workType;
}

// Getters //
int Driver::getLicenseID() {
	return licenseID;
}

Date Driver::getLicenseDate() {
	return licenseIssueDate;
}
string Driver::getWorkType() {
	return workType;
}
