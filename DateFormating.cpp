// DD/MM/YYYY
// YYYY/MM/DD
// MM/DD/YYYY
// DD-MM-YYYY
// YYYY-MM-DD
// MM-DD-YYYY
// DD.MM.YYYY
// YYYY.MM.DD
// MM.DD.YYYY

#include <iostream>
#include <string>
#include "my_library.h"
using namespace std;

enum enDateFormat { DDMMYYY = 1 , YYYYMMDD = 2, MMDDYYY = 3, DDMMYYY_DOT = 4, YYYYMMDD_DOT = 5, MMDDYYYY_DOT = 6, DDMMYYY_Dashed = 7 , YYYYMMDD_Dashed = 8, MMDDYYY_Dashed = 9};


string FormatingDate (stDate StDate, enDateFormat Format = DDMMYYY)
{
        string Separator ;
        if ( Format <= 3 ) Separator = "/";
        else if (  Format <= 6) Separator =  "."; 
        else   Separator =  "-";

        switch (Format) 
        {
            case DDMMYYY:
            case DDMMYYY_DOT:
            case DDMMYYY_Dashed: 
                return to_string(StDate.Day) + Separator + to_string(StDate.Month) + Separator + to_string(StDate.Year);


            case MMDDYYY:
            case MMDDYYYY_DOT:
            case MMDDYYY_Dashed:
                return to_string(StDate.Month) + Separator + to_string(StDate.Day) + Separator + to_string(StDate.Year);


            case YYYYMMDD:
            case YYYYMMDD_DOT:
            case YYYYMMDD_Dashed:
                return to_string(StDate.Year) + Separator + to_string(StDate.Month) + Separator + to_string(StDate.Day) ;

        default: 
                return std::to_string(StDate.Day) + "/" + std::to_string(StDate.Month) + "/" + std::to_string(StDate.Year);

        }
}


void PrintDateFormatMenu()
{
    cout << "\nChoose date format:\n";
    cout << "1: DD/MM/YYYY\n";
    cout << "2: YYYY/MM/DD\n";
    cout << "3: MM/DD/YYYY\n";
    cout << "4: DD.MM.YYYY\n";
    cout << "5: YYYY.MM.DD\n";
    cout << "6: MM.DD.YYYY\n";
    cout << "7: DD-MM-YYYY\n";
    cout << "8: YYYY-MM-DD\n";
    cout << "9: MM-DD-YYYY\n";
    cout << "Your choice: ";
}




int main ()
{
    string Date = ReadString("Please Enter the Date dd/mm/yyyy\n");
    stDate StDate = StringToDate(Date);
    PrintDateFormatMenu(); 
    int choice = ReadNumber(" ");

    string formattedDate = FormatingDate(StDate, (enDateFormat)choice);
    cout << "Date in chosen format: " << formattedDate << endl;


return 0;
}


