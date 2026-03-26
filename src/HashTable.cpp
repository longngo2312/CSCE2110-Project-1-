#include "HashTable.hpp"
#include "driver.hpp"

using namespace std;

HashNode::HashNode(int key, Driver data){
    this->key = key;
    this->data = data;
    this->next = nullptr;
}

HashTable::HashTable(int size){
    this->size = size;
    this->count = 0;
    table = new HashNode*[size];
    for (int i = 0; i < size; i++){
        table[i] = nullptr;
    }
}

HashTable::~HashTable(){
    for (int i = 0; i < size; i++){
        HashNode* traverse = table[i];
        while (traverse != nullptr){
            HashNode* deleteN = traverse;
            traverse = traverse->next;
            delete deleteN;
        }
    }
    delete[] table;
}

int HashTable::hashFunction(int key){
    return key % size;
}

// Insert
void HashTable::insert(Driver data){
    int index = hashFunction(data.getLicenseID());
    HashNode* newNode = new HashNode(data.getLicenseID(), data);

    // Check for duplicate key
    HashNode* traverse = table[index];
    while (traverse != nullptr){
        if (traverse->key == data.getLicenseID()){
            cout << "Error: Driver with License ID " << data.getLicenseID() << " already exists." << endl;
            delete newNode;
            return;
        }
        traverse = traverse->next;
    }

    // Insert at head of chain
    newNode->next = table[index];
    table[index] = newNode;
    count++;
}

// Search
Driver HashTable::search(int licenseID){
    int index = hashFunction(licenseID);
    HashNode* traverse = table[index];
    while (traverse != nullptr){
        if (traverse->key == licenseID){
            return traverse->data;
        }
        traverse = traverse->next;
    }
    cout << "Driver not found." << endl;
    return Driver();
}

// Remove
Driver HashTable::remove(int licenseID){
    int index = hashFunction(licenseID);
    HashNode* traverse = table[index];
    HashNode* prev = nullptr;

    while (traverse != nullptr && traverse->key != licenseID){
        prev = traverse;
        traverse = traverse->next;
    }

    if (traverse == nullptr){
        cout << "Error: Driver not found." << endl;
        return Driver();
    }

    Driver removed = traverse->data;

    if (prev == nullptr){
        table[index] = traverse->next;
    }
    else{
        prev->next = traverse->next;
    }

    delete traverse;
    count--;
    return removed;
}

// Display
void HashTable::display(){
    for (int i = 0; i < size; i++){
        cout << "Bucket " << i << ": ";
        HashNode* traverse = table[i];
        if (traverse == nullptr){
            cout << "empty";
        }
        while (traverse != nullptr){
            cout << "[" << traverse->data.getLicenseID()
                 << " | " << traverse->data.getName() << "]";
            if (traverse->next != nullptr){
                cout << " -> ";
            }
            traverse = traverse->next;
        }
        cout << endl;
    }
}

// Getters
int HashTable::getSize(){
    return size;
}

int HashTable::getCount(){
    return count;
}
