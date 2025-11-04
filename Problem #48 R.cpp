#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientDataFile = "Client Data.txt";

struct strClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
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

strClientData FillStructWithRecordLine(string str, string Delim = "#//#")
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

vector <strClientData> LoadClientDataFromFile(string FileName)
{
    fstream File;
    vector <strClientData> vClients;

    File.open(FileName, ios::in);

    string Line;

    if (File.is_open())
    {
        strClientData Client;

        while (getline(File, Line))
        {
            Client = FillStructWithRecordLine(Line);

            vClients.push_back(Client);
        }
        File.close();
    }

    return vClients;
}

void PrintClientRecord(strClientData Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(40) << Client.Name;
    cout << "| " << left << setw(12) << Client.Phone;
    cout << "| " << left << setw(12) << Client.AccountBalance;
}

void PrintAllClientsData(vector <strClientData> vClients)
{
    cout << "\n\t\t\t\t\tClients List  (" << vClients.size() << ") Client(s) \n";
    cout << "----------------------------------------------------------------------------------------------------\n\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n\n----------------------------------------------------------------------------------------------------\n";

    for (strClientData& Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }

    cout << "\n----------------------------------------------------------------------------------------------------\n";

}

int main()
{
    vector <strClientData> vClientsData = LoadClientDataFromFile(ClientDataFile);

    PrintAllClientsData(vClientsData);

    cout << "\n";
    system("pause>0");
}
