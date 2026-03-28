// include the needed class header files after properly connecting them
#include "../include/driver.hpp"
#include "../include/DriverList.hpp"
#include "../include/HashTable.hpp"
#include <limits>
#include <fstream>
#include <sstream>

#include <iostream>
using namespace std;
void readData (DriverList& activeDrivers, HashTable& table);
void Menu ();
void AddDriverMenu (DriverList& activeDrivers, HashTable& table);
void SearchDriverMenu (DriverList& activeDrivers);
void InsertAfterMenu (DriverList& activeDrivers, HashTable& table);
void InactiveMenu (DriverList& activeDrivers, DriverList& inactiveDrivers, HashTable& table);
void DisplayMenu (DriverList& activeDrivers, DriverList& inactiveDrivers);
void DisplayNewOldMenu ();

int main() {
    bool Running = true;

    DriverList activeDrivers;
    DriverList inactiveDrivers;
    //start with 100 for database drivers
    HashTable table(100);

    readData(activeDrivers, table);


    while (Running != false) {
        Menu ();
        
        int choice;
        
        cin >> choice;

        

        switch (choice) {

            case 1:
                AddDriverMenu (activeDrivers, table);
                break;
            case 2:
                SearchDriverMenu (activeDrivers);
                break;
            case 3:
                InsertAfterMenu (activeDrivers, table);
                break;
            case 4:
                InactiveMenu (activeDrivers, inactiveDrivers, table);
                break;
            case 5:
                DisplayMenu (activeDrivers, inactiveDrivers);
                break;
            case 6:
                DisplayNewOldMenu ();
                break;
            case 7:
                cout<<"Exiting program\n";
                Running = false;
                break;
            default:
                cout<<"Invalid choice\n";
                break;

        }


    }



    return 0;
}

void readData (DriverList& activeDrivers, HashTable& table) {
    ifstream file("Database.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open Database.txt\n";
        return;
    }

    string line;

while (getline(file, line)) {
    stringstream ss(line);

    string licenseID, name, dob, issueDate;
    string street, city, county;
    string experience;
    string workType;

    getline(ss, licenseID, ',');
    getline(ss, name, ',');
    getline(ss, dob, ',');
    getline(ss, issueDate, ',');
    getline(ss, street, ',');
    getline(ss, city, ',');
    getline(ss, county, ',');
    getline(ss, experience, ',');
    getline(ss, workType, ',');
    //getline(ss, hasTicket, ',');
    //getline(ss, workDetails, ',');
    

   
    // Converting into own datatypes
    int id = stoi(licenseID);
    int exp = stoi(experience);

    
    //bool ticket = (hasTicket == "1");

    
    int m1, d1, y1;
    char s1, s2;
    stringstream dobStream(dob);
    dobStream >> m1 >> s1 >> d1 >> s2 >> y1;
    Date dobDate(m1, d1, y1);
        
        
  

 
    int m2, d2, y2;
    char t1, t2;
    stringstream issueStream(issueDate);
    issueStream >> m2 >> t1 >> d2 >> t2 >> y2;
    Date issueD(m2, d2, y2);
    
    

    Driver d;
    d.setLicenseID(id);
    d.setName(name);
    d.setDOB(dobDate);
    d.setLicenseDate(issueD);
    d.setAddress(Address(street, city, county));
    d.setExperience(exp);
    d.setWorkType(workType);
    

    /*if (ticket) {
        // Convert ticket to date type
        int tm, td, ty;
        char ts1, ts2;
        stringstream ticketDateStream(ticketDate);
        ticketDateStream >> tm >> ts1 >> td >> ts2 >> ty;

        Date ticketDateObj(tm, td, ty);

        // Build Ticket object
        Ticket ticketObj(ticketDateObj, ticketLocation);
        d.setTicket(ticketObj);
    }*/

    
    activeDrivers.insertAtEnd(d);
    table.insert(d);
}



}

void Menu () {
    cout<<"   Menu   \n";
    cout<<"1: Add driver\n";
    cout<<"2: Search for a driver by (criteria)\n";
    cout<<"3: Insert the driver after a specific driver\n";
    cout<<"4: Move driver to inactive database\n";
    cout<<"5: Display active or inactive drivers\n";
    cout<<"6: Display oldest or newest drivers\n";
    cout<<"7: Exit program\n";
    cout<<"\n";
}

void AddDriverMenu (DriverList& activeDrivers, HashTable& table) {
    int choice1;
    //create relavent cin/class object lines
    
    cout<<"Menu\\Add_Driver \n";
    
    
    cout<<"Select driver type: \n";

    cout<<"1: Student\n";
    cout<<"2: Business\n";
    cout<<"3: Self Employed\n";
    cout<<"4: Private Employee\n";
    cout<<"5: Government\n";

    cin>>choice1;
    cin.ignore();
    

    Driver newDriver;

    switch (choice1) {
        case 1: {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string university;
            cout<< "Enter university name: ";
            getline(cin, university);
            newDriver.setWorkType(university);
            break;}
        case 2: {
            string company;
            cout<< "Enter company name: ";
            getline(cin, company);
            newDriver.setWorkType(company);
            break;}
        case 3: {
            string company;
            cout<< "Enter company name: ";
            getline(cin, company);
            newDriver.setWorkType(company);
            break;}
        case 4: {
            string company;
            cout<< "Enter company name: ";
            getline(cin, company);
            newDriver.setWorkType(company);
            break;}
        case 5: {
            string department;
            cout<< "Enter department name: ";
            getline(cin, department);
            newDriver.setWorkType(department);
            break;}
        default:
                cout<<"Invalid choice\n";
                break;


    }
    int LicenseID;
    string name;
    int m, d, y;
    string street, city, county;
    char hasT;

    cout<<"Enter License ID: \n";
    cin>>LicenseID;
    newDriver.setLicenseID(LicenseID);

    cout<<"Enter driver name: \n";
    cin.ignore();
    getline(cin, name);
    newDriver.setName(name);

    cout<<"Enter DOB (MM DD YYYY): \n";
    cin>>m>>d>>y;
    newDriver.setDOB(Date(m,d,y));

    cout<<"Enter Date: \n";
    cin>>m>>d>>y;
    newDriver.setLicenseDate(Date(m,d,y));

    cout<<"Enter address (street, city, county): \n";
    cout<<"Street: ";
    cin.ignore();
    getline(cin, street);

    cout<<"City: ";
    getline(cin, city);

    cout<<"County: ";
    getline(cin, county);
    newDriver.setAddress(Address(street, city, county));

    cout<<"Does this Driver have any tickets? (y/n): \n";
    cin>>hasT;

    if (hasT == 'y' || hasT == 'Y') {
        cout<<"Enter ticket issue date (MM DD YYYY): ";
        cin>>m>>d>>y;
        Date ticketDate(m, d, y);

        cout<<"Enter ticket location: ";
        cin.ignore();
        string location;
        getline(cin, location);

        Ticket t(ticketDate, location);
        newDriver.setTicket(t);
    }
    
    
    activeDrivers.insertAtEnd(newDriver);
    table.insert(newDriver);
    
    cout<<"\n";



}

void SearchDriverMenu (DriverList& activeDrivers) {
    int LicenseID;
    cout<<"Menu\\Search_Driver \n";

    cout<<"Enter dirver's license: \n";
    cin>>LicenseID;

   activeDrivers.searchByLicenseID(LicenseID);
   
    cout<<"\n";
}

void InsertAfterMenu (DriverList& activeDrivers, HashTable& table) {
    string name;
    int licenseID;
    cout<<"Menu\\Insert_After_Driver \n";
    cout<<"Enter drivers name: \n";
    cin.ignore();
    getline(cin, name);

    

    cout<<"Enter drivers licence: \n";
    cin>>licenseID;

    
    cout<<"-New driver information-\n";
    
    int choice1;

    
    
    cout<<"Select driver type: \n";

    cout<<"1: Student\n";
    cout<<"2: Business\n";
    cout<<"3: Self Employed\n";
    cout<<"4: Private Employee\n";
    cout<<"5: Government\n";

    cin>>choice1;
    cin.ignore();
    

    Driver newDriver;

    switch (choice1) {
        case 1: {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string university;
            cout<< "Enter university name: ";
            getline(cin, university);
            newDriver.setWorkType(university);
            break;}
        case 2: {
            string company;
            cout<< "Enter company name: ";
            getline(cin, company);
            newDriver.setWorkType(company);
            break;}
        case 3: {
            string company;
            cout<< "Enter company name: ";
            getline(cin, company);
            newDriver.setWorkType(company);
            break;}
        case 4: {
            string company;
            cout<< "Enter company name: ";
            getline(cin, company);
            newDriver.setWorkType(company);
            break;}
        case 5: {
            string department;
            cout<< "Enter department name: ";
            getline(cin, department);
            newDriver.setWorkType(department);
            break;}
        default:
                cout<<"Invalid choice\n";
                break;


    }
    int LicenseID;
    int m, d, y;
    string street, city, county;
    char hasT;

    cout<<"Enter License ID: \n";
    cin>>LicenseID;
    newDriver.setLicenseID(LicenseID);

    cout<<"Enter driver name: \n";
    cin.ignore();
    getline(cin, name);
    newDriver.setName(name);

    cout<<"Enter DOB (MM DD YYYY): \n";
    cin>>m>>d>>y;
    newDriver.setDOB(Date(m,d,y));

    cout<<"Enter Date: \n";
    cin>>m>>d>>y;
    newDriver.setLicenseDate(Date(m,d,y));

    cout<<"Enter address (street, city, county): \n";
    cout<<"Street: ";
    cin.ignore();
    getline(cin, street);

    cout<<"City: ";
    getline(cin, city);

    cout<<"County: ";
    getline(cin, county);
    newDriver.setAddress(Address(street, city, county));

    cout<<"Does this Driver have any tickets? (y/n): \n";
    cin>>hasT;

    if (hasT == 'y' || hasT == 'Y') {
        cout<<"Enter ticket issue date (MM DD YYYY): ";
        cin>>m>>d>>y;
        Date ticketDate(m, d, y);

        cout<<"Enter ticket location: ";
        cin.ignore();
        string location;
        getline(cin, location);

        Ticket t(ticketDate, location);
        newDriver.setTicket(t);
    }
    
    
    activeDrivers.insertAfterValue("name",name,newDriver);
    table.insert(newDriver);
    cout<<"\n";
}

void InactiveMenu (DriverList& activeDrivers, DriverList& inactiveDrivers, HashTable& table) {
    int licenseID;
    cout<<"Menu\\Inactive_Driver \n";
    cout<<"Enter drivers licence: \n";
    cin>>licenseID;
   
    inactiveDrivers.insertAtBeginning(activeDrivers.searchByLicenseID(licenseID));
    activeDrivers.removeByLicenseID(licenseID);
    
    //ask if hashtable needs to be updated/ how to do so
    cout<<"\n";
}

void DisplayMenu (DriverList& activeDrivers, DriverList& inactiveDrivers) {
    int choice2;
    cout<<"Menu\\Display_Driver \n";
    cout<<"1: active drivers\n";
    cout<<"2: inactive drivers\n";

    cin>>choice2;

    switch(choice2) {
        case 1:
            activeDrivers.display();
            break;
        case 2:
            inactiveDrivers.display();
            break;
        default:
                cout<<"Invalid choice\n";
                break;
    }
    cout<<"\n";
}

void DisplayNewOldMenu () {
    cout<<"Menu\\Display_New\\Old_Drivers \n";
    cout<<"1: New drivers\n";
    cout<<"2: Old drivers\n";

    

    cout<<"\n";

}