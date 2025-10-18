#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string ReadString(string Messege)
{
	cout << Messege;
	string x;
	getline(cin, x);

	return x;
}

char ReadChar(string Messege)
{
	cout << Messege;
	char x;
	cin >> x;

	return x;
}

char InvertCharecterCase(char Letter)
{
	return isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

short CountLetter(string str, char Letter, bool MatchCase = true)
{
	short Sum = 0;

	for (short i = 0; i < str.length(); i++)
	{
		if (MatchCase)
		{
			if (str[i] == Letter)
				Sum++;
		}
		else if (tolower(Letter) == tolower(str[i]))
		{
			Sum++;
		}
	}

	return Sum;
}

bool IsVowel(char ch)
{
	ch = tolower(ch);

	return ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'));
}

int main()
{
	

	char x = ReadChar("Please enter a character to check is vowel ! \n\n");

	IsVowel(x) ? cout << "\n\nYes it is a vowel letter\n\n" : cout << "\n\nNo not a vowel letter \n\n";

}
