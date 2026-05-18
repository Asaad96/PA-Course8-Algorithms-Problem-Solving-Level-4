



#include "my_library.h"
#include<iostream>
using namespace std;


void SwapDates (stDate& Date1 , stDate& Date2)
{

    stDate TempDate;


    TempDate.Year = Date1.Year;
    TempDate.Month = Date1.Month;
    TempDate.Day = Date1.Day;

    Date1.Year = Date2.Year;
    Date1.Month = Date2.Month;
    Date1.Day = Date2.Day;


    Date2.Year = TempDate.Year ;
    Date2.Month = TempDate.Month;
    Date2.Day = TempDate.Day;



}


int GetDifferenceInDaysWithSwap(stDate Date1 , stDate Date2 , bool IncludeEndDay = false )
{
 int Days = 0 ; 
 short SwapFlagValue = 1;

 if (!IsDate1BeforeDate2(Date1, Date2))
 {
     //SwapDates 
     SwapDates(Date1 , Date2);
     SwapFlagValue = -1;
 }

 while (IsDate1BeforeDate2(Date1 , Date2))
    {
        Days ++;
        Date1 = increaseDateOneDay(Date1);
    }
    return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;

}


int main ()
{


    stDate  Date1 = ReadFullDate();
    stDate  Date2 = ReadFullDate();

cout << "\nDifferenc is " << GetDifferenceInDaysWithSwap(Date1 , Date2 ) << "Days";
cout << "\nDifferenc including End Day is "<< GetDifferenceInDaysWithSwap(Date1, Date2 , false ) << "Days\n"; 

 return 0;
}
