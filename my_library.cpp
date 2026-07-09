#pragma warning(disable : 4996)

#include "my_library.h"
#include <iostream>
#include <limits>
#include <ctime>



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

short DayOfWeekOrder(stDate Date)
{

     return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
 
}


std::string DayShortName(short DayOfWeekOrder)
{
    std::string arrDayNames[] = {
      "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
 return arrDayNames[DayOfWeekOrder];
}

bool IsEndOfWeek(stDate Date)
{
    return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd (stDate Date)
{
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay (stDate Date)
{
    return (!IsWeekEnd(Date));
}

bool IsValidDate (stDate Date)
{
    if (Date.Month < 1 || Date.Month > 12 ) return false;
    if (Date.Year < 1 ) return false;
    if (Date.Day < 1 || Date.Day > NumberofDaysInMonth(Date.Month ,Date.Year) ) return false ;

    return true;
}



stDate ReadFullDate() {
    stDate Date;

    do {
        Date.Day = ReadNumber("Please enter a Day? ");
        Date.Month = ReadNumber("Please enter a Month? ");
        Date.Year = ReadNumber("Please enter a Year? ");

        if (!IsValidDate(Date))
        {
            std::cout << "\nEnter a valid Date, This Date Does Not Exist in The Calendar! \n";
        }
    } while (!IsValidDate(Date));

    return Date;
}


stPeriod ReadPeriod()
{
    stPeriod Period;
    std::cout << "\nEnter Start Date\n";
    Period.StartDate = ReadFullDate();
    std::cout << "\nEnter End Date\n";
    Period.EndDate = ReadFullDate();
    return Period;
}



bool IsLastMonthInTheYear (stDate Date) 
{
    return (Date.Month == 12);
}

bool IsLastDayInTheMonth (stDate Date)
{  
 return (Date.Day == NumberofDaysInMonth(Date.Month , Date.Year));
        
}

bool IsFirstMonthInTheYear(stDate Date)
{
    return (Date.Month == 1);
}

bool IsFirstDayInTheMonth(stDate Date)
{

    return (Date.Day == 1 );

}


bool Date1AfterDate2 (stDate Date1 , stDate Date2)
{

   return (!IsDate1BeforeDate2(Date1,Date2) && !IsDate1EqualDate2(Date1,Date2));

}


bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
return (Date1.Year == Date2.Year) ? ((Date1.Month ==
Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false)
: false;
}


stDate increaseDateOneDay(stDate Date)

{

   if (IsLastDayInTheMonth(Date))
     { 
        if (IsLastMonthInTheYear(Date))
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

stDate DecreaseDateOneDay(stDate Date)
{

    if(IsFirstDayInTheMonth(Date))
    {
        if(IsFirstMonthInTheYear(Date))
        { 
            Date.Month = 12;
            Date.Day = 31;
            Date.Year--;
        }
        else 
        {
            Date.Month --;
            Date.Day = NumberofDaysInMonth(Date.Month, Date.Year);
        }
    }
    else 
    { 
        Date.Day --;
    }
            
return Date;
}


int GetDifferenceInDays(stDate Date1 , stDate Date2 , bool IncludeEndDay)
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


int GetDifferenceInDaysWithSwap(stDate Date1 , stDate Date2 , bool IncludeEndDay )
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

stDate GetSystemDate()
{
    stDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;
}


DateStats  CompareDates (stDate Date1 , stDate Date2)
{
  if(IsDate1BeforeDate2(Date1,Date2))
      return DateStats::Before;
  if(IsDate1EqualDate2(Date1,Date2))
      return DateStats::Equal;

  return DateStats::After;
}


