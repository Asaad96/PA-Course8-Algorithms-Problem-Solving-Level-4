#include <iostream>
#include "my_library.h"

using namespace std;
 


bool IsEqualTwoDates (stDate Date1, stDate Date2)
{

return   (Date1.Year == Date2.Year) ?  ((Date1.Month == Date2.Month) ?   ((Date1.Day == Date2.Day) ? true : false) : false) : false;


//return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}




int main ()
{
    stDate Date1 = ReadFullDate();
    stDate Date2 = ReadFullDate();

    if(IsEqualTwoDates(Date1, Date2))
        cout << "\nYes Dates are Equal ";
    else 
        cout << "\nNo Dates are NOT Equal \n";

   // system("Pause");
    return 0;
}


