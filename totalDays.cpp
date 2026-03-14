// Write a program to print total days from the beginning of the year
// Number of Days from the beginning of the year is ****

// here we need to think about the year if it's a leap year or Not
// my Method
// #include "my_library.h"
// #include <iostream>
//
// using namespace std;
//
// short CalculateFun(short Year, short Month, short Day) {
//   // short NumberOfMonth = 12 - Month; // here I have How many Months left ex
//   3
//   // months
//   //short NumberOfDay = NumberofDaysInMonth(Month, Year) - Day; // here I
//   have How many days left from the month 20 - 31 short Counter = 0; for
//   (short i = 1; i < Month; i++) {
//     Counter += NumberofDaysInMonth(i, Year);
//   }
//
//   short totalDays = Counter + Day;
//
//   return totalDays;
// }
//
// void PrintTheAnswer(short Year, short Month, short Day) {
//   short Ans = CalculateFun(Year, Month, Day);
//   cout << "Number of Days from the beginning of the year is : " << Ans;
// }
//
// int main() {
//   short Year = ReadNumber("Please Enter a Year \n");
//   short Month = ReadNumber("Please Enter a Month \n");
//   short Day = ReadNumber("Please Enter a Day \n");
//
//   PrintTheAnswer(Year, Month, Day);
//
//   return 0;
// }
//
//
// Instructor's Method

#include <iostream>
using namespace std;
bool isLeapYear(short Year) {
  // if year is divisible by 4 AND not divisible by 100
  // OR if year is divisible by 400
  // then it is a leap year
  return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInAMonth(short Month, short Year) {
  if (Month < 1 || Month > 12)
    return 0;
  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
  short TotalDays = 0;
  for (int i = 1; i <= Month - 1; i++) {
    TotalDays += NumberOfDaysInAMonth(i, Year);
  }
  TotalDays += Day;
  return TotalDays;
}
short ReadDay() {
  short Day;
  cout << "\nPlease enter a Day? ";
  cin >> Day;
  return Day;
}
short ReadMonth() {
  short Month;
  cout << "\nPlease enter a Month? ";
  cin >> Month;
  return Month;
}
short ReadYear() {
  short Year;
  cout << "\nPlease enter a Year? ";
  cin >> Year;
  return Year;
}
int main() {
  short Day = ReadDay();
  short Month = ReadMonth();
  short Year = ReadYear();
  cout << "\nNumber of Days from the begining of the year is "
       << NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);
  system("pause>0");
  return 0;
}
