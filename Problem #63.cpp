#include <iostream>
#include <vector>
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

void PrintDate(const strDate& Date)
{
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

vector <string> SplitString(string str, string Delim)
{
    vector <string> vWords;
    string Word = "";

    short Pos = 0;

    while ((Pos = str.find(Delim)) != std::string::npos)
    {
        Word = str.substr(0, Pos);

        if (Word != "")
        {
            vWords.push_back(Word);
        }

        str.erase(0, Pos + Delim.length());
    }

    if (str != "")
    {
        vWords.push_back(str);
    }

    return vWords;
}


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

bool IsDateValid(const strDate Date)
{
    return (Date.Month <= 12 && Date.Month >= 1 && Date.Day <= DaysInaMonth(Date.Month, Date.Year) && Date.Day >= 1 && Date.Year >= 1);
}

strDate ConvertStringToDate(string Str)
{
    vector <string> vDateParts = SplitString(Str,"/");
    strDate Date;

    Date.Year = stoi(vDateParts[2]);
    Date.Month = stoi(vDateParts[1]);
    Date.Day = stoi(vDateParts[0]);

    return Date;
}

string ConvertDateToString(const strDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

int main()
{

    string stringDate;
    cout << "Please enter date : ";
    cin >> stringDate;

    strDate Date = ConvertStringToDate(stringDate);

    cout << "\n\nDate in struct case : ";
    PrintDate(Date);

    stringDate = ConvertDateToString(Date);

    cout << "\n\nDate in string case : " << stringDate << endl;

    system("pause>0");
}