// Write a program to read a vacation start datefrom and 
// vacationDays ,then make a function to calculate the vacation retrun date.


#include "my_library.h"
#include <iostream>
using namespace std;

// My method but I forgot to check if the first date is weekend or not and delete it 
// stDate CalculateVacationDays(stDate Datestart, short vacationDays)
// {
//  short i = 0;
//  stDate currentDate = Datestart;
//
//     if (vacationDays <= 0)
//         return currentDate;
//
//
//     while (i < vacationDays)
//     {
//       currentDate = increaseDateOneDay(currentDate);
//      
//         if(IsBusinessDay(currentDate))
//         { 
//           i++;
//         }
//     }
//    // NewDate = increaseDateOneDay(Datestart);
//     return currentDate; 



// Teacher's Method


stDate CalculateVacationReturnDate(stDate Datestart, short VacationDays)
{

    short WeekEndCounter = 0;

    //in case the data  is weekend keep adding one day util you reach business day
    //we get rid of all weekends before the first business day
    while (IsWeekEnd(Datestart))
    {
        Datestart = increaseDateOneDay(Datestart);
    }

     //here we increase the vacation dates to add all weekends to it.
    
    for (short i = 1; i <= VacationDays+ WeekEndCounter; i++)
    {

        if (IsWeekEnd(Datestart))
            WeekEndCounter++;

        Datestart = increaseDateOneDay(Datestart);
    }

    
    //in case the return date is week end keep adding one day util you reach business day
    while (IsWeekEnd(Datestart))
    {
        Datestart = increaseDateOneDay(Datestart);
    }

    return Datestart;
}



int main ()
{
cout << "Vacation Start :\n";
stDate Datestart = ReadFullDate();
short vacationDays = ReadNumber();
stDate ReturnDate = CalculateVacationReturnDate(Datestart,vacationDays);
short OrderDate = DayOfWeekOrder(ReturnDate);
    
cout << "\nRetrun Date: " << DayShortName(OrderDate) << " " << ReturnDate.Day << "." << ReturnDate.Month << "." << ReturnDate.Year  ;

    return 0;
}
