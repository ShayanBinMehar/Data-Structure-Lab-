#include <iostream>
using namespace std;

void printNumbers(int n)
{
    if (n < 1)
        return;
    cout << n << " ";
    printNumbers(n - 1);
}

void functionB(int n);

void functionA(int n)
{
    if (n < 1)
        return;
    cout << "A: " << n << " ";
    functionB(n - 1);
}

void functionB(int n)
{
    if (n < 1)
        return;
    cout << "B: " << n << " ";
    functionA(n - 1);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Direct recursion output: ";
    printNumbers(num);
    cout << endl;

    cout << "Indirect recursion output: ";
    functionA(num);
    cout << endl;

    return 0;
}