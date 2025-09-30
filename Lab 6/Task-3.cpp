#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue
{
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    void enqueue(int x)
    {
        if (rear == MAX_SIZE - 1)
        {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = x;
        cout << x << " enqueued\n";
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << arr[front++] << " dequeued\n";
        if (front > rear)
            front = rear = -1;
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue contents: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void checkStatus()
    {
        if (front == -1 || front > rear)
            cout << "Queue is empty\n";
        else if (rear == MAX_SIZE - 1)
            cout << "Queue is full\n";
        else
            cout << "Queue is neither empty nor full\n";
    }
};

int main()
{
    Queue q;
    int choice, value;
    do
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Check empty/full\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            q.checkStatus();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);
    return 0;
}