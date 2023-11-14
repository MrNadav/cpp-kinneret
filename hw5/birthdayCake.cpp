#include <iostream>

#include <string.h>

#include "birthdayCake.h"
#include "date.h"

using namespace std;

BirthdayCake::BirthdayCake(
    Date expirtDate,
    int diameter,
    double height,
    double price,
    int storage,
    bool glutenFree,
    const char* text
) : Cake(
    expirtDate,
    diameter,
    height,
    price,
    storage,
    glutenFree
) {
    this->text = new char[strlen(text) + 1];
    strcpy(this->text, text);
}

BirthdayCake::BirthdayCake(BirthdayCake& birthdayCake) : Cake(birthdayCake) {
    const char* tmp = birthdayCake.getText();

    if (tmp != nullptr) {
        this->text = new char[strlen(tmp) + 1];

        strcpy(this->text, tmp);
    }
    else {
        this->text = nullptr;
    }
}








// BirthdayCake(BirthdayCake& birthdayCake);

//         ~BirthdayCake();

//         void setExpireDate(const Date& date) const;
//         Date getExpireDate() const;

//         void setDiameter(const int diameter) const;
//         int getDiameter() const;

//         double setHeight(const double height) const;
//         int getHeight() const;

//         void setPrice(const double price) const;
//         double getPrice() const;

//         void setStorage(const int storage) const;
//         int getStorage() const;

//         void setGlutenFree(const bool glutenFree) const;
//         bool getGlutenFree() const;
        
//         void setText(const char* text) const;
//         char* getText() const;

//         bool operator==(const BirthdayCake& birthdayCake) const;
