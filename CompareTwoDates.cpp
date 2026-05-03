#include <iostream>
#include "my_library.h"
using namespace std;


struct stDate
{
    short Day;
    short Month;
    short Year;
};



bool IsDate1BrforeDate2 (stDate Date1 , stDate Date2) 
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ?
            (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day :false )) :  false );



 //   (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
// Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
// Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}



stDate ReadFullDate() 
{

stDate Date;

Date.Day = ReadNumber("Please Enter the Day");
Date.Month = ReadNumber("Please Enter the Month");
Date.Year = ReadNumber("Please Enter the Year");

return Date;
}

int main ()
{
    stDate Date1 = ReadFullDate();
    stDate Date2 = ReadFullDate();

    if(IsDate1BrforeDate2(Date1, Date2))
        cout << "\nYes Date 1 is Less Than Date 2 ";
    else 
        cout << "\nNo Date 1 is NOT Less Than Date 2 \n";

   // system("Pause");
    return 0;
}


            

        




    



