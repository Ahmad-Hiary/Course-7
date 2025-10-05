#include<iostream>
#include<string>
#include<iomanip>


using namespace std;

int GetRandomNumber(int from, int to)
{
    // Function to generate a random number between from and to
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

short CheckIsNumberInMatrix(short Matrix[3][3], short Rows, short Cols, short NumberToFind)
{

    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            if (Matrix[i][j] == NumberToFind)
                return 1;
        }
        
    }
    return 0;
}

void PrintMatrix(short x[3][3])
{
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            cout << setw(3) << x[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));


    short x[3][3] = { { 0,0,0 }, { 0,9,0 }, { 0,9,9 } };


    cout << "This is a 3x3 Scalar matrix : \n\n";

    PrintMatrix(x);



    cout << "Please enter number to check is it in matrix?\n";
    short NumberToFind = 0;
    cin >> NumberToFind;


    if (CheckIsNumberInMatrix(x, 3, 3,NumberToFind))
        cout << "Yes it is There !!\n";
    else
        cout << "No it is not There !!\n";


}