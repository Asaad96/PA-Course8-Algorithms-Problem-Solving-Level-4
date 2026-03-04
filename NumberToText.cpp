 // Write a program to read a number and print the text of that number 
 // Enter  a number : 5843 -> Five thousands eight Hunders forty three



#include <iostream>
#include <string>
#include <limits>

using namespace std;

string NumberToText(long long Number)
{
    if (Number == 0)
        return "Zero";

    if (Number < 0)
        return "Minus " + NumberToText(-Number);

    if (Number >= 1000000000)
    {
        long long billions = Number / 1000000000;
        long long remainder = Number % 1000000000;

        if (remainder == 0)
            return NumberToText(billions) + " Billion";

        return NumberToText(billions) + " Billion " + NumberToText(remainder);
    }

    if (Number >= 1000000)
    {
        long long millions = Number / 1000000;
        long long remainder = Number % 1000000;

        if (remainder == 0)
            return NumberToText(millions) + " Million";

        return NumberToText(millions) + " Million " + NumberToText(remainder);
    }

    if (Number >= 1000)
    {
        long long thousands = Number / 1000;
        long long remainder = Number % 1000;

        if (remainder == 0)
            return NumberToText(thousands) + " Thousand";

        return NumberToText(thousands) + " Thousand " + NumberToText(remainder);
    }

    if (Number >= 100)
    {
        long long hundreds = Number / 100;
        long long remainder = Number % 100;

        if (remainder == 0)
            return NumberToText(hundreds) + " Hundred";

        return NumberToText(hundreds) + " Hundred " + NumberToText(remainder);
    }

    if (Number >= 20)
    {
        string tens[] = {
            "", "", "Twenty", "Thirty", "Forty",
            "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
        };

        long long remainder = Number % 10;

        if (remainder == 0)
            return tens[Number / 10];

        return tens[Number / 10] + " " + NumberToText(remainder);
    }

    string ones[] = {
        "", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    return ones[Number];
}

long long ReadNumber()
{
    long long Number;

    cout << "Enter a Number: ";
    cin >> Number;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid number: ";
        cin >> Number;
    }

    return Number;
}

int main()
{
    long long Number = ReadNumber();
    cout << NumberToText(Number) << endl;

    return 0;
}
