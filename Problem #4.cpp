#include <iostream>

using namespace std;

short ReadYear()
{
    short Year = 0;
    cout << "Please enter a year to ckeck : ";
    cin >> Year;

    return Year;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);

}

short DaysInYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}


int HoursInYear(short Year)
{
    return DaysInYear(Year) * 24;
}

long int MinutsInYear(short Year)
{
    return HoursInYear(Year) * 60;
}

long long int SecondsInYear(short Year)
{
   return MinutsInYear(Year) * 60;
}

int main()
{

    short Year = ReadYear();

    cout << "\n\nDays    in this year : " << DaysInYear(Year) << endl;
    cout << "Hours   in this year : " << HoursInYear(Year) << endl;
    cout << "Minuts  in this year : " << MinutsInYear(Year) << endl;
    cout << "Seconds in this year : " << SecondsInYear(Year) << endl;
    cout << "\n\n";

    system("pause>0");
}
