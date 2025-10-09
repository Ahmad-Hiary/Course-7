#include <iostream>
#include <iomanip>

using namespace std;

void PrintFibonacciSeries(int Number)
{
    int Prev1 = 1, Prev2 = 1, Sum = 0, Counter = 0;

    cout << setw(4) << Prev1 << setw(4) << Prev2;
    for (int i = 0; i < Number-2; i++)
    {
        Sum = Prev1 + Prev2;
        cout << setw(4) << Sum;
        Prev1 = Prev2;
        Prev2 = Sum;

    }
}

int main()
{
    cout << "Please enter a number to print fabinacci series . \n";
    int Number = 0;
    cin >> Number;

    cout << "The Fabinacce sereis of number " << Number << " is : ";
    PrintFibonacciSeries(Number);
}

