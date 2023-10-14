#include "trip.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
bool Trip::ValiDest(const char* dest) const
{
    for(int i=0; i<strlen(dest); i++)
    {
        if(!isalpha(dest[i]))
            return false;
    }
    return true;
}
Trip::Trip()
{
    dest = new char[8];
    strcpy(dest, "unkown");
}
Trip::Trip(int tripNum, const char* dest, const Date& d)
{
    if(tripNum> 0 && ValiDest(dest))
    {
        this->tripNum = tripNum;
    }
}