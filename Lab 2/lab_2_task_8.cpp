#include <iostream>
using namespace std;

int main() {
    int dCount, readings;
    cout << "Enter total days: ";
    cin >> dCount;
    cout << "Enter number of readings per day: ";
    cin >> readings;

    double** record = new double*[dCount];
    double* avgTemp = new double[dCount];

    for (int d = 0; d < dCount; d++) {
        record[d] = new double[readings];
        double total = 0;

        cout << "\nProvide temperature readings for Day " << d + 1 << ":\n";
        for (int r = 0; r < readings; r++) {
            cout << "Reading #" << r + 1 << ": ";
            cin >> record[d][r];
            total += record[d][r];
        }

        avgTemp[d] = total / readings;
    }

    cout << "\nAverage Temperature per Day:\n";
    for (int d = 0; d < dCount; d++) {
        cout << "Day " << d + 1 << ": " << avgTemp[d] << endl;
    }

    int maxDay = 0, minDay = 0;
    for (int d = 1; d < dCount; d++) {
        if (avgTemp[d] > avgTemp[maxDay]) maxDay = d;
        if (avgTemp[d] < avgTemp[minDay]) minDay = d;
    }

    cout << "\nHottest Day: " << maxDay + 1
         << " (Avg Temp = " << avgTemp[maxDay] << ")" << endl;
    cout << "Coldest Day: " << minDay + 1
         << " (Avg Temp = " << avgTemp[minDay] << ")" << endl;

    for (int d = 0; d < dCount; d++) {
        delete[] record[d];
    }
    delete[] record;
    delete[] avgTemp;

    return 0;
}
