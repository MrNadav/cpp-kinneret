#ifdef MOUSSECAKE_H
#define MOUSSECAKE_H

#include "date.h"
#include "cake.h"

class MusseCake : public Cake {
    private:
        char* taste;

    public:
        MusseCake(
            Date expirtDate,
            int diameter,
            double height,
            double price,
            int storage,
            bool glutenFree,
            char* taste
        );

        MusseCake(MusseCake& moussecake);

        ~MusseCake();

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

        void setTaste(const char* taste) const;
        char* getTaste() const;

        bool operator==(const MusseCake& ms) const;
};

#endif