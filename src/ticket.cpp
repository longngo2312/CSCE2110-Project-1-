#include <iostream>
#include <string>
#include "ticket.hpp"
using namespace std;

Ticket::Ticket() {}

// Constructor With Ticket Info Input //
Ticket::Ticket(Date issueDate, string location) {
	this->issueDate = issueDate;
	this->location = location;
}

// Getters //
Date Ticket::getIssueDate() {
	return issueDate;
}
string Ticket::getLocation() {
	return location;
}
