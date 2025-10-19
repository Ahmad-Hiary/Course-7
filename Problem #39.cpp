#include <iostream>
#include <vector>
#include <string>

using namespace std;

void JoinString(vector <string> vWords, string &str,string Separator)
{                   
    for (string& Word : vWords)
    {
        str += Word + Separator;
    }

    // this is another way   :     str=str.substr(0, str.length()-Separator.length());
    str.erase(str.length() - Separator.length(), Separator.length());
}

int main()
{
    vector <string> vNames;
    string EmployeesNames;

    vNames.push_back("Ahmad");
    vNames.push_back("Mohammad");
    vNames.push_back("Ali");
    vNames.push_back("Khaled");

    JoinString(vNames, EmployeesNames, "&&");

    cout << "The employees are : " << EmployeesNames << endl;

}

