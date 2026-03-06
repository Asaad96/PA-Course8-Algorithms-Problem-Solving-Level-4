// Write a program to check if the year si a leap year or Not 

#include <ios>
#include <iostream>

using namespace std;

int ReadNumber ()
{
     int Year; 
     cout << "Please Enter a Year! \n";
     cin >> Year;

     while (cin.fail())
     {
         cin.clear();
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

         cout << "Please Enter a Number of the Year! \n";
         cin >> Year;
     }

     return Year;
}

bool IsLeapYear(int Year)
{
    if ( Year % 400 == 0 )
    {
        return true;
    }

    if (Year % 4 == 0 ) 
    {
        return true;
    }
    if (Year % 100 == 0 ) 
    {
        return false; 
    }
    else
    {
        return false;
    }
}






int main()
{
    int Year = ReadNumber();
    if(IsLeapYear(Year))
        cout << "It is a leap year \n ";

    else 
        cout << "It is Not a leap year \n";


    return 0;
}
