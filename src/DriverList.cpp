#include "DriverList.hpp"
#include "driver.hpp"

using namespace std;

Node::Node(Driver data){
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

DriverList::DriverList(){
    head = nullptr;
    tail = nullptr;
    count = 0;
}

void DriverList::insertAfter(Driver data, Node* traverse){
    Node* newNode = new Node(data);
    newNode->prev = traverse;
    newNode->next = traverse->next;
    if (traverse->next != nullptr){
        traverse->next->prev = newNode;
    } 
    else {
        tail = newNode;
    }
    traverse->next = newNode;
    count++;
}

DriverList::~DriverList(){
    Node* traverse = head;
    while (traverse != nullptr){
        Node* deleteN = traverse;
        traverse = traverse->next;
        delete deleteN;
    }
}

void DriverList::insertAtBeginning(Driver data){
    Node* newNode = new Node(data);
    if (head == nullptr){
        head = tail = newNode;
    }
    else{
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    count++;
}

void DriverList::insertAtEnd(Driver data){
    Node* newNode = new Node(data);
    if (head == nullptr){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}

void DriverList::insertAfterValue(string criteria, string value, Driver data){
    Node* traverse = head;
    if (criteria == "name"){
        while (traverse != nullptr && traverse->data.getName() != value){
            traverse = traverse->next;
        }
    }
    else if(criteria == "county"){
        while (traverse != nullptr && traverse->data.getAddress().getCounty() != value){
            traverse = traverse->next;
        }
    }
    if (traverse != nullptr){
        insertAfter(data, traverse);
    } 
    else {
        cout << "Error: Driver not found." << endl;
    }
}

void DriverList::insertAfterValue(string criteria, int value, Driver data){
    Node* traverse = head;
    while (traverse != nullptr && traverse->data.getLicenseID() != value){
        traverse = traverse->next;
    }
    if (traverse != nullptr){
        insertAfter(data, traverse);
    } 
    else {
        cout << "Error: Driver not found." << endl;
    }
}

// Search
Driver DriverList::searchByLicenseID(int licenseID){
    Node* traverse = head;
    while (traverse != nullptr){
        if (traverse->data.getLicenseID() == licenseID){
            return traverse->data;
        }
        traverse = traverse->next;
    }
    cout << "Driver not found." << endl;
    return Driver();
}

Driver DriverList::searchByName(string name){
    Node* traverse = head;
    while (traverse != nullptr){
        if (traverse->data.getName() == name){
            return traverse->data;
        }
        traverse = traverse->next;
    }
    cout << "Driver not found." << endl;
    return Driver();
}

Driver DriverList::searchByCounty(string county){
    Node* traverse = head;
    while (traverse != nullptr){
        if (traverse->data.getAddress().getCounty() == county){
            return traverse->data;
        }
        traverse = traverse->next;
    }
    cout << "Driver not found." << endl;
    return Driver();
}

// Remove
Driver DriverList::removeByLicenseID(int licenseID){
    Node* traverse = head;
    while (traverse != nullptr && traverse->data.getLicenseID() != licenseID){
        traverse = traverse->next;
    }
    if (traverse == nullptr){
        cout << "Error: Driver not found." << endl;
        return Driver();
    }

    Driver removed = traverse->data;

    if (traverse == head && traverse == tail){
        head = tail = nullptr;
    }
    else if (traverse == head){
        head = head->next;
        head->prev = nullptr;
    }
    else if (traverse == tail){
        tail = tail->prev;
        tail->next = nullptr;
    }
    else{
        traverse->prev->next = traverse->next;
        traverse->next->prev = traverse->prev;
    }

    delete traverse;
    count--;
    return removed;
}

// Display
void DriverList::display(){
    Node* traverse = head;
    if (traverse == nullptr){
        cout << "List is empty." << endl;
        return;
    }
    while (traverse != nullptr){
        cout << "License ID: " << traverse->data.getLicenseID()
             << " | Name: " << traverse->data.getName()
             << " | Work Type: " << traverse->data.getWorkType()
             << endl;
        traverse = traverse->next;
    }
}

// Getters
int DriverList::getSize(){
    return count;
}

Node* DriverList::getHead(){
    return head;
}

Node* DriverList::getTail(){
    return tail;
}

