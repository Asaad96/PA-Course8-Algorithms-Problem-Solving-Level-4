// Write a program to print Number of : Days Hours Minutes Seconds in a certain Months

#include <iostream>
#include <limits>
using namespace std;


short ReadYear ()
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


short ReadMonth()
{
    short Month;
    cout << "Please Enter the Month\n";
    cin >> Month;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Please Enter the Month \n";
        cin >> Month;
    }
    return Month;

}


bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 ==
0);
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


int NumberofHoursInMonth(short Month, short Year)
{
return NumberofDaysInMonth(Month, Year) * 24; 
}

int NumberOfMinutesInMonth(short Month, short Year)
{
return NumberofHoursInMonth(Month , Year) * 60;
}

long long NumberOfSecondsInMonth(short Month,short Year)
{
return NumberOfMinutesInMonth(Month , Year) * 60;
}


int main ()
{
    short Year = ReadYear();
    short Month = ReadMonth();
        cout << "\nNumebr of Days in Month [" << Month << "] is " 
             << NumberofDaysInMonth(Month, Year);
    
        cout << "\nNumber of Hours in Month [" << Month <<"] is " 
             << NumberofHoursInMonth(Month, Year);

        cout << "\nNumber of Minutes [" << Month << "] is " 
             << NumberOfMinutesInMonth( Month,  Year);

        cout << "\nNumber of Seconds [" << Month << "] is "
             << NumberOfSecondsInMonth(Month, Year) << endl;


    return 0;
}
