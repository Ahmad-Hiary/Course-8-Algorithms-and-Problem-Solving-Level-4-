#include <iostream>

using namespace std;

short ReadShortNumber(string Message)
{
    short Number = 0;
    cout << Message;
    cin >> Number;

    return Number;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);

}

short DaysInaMonth(short Month, short Year)
{
    if (Month < 1 || Month>12)
        return 0;

    short MonthsDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : MonthsDays[Month - 1];

}

int HoursInaMonth(short Month, short Year)
{
    return DaysInaMonth(Month, Year) * 24;
}

long int MinutesInaMonth(short Month, short Year)
{
    return HoursInaMonth(Month, Year) * 60;
}

long long int SecondsInaMonth(short Month, short Year)
{
    return MinutesInaMonth(Month, Year) * 60;
}

int main()
{

    short Year = ReadShortNumber("Please enter the year : ");
    short Month = ReadShortNumber("\n\nPlease enter the month : ");

    cout << "\n\nDays    in this Month : " << DaysInaMonth(Month, Year) << endl;
    cout << "Hours   in this Month : " << HoursInaMonth(Month, Year) << endl;
    cout << "Minuts  in this Month : " << MinutesInaMonth(Month, Year) << endl;
    cout << "Seconds in this Month : " << SecondsInaMonth(Month, Year) << endl;
    cout << "\n\n";

    system("pause>0");
}

