#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientDataFile = "Client Data.txt";

struct strClientData
{
    string AccountNumber, Phone, Name, PinCode;
    int AccountBalance;
};

string ReadString(string Messege)
{
    cout << Messege;
    string x;
    getline(cin, x);

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

strClientData FillStructWithRecordLine(string str, string Delim)
{
    vector <string> vSplitedString = SplitString(str, Delim);

    strClientData ClientData;

    ClientData.AccountNumber = vSplitedString[0];
    ClientData.PinCode = vSplitedString[1];
    ClientData.Name = vSplitedString[2];
    ClientData.Phone = vSplitedString[3];
    ClientData.AccountBalance = stoi(vSplitedString[4]);

    return ClientData;
}

vector <string> LoadFileDataToVector(string FileName)
{
    fstream File;
    vector <string> vFileData;

    File.open(FileName, ios::in);

    string Line;

    if (File.is_open())
    {
        while (getline(File, Line))
        {
            vFileData.push_back(Line);
        }
        File.close();
    }

    return vFileData;
}

void PrintHeader()
{
    cout << "\n\t\tClients Data\n";
    cout << "--------------------------------------------------------------------------------------\n\n";
    cout << "| " << left << setw(20) << "Account Number";
    cout << "| " << left << setw(15) << "Pin Code";
    cout << "| " << left << setw(20) << "Name";
    cout << "| " << left << setw(10) << "Account Balance";
    cout << "\n\n---------------------------------------------------------------------------------------\n";
}

void ShowClientData(string RecordLine, string Delim)
{
    strClientData Client;
    Client = FillStructWithRecordLine(RecordLine, Delim);

    cout << "| " << left << setw(20) << Client.AccountNumber;
    cout << "| " << left << setw(15) << Client.PinCode;
    cout << "| " << left << setw(20) << Client.Name;
    cout << "| " << left << setw(10) << Client.AccountBalance;
}

void ShowClientsData()
{
    vector <string> vData;

    vData = LoadFileDataToVector(ClientDataFile);

    PrintHeader();

    for (string& Line : vData)
    {
        ShowClientData(Line, "#//#");
        cout << "\n";
    }
}

int main()
{
    ShowClientsData();
}
