#include <iostream>
#include <string>
using namespace std;

class TestRecord {
private:
    string* namePtr;
    string* datePtr;
    int marks;

public:
    TestRecord(string nm, string dt, int m) {
        namePtr = new string(nm);
        datePtr = new string(dt);
        marks = m;
    }

    ~TestRecord() {
        delete namePtr;
        delete datePtr;
    }

    void updateName(const string& nm) {
        *namePtr = nm;
    }

    void updateDate(const string& dt) {
        *datePtr = dt;
    }

    void updateMarks(int m) {
        marks = m;
    }

    void show() const {
        cout << "Candidate: " << *namePtr
             << "\nDate: " << *datePtr
             << "\nMarks: " << marks << endl;
    }
};

int main() {
    TestRecord t1("Alice", "2025-08-25", 90);
    cout << "Record 1:\n";
    t1.show();

    TestRecord t2 = t1;
    cout << "\nRecord 2 (copied from Record 1):\n";
    t2.show();

    t2.updateName("Bob");
    t2.updateDate("2025-09-01");
    t2.updateMarks(75);

    cout << "\nRecord 2 (after updates):\n";
    t2.show();

    cout << "\nRecord 1 (after Record 2 changes):\n";
    t1.show();

    return 0;
}
