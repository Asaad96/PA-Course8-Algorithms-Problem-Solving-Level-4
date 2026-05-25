 // IncreaseDatebyXDays
 



#include "my_library.h" 
#include <iostream>
using namespace std;



stDate IncreaseDatebyXDays( stDate Date, int XDay)
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

stDate increaseDatebyXWeek(stDate NewDate3, int xWeek)
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

int main ()
{
        
stDate Date1 = ReadFullDate();
  int XDay = ReadNumber();
stDate NewDate1 = increaseDateOneDay(Date1);
stDate NewDate2 = IncreaseDatebyXDays(NewDate1, XDay);
stDate NewDate3 = increaseDateOneWeek(NewDate2);

cout << "\nDate After\n";   
cout << "01-Adding One Day is " << NewDate1.Day << "." << NewDate1.Month<< "." << NewDate1.Year; 
cout << "\n02-Adding " << XDay << " Day " << NewDate2.Day << "." << NewDate2.Month<< "." << NewDate2.Year ;
cout << "\n03-Adding one Week " << NewDate3.Day << "." << NewDate3.Month << "." << NewDate3.Year;
int xWeek = ReadNumber("\nHow Many weeks \t");
stDate NewDate4 = increaseDatebyXWeek(NewDate3, xWeek);
cout << "04-Adding " << xWeek << " weeks " << NewDate4.Day << "." << NewDate4.Month << "." << NewDate4.Year;
stDate NewDate5 = increaseDateOneMonth(NewDate4);
cout << "\n05-Adding One Month " << NewDate5.Day << "." << NewDate5.Month << "." << NewDate5.Year ;

  return 0;
}

