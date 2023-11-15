#ifndef MOUSSECAKE_H
#define MOUSSECAKE_H

#include <iostream>
#include <stdbool.h>

#include "date.h"
#include "cake.h"

using namespace std;

class MusseCake : public Cake {
    private:
        char* taste;

    public:
        MusseCake(
            Date expiryDate,
            int diameter,
            double height,
            double price,
            int storage,
            bool glutenfree,
            char* taste
        );

        MusseCake(MusseCake& moussecake);

        ~MusseCake();

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

        void setTaste(const char* taste);
        char* getTaste() const;

        bool operator==(const MusseCake& ms);

        ostream& operator<<(ostream& out, const MousseCake& ms);
};

#endif