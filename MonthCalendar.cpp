// Write a program to print Calender
// Please Enetr a year ?
// Please Enter a Month?
//
// _____________Sep_________________
// Sun  Mon  Tue  Wed  Thu  Fri  Sat
//
//
//
//
//
//
// __________________________________

#include "my_library.h"
#include <iostream>

using namespace std;

string DayShortName(short DayOfWeekOrder) {
  string arrDayName[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

  return arrDayName[DayOfWeekOrder];
}

string MonthShortName(short MonthNumber) {
  string Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                       "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  return (Months[MonthNumber - 1]);
}

void PrintCalendar(short Month, short Year) {

  int NumberOfDays;
  int current = DayOfWeekOrder(1, Month, Year);

  NumberOfDays = NumberofDaysInMonth(Month, Year);
  // Print the current month name
  printf("\n _______________%s_______________\n\n",
         MonthShortName(Month).c_str());
  // Print the columns
  printf("   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");
  // Print appropriate spaces
  int i;
  for (i = 0; i < current; i++)
    printf(" ");
  for (int j = 1; j <= NumberOfDays; j++) {
    printf("%5d", j);
    if (++i == 7) {
      i = 0;
      printf("\n");
    }
  }
  printf("\n _________________________________\n");
}

int main() {
  short Year = ReadNumber("Please Enter the Year \n");
  short Month = ReadNumber("Please Enter the Month \n");
  PrintCalendar(Month, Year);

  return 0;
}
