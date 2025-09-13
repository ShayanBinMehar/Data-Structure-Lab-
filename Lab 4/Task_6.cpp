#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void combSort(int arr[], int n, int &swapCount, int &compCount)
{
    int gap = n;
    bool swapped = true;
    const double shrink = 1.3;
    swapCount = 0;
    compCount = 0;
    while (gap > 1 || swapped)
    {
        gap = (int)(gap / shrink);
        if (gap < 1)
            gap = 1;
        swapped = false;
        for (int i = 0; i + gap < n; ++i)
        {
            compCount++;
            if (arr[i] > arr[i + gap])
            {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapCount++;
                swapped = true;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[100];
    if (n > 100)
    {
        cout << "Maximum allowed size is 100." << endl;
        return 1;
    }
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int swapCount = 0, compCount = 0;
    combSort(arr, n, swapCount, compCount);

    cout << "Sorted array: ";
    printArray(arr, n);
    cout << "Total comparisons: " << compCount << endl;
    cout << "Total swaps: " << swapCount << endl;
    return 0;
}
