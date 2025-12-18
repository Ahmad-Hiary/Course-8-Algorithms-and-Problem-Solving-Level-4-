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
    Date.Month = ReadNumber("\n\nPlease enter Month : ");
    Date.Day = ReadNumber("\n\nPlease enter Day : ");


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

int main()
{

    strDate Date = ReadDate();

    cout << "\n\nDate     : " << Date.Year << " / " << Date.Month << " / " << Date.Day << endl;

    Date = AddOneDayToDate(Date);

    cout << "\n\nNew Date : " << Date.Year << " / " << Date.Month << " / " << Date.Day << endl;


    system("pause>0");
}

