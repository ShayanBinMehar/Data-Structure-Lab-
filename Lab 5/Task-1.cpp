#include <iostream>
using namespace std;

int calculateFactorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * calculateFactorial(n - 1);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (num < 0)
    {
        cout << "Factorial is not defined for negative numbers." << endl;
    }
    else
    {
        cout << "Factorial of " << num << " is " << calculateFactorial(num) << endl;
    }
    return 0;
}