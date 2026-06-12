
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

stDate DecreaseDateByXWeek(stDate Date, short Xweek)
{

    if(Xweek == 0)
    return Date;

for(short i = 0 ;  i < Xweek ; i++ )
    {
        Date = DecreaseDateOneWeek(Date);
    }

return Date;
}



stDate DecreaseDateOneMonth(stDate Date)

{
    Date.Month -= 1;
    return Date;}

stDate DecreaseDatebyXMonth(stDate Date, short Xmonth)
{
    if(Xmonth == 0)
        return Date;

    for (short i = 0 ; i < Xmonth ; i++)
    {
        Date = DecreaseDateOneMonth(Date);
    }

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
short Xweek = ReadNumber("\nHow Many Weeks?\t");
Date = DecreaseDateByXWeek(Date, Xweek);
cout << "\nDecreasing Date by " << Xweek << " Week(s) " << Date.Day << "." << Date.Month << "." << Date.Year ; 
Date = DecreaseDateOneMonth(Date);
cout << "\nDecreasing by One Month " << Date.Day << "." << Date.Month << "." << Date.Year ;
short Xmonth = ReadNumber("\nHow Many Month?\t");
Date = DecreaseDatebyXMonth(Date , Xmonth);
cout <<"\nDecreasing Date by " << Xmonth << " Month(s) " << Date.Day << "." << Date.Month << "." << Date.Year;


return 0;
}

