#include "date.h"
#include <iostream>
using namespace std;
bool Date::ValidMonth(int m)
{
    return m>0 && m<=12;
}
bool Date::ValidDay(int d)
{
    return d>0 && d<=30;
}

Date::Date()
{
    day = 1;
    month = 1;
    year = 2000;
}
Date::Date(int d, int m, int y)
{
    if(ValidDay(d) && ValidMonth(m) && y>0)
    {
        day = d;
        month = m;
        year = y;
    }
    else
    {
        day = 0;
        month = 0;
        year = 0;
    }
}
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::setDay(int d)
{
    if(ValidDay(d))
        day = d;
    else
        day = 0;
}
void Date::setMonth(int m)
{
    if(ValidDay(m))
        month = m;
    else
        month = 0;
}
void Date::setYear(int y)
{
    if(y>0)
        year = y;
    else
        year = 0;
}

// void Date::printDate() const {
//     cout << day << "/" << month << "/" << year << endl;
// }

//hw4
ostream& operator<<(ostream& os, const Date& date) {
    os << date.day << "/" << date.month << "/" << date.year; //  without getters
    return os;
}

bool Date::operator<(const Date& other) const{
    if (year < other.year) return true;
    if (month < other.month) return true;
    if (day < other.day) return true;
    return false;
}
bool Date::operator>(const Date& other) const{
    if (year > other.year) return true;
    if (month > other.month) return true;
    if (day > other.day) return true;
    return false;
}
bool Date::operator==(const Date& other) const{
    return (day == other.day && month == other.month && year == other.year);
}
