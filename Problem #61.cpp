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
    strDate StartDate, EndDate;
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

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);

}

short GetDayNumber(short Year, short Month, short Day)
{
    if (Month > 12 || Month < 1)
        return 7;

    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DaysInaMonth(short Month, short Year)
{
    if (Month < 1 || Month>12)
        return 0;

    short MonthsDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : MonthsDays[Month - 1];

}

bool IsLastDayInaMonth(strDate Date)
{
    return (Date.Day == DaysInaMonth(Date.Month, Date.Year));
}

bool IsLastMonthInaYear(strDate Date)
{
    return (Date.Month == 12);
}

strDate IncreaseDateByOneDay(strDate Date)
{
    if (IsLastDayInaMonth(Date))
    {
        if (IsLastMonthInaYear(Date))
        {
            Date.Month = 1;
            Date.Day = 1;

            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
        Date.Day++;

    return Date;
}

void Swap2Dates(strDate& Date1, strDate& Date2)
{
    strDate TempDate = Date2;
    Date2 = Date1;
    Date1 = TempDate;
}

int GetDifferenceInDays(strDate Date1, strDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    short Sign = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        Swap2Dates(Date1, Date2);
        Sign = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days * Sign : Days * Sign;
}

strDate ReadDate()
{
    strDate Date;

    Date.Year = ReadNumber("Please enter year : ");
    Date.Month = ReadNumber("\n\nPlease enter Month : ");
    Date.Day = ReadNumber("\n\nPlease enter Day : ");


    return Date;
}

enum enCompResult { Before = -1, Equal = 0, After = 1 };

enCompResult GetDatesCompareResult(strDate Date, strDate Date2)
{
    return IsDate1EqualDate2(Date, Date2) ? enCompResult::Equal : (IsDate1BeforeDate2(Date, Date2) ? enCompResult::Before : enCompResult::After);
}

bool IsTwoPeriodsOverlap(const strPeriod& p1, const strPeriod& p2)
{
    return !(IsDate1BeforeDate2(p1.EndDate, p2.StartDate) ||
        IsDate1BeforeDate2(p2.EndDate, p1.StartDate));
}

short GetPeriodLengthInDays(strPeriod Period, bool IncludeEndDay = false)
{
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}

bool IsDateInSidePeriod(strPeriod Period, strDate Date)
{
    return (GetDatesCompareResult(Period.StartDate, Date) == enCompResult::Before && GetDatesCompareResult(Period.EndDate, Date) == enCompResult::After);
}




int CountOverLappingDays(strPeriod Period1, strPeriod Period2, bool IncludeEndDay = true)
{
    if (!(IsTwoPeriodsOverlap(Period1, Period2)))
        return 0;
    
    int Period1Length = GetPeriodLengthInDays(Period1);
    int Period2Length = GetPeriodLengthInDays(Period2);
    int DaysCounter = 0;

    if (Period1Length < Period2Length)
    {
        while (IsDate1BeforeDate2(Period1.StartDate,Period1.EndDate))
        {
            if (IsDateInSidePeriod(Period2, Period1.StartDate))
                DaysCounter++;

                Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
            
        }
    }
    else
    {
        while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
        {
            if (IsDateInSidePeriod(Period1, Period2.StartDate))
                DaysCounter++;

            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);

        }
    }

    return DaysCounter;
        
}

int main()
{
    strPeriod Period, Period2;

    cout << "\tPeriod 1 \n\n";
    cout << "Please enter start Date .\n\n";
    Period.StartDate = ReadDate();
    cout << "\n\nPlease enter end Date .\n";
    Period.EndDate = ReadDate();

    cout << "\n\n";
    cout << "\tPeriod 2 \n\n";
    cout << "Please enter start Date .\n";
    Period2.StartDate = ReadDate();
    cout << "\n\nPlease enter end Date .\n";
    Period2.EndDate = ReadDate();

    cout << "Number of overlapping days is : " << CountOverLappingDays(Period, Period2);

    system("pause>0");
}