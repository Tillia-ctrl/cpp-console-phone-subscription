#ifndef PHONE_CALL_H
#define PHONE_CALL_H

#include "constants.h"

struct period{
    int hours;
    int minutes;
    int seconds;
};
struct date{
    int day;
    int month;
    int year;
};
struct PhoneCall {
    char number[MAX_STRING_SIZE];
    date dt;
    period start;
    period tm;
    char tariff[MAX_STRING_SIZE];
    double cost;
};

#endif
