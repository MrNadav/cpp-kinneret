#ifndef CAKE_H
#define CAKE_H
#include <iostream>
using namespace std;

#include "date.h"

class Cake
{
    protected:
        Date expiryDate;
        int diameter;
        double height;
        double price;
        int storage;
        bool glutenfree;
    public:
        Cake(
            Date expiryDate,
            int diameter,
            double height,
            double price,
            int storage,
            bool glutenfree
        );
        
        Cake(Cake& cake);
        friend ostream& operator<<(ostream& os, const Cake& cake);
        bool operator==(const Cake& cake);
        Cake& operator+=(double price);
         

        

};


#endif