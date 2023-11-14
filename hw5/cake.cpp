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
    bool glutenFree
) {
    this->expirtDate = expirtDate;
    this->diameter = diameter;
    this->height = height;
    this->price = price;
    this->storage = storage;
    this->glutenFree = glutenFree;
}

Cake::Cake(Cake& cake) {
    if (this != &cake) {
        this->expirtDate = cake.expirtDate;
        this->diameter = cake.diameter;
        this->height = cake.height;
        this->price = cake.price;
        this->storage = cake.storage;
        this->glutenFree = cake.glutenFree;
    }
}

ostream& Cake::operator<<(ostream& out, const Cake& cake) {
    out << "Date: " << cake.expirtDate << "\n";
    out << "Diameter: " << cake.diameter <<"\n";
    out << "Height: " << cake.height << "\n";
    out << "Price: " << cake.price << "\n";
    out << "Storage: " << cake.storage << "\n";
    out << "glutenFree: " << cake.glutenFree << "\n";
}

Cake& Cake::operator+=(double price){
    this.price += price;
}
bool Cake::operator==(const Cake& cake){
    if(this == &cake)
        return true;
    if(this->expirtDate == cake.expirtDate 
        && this->diameter == cake.diameter 
        && this->height == cake.height
        && this->price == cake.price
        && this->storage == cake.storage
        && this->gluenFree == cake.glutenFree){
            return true;
        }
    return false;
}