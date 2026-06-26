#include "my_library.h"
#include <iostream>
using namespace std;


int main ()
{

cout <<"Please Enter Date1:\n";
stDate Date1 = ReadFullDate();

cout <<"Please Enter Date2:\n";
stDate Date2= ReadFullDate();

if(Date1AfterDate2(Date1,Date2)) 
        cout << "\nYes, Date1 Is After Date2\n";

else
        cout << "\nNo, Date1 Is NOT After Date2\n";



return 0;
}
