// Time.h
#ifndef TIME_H
#define TIME_H

class Time {
private:
    int hour = 0, minute = 0, second = 0;
public:
    int excessDay = 0;
    void setHour(int hour_);
    void setMinute(int minute_);
    void setSecond(int second_);
    int getHour();
    int getMinute();
    int getSecond();
    void add(int n);
    void addMinute(int m);
    void addHour(int k);
    int toSeconds() const;
};

#endif // TIME_H