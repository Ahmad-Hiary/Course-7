#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString(string Messege)
{
    cout << Messege << "\n";
    string Words;

    getline(cin, Words);


    return Words;
}

vector <string> SplitString(string str, string Delim)
{
    vector <string> vWords;
    string Word;

    short Pos = 0;

    while ((Pos = str.find(Delim)) != std::string::npos)
    {
        Word = str.substr(0, Pos);

        if (Word != "")
        {
            vWords.push_back(Word);
        }

        str.erase(0, Pos + Delim.length());
    }

    if (str != "")
    {
        vWords.push_back(str);
    }

    return vWords;

}

string ReverseString(string str, string Delim = " ")
{
    vector <string> vSplitedString;
    
    vSplitedString = SplitString(str, Delim);

    string Result = "";
    
    vector <string>::iterator Iter = vSplitedString.end();

    while (Iter != vSplitedString.begin())
    {
        Iter--;

        Result += *Iter + Delim;

    }

    Result = Result.erase(Result.length() - Delim.length(), Delim.length());

    return Result;

}

int main()
{

    string str = ReadString("Please enter the words to print first letter of each word\n\n");

    str = ReverseString(str);

    cout << "Reversed string =  " << str                                                                                                                                                ;
    cout << "\n\n";
    system("pause");

}