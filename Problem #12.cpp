#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib> 
#include<ctime>   
#include<cstdio>

using namespace std;

int GetRandomNumber(int from, int to)
{

    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

void Fill3x3MatrixWithRandomNumbers(short x[3][3])
{
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            x[i][j] = GetRandomNumber(1, 10);
        }
    }
}

void PrintMatrix(short arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            printf("%0*d   ", 2, arr[i][j]);
        }
        cout << "\n";
    }
}

bool IsTwoMatrixTypical(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] != Matrix2[i][j])
            {
                return 0;
            }
        }
       
    }

    return 1;
}

int main()
{
    srand((unsigned)time(NULL));

    short Matrix1[3][3];
    short Matrix2[3][3];
    

    Fill3x3MatrixWithRandomNumbers(Matrix1);
    Fill3x3MatrixWithRandomNumbers(Matrix2);

    cout << "This is the first matrix : \n\n";

    PrintMatrix(Matrix1, 3, 3);

    cout << "This is the Second matrix : \n\n";

    PrintMatrix(Matrix2, 3, 3);


    if (IsTwoMatrixTypical(Matrix1, Matrix2, 3, 3))
        cout << "Those two matrices are equal .\n\n";
    else 
        cout << "Those two matrices are not equal .\n\n";




    

}
