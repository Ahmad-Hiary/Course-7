#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientDataFile = "Clients Data.txt";

struct strClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;

    bool ClientMark = false;
    char up = 'u';
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

string ConvertClientRecordToLine(strClientData ClientData, string Delim)
{
    string RecordLine;
    RecordLine += ClientData.AccountNumber + Delim;
    RecordLine += ClientData.PinCode + Delim;
    RecordLine += ClientData.Name + Delim;
    RecordLine += ClientData.Phone + Delim;
    RecordLine += to_string(ClientData.AccountBalance);


    return RecordLine;

}

strClientData FillStructWithRecordLine(string str, string Delim = "#//#")
{
    vector <string> vSplitedString = SplitString(str, Delim);

    strClientData ClientData;

    ClientData.AccountNumber = vSplitedString[0];
    ClientData.PinCode = vSplitedString[1];
    ClientData.Name = vSplitedString[2];
    ClientData.Phone = vSplitedString[3];
    ClientData.AccountBalance = stod(vSplitedString[4]);

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

bool FindClientByAccountNumber(string AccountNumber, vector <strClientData> vClients, strClientData& Client)
{


    for (strClientData& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;

            return true;
        }
    }

    return false;
}

void MarkClient(string AccountNumber, vector <strClientData>& vClients)
{
    for (strClientData& c : vClients)
    {
        if (c.AccountNumber == AccountNumber)
        {
            c.ClientMark = true;
            c.up = 'y';
        }
    }
}

void SaveClientToFile(string FileName, vector <strClientData> vClients)
{
    fstream File;

    File.open(FileName, ios::out);

    if (File.is_open())
    {
        string Line = "";

        for (strClientData& c : vClients)
        {
            if (c.ClientMark == false)
            {
                Line = ConvertClientRecordToLine(c, "#//#");

                File << Line << endl;
            }
            else if (c.up == 'y')
            {
                cout << "\nPlease enter Pin Code : ";
                getline(cin >> ws, c.PinCode);                              
                c.Name = ReadString("\nPlease enter Name : ");
                c.Phone = ReadString("\nPlease enter Phone : ");
                c.AccountBalance = stod(ReadString("\nPlease enter Account Balance : "));

                Line = ConvertClientRecordToLine(c, "#//#");

                File << Line << endl;
            }
        }

        File.close();
    }
}

void PrintClientCard(strClientData Client)
{
    cout << "\nClient Card\n";
    cout << "-----------------------\n";
    cout << "Account Number : " << Client.AccountNumber << endl;
    cout << "Pin Code       : " << Client.PinCode << endl;
    cout << "Client Name    : " << Client.Name << endl;
    cout << "Phone          : " << Client.Phone << endl;
    cout << "Balance        : " << Client.AccountBalance << endl;
    cout << "-----------------------\n";
    cout << endl;

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


void UpdateClient(string AccountNumber , vector <strClientData> vClients)
{
    strClientData Client;
    char Answer = 'y';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);

        cout << "\n Are you sure you want to update this client informations ?? ";
        cin >> Answer;      

        if (Answer == 'y' || Answer == 'Y')
        {
            

            MarkClient(AccountNumber, vClients);
            SaveClientToFile(ClientDataFile, vClients);

            vClients = LoadClientDataFromFile(ClientDataFile);

            cout << "\nCLient updated succfully .";
        }
    }
    else
    {
        cout << "\nClient not found !!";
    }

}

int main()
{
    vector <strClientData> vClientsData = LoadClientDataFromFile(ClientDataFile);


    PrintAllClientsData(vClientsData);
  

    string AccountNumber = ReadString("\n\nPlease enter Account Number to Update : ");

    UpdateClient(AccountNumber, vClientsData);

    cout << "\n";
    system("pause>0");
}