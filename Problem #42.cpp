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


string ReplaceWordInString(string str, string Word, string NewWord)
{
    short Pos = 0;

    while ((Pos = str.find(Word)) != std::string::npos)
    {
        str.replace(Pos, Word.length(), NewWord);
    }

    return str;
}

int main()
{
    string Name = ReadString("Please enter the string\n");
    string WordToReplace = ReadString("Please enter the word you want to replace? \n");
    string NewWord = ReadString("Please enter the new word ? \n");

    Name = ReplaceWordInString(Name, WordToReplace, NewWord);

    cout << "The string after replace the word : \n" << Name;

}

