#include <iostream>
using namespace std;

int main() {
    int deptCount;
    cout << "How many departments? ";
    cin >> deptCount;

    int** pay = new int*[deptCount];
    int* empCount = new int[deptCount];
    double* averages = new double[deptCount];

    for (int d = 0; d < deptCount; d++) {
        cout << "\nEnter number of staff in Department " << d + 1 << ": ";
        cin >> empCount[d];
        pay[d] = new int[empCount[d]];

        int total = 0;
        int maxSalary = 0;

        for (int e = 0; e < empCount[d]; e++) {
            cout << "Salary of employee " << e + 1 << ": ";
            cin >> pay[d][e];
            total += pay[d][e];
            if (pay[d][e] > maxSalary) {
                maxSalary = pay[d][e];
            }
        }

        averages[d] = static_cast<double>(total) / empCount[d];
        cout << "Top salary in Department " << d + 1 << ": " << maxSalary << endl;
    }

    int topDept = 0;
    for (int d = 1; d < deptCount; d++) {
        if (averages[d] > averages[topDept]) {
            topDept = d;
        }
    }

    cout << "\nDepartment with the best average salary: Dept-" 
         << topDept + 1 << " (Average = " << averages[topDept] << ")" << endl;

    for (int d = 0; d < deptCount; d++) {
        delete[] pay[d];
    }
    delete[] pay;
    delete[] empCount;
    delete[] averages;

    return 0;
}
