#include <iostream>
using namespace std;

#include <ctime>

void copyArray(int src[], int dest[], int n)
{
    for (int i = 0; i < n; ++i)
        dest[i] = src[i];
}

void bubbleSort(int arr[], int n, int &comp, int &swaps)
{
    comp = swaps = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            comp++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
}

void insertionSort(int arr[], int n, int &comp, int &swaps)
{
    comp = swaps = 0;
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            comp++;
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

void shellSort(int arr[], int n, int &comp, int &swaps)
{
    comp = swaps = 0;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; ++i)
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap)
            {
                comp++;
                if (arr[j - gap] > temp)
                {
                    arr[j] = arr[j - gap];
                    swaps++;
                    j -= gap;
                }
                else
                {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements (e.g., 1000): ";
    cin >> n;
    int arr[2000], arr1[2000], arr2[2000], arr3[2000];
    if (n > 2000)
    {
        cout << "Maximum allowed size is 2000." << endl;
        return 1;
    }
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    copyArray(arr, arr1, n);
    copyArray(arr, arr2, n);
    copyArray(arr, arr3, n);

    int compB, swapsB, compI, swapsI, compS, swapsS;
    clock_t t1, t2;

    t1 = clock();
    bubbleSort(arr1, n, compB, swapsB);
    t2 = clock();
    double timeB = (double)(t2 - t1) / CLOCKS_PER_SEC;

    t1 = clock();
    insertionSort(arr2, n, compI, swapsI);
    t2 = clock();
    double timeI = (double)(t2 - t1) / CLOCKS_PER_SEC;

    t1 = clock();
    shellSort(arr3, n, compS, swapsS);
    t2 = clock();
    double timeS = (double)(t2 - t1) / CLOCKS_PER_SEC;

    cout << "\nResults for " << n << " elements:\n";
    cout << "Bubble Sort:    Time = " << timeB << "s, Comparisons = " << compB << ", Swaps = " << swapsB << endl;
    cout << "Insertion Sort: Time = " << timeI << "s, Comparisons = " << compI << ", Swaps = " << swapsI << endl;
    cout << "Shell Sort:     Time = " << timeS << "s, Comparisons = " << compS << ", Swaps = " << swapsS << endl;
    return 0;
}
