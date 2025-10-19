#include <iostream>
#include <string>

using namespace std;

string TrimLeft(string str)
{
    for (short i = 0; i <= str.length(); i++)
    {
        if (str[i] != ' ')
        {
            return str.substr(i, str.length() - i);
        }
    }
}

string TrimRight(string str)
{
    for (short i = str.length()-1 ; i >= 0; i--)
    {
        if (str[i] != ' ')
        {
            return str.substr(0, i+1);
        }
    }
}

string Trim(string str)
{
    return TrimRight(TrimLeft(str));
}

int main()
{
    string Str = "     Ahmad Faris Al-Hiary     ";

    cout << "The string = " << Str << "\n";
    cout << "Trim left  = " << TrimLeft(Str) << "\n";
    cout << "Trim Right = " << TrimRight(Str) << "\n";
    cout << "Trim       = " << Trim(Str);
}