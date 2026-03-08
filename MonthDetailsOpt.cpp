// We need to Optimize the previous code to replace with two lines of two code


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

short NumberOfDaysInAMonth(short Month, short Year)
{   if (Month < 1 || Month > 12)
    return 0;

      int NumberofDays[12] = {31,28,31,30,31,30,31,30,31,30,31,30};

        return ( Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberofDays[Month]; // Ternary Conditional Operator
 }

int main()
{
  short Year = ReadYear();
  short Month = ReadMonth();
  cout << "\nNumber of Days in Month [" << Month << "] is " << NumberOfDaysInAMonth(Month, Year);
  return 0;
}

