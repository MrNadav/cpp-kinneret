
#ifndef DATE_H
#define DATE_H

class Date {
private:
    int day;
    int month;
    int year;

    bool isValidDay(int d) const;
    bool isValidMonth(int m) const;

public:
    Date();
    Date(int d, int m, int y);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    void printDate() const;
};

#endif
