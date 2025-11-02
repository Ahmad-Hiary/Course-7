#include <iostream>
#include <string>
#include <vector>

using namespace std;


string ReadString(string Messege)
{
    cout << Messege;
    string x;
    getline(cin, x);

    return x;
}

int ReadNumber(string Messege)
{
    cout << Messege;
    int x;
    cin >> x;

    return x;
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

struct strClientData
{
    string AccountNumber, Phone, Name, PinCode;
    int AccountBalance;
};

strClientData FillClientData()
{
    strClientData Data;


    Data.AccountNumber = ReadString("\nPlease enter Account number: ");


    Data.Name = ReadString("\nPlease enter Name: ");


    Data.PinCode = ReadString("\nPlease enter Pin code: ");


    Data.Phone = ReadString("\nPlease enter Phone: ");

    cout << "\nPlease enter Account balance : ";
    cin >> Data.AccountBalance;

    return Data;
}

strClientData FillStructWithRecordLine(string str, string Delim)
{
    vector <string> vSplitedString = SplitString(str, Delim);

    strClientData ClientData;

    
    vector <string>::iterator Iter = vSplitedString.begin();
    

    ClientData.AccountNumber = vSplitedString[0];
    ClientData.PinCode = vSplitedString[1];
    ClientData.Name = vSplitedString[2];
    ClientData.Phone = vSplitedString[3];
    ClientData.AccountBalance = stoi(vSplitedString[4]);


    return ClientData;


}

void PrintClientData(const strClientData& ClientData)
{
    cout << "Account Number: " << ClientData.AccountNumber << endl;
    cout << "Pin Code: " << ClientData.PinCode << endl;
    cout << "Name: " << ClientData.Name << endl;
    cout << "Phone: " << ClientData.Phone << endl;
    cout << "Account Balance: " << ClientData.AccountBalance << endl;
}

int main()
{
    string RecordLine = ""; 
    

    RecordLine = "A117#//#3333#//#Ahmad Faris Al-Hiary#//#0780930833#//#7000";

    strClientData ClientData = FillStructWithRecordLine(RecordLine, "#//#");

    cout << "\n\n     Client Data   \n";

    PrintClientData(ClientData);


    cout << "\n";
    system("pause>0");
}