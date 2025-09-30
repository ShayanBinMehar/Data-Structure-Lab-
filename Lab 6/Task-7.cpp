#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Process
{
    int id;
    int priority;
};

class Queue
{
    Process arr[MAX_SIZE];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}
    bool isEmpty() { return front == -1 || front > rear; }
    bool isFull() { return rear == MAX_SIZE - 1; }
    void enqueue(Process p)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = p;
        cout << "Process " << p.id << " (priority " << p.priority << ") added to queue\n";
    }
    Process dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return {-1, -1};
        }
        return arr[front++];
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue (arrival order):\n";
        for (int i = front; i <= rear; i++)
            cout << "ID: " << arr[i].id << ", Priority: " << arr[i].priority << endl;
    }
    int size() { return isEmpty() ? 0 : rear - front + 1; }
    void clear() { front = rear = -1; }
    void moveHighPriorityToStack(class Stack &s, int minPriority);
};

class Stack
{
    Process arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_SIZE - 1; }
    void push(Process p)
    {
        if (isFull())
        {
            cout << "Stack is full\n";
            return;
        }
        arr[++top] = p;
        cout << "Process " << p.id << " (priority " << p.priority << ") pushed to stack\n";
    }
    Process pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return {-1, -1};
        }
        return arr[top--];
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack (execution order):\n";
        for (int i = top; i >= 0; i--)
            cout << "ID: " << arr[i].id << ", Priority: " << arr[i].priority << endl;
    }
};

void Queue::moveHighPriorityToStack(Stack &s, int minPriority)
{
    for (int i = front; i <= rear; i++)
    {
        if (arr[i].priority >= minPriority)
        {
            s.push(arr[i]);
            arr[i].priority = -1;
        }
    }
    int newFront = front;
    while (newFront <= rear && arr[newFront].priority == -1)
        newFront++;
    front = newFront;
}

int main()
{
    Queue q;
    Stack s;
    int choice, id, priority, minPriority;
    do
    {
        cout << "\n1. Add process\n2. Show queue\n3. Move high-priority to stack\n4. Show stack\n5. Execute from stack\n6. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter process ID: ";
            cin >> id;
            cout << "Enter priority (higher number = higher priority): ";
            cin >> priority;
            q.enqueue({id, priority});
            break;
        case 2:
            q.display();
            break;
        case 3:
            cout << "Enter minimum priority to move to stack: ";
            cin >> minPriority;
            q.moveHighPriorityToStack(s, minPriority);
            break;
        case 4:
            s.display();
            break;
        case 5:
            if (!s.isEmpty())
            {
                Process p = s.pop();
                cout << "Executing process " << p.id << " (priority " << p.priority << ")\n";
            }
            else
            {
                cout << "Stack is empty\n";
            }
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 6);
    return 0;
}