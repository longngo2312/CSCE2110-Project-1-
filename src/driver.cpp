#include <iostream>
#include "driver.hpp"
using namespace std;

Driver::Driver() {
	licenseID = 0;
	experienceYears = 0;
	hasTicket = false;
	medicalCondition = MedicalCondition::Fit;
}

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
void Driver::setMedicalCondition(MedicalCondition condition) {
	this->medicalCondition = condition;
}

// Getters //
int Driver::getLicenseID() {
	return licenseID;
}
string Driver::getName() {
	return name;
}
Date Driver::getDOB() {
	return dob;
}
Date Driver::getLicenseDate() {
	return licenseIssueDate;
}
Address Driver::getAddress() {
	return address;
}
int Driver::getExperience() {
	return experienceYears;
}
bool Driver::getHasTicket() {
	return hasTicket;
}
Ticket Driver::getTicket() {
	return ticket;
}
string Driver::getWorkType() {
	return workType;
}
MedicalCondition Driver::getMedicalCondition() {
	return medicalCondition;
}
