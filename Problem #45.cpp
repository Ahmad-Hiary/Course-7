#include <iostream>
#include <string>

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

string ConvertClientRecordToLine(strClientData ClientData , string Delim)
{
    string RecordLine ;
    RecordLine += ClientData.AccountNumber + Delim;
    RecordLine += ClientData.PinCode + Delim;
    RecordLine += ClientData.Name + Delim;
    RecordLine += ClientData.Phone + Delim;
    RecordLine += to_string(ClientData.AccountBalance);
   

    return RecordLine;
    
}
        

int main()
{
    string RecordLine = "";

    strClientData ClientData = FillClientData();

    RecordLine = ConvertClientRecordToLine(ClientData,"#//#");

    cout << "\n\nClient Record is :\n" << RecordLine;


    cout << "\n";
    system("pause>0");
}

