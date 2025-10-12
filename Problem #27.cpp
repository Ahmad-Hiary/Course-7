#include <iostream>
#include <cctype>

using namespace std;

char ReadCharecter(string Messege)
{
	cout << Messege;
	char x = ' ';
	cin >> x;

	return x;
}

char InvertCharecterCase(char Letter)
{
	return isupper(Letter) ? tolower(Letter) : toupper(Letter);

}

int main()
{
	char Letter = ReadCharecter("Please enter a charecter to invert his case ! \n");

	Letter = InvertCharecterCase(Letter);

	cout << "The Letter after invert is : " << Letter << "\n\n";
}

