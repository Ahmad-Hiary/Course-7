#include<iostream>
#include<string>
#include<iomanip>
#include"MyMathLib.h"

using namespace std;
using namespace MyMathLib;

int GetRandomNumber(int from, int to)
{
    // Function to generate a random number between from and to
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

short CheckIsMatrixSparse(short Matrix[3][3], short Rows, short Cols)
{

    short HalfOfMatrix = (Rows * Cols) / 2;

    return (GetNumberCountInMatrix(Matrix, 3, 3, 0) > HalfOfMatrix);
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


    
    cout << "Lets check if the matrix is sparse  : \n\nAfter some calculations this is the result : ";
   

    if (CheckIsMatrixSparse(x, 3, 3))
        cout << "Yes it is a sparse !!\n";
    else 
        cout << "No it is not a sparse !!\n";


}