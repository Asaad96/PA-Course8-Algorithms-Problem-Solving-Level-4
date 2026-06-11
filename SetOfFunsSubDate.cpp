
#include "my_library.h"
#include <iostream>
#include <cerrno>
using namespace std;

stDate DecreaseDateByXDay(stDate Date, short XDay)
{
    if(XDay == 0)
    {return Date;}

    
     for (short i = 0 ; i < XDay ; i++)
        {
            Date = DecreaseDateOneDay(Date);
        }

    

    return Date;
}

stDate DecreaseDateOneWeek(stDate Date)
{
     Date = DecreaseDateByXDay(Date , 7);
     return Date;
}

int main ()
{
    stDate Date = ReadFullDate();
    short XDay = ReadNumber("\nHow many Days?\t");
    Date = DecreaseDateOneDay(Date);
  cout << "\nDecreasing Date One Day\t"<< Date.Day << "." << Date.Month << "." << Date.Year;
Date = DecreaseDateByXDay(Date, XDay);
cout << "\nDecreasing Date " << XDay << " Days "<< Date.Day << "." << Date.Month << "." << Date.Year;
Date = DecreaseDateOneWeek(Date);
cout << "\nDecreasing Date by One Week "<< Date.Day << "." << Date.Month << "." << Date.Year ;



return 0;
}

