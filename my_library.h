#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#include <string>

int ReadNumber(std::string Message = "Enter a number: ");
bool IsLeapYear(short Year);
short NumberofDaysInMonth(short Month, short Year);
short DayOfWeekOrder(short Day, short Month, short Year);


#endif 
