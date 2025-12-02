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
    if (Year % 400 == 0)
    {
        return true;
    }
    else if (Year % 100 == 0)
    {
        return false;
    }
    else if (Year % 4 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
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

