// Write a prgrom to read a date, and print the day name of week

#include<iostream>
#include "my_library.h"
using namespace std;

enum enDaysOfWeek { Sunday = 0, Monday = 1, Tuesday = 2, Wednesday = 3 , Thursday = 4, Friday = 5 , Saturday = 6 };

short ReadYear ()
{ 
    cout << "Please Enter a year! \n" ;
    short Year = ReadNumber();  
    return Year;
}

short ReadMonth ()
{
    cout << "Please Enter a Month! \n"; 

    short Month = ReadNumber();
    return Month;
}

short ReadDay ()
{
    cout << "Please Enter a Day! \n"; 

    short Day = ReadNumber();
    return Day;
}

short DefineEquations (short Year, short Month, short Day)
{
    short a = (14 - Month) / 12;
    short y = Year - a ;
    short m = Month + (12 * a) - 2; 
    short d = (Day + y + (y/4) - (y/100) + (y/400) + ((31 * m) /12)) % 7;
return d ;
}

string GetDayName(short DayOrder) {
    switch (DayOrder) {
    case enDaysOfWeek::Sunday:    return "Sunday";
    case enDaysOfWeek::Monday:    return "Monday";
    case enDaysOfWeek::Tuesday:   return "Tuesday";
    case enDaysOfWeek::Wednesday: return "Wednesday";
    case enDaysOfWeek::Thursday:  return "Thursday";
    case enDaysOfWeek::Friday:    return "Friday";
    case enDaysOfWeek::Saturday:  return "Saturday";
    default:                      return "Unknown";
    }
}
void PrintFormatAnswers ( short Year, short Month , short Day)
{
    
   short DayOrder = DefineEquations(Year, Month, Day);
   string DayName = GetDayName(DayOrder);

    cout << "Date : " << Day << "/" << Month << "/" << Year << "\n";
    cout << "Day order : " << DayOrder + 1  ;
    cout << "\nDay Name : " << DayName << endl;
}




int main ()
{
short Year = ReadYear();
short Month = ReadMonth();
short Day = ReadDay() ;
 



PrintFormatAnswers(Year,Month,Day);

    return 0;
}
