#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include "driver.hpp"
using namespace std;

struct HashNode{
    int key;
    Driver data;
    HashNode* next;
    HashNode(int key, Driver data);
};

class HashTable{
private:
    HashNode** table;
    int size;
    int count;

    int hashFunction(int key);

public:
    // Constructors
    HashTable(int size);
    ~HashTable();

    // Insert
    void insert(Driver data);

    // Search
    Driver search(int licenseID);

    // Remove
    Driver remove(int licenseID);

    // Display
    void display();

    // Getters
    int getSize();
    int getCount();
};

#endif
