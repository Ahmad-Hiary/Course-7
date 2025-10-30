#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

string ReadString(string Messege)
{
    cout << Messege;
    string x;
    getline(cin, x);

    return x;
}

void JoinString(vector <string> vWords, string& str, string Separator)
{
    for (string& Word : vWords)
    {
        str += Word + Separator;
    }

    // this is another way   :     str=str.substr(0, str.length()-Separator.length());
    str.erase(str.length() - Separator.length(), Separator.length());
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

string LowerAllStirng(string Str)
{


    for (short i = 0; i < Str.length(); i++)
    {
        Str[i] = tolower(Str[i]);
    }

    return Str;

}

string ReplaceWordInString(string str, string Word, string NewWord, bool MatchCase = true)
{
    vector <string> vSplitedString;

    vSplitedString = SplitString(str, " ");

    for (string& Temp : vSplitedString)
    {
        if (MatchCase)
        {
            if (Temp == Word)
                Temp = NewWord;
        }
        else
        {
            if (LowerAllStirng(Temp) == LowerAllStirng(Word))
                Temp = NewWord;
        }
    }
    

    str = " ";
    JoinString(vSplitedString, str, " ");
    return str;
}

int main()
{
    string Name = ReadString("Please enter the string\n");
    string WordToReplace = ReadString("Please enter the word you want to replace? \n");
    string NewWord = ReadString("Please enter the new word ? \n");

    Name = ReplaceWordInString(Name, WordToReplace, NewWord,false);

    cout << "The string after replace the word : \n" << Name;

}

