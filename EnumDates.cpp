

#include "my_library.h"
#include <iostream>
using namespace std;

enum DateStats  { Before = -1, Equal = 0, After = 1};

DateStats  CompareDates (stDate Date1 , stDate Date2)
{
  if(IsDate1BeforeDate2(Date1,Date2))
      return DateStats::Before;
  if(IsDate1EqualDate2(Date1,Date2))
      return DateStats::Equal;

  return DateStats::After;
}



int main()
{

cout << "Please Enter Date 1\n";
stDate Date1 = ReadFullDate();
cout << "Please Enter Date 2\n"; 
stDate Date2 = ReadFullDate();

cout << "\nCompare Results : " << CompareDates(Date1, Date2);



return 0;
}

