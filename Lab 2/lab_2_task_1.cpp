#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int *data = new int[n];
    
    for (int i = 0; i < n; i++) {
        data[i] = 0;
    }

    char again = 'y';
    while (again == 'y' || again == 'Y') {
        int pos, val;
        cout << "\nChoose index (0 - " << n - 1 << "): ";
        cin >> pos;

        if (pos >= 0 && pos < n) {
            cout << "Enter number to store: ";
            cin >> val;
            data[pos] = val;
        } else {
            cout << "⚠ Index out of range!" << endl;
        }

        cout << "Update another element? (y/n): ";
        cin >> again;
    }

    cout << "\nArray content: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    delete[] data;
    return 0;
}
