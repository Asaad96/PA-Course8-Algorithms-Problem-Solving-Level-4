#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#include <string>




struct stDate {
    short Day;
    short Month;
    short Year;
};

int ReadNumber(std::string Message = "Enter a number: ");
bool IsLeapYear(short Year);
short NumberofDaysInMonth(short Month, short Year);
short DayOfWeekOrder(short Day, short Month, short Year);
bool IsValidDate (stDate Date);
stDate ReadFullDate();
stDate increaseDateOneDay( stDate Date);
stDate DecreaseDateOneDay(stDate Date);
bool IsLastMonthInTheYear (stDate Date);
bool IsLastDayInTheMonth  (stDate Date);
bool Date1AfterDate2 (stDate Date1 , stDate Date2); 
bool IsDate1BeforeDate2 (stDate Date1, stDate Date2);
bool IsDate1EqualDate2(stDate Date1, stDate Date2);
int  GetDifferenceInDays(stDate Date1 , stDate Date2, bool IncludeEndDay = false);
int GetDifferenceInDaysWithSwap(stDate Date1, stDate Date2, bool IncludeEndDay = false);
void SwapDates(stDate& Date1, stDate& Date2);
short DayOfWeekOrder(stDate Date);
std::string DayShortName(short DayOfWeekOrder);
bool IsEndOfWeek(stDate Date);
bool IsWeekEnd (stDate Date);
bool IsBusinessDay (stDate Date);
stDate GetSystemDate();
stDate CalculateVacationReturnDate(stDate Datestart, short VacationDays);

#endif
