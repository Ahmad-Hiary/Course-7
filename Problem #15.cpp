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

short CheckNumberCountInMatrix(short Matrix[3][3], short Rows, short Cols, short NumberToCheck)
{

    short Counter = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == NumberToCheck)
                Counter++;
        }
    }


    return Counter;
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


    short NumbertoCount = 0;
    cout << "Please neter a number to check how much counted in matrix : ";
    cin >> NumbertoCount;

    printf("\nNumber %d counted %d times in the matrix .\n\n", NumbertoCount, CheckNumberCountInMatrix(x, 3, 3, NumbertoCount));


}