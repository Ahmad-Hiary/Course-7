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

short GetMaxNumberInMatrix(short Matrix[3][3] , short Rows, short Cols)
{
    short MaxNumber = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] > MaxNumber)
                MaxNumber = Matrix[i][j];
        }
    }

    return MaxNumber;
}

short GetMinimumNumberInMatrix(short Matrix[3][3], short Rows, short Cols)
{
    short MinimumNumber = 100;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] < MinimumNumber)
                MinimumNumber = Matrix[i][j];
        }
    }

    return MinimumNumber;
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




    cout << "Those are  3x3 matrix : \n\n";

    PrintMatrix(Matrix1);
    cout << "\n\n";
   

    printf("The Maximum Number in matrix is : %d\n\n", GetMaxNumberInMatrix(Matrix1, 3, 3));
    printf("The Minimum Number in matrix is : %d\n\n", GetMinimumNumberInMatrix(Matrix1, 3, 3));


}