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

bool CheckIsMatrixPalindrome(short Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] != Matrix[i][Cols-1-j])
                return 0;
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


    short Matrix1[3][3] =
    {
        { 1,  5, 1 },
        { 1, 6,  1 },
        {  5,  0,  4 }
    };




    cout << "This is  3x3 matrix : \n\n";

    PrintMatrix(Matrix1);
    cout << "\n\n";


    if (CheckIsMatrixPalindrome(Matrix1, 3, 3))
        cout << "\nYes Palindrome .\n\n";
    else
        cout << "\nNo not Palindrome .\n\n";


}