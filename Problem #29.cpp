#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

enum enWhatToCount { Capital = 0, Small = 1, All = 8 };

string ReadCharecter(string Messege)
{
	cout << Messege;
	string x;
	getline(cin, x);

	return x;
}


short CountCapitalLetters(string str)
{

	short Sum = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]))
			Sum++;
	}
	return Sum;
}

short CountSmallLetters(string str)
{

	short Sum = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (islower(str[i]))
			Sum++;
	}
	return Sum;
}

short CountLettersChosed(string str, enWhatToCount WhatToCount = enWhatToCount::All)
{
	if (WhatToCount == enWhatToCount::All)
	{
		return str.length();
	}

	short Sum = 0;

	for (short i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]) && WhatToCount == enWhatToCount::Capital)
		{
			Sum++;
		}

		if (islower(str[i]) && WhatToCount == enWhatToCount::Small)
		{
			Sum++;
		}

	}

	return Sum;

}

int main()
{
	string str = ReadCharecter("Please enter a string to invert his case ! \n");

	printf("\nThe string length is : %d\n\n", str.length());

	printf("Number of capital letters in string = %d\n\n", CountCapitalLetters(str));

	printf("Number of small letters in string = %d\n\n", CountSmallLetters(str));


	/*  another way .
	
	printf("Number of capital letters in string = %d\n\n", CountLettersChosed(str,enWhatToCount::Capital));

	printf("Number of small letters in string = %d\n\n", CountLettersChosed(str, enWhatToCount::Small));
	*/
}

