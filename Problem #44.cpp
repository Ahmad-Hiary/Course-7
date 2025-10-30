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

string RemovePunctuationsFromString(string S1)
{
    string S2 = ""; 

    
    for (short i = 0; i < S1.length(); i++) {
        
        if (!ispunct(S1[i])) {
            S2 += S1[i];
        }
    }

    return S2; 
}

int main()
{
    string Name = ReadString("Please enter full name ? \n");

    Name = RemovePunctuationsFromString(Name);

    cout << "\n\nName after remove punctuastions is : " << Name << "\n\n";

}

