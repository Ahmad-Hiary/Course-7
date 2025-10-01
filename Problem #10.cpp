#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>

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
            x[i][j] = GetRandomNumber(1, 10);
        }
    }
}

void PrintMatrix(short x[3][3])
{
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            printf(" %0*d    ", 2, x[i][j]);
        }

        cout << "\n";
    }
}

short GetMatrixElementsSum(short Matrix[3][3],short Rows,short Cols)
{
    short Sum = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Sum += Matrix[i][j];
        }
    }

    return Sum;

}

int main()
{
    srand((unsigned)time(NULL));

    short x[3][3];


    Fill3x3MatrixWhithRandomNumbers(x);

    cout << "This is a 3x3 matrix whith random numbers : \n\n";

    PrintMatrix(x);

    short MatrixSum = GetMatrixElementsSum(x, 3, 3);

    printf("Thw sum of all matrix elements are : %d\n\n", MatrixSum);




}