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

void PrintFirstLetterOfEachWord(string Str)
{
    bool IsFirstLetter = true;

    for (short i = 0; i < Str.length(); i++)
    {
        if (Str[i] != ' ' && IsFirstLetter)
        {
            cout << Str[i] << "\n";
        }

        IsFirstLetter = (Str[i] == ' ') ? true : false;
    }

}                   



int main()
{
    vector <char> vLetterOfWords;

    string Words = ReadString("Please enter the words to print first letter of each word");

    PrintFirstLetterOfEachWord(Words);

    system("pause");


}

