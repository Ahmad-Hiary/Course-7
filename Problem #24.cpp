#include <iostream>
#include <cctype>
#include <string>

using namespace std;


string ReadString(string Messege)
{
    cout << Messege << "\n";
    string Words;

    getline(cin, Words);


    return Words;
}

string ConvertFirstLetterToUpperInEachWord(string Str)
{
    bool IsFirstLetter = true;

    for (short i = 0; i < Str.length(); i++)
    {
        if (Str[i] != ' ' && IsFirstLetter)
        {
            Str[i] = toupper(Str[i]);
        }
       

        IsFirstLetter = (Str[i] == ' ') ? true : false;
    }

    return Str;

}

int main()
{
    string Str = ReadString("enter a string \n");

    Str = ConvertFirstLetterToUpperInEachWord(Str);

    cout << "The string after convert each first letter to upper \n" << Str << "\n\n";
}
