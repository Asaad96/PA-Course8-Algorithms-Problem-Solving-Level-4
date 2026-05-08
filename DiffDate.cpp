// Wirte a program to read a Date1 and Date2 and make a function to calculate the difference in days
// Note: Date1 should be less than Date2

#include "my_library.h"
#include <iostream>
using namespace std;


int GetDifferenceInDays(stDate Date1 , stDate Date2 , bool IncludeEndDay = false )
{
 int Days = 0 ;
 while (IsDate1BeforeDate2(Date1 , Date2))
    {
        Days ++;
        Date1 = increaseDateOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;

}


int main ()
{

 stDate Date1 = ReadFullDate();
 stDate Date2 = ReadFullDate();
    
 cout << "\nDiffrence is: " << GetDifferenceInDays(Date1 , Date2) << " Days";
 cout << "\nDiffrence Including End Day is: " << GetDifferenceInDays(Date1 , Date2 , false) << " Days\n";
 return 0;
}
