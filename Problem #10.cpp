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

void ReadDate(short& Year, short& Month, short& Day)
{
    Year = ReadNumber("Please enter year : ");
    Month = ReadNumber("\n\nPlease enter Month : ");
    Day = ReadNumber("\n\nPlease enter Day : ");
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

short CountDaysUntilDate(short Year, short Month, short Day)
{
    short TotalDays = 0;

    for (short i = 1; i <= Month - 1; i++)
    {
        TotalDays += DaysInaMonth(i, Year);
    }

    TotalDays += Day;

    return TotalDays;
}

int main()
{
    short Year, Month,Day;

    ReadDate(Year, Month, Day);

    cout << "\n\nNumber of Days from the begining of the year is " << CountDaysUntilDate(Year, Month, Day);

    system("pause>0");
}