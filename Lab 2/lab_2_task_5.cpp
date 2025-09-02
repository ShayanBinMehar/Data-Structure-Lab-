#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Enter total rows: ";
    cin >> r;
    cout << "Enter total columns: ";
    cin >> c;

    int** M1 = new int*[r];
    int** M2 = new int*[r];
    int** add = new int*[r];
    int** sub = new int*[r];

    for (int i = 0; i < r; i++) {
        M1[i] = new int[c];
        M2[i] = new int[c];
        add[i] = new int[c];
        sub[i] = new int[c];
    }

    cout << "\nFill Matrix 1:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> M1[i][j];
        }
    }

    cout << "\nFill Matrix 2:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> M2[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            add[i][j] = M1[i][j] + M2[i][j];
            sub[i][j] = M1[i][j] - M2[i][j];
        }
    }

    cout << "\nResult of M1 + M2:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << add[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nResult of M1 - M2:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << sub[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < r; i++) {
        delete[] M1[i];
        delete[] M2[i];
        delete[] add[i];
        delete[] sub[i];
    }
    delete[] M1;
    delete[] M2;
    delete[] add;
    delete[] sub;

    return 0;
}
