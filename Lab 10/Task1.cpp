#include <iostream>
using namespace std;

struct Patient {
    string name;
    int severity;
    int arrival;
};

class MaxPriorityQueue {
private:
    Patient heap[100];
    int size;

    bool higherPriority(Patient a, Patient b) {
        if (a.severity > b.severity) return true;
        if (a.severity < b.severity) return false;

        return a.arrival < b.arrival;
    }

    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (higherPriority(heap[idx], heap[parent])) {
                Patient temp = heap[idx];
                heap[idx] = heap[parent];
                heap[parent] = temp;
                idx = parent;
            } else break;
        }
    }

    void heapifyDown(int idx) {
        while (true) {
            int left = idx * 2 + 1;
            int right = idx * 2 + 2;
            int largest = idx;

            if (left < size && higherPriority(heap[left], heap[largest]))
                largest = left;
            if (right < size && higherPriority(heap[right], heap[largest]))
                largest = right;

            if (largest != idx) {
                Patient temp = heap[idx];
                heap[idx] = heap[largest];
                heap[largest] = temp;
                idx = largest;
            } else break;
        }
    }

public:
    MaxPriorityQueue() { size = 0; }

    void addPatient(string name, int severity, int arrival) {
        if (size >= 100) {
            cout << "Queue full!\n";
            return;
        }
        heap[size] = { name, severity, arrival };
        heapifyUp(size);
        size++;
    }
    Patient getNextPatient() {
        if (size == 0) {
            cout << "No patients waiting.\n";
            return {"None", -1, -1};
        }
        Patient next = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return next;
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
        cout << "Patient not found.\n";
    }

    void display() {
        if (size == 0) {
            cout << "No patients waiting.\n";
            return;
        }

        cout << "Patients (highest priority first):\n";
        // We create a temporary copy to simulate priority order
        MaxPriorityQueue temp = *this;

        while (temp.size > 0) {
            Patient p = temp.getNextPatient();
            cout << p.name << " | Severity: " << p.severity
                 << " | Arrival: " << p.arrival << endl;
        }
    }
};

int main() {
    MaxPriorityQueue pq;

    int arrivalCounter = 0;
    int choice;

    while (true) {
        cout << "\n--- Hospital Queue Menu ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Get Next Patient\n";
        cout << "3. Update Severity\n";
        cout << "4. Display All Patients\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int sev;
            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter severity (1-10): ";
            cin >> sev;
            pq.addPatient(name, sev, arrivalCounter++);
        }
        else if (choice == 2) {
            Patient p = pq.getNextPatient();
            if (p.severity != -1)
                cout << "Next patient: " << p.name << " (severity " << p.severity << ")\n";
        }
        else if (choice == 3) {
            string name;
            int sev;
            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter new severity: ";
            cin >> sev;
            pq.updateSeverity(name, sev);
        }
        else if (choice == 4) {
            pq.display();
        }
        else if (choice == 5) {
            break;
        }
    }

    return 0;
}
