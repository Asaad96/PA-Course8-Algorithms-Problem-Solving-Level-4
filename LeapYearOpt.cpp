// We need to Optimize the code and make in one line of code 


#include <iostream>
using namespace std;

short ReadNumber ()
{
    short Year;
    cout << "Please Enter a Year?\n";
    cin >> Year;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Please Enter a Number of the Year! \n";
        cin >> Year;
    }
    return Year;
}

bool IsLeapYear (short Year)
{
    if( (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0))
    return true;
    else return false;
}


int main ()
{
    short Year = ReadNumber();

    if(IsLeapYear(Year))
        
        cout << "Yes, " << Year << " is a leap Year \n";
    else 
       cout << "No, " << Year << " is Not a leap Year \n";

    return 0 ;
}

