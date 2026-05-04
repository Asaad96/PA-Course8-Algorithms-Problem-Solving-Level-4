#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#include <string>




struct stDate {
    short Day;
    short Month;
    short Year;
};

int ReadNumber(std::string Message = "Enter a number: ");
bool IsLeapYear(short Year);
short NumberofDaysInMonth(short Month, short Year);
short DayOfWeekOrder(short Day, short Month, short Year);
struct stDate ;
stDate ReadFullDate();

#endif 
