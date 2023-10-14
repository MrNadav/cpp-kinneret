// hw3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "date.h"
using namespace std;
int main() {
    Date date1;
    Date date2(15, 5, 2023);
    
    date1.printDate();
    date2.printDate();

    return 0;
}