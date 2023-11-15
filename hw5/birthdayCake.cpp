#include <iostream>
#include <stdbool.h>
#include <string.h>
#include "birthdayCake.h"
#include "cake.h"
#include "date.h"

using namespace std;

BirthdayCake::BirthdayCake(
    Date expiryDate,
    int diameter,
    double height,
    double price,
    int storage,
    bool glutenfree,
    const char* text
) : Cake(
    expiryDate,
    diameter,
    height,
    price,
    storage,
    glutenfree
) {
    setText(text);
}

BirthdayCake::BirthdayCake(BirthdayCake& birthdayCake) : Cake(birthdayCake) {
    const char* tmp = birthdayCake.getText();

    if (tmp != nullptr) {
        setText(tmp);
    }
    else {
        this->text = nullptr;
    }
}

BirthdayCake::~BirthdayCake() {
    delete[] this->text;
}

void BirthdayCake::setExpireDate(const Date& date) {
    this->expiryDate = &date;
}

Date BirthdayCake::getExpireDate() const {
    return expiryDate;
}

void BirthdayCake::setDiameter(const int diameter) {
    this->diameter = diameter;
}

int BirthdayCake::getDiameter() const {
    return diameter;
}

void BirthdayCake::setHeight(const double height) {
    this->height = height;
}

double BirthdayCake::getHeight() const {
    return height;
}

void BirthdayCake::setPrice(const double price) {
    this->price = price;
}

double BirthdayCake::getPrice() const {
    return price;
}

void BirthdayCake::setStorage(const int storage) {
    if(storage > 2 || storage <= 0) {
        this->storage = 1;
    }
    else {
        this->storage = storage;
    }
}

int BirthdayCake::getStorage() const {
    return storage;
}

void BirthdayCake::setGlutenFree(const bool glutenfree) {
    this->glutenfree = glutenfree;
}

bool BirthdayCake::getGlutenFree() const {
    return glutenfree;
}

void BirthdayCake::setText(const char* text) {
    this->text = new char[strlen(text) + 1];

    strcpy(this->text, text);
}

char* BirthdayCake::getText() const {
    return text;
}

bool BirthdayCake::operator==(const BirthdayCake& birthdayCake) {
    if (this == &birthdayCake) {
        return true;
    }
    else if (
        this->expiryDate == birthdayCake.getExpireDate() &&
        this->diameter == birthdayCake.getDiameter()     &&
        this->height == birthdayCake.getHeight()         &&
        this->price == birthdayCake.getPrice()           &&
        this->storage == birthdayCake.getStorage()       &&
        this->glutenfree == birthdayCake.getGlutenFree()  &&
        this->text == birthdayCake.getText()
    ) {
        return true;
    }

    return false;
}

ostream& operator<<(ostream& out, const BirthdayCake& birthdayCake) {
    out << birthdayCake;
    out << "Text: " << birthdayCake.getText() << "\n";

    return out;
}
