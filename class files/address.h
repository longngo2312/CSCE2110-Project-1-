#include <iostream>
#include <string>
#ifndef ADDRESS_H
#define ADDRESS_H
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