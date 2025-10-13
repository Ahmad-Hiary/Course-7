#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

enum enWhatToCount { Capital = 0, Small = 1, All = 8 };

string ReadString(string Messege)
{
	cout << Messege;
	string x;
	getline(cin, x);

	return x;
}

char ReadCharacter(string Messege)
{
	cout << Messege;
	char x;
	cin >> x;
	return x;
}

short CountChosedCharacterInString(char ChosedCharacter, string str)
{
	short Sum = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (str[i]==ChosedCharacter)
			Sum++;
	}
	return Sum;
}

int main()
{
	string str = ReadString("Please enter a string ! \n");

	char ch = ReadCharacter("Please enter a character to count in string .\n");

	printf("\n\nThe letter %c count in string %d times .\n\n", ch, CountChosedCharacterInString(ch, str));

}
