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


