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

strDate AddOneDayToDate(strDate Date)
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
        Date1 = AddOneDayToDate(Date1);
    }
    return IncludeEndDay ? ++Days * Sign : Days * Sign;
}

void PrintDate(strDate Date)
{
    cout << Date.Year << "/" << Date.Month << "/" << Date.Day << "\n\n";
}

strDate IncreaseDateByOneWeek(strDate Date)
{
    for (short i = 0; i < 7; i++)
    {
        Date = AddOneDayToDate(Date);
    }
    return Date;
}

strDate IncreaseDateByXWeek(strDate Date,short Number)
{
    for (short i = 0; i < Number; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

strDate IncreaseDateByOneMonth(strDate Date)
{
    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }

    short NewMonthsDays = DaysInaMonth(Date.Month, Date.Year);

    if (Date.Day > NewMonthsDays)
        Date.Day = NewMonthsDays;


    return Date;
}

strDate IncreaseDateByXMonth(strDate Date, short Number)
{
    for (short i = 0; i < Number; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

strDate IncreaseDateByOneYear(strDate Date)
{
    Date.Year++;

    short MaxDay = DaysInaMonth(Date.Month, Date.Year);

    if (Date.Day > MaxDay)
        Date.Day = MaxDay;

    return Date;
}

strDate IncreaseDateByXYear(strDate Date, short Number)
{
    Date.Year += Number;

    // Or This way ...

    /*
    for (short i=0; i<=Number ; i++)
    {
      Date = IncreaseDateByOneYear(Date);
    }
    */
    return Date;
}

strDate IncreaseDateByOneDecade(strDate Date)
{
    Date.Year += 10;
    return Date;
}

strDate IncreaseDateByXDecade(strDate Date, short Number)
{
    Date.Year += Number * 10;
    return Date;

    //There is another way using for loop , But this better . 
}

strDate IncreaseDateByOneCentury(strDate Date)
{
    Date.Year += 100;
    return Date;
}

strDate IncreaseDateByOneMillennium(strDate Date)
{
    Date.Year += 1000;
    return Date;
}

int main()
{
    cout << "Please enter Date : \n\n";

    strDate Date1 = ReadDate();

    cout << "\n\nOriginal Date : ";
    PrintDate(Date1);

    Date1 = IncreaseDateByOneWeek(Date1);
    cout << "01- Added One Week : ";
    PrintDate(Date1);

    Date1 = IncreaseDateByXWeek(Date1, 2);
    cout << "02- Added 2 Weeks : ";
    PrintDate(Date1);

    Date1 = IncreaseDateByOneMonth(Date1);
    cout << "03- Added One Month : ";
    PrintDate(Date1);

    Date1 = IncreaseDateByXMonth(Date1, 3);
    cout << "04- Added 3 Months : ";
    PrintDate(Date1);

    Date1 = IncreaseDateByOneYear(Date1);
    cout << "05- Added One Year : ";
    PrintDate(Date1);

    Date1 = IncreaseDateByXYear(Date1, 5);
    cout << "06- Added 5 Years : ";
    PrintDate(Date1);

    Date1 = IncreaseDateByOneDecade(Date1);
    cout << "07- Added One Decade : ";
    PrintDate(Date1);

    Date1 = IncreaseDateByXDecade(Date1, 2);
    cout << "08- Added 2 Decades : ";
    PrintDate(Date1);

    Date1 = IncreaseDateByOneCentury(Date1);
    cout << "09- Added One Century : ";
    PrintDate(Date1);

    Date1 = IncreaseDateByOneMillennium(Date1);
    cout << "10- Added One Millennium : ";
    PrintDate(Date1);

    system("pause>0");
    return 0;
}
