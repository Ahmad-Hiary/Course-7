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



bool IsIdScalarMatrix(short Matrix[3][3], short Rows, short Cols)
{

    short FirstDiagonalElement = Matrix[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix[i][j] != FirstDiagonalElement)
            {
                return 0;
            }
            else if (i != j && Matrix[i][j] != 0)
            {
                return 0;
            }
        }
    }

    return 1;
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

  
    short x[3][3] = { { 9,0,0 }, { 0,9,0 }, { 0,0,9 } };
   

    

    cout << "This is a 3x3 Scalar matrix : \n\n";



    PrintMatrix(x);



    if (IsIdScalarMatrix(x, 3, 3))
    {
        cout << "\n\n\nIt is scalar\n\n";
    }
    else
    {
        cout << "\n\n\nIt is not scalar\n\n";
    }


}