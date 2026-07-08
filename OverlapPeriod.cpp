// write a program to read two periods and check if they are overlap or not


#include "my_library.h"
#include <iostream>
using namespace std;



struct stPeriod 
{
stDate StartDate;
stDate EndDate;

};


stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Date\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date\n";
    Period.EndDate = ReadFullDate();
    return Period;

}



bool IsOverLapPeriod(stPeriod Period1, stPeriod Period2)
{
    if (
            CompareDates(Period2.EndDate , Period1.StartDate) == DateStats::Before || 
            CompareDates(Period2.StartDate , Period1.EndDate) == DateStats:: After   
       )
        return false;
    else
        return true;

}




int main ()
{
   cout << "\nEnter Period 1:";
   stPeriod Period1 = ReadPeriod();
   cout << "\nEnter Period 2:";
   stPeriod Period2 = ReadPeriod();   


    if(IsOverLapPeriod(Period1,Period2))
      cout << "Yes, Periods overlap\n";
    else
      cout << "No, Periods Are Not overlap\n";


return 0;
}

