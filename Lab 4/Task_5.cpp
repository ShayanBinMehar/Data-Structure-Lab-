#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high && target >= arr[low] && target <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == target)
                return low;
            return -1;
        }
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);
        if (arr[pos] == target)
            return pos;
        if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main()
{
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[100];
    if (n > 100)
    {
        cout << "Maximum allowed size is 100." << endl;
        return 1;
    }
    cout << "Enter the sorted elements (uniformly distributed): ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << "Enter the value to search: ";
    cin >> target;
    int index = interpolationSearch(arr, n, target);
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found in the array." << endl;
    return 0;
}
