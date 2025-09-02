#include <iostream>
using namespace std;

int main() {
    int benchCount, seatCount;
    cout << "Enter total benches (rows): ";
    cin >> benchCount;
    cout << "Enter seats per bench (columns): ";
    cin >> seatCount;

    int** arrangement = new int*[benchCount];
    for (int r = 0; r < benchCount; r++) {
        arrangement[r] = new int[seatCount];
        for (int s = 0; s < seatCount; s++) {
            arrangement[r][s] = 0;
        }
    }

    char more = 'y';
    while (more == 'y' || more == 'Y') {
        int rowIndex, colIndex;
        cout << "\nSelect row (0 - " << benchCount - 1 << "): ";
        cin >> rowIndex;
        cout << "Select column (0 - " << seatCount - 1 << "): ";
        cin >> colIndex;

        if (rowIndex >= 0 && rowIndex < benchCount &&
            colIndex >= 0 && colIndex < seatCount) {
            arrangement[rowIndex][colIndex] = 1;
        } else {
            cout << "⚠ Invalid seat location!" << endl;
        }

        cout << "Mark another seat? (y/n): ";
        cin >> more;
    }

    cout << "\nSeating Layout:\n";
    for (int r = 0; r < benchCount; r++) {
        for (int s = 0; s < seatCount; s++) {
            cout << arrangement[r][s] << " ";
        }
        cout << endl;
    }

    for (int r = 0; r < benchCount; r++) {
        delete[] arrangement[r];
    }
    delete[] arrangement;

    return 0;
}
