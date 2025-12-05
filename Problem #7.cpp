#include <iostream>
#include <string>

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
    short m = 12 * a + Month - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string GetDayName(short Day)
{
    string arrDays[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    return arrDays[Day];
}

int main()
{
    short Year, Month, Day;
    Year = ReadNumber("Please enter year : ");
    Month= ReadNumber("\nPlease enter month : ");
    Day= ReadNumber("\nPlease enter day : ");

    cout << "\n\nDate       : " << Year << "/" << Month << "/" << Day << endl;
    cout << "Day Number : " << GetDayNumber(Year, Month, Day) << endl;
    cout << "Day        : " << GetDayName(GetDayNumber(Year, Month, Day)) << endl;

    system("pause>0");
}

