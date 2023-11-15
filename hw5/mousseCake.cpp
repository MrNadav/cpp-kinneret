#include <iostream>

#include <stdbool.h>
#include <string.h>

#include "mousseCake.h"
#include "date.h"

using namespace std;

moussecake::MousseCake(
    Date expiryDate,
    int diameter,
    double height,
    double price,
    int storage,
    bool glutenfree,
    const char* taste
) : Cake(
    expirtDate,
    diameter,
    height,
    price,
    storage,
    glutenFree
) {
    setTaste(taste);
}

MousseCake::MousseCake(MousseCake& MousseCake) : Cake(MousseCake) {
    const char* tmp = MousseCake.getTaste();

    if (tmp != nullptr) {
        setTaste(tmp);
    }
    else {
        this->taste = nullptr;
    }
}

MousseCake::~MousseCake() {
    delete[] this->taste;
}

void MousseCake::setExpireDate(const Date& date) {
    this->expiryDate = &date;
}

Date MousseCake::getExpireDate() const {
    return expiryDate;
}

void MousseCake::setDiameter(const int diameter) {
    this->diameter = diameter;
}

int MousseCake::getDiameter() const {
    return diameter;
}

void MousseCake::setHeight(const double height) {
    this->height = height;
}

double MousseCake::getHeight() const {
    return height;
}

void MousseCake::setPrice(const double price) {
    this->price = price;
}

double MousseCake::getPrice() const {
    return price;
}

void MousseCake::setStorage(const int storage) {
    if(storage > 2 || storage <= 0) {
        this->storage = 1;
    }
    else {
        this->storage = storage;
    }
}

int MousseCake::getStorage() const {
    return storage;
}

void MousseCake::setGlutenFree(const bool glutenfree) {
    this->glutenfree = glutenfree;
}

bool MousseCake::getGlutenFree() const {
    return glutenfree;
}

void MousseCake::setTaste(const char* taste) {
    this->taste = new char[strlen(text) + 1];

    strcpy(this->taste, taste);
}

char* MousseCake::getTaste() const {
    return taste;
}

bool MousseCake::operator==(const MousseCake& ms) {
    if (this == &ms) {
        return true;
    }
    else if (
        this->expirtDate == ms.getExpireDate() &&
        this->diameter == ms.getDiameter()     &&
        this->height == ms.getHeight()         &&
        this->price == ms.getPrice()           &&
        this->storage == ms.getStorage()       &&
        this->gluenFree == ms.getGlutenFree()  &&
        this->taste == ms.getTaste()
    ) {
        return true;
    }

    return false;
}

ostream& operator<<(ostream& out, const MousseCake& ms) {
    out << ms;
    out << "Taste: " << ms.geText() << "\n";
    return out;
}