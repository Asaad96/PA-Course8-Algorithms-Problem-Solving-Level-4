// Write a program to print total days from the
// beginning of year, then take the total days and convert them back
// to date

#include "my_library.h"
#include <iostream>

using namespace std;

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
  short TotalDays = 0;
  for (int i = 1; i <= Month - 1; i++) {
    TotalDays += NumberofDaysInMonth(i, Year);
  }
  TotalDays += Day;
  return TotalDays;
}

struct sDate {
  short Year;
  short Month;
  short Day;
};

sDate GeTdateFromDayOrderInYear(short DateOrderInYear, short Year) {
  sDate Date;
  short RemainingDays = DateOrderInYear;
  short MonthDays = 0;

  Date.Year = Year;
  Date.Month = 1;

  while (true) {
    MonthDays = NumberofDaysInMonth(Date.Month, Year);

    if (RemainingDays > MonthDays) {
      RemainingDays -= MonthDays;
      Date.Month++;
    } else {
      Date.Day = RemainingDays;
      break;
    }
  }
  return Date;
}

int main() {
  short Day = ReadNumber("Please Enter a day \n");
  short Month = ReadNumber("Please Enter a Month \n");
  short Year = ReadNumber("Please Enter a year \n");
  short DaysOrderInYear = NumberOfDaysFromTheBeginingOfTheYear(Day,  Month, Year);
  sDate Date;
  cout << "\nNumber of Days from the beginning of the year is "
       << NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);


  Date = GeTdateFromDayOrderInYear(DaysOrderInYear, Year);
  cout << "Date for [" << DaysOrderInYear << "] is: ";
  cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

  return 0;
}
