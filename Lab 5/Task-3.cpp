#include <iostream>
using namespace std;

int sumTail(int n, int total)
{
    if (n == 0)
        return total;
    return sumTail(n - 1, total + n);
}

int sumNonTail(int n)
{
    if (n == 0)
        return 0;
    return n + sumNonTail(n - 1);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Sum using tail recursion: " << sumTail(num, 0) << endl;
    cout << "Sum using non-tail recursion: " << sumNonTail(num) << endl;

    cout << "\nDifference in call stacks:\n";
    cout << "Tail recursion passes the accumulated sum, so each call can return immediately.\n";
    cout << "Non-tail recursion waits for all recursive calls to finish before adding, so stack grows deeper.\n";

    return 0;
}