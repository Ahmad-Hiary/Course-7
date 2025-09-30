#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

void Fill3x3MatrixInOrderdNumbers(short x[3][3])
{
    short Count = 1;
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            x[i][j] = Count;
            Count++;
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

void TransporeMatrix(short x[3][3],short Transposed[3][3])
{
    short Count = 1;
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            Transposed[i][j] = x[j][i];
            Count++;
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    short x[3][3];
    short Transposed[3][3];

    Fill3x3MatrixInOrderdNumbers(x);

    cout << "This is a 3x3 matrix Before transpore : \n\n";

    PrintMatrix(x);



    cout << "This is a 3x3 matrix After transpore : \n\n";

    TransporeMatrix(x, Transposed);

    PrintMatrix(Transposed);

}

void TransporeMatrix(short x[3][3]);