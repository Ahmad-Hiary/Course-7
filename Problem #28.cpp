#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string ReadCharecter(string Messege)
{
	cout << Messege;
	string x;
	getline(cin, x);

	return x;
}

char InvertCharecterCase(char Letter)
{
	return isupper(Letter) ? tolower(Letter) : toupper(Letter);

}

string InvertStringLetterCase(string str)
{
	for (short i = 0; i < str.length(); i++)
	{
		str[i] = InvertCharecterCase(str[i]);
	}
	return str;
}

int main()
{
	string str = ReadCharecter("Please enter a string to invert his case ! \n");

	str = InvertStringLetterCase(str);
	cout << "The Letter after invert is : " << str << "\n\n";
}

