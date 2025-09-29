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

void Fill3x3MatrixWhithRandomNumbers(short x[3][3])
{
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            x[i][j] = GetRandomNumber(1, 100);
        }
    }
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

short RowSum(short x[3][3],short row ,short cols)
{
    short sum = 0;

    for (short i = 0; i < cols; i++)
    {
        sum += x[row][i];
    }

    return sum;

}

void PrintSumOfRowsInMatrix(short x[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "The sum of row " << i + 1 << " = " << RowSum(x, i, 3) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    short x[3][3];

    Fill3x3MatrixWhithRandomNumbers(x);

    cout << "This is a 3x3 matrix whith random numbers : \n\n";

    PrintMatrix(x);

    PrintSumOfRowsInMatrix(x);

}