 // IncreaseDatebyXDays
 



#include "my_library.h" 
#include <cerrno>
#include <iostream>
using namespace std;



stDate IncreaseDatebyXDays( stDate Date, short XDay)
{

  
    
  if (XDay == 0) 
  {
       return Date;
  }

  

        while(XDay > 0 )

        { Date = increaseDateOneDay(Date);
          XDay -= 1;

        }
     short NewDateDay = NumberofDaysInMonth(Date.Month, Date.Year);
    if (Date.Day > NewDateDay )
        Date.Day = NewDateDay;
      
  return Date;
}


stDate increaseDateOneWeek(stDate NewDate2)
{
    int XDay = 7;
    NewDate2 = IncreaseDatebyXDays(NewDate2 , XDay);
    
    return NewDate2;

}

stDate increaseDatebyXWeek(stDate NewDate3, short xWeek)
{
  if (xWeek == 0)
  { return NewDate3 ;}

  while (xWeek > 0)
  {
    NewDate3 = increaseDateOneWeek(NewDate3);
    xWeek -= 1;
  }
  return NewDate3;
}


stDate increaseDateOneMonth(stDate NewDate4)
{
   
    
   // NumberofDaysInMonth( NewDate4.Month, NewDate4.Year);

    NewDate4.Month = NewDate4.Month + 1;

    int NumberofDaysInNewMonth = NumberofDaysInMonth(NewDate4.Month ,NewDate4.Year);

    if(NewDate4.Day > NumberofDaysInNewMonth)
       NewDate4.Day = NumberofDaysInNewMonth;

return NewDate4;
}


stDate increaseDatebyXmonths (short Months, stDate Date)
{

   if(Months == 0)
   {return Date;}

    for (short i = 0 ; i < Months ; i ++)
     {
    
         Date = increaseDateOneMonth(Date);

     }
    return Date;
}


stDate increaseDatebyOneYear (stDate Date)
{

Date.Year ++;
return Date;

}

stDate increaseDatebyXYear(short Year , stDate Date)
{

    for (short i = 0 ; i < Year ; i++)
    {
        Date = increaseDatebyOneYear(Date);
    }

return Date;
}

stDate increaseDatebyOneDecade (stDate Date)
{
Date.Year += 10;
return Date;

}

stDate increaseDatebyXDecade(short XDecade,stDate Date)
{
  if(XDecade == 0) 
    {return Date;}
  for (short i = 0; i < XDecade ; i++)
   {
      Date = increaseDatebyOneDecade(Date); 
   }

return Date;
}

stDate increaseDatebyOneCentury(stDate Date)
{

  Date.Year += 100;
  return Date;

}

stDate increaseDatebyOneMillennium(stDate Date)
{
    Date.Year += 1000;
    return Date;

}


int main ()
{
        
stDate Date1 = ReadFullDate();
  short XDay = ReadNumber("\nHow Many Days \t");
  stDate NewDate1 = increaseDateOneDay(Date1);
stDate NewDate2 = IncreaseDatebyXDays(NewDate1, XDay);
stDate NewDate3 = increaseDateOneWeek(NewDate2);

///stDate NewDate6 = increaseDatebyXmonths(NewDate5);

cout << "\nDate After\n";   
cout << "01-Adding One Day is " << NewDate1.Day << "." << NewDate1.Month<< "." << NewDate1.Year; 
cout << "\n02-Adding " << XDay << " Day " << NewDate2.Day << "." << NewDate2.Month<< "." << NewDate2.Year ;
cout << "\n03-Adding one Week " << NewDate3.Day << "." << NewDate3.Month << "." << NewDate3.Year;
short xWeek = ReadNumber("\nHow Many weeks \t");
stDate NewDate4 = increaseDatebyXWeek(NewDate3, xWeek);
cout << "04-Adding " << xWeek << " weeks " << NewDate4.Day << "." << NewDate4.Month << "." << NewDate4.Year;
stDate NewDate5 = increaseDateOneMonth(NewDate4);
cout << "\n05-Adding One Month " << NewDate5.Day << "." << NewDate5.Month << "." << NewDate5.Year ;
short Xmonth = ReadNumber("\nHow Many Months \t");
stDate NewDate6 = increaseDatebyXmonths(Xmonth ,NewDate5);
cout << "\n06-Adding " << Xmonth << " Months " << NewDate6.Day << "." << NewDate6.Month << "." << NewDate6.Year ;
stDate NewDate7 = increaseDatebyOneYear(NewDate6);
cout << "\n07-Adding one Year " << NewDate7.Day << "." << NewDate7.Month << "." << NewDate7.Year ;
short Year = ReadNumber("\nHow Many Years\t");
stDate NewDate8 = increaseDatebyXYear(Year, NewDate7);
cout << "\n08-Adding " << Year << " Year " << NewDate8.Day << "." << NewDate8.Month << "." << NewDate8.Year ;
stDate NewDate9 = increaseDatebyOneDecade(NewDate8);
cout << "\n09-Adding " << NewDate9.Day << "." << NewDate9.Month << "." << NewDate9.Year;
short XDecade = ReadNumber("\nHow Many Decades?\t");
stDate NewDate10 = increaseDatebyXDecade(XDecade, NewDate9);
cout << "\n10-Adding " << XDecade << " Decades " <<NewDate10.Day << "." << NewDate10.Month << "." << NewDate10.Year ;
NewDate10 = increaseDatebyOneCentury(NewDate10); 
cout << "\n11-Adding one Century "<< NewDate10.Day << "." << NewDate10.Month << "." << NewDate10.Year ;

NewDate10 = increaseDatebyOneMillennium(NewDate10);
cout << "\n12-Adding one Millennium " << NewDate10.Day << "." << NewDate10.Month << "." << NewDate10.Year ;
    return 0; }
