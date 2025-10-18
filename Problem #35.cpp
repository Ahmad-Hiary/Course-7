#include <iostream>
#include <string>

using namespace std;

string ReadString(string Messege)
{
    cout << Messege << "\n";
    string Words;

    getline(cin, Words);


    return Words;
}

void PrintEachWordAlone(string str)
{
    string Delim = " ";
    string Word;

    short Pos = 0;

    while ((Pos = str.find(Delim)) != std::string::npos)
    {
        Word = str.substr(0, Pos);

        if (Word != "")
        {
            cout << Word << "\n";
        }

        str.erase(0, Pos + Delim.length());
    }

    if (str != "")
    {
        cout << str << "\n";
    }
    
}


int main()
{

    string str = ReadString("Please enter the words to print first letter of each word");

    PrintEachWordAlone(str);

    system("pause");

}
