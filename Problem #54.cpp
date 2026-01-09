#pragma warning(disable : 4996)

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

strDate ReadDate()
{
    strDate Date;

    Date.Year = ReadNumber("Please enter year : ");
    Date.Month = ReadNumber("\nPlease enter Month : ");
    Date.Day = ReadNumber("\nPlease enter Day : ");


    return Date;
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

short GetDayNumber(strDate Date)
{
    return GetDayNumber(Date.Year, Date.Month, Date.Day);
}

string GetDayName(short Day)
{
    string arrDays[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    return arrDays[Day];
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


strDate SystemDate()
{
    time_t t = time(0);
    tm* now = localtime(&t);

    strDate Date;

    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;

    return Date;
}

void Swap2Dates(strDate& Date1, strDate& Date2)
{
    strDate TempDate = Date2;
    Date2 = Date1;
    Date1 = TempDate;
}

bool IsDateLessThanOther(strDate Date1, strDate Date2)
{
    if (Date1.Year != Date2.Year)
        return Date1.Year < Date2.Year;
    else if (Date1.Month != Date2.Month)
        return Date1.Month < Date2.Month;
    else
        return Date1.Day < Date2.Day;

    //return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

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

bool IsWeekEnd(strDate Date)
{
    short CurrentDay = GetDayNumber(Date);

    return CurrentDay == 6 || CurrentDay == 5;
}

bool IsBusinessDay(strDate Date)
{
    return !IsWeekEnd(Date);
}

int GetDifferenceInDays(strDate Date1, strDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    short Sign = 1;

    if (!IsDateLessThanOther(Date1, Date2))
    {
        Swap2Dates(Date1, Date2);
        Sign = -1;
    }

    while (IsDateLessThanOther(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days * Sign : Days * Sign;
}

short GetVacationDays(strDate DateFrom, strDate DateTo)
{
    short DaysCounter = 0;

    while (IsDateLessThanOther(DateFrom, DateTo))
    {
        if (IsBusinessDay(DateFrom))
            DaysCounter++;

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    return DaysCounter;
}

int main()
{
    cout << "Please enter the start of vacation : \n\n";

    strDate Date = ReadDate();

    cout << "\n\nPlease enter the end of vacation : \n\n";

    strDate Date2 = ReadDate();

    cout << "\n\nVacation period is " << GetVacationDays(Date,Date2) << " Day(s) . \n";

    system("pause>0");

}