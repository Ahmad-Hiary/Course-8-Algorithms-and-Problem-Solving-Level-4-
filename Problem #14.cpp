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

bool AreDatesEqual(strDate Date1, strDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) : false) : false;
}

int main()
{

    strDate Date1 = ReadDate();

    cout << "\n\n";

    strDate Date2 = ReadDate();

    if (AreDatesEqual(Date1, Date2))
        cout << "\nYes Equal (:\n\n";
    else
        cout << "\No not Equal (:\n\n";

    system("pause>0");
}