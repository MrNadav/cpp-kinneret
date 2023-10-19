#ifndef DATE_H
#define DATE_H
class Date
{
    private:
        int day;
        int month;
        int year;
        bool ValidMonth(int m);
        bool ValidDay(int d);
    public:
        Date();
        Date(int day, int month, int year);
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);
        //hw4
        bool operator>(const Date& other) const;
        bool operator<(const Date& other) const;
        bool operator==(const Date& other) const;


        //void printDate() const; //print
         friend ostream& operator<<(ostream& os, const Date& date);
};
#endif