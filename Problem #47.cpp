#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


const string ClientsFile = "Client Data.txt";

string ReadString(string Messege)
{
    cout << Messege;
    string x;
    getline(cin, x);

    return x;
}

struct strClientData
{
    string AccountNumber, Phone, Name, PinCode;
    int AccountBalance;
};

strClientData FillClientData()
{
    strClientData Data;


    cout << "\nPlease enter Account number: ";
    getline(cin >> ws, Data.AccountNumber);

    Data.PinCode = ReadString("\nPlease enter Pin code: "); 

    Data.Name = ReadString("\nPlease enter Name: ");

    Data.Phone = ReadString("\nPlease enter Phone: ");

    cout << "\nPlease enter Account balance : ";
    cin >> Data.AccountBalance;

    return Data;
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

void AddClientToFile(string FileName ,const string DataLine)
{
    fstream File;

    File.open(FileName, ios::out | ios::app);

    if (File.is_open())
    {
        File << DataLine << endl;

        File.close();
    }
}

void AddClient()
{
    strClientData Client;

    Client = FillClientData();
    AddClientToFile(ClientsFile, ConvertClientRecordToLine(Client, "#//#"));
}

void AddClients()
{
    
    char Add = 'y';
    while (toupper(Add) == 'Y')
    {
        system("cls");

        cout << "Adding new client :\n\n";

        AddClient();

        cout << "\nClient added succisfully, Do you want add a new client Y/N : ";
        cin >> Add;
        
    }

}


int main()
{
    AddClients();

    cout << "\n";
    system("pause>0");
}
