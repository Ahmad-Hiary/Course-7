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

void PrintMiddleRowInMatrix(short x[3][3], short row, short cols)
{
    short MiddleRowIndex = row / 2;

    for (short i = 0; i < row; i++)
    {
        printf(" %0*d   ", 2, x[i][MiddleRowIndex]);
    }
}

void PrintMiddleColInMatrix(short x[3][3], short row, short cols)
{
    short MiddleColIndex = cols / 2;

    for (short i = 0; i < row; i++)
    {
        printf(" %0*d   ", 2, x[MiddleColIndex][i]);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    short x[3][3];
    

    Fill3x3MatrixWhithRandomNumbers(x);

    cout << "This is a 3x3 matrix whith random numbers : \n\n";

    PrintMatrix(x);

    cout << "\n\nThe middle row in the matrix = ";

    PrintMiddleRowInMatrix(x, 3, 3);

    
    cout << "\n\nThe middle col in the matrix = ";

    PrintMiddleColInMatrix(x, 3, 3);

    cout << "\n\n\n";



}