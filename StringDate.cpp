// Write a program to:
// Read Date string 
// convert it to date structure
// print Date , Month, Year Separately 
// Then convert Date structure to stirng and print it 
// on the screen
// Note:Write the following functions:
// StringToDate
// DateToString


#include "my_library.h"
#include <iostream>
#include <string>
using namespace std;

string ReadString (string Message)
{
    
    string S1;
    cout << Message;
    getline(cin,S1);
    return S1;
}

void PrintEachWordInString(string S1);

stDate StringToDate ( string S1)
{

    stDate Date;
    vector <string> vDate;
    vDate = SplitString(S1, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string DateToString (stDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year) ;
}



int main ()
{
string S1 = ReadString("\nPlease Enter the Date dd/mm/yyyy ?\n");
stDate Date = StringToDate(S1);
cout << "\nDay: " << Date.Day; 
cout << "\nMonth: " << Date.Month;
cout << "\nYear: " << Date.Year << endl ;
//cout << S1 << endl;

cout << "\nYou Entered: " << DateToString(Date);


    return 0;
}
