#ifndef ADDRESS_HPP
#define ADDRESS_HPP
#include <iostream>
#include <string>
using namespace std;

class Address {
public:
	Address();
	// Constructor With Address Info Input //
	Address(string street, string city, string county);
private:
	// Address Variables //
	string street;
	string city;
	string county;
};

#endif
