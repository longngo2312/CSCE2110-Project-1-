#include <iostream>
#ifndef DATE_H 
#define DATE_H
using namespace std;

class Date {
    public:
        Date();
        // Constructor With Date Input //
        Date(int d, int m, int y);
    private:
        // Date Variables //
        int day;
        int month;
        int year;
};

#endif