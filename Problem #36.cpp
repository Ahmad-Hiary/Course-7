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

short CountWords(string str)
{
    string Delim = " ";
    string Word;

    short Pos = 0;
    short Counter = 0;

    while ((Pos = str.find(Delim)) != std::string::npos)
    {
        Word = str.substr(0, Pos);

        if (Word != "")
        {
            Counter++;
        }

        str.erase(0, Pos + Delim.length());
    }

    if (str != "")
    {
        Counter++;
    }
    return Counter;
}


int main()
{

    string str = ReadString("Please enter the words to print first letter of each word");

    cout << "Words Number is " << CountWords(str) << "\n\n\n";

    system("pause");

}
