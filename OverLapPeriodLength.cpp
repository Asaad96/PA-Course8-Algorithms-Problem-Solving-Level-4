// Write a program to read the length of the period 


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



int main()
{


    cout << "\nEnter Period 1:\n";
    stPeriod Period1 = ReadPeriod();
    
    cout << "Period Length is: " << GetDifferenceInDays( Period1.StartDate , Period1.EndDate, false);

    cout <<"\n Period Length (includes End Date) is " << GetDifferenceInDays(Period1.StartDate , Period1.EndDate, true);

        return 0;
}
