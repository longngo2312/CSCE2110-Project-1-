#ifndef TICKET_HPP
#define TICKET_HPP
#include <iostream>
#include <string>
#include "date.hpp"
using namespace std;

class Ticket {
public:
	Ticket();
	// Constructor With Ticket Info Input //
	Ticket(Date issueDate, string location);
private:
	// Ticket Variables //
	Date issueDate;
	string location;
};

#endif
