#include <iostream>
using namespace std;

int main() {
    int months;
    cout << "How many months of expenses do you want to record? ";
    cin >> months;

    double* cost = new double[months];

    for (int m = 0; m < months; m++) {
        cout << "Enter expense for month #" << m + 1 << ": ";
        cin >> cost[m];
    }

    char more;
    cout << "Would you like to add extra months? (y/n): ";
    cin >> more;

    if (more == 'y' || more == 'Y') {
        int addMonths;
        cout << "How many more months to include? ";
        cin >> addMonths;

        double* updated = new double[months + addMonths];

        for (int i = 0; i < months; i++) {
            updated[i] = cost[i];
        }

        for (int i = months; i < months + addMonths; i++) {
            cout << "Enter expense for month #" << i + 1 << ": ";
            cin >> updated[i];
        }

        delete[] cost;
        cost = updated;
        months += addMonths;
    }

    double sum = 0;
    for (int i = 0; i < months; i++) {
        sum += cost[i];
    }
    double average = sum / months;

    cout << "\nOverall Expenses = " << sum << endl;
    cout << "Average per Month = " << average << endl;

    delete[] cost;
    return 0;
}
