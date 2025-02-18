// Date.cpp
#include "Date.h"

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

int Date::findMaxDay() {
    int maxDay = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDay = 30;
    if (month == 2) {
        if (year % 4 == 0 && year % 100 != 0)
            maxDay = 29;
        else if (year % 100 == 0 && year % 400 == 0)
            maxDay = 29;
        else
            maxDay = 28;
    }
    return maxDay;
}

void Date::addDay(int n) {
    if (n == 0)
        return;
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            day++;
            if (day > findMaxDay()) {
                day = 1;
                addMonth();
            }
        }
    }
    if (n < 0) {
        for (int i = 0; i > n; i--) {
            day--;
            if (day == 0) {
                addMonth(-1);
                day = findMaxDay();
            }
        }
    }
}

void Date::addMonth(int n) {
    month += n;
    if (month > 12) {
        month = 1;
        year++;
    }
    if (month < 1) {
        month = 12;
        year--;
    }
}

bool Date::isLeapYear() const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::toDays() const {
    int days = 0;
    for (int y = 1; y < year; y++) {
        bool isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        days += isLeap ? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        Date temp(year, m, 1);
        days += temp.findMaxDay();
    }
    days += day - 1; // 从1月1日开始计数
    return days;
}