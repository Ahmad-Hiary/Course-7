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


int main()
{

    string str = ReadString("Please enter the words to print first letter of each word\n\n");

    vector <string> vWords;

    vWords = SplitString(str, " ");
    
    for (string& Word : vWords)
    {
        cout << "\n \n" << Word;
    }


    cout << "\n\n";
    system("pause");

}