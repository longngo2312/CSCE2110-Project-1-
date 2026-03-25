#ifndef DRIVERLIST_HPP
#define DRIVERLIST_HPP
#include "driver.hpp"
using namespace std;

struct Node{
    Driver data;
    Node* next;
    Node* prev;
    Node(Driver data);
};

class DriverList{
private:
    Node* head; 
    Node* tail;
    int count;
public:
    //constructors
    DriverList();
    ~DriverList();

    //helper 
    void insertAfter(Driver data, Node* traverse);

    // Insert
    void insertAtBeginning(Driver data);
    void insertAtEnd(Driver data);
    void insertAfterValue(string criteria, string value, Driver data);
    void insertAfterValue(string criteria, int value, Driver data);

    // Search
    Driver searchByLicenseID(int licenseID);
    Driver searchByName(string name);
    Driver searchByCounty(string county);

    // Remove
    Driver removeByLicenseID(int licenseID);

    // Display
    void display();

    // Getters
    int getSize();
    Node* getHead();
    Node* getTail();

};



#endif

