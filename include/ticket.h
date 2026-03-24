#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <string>
#include "date.h"
using namespace std;

class Ticket {
public:
	Ticket();
	// Constructor With Address Info Input //
	Ticket(Date issueDate, string location);
private:
	// Ticket Variables //
	Date issueDate;
	string location;
};

#endif
