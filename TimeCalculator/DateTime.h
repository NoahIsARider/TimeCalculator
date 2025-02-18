// DateTime.h
#ifndef DATETIME_H
#define DATETIME_H

#include "Time.h"
#include "Date.h"

class DateTime : public Date, public Time {
public:
    DateTime(int y, int m, int d, int h, int min, int s);
    int diffSeconds(const DateTime& other) const;
};

#endif // DATETIME_H