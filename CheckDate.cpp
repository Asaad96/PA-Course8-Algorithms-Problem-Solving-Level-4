// Write a program to read and check a date if the day is the last day in the month if the month is the last month in the year



#include"my_library.h"
#include <iostream>
using namespace std;


bool IsLastMonthInTheYear (stDate Date) 
{
    return (Date.Month == 12);
}

bool IsLastDayInTheMonth (stDate Date)
{  
 return (Date.Day == NumberofDaysInMonth(Date.Month , Date.Year));
        
}


int main()
{

stDate Date = ReadFullDate();

if (IsLastDayInTheMonth(Date)) 
       cout <<"\nYes, Last Day in the Month";
else 
       cout <<"\nNo, It Is NOT Last Day in the Month\n";

if (IsLastMonthInTheYear(Date)) 
        cout <<"\nYes, Last Month in The Year";
else 
        cout <<"\nNo, It Is NOT Last Month in The Year\n";

    return 0;
}


