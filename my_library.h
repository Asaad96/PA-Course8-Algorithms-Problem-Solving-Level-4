#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#include <string>
#include <vector>
#include <fstream>


enum DateStats  { Before = -1, Equal = 0, After = 1};


struct stDate {
    short Day;
    short Month;
    short Year;
};


struct stPeriod 
{
    stDate StartDate;
    stDate EndDate; 
};



int ReadNumber(std::string Message = "Enter a number: ");
bool IsLeapYear(short Year);
short NumberofDaysInMonth(short Month, short Year);
short DayOfWeekOrder(short Day, short Month, short Year);
bool IsValidDate (stDate Date);
stDate ReadFullDate();
stPeriod ReadPeriod();
stDate increaseDateOneDay( stDate Date);
stDate DecreaseDateOneDay(stDate Date);
bool IsLastMonthInTheYear (stDate Date);
bool IsLastDayInTheMonth  (stDate Date);
bool Date1AfterDate2 (stDate Date1 , stDate Date2); 
bool IsDate1BeforeDate2 (stDate Date1, stDate Date2);
bool IsDate1EqualDate2(stDate Date1, stDate Date2);
int  GetDifferenceInDays(stDate Date1 , stDate Date2, bool IncludeEndDay = false);
int GetDifferenceInDaysWithSwap(stDate Date1, stDate Date2, bool IncludeEndDay = false);
void SwapDates(stDate& Date1, stDate& Date2);
short DayOfWeekOrder(stDate Date);
std::string DayShortName(short DayOfWeekOrder);
bool IsEndOfWeek(stDate Date);
bool IsWeekEnd (stDate Date);
bool IsBusinessDay (stDate Date);
stDate GetSystemDate();
stDate CalculateVacationReturnDate(stDate Datestart, short VacationDays);
DateStats  CompareDates (stDate Date1 , stDate Date2);



// ─── Matrix (3D) ───────────────────────────────────────────────
int  RandomNumber(int From, int To);
void FillMatrixWithRandomNumber(int arr[3][3][3], short Rows, short Cols, short depth);
void PrintMatrixWithRandomNumber(int arr[3][3][3], short Rows, short Cols, short depth);

// ─── Matrix (2D) ───────────────────────────────────────────────
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols);
void PrintMatrix(int arr[3][3], short Rows, short Cols);
void SumRowsMatrixNumbers(int arr[3][3], short Rows, short Cols);
int  ColSum(int arr[3][3], short Rows, short ColNumber);
void PrintEachColSum(int arr[3][3], short Rows, short Cols);
void SumMatrixColsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols);
void PrintColsSumArray(int arr[3], short length);
int  OrderNumber(int From, int To);
void FillMatrix(int arr[3][3], int Rows, int Cols);
void PrintMatrixTran(int arr[3][3], short Rows, short Cols);
void MultiplyMatrix(int Matrix1[3][3], int Matrix2[3][3], int MatrixResults[3][3], short Rows, short Cols);
void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols);
void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols);
int  SumOFMatrix(int arr[3][3], short Rows, short Cols);
bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols);
bool AreTypical(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols);
bool IsidentityMartix(int Matrix[3][3], short Rows, short Cols);
bool IsScalar(int Matrix[3][3], short Rows, short Cols);
int  reqNum();
void CountMatrix(int Matrix[3][3], short Rows, short Cols);
short CountNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols);
bool IsSparseMatrix(int Matrix[3][3], short Rows, short Cols);
bool SearchNumber(int Matrix[3][3], int& Number, short Rows, short Cols);
bool CheckExistNumber(int Matrix[3][3], int& Number, short Rows, short Cols);
bool IsNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols);
void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols);
void MinimumNumberinMatrix(int Matrix[3][3], short Rows, short Cols);
void MaximumNumberinMatrix(int Matrix[3][3], short Rows, short Cols);
int  ReverseNumber(int Number);
void IsPalindromeNumber(int Number);
int  IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols);

// ─── Math / Series ─────────────────────────────────────────────
void FibonacciSeries(short Number);
void FibonacciSeries(short Number, int Perv1, int Perv2);

// ─── String ────────────────────────────────────────────────────
enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

std::string ReadString();
char        ReadChar();
void        PrintEachLetterOfString(std::string text);
std::string UpperFirstLetterOfEachWord(std::string S1);
std::string LowerFirstLetterOfEachWord(std::string S1);
std::string UpperLetterOfEachWord(std::string S1);
std::string LowerLetterOfEachWord(std::string S1);
std::string LowerAllString(std::string S1);
char        InvertLetterCase(char char1);
std::string InvertStringCase(std::string S1);
short       CountLetters(std::string S1, enWhatToCount WhatToCount = enWhatToCount::All);
short       CountCapitalLetters(std::string S1);
short       CountSmallLetters(std::string S1);
short       CountLetter(std::string S1, char Letter, bool MatchCase = true);
bool        IsVowel(char Ch1);
short       CountVowel(std::string S1);
void        PrintVowel(std::string S1);
void        PrintEachWordInString(std::string S1);
void        PrintEachWorInString(std::string S1);
std::vector<std::string> SplitString(std::string S1, std::string Delim);
std::string TrimLeft(std::string S1);
std::string TrimRight(std::string S1);
std::string TrimAll(std::string S1);
std::string JoinString(std::vector<std::string> vString, std::string Delim);
std::string JoinString(std::string Arr[], short length, std::string Delim);
std::string ReverseWordsInString(std::string S1);
std::string ReplaceWord(std::string S1, std::string ToReplace, std::string cReplaceTo);
std::string ReplaceString(std::string S1, std::string StringToReplace, std::string ToReplace, bool MatchCase = true);
std::string RemovePunc(std::string S1);

// ─── Client / File ─────────────────────────────────────────────
struct sClient
{
    std::string AccountNumber;
    std::string PinCode;
    std::string Name;
    std::string Phone;
    double      AccountBalance = 0;
    bool        MarkForDelete  = false;
};

sClient     ReadNewClient();
std::string ConvertRecordToLine(sClient Client, std::string Seperator = "#//#");
sClient     ConvertLinetoRecord(std::string Line, std::string Seperator = "#//#");
void        PrintClientRecord(sClient Client);
void        PrintClientCard(sClient Client);
void        AddDataLineToFile(std::string FileName, std::string stDataLine);
void        AddNewClient(std::string FileName);
void        AddClients(std::string FileName);
void        ClearScreen();
std::vector<sClient> LoadClientsDataFromFile(std::string FileName);
void        PrintAllClientData(std::vector<sClient> vClients);
std::string ReadClientAccountNumber();
bool        FindClientByAccountNumber(std::string AccountNumber, std::vector<sClient> vClients, sClient& Client);
bool        MarkClientForDeleteByAccountNumber(std::string AccountNumber, std::vector<sClient>& vClients);
bool        DeleteCLientByAccountNumber(std::string AccountNumber, std::vector<sClient>& vClients, std::string FileName);


#endif
