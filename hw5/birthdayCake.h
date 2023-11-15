#ifndef BIRHTDAYCAKE_H
#define BIRTHDAYCAKE_H

#include <iostream>
#include <stdbool.h>

#include "cake.h"
#include "date.h"

using namespace std;

class BirthdayCake : public Cake {
    private:
        const char* text;

    public:
        BirthdayCake(
            Date expiryDate,
            int diameter,
            double height,
            double price,
            int storage,
            bool glutenfree,
            char* text
        );

        BirthdayCake(BirthdayCake& birthdayCake);

        ~BirthdayCake();

        void setExpireDate(const Date& date);
        Date getExpireDate() const;

        void setDiameter(const int diameter);
        int getDiameter() const;

        void setHeight(const double height);
        double getHeight() const;

        void setPrice(const double price);
        double getPrice() const;

        void setStorage(const int storage);
        int getStorage() const;

        void setGlutenFree(const bool glutenfree);
        bool getGlutenFree() const;
        
        void setText(const char* text);
        char* getText() const;

        bool operator==(const BirthdayCake& birthdayCake);
        
        friend ostream& operator<<(ostream& out, const BirthdayCake& birthdayCake);
};

#endif