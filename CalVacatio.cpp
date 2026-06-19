// Write a program to read vacation period datefrom and dateTo and 
// make a function to calculate the actual vacation days.

// Note: Weekends are excluded

#include "my_library.h"
#include <iostream> 
using namespace std;




short calculateVacationDays(stDate DateStart , stDate DateEnd)
{

    short DaysCount = 0;
    while(IsDate1BeforeDate2(DateStart ,DateEnd))
       {
          if(IsBusinessDay(DateStart))
           DaysCount ++;
          DateStart = increaseDateOneDay(DateStart);
       } 

    return DaysCount;
//  return GetDifferenceInDays(DateStart, DateEnd, true);
}


int main ()
{
  cout << "\nvacation starts from \n";
  stDate DateStart = ReadFullDate();

  cout << "\nvacation Ends\n";
  stDate DateEnd = ReadFullDate();



  cout << "\nActual vacation days: " << calculateVacationDays(DateStart , DateEnd) ; 
    return 0;
}
