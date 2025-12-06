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

string GetMonthName(short Month)
{
    string Months[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

    return Months[Month - 1];
}

void PrintMonthCalendar(short Year, short Month)
{
    short Current = GetDayNumber(Year, Month, 1);
    short DaysInTheMonth = DaysInaMonth(Month, Year);

    printf("\n _______________%s________________\n\n", GetMonthName(Month).c_str());

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    short i;
    for (i = 0; i < Current; i++)
        printf("     ");

    for (short j = 1; j <= DaysInTheMonth; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            printf("\n");
            i = 0;
        }
    }

    printf("\n __________________________________\n");
}

void PrintYearCalendar(short Year)
{
    printf("\n\n          Calendar %d \n\n", Year);

    for (short i = 1; i <= 12; i++)
    {
        PrintMonthCalendar(Year, i);
        cout << "\n\n";
    }
}

int main()
{
    short Year, Month;
    Year = ReadNumber("Please enter year : ");
    

    PrintYearCalendar(Year);

}