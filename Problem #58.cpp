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

struct strPeriod
{
    strDate StartDate,EndDate;
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

bool IsTwoPeriodsOverLap(strPeriod Period1, strPeriod Period2)
{
    if (GetDatesCompareResult(Period1.StartDate, Period2.StartDate) == enCompResult::Before)
    {
        if (GetDatesCompareResult(Period2.StartDate, Period1.EndDate) == enCompResult::Before)
            return true;
        else
            return false;
    }
    else if (GetDatesCompareResult(Period1.StartDate, Period2.StartDate) == enCompResult::After)
    {
        if (GetDatesCompareResult(Period1.StartDate, Period2.EndDate) == enCompResult::Before)
            return true;
        else
            return false;
    }
    
    return true;
}

int main()
{

    strPeriod Period,Period2;

    cout << "Please enter start Date .\n\n";
    Period.StartDate = ReadDate();
    cout << "\n\nPlease enter end Date .\n";
    Period.EndDate = ReadDate();

    cout << "\n\n";

    cout << "Please enter start Date .\n";
    Period2.StartDate = ReadDate();
    cout << "\n\nPlease enter end Date .\n";
    Period2.EndDate = ReadDate();

    if (IsTwoPeriodsOverLap(Period, Period2) == 1)
        cout << "\n\nYes it is overd lap !!\n\n";
    else 
        cout << "\n\No it is not overd lap !!\n\n";

    system("pause>0");
}