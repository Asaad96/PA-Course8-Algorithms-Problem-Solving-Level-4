#include "my_library.h"
#include <iostream>
#include <limits>


int ReadNumber (std::string Message) 
{
    int Number;
    std::cout << Message;  
    std::cin >> Number;

    while (std::cin.fail())
    {
        std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid Number, Enter a valid one \n";
        std::cin >> Number;
    }

    return Number;
}

bool IsLeapYear (short Year)
{
   return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}


short NumberofDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12 ) 
        return 0;

    if (Month == 2 )
    {
        return IsLeapYear(Year) ? 29 : 28 ;
    }

    short arr31Days[7] = { 1, 3, 5, 7, 8 , 10 , 12};

    for (short i = 1 ; i <= 7 ; i ++ )
    {
        if (arr31Days[i-1] == Month)
            return 31;
    }
    return 30;
}




short DayOfWeekOrder(short Day, short Month, short Year)
{
short a, y, m, d;
a = (14 - Month) / 12;
y = Year - a;
m = Month + (12 * a) - 2;
// Gregorian:
//0:sun, 1:Mon, 2:Tue...etc
d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    
    return d;
}


stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadNumber("Please enter a Day? ");
    Date.Month = ReadNumber("Please enter a Month? ");
    Date.Year = ReadNumber("Please enter a Year? ");
    return Date;
}

bool IsLastMonthInTheYear (stDate Date) 
{
    return (Date.Month == 12);
}

bool IsLastDayInTheMonth (stDate Date)
{  
 return (Date.Day == NumberofDaysInMonth(Date.Month , Date.Year));
        
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}


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


int GetDifferenceInDays(stDate Date1 , stDate Date2 , bool IncludeEndDay = false )
{
 int Days = 0 ;
 while (IsDate1BeforeDate2(Date1 , Date2))
    {
        Days ++;
        Date1 = increaseDateOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;

}


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


