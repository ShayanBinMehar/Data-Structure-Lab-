#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class CircularQueue
{
    int arr[MAX_SIZE];
    int front, rear;

public:
    CircularQueue() : front(-1), rear(-1) {}

    bool isFull()
    {
        return (front == (rear + 1) % MAX_SIZE);
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue Overflow\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = x;
        cout << x << " enqueued\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue contents: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue q;
    int choice, value;
    do
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ";
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
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 4);
    return 0;
}