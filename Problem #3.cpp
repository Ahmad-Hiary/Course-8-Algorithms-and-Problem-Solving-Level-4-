#include <iostream>

using namespace std;

short ReadYear()
{
    short Year = 0;
    cout << "Please enter a year ot ckeck : ";
    cin >> Year;

    return Year;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);

}

int main()
{

    short Year = ReadYear();

    if (IsLeapYear(Year))
    {
        cout << "\n\nYes it is leap year .";
    }
    else
    {
        cout << "\n\n NO it is not leap year .";
    }
}

