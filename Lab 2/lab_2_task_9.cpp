#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Enter total rows: ";
    cin >> r;
    cout << "Enter total columns: ";
    cin >> c;

    int** mat = new int*[r];
    for (int i = 0; i < r; i++) {
        mat[i] = new int[c];
    }

    cout << "\nFill the matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    int count = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) count++;
        }
    }

    int** sparse = new int*[count];
    for (int i = 0; i < count; i++) {
        sparse[i] = new int[3];
    }

    int idx = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                sparse[idx][0] = i;
                sparse[idx][1] = j;
                sparse[idx][2] = mat[i][j];
                idx++;
            }
        }
    }

    cout << "\nSparse Matrix Representation (row col value):\n";
    for (int i = 0; i < count; i++) {
        cout << sparse[i][0] << " "
             << sparse[i][1] << " "
             << sparse[i][2] << endl;
    }

    for (int i = 0; i < r; i++) {
        delete[] mat[i];
    }
    delete[] mat;

    for (int i = 0; i < count; i++) {
        delete[] sparse[i];
    }
    delete[] sparse;

    return 0;
}
