#ifndef BIRHTDAYCAKE_H
#define BIRTHDAYCAKE_H

#include "cake.h"
#include "date.h"

class BirthdayCake : public Cake {
    private:
        const char* text;

    public:
        BirthdayCake(
            Date expirtDate,
            int diameter,
            double height,
            double price,
            int storage,
            bool glutenFree,
            char* text
        );

        BirthdayCake(BirthdayCake& birthdayCake);

        ~BirthdayCake();

        void setExpireDate(const Date& date) const;
        Date getExpireDate() const;

        void setDiameter(const int diameter) const;
        int getDiameter() const;

        double setHeight(const double height) const;
        int getHeight() const;

        void setPrice(const double price) const;
        double getPrice() const;

        void setStorage(const int storage) const;
        int getStorage() const;

        void setGlutenFree(const bool glutenFree) const;
        bool getGlutenFree() const;
        
        void setText(const char* text) const;
        char* getText() const;

        bool operator==(const BirthdayCake& birthdayCake) const;
};

#endif