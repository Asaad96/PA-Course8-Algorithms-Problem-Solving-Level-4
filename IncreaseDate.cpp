// Write a program to increase the date by one day
// 31.12.2025 -> 1.1.2026
//



#include "my_library.h"
#include <iostream>
using namespace std;


 stDate increaseDateOneDay( stDate Date)

{

   if (IsLastDayInTheMonth(Date))
     { 
        if (IsLastMonthInTheYear (Date))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year ++ ;
        }
        else 
        {
             Date.Month++;
             Date.Day = 1;
        }
     }
   else
    {
        Date.Day++;
    } 
        return Date;

}

int main ()
{

    stDate Date = ReadFullDate();

    Date = increaseDateOneDay(Date);

    cout << "\nDate after adding one day is " << Date.Day << "/" << Date.Month << "/" << Date.Year ;
    return 0;
}
