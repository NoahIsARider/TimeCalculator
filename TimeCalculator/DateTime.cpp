#include "DateTime.h"

// DateTime.cpp
DateTime::DateTime(int y, int m, int d, int h, int min, int s) : Date(y, m, d) {
    setHour(h);
    setMinute(min);
    setSecond(s);
    // 处理时间进位导致的天数变化
    addDay(excessDay);
    excessDay = 0; // 重置
}

long long DateTime::diffSeconds(const DateTime& other) const {
    long long daysDiff = toDays() - other.toDays();
    long long secondsDiff = toSeconds() - other.toSeconds();
    return daysDiff * 24 * 3600 + secondsDiff;
}