#include <iostream>
using namespace std;

class SmartInt {
    int* data;
public:
    SmartInt() {
        data = new int(0);
    }
    ~SmartInt() {
        delete data;
    }

    void assign(int value) {
        *data = value;
    }

    int fetch() const {
        return *data;
    }

    void clear() {
        delete data;
        data = nullptr;
    }
};

int main() {
    const int size = 5;
    SmartInt scores[size];

    cout << "Enter scores for " << size << " learners:\n";
    for (int i = 0; i < size; i++) {
        int temp;
        cout << "Learner " << i + 1 << ": ";
        cin >> temp;
        scores[i].assign(temp);
    }

    cout << "\nRecorded Scores:\n";
    for (int i = 0; i < size; i++) {
        cout << "Learner " << i + 1 << ": " << scores[i].fetch() << endl;
    }

    for (int i = 0; i < size; i++) {
        scores[i].clear();
    }

    return 0;
}
