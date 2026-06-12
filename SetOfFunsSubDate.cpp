
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

        if(Date.Month < 1) 
        {
          Date.Month = 12;
          Date.Year --;
        }
    }

    return Date;
}

stDate DecreaseDateOneYear(stDate Date)
{
    Date.Year -= 1;
    return Date;
}


stDate DecreaseDateByXYear(stDate Date , short Xyear)
{

    if(Xyear == 0)
        return Date;

    for (short i = 0 ; i < Xyear ; i++)
    {
        Date = DecreaseDateOneYear(Date);
    }

    return Date;

}

stDate DecreaseDateByXYearFaster(stDate Date, short Xyear)
{
 Date.Year -= Xyear;
 return Date;
}

stDate DecreaseDateOneDecade(stDate Date)
{
    Date.Year -= 10;
    return Date;
}

stDate DecreaseDatebyXDecade(stDate Date, short XDecade)
{

    if(XDecade == 0)
        return Date;

    for ( short i = 0; i < XDecade ; i++)
    {
        Date = DecreaseDateOneDecade(Date);
    }

    return Date;

}

stDate DecreaseDatebyXDecadeFaster(stDate Date, short XDecade)
{

    Date.Year -= XDecade ;
    return Date;
}


stDate DecreaseDateOneCentury(stDate Date)
{
    Date.Year -= 100; 
    return Date ;
}

stDate DecreaseDateOneMill (stDate Date)
{
    Date.Year -= 1000;
    return Date ;
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
Date = DecreaseDateOneYear(Date);
cout << "\nDecreasing Date by One Year "<< Date.Day << "." << Date.Month << "." << Date.Year ; 
short Xyear = ReadNumber("\nHow Many years?\t"); 
Date = DecreaseDateByXYear(Date , Xyear);
cout << "\nDecreasing Date by " << Xyear << " Years " << Date.Day << "." << Date.Month << "." << Date.Year;
Date = DecreaseDateByXYearFaster(Date, Xyear);
cout << "\nDecreasing Date by " << Xyear << " Years Via Faster Func " << Date.Day << "." << Date.Month << "." << Date.Year;

Date = DecreaseDateOneDecade(Date);
cout << "\nDecreasing Date by one Decade " <<  Date.Day << "." << Date.Month << "." << Date.Year;
short XDecade = ReadNumber("\nHow Many Decades \t");
Date = DecreaseDatebyXDecade(Date, XDecade);
cout << "\nDecreasing Date by " << XDecade << " Decades " << Date.Day << "." << Date.Month << "." << Date.Year;
Date = DecreaseDatebyXDecadeFaster(Date, XDecade);
cout << "\nDecreasing Date by " << XDecade << " Decades Faster " << Date.Day << "." << Date.Month << "." << Date.Year;
Date = DecreaseDateOneCentury(Date);
cout << "\nDecreasing Date by one Century " <<  Date.Day << "." << Date.Month << "." << Date.Year;
Date = DecreaseDateOneMill(Date);
cout << "\nDecreasing Date by one Mill " <<  Date.Day << "." << Date.Month << "." << Date.Year;

return 0;
}

