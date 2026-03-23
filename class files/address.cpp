#include <iostream>
#include <string>
#include "address.h"
using namespace std;

Address::Address() {}

// Constructor With Date Input //
Address::Address(string street, string city, string county) {
	this->street = street;
	this->city = city;
	this->county = county;
}