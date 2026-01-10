#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

short ReadNumber(string Message)
{
    cout << Message;
    short n;
    cin >> n;

    return n;
}

struct strDate
{
    short Year, Month, Day;
};

bool IsDate1BeforeDate2(strDate Date1, strDate Date2)
{
    if (Date1.Year != Date2.Year)
        return Date1.Year < Date2.Year;
    else if (Date1.Month != Date2.Month)
        return Date1.Month < Date2.Month;
    else
        return Date1.Day < Date2.Day;

    //return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}

bool IsDate1EqualDate2(strDate Date1, strDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(strDate Date1, strDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && (!IsDate1EqualDate2(Date1, Date2)));
}

strDate ReadDate()
{
    strDate Date;

    Date.Year = ReadNumber("Please enter year : ");
    Date.Month = ReadNumber("\n\nPlease enter Month : ");
    Date.Day = ReadNumber("\n\nPlease enter Day : ");


    return Date;
}

enum enCompResult { Before = -1, Equla = 0, After = 1 };

enCompResult GetDatesCompareResult(strDate Date, strDate Date2)
{
    return IsDate1EqualDate2(Date, Date2) ? enCompResult::Equla : (IsDate1BeforeDate2(Date, Date2) ? enCompResult::Before : enCompResult::After);
}

int main()
{

    strDate Date1 = ReadDate();

    cout << "\n\n";

    strDate Date2 = ReadDate();

    if (GetDatesCompareResult(Date1, Date2) == enCompResult::Equla)
        cout << "\nCompare result is : 0\n\n";
    else if (GetDatesCompareResult(Date1, Date2) == enCompResult::After)
        cout << "\nCompare result is : 1\n\n";
    else 
        cout << "\nCompare result is : -1\n\n";

    system("pause>0");
}