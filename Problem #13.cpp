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

    void FillIdentityMatrix(short Matrix[3][3],short Rows, short Cols)
    {

        short HereIdentity = Cols / 2;

        for (short i = 0; i < 3; i++)
        {
            for (short j = 0; j < 3; j++)
            {
                if (i == j)
                {
                    Matrix[i][j] = 1;

                }
                else
                {
                    Matrix[i][j] = 0;
                }
            }
        }                                                               
            
    }

    bool IsIdentityMatrix(short Matrix[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (i == j && Matrix[i][j] != 1)
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

        short x[3][3];

        FillIdentityMatrix(x,3,3);

        cout << "This is a 3x3 identity matrix : \n\n";


        
        PrintMatrix(x);

        

        if (IsIdentityMatrix(x, 3, 3))
        {
            cout << "\n\n\nIt is identity\n\n";
        }
        else
        {
            cout << "\n\n\nIt is not identity\n\n";
        }
        

    }