#include <iostream>
using namespace std;

int main() {
    int totalStudents;
    cout << "How many students? ";
    cin >> totalStudents;

    int** scoreList = new int*[totalStudents];
    int* subjectCount = new int[totalStudents];
    double* average = new double[totalStudents];

    for (int s = 0; s < totalStudents; s++) {
        cout << "\nEnter courses taken by Student " << s + 1 << ": ";
        cin >> subjectCount[s];
        scoreList[s] = new int[subjectCount[s]];

        int total = 0;
        for (int sub = 0; sub < subjectCount[s]; sub++) {
            cout << "Marks in course " << sub + 1 << ": ";
            cin >> scoreList[s][sub];
            total += scoreList[s][sub];
        }
        average[s] = static_cast<double>(total) / subjectCount[s];
    }

    cout << "\n--- Students' Average Marks ---\n";
    for (int s = 0; s < totalStudents; s++) {
        cout << "Student " << s + 1 << " -> " << average[s] << endl;
    }

    for (int s = 0; s < totalStudents; s++) {
        delete[] scoreList[s];
    }
    delete[] scoreList;
    delete[] subjectCount;
    delete[] average;

    return 0;
}
