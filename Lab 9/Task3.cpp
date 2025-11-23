#include <iostream>
using namespace std;

struct Patient {
    string name;
    int severity;
    int arrival;
};

class MaxPriorityQueue {
private:
    Patient heap[200];
    int size;

    bool higherPriority(const Patient &a, const Patient &b) {
        if (a.severity > b.severity) return true;
        if (a.severity < b.severity) return false;

        return a.arrival < b.arrival;
    }

    void swapPatients(Patient &p1, Patient &p2) {
        Patient temp = p1;
        p1 = p2;
        p2 = temp;
    }
    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;

            if (higherPriority(heap[idx], heap[parent])) {
                swapPatients(heap[idx], heap[parent]);
                idx = parent;
            } else break;
        }
    }
    void heapifyDown(int idx) {
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = idx;

            if (left < size && higherPriority(heap[left], heap[largest]))
                largest = left;

            if (right < size && higherPriority(heap[right], heap[largest]))
                largest = right;

            if (largest != idx) {
                swapPatients(heap[idx], heap[largest]);
                idx = largest;
            } else break;
        }
    }

public:
    MaxPriorityQueue() {
        size = 0;
    }

    void addPatient(string name, int severity, int arrival) {
        heap[size].name = name;
        heap[size].severity = severity;
        heap[size].arrival = arrival;

        heapifyUp(size);
        size++;
    }
    Patient getNextPatient() {
        if (size == 0) {
            cout << "No patients waiting!" << endl;
            return {"None", -1, -1};
        }

        Patient top = heap[0];

        heap[0] = heap[size - 1];
        size--;

        heapifyDown(0);

        return top;
    }

    void updateSeverity(string name, int newSeverity) {
        for (int i = 0; i < size; i++) {
            if (heap[i].name == name) {
                heap[i].severity = newSeverity;

                heapifyUp(i);
                heapifyDown(i);

                return;
            }
        }
        cout << "Patient not found!\n";
    }
    void displayAll() {
        if (size == 0) {
            cout << "No patients waiting.\n";
            return;
        }

        MaxPriorityQueue temp = *this;

        cout << "\n--- Waiting Patients (Highest Priority First) ---\n";

        while (temp.size > 0) {
            Patient p = temp.getNextPatient();
            cout << p.name << " | Severity: " << p.severity
                 << " | Arrival: " << p.arrival << endl;
        }
        cout << "------------------------------------------------\n";
    }
};

int main() {
    MaxPriorityQueue pq;
    int arrivalCounter = 0;

    while (true) {
        cout << "\n===== Hospital Priority Queue =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Get Next Patient to Treat\n";
        cout << "3. Update Patient Severity\n";
        cout << "4. Display All Waiting Patients\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string name;
            int severity;

            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter severity (1-10): ";
            cin >> severity;

            pq.addPatient(name, severity, arrivalCounter++);
        }

        else if (choice == 2) {
            Patient next = pq.getNextPatient();
            if (next.severity != -1) {
                cout << "\nNext Patient: " << next.name 
                     << " (severity: " << next.severity << ")\n";
            }
        }

        else if (choice == 3) {
            string name;
            int newSeverity;

            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter new severity: ";
            cin >> newSeverity;

            pq.updateSeverity(name, newSeverity);
        }

        else if (choice == 4) {
            pq.displayAll();
        }

        else if (choice == 5) {
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
