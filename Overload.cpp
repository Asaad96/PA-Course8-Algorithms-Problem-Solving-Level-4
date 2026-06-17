#include"my_library.h"
#include<iostream>
using namespace std;


short DaysuntilWeekEnd(stDate Date)
{
 short DayOrder = DayOfWeekOrder(Date);
// if (DayOrder == 6)
//     return 6;
// else
// return (5 - DayOrder);
//
//
return (DayOrder == 6) ? 6 :  (5 - DayOrder);

}

short DayuntilMonthend(stDate Date)
{
  stDate EndOfMonthDate;
  EndOfMonthDate.Day = NumberofDaysInMonth(Date.Month, Date.Year);
  EndOfMonthDate.Month = Date.Month;
  EndOfMonthDate.Year = Date.Year;
 return GetDifferenceInDays(Date, EndOfMonthDate , true);
}


short DayuntilYearEnd(stDate Date)
{
    stDate EndOfYearDate;
    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date.Year;

 return GetDifferenceInDays(Date ,EndOfYearDate, true);
}

int main ()
{
//stDate Date = ReadFullDate();

stDate Date = GetSystemDate();
cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date))
<< " , "
<< Date.Day << "/" << Date.Month << "/" << Date.Year <<
endl;

cout << "\nIs It End Of The Week?";

if(IsEndOfWeek(Date)) 
    cout << "\nYes It Is End Of The Week";
else 
    cout << "\nNo It Is NOT End Of The Week\n";

cout << "\nIs It the WeekEnd?";

if(IsWeekEnd(Date))
    cout <<"\nYes It Is The Weekend\n";
else 
    cout <<"\nNo It NOT The WeekEnd\n";
cout << "\nIs It business Day?";

if(IsBusinessDay(Date))
    cout << "\nYes It's.\n";
else 
    cout << "\nNo It Is NOT.\n";

cout << "\nDays until end of the week " << DaysuntilWeekEnd(Date) << " Day(s)." ;

cout << "\nDays until end of the mounth " << DayuntilMonthend(Date) << " Day(s).";

cout << "\nDays until end of the year " << DayuntilYearEnd(Date) << " Day(s).";



return 0;
}

