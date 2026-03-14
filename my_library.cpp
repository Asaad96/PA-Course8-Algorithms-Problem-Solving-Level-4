#include "my_library.h"
#include <iostream>
#include <limits>


int ReadNumber (std::string Message) 
{
    int Number;
    std::cout << Message;  
    std::cin >> Number;

    while (std::cin.fail())
    {
        std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid Number, Enter a valid one \n";
        std::cin >> Number;
    }

    return Number;
}

bool IsLeapYear (short Year)
{
   return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}


short NumberofDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12 ) 
        return 0;

    if (Month == 2 )
    {
        return IsLeapYear(Year) ? 29 : 28 ;
    }

    short arr31Days[7] = { 1, 3, 5, 7, 8 , 10 , 12};

    for (short i = 1 ; i <= 7 ; i ++ )
    {
        if (arr31Days[i-1] == Month)
            return 31;
    }
    return 30;
}




short DayOfWeekOrder(short Day, short Month, short Year)
{
short a, y, m, d;
a = (14 - Month) / 12;
y = Year - a;
m = Month + (12 * a) - 2;
// Gregorian:
//0:sun, 1:Mon, 2:Tue...etc
d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    
    return d;
}
