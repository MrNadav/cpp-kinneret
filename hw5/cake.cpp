#include <iostream>

#include "cake.h"
#include "date.h"

using namespace std;

Cake::Cake(
    Date expirtDate,
    int diameter,
    double height,
    double price,
    int storage,
    bool glutenfree
) {
    this->expiryDate = expirtDate;
    this->diameter = diameter;
    this->height = height;
    this->price = price;
    this->storage = storage;
    this->glutenfree = glutenfree;
}

Cake::Cake(Cake& cake) {
    if (this != &cake) {
        this->expiryDate = cake.expiryDate;
        this->diameter = cake.diameter;
        this->height = cake.height;
        this->price = cake.price;
        this->storage = cake.storage;
        this->glutenfree = cake.glutenfree;
    }
}

ostream& Cake::operator<<(ostream& out, const Cake& cake) {
    out << "Date: " << cake.expiryDate << "\n";
    out << "Diameter: " << cake.diameter <<"\n";
    out << "Height: " << cake.height << "\n";
    out << "Price: " << cake.price << "\n";

    if (this->storage == 1) {
        out << "Storage: Refrigeretor" << "\n";
    }
    else {
        out << "Storage: No Refrigeretor" << "\n";
    }

    if (glutenfree) {
        out << "without Gluten" << "\n";
    }
    else {
        out << "with gluten" << "\n";
    }

    return out
}

Cake& Cake::operator+=(double price){
    this.price += price;
}
bool Cake::operator==(const Cake& cake){
    if(this == &cake)
        return true;
    if(this->expiryDate == cake.expiryDate 
        && this->diameter == cake.diameter 
        && this->height == cake.height
        && this->price == cake.price
        && this->storage == cake.storage
        && this->glutenfree == cake.glutenfree){
            return true;
        }
    return false;
}