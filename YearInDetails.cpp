// Write a program to print Number of : Days , Hours , Minutes , Seconds in a Certain Year.
#include <iostream>
using namespace std;

short ReadNumber ()
{
    short Year;
    cout << "Please Enter the Year\n";
    cin >> Year;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Please Enter the year \n";
        cin >> Year;
    }
    return Year;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 ==
0);
}

int CalDays (short Year)
{
    int Days;
    if (IsLeapYear(Year))
    {   Days = 366;
    }
    else 
        Days = 365;
return Days;
}

int CalHours (short Year)
{
    int Hours = CalDays(Year) * 24;

    return Hours;
}

int CalMinu (short Year)
{
    int Minutes = CalHours(Year) * 60 ;

    return Minutes;
}

int CalSec (short Year)
{
    int Seconds = CalMinu(Year) * 60 ;
    
    return Seconds;
}

void CalculateTheYear(short Year)
{

    cout << "Days : " << CalDays(Year) << endl;
    cout << "Hours : " << CalHours(Year) << endl;
    cout << "Minutes : " << CalMinu(Year) << endl;
    cout << "Seconds : " << CalSec(Year) << endl;

}


int main ()
{

short Year = ReadNumber();
CalculateTheYear(Year);

}


// Instructor Method
// short NumberOfDaysInAYear(short Year)
// {
// return isLeapYear(Year) ? 366 : 365;
// }
// short NumberOfHoursInAYear(short Year)
// {
// return NumberOfDaysInAYear(Year) * 24;
// }
// int NumberOfMinutesInAYear(short Year)
// {
// return NumberOfHoursInAYear(Year) * 60;
// }
// int NumberOfSecondsInAYear(short Year)
// {
// return NumberOfMinutesInAYear(Year) * 60;
// }
