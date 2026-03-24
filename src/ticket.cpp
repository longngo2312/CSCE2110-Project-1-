#include <iostream>
#include <string>
#include "ticket.h"
using namespace std;

Ticket::Ticket() {}

// Constructor With Ticket Info Input //
Ticket::Ticket(Date issueDate, string location) {
	this->issueDate = issueDate;
	this->location = location;
}
