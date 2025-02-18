// Time.cpp
#include "Time.h"

void Time::setHour(int hour_) {
    int days = hour_ / 24;
    hour = hour_ % 24;
    if (hour < 0) {
        hour += 24;
        days--;
    }
    excessDay += days;
}

void Time::setMinute(int minute_) {
    int hours = minute_ / 60;
    minute = minute_ % 60;
    if (minute < 0) {
        minute += 60;
        hours--;
    }
    addHour(hours);
}

void Time::setSecond(int second_) {
    int minutes = second_ / 60;
    second = second_ % 60;
    if (second < 0) {
        second += 60;
        minutes--;
    }
    addMinute(minutes);
}

int Time::getHour() {
    return hour;
}

int Time::getMinute() {
    return minute;
}

int Time::getSecond() {
    return second;
}

void Time::add(int n) {
    second += n;
    if (second >= 60) {
        int m = second / 60;
        addMinute(m);
        second %= 60;
    }
    if (second < 0) {
        int m = (second / 60) - 1;
        addMinute(m);
        second = 60 - second * (-1) % 60;
    }
}

void Time::addMinute(int m) {
    minute += m;
    if (minute < 0) {
        int k = (minute / 60) - 1;
        addHour(k);
        minute = 60 - minute * (-1) % 60;
    } else if (minute >= 60) {
        int k = minute / 60;
        addHour(k);
        minute %= 60;
    }
}

void Time::addHour(int k) {
    hour += k;
    if (hour >= 24) {
        excessDay = hour / 24;
        hour %= 24;
    }
    if (hour < 0) {
        excessDay = (hour / 24);
        if (excessDay == 0)
            excessDay = -1;
        hour = 24 - (-1) * hour % 24;
    }
}

int Time::toSeconds() const {
    return hour * 3600 + minute * 60 + second;
}
