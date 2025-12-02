#include <iostream>
#include <cmath>

using namespace std;

long int ReadNumber(string Messege)
{
	int Number = 0;
	cout << Messege;
	cin >> Number;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Invalid Number !!!\n";
		cout << Messege;
		cin >> Number;
	}

	return Number;
}

string ConvertNumberToText(long int Number)
{
	if (Number == 0)
	{
		return " ";
	}

	if (Number >= 1 && Number <= 19)
	{
		string Arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight",
			"Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
			"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
		return Arr[Number] + " ";
	}
	if (Number >= 20 && Number <= 99)
	{
		string TensArr[] = { "","","Twenty","Thirty","Forty","Fifty"
			,"Sixty","Seventy","Eighty","Ninety" };
		
		return TensArr[Number / 10] + " " + ConvertNumberToText(Number % 10);
	}
	if (Number >= 100 && Number <= 999)
	{
		return ConvertNumberToText(Number / 100) + "Hundred and" + " " + ConvertNumberToText(Number % 100);
	}
	if (Number >= 1000 && Number <= 99999)
	{
		return ConvertNumberToText(Number / 1000) + "Thousand and " + ConvertNumberToText(Number % 1000);
	}
	if (Number >= 100000 && Number <= 999999)
	{
		return ConvertNumberToText(Number / 100000) + "Hundred thousand and " + ConvertNumberToText(Number % 100000);
	}
	if (Number >= 1000000 && Number <= 9999999)
	{
		return ConvertNumberToText(Number / 1000000) + "Million and " + ConvertNumberToText(Number % 1000000);
	}
	if (Number >= 10000000 && Number <= 99999999)
	{
		return ConvertNumberToText(Number / 10000000) + "Billion and " + ConvertNumberToText(Number % 10000000);
	}
}

int main()
{
	long int Number = ReadNumber("Please enter number to convert it to text : ");
	
	cout << ConvertNumberToText(Number) << endl;


	
}
