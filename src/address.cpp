#include <iostream>
#include <string>
#include "address.hpp"
using namespace std;

Address::Address() {}

// Constructor With Address Info Input //
Address::Address(string street, string city, string county) {
	this->street = street;
	this->city = city;
	this->county = county;
}

// Getters //
string Address::getStreet() {
	return street;
}
string Address::getCity() {
	return city;
}
string Address::getCounty() {
	return county;
}
