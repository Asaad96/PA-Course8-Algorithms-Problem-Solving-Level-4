#pragma warning(disable : 4996)

#include "my_library.h"
#include <iostream>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iomanip>



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




short DayOfWeekOrder(short Day, short Month, short Year)
{
short a, y, m, d;
a = (14 - Month) / 12;
y = Year - a;
m = Month + (12 * a) - 2;
// Gregorian:
//0:sun, 1:Mon, 2:Tue...etc
d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    
    return d;
}

short DayOfWeekOrder(stDate Date)
{

     return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
 
}


std::string DayShortName(short DayOfWeekOrder)
{
    std::string arrDayNames[] = {
      "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
 return arrDayNames[DayOfWeekOrder];
}

bool IsEndOfWeek(stDate Date)
{
    return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd (stDate Date)
{
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay (stDate Date)
{
    return (!IsWeekEnd(Date));
}

bool IsValidDate (stDate Date)
{
    if (Date.Month < 1 || Date.Month > 12 ) return false;
    if (Date.Year < 1 ) return false;
    if (Date.Day < 1 || Date.Day > NumberofDaysInMonth(Date.Month ,Date.Year) ) return false ;

    return true;
}



stDate ReadFullDate() {
    stDate Date;

    do {
        Date.Day = ReadNumber("Please enter a Day? ");
        Date.Month = ReadNumber("Please enter a Month? ");
        Date.Year = ReadNumber("Please enter a Year? ");

        if (!IsValidDate(Date))
        {
            std::cout << "\nEnter a valid Date, This Date Does Not Exist in The Calendar! \n";
        }
    } while (!IsValidDate(Date));

    return Date;
}


stPeriod ReadPeriod()
{
    stPeriod Period;
    std::cout << "\nEnter Start Date\n";
    Period.StartDate = ReadFullDate();
    std::cout << "\nEnter End Date\n";
    Period.EndDate = ReadFullDate();
    return Period;
}



bool IsLastMonthInTheYear (stDate Date) 
{
    return (Date.Month == 12);
}

bool IsLastDayInTheMonth (stDate Date)
{  
 return (Date.Day == NumberofDaysInMonth(Date.Month , Date.Year));
        
}

bool IsFirstMonthInTheYear(stDate Date)
{
    return (Date.Month == 1);
}

bool IsFirstDayInTheMonth(stDate Date)
{

    return (Date.Day == 1 );

}


bool Date1AfterDate2 (stDate Date1 , stDate Date2)
{

   return (!IsDate1BeforeDate2(Date1,Date2) && !IsDate1EqualDate2(Date1,Date2));

}


bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
return (Date1.Year == Date2.Year) ? ((Date1.Month ==
Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false)
: false;
}


stDate increaseDateOneDay(stDate Date)

{

   if (IsLastDayInTheMonth(Date))
     { 
        if (IsLastMonthInTheYear(Date))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year ++ ;
        }
        else 
        {
             Date.Month++;
             Date.Day = 1;
        }
     }
   else
    {
        Date.Day++;
    } 
        return Date;

}

stDate DecreaseDateOneDay(stDate Date)
{

    if(IsFirstDayInTheMonth(Date))
    {
        if(IsFirstMonthInTheYear(Date))
        { 
            Date.Month = 12;
            Date.Day = 31;
            Date.Year--;
        }
        else 
        {
            Date.Month --;
            Date.Day = NumberofDaysInMonth(Date.Month, Date.Year);
        }
    }
    else 
    { 
        Date.Day --;
    }
            
return Date;
}


int GetDifferenceInDays(stDate Date1 , stDate Date2 , bool IncludeEndDay)
{
 int Days = 0 ;
 while (IsDate1BeforeDate2(Date1 , Date2))
    {
        Days ++;
        Date1 = increaseDateOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;

}


void SwapDates (stDate& Date1 , stDate& Date2)
{

    stDate TempDate;


    TempDate.Year = Date1.Year;
    TempDate.Month = Date1.Month;
    TempDate.Day = Date1.Day;

    Date1.Year = Date2.Year;
    Date1.Month = Date2.Month;
    Date1.Day = Date2.Day;


    Date2.Year = TempDate.Year ;
    Date2.Month = TempDate.Month;
    Date2.Day = TempDate.Day;

}


int GetDifferenceInDaysWithSwap(stDate Date1 , stDate Date2 , bool IncludeEndDay )
{
 int Days = 0 ; 
 short SwapFlagValue = 1;

 if (!IsDate1BeforeDate2(Date1, Date2))
 {
     //SwapDates 
     SwapDates(Date1 , Date2);
     SwapFlagValue = -1;
 }

 while (IsDate1BeforeDate2(Date1 , Date2))
    {
        Days ++;
        Date1 = increaseDateOneDay(Date1);
    }
    return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;

}

stDate GetSystemDate()
{
    stDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;
}


DateStats  CompareDates (stDate Date1 , stDate Date2)
{
  if(IsDate1BeforeDate2(Date1,Date2))
      return DateStats::Before;
  if(IsDate1EqualDate2(Date1,Date2))
      return DateStats::Equal;

  return DateStats::After;
}



// ================================================================
// ─── Matrix 3D ──────────────────────────────────────────────────
// ================================================================

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumber(int arr[3][3][3], short Rows, short Cols, short depth)
{
    for (short i = 0; i < Rows; i++)
        for (short j = 0; j < Cols; j++)
            for (short k = 0; k < depth; k++)
                arr[i][j][k] = RandomNumber(1, 100);
}

void PrintMatrixWithRandomNumber(int arr[3][3][3], short Rows, short Cols, short depth)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
            for (short k = 0; k < depth; k++)
                printf("%3d   ", arr[i][j][k]);
        std::cout << "\n\n";
    }
}

// ================================================================
// ─── Matrix 2D ──────────────────────────────────────────────────
// ================================================================

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
        for (short j = 0; j < Cols; j++)
            arr[i][j] = RandomNumber(1, 100);
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
            printf(" %02d ", arr[i][j]);
        std::cout << "\n";
    }
}

void SumRowsMatrixNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        int Sum = 0;
        for (short j = 0; j < Cols; j++)
            Sum += arr[i][j];
        std::cout << "Row " << i + 1 << " Sum = " << Sum << "\n";
    }
}

int ColSum(int arr[3][3], short Rows, short ColNumber)
{
    int Sum = 0;
    for (short i = 0; i < Rows; i++)
        Sum += arr[i][ColNumber];
    return Sum;
}

void PrintEachColSum(int arr[3][3], short Rows, short Cols)
{
    std::cout << "\nThe following are the sum of each col in the matrix:\n";
    for (short j = 0; j < Cols; j++)
        std::cout << "Col " << j + 1 << " Sum = " << ColSum(arr, Rows, j) << "\n";
}

void SumMatrixColsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
    for (short j = 0; j < Cols; j++)
        arrSum[j] = ColSum(arr, Rows, j);
}

void PrintColsSumArray(int arr[3], short length)
{
    std::cout << "\nThe following are the sum of each col in the matrix:\n";
    for (short i = 0; i < length; i++)
        std::cout << "Col " << i + 1 << " Sum = " << arr[i] << "\n";
}

int OrderNumber(int From, int To)
{
    static int Number = From;
    if (Number > To) return -1;
    return Number++;
}

void FillMatrix(int arr[3][3], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
            arr[i][j] = OrderNumber(1, 9);
}

void PrintMatrixTran(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
            printf("%3d   ", arr[j][i]);
        std::cout << "\n";
    }
}

void MultiplyMatrix(int Matrix1[3][3], int Matrix2[3][3], int MatrixResults[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
        for (short j = 0; j < Cols; j++)
            MatrixResults[i][j] = Matrix1[i][j] * Matrix2[i][j];
}

void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols)
{
    short MiddleRow = Rows / 2;
    for (short j = 0; j < Cols; j++)
        printf(" %02d  ", arr[MiddleRow][j]);
    std::cout << "\n";
}

void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols)
{
    short MiddleCol = Cols / 2;
    for (short i = 0; i < Rows; i++)
        printf(" %02d  ", arr[i][MiddleCol]);
    std::cout << "\n";
}

int SumOFMatrix(int arr[3][3], short Rows, short Cols)
{
    int Sum = 0;
    for (short i = 0; i < Rows; i++)
        for (short j = 0; j < Cols; j++)
            Sum += arr[i][j];
    return Sum;
}

bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    return (SumOFMatrix(Matrix1, Rows, Cols) == SumOFMatrix(Matrix2, Rows, Cols));
}

bool AreTypical(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
        for (short j = 0; j < Cols; j++)
            if (Matrix1[i][j] != Matrix2[i][j])
                return false;
    return true;
}

bool IsidentityMartix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix[i][j] != 1) return false;
            if (i != j && Matrix[i][j] != 0) return false;
        }
    return true;
}

bool IsScalar(int Matrix[3][3], short Rows, short Cols)
{
    int FirstDiag = Matrix[0][0];
    for (short i = 0; i < Rows; i++)
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix[i][j] != FirstDiag) return false;
            if (i != j && Matrix[i][j] != 0)         return false;
        }
    return true;
}

int reqNum()
{
    int Num = 0;
    std::cout << "Please Enter the Number to count in Matrix!\n";
    std::cin >> Num;
    return Num;
}

void CountMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int EnterNum = reqNum();
    int count = 0;
    for (short i = 0; i < Rows; i++)
        for (short j = 0; j < Cols; j++)
            if (Matrix[i][j] == EnterNum) count++;
    std::cout << "Number " << EnterNum << " count in Matrix is " << count << "\n";
}

short CountNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols)
{
    short NumberCount = 0;
    for (short i = 0; i < Rows; i++)
        for (short j = 0; j < Cols; j++)
            if (Matrix[i][j] == Number) NumberCount++;
    return NumberCount;
}

bool IsSparseMatrix(int Matrix[3][3], short Rows, short Cols)
{
    short MatrixSize = Rows * Cols;
    return (CountNumberInMatrix(Matrix, 0, Rows, Cols) >= ceil((float)MatrixSize / 2));
}

bool SearchNumber(int Matrix[3][3], int& Number, short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
        for (short j = 0; j < Cols; j++)
            if (Number == Matrix[i][j]) return true;
    return false;
}

bool CheckExistNumber(int Matrix[3][3], int& Number, short Rows, short Cols)
{
    return SearchNumber(Matrix, Number, Rows, Cols);
}

bool IsNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
        for (short j = 0; j < Cols; j++)
            if (Matrix[i][j] == Number) return true;
    return false;
}

void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
        for (short j = 0; j < Cols; j++)
            if (IsNumberInMatrix(Matrix2, Matrix1[i][j], Rows, Cols))
                printf("%3d ", Matrix1[i][j]);
}

void MinimumNumberinMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int Mini = Matrix[0][0];
    for (short i = 0; i < Rows; i++)
        for (short j = 0; j < Cols; j++)
            if (Matrix[i][j] < Mini) Mini = Matrix[i][j];
    std::cout << "Minimum Number is " << Mini << "\n";
}

void MaximumNumberinMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int Max = Matrix[0][0];
    for (short i = 0; i < Rows; i++)
        for (short j = 0; j < Cols; j++)
            if (Matrix[i][j] > Max) Max = Matrix[i][j];
    std::cout << "Maximum Number is " << Max << "\n";
}

int ReverseNumber(int Number)
{
    int Remainder = 0, Number2 = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number    = Number / 10;
        Number2   = Number2 * 10 + Remainder;
    }
    return Number2;
}

void IsPalindromeNumber(int Number)
{
    if (Number == ReverseNumber(Number))
        std::cout << "Is Palindrome Number\n";
    else
        std::cout << "Is NOT Palindrome Number\n";
}

int IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
        for (short j = 0; j < Cols / 2; j++)
            if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j])
                return false;
    return true;
}

// ================================================================
// ─── Math / Series ──────────────────────────────────────────────
// ================================================================

void FibonacciSeries(short Number)
{
    int FebNumber = 0, Perv1 = 1, Perv2 = 0;
    std::cout << "1  ";
    for (short i = 2; i <= Number; ++i)
    {
        FebNumber = Perv2 + Perv1;
        std::cout << FebNumber << "  ";
        Perv2 = Perv1;
        Perv1 = FebNumber;
    }
}

void FibonacciSeries(short Number, int Perv1, int Perv2)
{
    if (Number > 0)
    {
        int FebNumber = Perv2 + Perv1;
        Perv2 = Perv1;
        Perv1 = FebNumber;
        std::cout << FebNumber << "  ";
        FibonacciSeries(Number - 1, Perv1, Perv2);
    }
}

// ================================================================
// ─── String ─────────────────────────────────────────────────────
// ================================================================

std::string ReadString()
{
    std::string S1;
    std::cout << "Please Enter Your String?\n";
    getline(std::cin, S1);
    return S1;
}

char ReadChar()
{
    char Ch1;
    std::cout << "Please Enter a Character?\n";
    std::cin >> Ch1;
    return Ch1;
}

void PrintEachLetterOfString(std::string text)
{
    bool isFirstLetter = true;
    std::cout << "\nFirst Letters of this string\n";
    for (int i = 0; i < (int)text.length(); i++)
    {
        if (text[i] != ' ' && isFirstLetter)
            std::cout << text[i] << "\n";
        isFirstLetter = (text[i] == ' ');
    }
}

std::string UpperFirstLetterOfEachWord(std::string S1)
{
    bool isFirstLetter = true;
    for (short i = 0; i < (short)S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
            S1[i] = toupper(S1[i]);
        isFirstLetter = (S1[i] == ' ');
    }
    return S1;
}

std::string LowerFirstLetterOfEachWord(std::string S1)
{
    bool isFirstLetter = true;
    for (short i = 0; i < (short)S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
            S1[i] = tolower(S1[i]);
        isFirstLetter = (S1[i] == ' ');
    }
    return S1;
}

std::string UpperLetterOfEachWord(std::string S1)
{
    for (short i = 0; i < (short)S1.length(); i++)
        S1[i] = toupper(S1[i]);
    return S1;
}

std::string LowerLetterOfEachWord(std::string S1)
{
    for (short i = 0; i < (short)S1.length(); i++)
        S1[i] = tolower(S1[i]);
    return S1;
}

std::string LowerAllString(std::string S1)
{
    for (short i = 0; i < (short)S1.length(); i++)
        S1[i] = tolower(S1[i]);
    return S1;
}

char InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}

std::string InvertStringCase(std::string S1)
{
    for (short i = 0; i < (short)S1.length(); i++)
        S1[i] = InvertLetterCase(S1[i]);
    return S1;
}

short CountLetters(std::string S1, enWhatToCount WhatToCount)
{
    if (WhatToCount == enWhatToCount::All)
        return S1.length();
    short Counter = 0;
    for (short i = 0; i < (short)S1.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i])) Counter++;
        if (WhatToCount == enWhatToCount::SmallLetters   && islower(S1[i])) Counter++;
    }
    return Counter;
}

short CountCapitalLetters(std::string S1)
{
    short Counter = 0;
    for (short i = 0; i < (short)S1.length(); i++)
        if (isupper(S1[i])) Counter++;
    return Counter;
}

short CountSmallLetters(std::string S1)
{
    short Counter = 0;
    for (short i = 0; i < (short)S1.length(); i++)
        if (islower(S1[i])) Counter++;
    return Counter;
}

short CountLetter(std::string S1, char Letter, bool MatchCase)
{
    short Counter = 0;
    for (short i = 0; i < (short)S1.length(); i++)
    {
        if (MatchCase)
        { if (S1[i] == Letter) Counter++; }
        else
        { if (tolower(S1[i]) == tolower(Letter)) Counter++; }
    }
    return Counter;
}

bool IsVowel(char Ch1)
{
    Ch1 = tolower(Ch1);
    return (Ch1=='a'||Ch1=='e'||Ch1=='i'||Ch1=='o'||Ch1=='u');
}

short CountVowel(std::string S1)
{
    short counter = 0;
    for (short i = 0; i < (short)S1.length(); i++)
        if (IsVowel(S1[i])) counter++;
    return counter;
}

void PrintVowel(std::string S1)
{
    for (short i = 0; i < (short)S1.length(); i++)
        if (IsVowel(S1[i])) std::cout << S1[i] << "  ";
    std::cout << "\n";
}

void PrintEachWordInString(std::string S1)
{
    std::string delim = " ";
    std::cout << "\nYour string words are:\n\n";
    short pos = 0;
    std::string sWord;
    while ((pos = S1.find(delim)) != (short)std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "") std::cout << sWord << "\n";
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "") std::cout << S1 << "\n";
}

void PrintEachWorInString(std::string S1)
{
    std::string delim = " ";
    short pos = 0, counter = 0;
    std::string sWord;
    while ((pos = S1.find(delim)) != (short)std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "") counter++;
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "") counter++;
    std::cout << "The Number of words in your string is: " << counter << "\n";
}

std::vector<std::string> SplitString(std::string S1, std::string Delim)
{
    std::vector<std::string> vString;
    short pos = 0;
    std::string sWord;
    while ((pos = S1.find(Delim)) != (short)std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "") vString.push_back(sWord);
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "") vString.push_back(S1);
    return vString;
}

std::string TrimLeft(std::string S1)
{
    for (short i = 0; i < (short)S1.length(); i++)
        if (S1[i] != ' ') return S1.substr(i, S1.length() - 1);
    return "";
}

std::string TrimRight(std::string S1)
{
    for (short i = S1.length() - 1; i >= 0; i--)
        if (S1[i] != ' ') return S1.substr(0, i + 1);
    return "";
}

std::string TrimAll(std::string S1)
{
    return TrimLeft(TrimRight(S1));
}

std::string JoinString(std::vector<std::string> vString, std::string Delim)
{
    std::string S1 = "";
    for (std::string& s : vString)
        S1 = S1 + s + Delim;
    return S1.substr(0, S1.length() - Delim.length());
}

std::string JoinString(std::string Arr[], short length, std::string Delim)
{
    std::string S1 = "";
    for (short i = 0; i < length; i++)
        S1 = S1 + Arr[i] + Delim;
    return S1.substr(0, S1.length() - Delim.length());
}

std::string ReverseWordsInString(std::string S1)
{
    std::vector<std::string> vString = SplitString(S1, " ");
    std::string S2 = "";
    std::vector<std::string>::iterator iter = vString.end();
    while (iter != vString.begin())
    {
        --iter;
        S2 += *iter + " ";
    }
    return TrimRight(S2);
}

std::string ReplaceWord(std::string S1, std::string ToReplace, std::string cReplaceTo)
{
    short pos = S1.find(ToReplace);
    while (pos != (short)std::string::npos)
    {
        S1  = S1.replace(pos, ToReplace.length(), cReplaceTo);
        pos = S1.find(ToReplace);
    }
    return S1;
}

std::string ReplaceString(std::string S1, std::string StringToReplace, std::string ToReplace, bool MatchCase)
{
    std::vector<std::string> vString = SplitString(S1, " ");
    for (std::string& s : vString)
    {
        if (MatchCase)
        { if (s == StringToReplace) s = ToReplace; }
        else
        { if (LowerAllString(s) == LowerAllString(StringToReplace)) s = ToReplace; }
    }
    return JoinString(vString, " ");
}

std::string RemovePunc(std::string S1)
{
    std::string S2 = "";
    for (short i = 0; i < (short)S1.length(); i++)
        if (!ispunct(S1[i])) S2 += S1[i];
    return S2;
}

// ================================================================
// ─── Client / File ──────────────────────────────────────────────
// ================================================================

void ClearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

sClient ReadNewClient()
{
    sClient Client;
    std::cout << "Enter Account Number: ";
    getline(std::cin >> std::ws, Client.AccountNumber);
    std::cout << "Enter PinCode: ";
    getline(std::cin, Client.PinCode);
    std::cout << "Enter Name: ";
    getline(std::cin, Client.Name);
    std::cout << "Enter Phone: ";
    getline(std::cin, Client.Phone);
    std::cout << "Enter Account Balance: ";
    std::cin >> Client.AccountBalance;
    return Client;
}

std::string ConvertRecordToLine(sClient Client, std::string Seperator)
{
    std::string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode       + Seperator;
    stClientRecord += Client.Name          + Seperator;
    stClientRecord += Client.Phone         + Seperator;
    stClientRecord += std::to_string(Client.AccountBalance);
    return stClientRecord;
}

sClient ConvertLinetoRecord(std::string Line, std::string Seperator)
{
    sClient Client;
    std::vector<std::string> vClientData = SplitString(Line, Seperator);
    if (vClientData.size() < 5) return Client;
    Client.AccountNumber  = vClientData[0];
    Client.PinCode        = vClientData[1];
    Client.Name           = vClientData[2];
    Client.Phone          = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);
    return Client;
}

void PrintClientRecord(sClient Client)
{
    std::cout << "\nAccount Number : " << Client.AccountNumber;
    std::cout << "\nPin Code       : " << Client.PinCode;
    std::cout << "\nName           : " << Client.Name;
    std::cout << "\nPhone          : " << Client.Phone;
    std::cout << "\nAccount Balance: " << Client.AccountBalance << "\n";
}

void PrintClientCard(sClient Client)
{
    std::cout << "\nThe Following are the Client details:\n";
    PrintClientRecord(Client);
}

void AddDataLineToFile(std::string FileName, std::string stDataLine)
{
    std::fstream MyFile;
    MyFile.open(FileName, std::ios::out | std::ios::app);
    if (MyFile.is_open())
    {
        MyFile << stDataLine << "\n";
        MyFile.close();
    }
}

void AddNewClient(std::string FileName)
{
    sClient Client = ReadNewClient();
    AddDataLineToFile(FileName, ConvertRecordToLine(Client));
}

void AddClients(std::string FileName)
{
    char AddMore = 'Y';
    do
    {
        ClearScreen();
        std::cout << "Adding New Client:\n\n";
        AddNewClient(FileName);
        std::cout << "\nClient Added Successfully. Add more? Y/N\n";
        std::cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

std::vector<sClient> LoadClientsDataFromFile(std::string FileName)
{
    std::vector<sClient> vClients;
    std::fstream MyFile;
    MyFile.open(FileName, std::ios::in);
    if (MyFile.is_open())
    {
        std::string Line;
        while (getline(MyFile, Line))
            vClients.push_back(ConvertLinetoRecord(Line));
        MyFile.close();
    }
    return vClients;
}

void PrintAllClientData(std::vector<sClient> vClients)
{
    std::cout << "\n\t\t\t Clients List (" << vClients.size() << ") Client(s)";
    std::cout << "\n" << std::string(100, '-') << "\n";
    printf("| %-15s| %-10s| %-30s| %-15s| %-12s\n",
           "Account Number","Pin Code","Client Name","Phone","Balance");
    std::cout << std::string(100, '-') << "\n";
    for (sClient Client : vClients)
    {
        printf("| %-15s| %-10s| %-30s| %-15s| %-12.2f\n",
               Client.AccountNumber.c_str(),
               Client.PinCode.c_str(),
               Client.Name.c_str(),
               Client.Phone.c_str(),
               Client.AccountBalance);
    }
    std::cout << std::string(100, '-') << "\n";
}

std::string ReadClientAccountNumber()
{
    std::string AccountNumber = "";
    std::cout << "\nPlease Enter Account Number? ";
    std::cin >> AccountNumber;
    return AccountNumber;
}

bool FindClientByAccountNumber(std::string AccountNumber, std::vector<sClient> vClients, sClient& Client)
{
    for (sClient C : vClients)
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    return false;
}

bool MarkClientForDeleteByAccountNumber(std::string AccountNumber, std::vector<sClient>& vClients)
{
    for (sClient& C : vClients)
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    return false;
}

bool DeleteCLientByAccountNumber(std::string AccountNumber, std::vector<sClient>& vClients, std::string FileName)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        std::cout << "\nAre you sure you want to delete this client? Y/N\n";
        std::cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            std::fstream MyFile;
            MyFile.open(FileName, std::ios::out);
            if (MyFile.is_open())
            {
                for (sClient& C : vClients)
                    if (!C.MarkForDelete)
                        MyFile << ConvertRecordToLine(C) << "\n";
                MyFile.close();
            }
            vClients = LoadClientsDataFromFile(FileName);
            std::cout << "\nClient Deleted Successfully.\n";
            return true;
        }
    }
    else
        std::cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
    return false;
}
