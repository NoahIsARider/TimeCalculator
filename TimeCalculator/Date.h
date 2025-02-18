// Date.h
#ifndef DATE_H
#define DATE_H

class Date {
protected:
    int year, month, day;
public:
    Date(int y, int m, int d);
    int findMaxDay();
    void addDay(int n);
    void addMonth(int n = 1);
    bool isLeapYear() const;
    int toDays() const;
};

#endif // DATE_H
