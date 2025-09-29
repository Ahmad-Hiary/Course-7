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

void FillMatrixWhithRandomNumbers(short x[3][3],short Rows,short cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            x[i][j] = GetRandomNumber(1, 100);
        }
    }
}

void PrintMatrix(short x[3][3], short Rows, short cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(3) << x[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));

    short x[3][3];

    FillMatrixWhithRandomNumbers(x, 3, 3);

    cout << "This is a 3x3 matrix whith random numbers : \n";

    PrintMatrix(x, 3, 3);

}

