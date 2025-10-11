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

string LowerAllStirng(string Str)
{
    

    for (short i = 0; i < Str.length(); i++)
    {
        Str[i] = tolower(Str[i]);
    }

    return Str;

}

string UpperAllStirng(string Str)
{


    for (short i = 0; i < Str.length(); i++)
    {
        Str[i] = toupper(Str[i]);
    }

    return Str;

}

int main()
{
    string Str = ReadString("enter a string \n");

    Str = UpperAllStirng(Str);

    cout << "The string after convert letters to upper \n" << Str << "\n\n";



    Str = LowerAllStirng(Str);

    cout << "The string after convert letters to lower \n" << Str << "\n\n";
}
