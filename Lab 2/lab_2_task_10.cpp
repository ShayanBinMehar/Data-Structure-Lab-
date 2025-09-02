#include <iostream>
using namespace std;

int main() {
    int genreCount;
    cout << "Enter total number of categories: ";
    cin >> genreCount;

    int* bookCount = new int[genreCount];
    int** shelf = new int*[genreCount];

    for (int g = 0; g < genreCount; g++) {
        cout << "\nHow many books in category " << g + 1 << "? ";
        cin >> bookCount[g];

        shelf[g] = new int[bookCount[g]];
        cout << "Enter book IDs for category " << g + 1 << ":\n";

        for (int b = 0; b < bookCount[g]; b++) {
            cin >> shelf[g][b];
        }
    }

    int targetID;
    cout << "\nEnter a Book ID to search: ";
    cin >> targetID;

    bool available = false;
    int locatedCategory = -1;

    for (int g = 0; g < genreCount; g++) {
        for (int b = 0; b < bookCount[g]; b++) {
            if (shelf[g][b] == targetID) {
                available = true;
                locatedCategory = g;
                break;
            }
        }
        if (available) break;
    }

    if (available) {
        cout << "Book ID " << targetID 
             << " found in Category " << locatedCategory + 1 << endl;
    } else {
        cout << "Book ID " << targetID 
             << " is not available in the library.\n";
    }

    for (int g = 0; g < genreCount; g++) {
        delete[] shelf[g];
    }
    delete[] shelf;
    delete[] bookCount;

    return 0;
}
