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

void PrintIntersectedNumbersInMatrix(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Cols)
{
    short Number = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Number = Matrix1[i][j];

            if (CheckIsNumberInMatrix(Matrix2, 3, 3, Number))
                cout << setw(3) << Number << "   ";
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

int main()
{
    srand((unsigned)time(NULL));


    short Matrix1[3][3] = 
    {
        { 77,  5, 12 },
        { 22, 20,  1 },
        {  1,  0,  9 }
    };

    short Matrix2[3][3] =
    {
        {  5, 80, 90 },
        { 22, 77,  1 },
        { 10,  8, 33 }
    };



    cout << "Those are  3x3 matrix : \n\n";

    PrintMatrix(Matrix1);
    cout << "\n\n";
    PrintMatrix(Matrix2);



    cout << "\n\nThe intersected Numbers are : ";
    PrintIntersectedNumbersInMatrix(Matrix1, Matrix2, 3, 3);
    cout << "\n\n";


}