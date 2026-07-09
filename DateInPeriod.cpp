// Write a program to read a period and date, then check if date is within this period or not?

#include "my_library.h"
#include <iostream>
using namespace std;


bool IsDateInPeriod(stDate Date, stPeriod Period)
{
return  !(CompareDates(Date,Period.StartDate) ==  DateStats::Before 
        
           || 

          CompareDates(Date,Period.EndDate) == DateStats::After );

}

int main()
{
cout << "Enter Period";
stPeriod Period = ReadPeriod();
cout << "\nEnter Date To Check\n";
stDate Date = ReadFullDate();
 if (IsDateInPeriod(Date, Period))
cout << "\nYes, Date is within period\n";
 else
cout << "\nNo, Date is NOT within period\n";
 return 0;
}
